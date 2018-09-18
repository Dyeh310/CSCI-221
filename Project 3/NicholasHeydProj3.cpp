/* This is program project 2 on page 695. 
 * Before you begin the project, please read the project description 
 * on page 695 first.
 *
 * Author: Nicholas Heyd
 * Version: September 15-16
 */

#include <iostream>
#include <cmath>
#include <cassert>
#include <algorithm>

using namespace std;

class Fraction
{
public:


	// constructor
	//two arguments
	Fraction(int a, int b)
	{

		num = a;
		den = b;
		if (den < 0)
		{
			num *= -1;
			den *= -1;
		}
	}
    //one argument
	Fraction(int a)
	{
		den = 1;
		num = a;
	}
    
	//default
	Fraction()
	{
		den = 1;
		num = 0;
	}

	// member functions
    
	int get_numerator() const
	{
		return num;
	}
    
	int get_denominator() const
	{
		return den;
	}
    
    void reduce()
	{
		Fraction frac = Fraction(num, den);
		int gcd = frac.gcd();
		num /= gcd;
		den /= gcd;
	}
    
    Fraction reciprocal() const
	{
		return Fraction(den, num);
	}
    
	friend Fraction operator +(const Fraction& f1, const Fraction& f2)
	{
		int top = f1.num * f2.den + f2.num * f1.den;
		int bottom = f1.den * f2.den;
		Fraction frac = Fraction(top, bottom);
		frac.reduce();
		return frac;
	}

    
    friend Fraction operator -(const Fraction& f1, const Fraction& f2)
	{
		int top = f1.num * f2.den - f2.num * f1.den;
		int bottom = f1.den * f2.den;
		Fraction frac = Fraction(top, bottom);
		frac.reduce();
		return frac;
	}
    
    friend Fraction operator *(const Fraction& f1, const Fraction& f2)
	{
		int top = f1.num * f2.num;
		int bottom = f1.den * f2.den;
		Fraction frac = Fraction(top, bottom);
		frac.reduce();
		return frac;
	}
    
    friend Fraction operator /(const Fraction& f1, const Fraction& f2)
	{
		int top = f1.num * f2.den;
		int bottom = f1.den * f2.num;
		Fraction frac = Fraction (top, bottom);
		frac.reduce();
		return frac;
	}
    
	friend Fraction operator -(const Fraction& f)
	{
		return Fraction(-f.num, f.den);
	}
    
	friend bool operator < (const Fraction& f1, const Fraction& f2)
	{
		return f1.num * f2.den < f2.num * f1.den;
	}
    
    friend bool operator > (const Fraction& f1, const Fraction& f2)
	{
		return f1.num * f2.den > f2.num * f1.den;
	}
    
    friend bool operator <= (const Fraction& f1, const Fraction& f2)
	{
		return f1.num * f2.den <= f2.num * f1.den;
	}
    
    friend bool operator >= (const Fraction& f1, const Fraction& f2)
	{
		return f1.num * f2.den >= f2.num * f1.den;
	}
    
    friend bool operator == (const Fraction& f1, const Fraction& f2)
	{
		return f1.num * f2.den == f2.num * f1.den;		
	}
    
    friend bool operator != (const Fraction& f1, const Fraction& f2)
	{
		return f1.num * f2.den != f2.num * f1.den;	
	}
    
	friend istream& operator >> (istream& in, Fraction& f)
	{
		char slash;
		in >> f.num >> slash >> f.den;
		if(f.den < 0)
		{
			f.den *= -1;
			f.num *= -1;
		}

		return in;
	}
    
	friend ostream& operator << (ostream& out, Fraction& f)
	{
		out << f.num << '/' << f.den;
		return out;
	}

private:
	int num; // numerator of the fraction
	int den; // denominator of the fraction
    
	int gcd();
    // A prvate function that is used to find the gcd of numerator
    // and denominator by using Euclidean Algorithm
};

// all following test functions are given

double test1();
// test all constructors and two get methods.
// All these functions worth 1.5 points

double test2();
// test neg, reduce, and reciprocal functions.
// All these functions worth 1.5 points

double test3();
// test add, sub, mul, and div functions.
// All these functions worth 3 points

double test4();
// test less, greater, equal, less_or_equal, greater_or_equal,
// not_equal. All these functions worth 2 points

double test5();
// test input and output function. This two functions worth 1 points

