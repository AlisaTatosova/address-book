#include "filehandler.h"

void FileSaver::save_to_file(const std::vector<Contact>& contacts) {
        for (auto& contact : contacts) {
            std::ofstream file("Contacts.txt");
            file << "         Contacts            \n";
            file << "---------------------------------\n";
            if (file.is_open()) {
                for (auto it = contacts.begin(); it != contacts.end(); ++it) {
                    file << "Name: " << (*it).get_name() << "\n";
                    file << "Surname: " << (*it).get_surname() << "\n";
                    file << "Email: " << (*it).get_email() << "\n";
                }
            }
        }
}