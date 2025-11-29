
#ifndef ADATKEZELES_H
#define ADATKEZELES_H

#include "strukturak.h"

// sum-er
double calculateTotalScore(const Student *student_ptr);
// result calculator
void calculateGrade(double totalScore, char *result);

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

// all of these function same as the above
void listAllStudentsByGroup(Student *theFirstElementOfTheList);
void listAllStudentsByNZH(Student *theFirstElementOfTheList);
void listAllStudentsByKZH(Student *theFirstElementOfTheList);
void listAllStudentsByNEPTUN(Student *theFirstElementOfTheList);

// list by zh or *retake
void listAllStudentsByRetake(Student *theFirstElementOfTheList);




void mainLoopForAddNewStudent(Student* studentToAdd);
void mainLoopForAddNewTeacher(Teacher* teacherToADd);
// create a new student instance
Student *createNewStudentInstance(Student*newStudent);
// create a new teacher instance
Teacher *createNewTeacherInstance(Teacher *newTeacher);

// create functions
/**
 * @brief Adds a new student record to the list.
 *
 *
 * @param newStudent The data of the new student, already stored in a structure.
 * @param studentList The list to add the new item.
 * @return Student* if successful, NULL if unsuccessful.
 */
Student* addNewStudent(Student *studentList,Student *newStudent);
/**
 * @brief Adds a new teacher record to the list.*
 *
 *
 * @param newTeacher The data of the new teacher, already stored in a
 * structure.
 * @param teacherList The list to add the new item.
 * @return Teacher* if successful, NULL if unsuccessful.
 */
Teacher *addNewTeacher(Teacher *teacherList,Teacher *newTeacher);

// update functions

/**
 * @brief Updates the student record
 * The user has to select one record from the list to modify, through the terminal
 * and type in the modifyed fields.
 * @param studentList the list which will be used for selecting one record to be updated
 * @return int 0 if successful, -1 if unsuccessful (e.g., memory allocation
 * failed).
 */
int updateStudent(Student *studentList);

/**
 * @brief Updates the teacher  record
 * The user has to select one record from the list to modify, through the terminal
 * and type in the modifyed fields.
 * @param teacherList the list which will be used for selecting one record to be updated
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
