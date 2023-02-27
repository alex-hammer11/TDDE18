#include "battery.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

Battery::Battery(string given_name, double volt, Terminal &input, Terminal &output)
    : Component{given_name, input, output}, voltage{volt}
{
}

Battery::~Battery()
{
}

double Battery::calculateCurrent() const
{
    return 0.0;
}

void Battery::calculation(double)
{
    out.setCharge(voltage);
    in.setCharge(0);
}

void Battery::print_component() const
{
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    cout << setw(0) << voltage << "  " << this->calculateCurrent();
}