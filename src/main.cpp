#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 100;
int rollNo[MAX], meals[MAX];
string name[MAX];
int totalStudents = 0;

void loadStudents();
void saveStudents();
void displayStudents();

void addStudent() {
    if (totalStudents >= MAX) {
        cout << "Student limit reached!\n";
        return;
    }

    cout << "Enter Roll No: ";
    cin >> rollNo[totalStudents];
    cout << "Enter Name: ";
    cin >> name[totalStudents];
    cout << "Enter Meals Taken: ";
    cin >> meals[totalStudents];

    totalStudents++;
    cout << "Student added successfully!\n";
}

void updateMeals() {
    int r, found = 0;
    cout << "Enter Roll No to update meals: ";
    cin >> r;

    for (int i = 0; i < totalStudents; i++) {
        if (rollNo[i] == r) {
            cout << "Enter new meal count: ";
            cin >> meals[i];
            cout << "Meals updated successfully!\n";
            found = 1;
            break;
        }
    }
    if (!found)
        cout << "Student not found!\n";
}


void deleteStudent() {
    int r, index = -1;
    cout << "Enter Roll No to delete record: ";
    cin >> r;

    for (int i = 0; i < totalStudents; i++) {
        if (rollNo[i] == r) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Student not found!\n";
        return;
    }

    for (int i = index; i < totalStudents - 1; i++) {
        rollNo[i] = rollNo[i + 1];
        name[i] = name[i + 1];
        meals[i] = meals[i + 1];
    }

    totalStudents--;
    cout << "Student record deleted successfully!\n";
}

int main() {
    int choice;
    

    do {
        cout << "\n========== HOSTEL MESS MANAGEMENT ==========\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Update Student Meals\n";
        cout << "4. Delete Student Record\n";
        cout << "6. Save & Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: updateMeals(); break;
            case 4: deleteStudent(); break;
            case 6: saveStudents(); break;
            
            default: cout << "Invalid choice! Try again.\n";
        }

        
    } while (choice != 6);

    return 0;
}


void loadStudents(){
    cout<<"load students";
    ifstream file("mess.txt");
    if (!file)
        return;

    file >> totalStudents;
    for (int i = 0; i < totalStudents; i++) {
        file >> rollNo[i] >> name[i] >> meals[i];
    }
    file.close();
}
void saveStudents(){
    cout<<"save students";

    ofstream file("mess.txt");
    file << totalStudents << endl;

    for (int i = 0; i < totalStudents; i++) {
        file << rollNo[i] << " "
             << name[i] << " "
             << meals[i] << endl;
    }
    file.close();
}


void displayStudents() {
    if (totalStudents == 0) {
        cout << "No records found!\n";
        return;
    }

    cout << "\nRollNo\tName\tMeals\n";
    for (int i = 0; i < totalStudents; i++) {
        cout << rollNo[i] << "\t" << name[i] << "\t" << meals[i] << endl;
    }
}
