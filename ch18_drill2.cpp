#include "std_lib_facilities.h"

//1. feladat:
vector<int> gv(10);

//2-3. feladat
void f(vector<int> pp){
	//3-a
	vector<int> lv(pp.size());
	
	//3-b
	copy(pp.begin(), pp.end(), lv.begin());
	//3-c
	for(int i=0; i<pp.size(); i++){
		cout << pp[i] << "\n";
	}
	cout<< "\n\n";
	
	//3-d
	vector<int> lv2 = pp;
	//3-e
	for(int i=0; i<lv2.size(); i++){
		cout << lv2[i] << "\n";
	}
}



int main(){
	
	for(int i=0; i<gv.size(); i++){
		int l=1;
		for(int k=0;k<i;k++){
			l = l*2;
		}
		gv[i]=l;
		cout << gv[i] << "\n";
	}
	
	cout << "\n\n";
	
	//4. feladat
	//4-a
	f(gv);
	
	//4-b
	vector<int> vv(10);
	
	for(int i = 1; i<vv.size()+1; i++){
		int l=1;
		for(int k=0; k<i; k++){
			l=l*(k+1);
		} 
		vv[i-1]=l;
	}
	
	cout << "\n\n";
	
	f(vv);
}
