#ifndef ADATKEZELES_H
#define ADATKEZELES_H

#include "strukturak.h"


/**
 * @brief Calculates the total score of the given student.
 *
 * Sums up all the Mini Midterm (KZH), Major Midterm (NZH), and Exam scores.
 *
 * @param student_ptr Pointer to the Student structure whose scores are to be summed.
 * @return double The total accumulated score (KZHs + NZH + Exam).
 */
double calculateTotalScore(const Student *student_ptr);

/**
 * @brief Determines the student's final grade based on the total score achieved.
 *
 * The grade (e.g., "Excellent (5)") is copied into the provided result string.
 *
 * @param totalScore The total score achieved by the student.
 * @param result The character array (string) where the final grade will be stored.
 * @return void
 */
void calculateGrade(double totalScore, char *result);


/**
 * @brief Controls the logic and user choices for the listing menu.
 *
 * Allows viewing the stored data based on various criteria.
 *
 * @param studentList The head of the student linked list.
 * @param teacherList The head of the teacher linked list.
 * @return void
 */
void mainLoopForListMenu(Student *studentList, Teacher *teacherList);

/**
 * @brief Controls the logic for the new data creation menu.
 *
 * Allows for adding new student and teacher records. As the list head may change
 * upon insertion, it receives pointers to the list heads (Student** and Teacher**).
 *
 * @param studentListHead Pointer to the pointer of the student list head (Student **).
 * @param teacherListHead Pointer to the pointer of the teacher list head (Teacher **).
 * @return void
 */
void mainLoopForCreateMenu(Student **studentListHead, Teacher **teacherListHead);

/**
 * @brief Controls the logic for the data modification and deletion menu.
 *
 * Allows modification or removal of existing records. Since deletion can
 * change the list head, it receives pointers to the list heads (Student** and Teacher**).
 *
 * @param studentListHead Pointer to the pointer of the student list head (Student **).
 * @param teacherListHead Pointer to the pointer of the teacher list head (Teacher **).
 * @return void
 */
void mainLoopForUpdateMenu(Student **studentListHead, Teacher **teacherListHead);


/**
 * @brief Prints the minimal data for all students stored in the program.
 *
 * @param theFirstElementOfTheList The head of the student linked list.
 * @return void
 */
void listAllStudents(Student *theFirstElementOfTheList);

/**
 * @brief Prints the names and assigned groups of all teachers stored in the program.
 *
 * @param theFirstElementOfTheList The head of the teacher linked list.
 * @return void
 */
void listAllTeachers(Teacher *theFirstElementOfTheList);

/**
 * @brief Lists students based on their fixed assigned practical group code.
 *
 * @param theFirstElementOfTheList The head of the student linked list.
 * @return void
 */
void listAllStudentsByGroup(Student *theFirstElementOfTheList);

/**
 * @brief Lists students based on their Major Midterm (NZH) score.
 *
 * @param theFirstElementOfTheList The head of the student linked list.
 * @return void
 */
void listAllStudentsByNZH(Student *theFirstElementOfTheList);

/**
 * @brief Lists students based on their Mini Midterm (KZH) scores.
 *
 * @param theFirstElementOfTheList The head of the student linked list.
 * @return void
 */
void listAllStudentsByKZH(Student *theFirstElementOfTheList);

/**
 * @brief Lists students based on their NEPTUN code.
 *
 * @param theFirstElementOfTheList The head of the student linked list.
 * @return void
 */
void listAllStudentsByNEPTUN(Student *theFirstElementOfTheList);

/**
 * @brief Lists students who are eligible for/required to take a Retake Midterm (PZH) based on defined conditions.
 *
 * @param theFirstElementOfTheList The head of the student linked list.
 * @return void
 */
void listAllStudentsByRetake(Student *theFirstElementOfTheList);


/**
 * @brief Manages reading the data for a new student from the terminal and adding it to the list.
 *
 * Handles memory allocation, data input, and calls the addNewStudent function.
 * Updates the list head if the first element is being added.
 *
 * @param studentListHead Pointer to the pointer of the student list head (Student **).
 * @return void
 */
void mainLoopForAddNewStudent(Student **studentListHead);

/**
 * @brief Manages reading the data for a new teacher from the terminal and adding it to the list.
 *
 * Handles memory allocation, data input, and calls the addNewTeacher function.
 * Updates the list head if the first element is being added.
 *
 * @param teacherListHead Pointer to the pointer of the teacher list head (Teacher **).
 * @return void
 */
void mainLoopForAddNewTeacher(Teacher **teacherListHead);


/**
 * @brief Interactively reads student data from the console and populates the given structure.
 *
 * @param newStudent Pointer to the already allocated Student structure.
 * @return Student* Pointer to the populated Student structure, or NULL upon unsuccessful read.
 */
Student *createNewStudentInstance(Student*newStudent);

/**
 * @brief Interactively reads teacher data from the console and populates the given structure.
 *
 * @param newTeacher Pointer to the already allocated Teacher structure.
 * @return Teacher* Pointer to the populated Teacher structure, or NULL upon unsuccessful read.
 */
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
 * @return int 1 if successful, -1 if the record is not found, -3 for invalid index, or -4 if the list is empty.
 */
int deleteStudent(Student **studentListHead);

/**
 * @brief Removes a teacher record by index, updating the list head if necessary.
 * @param teacherListHead Pointer to the list head pointer (Teacher**).
 * @return int 1 if successful, -1 if the record is not found, -3 for invalid index, or -4 if the list is empty.
 */
int deleteTeacher(Teacher **teacherListHead);

#endif