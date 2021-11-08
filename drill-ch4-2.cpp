#include "std_lib_facilities.h"

int
main ()
{
  double biggest = 0;
  double smallest = 0;
  int num_of_values = 0;
  double num = 0;
  string unit = " ";
  vector < string > accepted_units =
  {
  "m", "cm", "ft", "in"};
  vector < double >entered_values;
  double sum = 0;

  cout << "Enter a number:\n";


  while (cin >> num >> unit)
    {

      if (count (accepted_units.begin (), accepted_units.end (), unit))
	{

	  if (unit == "cm")
	    {
	      num = num / 100;
	    }
	  if (unit == "in")
	    {
	      num = num * (2.54 / 100);
	    }
	  if (unit == "ft")
	    {
	      num = num * (0.0254 * 12);
	    }

	  unit = "m";
	  sum += num;
	  entered_values.push_back (num);


	  cout << num << " " << unit;
	  if (num_of_values == 0)
	    {
	      biggest = num;
	      smallest = num;
	      cout <<
		", the first entered value so it is both the biggest and the smallest.";
	    }
	  if (num > biggest)
	    {
	      cout << ", the biggest number so far\n";
	      biggest = num;
	    }
	  else if (num < smallest)
	    {
	      cout << ", the smallest number so far\n";
	      smallest = num;
	    }
	  else
	    {
	      cout << "\n";
	    }
	}
      else
	{
	  cout <<
	    "The unit entered is illegal. Plase use a legal unit. Legal units: m, cm, in, f";
	  num_of_values -= 1;
	}
      num_of_values += 1;
    }
  cout << "\nThe number of values entered: " << num_of_values;
  cout << "\nThe smallest: " << smallest << "" << unit;
  cout << "\nThe largest: " << biggest << "" << unit;
  cout << "\nThe sum of values: " << sum << "" << unit;
  sort (entered_values.begin (), entered_values.end ());
  cout << "\nThe entered values: ";
for (auto i:entered_values)
    cout << i << unit << ", ";
  return 0;
}
