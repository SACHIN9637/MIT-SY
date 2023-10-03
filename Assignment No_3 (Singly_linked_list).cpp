//2.Railway Reservation System..


#include <iostream>
#include <cstring>

using namespace std;

class Node {
public:
    char trainName[50];
    int id;
    int trainNumber;
    Node* next;
};

class sll {
public:
    Node* head;
	sll()
	{
        head = NULL;
    }

    void create();
    void display();
    void insert();
    void update();
    void del();
    void search();
    void sort();
};

void sll::create() {
    Node* temp, * p;
    char ch;
    do {
        temp = new Node;
        cout << "Enter Train Name: ";
        cin >> temp->trainName;

        cout << "Enter Train Number: ";
        cin >> temp->trainNumber;

        cout << "Enter ID: ";
        cin >> temp->id;

        temp->next = NULL;

        if (head == NULL) {
            head = temp;
        }
        else {
            p = head;
            while (p->next != NULL)
                p = p->next;
            p->next = temp;
        }
        cout << "Do you want to add more trains (y/n): ";
        cin >> ch;
    } while (ch == 'y');
}

void sll::display() {
    Node* temp;
    temp = head;

    cout << "Train Name\tTrain Number\tID" << endl;
    while (temp != NULL) {
        cout << temp->trainName << "\t\t" << temp->trainNumber << "\t\t" << temp->id;
        cout << endl;
        temp = temp->next;
    }
}

void sll::insert() {
    Node* temp, * p;
    temp = new Node;
    char ch;
    char info[50];

    cout << "Enter Values to insert" << endl;

    cout << "Enter Train Name: ";
    cin >> temp->trainName;

    cout << "Enter Train Number: ";
    cin >> temp->trainNumber;

    cout << "Enter ID: ";
    cin >> temp->id;

    temp->next = NULL;

    cout << "Do you want to insert at the beginning (y/n): ";
    cin >> ch;
    p = head;

    if (ch == 'y') {
        temp->next = p;
        head = temp;
    }
    else {
        cout << "Enter Train Name After Which you want to add: ";
        cin >> info;
        while (p != NULL) {
            if (strcmp(p->trainName, info) == 0) {
                temp->next = p->next;
                p->next = temp;
                break;
            }
            else
                p = p->next;
        }
    }
}

void sll::update() {
    char key[50];
    cout << "Enter Train Name to Update: ";
    cin >> key;

    Node* temp = head;

    while (temp != NULL) {
        if (strcmp(temp->trainName, key) == 0) {
            cout << "Enter new Train Name: ";
            cin >> temp->trainName;

            cout << "Enter new Train Number: ";
            cin >> temp->trainNumber;

            cout << "Enter new ID: ";
            cin >> temp->id;

            cout << "Record updated successfully." << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Record Not Found" << endl;
}

void sll::del() {
    Node* temp, * prev;

    char key[50];

    temp = head;
    prev = NULL;

    cout << "Enter Train Name to Delete: ";
    cin >> key;

    while (temp != NULL) {

        if (strcmp(temp->trainName, key) == 0) {
            if (temp == head) {
                head = head->next;
                delete (temp);
                cout << "Record deleted successfully." << endl;
                return;
            }
            else {
                prev->next = temp->next;
                delete (temp);
                cout << "Record deleted successfully." << endl;
                return;
            }
        }
        else {
            prev = temp;
            temp = temp->next;
        }
    }
    cout << "Record Not Found" << endl;
}

void sll::search() {
    char key[50];
    Node* temp = head;
    cout << "Enter Train Name to Search: ";
    cin >> key;
    while (temp != NULL) {
        if (strcmp(temp->trainName, key) == 0) {
            cout << "Record Found" << endl;
            cout << "Train Name\tTrain Number\tID" << endl;
            cout << temp->trainName << "\t\t" << temp->trainNumber << "\t\t" << temp->id;
            cout << endl;
            return;
        }
        else
            temp = temp->next;
    }
    cout << "Record Not Found" << endl;
}

void sll::sort() {
    if (head == NULL) {
        cout << "List is empty. Nothing to sort." << endl;
        return;
    }

    Node* current = head;
    Node* index = NULL;
    int tempNum;
    char tempName[50];
    int tempId;

    while (current != NULL) {
        index = current->next;

        while (index != NULL) {
            if (strcmp(current->trainName, index->trainName) > 0) {
                
                strcpy(tempName, current->trainName);
                strcpy(current->trainName, index->trainName);
                strcpy(index->trainName, tempName);

         
                tempNum = current->trainNumber;
                current->trainNumber = index->trainNumber;
                index->trainNumber = tempNum;

                
                tempId = current->id;
                current->id = index->id;
                index->id = tempId;
            }
            index = index->next;
        }
        current = current->next;
    }
}

int main() {
    int choice;
    sll railwaySystem;

    cout << "Welcome to the Railway Reservation System" << endl;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Create Entry" << endl;
        cout << "2. Add Entry" << endl;
        cout << "3. Update Entry" << endl;
        cout << "4. Delete Entry" << endl;
        cout << "5. Search Entry" << endl;
        cout << "6. Sort Entries" << endl;
        cout << "7. Display Entries" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            railwaySystem.create();
            break;
        case 2:
            railwaySystem.insert();
            break;
        case 3:
            railwaySystem.update();
            break;
        case 4:
            railwaySystem.del();
            break;
        case 5:
            railwaySystem.search();
            break;
        case 6:
            railwaySystem.sort();
            cout << "Entries sorted successfully." << endl;
            break;
        case 7:
            railwaySystem.display();
            break;
        case 8:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
            break;
        }
    } while (choice != 8);

    return 0;
}


