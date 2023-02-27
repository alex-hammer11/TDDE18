#ifndef BATTERY_H
#define BATTERY_H

#include "component.h"
#include <string>
class Battery : public Component
{
public:
    Battery(std::string name, double volt, Terminal &input, Terminal &output);

    ~Battery();

    double calculateCurrent() const;

    void calculation(double);

    void print_component() const;

private:
    double voltage;
};
#endif