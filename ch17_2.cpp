#include "std_lib_facilities.h"

void print_array(ostream& os, int*a, int n){
	for(int i=0; i<n; i++){
		os << a[i] << " ";
	}
	cout << "\n";
}

int main(){
	//1. feladat
	int* p1 = new int(7);
	
	//2. feladat
	cout << "p1's value: " <<p1 << "\nThe value p1 points to: " << *p1 << "\n";
	
	//3. feladat
	int* p2 = new int[7];
	for(int i=0; i<7; i++){
		int l=1;
		for(int k=0;k<i;k++){
			l = l*2;
		}
		p2[i]=l;
	}
	cout << "\n";
	
	//4. feladat
	cout << "p2's value: " <<p2 << "\nThe values p2 points to: \n";
	
	print_array(cout,p2,7);
	cout << "\n";
	
	//5-7. feladat
	
	int* p3 = p2;	
	p2 = p1;
	p2 = p3;
	
	//8. feladat
	cout << "p1's value: " <<p1 << "\nThe value p1 points to: " << *p1 << "\n";
	cout << "\n";
	
	cout << "p2's value: " <<p2 << "\nThe values p2 points to: \n";
	print_array(cout,p2,7);
	
	//9.feladat
	delete p1;
	delete[] p3;
	
	
	//10.feladat
	p1 = new int[10];
	for(int i=0; i<10; i++){
		int l=1;
		for(int k=0;k<i;k++){
			l = l*2;
		}
		p1[i]=l;
	}
	print_array(cout,p1,10);
	
	//11.feladat
	p2 = new int[10];
	
	
	//12. feladat
	for(int i =0; i<10; i++){
		p2[i] = p1[i];
	}
	
	delete[] p1;
	delete[] p2;
	
	//13. feladat
	vector<int> v1(10);
	for(int i=0; i<v1.size(); i++){
		int l=1;
		for(int k=0;k<i;k++){
			l = l*2;
		}
		v1[i]=l;
	}
	
	vector<int> v2(10);
	
	for(int i=0; i<v2.size();i++){
		v2[i]=v1[i];
	}
}
