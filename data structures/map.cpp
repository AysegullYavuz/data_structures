#include <iostream> 
#include <map> 
#include <string> 

//phonebook

using namespace std; 

class PhoneBook { // Phone book class
private:
    map<string, string> book; //A map key-value to store names and phone numbers

public:
    void add(string name, string number) { // function to add people
        book[name] = number; // Adds name and number to map
    }

    string search(string number) { //  Function to find out whose number is
        for(map<string, string>::iterator it = book.begin(); it != book.end(); ++it) {
            if(it->second == number) {
                return it->second; // When the number is found, it returns the name
            }
        }
        return "Number not found in book."; //Returns an error message if the number is not found
    }

    void remove(string name) { // Function to delete a contact
        book.erase(name); // Removes name from map
    }

    void update(string name, string new_number) { // Function to update a contact's number
        book[name] = new_number; // Adds the new number to the map
    }

    int person_count() { // Function to return the number of contacts in the phone book
        return book.size(); // Returns the size of the map
    }

    void list() { // Function to list all contacts
        for(map<string, string>::iterator it = book.begin(); it != book.end(); ++it) {
            cout << it->first << ": " << it->second << endl; // Prints each person's name and number
        }
    }

    void list_between(string start, string end) { // Function to list contacts in a certain range
        map<string, string>::iterator it1 = book.lower_bound(start);
        map<string, string>::iterator it2 = book.upper_bound(end);
        for(map<string, string>::iterator it = it1; it != it2; ++it) {
            cout << it->first << ": " << it->second << endl; // Prints the name and number of each person in the range
        }
    }
};

int main() { 
    PhoneBook book; // Creates a phone book object
    book.add("Ali", "1234567890"); // Adds people
    book.add("Aysegul", "0987654321");
    book.add("Melisa", "7349378920");
    book.add("Zeynep", "4235768982");
    cout << "Ali's number: " << book.search("1234567890") << endl; //  calls Ali's number and prints it.
    book.remove("Ali"); // deletes Ali
    book.update("Ayse", "1111111111"); // Updates Ayþegul's number
    cout << "Number of people in book: " << book.person_count() << endl; //Prints the number of contacts in the phonebook
    cout << "People between Aysegul and Zeynep:\n";
    book.list_between("Aysegul", "Zeynep"); // Lists the contacts between Ayþegul and Zeynep
    return 0; 
}

