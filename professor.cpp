#include <iostream>
#include <string>

using namespace std;

class Professor {
protected:
    int salary;
public:
    string name;
    Professor(string n) : name(n), salary(100000) {}

    void changeSalary() {salary = 1000000;}
};

class EEProfessor : public Professor {
public:
    int levelOfInsanity;
    int sincerity;
    EEProfessor(string n) : Professor(n) {}
    void doubleSalary() {salary *= 2;}
};

class PhysicsProfessor : public Professor {
public:
    bool monopoly;
    PhysicsProfessor(string n) : Professor(n) {}
};

int main()
{
    EEProfessor fontaine("Fontaine");
    cout << fontaine.name << endl;
    cout << fontaine.salary << endl;
    return 0;
}
