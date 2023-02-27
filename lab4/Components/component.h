#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include "terminal.h"

class Component
{
public:
    Component(std::string given_name, Terminal &input, Terminal &output);
    virtual ~Component();

    virtual double calculateCurrent() const = 0;

    virtual void calculation(double) = 0;

    virtual void print_component() const = 0;

    void print_name() const;

protected:
    std::string name;
    Terminal &in;
    Terminal &out;
};

#endif
