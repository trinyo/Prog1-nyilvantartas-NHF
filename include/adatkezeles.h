
#ifndef ADATKEZELES_H
#define ADATKEZELES_H

#include "strukturak.h"

// main function for data handling
void mainLoopForDataHandling(Student *studentList, Teacher *teacherList);

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
// list by zh or retake
void listByRetake();
// list by rank
void listByPoints();
void listByAbsence();
void listByGroupAvgPoints();

// create a new student instance
Student *createNewStudentInstance(char nev, char neptun_kod, int elo_csoport,
                                  char gyak_csoport[10], int hianyzasok_szama,
                                  double kis_zh_pontok[MAX_ZH_SZAM],
                                  double nzh_pont, double vizsga_pont);
// create a new teacher instance
Teacher *createNewTeacherInstance(char nev, char csoportok, int csoportok_szama,
                                  Student *next, Student *previous);

// create functions
/**
 * @brief Adds a new student record to the list.
 * * Dynamically allocates memory for the new student.
 *
 * @param newStudent The data of the new student, already stored in a structure.
 * @return int 0 if successful, -1 if unsuccessful (e.g., memory allocation
 * failed).
 */
int createNewStudent(Student newStudent);
/**
 * @brief Adds a new teacher record to the list.
 * * Dynamically allocates memory for the new teacher.
 *
 * @param newTeacher* The data of the new teacher, already stored in a
 * structure.
 * @return int 0 if successful, -1 if unsuccessful (e.g., memory allocation
 * failed).
 */
int createNewTeacher(Teacher newTeacher);

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
int updateStudent(Student *oldStudent, Student updateStudentWith);

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
int updateTeacher(Teacher *oldTeacher, Teacher updateTeacherWith);

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
