#ifndef UNTITLED_PEOPLE_H
#define UNTITLED_PEOPLE_H

class People {
protected:
    string name, address;
    int taxNumber;
};

class Employee : public People{
private:
    float salary;
    string pharmacy, post;
};

class Client : public People{
};

#endif //UNTITLED_PEOPLE_H
