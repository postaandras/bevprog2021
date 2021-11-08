
/*
	The first working version of Stroustrup's calculator.
	Written by Renátó Besenczi based on the book BS, "Programming: Principles and Practice using C++, Second Edition"
	See chapter 6 and chapter 7 of book: https://stroustrup.com/programming.html
	© 2020 Renátó Besenczi, according to CC0. Questions: renato.besenczi@gmail.com
	Input from cin; output to cout. Input comes from cin through the Token_stream called ts.
	Grammar:
	
	Calculation:
		Statement
		Print
		Quit
		Calculation Statement
	Print:
		=
	Quit:
		exit
	Statement:
		Declaration
		Expression
	Declaration:
		"#" Name ">" Expression
	Name:
		string literal
	Expression:
		Term
		Expression + Term
		Expression – Term
	Term:
		Primary
		Term * Primary
		Term / Primary
		Term % Primary
	Primary:
		Number
		( Expression )
		– Primary
		+ Primary
		pow(x,y)
		sqrt(x)
	Number:
		floating-point-literal
*/

#include "std_lib_facilities.h" //Include usual header

// Some symbolic constants for clarity
constexpr char number = '8';
constexpr char quit = 'x';
const string exitkey = "exit";
constexpr char print = '=';
constexpr char name = 'a';
constexpr char let = 'L';
constexpr char result = '=';
const string declkey = "#"; //constexpr string since C++20 only
const string sqrtkey = "sqrt";
constexpr char sqrt_type = 's';
const string powkey = "pow";
constexpr char pow_type = 'p';
constexpr char declare = '>';

//function declarations
double expression();
double primary();
double term();
double declaration();
double statement();

// Variable ///////////////////////
class Variable {
public:
	string name;
	double value;
};

vector<Variable> var_table;

bool is_declared(string var)
{
	for (const auto& v : var_table)
		if (v.name == var) return true;
	return false;
}

double define_name (string var, double val)
{
	if (is_declared(var)) error(var, " declared twice");
	var_table.push_back(Variable{var,val});
	return val;
}

double get_value(string s)
{
	for(const auto& v : var_table)
		if (v.name == s) return v.value;
	error("get: undefined variable", s);
	return -1;
}

void set_value(string s, double d)
{
	for (auto& v : var_table)
		if(v.name == s){
			v.value = d;
			return;
		}
	error("set: undefined variable", s);
}
// Variable end ///////////////////////

// Token ///////////////////////
class Token {
public:
	char kind;
	double value;
	string name;
	Token(): kind(0) {}
	Token(char ch): kind(ch), value(0) {}
	Token(char ch, double val): kind(ch), value(val) {}
	Token(char ch, string n): kind(ch), name(n) {}
};
// Token end ///////////////////////

// Token_stream ///////////////////////
class Token_stream {
public:
	Token_stream();
	void putback(Token t);
	Token get();
	void ignore(char c);
private:
	bool full;
	Token buffer;
};

Token_stream::Token_stream() :full(false), buffer(0) {}

void Token_stream::putback(Token t)
{
	if (full) error("putback() into full buffer");
	buffer = t;
	full = true;
}

Token Token_stream::get()
{
	if (full)
	{
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;

	switch (ch)
	{
		case print:
		case declare:
		case '(':
		case ')':
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case ',':
			return Token(ch);
		case '#':{
		    return Token(let);
		}
		case '.':
		case '0': case '1': case '2': case '3': case '4':
    	case '5': case '6': case '7': case '8': case '9':
    	{
    		cin.putback (ch);
    		double val;
    		cin >> val;
    		return Token(number, val);
    	}
    	default: 
    	{
    		if (isalpha(ch))
    		{
    			string s;
    			s += ch;
    			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
    			cin.putback(ch);
    			if (s==sqrtkey) return Token(sqrt_type);
    			if (s == powkey) return Token(pow_type);
    			if (s == exitkey) return Token(quit);
    			if (s == declkey) return Token(let);
    			else if (is_declared(s))
    				return Token(number, get_value(s));
    			return Token{name,s};
    		}
    		error("Bad token");
    	}
    	return 0;
	}
}

void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind)
	{
		full = false;
		return;
	}

	full = false;

	char ch = 0;
	while (cin>>ch)
		if (ch==c) return;
}
// Token_stream end ///////////////////////
Token_stream ts;

void clean_up_mess()
{
	ts.ignore(print);
}