// OUTPUT

//Welcome to the Railway Reservation System
//
//Menu:
//1. Create Entry
//2. Add Entry
//3. Update Entry
//4. Delete Entry
//5. Search Entry
//6. Sort Entries
//7. Display Entries
//8. Exit
//Enter your choice: 1
//Enter Train Name: punenandedexp
//Enter Train Number: 17629
//Enter ID: 17629
//Do you want to add more trains (y/n): y
//Enter Train Name: pnvlnandedexp
//Enter Train Number: 17613
//Enter ID: 17613
//Do you want to add more trains (y/n): n
//
//Menu:
//1. Create Entry
//2. Add Entry
//3. Update Entry
//4. Delete Entry
//5. Search Entry
//6. Sort Entries
//7. Display Entries
//8. Exit
//Enter your choice: 2
//Enter Values to insert
//Enter Train Name: hdpnandedspl
//Enter Train Number: 07404
//Enter ID: 07404
//Do you want to insert at the beginning (y/n): y
//
//Menu:
//1. Create Entry
//2. Add Entry
//3. Update Entry
//4. Delete Entry
//5. Search Entry
//6. Sort Entries
//7. Display Entries
//8. Exit
//Enter your choice: 2
//Enter Values to insert
//Enter Train Name: punefestivlspl
//Enter Train Number: 02729
//Enter ID: 02729
//Do you want to insert at the beginning (y/n): y
//
//Menu:
//1. Create Entry
//2. Add Entry
//3. Update Entry
//4. Delete Entry
//5. Search Entry
//6. Sort Entries
//7. Display Entries
//8. Exit
//Enter your choice: 7
//Train Name      Train Number    ID
//punefestivlspl          2729            2729
//hdpnandedspl            7404            7404
//punenandedexp           17629           17629
//pnvlnandedexp           17613           17613
//
//Menu:
//1. Create Entry
//2. Add Entry
//3. Update Entry
//4. Delete Entry
//5. Search Entry
//6. Sort Entries
//7. Display Entries
//8. Exit
//Enter your choice: 3
//Enter Train Name to Update: pnvlnandedexp
//Enter new Train Name: nandedexp
//Enter new Train Number: 963730
//Enter new ID: 963730
//Record updated successfully.
//
//Menu:
//1. Create Entry
//2. Add Entry
//3. Update Entry
//4. Delete Entry
//5. Search Entry
//6. Sort Entries
//7. Display Entries
//8. Exit
//Enter your choice: 7
//Train Name      Train Number    ID
//punefestivlspl          2729            2729
//hdpnandedspl            7404            7404
//punenandedexp           17629           17629
//nandedexp               963730          963730
//
//Menu:
//1. Create Entry
//2. Add Entry
//3. Update Entry
//4. Delete Entry
//5. Search Entry
//6. Sort Entries
//7. Display Entries
//8. Exit
//Enter your choice: 4
//Enter Train Name to Delete: hdpnandedspl
//Record deleted successfully.
//
//Menu:
//1. Create Entry
//2. Add Entry
//3. Update Entry
//4. Delete Entry
//5. Search Entry
//6. Sort Entries
//7. Display Entries
//8. Exit
//Enter your choice: 7
//Train Name      Train Number    ID
//punefestivlspl          2729            2729
//punenandedexp           17629           17629
//nandedexp               963730          963730
//
//Menu:
//1. Create Entry
//2. Add Entry
//3. Update Entry
//4. Delete Entry
//5. Search Entry
//6. Sort Entries
//7. Display Entries
//8. Exit
//Enter your choice: 5
//Enter Train Name to Search: nandedexp
//Record Found
//Train Name      Train Number    ID
//nandedexp               963730          963730
//
//Menu:
//1. Create Entry
//2. Add Entry
//3. Update Entry
//4. Delete Entry
//5. Search Entry
//6. Sort Entries
//7. Display Entries
//8. Exit
//Enter your choice: 6
//Entries sorted successfully.
//
//Menu:
//1. Create Entry
//2. Add Entry
//3. Update Entry
//4. Delete Entry
//5. Search Entry
//6. Sort Entries
//7. Display Entries
//8. Exit
//Enter your choice: 7
//Train Name      Train Number    ID
//nandedexp               963730          963730
//punefestivlspl          2729            2729
//punenandedexp           17629           17629
//
//Menu:
//1. Create Entry
//2. Add Entry
//3. Update Entry
//4. Delete Entry
//5. Search Entry
//6. Sort Entries
//7. Display Entries
//8. Exit
//Enter your choice: 8
//Exiting program.

