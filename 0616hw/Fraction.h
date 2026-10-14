#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    void simplify() {
        int gcd = FindGCD(abs(numerator), abs(denominator));
        numerator /= gcd;
        denominator /= gcd;
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    int FindGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    Fraction() {
        numerator = 0;
        denominator = 1;
    }

    Fraction(int num, int den) {
        numerator = num;
        denominator = (den != 0) ? den : 1;
        simplify();
    }

    void Input() {
        char slash;
        cin >> numerator >> slash >> denominator;
        if (denominator == 0) {
            denominator = 1;
        }
        simplify();
    }

    void Print() const {
        cout << numerator << "/" << denominator << endl;
    }

    Fraction Add(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    Fraction Subtract(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    Fraction Multiply(const Fraction& other) const {
        int num = numerator * other.numerator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    Fraction Divide(const Fraction& other) const {
        int num = numerator * other.denominator;
        int den = denominator * other.numerator;
        return Fraction(num, den);
    }
};

#endif