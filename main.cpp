#include "System.h"
#include <iostream>
#include <limits>
using namespace std;

void displayMenu() {
    cout << "\n========================================\n";
    cout << "  STUDENTS RECORD AND GRADING SYSTEM\n";
    cout << "========================================\n";
    cout << "1. Add Student\n";
    cout << "2. Add Course\n";
    cout << "3. Enroll Student in Course\n";
    cout << "4. Assign Grade to Enrollment\n";
    cout << "5. Display Student Information\n";
    cout << "6. Display All Courses\n";
    cout << "7. Show Rankings (Sorted by GPA)\n";
    cout << "8. Exit\n";
    cout << "========================================\n";
    cout << "Enter your choice: ";
}

int main() {
    GradeSystem system;
    int choice;
    
    cout << "Welcome to the Students Record and Grading System!\n";
    
    while (true) {
        displayMenu();
        cin >> choice;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number between 1-8.\n";
            continue;
        }
        
        switch (choice) {
            case 1: {
                int studentID;
                string studentName;
                
                cout << "\n--- Add Student ---\n";
                cout << "Enter Student ID: ";
                cin >> studentID;
                
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input!\n";
                    break;
                }
                
                cin.ignore();
                cout << "Enter Student Name: ";
                getline(cin, studentName);
                
                system.addStudent(studentID, studentName);
                break;
            }
            
            case 2: {
                int courseID;
                string courseName;
                
                cout << "\n--- Add Course ---\n";
                cout << "Enter Course ID: ";
                cin >> courseID;
                
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input!\n";
                    break;
                }
                
                cin.ignore();
                cout << "Enter Course Name: ";
                getline(cin, courseName);
                
                system.addCourse(courseID, courseName);
                break;
            }
            
            case 3: {
                int studentID, courseID;
                
                cout << "\n--- Enroll Student in Course ---\n";
                cout << "Enter Student ID: ";
                cin >> studentID;
                
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Invalid input!\n";
                    break;
                }
                
                cout << "Enter Course ID: ";
                cin >> courseID;
                
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input!\n";
                    break;
                }
                
                system.enroll(studentID, courseID);
                break;
            }
            
            case 4: {
                int studentID, courseID;
                double grade;
                
                cout << "\n--- Assign Grade to Enrollment ---\n";
                cout << "Enter Student ID: ";
                cin >> studentID;
                
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input!\n";
                    break;
                }
                
                cout << "Enter Course ID: ";
                cin >> courseID;
                
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input!\n";
                    break;
                }
                
                cout << "Enter Grade (0.0 - 100.0): ";
                cin >> grade;
                
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input!\n";
                    break;
                }
                
                system.assignGrade(studentID, courseID, grade);
                break;
            }
            
            case 5: {
                int studentID;
                
                cout << "\n--- Display Student Information ---\n";
                cout << "Enter Student ID: ";
                cin >> studentID;
                
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input!\n";
                    break;
                }
                
                system.displayStudentInfo(studentID);
                break;
            }
            
            case 6: {
                system.displayAllCourses();
                break;
            }
            
            case 7: {
                system.displaySortedStudents();
                break;
            }
            
            case 8: {
                cout << "\nThank you for using the Students Record and Grading System!\n";
                cout << "Exiting...\n";
                return 0;
            }
            
            default:
                cout << "Invalid choice! Please enter a number between 1-8.\n";
                break;
        }
        
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    }
    
    return 0;
}

