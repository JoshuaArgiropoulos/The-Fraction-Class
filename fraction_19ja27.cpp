#include <iostream>
using namespace std;
#include <string>
#include "fraction_19ja27.h"
#include <cstdlib>

//GDC Algorithm from ONQ
int GCD(int n, int m) {
    if (m<=n && n%m==0)
        return(m);

    else if (n<m)
        return GCD(m,n);
    
    else 
        return GCD(m, n%m);
}
//Sets default case to 0/1
Fraction::Fraction() {
    n = 0;
    d = 1;
}
//constructor for 1 argument, sets to N/1
Fraction::Fraction(int num) {
    n = num;
    d = 1;
}
//constructor for 2 arguments, sets to num/dNum
Fraction::Fraction(int num, int dNum){
    //checks if denominator is 0 and throws error
    if (dNum == 0)
        throw(FractionException("Illegal denominator"));
    bool numNeg = false;
    //Checks if num is negetive or postive
    if ((num <0 && dNum >= 0) || (num >=0 && dNum <0))
        numNeg =true;
    num = abs(num);
    dNum = abs(dNum);
    int absVal = GCD(num, dNum);

    //If numNeg, -1*absolute value if not, leaves as is
    if (numNeg)
        n = (-1)*num/absVal;
    else 
        n = num/absVal;
    
    d = (dNum / absVal);
}
//Accessor function to get numerator and denominator of function
int Fraction::numerator()const{
    return n;
}
int Fraction::denominator()const{
    return d;
}
//Override + operator for function + function
Fraction Fraction::operator+(Fraction Frac1) {
    int newNum = (d * Frac1.numerator() + n * Frac1.denominator());
    int newDnum = d * Frac1.denominator();

    return Fraction(newNum / GCD(newNum,newDnum), newDnum / GCD(newNum,newDnum) );
}
//Overide + operator for a number + function 
Fraction operator+(int num, Fraction Frac1) {
    int newNum = ( num * Frac1.denominator() + Frac1.numerator());

    return Fraction(newNum / GCD(abs(newNum),Frac1.denominator()), Frac1.denominator() /GCD(abs(newNum),Frac1.denominator()) );
}
//Overide - operator for fraction - function 
Fraction Fraction::operator-(Fraction Frac1) {
    int newNum = (n * Frac1.denominator() - d * Frac1.numerator());
    int newDnum = d* Frac1.denominator();

    return Fraction(newNum / GCD(abs(newNum),newDnum), newDnum /GCD(abs(newNum),newDnum) );
}
//Overide - operator for num - fraction 
Fraction operator-(int num, Fraction Frac1) {
    int newNum = ( num* Frac1.denominator() - Frac1.numerator());

    return Fraction(newNum / GCD(abs(newNum),Frac1.denominator()), Frac1.denominator() / GCD(abs(newNum),Frac1.denominator()) );
}
//Overide * operator for fraction * fraction
Fraction Fraction::operator*(Fraction Frac1) {
    int newNum = (Frac1.numerator() * n);
    int newDnum = (Frac1.denominator() * d);
    return Fraction(newNum / GCD(abs(newNum),newDnum), newDnum / GCD(abs(newNum),newDnum) );
}

//Overide * operator for num * Fraction
Fraction operator*(int num, Fraction Frac1) {
    int newNum = (num * Frac1.numerator());
    return Fraction(newNum / GCD(abs(newNum),Frac1.denominator()), Frac1.denominator() / GCD(abs(newNum),Frac1.denominator()) );
}

//Overide / operator for fraction / fraction
Fraction Fraction::operator/(Fraction Frac1) {
    int newNum = (Frac1.denominator() * n);
    int newDnum = (Frac1.numerator() * d);
    return Fraction(newNum / GCD(abs(newNum),newDnum), newDnum /GCD(abs(newNum),newDnum) );
}

//Overide / operator for num / fraction
Fraction operator/(int num, Fraction Frac1) {
    int newNum = (Frac1.denominator() * num);
    return Fraction(newNum / GCD(abs(newNum),Frac1.numerator()), Frac1.numerator() /GCD(abs(newNum),Frac1.numerator()) );
}
//Overide - operator to make the fraction a negetive number
Fraction Fraction::operator-() {
    return Fraction((-1) * n, d);
}

