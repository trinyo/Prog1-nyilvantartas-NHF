// global libraries
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// local headers
#include "../include/adatkezeles.h"
#include "../include/fajlkezeles.h"
#include "../include/menuElemek.h"
#include "../include/strukturak.h"

int main(int argc, char *argv[]) {
  int userInput;
  Student *studentsList = readStudentFileAndCreateStudentList();
  Teacher *teacherList = readTeacherFileAndCreateTeacherList();
  do {
    clear_screen();
    displayMainMenu();
    scanf("%i", &userInput);
    switch (userInput) {
      // list menu
    case 1:
      mainLoopForDataHandling(studentsList, teacherList);
      break;
      // add new data
    case 2:
      clear_screen();
      displayNewDataMenu();
      break;
      // update data or remove
    case 3:
      clear_screen();
      break;
    default:
      printf("Nem volt megfelelő a bemenet! \n");
      waitForEnter();
    }
  } while (userInput != 0);

  freeStudentsLinkedList(studentsList);
  freeTeachersLinkedList(teacherList);
  return EXIT_SUCCESS;
}
