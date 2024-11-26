#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

// Function to create a new file
void createFile(const string& fileName) {
    ofstream outFile(fileName, ios::trunc);
    if (!outFile) {
        cerr << "Error creating the file!" << endl;
        return;
    }
    cout << "File successfully created." << endl;
    outFile.close();
}

// Function to view the list of students with formatted table output
void viewFile(const string& fileName) {
    ifstream inFile(fileName);
    if (!inFile) {
        cerr << "Error opening the file!" << endl;
        return;
    }

    cout << left << setw(20) << "Surname"
        << setw(10) << "Grade 1"
        << setw(10) << "Grade 2"
        << setw(10) << "Grade 3" << endl;
    cout << string(50, '-') << endl;

    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string surname;
        int grade1, grade2, grade3;

        ss >> surname >> grade1 >> grade2 >> grade3;
        cout << left << setw(20) << surname
            << setw(10) << grade1
            << setw(10) << grade2
            << setw(10) << grade3 << endl;
    }

    cout << string(50, '-') << endl;
    inFile.close();
}

// Function to add a new student
void appendToFile(const string& fileName) {
    ofstream outFile(fileName, ios::app);
    if (!outFile) {
        cerr << "Error opening the file!" << endl;
        return;
    }

    string surname;
    int grade1, grade2, grade3;
    cout << "Enter the student's surname: ";
    cin >> surname;
    cout << "Enter three grades separated by spaces: ";
    while (!(cin >> grade1 >> grade2 >> grade3)) {
        cerr << "Input error! Please try again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    outFile << surname << " " << grade1 << " " << grade2 << " " << grade3 << endl;
    cout << "Data successfully added to the file." << endl;

    outFile.close();
}

// Program menu
void showMenu() {
    cout << "\nMenu:\n";
    cout << "1. Create a new file\n";
    cout << "2. View the student list\n";
    cout << "3. Add a new student\n";
    cout << "4. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    string fileName;
    cout << "Enter the file name: ";
    cin >> fileName;

    int choice;
    do {
        showMenu();
        while (!(cin >> choice) || (choice < 1 || choice > 4)) {
            cerr << "Invalid choice! Please try again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice) {
        case 1:
            createFile(fileName);
            break;
        case 2:
            viewFile(fileName);
            break;
        case 3:
            appendToFile(fileName);
            break;
        case 4:
            cout << "Exiting the program." << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}
