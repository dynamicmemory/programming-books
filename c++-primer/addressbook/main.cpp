// Load file on startup and print to screen 
// Crud to file and save any changes 
// Sort contacts 

#include <iostream>
#include <vector>
#include <cstdint>
using std::string, std::vector;

class Contact {
public:
    Contact(string f, string l, string n) : fname(std::move(f)), 
                                            lname(std::move(l)), 
                                            number(std::move(n)) {}

    const string &get_firstname() const {return fname;}
    const string &get_lastname() const {return lname;}
    const string &get_number() const {return number;}

    void set_first_name(string a) { fname=std::move(a); }
    void set_last_name(string a) { lname=std::move(a); }
    void set_number(string a) { number=std::move(a); }
private:
    string fname;
    string lname;
    string number;
};

class AddressBook {
public:
    AddressBook(string file) : filename(file) {}

    void add_contact(Contact c);
    void edit_contact(Contact c);
    void delete_contact(Contact c);

private:
    string filename;
    vector<Contact> contact_list;
    vector<Contact> populate_contacts();
};

vector<Contact> populate_contacts() {
    vector<Contact> temp;
    // Try to read file and parse in contents 
    return temp;
}

void add_contact(Contact c) {

}

void edit_contact(Contact c) {

}

void delete_contact(Contact c) {

}

int main(int argc, char *argv[]) {
    string fname = "./contacts";
    AddressBook book(fname);

    return 0;
}
