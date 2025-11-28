
#ifndef ADATKEZELES_H
#define ADATKEZELES_H

#include "strukturak.h"

void saveStudentListToFile(Student *studentList);
void saveTeacherListToFile(Student *studentList);
// main function for data handling
void mainLoopForListMenu(Student *studentList, Teacher *teacherList);
void mainLoopForCreateMenu(Student *studentList, Teacher *teacherList);
void mainLoopForUpdateMenu(Student *studentList, Teacher *teacherList);
// list all
/**
 * @brief Lists all students from the linked list.
 * @param theFirstElementOfTheList The head of the student list (Student*).
 */
void listAllStudents(Student *theFirstElementOfTheList);

/**
 * @brief Lists all teachers from the linked list.
 * @param theFirstElementOfTheList The head of the teacher list (Teacher*).
 */
void listAllTeachers(Teacher *theFirstElementOfTheList);
void listAllStudentsByGroup(Student *theFirstElementOfTheList);
// list by zh or *retake
void listAllStudentsByRetake(Student *theFirstElementOfTheList);
// list by rank
void listAllStudentsByPointsDescending(Student *theFirstElementOfTheList);
void listByAbsence(Student *theFirstElementOfTheList);
void listByGroupAvgPoints(Student *theFirstElementOfTheList);


Student* readNewStudentData();

void mainLoopForAddNewStudent(Student* studentToAdd);
void mainLoopForAddNewTeacher(Teacher* teacherToADd);
// create a new student instance
Student *createNewStudentInstance(Student*newStudent);
// create a new teacher instance
Teacher *createNewTeacherInstance(Teacher *newTeacher);

// create functions
/**
 * @brief Adds a new student record to the list.
 * * Dynamically allocates memory for the new student.
 *
 * @param newStudent The data of the new student, already stored in a structure.
 * @return int 0 if successful, -1 if unsuccessful (e.g., memory allocation
 * failed).
 */
Student* addNewStudent(Student *studentList,Student *newStudent);
/**
 * @brief Adds a new teacher record to the list.*
 * * Dynamically allocates memory for the new teacher.
 *
 * @param newTeacher* The data of the new teacher, already stored in a
 * structure.
 * @return int 0 if successful, -1 if unsuccessful (e.g., memory allocation
 * failed).
 */
Teacher *addNewTeacher(Teacher *studentList,Teacher *newTeacher);

// update functions

/**
 * @brief Updates the student record pointed by the
 * oldStudent pointer  with the new struct.
 *
 *
 * @param oldStudent* pointer to the student that is whis to be updated.
 * @param updateStudentWith struct that overWrites the oldStudent.
 * @return int 0 if successful, -1 if unsuccessful (e.g., memory allocation
 * failed).
 */
int updateStudent(Student *studentList);

/**
 * @brief Updates the teacher  record pointed by the
 * oldTeacher pointer with the new struct.
 *
 *
 * @param oldTeacher* pointer to the teacher that is whis to be updated.
 * @param updateTeacherWith struct that overWrites the oldTeacher.
 * @return int 0 if successful, -1 if unsuccessful (e.g., memory allocation
 * failed).
 */
int updateTeacher(Teacher *teacherList);

// delete functions

/**
 * @brief Removes the student  record pointed by the
 * studentToRemove pointer.
 *
 *
 * @param studentToRemove* pointer to the student that is whis to be removed.
 * @return int 0 if successful, -1 if unsuccessful (e.g., memory allocation
 * failed).
 */
int deleteStudent(Student *studentToRemove);
/**
 * @brief Removes the teacher  record pointed by the
 * teacherToRemove pointer.
 *
 *
 * @param teacherToRemove* pointer to the teacher that is whis to be removed.
 * @return int 0 if successful, -1 if unsuccessful (e.g., memory allocation
 * failed).
 */
int deleteTeacher(Teacher *teacherToRemove);
#endif
