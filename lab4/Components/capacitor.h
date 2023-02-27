#ifndef CAPACITOR_H
#define CAPACITOR_H

#include "component.h"
class Capacitor : public Component
{
public:
    Capacitor(std::string given_name, double cap, Terminal &input, Terminal &output);

    ~Capacitor();

    double calculateCurrent() const;

    void calculation(double time_unit);

    void print_component() const;

private:
    double capacitance;
    double chargeStored;
};

#endif