#include "std_lib_facilities.h"

//1. feladat
int ga[10];

//2. feladat
void f(int arr[], int n){
	//3. feladat
	//3-a
	int la[10];
	
	//3-b
	for(int i=0; i<n; i++){
		la[i] = arr[i];
		//3-c
		cout << la[i] << "\n";
	}
	cout << "\n\n";
	
	//3-d
	int* p = new int[n];
	
	//3-e
	for(int i=0; i<n; i++){
		p[i] = arr[i];
		//3-f
		cout << p[i] << "\n";
	}
	
	//3-g
	delete[] p;
}

int main(){
	for(int i=0; i<10; i++){
		int l=1;
		for(int k=0;k<i;k++){
			l = l*2;
		}
		ga[i]=l;
		cout << ga[i] << "\n";
	}
	
	cout << "\n\n";
	
	//4-a
	
	f(ga, 10);
	
	cout << "\n\n";
	
	//4-b
	
	int aa[10];
	
	for(int i = 1; i<11; i++){
		int l=1;
		for(int k=0; k<i; k++){
			l=l*(k+1);
		} 
		aa[i-1]=l;
	}
	
	//4-c
	
	f(aa,10);
	
}
