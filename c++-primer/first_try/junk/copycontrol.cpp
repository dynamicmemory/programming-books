#include <iostream>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()) : 
        ps(new std::string(s)), i(0) {}

    HasPtr(const HasPtr &rhs) : ps(new std::string(*rhs.ps)), i(rhs.i) {}
    HasPtr& operator=(const HasPtr &);
    ~HasPtr() { delete ps; }
    void swap(HasPtr &rhs, HasPtr &lhs) {
        std::swap(lhs.ps, rhs.ps);
        std::swap(lhs.i, rhs.i);
    }

private: 
    std::string *ps;
    int i;
};

HasPtr &HasPtr::operator=(const HasPtr &rhs) {
        if (this == &rhs) 
            return *this;

        std::string *newps = new std::string(*rhs.ps);
        delete ps;

        ps = newps;
        i = rhs.i;

        return *this;
    }


class Numbered {
public:
    Numbered() : mysn(1) {}

    Numbered(const Numbered &rhs) : mysn(rhs.mysn) {}
    Numbered &operator=(const Numbered &rhs) { 
        if (this == &rhs) 
            return *this;

        mysn = rhs.mysn;
        return *this;
    }
    ~Numbered() {}

private:
    int mysn;

};

class Employee {
public: 
    Employee() {
        name = "None";
        id = ++employee_number;
    }
    Employee(std::string &s) : name(s), id(++employee_number) {}



private:
    std::string name;
    int id;
    static int employee_number;
};

int Employee::employee_number = 0;
