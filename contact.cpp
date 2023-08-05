#include "contact.h"


Contact::Contact(const std::string& name, const std::string& surname, const std::string& email) 
    : name{name}, surname{surname}, email{email} {}

std::string Contact::get_name() const {
    return name;
}

std::string Contact::get_surname() const {
    return surname;
}

std::string Contact::get_email() const {
    return email;
}

void Contact::set_name(const std::string& name) {
    this -> name = name;
}

void Contact::display_contact_details() {
    std::cout << "Contact details \n";
    std::cout << "---------------------------\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Surname: " << surname << "\n";
    std::cout << "Email: " << email << "\n";
}