// Logically separate calculate() from the usual "boiler plate" of main 
void calculate()
{
	while (cin)
	try {
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.putback(t);
		cout << result << statement() << endl;
	}
	catch (exception& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main() 
try {

	define_name("pi", 3.1415926535);
	define_name("e", 2.7182818284);
	define_name("k",1000);
	
	cout<<"\n Welcome to our simple calculator! \n Please enter expressions and floating-point numbers.";
	cout<<"\n The available operators are: \n  +,-,*,/,%";
	cout<<"\n You can sign the end of an expression by typing '=' and you can quit the program by typing 'exit'.";
	cout<<"\n You can use the pow(x,y) and the sqrt(x) function";
	cout<<"\n You can declare variables in the following syntax: #[name]>[value]=\n\n";
	calculate();

	return 0;

} catch (exception& e){
	cerr << e.what() << endl;
	return 1;
} catch (...) {
	cerr << "exception\n";
	return 2;
}

//Functions mapping grammar rules //////////////////////////

double squareroot(){
    Token t = ts.get();
    if(t.kind!='('){
        ts.putback(t);
        error("Incorrect usage of squareroot! The funcions formula is: 'sqrt(expression)'");
    }
    double d = expression();
    if(d>0||d==0){
        return sqrt(d);
    }
    error("The expression under a square root cannot be below 0. The calculator works with real numbers");
}

double power(){
    Token t =ts.get();
    if(t.kind!='('){
        error("Incorrect usage of power! The funcion's formula is: 'pow(expression,expression<integer>)' A '(' is missing");
    }
    double base = expression();
    
    t=ts.get();
    if(t.kind!=','){
        error("Incorrect usage of power! The funcion's formula is: 'pow(expression,expression<integer>)' A ',' is missing");
    }
    
    int i = narrow_cast<int>(expression());
    
    return pow(base,i);
}

double primary()
{
	Token t = ts.get();
	switch (t.kind)
	{
		case '(':
		{
			double d = expression();
			t = ts.get();
			if (t.kind != ')') error("')' expected");
			return d;
		}
		case sqrt_type:{
		    double d = squareroot();
	        t = ts.get();
	        if(t.kind!=')'){
	            error("Incorrect usage of squareroot! The funcions formula is: 'sqrt(expression)'");
	        }
	        return d;
		}
		case pow_type:{
	        double d = power();
	        t=ts.get();
	        if(t.kind!=')'){
	            error("Incorrect usage of power! The funcion's formula is: 'pow(expression,expression<integer>)' A ')' is missing");
	        }
	        return d;
		}
		case number:
			return t.value;
		case '-':
			return - primary();
		case '+':
			return primary();
		default:
		    ts.putback(t);
			error("primary expected");
			return 0;
	}
	return -1;
}

double term()
{
	double left = primary();
	Token t = ts.get();
	while(true)
	{
		switch (t.kind)
		{
			case '*':
				left *= primary();
				t = ts.get();
				break;
			case '/':
			{
				double d = primary();
				if (d == 0) error("divide by zero");
				left /= d;
				t = ts.get();
				break;
			}
			case '%':
			{
				double d = primary();
				if (d == 0) error("%: divide by zero");
				left = fmod (left, d);
				t = ts.get();
				break;
				/* //or you can use narrow cast check
				int i1 = narrow_cast<int>(left);
				int i2 = narrow_cast<int>(primary());
				if (i2 == 0) error ("%: Zero oszto");
				left = i1 % i2;
				t = ts.get();
				break;
				*/
			}
			default:
				ts.putback(t);
				return left;
		}
	}
}

double expression()
{
	double left = term();
	Token t = ts.get();
	while (true)
	{
		switch(t.kind)
		{
			case '+':
				left += term();
				t = ts.get();
				break;
			case '-':
				left -= term();
				t = ts.get();
				break;
			default:
				ts.putback(t);
				return left;
		}
	}
}

double declaration()
{
	Token t = ts.get();
	if(t.kind=='8'){
	    //error("variable already declared");
	    string s;
	    for (const auto& v : var_table)
		if (v.value == t.value){
		    s=v.name;
		}
		
	    Token t2 = ts.get();
	    if (t2.kind != declare){
	        error("> missing in declaration of ", s);
	    }
	    else{
	        double d = expression();
	        set_value(s,d);
	        return d;
	    }
	}
	
	if (t.kind != name) error("name expected in declaration");
	string var_name = t.name;

	Token t2 = ts.get();
	if (t2.kind != declare) error("> missing in declaration of ", var_name);

	double d = expression();
	define_name(var_name, d);
	return d;
}

double statement()
{
	Token t = ts.get();
	switch(t.kind)
	{
		case let:
			return declaration();
		default:
			ts.putback(t);
			return expression();
	}
}
//Functions mapping grammar rules end //////////////////////////

// Program end!




