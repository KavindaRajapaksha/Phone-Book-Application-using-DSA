#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

struct PhonebookRecord {  //creat node class
    string first_name;
    string last_name;
    string phone_number;
    string nic_number;
    string gender;
    PhonebookRecord* next;
};

class Phonebook {
private:
    PhonebookRecord* head;
public:
    Phonebook() {
        head = NULL;
    }

    void addRecord() {  //for insert data
        PhonebookRecord* newRecord = new PhonebookRecord; // create a new node
        cout << "\n ####### ADD NEW RECORD ####### \n" << endl;
        cout << "Enter first name: ";
        cin >> newRecord->first_name;
        cout << "Enter last name: ";
        cin >> newRecord->last_name;
        cout << "Enter phone number: ";
        cin >> newRecord->phone_number;
        cout << "Enter NIC number: ";
        cin >> newRecord->nic_number;
        cout << "Enter gender: ";
        cin >> newRecord->gender;
        newRecord->next = head;
        head = newRecord;
        cout << "Record added successfully." << endl;
        cout << " " << endl;
    }

    void sortRecords() {
        if (head == NULL) {
            cout << "No records found." << endl;
            cout << " " << endl;
            return;
        }
        int size = 0;
        PhonebookRecord* currentRecord = head;
        while (currentRecord != NULL) {  // counting the size of the linked list
            size++;
            currentRecord = currentRecord->next;
        }
        for (int i = 0; i < size - 1; i++) {
            currentRecord = head;
            for (int j = 0; j < size - i - 1; j++) {
                if (currentRecord->first_name > currentRecord->next->first_name) { //swap nodes
                    PhonebookRecord* temp = currentRecord;
                    currentRecord = currentRecord->next;
                    temp->next = currentRecord->next;
                    currentRecord->next = temp;
                    if (j == 0) {                   
                        head = currentRecord;       
                    }
                    else {
                        PhonebookRecord* previousRecord = head;
                        for (int k = 0; k < j - 1; k++) {
                            previousRecord = previousRecord->next;
                        }
                        previousRecord->next = currentRecord;
                    }
                }
                else {
                    currentRecord = currentRecord->next;
                }
            }
        }
        cout << "Records sorted successfully." << endl;
        cout << " " << endl;
    }


    void viewRecords() {  //for view the records which are added previously
        cout << "\n ####### VIEW RECORDS ####### \n" << endl;
        if (head == NULL) {
            cout << "No records found." << endl;
            cout << " " << endl;
            return;
        }
        PhonebookRecord* currentRecord = head;
        int i = 1;
        while (currentRecord != NULL) {
            cout << "**Record " << i << "**\n"<<endl;
            cout << "First Name: " << currentRecord->first_name << endl;
            cout << "Last Name: " << currentRecord->last_name << endl;
            cout << "Phone Number: " << currentRecord->phone_number << endl;
            cout << "NIC Number: " << currentRecord->nic_number << endl;
            cout << "Gender: " << currentRecord->gender << endl;
            cout << endl;
            i++;
            currentRecord = currentRecord->next;
        }
    }

    void modifyRecord() {  //for the chnge the records
        cout << "\n ####### MODIFY RECORD ####### \n" << endl;
        if (head == NULL) {
            cout << "No records found." << endl;
            cout << " " << endl;
            return;
        }
        string firstNameToModify;
        cout << "Enter the first name of the record you want to modify: ";
        cin >> firstNameToModify;
        PhonebookRecord* currentRecord = head;
        while (currentRecord != NULL) {
            if (currentRecord->first_name == firstNameToModify) {
                cout << "Enter new first name: ";
                cin >> currentRecord->first_name;
                cout << "Enter new last name: ";
                cin >> currentRecord->last_name;
                cout << "Enter new phone number: ";
                cin >> currentRecord->phone_number;
                cout << "Enter new NIC number: ";
                cin >> currentRecord->nic_number;
                cout << "Enter new gender: ";
                cin >> currentRecord->gender;
                cout << "Record modified successfully." << endl;
                return;
            }
            currentRecord = currentRecord->next;
        }
        cout << "Record not found.\n" << endl;
        
    }

    void deleteRecord() {
        cout << "\n ####### DELETE RECORD ####### \n" << endl;
        if (head == NULL) {
            cout << "No records found.\n" << endl;
            return;
        }
        string firstNameToDelete;
        cout << "Enter the first name of the record you want to delete: ";
        cin >> firstNameToDelete;//enter the firstname to delete;
        PhonebookRecord* currentRecord = head;
        PhonebookRecord* previousRecord = NULL;
        while (currentRecord != NULL) {
            if (currentRecord->first_name == firstNameToDelete) {
                if (previousRecord == NULL) {
                    head = currentRecord->next;
                }
                else {
                    previousRecord->next = currentRecord->next;
                }
                delete currentRecord;
                cout << "Record deleted successfully." << endl;
                cout << " " << endl;
                return;
            }
            previousRecord = currentRecord;
            currentRecord = currentRecord->next;
        }
        cout << "Record not found. \n" << endl;
        
    }
    
    void searchRecords() {
        cout << "\n ####### SEARCH RECORD ####### \n" << endl;
        if (head == NULL) {
            cout << "No records found.\n" << endl;
            
            return;
        }
        string search;
        cout << "Enter the first name or the phone number to search :  ";
        cin >> search;  //enter the first name or phone number to search
        PhonebookRecord* currentRecord = head;
        bool recordFound = false;
        while (currentRecord != NULL) {
            if (currentRecord->first_name == search || currentRecord->phone_number == search) {
                cout << "\n///// Record found /////\n" << endl;
                cout << "First Name: " << currentRecord->first_name << endl;
                cout << "Last Name: " << currentRecord->last_name << endl;
                cout << "Phone Number: " << currentRecord->phone_number << endl;
                cout << "NIC Number: " << currentRecord->nic_number << endl;
                cout << "Gender: " << currentRecord->gender << endl;
                cout << endl;
                recordFound = true;
            }
            currentRecord = currentRecord->next;
        }
        if (!recordFound) {
            cout << "Record not found.\n" << endl;
            
        }
    }
};

int main() {
    Phonebook phonebook;
    int choice = 0;
    string input;
    do {
        cout << "Phonebook Application" << endl;
        cout << "---------------------" << endl;
        cout << "1. Add Record" << endl;
        cout << "2. View Records" << endl;
        cout << "3. Modify Record" << endl;
        cout << "4. Delete Record" << endl;
        cout << "5. Search Record" << endl;
        cout << "6. Exit \n" << endl;
        cout << "Enter your choice: ";
        cin >> input;
        try {
            choice = stoi(input);
            switch (choice) {
            case 1:
                phonebook.addRecord();
                break;
            case 2:
                phonebook.sortRecords();
                phonebook.viewRecords();
                break;
            case 3:
                phonebook.modifyRecord();
                break;
            case 4:
                phonebook.deleteRecord();
                break;
            case 5:
                phonebook.searchRecords();
                break;
            case 6:
                cout << "Exiting Phonebook Application. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again.\n" << endl;
                break;
            }
        }
        catch (const invalid_argument& e) 
        {
            cout << "Invalid input. Please enter an integer choice.\n" << endl;
            choice = 0;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (choice != 6);
    return 0;
}




    






