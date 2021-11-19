#include "std_lib_facilities.h"
#include "my.h"

int foo;


int main(){
	foo=7;
	print_foo();
	print(99);
	
	
	//2.feladat:
	cout << "/////////////   Itegers:   ////////////\n";
	int x = 7;
	int y = 9;
	swap_v(x,y);		//compiles, but doesn't swap the variables
	cout <<"In main:\n\n" << x << "\n" << y <<"\n";
	swap_r(x,y); 		//compiles, and swaps the variables
	cout <<"In main:\n\n" << x << "\n" << y <<"\n";
	
	cout << "/////////////   Constants:   ////////////\n";
	
	
	const int cx = 7;
	const int cy = 9;
	swap_v(cx,cy);
	cout <<"In main:\n" << cx << "\n" << cy << "\n\n";  //compiles, but doesn't swap the variables
	/* swap_r(cx,cy);     //doesn't compile, we can't use swap on constant variables
	cout <<"In main:\n" << cx << "\n" << cy << "\n\n";*/
	
	
	cout << "/////////////   Doubles:   ////////////\n";
	double dx = 7.7;
	double dy = 9.9;
	swap_v(dx,dy);
	cout <<"In main:\n" << dx << "\n" << dy << "\n\n"; //compiles, but doesn't swap the variables
	/*swap_r(dx,dy);				//doesn't compile, as we are trying to swap double values with int references
	cout <<"In main:\n" << dx << "\n" << dy << "\n\n";*/
	
	swap_v(7.7,9);  				//compiles, but turns the doubles into ints
}