int main()
{
	double totalScore = 0.0;
	
	cout <<"Let's see your grade. \n\n";
	system("pause");
	cout << endl;

	// Test constructors, and get functions
	totalScore += test1();
	cout << "Your points so far is " << totalScore << "\n\n";
	system("pause");
	cout << endl;

	// Test neg, reciprocal, and reduce functions
	totalScore += test2();
	cout << "Your points so far is " << totalScore << "\n\n";
	system("pause");
	cout << endl;

	// Test +, -, *, / operators
	totalScore += test3();
	cout << "Your points so far is " << totalScore << "\n\n";
	system("pause");
	cout << endl;

	// Test all >, <, >=, <=, ==, != operators
	totalScore += test4();
	cout << "Your points so far is " << totalScore << "\n\n";
	system("pause");
	cout << endl;

	// Test >> and << operators
	totalScore += test5();
	cout << "Your points so far is " << totalScore << "\n\n";
	system("pause");
	cout << endl;

	cout << "If you turn in your program to Dr. Zeng now, your will get " << totalScore << " out of 9\n";
	cout << "Dr. Zeng will read your program and decide if you will get 1 more point for program style\n";
	
	system("pause");
	return 0;
	
}

// implement all class member functions here, gcd function is given

int Fraction::gcd()
{
	if(num == 0) return 1;

	int a = max(abs(num), abs(den));
	int b = min(abs(num), abs(den));

	while(b != 0)
	{
		int result = a%b;
		a = b;
		b = result;
	}

	return a;
}

// test all constructors and two get methods.
// All these functions worth 1 points
double test1()
{
	double result = 1.5;
	// Test no argument constructor
	Fraction f1; // the fraction should be 0/1
	if(f1.get_numerator() != 0 || f1.get_denominator() != 1)
	{
		cout << "The constructor with no argument was wrong.\n";
		result -= 0.5;
	}
	// Test one argument constructor
	Fraction f2(2); // the fraction should shoule be 2/1
	if(f2.get_numerator() != 2 || f2.get_denominator() != 1)
	{
		cout << "The constructor with one argument was wrong.\n";
		result -= 0.5;
	}
	// Test two arguments constructors
	Fraction f3(3, -4); // the fraction should be -3/4
	if(f3.get_numerator() != -3 || f3.get_denominator() != 4)
	{
		cout << "The constructor with two argument was wrong. Make sure that the denomunator always positive.\n";
		result -= 0.5;
	}
	// finish test
	if(result < 1.5 && result > 0)
		cout << "Test 1 partially failed. You got " << result << " more points\n";
	else if(result > 1.4)
		cout << "Test 1 fully passed. You got 1.5 more points\n";
	else
		cout << "Test 1 completely failed. You may check your constructors and get methods\n";
	return result;
}

// test neg, reduce, and reciprocal functions.
// All these functions worth 1.5 points
double test2()
{
	double result = 1.5;
	Fraction f1(12, -15), f2(2, 3), f3, f4;
	// Test neg
	f3 = -f1; // f3 is 12/15
	f4 = -f2; // f4 is -2/3
	if(f3.get_numerator() != 12 || f3.get_denominator() != 15
		|| f4.get_numerator() != -2 || f4.get_denominator() != 3)
	{
		cout <<"The negation function was wrong.\n";
		result -= 0.5;
	}
	// Test reciprocal
	f3 = f1.reciprocal(); // f3 is -15/12
	f4 = f2.reciprocal(); // f4 is 3/2
	if(f3.get_numerator() != -15 || f3.get_denominator() != 12
		|| f4.get_numerator() != 3 || f4.get_denominator() != 2)
	{
		cout <<"The reciprocal function was wrong.\n";
		result -= 0.5;
	}
    
	// Test reduce
	f1.reduce(); // f1 is -4/5
	f2.reduce(); // f2 is 2/3
	if(f1.get_numerator() != -4 || f1.get_denominator() != 5 || f2. get_numerator() != 2 || f2.get_denominator() != 3)
	{
		cout <<"The reduce function was wrong.\n";
		result -= 0.5;
	}
	// finish test
	if(result < 1.5 && result > 0)
		cout << "Test 2 partially failed. You got " << result << " more points\n";
	else if(result > 1.4)
		cout << "Test 2 fully passed. You got 1.5 more points\n";
	else
		cout << "Test 2 completely failed. \n";
	return result;
}

