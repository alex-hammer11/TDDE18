#include "component.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

Component::Component(string given_name, Terminal &input, Terminal &output)
    : name{given_name}, in{input}, out{output}
{
}

Component::~Component()
{
}

void Component::print_name() const
{
    cout << this->name << setfill(' ') << setw(15);
}
