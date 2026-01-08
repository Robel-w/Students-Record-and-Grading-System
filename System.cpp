#include "System.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

bool GradeSystem::addStudent(int studentID, const string& studentName) {
    if (students.find(studentID) != students.end()) {
        cout << "Error: Student with ID " << studentID << " already exists!\n";
        return false;
    }
    
    students[studentID] = Student(studentID, studentName);
    cout << "Student added successfully: ID=" << studentID 
              << ", Name=" << studentName << "\n";
    return true;
}

bool GradeSystem::addCourse(int courseID, const string& courseName) {
    if (courses.find(courseID) != courses.end()) {
        cout << "Error: Course with ID " << courseID << " already exists!\n";
        return false;
    }
    
    courses[courseID] = Course(courseID, courseName);
    cout << "Course added successfully: ID=" << courseID 
              << ", Name=" << courseName << "\n";
    return true;
}

bool GradeSystem::enroll(int studentID, int courseID) {
    if (!studentExists(studentID)) {
        cout << "Error: Student with ID " << studentID << " does not exist!\n";
        return false;
    }
    
    if (!courseExists(courseID)) {
        cout << "Error: Course with ID " << courseID << " does not exist!\n";
        return false;
    }
    
    Student& student = students[studentID];
    
    for (const Edge& edge : student.enrollments) {
        if (edge.courseID == courseID) {
            cout << "Error: Student " << studentID 
                      << " is already enrolled in Course " << courseID << "!\n";
            return false;
        }
    }
    
    student.enrollments.push_back(Edge(courseID, 0.0));
    cout << "Student " << studentID << " enrolled in Course " << courseID << "\n";
    return true;
}

bool GradeSystem::assignGrade(int studentID, int courseID, double grade) {
    if (!studentExists(studentID)) {
        cout << "Error: Student with ID " << studentID << " does not exist!\n";
        return false;
    }
    
    if (grade < 0.0 || grade > 100.0) {
        cout << "Error: Grade must be between 0.0 and 100.0!\n";
        return false;
    }
    
    Student& student = students[studentID];
    
    bool found = false;
    for (Edge& edge : student.enrollments) {
        if (edge.courseID == courseID) {
            edge.grade = grade;
            found = true;
            break;
        }
    }
    
    if (!found) {
        cout << "Error: Student " << studentID 
                  << " is not enrolled in Course " << courseID << "!\n";
        return false;
    }
    
    student.gpa = calculateGPA(studentID);
    
    cout << "Grade assigned: Student " << studentID 
              << ", Course " << courseID << ", Grade: " << grade << "\n";
    return true;
}

double GradeSystem::calculateGPA(int studentID) {
    if (!studentExists(studentID)) {
        return -1.0;
    }
    
    const Student& student = students.at(studentID);
    
    if (student.enrollments.empty()) {
        return 0.0;
    }
    
    double totalGrade = 0.0;
    int courseCount = 0;
    
    for (const Edge& edge : student.enrollments) {
        if (edge.grade > 0.0) { 
            totalGrade += edge.grade;
            courseCount++;
        }
    }
    
    if (courseCount == 0) {
        return 0.0;
    }
    
    return totalGrade / courseCount;
}

void GradeSystem::merge(std::vector<Student>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    vector<Student> leftArr(n1);
    vector<Student> rightArr(n2);
    
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }
    
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (leftArr[i].gpa >= rightArr[j].gpa) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void GradeSystem::mergeSortHelper(std::vector<Student>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSortHelper(arr, left, mid);
        mergeSortHelper(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void GradeSystem::displaySortedStudents() {
    if (students.empty()) {
        cout << "\nNo students in the system.\n";
        return;
    }
    
    vector<Student> studentList;
    for (auto& pair : students) {
        Student& student = pair.second;
        student.gpa = calculateGPA(student.id); // Ensure GPA is up to date
        studentList.push_back(student);
    }
    
    if (!studentList.empty()) {
        mergeSortHelper(studentList, 0, studentList.size() - 1);
    }
    
    cout << "\n=== Sorted Student Records (by GPA) ===\n";
    cout << left << setw(8) << "Rank"
              << setw(12) << "Student ID"
              << setw(25) << "Name"
              << setw(10) << "GPA" << "\n";
    cout << "------------------------------------------------------------\n";
    
    int rank = 1;
    for (const Student& student : studentList) {
        cout << left << setw(8) << rank++
                  << setw(12) << student.id
                  << setw(25) << student.name
                  << setw(10) << fixed << setprecision(2) 
                  << student.gpa << "\n";
    }
    cout << "============================================================\n\n";
}

bool GradeSystem::studentExists(int studentID) const {
    return students.find(studentID) != students.end();
}

bool GradeSystem::courseExists(int courseID) const {
    return courses.find(courseID) != courses.end();
}

void GradeSystem::displayStudentInfo(int studentID) const {
    if (!studentExists(studentID)) {
        cout << "Student with ID " << studentID << " does not exist!\n";
        return;
    }
    
    const Student& student = students.at(studentID);
    cout << "\n=== Student Information ===\n";
    cout << "ID: " << student.id << "\n";
    cout << "Name: " << student.name << "\n";
    
    cout << "\nEnrolled Courses:\n";
    if (student.enrollments.empty()) {
        cout << "  No courses enrolled.\n";
    } else {
        cout << left << setw(15) << "Course ID" 
                  << setw(10) << "Grade" << "\n";
        cout << "--------------------------------\n";
        for (const Edge& edge : student.enrollments) {
            cout << left << setw(15) << edge.courseID;
            if (edge.grade > 0.0) {
                cout << setw(10) << fixed << setprecision(2) 
                          << edge.grade << "\n";
            } else {
                cout << setw(10) << "N/A" << "\n";
            }
        }
    }
    
    cout << "\nGPA: " << fixed << setprecision(2) << student.gpa << "\n";
    cout << "==========================\n\n";
}

void GradeSystem::displayAllCourses() const {
    if (courses.empty()) {
        cout << "\nNo courses in the system.\n";
        return;
    }
    
    cout << "\n=== All Courses ===\n";
    cout << left << setw(10) << "ID" 
              << setw(25) << "Name" << "\n";
    cout << "----------------------------------------\n";
    
    for (const auto& pair : courses) {
        const Course& course = pair.second;
        cout << left << setw(10) << course.id
                  << setw(25) << course.name << "\n";
    }
    cout << "========================================\n\n";
}

