#include <iostream>
#include <vector>
using namespace std;

class Student {
public:
    string id;
    string name;
    string department;
    int room;

    Student(string id, string name, string department, int room) {
        this->id = id;
        this->name = name;
        this->department = department;
        this->room = room;
    }

    string getInfo() const {
        return "ID: " + id + "\nNAME: " + name + "\nDEPARTMENT: " + department + "\nROOM: " + to_string(room);
    }
};

class HostelManager {
private:
    vector<Student> students;

    void initializeStudents() {
        students.push_back(Student("023-22-0056", "ALLAHDAD", "COMPUTER SCIENCE", 1));
        students.push_back(Student("023-22-0057", "HALAR", "COMPUTER SCIENCE", 2));
        students.push_back(Student("023-22-0058", "KHAN", "COMPUTER SCIENCE", 3));
    }

public:
    HostelManager() {
        initializeStudents();
    }

    void displayStudents() const {
        if (students.empty()) {
            cout << "* STUDENTS ARE NOT ENROLLED *" << endl;
        } else {
            for (const auto& student : students) {
                cout << student.getInfo() << endl << endl;
            }
        }
    }

    void enrollStudent(string id, string name, string department, int room) {
        if (students.size() < 10) {
            students.push_back(Student(id, name, department, room));
            cout << "* SUCCESSFULLY ENROLLED *" << endl;
        } else {
            cout << "* SORRY, NO VACANCY *" << endl;
        }
    }

    void searchStudent(string query) const {
        int count = 0;
        for (const auto& student : students) {
            if (query == student.name || query == student.id || query == student.department) {
                cout << student.getInfo() << endl << endl;
                count++;
            }
        }
        if (count == 0) {
            cout << "* STUDENT NOT FOUND *" << endl;
        }
    }

    void deleteStudent(string query) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (query == it->name || query == it->id || query == it->department) {
                cout << it->getInfo() << endl << "* UNENROLLED SUCCESSFULLY *" << endl;
                students.erase(it);
                return;
            }
        }
        cout << "* STUDENT NOT FOUND *" << endl;
    }

    void searchRoom(int roomNumber) const {
        int count = 0;
        for (const auto& student : students) {
            if (roomNumber == student.room) {
                cout << student.getInfo() << endl << endl;
                count++;
            }
        }
        if (count == 0) {
            cout << "* NO STUDENT FOUND IN THIS ROOM *" << endl;
        }
    }
};

void enrollStudent(HostelManager& hostelManager) {
    string id, name, department;
    int room;
    cout << "Enter the ID: ";
    cin >> id;
    cout << "Enter the Name: ";
    cin >> name;
    cout << "Enter the Department: ";
    cin >> department;
    cout << "Enter the Room: ";
    cin >> room;
    hostelManager.enrollStudent(id, name, department, room);
}

void searchStudent(const HostelManager& hostelManager) {
    string query;
    cout << "Enter the Name/ID/Department: ";
    cin >> query;
    hostelManager.searchStudent(query);
}

void deleteStudent(HostelManager& hostelManager) {
    string query;
    cout << "Enter the Name/ID/Department: ";
    cin >> query;
    hostelManager.deleteStudent(query);
}

void searchRoom(const HostelManager& hostelManager) {
    int roomNumber;
    cout << "Enter the Room Number: ";
    cin >> roomNumber;
    hostelManager.searchRoom(roomNumber);
}

int main() {
    HostelManager hostelManager;
    int option;

    do {
        cout << "\n...... HOSTEL MANAGEMENT ......\n";
        cout << "1. ENROLLED STUDENTS\n";
        cout << "2. ENROLL NEW STUDENT\n";
        cout << "3. SEARCH STUDENT\n";
        cout << "4. DELETE STUDENT\n";
        cout << "5. SEARCH ROOM\n";
        cout << "0. EXIT\n";
        cout << "SELECT THE ABOVE OPTION: ";
        cin >> option;

        switch (option) {
            case 1:
                hostelManager.displayStudents();
                break;
            case 2:
                enrollStudent(hostelManager);
                break;
            case 3:
                searchStudent(hostelManager);
                break;
            case 4:
                deleteStudent(hostelManager);
                break;
            case 5:
                searchRoom(hostelManager);
                break;
            case 0:
                cout << "Exiting... Goodbye!" << endl;
                break;
            default:
                cout << "Invalid option. Try again." << endl;
        }
    } while (option != 0);

    return 0;
}
