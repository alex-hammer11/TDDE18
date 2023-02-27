#ifndef RESISTOR_H
#define RESISTOR_H

#include "component.h"

class Resistor : public Component
{
public:
    Resistor(std::string given_name, double resist, Terminal &input, Terminal &output);

    ~Resistor();

    void calculation(double time_unit);

    double calculateCurrent() const;

    void print_component() const;

private:
    double resistance;
};

#endif