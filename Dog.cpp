#include <string>
#include <iostream>

using namespace std;


class Dog {
public:
    string nm; // name
    
    // constructor
    Dog(const string &name) : nm(name) {
        cout << "IN DOG CONSTRUCTOR " << name << endl;
    }

    // destructor
    ~Dog() {
        cout << "IN DOG DESTRUCTOR " << endl;
    }

    // copy-constructor
    Dog(const Dog &d) {
        nm = d.nm;
    }

    // assignment-operator
    Dog& operator=(const Dog &d) {
        nm = d.nm;
    }

};

class DogHouse {
public:
    Dog *p;
    string houseName;

    // constructor
    DogHouse(Dog *dog, const string &hn) 
        : p(dog), houseName(hn) {
        cout << "IN DOGHOUSE CONSTRUCTOR " << houseName << endl; }

    // copy constructor
    DogHouse (const DogHouse &dh) 
    {
        //p = dh.p;
        p = new Dog("Super");
        houseName = "TWIN of " + dh.houseName;
    }

    // destructor
    ~DogHouse() {
        cout << "IN DOGHOUSE DESTRUCTOR " << endl;
        delete p;
    }

    // assignment operator override
    DogHouse& operator=(const DogHouse& dh) {
        cout << "IN ASSIGMENT OPERATOR " << endl;
        p = new Dog("Star");
        houseName = "TRIPLET OF " + dh.houseName;
    }

};

int main() {
    DogHouse novaHouse(new Dog("Nova"), "NovaHouse");
    cout << "PRINTING " << novaHouse.houseName << " " << novaHouse.p->nm <<endl;

    // Nova's twin is super
    DogHouse superHouse = novaHouse; // triggers copy constr.
    cout << "PRINTING " << superHouse.houseName << " " << superHouse.p->nm <<endl;

    // Star is Nova's triplet
    DogHouse starHouse(new Dog("JUNK"), "JUNK HOUSE"); // note that DogHouse() doesn't exist
    starHouse = novaHouse; // triggers assignment operator
    cout << "PRINTING " << starHouse.houseName << " " << starHouse.p->nm <<endl;
    return 0;
}
