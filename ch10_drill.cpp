#include "std_lib_facilities.h"

struct Point{
	int x;
	int y;
};

int main() {
	try{
		cout << "Please enter seven points in this syntax: x,y\n";
		vector<Point> points;
		int x;
		int y;
		char ch;
		for(int i=0; i<7; i++){
			cin>>x>>ch>>y;
			if(ch!=',') error("invalid syntax");
			points.push_back(Point{x,y});
		}
		
		cout<<"\n\n\n\n";
		
		for(const auto& Point:points){
			cout << Point.x << ch << Point.y << "\n";
		}
	
		ofstream ofile {"mydata.txt"};
		
		for(const auto& Point : points)
		ofile << Point.x << ch << Point.y << '\n';
		
		ofile.close();
		
		cout<<"\n\n\n\n";
	
		ifstream ifile {"mydata.txt"};
		vector<Point> processed_points;
		
		while(ifile >> x >> ch >> y){
		if(ch!=',') error("Invalid syntaxs.");
		processed_points.push_back(Point{x, y});
		}
		
		if(points.size()==processed_points.size()){
			for(int i=0; i<points.size();i++){
				Point original = points[i];
				Point copied = processed_points[i];
				if(original.x!=copied.x||original.y!=copied.y){
					error("Something's wrong");
				}
				else{
					cout << original.x << ',' << original.y << "       " << copied.x << ',' << copied.y << '\n';
				}
			}
		}
		else{
			error("Vector size difference");
			return 2;
		}
		
		
		return 0;
	}
	catch(runtime_error& e){
		cerr << "Error: " << e.what() << '\n';
		return 1;
	}
}
