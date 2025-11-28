// global libraries
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// local headers
#include "../include/adatkezeles.h"
#include "../include/fajlkezeles.h"
#include "../include/menuElemek.h"
#include "../include/strukturak.h"
#include "debugmalloc.h"


int main(int argc, char *argv[]) {
  int userInput;
  Student *studentsList = readStudentFileAndCreateStudentList();
  if (studentsList == NULL)
    return 1;
  Teacher *teacherList = readTeacherFileAndCreateTeacherList();
  if (teacherList == NULL)
    return 1;
  do {
    clear_screen();
    displayMainMenu();
    scanf("%i", &userInput);
    switch (userInput) {
      case 0:
        break;
      // list menu
      case 1:
        mainLoopForListMenu(studentsList, teacherList);
        break;
      // add new data
      case 2:
        clear_screen();
        mainLoopForCreateMenu(studentsList, teacherList);
        break;
      // update data or remove
      case 3:
        clear_screen();
        mainLoopForUpdateMenu(studentsList, teacherList);
        break;
      default:
        printf("Nem volt megfelelő a bemenet! \n");
        waitForEnter();
    }
  } while (userInput != 0);
  saveAllData(studentsList, teacherList);
  freeStudentsLinkedList(studentsList);
  freeTeachersLinkedList(teacherList);
  return EXIT_SUCCESS;
}
