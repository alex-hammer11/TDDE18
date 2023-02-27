#include "resistor.h"
#include <string>
#include <iostream>

using namespace std;

Resistor::Resistor(string given_name, double resist, Terminal &input, Terminal &output)
    : Component{given_name, input, output}, resistance{resist}
{
}

Resistor::~Resistor()
{
}
void Resistor::calculation(double time_unit)
{
    double const terminal_a = in.getCharge();
    double const terminal_b = out.getCharge();

    double move = ((abs(terminal_a - terminal_b)) / resistance) * time_unit;

    if (terminal_a > terminal_b)
    {
        out.setCharge(terminal_b + move);
        in.setCharge(terminal_a - move);
    }
    else
    {
        out.setCharge(terminal_b - move);
        in.setCharge(terminal_a + move);
    }
}

double Resistor::calculateCurrent() const
{
    return (abs(in.getCharge() - out.getCharge())) / resistance;
}

void Resistor::print_component() const
{
    double voltage = abs(in.getCharge() - out.getCharge());
    cout << voltage << "  " << this->calculateCurrent();
}