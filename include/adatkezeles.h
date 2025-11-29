#ifndef ADATKEZELES_H
#define ADATKEZELES_H

#include "strukturak.h"

double calculateTotalScore(const Student *student_ptr);
void calculateGrade(double totalScore, char *result);


void mainLoopForListMenu(Student *studentList, Teacher *teacherList);
void mainLoopForCreateMenu(Student **studentListHead, Teacher **teacherListHead); 
void mainLoopForUpdateMenu(Student **studentListHead, Teacher **teacherListHead);

void listAllStudents(Student *theFirstElementOfTheList);
void listAllTeachers(Teacher *theFirstElementOfTheList);
void listAllStudentsByGroup(Student *theFirstElementOfTheList);
void listAllStudentsByNZH(Student *theFirstElementOfTheList);
void listAllStudentsByKZH(Student *theFirstElementOfTheList);
void listAllStudentsByNEPTUN(Student *theFirstElementOfTheList);
void listAllStudentsByRetake(Student *theFirstElementOfTheList);

void mainLoopForAddNewStudent(Student **studentListHead);
void mainLoopForAddNewTeacher(Teacher **teacherListHead);

Student *createNewStudentInstance(Student*newStudent);
Teacher *createNewTeacherInstance(Teacher *newTeacher);


/**
 * @brief Adds a new student record to the list.
 * @param studentList A pointer to the head of the student list.
 * @param newStudent The data of the new student.
 * @return Student* Pointer to the new head of the list.
 */
Student* addNewStudent(Student *studentList,Student *newStudent);

/**
 * @brief Adds a new teacher record to the list.
 * @param teacherList A pointer to the head of the teacher list.
 * @param newTeacher The data of the new teacher.
 * @return Teacher* Pointer to the new head of the list.
 */
Teacher *addNewTeacher(Teacher *teacherList,Teacher *newTeacher);


int updateStudent(Student *studentList);
int updateTeacher(Teacher *teacherList);

/**
 * @brief Removes a student record by index, updating the list head if necessary.
 * @param studentListHead Pointer to the list head pointer (Student**).
 * @return int 1 if successful, -1 ha a rekord nem található, -3 ha érvénytelen index, -4 ha a lista üres.
 */
int deleteStudent(Student **studentListHead);

/**
 * @brief Removes a teacher record by index, updating the list head if necessary.
 * @param teacherListHead Pointer to the list head pointer (Teacher**).
 * @return int 1 if successful, -1 ha a rekord nem található, -3 ha érvénytelen index, -4 ha a lista üres.
 */
int deleteTeacher(Teacher **teacherListHead);

#endif