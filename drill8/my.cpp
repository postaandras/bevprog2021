#include "my.h"
#include "std_lib_facilities.h"

void print_foo(){
	cout << foo << "\n";
}

void print(int i){
	cout << i << "\n";
}

void swap_v(int a, int b){
	int temp;
	temp = a;
	a=b;
	b=temp;
	cout << "In swap_v:\n" << a << "\n" << b << "\n\n";
}

void swap_r(int& a, int& b){
	int temp;
	temp = a;
	a=b;
	b=temp;
	cout << "In swap_r:\n" << a << "\n" << b << "\n\n";
}

/*
 * Doesn't compile, constant reference variables can't be modified!
 * 
 * void swap_cr(const int& a, const int& b){
	int temp;
	temp = a;
	a=b;
	b=temp;
	cout << a << "\n" << b << "\n";
}*/

