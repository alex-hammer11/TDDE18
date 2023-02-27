#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <vector>
#include "Components/component.h"
class Simulator
{
public:
    Simulator(std::vector<Component *> &comp, int &iter, int &number_of_lines, double &time);
    void run_simulation() const;

private:
    std::vector<Component *> components;
    int iterations;
    int lines;
    double time_unit;
};

#endif