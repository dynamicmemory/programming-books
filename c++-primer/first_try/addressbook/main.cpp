// Load file on startup and print to screen 
// Crud to file and save any changes 
// Sort contacts 

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdint>
using std::string, std::vector, std::cout, std::cin, std::endl;

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
    AddressBook(string file) : filename(std::move(file)) {
        contact_list = populate_contacts();
    }

    void add_contact(string a, string b, string c);
    void edit_contact(string a, string b, string c);
    void delete_contact(string a);
    void update_addressbook();
    const vector<Contact> get_contact_list() const;
    vector<Contact> populate_contacts();

private:
    string filename;
    vector<Contact> contact_list;
};

vector<Contact> AddressBook::populate_contacts() {
    vector<Contact> temp;
    // Open a filestream for the addressbook filename
    std::ifstream fin(filename);
    // If file doesnt exist, create it
    if (!fin) {
        std::ofstream create(filename);
        fin.open(filename);
    }
    
    string line;
    while (std::getline(fin, line)) {
        std::stringstream ss(line);
        string fname, lname, number;

        if (std::getline(ss, fname, ',') &&
                std::getline(ss, lname, ',') &&
                std::getline(ss, number, ',')) {
            Contact new_contact(fname, lname, number);
            temp.push_back(new_contact);
        }
    }

    return temp;
}

/* Returns a copy of the class variable 'contact_list' */
const vector<Contact> AddressBook::get_contact_list() const {
    vector<Contact> copy = contact_list;
    return copy;
}

void AddressBook::add_contact(string fname, string lname, string number) {
    Contact c(fname, lname, number);
    contact_list.push_back(c);
    update_addressbook();
}

void AddressBook::edit_contact(string fname, string lname, string number) {
    // Edits a match entry to users new fields 
}

void AddressBook::delete_contact(string number) {
    for (auto it=contact_list.begin(); it != contact_list.end(); ++it) {
        if (it->get_number() == number) { 
            contact_list.erase(it);
            cout << number << " was removed from your contacts" << endl;
            update_addressbook(); 
            return;
        }
    }
    cout << number << " is not in your contacts." << endl;
}

void AddressBook::update_addressbook() {
    std::ofstream fout(filename);
    for (const auto &contact : contact_list)
        fout << contact.get_firstname() << ','
            << contact.get_lastname() << ','
            << contact.get_number() << '\n';
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "usage: ./main filename" << endl;
        return 1;
    }

    string fname = argv[1]; 
    // string fname = "./contacts.txt";
    AddressBook book(fname);

    cout << "First Name\tLast Name\tPhone Number" << "\n";
    while (true) {
        vector<Contact> list = book.get_contact_list(); 
        for (auto contact : list) {
            cout << contact.get_firstname() << "\t\t" <<
                contact.get_lastname() << "\t\t" <<
                contact.get_number() << endl;
        }

        string command;
        cout << "Enter a command (add, edit, delete, exit)\n>> ";
        cin >> command;

        if (command == "add") {
            string fname, lname, number;
            cout << "Enter the contacts first name.\n>> ";
            cin >> fname;
            cout << "Enter the contacts last name.\n>> ";
            cin >> lname;
            cout << "Enter the contacts number.\n>> ";
            cin >> number;
            book.add_contact(fname, lname, number);
        }
        else if (command == "delete") {
            string number;
            cout << "Enter the contacts number.\n>> ";
            cin >> number;
            book.delete_contact(number);
        }
        else if (command == "exit") {
            return 0;
        }
    }

    return 0;
}
