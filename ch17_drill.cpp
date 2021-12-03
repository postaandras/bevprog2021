#include "std_lib_facilities.h"

//4. feladat
void print_array10(ostream& os, int* a){
	for(int i=0; i<10; i++){
		os << a[i] << " ";
	}
	cout << "\n";
}

//7. feladat
void print_array(ostream& os, int*a, int n){
	for(int i=0; i<n; i++){
		os << a[i] << " ";
	}
	cout << "\n";
}

//10. feladat
void print_vector(ostream& os, vector<int> a){
	for(int i=0;i<a.size();i++){
		os << a[i] << " ";
	}
	cout << "\n";
}

int main(){
	//1-3. feladat
	int* b = new int[10];
	for(int i=0;i<10;i++){
		cout << b[i] << " ";
	}
	cout << "\n";
	delete[] b;
	
	//5. feladat
	int* c = new int[10];
	for(int i=0; i<10; i++){
		c[i]= 100+i;
	}
	
	print_array10(cout, c);
	delete[] c;

	//6. feladat

	int* d = new int[11];
	for(int i=0; i<11; i++){
		d[i]= 100+i;
	}
	
	print_array10(cout, d);
	delete[] d;
	
	//8. feladat
	int* e = new int[20];
	for(int i=0; i<20; i++){
		e[i]= 100+i;
	}
	
	print_array(cout, e, 20);
	delete[] e;
	
	//10.feladat
	vector<int> nums;
	for(int i=0; i<10; i++){
		nums.push_back(100+i);
	}
	
	print_vector(cout,nums);
	
	vector<int> nums2;
	for(int i=0; i<11; i++){
		nums2.push_back(100+i);
	}
	
	print_vector(cout,nums2);
	
	vector<int> nums3;
	for(int i=0; i<20; i++){
		nums3.push_back(100+i);
	}
	
	print_vector(cout,nums3);
	
	
	return 0;
}