// test +, -, *, and / operators.
// All these functions worth 3 points
double test3()
{
	Fraction f1(-1, 2), f2(3, 5), f;
	double result = 3.0;
	// Test +
	f = f1 + f2; // f is -1/2+3/5 = 1/10
	if(f.get_numerator() != 1 || f.get_denominator() != 10)
	{
		cout <<"The add function was wrong.\n";
		result -= 1.0;
	}
	// Test subtraction
	f = f1 - f2; // f is -1/2 - 3/5 = -11/10
	if(f.get_numerator() != -11 || f.get_denominator() != 10)
	{
		cout <<"The sub function was wrong.\n";
		result -= 0.5;
	}
	// Test multiplication
	f = f1 * f2; // f is -3/10
	if(f.get_numerator() != -3 || f.get_denominator() != 10)
	{
		cout <<"The mul function was wrong.\n";
		result -= 1.0;
	}
	// Test division
	f = f1 / f2; // f is -5/6
	if(f.get_numerator() != -5 || f.get_denominator() != 6)
	{
		cout <<"The div function was wrong.\n";
		result -= 0.5;
	}
	// finish test
	if(result < 3.0 && result > 0)
		cout << "Test 3 partially failed. You got " << result << " more points\n";
	else if(result > 2.9)
		cout << "Test 3 fully passed. You got 3.0 more points\n";
	else
		cout << "Test 3 completely failed. \n";
	return result;

}

// test less, greater, equal, less_or_equal, greater_or_equal,
// not_equal. All these functions worth 2 points
double test4()
{
	
	Fraction f1(-1, 2), f2(3, 5), f3(2, -4);
	double result = 2.0;
	// Test <
	if(!(f1 < f2) || f1 < f3 || f2 < f3)
	{
		cout <<"The < operator was wrong.\n";
		result -= 0.5;
	}
	// Test >
	if(f1 > f2 || !(f2 > f1) || f1 > f3)
	{
		cout <<"The > operator was wrong.\n";
		result -= 0.5;
	}
	// Test ==
	if(f1 == f2 || !(f1 == f3) || f2 == f3)
	{
		cout <<"The equal function was wrong.\n";
		result -= 0.5;
	}
	// Test <=
	if(!(f1 <= f2) || !(f1 <= f3) || f2 <= f3)
	{
		cout <<"The less_or_equal function was wrong.\n";
		result -= 0.5;
	}
	// Test >=
	if(f1 >= f2 || !(f1 >= f3) || !(f2 >= f3))
	{
		cout <<"The greater_or_equal function was wrong.\n";
		result -= 0.5;
	}
	// Test !=
	if(!(f1 != f2) || f1 != f3 || !(f2 != f3))
	{
		cout <<"The not_equal function was wrong.\n";
		result -= 0.5;
	}

	// finish test
	if(result < 2.0 && result > 0)
		cout << "Test 4 partially failed. You got " << result << " more points\n";
	else if(result > 1.9)
		cout << "Test 4 fully passed. You got 2.0 more points\n";
	else
		cout << "Test 4 completely failed. \n";
	return max(result, 0.0); // the student will not get negative points for any test
}

// test input and output function. This two functions worth 1 points
double test5()
{
	double result = 1.0;
	Fraction f;
	cout << "This test has to be interactive, please follow the instruction\n";
	cout << "Enter a fraction exactly as 3/-4:";
    cin >> f;
	if(f.get_denominator() != 4 || f.get_numerator() != -3)
	{
		cout << "The input function is not correct\n";
		result -= 0.5;
	}
	Fraction f1(3, -4);
	cout << f1;
	cout << "\nDoes the previous line show you -3/4? Y or N: ";
	char choice;
	cin >> choice;
	if(choice != 'y' && choice != 'Y')
	{
		cout << "The output function is not correct\n";
		result -= 0.5;
	}
	// finish test
	if(result < 1.0 && result > 0)
		cout << "Test 5 partially failed. You got " << result << " more points\n";
	else if(result > 0.9)
		cout << "Test 5 fully passed. You got 1.0 more points\n";
	else
		cout << "Test 5 completely failed. \n";
	return result;
}



/* --------------------OUTPUT----------------------------

Let's see your grade.

Press any key to continue . . .

Test 1 fully passed. You got 1.5 more points
Your points so far is 1.5

Press any key to continue . . .

Test 2 fully passed. You got 1.5 more points
Your points so far is 3

Press any key to continue . . .

Test 3 fully passed. You got 3.0 more points
Your points so far is 6

Press any key to continue . . .

Test 4 fully passed. You got 2.0 more points
Your points so far is 8

Press any key to continue . . .

This test has to be interactive, please follow the instruction
Enter a fraction exactly as 3/-4:3/-4
-3/4
Does the previous line show you -3/4? Y or N: Y
Test 5 fully passed. You got 1.0 more points
Your points so far is 9

Press any key to continue . . .

If you turn in your program to Dr. Zeng now, your will get 9 out of 9
Dr. Zeng will read your program and decide if you will get 1 more point for program style
Press any key to continue . . .




*/
