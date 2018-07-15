// Lab 9 Exercise 3
// Currency conversions
//

#include <iostream>
#include <iomanip>

using namespace std;

// This program will get an amount in US dollars and convert it
// to another currency

// Prototypes of the functions
// Prototypes of the functions
float convertToYen(float dollars, float yen);
float convertToEurosAndPesos(float dollars, float pesos, float euros);

int main ()
{
   float dollars, euros, pesos, yen;
   yen = 104.75;
   pesos = 13.07;
   euros = .77;
   cout << fixed << showpoint << setprecision(2);
   cout << "Please input the amount of US Dollars you want converted: " << endl;
   cin >> dollars;
   cout << "The value of " << dollars << " Dollars is:" << endl;
   convertToYen(dollars, yen);
   convertToEurosAndPesos(dollars, pesos, euros);

   //  Fill in the code to convert to yen, euros, and pesos
   // and display the results

   return 0;
}

float convertToYen(float dollars, float yen)
{
    float totalyen = dollars * yen;
    cout << fixed << setprecision(2) << totalyen << " Yen" << endl;
}

float convertToEurosAndPesos(float dollars, float pesos, float euros)
{
    float totalpesos = dollars * pesos;
    cout << fixed << setprecision(2) << totalpesos << " Pesos" << endl;
    float totaleuros = dollars * euros;
    cout << fixed << setprecision(2) << totaleuros << " Euros" << endl;

}

