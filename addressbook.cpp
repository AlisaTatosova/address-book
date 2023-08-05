#include "addressbook.h"
#include <fstream>
#include <string>

Contact AddressBook::add_contact() {
    std::string name, surname, email;
    bool is_valid = true;
    do {
        is_valid = true;
        std::cout << "Enter customer name: ";
        std::getline(std::cin, name);

        for (char c : name) {
            if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
                is_valid = false;
                break;
            }
        }

        if (!is_valid) {
            std::cout << "Name must contain only letters and cannot be empty. Please enter a valid name.\n";
        }

    } while (!is_valid);

    is_valid = true;

    do {
        is_valid = true;
        std::cout << "Enter customer surname: ";
        std::getline(std::cin, surname);

        for (char c : surname) {
            if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
                is_valid = false;
                break;
            }
        }

        if (!is_valid) {
            std::cout << "SurName must contain only letters and cannot be empty. Please enter a valid surname.\n";
        }

    } while (!is_valid);

    std::cout << "Enter contact information: ";
    std::getline(std::cin, email);

    Contact contact(name, surname, email);
    contacts.push_back(contact);
    std::cout << "Contact " << name << " is added to address book \n";
    return contact;
}

void AddressBook::delete_contact(Contact contact) {
    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        if (contact.get_name() == (*it).get_name()) {
            contacts.erase(it);
            std::cout << "Contact " << contact.get_name() << " is deleted\n";
            break;
        }
        else {
            std::cout << "Such contact is not found! \n";
        }
    }
}

void AddressBook::view_history_of_adding() {
    std::cout << "History of added contacts " << " \n " << "------------------------------------" << "\n";
    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        std::cout << "Name: " << (*it).get_name() << "\n";
        std::cout << "Surname: " << (*it).get_surname() << "\n";
        std::cout << "Email: " << (*it).get_email() << "\n";
    }
}

void AddressBook::update_contact(Contact contact, const std::string& new_name) {
    contact.set_name(new_name);
}

void AddressBook::search_contact(const std::string& name) {
    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        if (name == (*it).get_name()) {
            std::cout << "Contact with the name " << name << " is found \n";
            (*it).display_contact_details();
            break;
        }
        else {
            std::cout << "Such contact is not found! \n";
        }
    }
}

void AddressBook::save_to_file() {
    saver.save_to_file(contacts);
}
