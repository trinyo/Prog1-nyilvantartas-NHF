#include <stdio.h>
#include <string.h>

#include "../include/adatkezeles.h"
#include "../include/fajlkezeles.h"
#include "../include/menuElemek.h"
#include "../include/strukturak.h"

double calculateTotalScore(const Student *student_ptr) {
  double total = 0.0;
  // Sums up the points from the small tests (kis zh)
  for (int i = 0; i < MAX_ZH_SZAM; i++) {
    total += student_ptr->kis_zh_pontok[i];
  }
  // Adds the mid-term score (nzh)
  total += student_ptr->nzh_pont;
  // Adds the final exam score (vizsga)
  total += student_ptr->vizsga_pont;
  return total;
}

void calculateGrade(double totalScore, char *resultBuffer) {

  if (totalScore >= 119.0) {
    strcpy(resultBuffer, "Jeles (5)");
  } else if (totalScore >= 98.0) {
    strcpy(resultBuffer, "Jó (4)");
  } else if (totalScore >= 77.0) {
    strcpy(resultBuffer, "Közepes (3)");
  } else if (totalScore >= 56.0) {
    strcpy(resultBuffer, "Elégséges (2)");
  } else {
    strcpy(resultBuffer, "Elégtelen (1)");
  }
}

void listAllStudents(Student *head) {

  if (head == NULL) {
    perror("The list is empty!");
    return;
  }

  char gradeStr[15];
  double totalScore;

  printf("\n--- Hallgatók minimalizált listája ---\n");
  printf("| Név (20)             | Neptun | Összpont | Értékelés    |\n");
  printf("--------------------------------------------------\n");

  Student *current = head;

  while (current != NULL) {
    totalScore = calculateTotalScore(current);
    calculateGrade(totalScore, gradeStr);

    printf("| %-20s | %-6s | %-8.1f | %-11s |\n", current->nev,
           current->neptun_kod, totalScore, gradeStr);

    current = current->next;
  }

  printf("--------------------------------------------------\n");
}
void listAllTeachers(Teacher *head) {

  if (head == NULL) {
    printf("\nA tanári lista üres.\n");
    return;
  }

  printf("\n--- OKTATÓI NYILVÁNTARTÁS ---\n");

  printf("| %-30s | %-10s | Csoportok Listája\n", "Név", "Csoport Sz.");
  printf("---------------------------------------------------------------------"
         "---\n");

  Teacher *current = head;
  int i;

  while (current != NULL) {

    printf("| %-30s | %-10d | ", current->nev, current->csoportok_szama);

    if (current->csoportok_szama > 0) {
      for (i = 0; i < current->csoportok_szama; i++) {
        printf("%s", current->csoportok[i]);

        if (i < current->csoportok_szama - 1) {
          printf(", ");
        }
      }
    } else {
      printf("Nincs hozzárendelt csoport");
    }

    printf("\n");

    current = current->next;
  }

  printf("---------------------------------------------------------------------"
         "---\n");
}

void mainLoopForDataHandling(Student *studentList, Teacher *teacherList) {
  int userInput;
  do {
    clear_screen();
    displayListMenu();
    scanf("%i", &userInput);
    switch (userInput) {
    case 11:
      listAllStudents(studentList);
      waitForEnter();
      break;
    case 12:
      listAllTeachers(teacherList);
      waitForEnter();
      break;
    case 13:
      break;
    case 21:
      break;
    case 22:
      break;
    case 31:
      break;
    case 32:
      break;
    case 33:
      break;
    default:
      break;
    }
  } while (userInput != 9);
}
