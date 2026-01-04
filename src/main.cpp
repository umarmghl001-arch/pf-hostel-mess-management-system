#include <iostream>

using namespace std;

const int MAX = 100;
int rollNo[MAX], meals[MAX];
string name[MAX];
int totalStudents = 0;

void loadStudents();
void saveStudents();

int main() {
    int choice;
    

    do {
        cout << "\n========== HOSTEL MESS MANAGEMENT ==========\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Update Student Meals\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            
            case 2: displayStudents(); break;
            
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
