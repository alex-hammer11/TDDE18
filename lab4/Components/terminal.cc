#include "terminal.h"

Terminal::Terminal()
    : charge{0}
{
}

Terminal::~Terminal()
{
}

void Terminal::setCharge(double value)
{
    this->charge = value;
}

double Terminal::getCharge() const
{
    return this->charge;
}