#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Struct to represent train information
struct Train {
    int number;
    string name;
    string departureTime;
    string arrivalTime;
};

// Function to display the current trains
void displayTrains(const vector<Train>& trains) {
    cout << "Trains: " << endl;
    for (const Train& train : trains) {
        cout << "Train Number: " << train.number << endl;
        cout << "Train Name: " << train.name << endl;
        cout << "Departure Time: " << train.departureTime << endl;
        cout << "Arrival Time: " << train.arrivalTime << endl;
        cout << "-------------------------" << endl;
    }
}

int main() {
    vector<Train> trains;
    int choice;

    do {
        // Display the menu
        cout << "Menu:" << endl;
        cout << "1. Add Train" << endl;
        cout << "2. Delete Train" << endl;
        cout << "3. Update Train" << endl;
        cout << "4. Search Train" << endl;
        cout << "5. Sort Trains by Number" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Train newTrain;
                cout << "Enter Train Number: ";
                cin >> newTrain.number;
                cout << "Enter Train Name: ";
                cin >> newTrain.name;
                cout << "Enter Departure Time: ";
                cin >> newTrain.departureTime;
                cout << "Enter Arrival Time: ";
                cin >> newTrain.arrivalTime;
                trains.push_back(newTrain);
                cout << "Train Number " << newTrain.number << " added." << endl;
                displayTrains(trains);
                break;
            }
            case 2: {
                int trainNumberToDelete;
                cout << "Enter Train Number to delete: ";
                cin >> trainNumberToDelete;
                auto it = find_if(trains.begin(), trains.end(), [trainNumberToDelete](const Train& train) {
                    return train.number == trainNumberToDelete;
                });
                if (it != trains.end()) {
                    trains.erase(it);
                    cout << "Train Number " << trainNumberToDelete << " deleted." << endl;
                } else {
                    cout << "Train Number " << trainNumberToDelete << " not found." << endl;
                }
                displayTrains(trains);
                break;
            }
            case 3: {
                int trainNumberToUpdate;
                cout << "Enter Train Number to update: ";
                cin >> trainNumberToUpdate;
                auto it = find_if(trains.begin(), trains.end(), [trainNumberToUpdate](const Train& train) {
                    return train.number == trainNumberToUpdate;
                });
                if (it != trains.end()) {
                    cout << "Enter new Train Name: ";
                    cin >> it->name;
                    cout << "Enter new Departure Time: ";
                    cin >> it->departureTime;
                    cout << "Enter new Arrival Time: ";
                    cin >> it->arrivalTime;
                    cout << "Train Number " << trainNumberToUpdate << " updated." << endl;
                } else {
                    cout << "Train Number " << trainNumberToUpdate << " not found." << endl;
                }
                displayTrains(trains);
                break;
            }
            case 4: {
                int trainNumberToSearch;
                cout << "Enter Train Number to search: ";
                cin >> trainNumberToSearch;
                auto it = find_if(trains.begin(), trains.end(), [trainNumberToSearch](const Train& train) {
                    return train.number == trainNumberToSearch;
                });
                if (it != trains.end()) {
                    cout << "Train Number " << trainNumberToSearch << " found." << endl;
                    cout << "Train Name: " << it->name << endl;
                    cout << "Departure Time: " << it->departureTime << endl;
                    cout << "Arrival Time: " << it->arrivalTime << endl;
                } else {
                    cout << "Train Number " << trainNumberToSearch << " not found." << endl;
                }
                break;
            }
            case 5:
                sort(trains.begin(), trains.end(), [](const Train& a, const Train& b) {
                    return a.number < b.number;
                });
                cout << "Trains sorted by number." << endl;
                displayTrains(trains);
                break;
            case 6:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
