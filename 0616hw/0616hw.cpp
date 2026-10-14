#include <iostream>
#include "Fraction.h"

using namespace std;

int main() {
    Fraction f1, f2;
    f1.Input();
    f2.Input();

    Fraction sum = f1.Add(f2);
    sum.Print();

    return 0;
}