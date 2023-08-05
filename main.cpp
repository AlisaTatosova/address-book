#include "addressbook.h"

int main() {
    FileSaver file_saver;
    AddressBook address_book(file_saver);
    Contact contact1 = address_book.add_contact();
    Contact contact3 = address_book.add_contact();
    Contact contact4 = address_book.add_contact();
    address_book.delete_contact(contact3);
    address_book.search_contact("Alis");
    address_book.view_history_of_adding();
    address_book.save_to_file();
}