#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

struct Edge {
    int courseID;
    double grade; 
    
    Edge(int id = 0, double g = 0.0) : courseID(id), grade(g) {}
};

struct Student {
    int id;
    std::string name;
    double gpa;
    std::vector<Edge> enrollments; 
    
    Student(int studentID = 0, const std::string& studentName = "") 
        : id(studentID), name(studentName), gpa(0.0) {}
};

struct Course {
    int id;
    std::string name;
    
    Course(int courseID = 0, const std::string& courseName = "") 
        : id(courseID), name(courseName) {}
};

class GradeSystem {
private:
    std::unordered_map<int, Student> students;
    
    std::unordered_map<int, Course> courses;
    
    void merge(std::vector<Student>& arr, int left, int mid, int right);
    void mergeSortHelper(std::vector<Student>& arr, int left, int right);

public:
    bool addStudent(int studentID, const std::string& studentName);
    bool addCourse(int courseID, const std::string& courseName);
    
    bool enroll(int studentID, int courseID);
    
    bool assignGrade(int studentID, int courseID, double grade);
    double calculateGPA(int studentID);
    
    void displaySortedStudents(); 
    bool studentExists(int studentID) const;
    bool courseExists(int courseID) const;
    void displayStudentInfo(int studentID) const;
    void displayAllCourses() const;
};

#endif 

