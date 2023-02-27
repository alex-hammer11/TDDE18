#include "capacitor.h"
#include <string>
#include <iostream>

using namespace std;

Capacitor::Capacitor(string given_name, double cap, Terminal &input, Terminal &output)
    : Component{given_name, input, output}, capacitance{cap}, chargeStored{0}
{
}

Capacitor::~Capacitor()
{
}

double Capacitor::calculateCurrent() const
{
    return capacitance * (abs(in.getCharge() - out.getCharge()) - chargeStored);
}

void Capacitor::calculation(double time_unit)
{
    double const terminal_a = in.getCharge();
    double const terminal_b = out.getCharge();

    double voltage = abs(terminal_a - terminal_b);
    double const charge = capacitance * (voltage - chargeStored) * time_unit;
    if (terminal_a > terminal_b)
    {
        out.setCharge(terminal_b + charge);
        in.setCharge(terminal_a - charge);
    }
    else
    {
        out.setCharge(terminal_b - charge);
        in.setCharge(terminal_a + charge);
    }
    chargeStored += charge;
}

void Capacitor::print_component() const
{
    double voltage = abs(in.getCharge() - out.getCharge());
    cout << voltage << " " << this->calculateCurrent();
}
