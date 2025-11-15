#ifndef FAJLKEZELES_H
#define FAJLKEZELES_H
#include "strukturak.h"

/*@brief
 *Reads the student data from students.csv and creates a linked list of Student
structs. Returns a pointer to the head of the list (the last student read),
or NULL on failure.
 *
 *@return it returns the first student from the linked list
 */
Student *readStudentFileAndCreateStudentList();

/*@brief
 * @brief
Reads the teacher data from teachers.csv and creates a linked list of Teacher
structs. Returns a pointer to the head of the list (the last teacher read),
or NULL on failure.
*
*@return it returns the first teacher from the linked list
 */
Teacher *readTeacherFileAndCreateTeacherList();

/*
 * @brief Frees all dynamically allocated memory used by the Student linked
 * list.
 */
void freeStudentsLinkedList(Student *theFirstElementOfTheList);

/*
 *@brief Frees all dynamically allocated memory used by the Teacher linked list.
 */
void freeTeachersLinkedList(Teacher *theFirstElementOfTheList);

void mainFileHandlingFunction();
/**
 * @brief Saves the list in to text format in the data directory.
 */
void writeToFiles();
#endif
