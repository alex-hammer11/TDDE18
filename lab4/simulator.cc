#include "simulator.h"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

Simulator::Simulator(vector<Component *> &comp, int &iter, int &number_of_lines, double &time)
    : components{comp}, iterations{iter}, lines{number_of_lines}, time_unit{time}
{
}

void Simulator::run_simulation() const
{
    cout << "Running simulation ..." << endl;

    for (Component *comp : components)
    {
        comp->print_name();
    }

    cout << endl;

    for (int i{0}; i < int(components.size()); ++i)
    {
        cout << setw(0) << " Volt  Curr   ";
    }

    cout << endl;

    for (int i{0}; i <= iterations; ++i)
    {
        for (Component *comp : components)
        {
            comp->calculation(time_unit);
        }
        if (i % (iterations / lines) == 0 && i != 0)
        {
            for (Component *comp : components)
            {
                comp->print_component();
                cout << "    ";
            }
            cout << endl;
        }
    }
}