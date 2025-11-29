#ifndef FAJLKEZELES_H
#define FAJLKEZELES_H
#include "strukturak.h"

/**
 ** @brief Reads the student data from students.csv and creates a linked list of Studen
structs. Returns a pointer to the head of the list (the last student read),
or NULL on failure.
 *
 * @return it returns the first student from the linked list
 **/
Student *readStudentFileAndCreateStudentList();

/** @brief

Reads the teacher data from teachers.csv and creates a linked list of Teacher
structs. Returns a pointer to the head of the list (the last teacher read),
or NULL on failure.
*
* @return it returns the first teacher from the linked list
*/
Teacher *readTeacherFileAndCreateTeacherList();

/**
 * @brief Frees all dynamically allocated memory used by the Student linked
 * list.
 **/
void freeStudentsLinkedList(Student *theFirstElementOfTheList);

/*
 *@brief Frees all dynamically allocated memory used by the Teacher linked list.
 */
void freeTeachersLinkedList(Teacher *theFirstElementOfTheList);

void mainFileHandlingFunction();
/**
 * @brief Saves the list in to text format in the data directory.
 */

/**
 * @brief Saves the content of the Student linked list to a CSV file.
 * * The function opens the file specified by STUDENT_FILE_PATH in write mode ('w'),
 * prints the header, and then iterates through the linked list, writing each
 * student's data as a semicolon-separated line.
 * * @param head A pointer to the head of the Student linked list.
 */
void saveStudentsToFile(Student *head);

/**
 * @brief Saves the content of the Teacher linked list to a CSV file.
 * * The function opens the file specified by TEACHER_FILE_PATH in write mode ('w'),
 * prints the header, and iterates through the linked list, writing each
 * teacher's data (name and up to MAX_CSOPORT_SZAM groups) as a semicolon-separated line.
 * * @param head A pointer to the head of the Teacher linked list.
 */
void saveTeachersToFile(Teacher *head);

/**
 * @brief Wrapper function to save all data (Students and Teachers) to their respective files.
 * * This function calls saveStudentsToFile and saveTeachersToFile.
 * * @param studentHead A pointer to the head of the Student linked list.
 * @param teacherHead A pointer to the head of the Teacher linked list.
 */
void saveAllData(Student *studentHead, Teacher *teacherHead);
#endif
