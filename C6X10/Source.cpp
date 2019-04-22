/*  Program Description
C6X10 - from Programming Principles and Practices using C++ - Bjarn Stroustrep
Program: Takes 2 numbers as input and calulates either the Permutation or Combination of those 2 numbers.
Outputs the result.
Permutation (a,b) = a!/(aib)!
Combination (a.b) = P(a,b)/b!

*/

/*
Standard opening
*/

#include "C:\Users\mark.alexieff\source\repos\std_lib_facilities.h"

/*
global variables
*/



/*
functions declarations
*/

bool yes_no(string s);

int get_p_or_c(string s);

long int permutation(int a, int b);
long int combination(int a, int b);

long int factorial(int n);






/*
main
*/

int main() {

	int a{ 0 };
	int b{ 0 };
	int pc{ 0 };

	cout << "Welcome to C6x10\nThis program takes to integers and asks if you want Perm or Combo (p or c)\n";
	cout << "It returns the answer.\n";

	cout << "\nEnter two intergers separated by white space: ";
	cin >> a;
	cin >> b;

	pc = get_p_or_c("Do you want Permutation or Combination? ");

	switch (pc) {
	case 1:
		cout << "\n" << "Permutation of " << a << " and " << b << " = " << permutation(a, b) << "\n";
		break;
	case 2:
		cout << "\n" << "Combination of " << a << " and " << b << " = " << combination(a, b) << "\n";
		break;
	default:
		cout << "\n Something went wrong....\n";
		break;
	}
	keep_window_open();
	return(1);
}






/*
funcion definitions
*/

bool yes_no(string s) {						// self exlanatory - y return true anything else retirns false
	char response{ 'X' };
	cout << s << " (y/n): ";
	cin >> response;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');   //clears all remaining content from cin

	switch (response)
	{
	case 'y':
		return true;
	case 'n':
		return false;
	default:
		return false;
	}
}

int get_p_or_c(string s) {
	char response{ 'X' };
	cout << s << " (p/c): ";
	cin >> response;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');   //clears all remaining content from cin

	switch (response)
	{
	case 'p':
		return 1;
	case 'c':
		return 2;
	default:
		return 0;
	}
}

long int factorial(int n)
{
	return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

long int permutation(int a, int b) {
	return (factorial(a) / factorial(a - b));
}

long int combination(int a, int b) {
	return(permutation(a, b) / factorial(b));
}