//Checks if fraction is equal to input, returns true or false
bool Fraction::operator==(Fraction Frac1) {
    if (n == Frac1.numerator() && d == Frac1.denominator())
    {
        return true;
    }
    else
    {
        return false;
    }
}
//Checks if fraction is not equal to input fraction, returns the opposite of equals
bool Fraction::operator!=(Fraction Frac1) {
    if (n == Frac1.numerator() && d == Frac1.denominator())
    {
        return false;
    }
    else
    {
        return true;
    }
}
//Checks if fraction is greater than input, returns true / false
bool Fraction::operator>(Fraction Frac1) {
    if (((double) n / d) > ((double)Frac1.numerator() / Frac1.denominator()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Checks if fraction is greater than or equals to input fraction 
bool Fraction::operator>=(Fraction Frac1) {
    if (((double) n / d) >= ((double)Frac1.numerator() / Frac1.denominator()))
    {
        return true;
    }
    else
    {
        return false;
    }
}
//Checks if fraction is less than the input fraction
bool Fraction::operator<(Fraction Frac1) {
    if (((double) n / d) < ((double)Frac1.numerator() / Frac1.denominator()))
    {
        return true;
    }
    else
    {
        return false;
    }
}
//Checks if constant is less than fraction, returns true or false
bool operator<(int num, Fraction Frac1)
{
    if (num < ((double)Frac1.numerator() / Frac1.denominator()))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//Checks if fraction is less than or equal to input fraction
bool Fraction::operator<=(Fraction Frac1) {
    if (((double) n / d) <= ((double)Frac1.numerator() / Frac1.denominator()))
    {
        return true;
    }
    else
    {
        return false;
    }
}
//Checks if fraction is greater than input number 
bool Fraction::operator>(int num) {
    if (((double) n / d) > num)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//Adds 1 to fraction and stores the new fraction while returning the old fraction
Fraction Fraction::operator++(int) {

    int oldN = n;
    int oldD = d;
    n = n + d;

    n = (n / GCD(abs(n), d));
    d = (d / GCD(abs(n), d));

    return Fraction(oldN, oldD);
}
//Adds 1 to the fraction and returns the new fraction and stores the new fraction
Fraction Fraction::operator++() {
    n = n+d;
    return Fraction(((n) / GCD(abs(n), d)), (d / GCD(abs(n), d)));
}
//Adds a fraction / value to the current fraction 
Fraction Fraction::operator+=(Fraction Frac1) {
    
    int newN = (d * Frac1.numerator()) + (n * Frac1.denominator());
    int newD = Frac1.denominator() * d;

    int absVal = GCD(abs(newN), newD);

    n = newN / absVal;
    d = newD / absVal;

    return Fraction(newN / absVal, newD / absVal);
}


//Fraction Error exception message function 
FractionException::FractionException(const string &inMessage) {
    message = inMessage;
}
string &FractionException::what() {
    return message;
}

//Cout and cin implementation
//Used to display the fractions to the output and take user input fractions 

//Cout is used printing numerator "/" denominator 
ostream &operator<<(ostream &out, const Fraction &Frac1) {
    out << Frac1.numerator() << "/" << Frac1.denominator();
    return out;
}
//Cin 
istream &operator>>(istream &in, Fraction &Frac1)
{
    //declare varibles
    string userInput;
    string Numerator;
    string Denominator;
    //Stores in into userInput
    in >> userInput; 
    //Find the slash index in the input to seperate user input into numerator and denominator, 
    size_t slashNum = userInput.find("/");

    //Checks if the user input is an intege number
    if (slashNum == -1)
    {
        //Set numerator as the input and denonminator as 1, this is used to accept user input whole numbers as there is no slashes 
        Numerator = userInput;
        Denominator = "1";
    }
    else
    {
        //Substring out the numerator and denominator
        //Locates the numerator and the denominator using substring. Seperates them and stores them into variables 
        Numerator = userInput.substr(0, slashNum);
        Denominator = userInput.substr(slashNum + 1, userInput.length() - 1);

        //Check for zero in denominator
        if (Denominator == "0")
        {
            throw(FractionException("The fraction is undefined. Zero cannot be in the denominator."));
        }
    }
    
    //Converts the strings into integers to do operations on the fractions
    Frac1.n = stoi(Numerator);
    Frac1.d = stoi(Denominator);

    return in;
}