#include <iostream>
#include <string>
#include <list>
using namespace std;

struct Contact {
    string name;
    string mobileNumber;
};

class ContactList {
private:
    list<Contact> contacts;

public:
    // Add a new contact
    void addContact(const std::string& name, const std::string& mobileNumber) {
        Contact newContact;
        newContact.name = name;
        newContact.mobileNumber = mobileNumber;
        contacts.push_back(newContact);
    }

    // Search for a contact by name
    Contact* findContact(const std::string& name) {
        for (auto& contact : contacts) {
            if (contact.name == name) {
                return &contact;
            }
        }
        return nullptr; // Contact not found
    }

    // Display all contacts
    void displayContacts() {
        for (const auto& contact : contacts) {
            std::cout << "Name: " << contact.name << ", Mobile: " << contact.mobileNumber << std::endl;
        }
    }
};

int main() {
    ContactList myContacts;

    myContacts.addContact("lishika", "123-456-7890");
    myContacts.addContact("krishna", "987-654-3210");

    std::string searchName = "lishika";
    Contact* foundContact = myContacts.findContact(searchName);
    if (foundContact) {
        std::cout << "Found contact: " << foundContact->name << ", Mobile: " << foundContact->mobileNumber << std::endl;
    } else {
        std::cout << "Contact not found." << std::endl;
    }

    std::cout << "\nAll contacts:\n";
    myContacts.displayContacts();

    return 0;
}
