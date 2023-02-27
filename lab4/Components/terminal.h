#ifndef TERMINAL_H
#define TERMINAL_H

class Terminal
{
public:
    Terminal();
    ~Terminal();
    void setCharge(double value);
    double getCharge() const;

private:
    double charge;
};

#endif