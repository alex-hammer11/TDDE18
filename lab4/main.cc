#include "Components/battery.h"
#include "Components/resistor.h"
#include "Components/capacitor.h"
#include "Components/terminal.h"
#include "simulator.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void deallocate_components(vector<Component *> &comp);

void first_circuit(int &iterations, int &lines, double &time, double &battery_volt)
{
    Terminal t1, t2, t3, t4;

    vector<Component *> components;

    components.push_back(new Battery("B1", battery_volt, t4, t1));
    components.push_back(new Resistor("R1", 6, t1, t2));
    components.push_back(new Resistor("R2", 4, t2, t3));
    components.push_back(new Resistor("R3", 8, t3, t4));
    components.push_back(new Resistor("R4", 12, t2, t4));
    Simulator s{components, iterations, lines, time};
    s.run_simulation();
    deallocate_components(components);
}

void second_circuit(int &iterations, int &lines, double &time, double &battery_volt)
{
    Terminal t1, t2, t3, t4;

    vector<Component *> components;

    components.push_back(new Battery("B1", battery_volt, t4, t1));
    components.push_back(new Resistor("R1", 150, t1, t2));
    components.push_back(new Resistor("R2", 50, t1, t3));
    components.push_back(new Resistor("R3", 100, t2, t3));
    components.push_back(new Resistor("R4", 300, t2, t4));
    components.push_back(new Resistor("R5", 250, t3, t4));
    Simulator s{components, iterations, lines, time};
    s.run_simulation();
    deallocate_components(components);
}

void third_circuit(int &iterations, int &lines, double &time, double &battery_volt)
{
    Terminal t1, t2, t3, t4;

    vector<Component *> components;

    components.push_back(new Battery("B1", battery_volt, t4, t1));
    components.push_back(new Resistor("R1", 150, t1, t2));
    components.push_back(new Resistor("R2", 50, t1, t3));
    components.push_back(new Capacitor("C3", 1.0, t2, t3));
    components.push_back(new Resistor("R4", 300, t2, t4));
    components.push_back(new Capacitor("C5", 0.75, t3, t4));
    Simulator s{components, iterations, lines, time};
    s.run_simulation();
    deallocate_components(components);
}

void deallocate_components(vector<Component *> &comp)
{
    for (Component *c : comp)
    {
        delete (c);
    }
}

int main(int argc, char **argv)
{
    try
    {
        if (argc == 5)
        {
            int iterations = stoi(argv[1]);
            int lines = stoi(argv[2]);
            double time = stod(argv[3]);
            double volt = stod(argv[4]);

            first_circuit(iterations, lines, time, volt);
            cout << endl;
            second_circuit(iterations, lines, time, volt);
            cout << endl;
            third_circuit(iterations, lines, time, volt);
        }
        else
        {
            throw(argc);
        }
    }
    catch (int arguments)
    {
        cout << "Wrong number of arguments! Should be 4, you entered " << arguments - 1 << endl;
    }
    return 0;
}