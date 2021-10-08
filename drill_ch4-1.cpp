#include <iostream>
using namespace std;

#include "std_lib_facilities.h"
  
int
main ()
{
  
 
cout << "Enter two numbers, separated by an enter!\n";
  
 
double num1, num2;
  
while (cin >> num1 >> num2)
    
    {
      
if (num1 == num2)
	
	{
	  
cout << "The numbers are equal.\n";
	
}
      
      else
	
	{
	  
if (num1 > num2)
	    
	    {
	      
swap (num1, num2);
	    
}
	  
cout << "The smaller value is: " << num1 << "\n";
	  
cout << "The larger value is: " << num2 << "\n";
	  
 
if ((num2 - num1) < 0.01)
	    
	    {
	      
cout << "The numbers are almost equal\n";
	    
}
	
}
    
}
  
 
return 0;

}
