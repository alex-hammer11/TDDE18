#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    cout << "INPUT PART" << endl;
    cout << setfill('=') << setw(10) << '=' << endl;

    float first_price{};
    cout << "Enter first price: ";
    cin >> first_price;
    while (first_price < 0) {
        cout << "ERROR: First price must be greater than 0" << endl;
        cout << "Enter first price: ";
        cin >> first_price;
    }

    float last_price{};
    cout << "Enter last price: ";
    cin >> last_price;
    while (last_price <= first_price) {
        cout << "ERROR: Last price must be greater than first price" << endl;
        cout << "Enter last price: ";
        cin >> last_price;
    }

    float stride{};
    cout << "Enter stride: ";
    cin >> stride;
    while (stride <= 0.01f) {
        cout << "ERROR: Stride must be at least 0.01" << endl;
        cout << "Enter stride: ";
        cin >> stride;
    }

    float pct{};
    cout << "Enter tax percent: ";
    cin >> pct;
    while (pct < 0) {
        cout << "ERROR: Percentage must be at least 0 (zero)" << endl;
        cout << "Enter tax percent: ";
        cin >> pct;
    }
    pct = pct / 100;

    cout << endl;

    cout << "TAX TABLE" << endl;
    cout << setw(9) << '=' << endl;

    cout << setfill(' ') << setw(12) << "Price" << setw(17) << "Tax" << setw(20) << "Price with tax" << endl;

    cout << setfill('-') << setw(49) << '-' << endl;

    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);

    float iterations = (last_price - first_price) / stride;
    float price{first_price};
    float tax{price * pct};
    float price_with_tax{price + tax};

    for (float i{0}; i <= iterations; ++i) {
        cout << setfill(' ') << setw(12) << price << setw(17) << tax << setw(20) << price_with_tax << endl;
        price += stride;
        tax = price * pct;
        price_with_tax = price + tax;
    }
}
