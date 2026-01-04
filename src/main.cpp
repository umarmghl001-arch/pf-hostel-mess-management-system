#include <iostream>

using namespace std;

int main() {
    int choice;
    

    do {
        cout << "\n========== HOSTEL MESS MANAGEMENT ==========\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Update Student Meals\n";
        
        cout << "Enter your choice: ";
        cin >> choice;

        
    } while (choice != 6);

    return 0;
}