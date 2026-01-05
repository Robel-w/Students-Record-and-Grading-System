# Students Record and Grading System

A simple C++ system that uses a Graph Data Structure (Adjacency List) to manage student records and course enrollments with grading functionality.

## Project Structure

This project uses a clean 3-file structure:

- **System.h**: Header file containing `Student` struct, `Edge` struct, `Course` struct, and `GradeSystem` class declarations
- **System.cpp**: Implementation of all functions including manual Merge Sort algorithm
- **main.cpp**: Simple menu-driven interface for user interaction

## Data Structure

- **Graph-Based**: Students and Courses are vertices, enrollments are edges
- **Edge Weight**: Grades are stored as weights on edges connecting students to courses
- **Adjacency List**: Uses `unordered_map<int, Student>` for O(1) student lookup efficiency
- **Student Struct**: Contains ID, Name, GPA, and a vector of `Edge` objects (enrollments)

## Features

1. **Add Student**: Add students to the system (Meklit's task)
2. **Add Course**: Add courses to the system (Meklit's task)
3. **Enroll**: Enroll students in courses - creates edges in the graph (Leoul's task)
4. **Assign Grade**: Assign grades to enrollments - sets edge weights (Negasi's task)
5. **Calculate GPA**: Automatically calculates GPA by traversing student's edges (Negasi's task)
6. **Show Rankings**: Display students sorted by GPA using manual Merge Sort (Robel's task)

## Compilation

### Using Makefile:
```bash
make
```

## Running the Program

```bash
./student_grading_system
```

## Usage Example

1. **Add Student**: Enter student ID and name
2. **Add Course**: Enter course ID and name
3. **Enroll Student**: Link a student to a course (creates an edge)
4. **Assign Grade**: Set a grade (0.0-100.0) for an enrollment (edge weight)
5. **Show Rankings**: View all students sorted by GPA (highest first) using Merge Sort

## Menu Options

1. Add Student
2. Add Course
3. Enroll Student in Course
4. Assign Grade to Enrollment
5. Display Student Information
6. Display All Courses
7. Show Rankings (Sorted by GPA)
8. Exit

## Algorithm Efficiency

- **Student Lookup**: O(1) using `unordered_map`
- **Sorting**: O(n log n) using manual Merge Sort implementation (no std::sort)
- **GPA Calculation**: O(k) where k is the number of courses a student is enrolled in

## Clean Up

To remove compiled files:
```bash
make clean
```
