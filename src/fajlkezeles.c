#include "../include/menuElemek.h"
#include "../include/strukturak.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define STUDENT_FILE_PATH "./data/students.csv"
#define TEACHER_FILE_PATH "./data/teachers.csv"

Student *readStudentFileAndCreateStudentList() {

  // read students file
  FILE *studentsFile = fopen("./data/students.csv", "r");

  // check if it succeded
  if (studentsFile == NULL) {
    perror("The Student file dosent exist!");
    printf("The Student file dosent exist!");
    waitForEnter();
    return NULL;
  }

  // variable for reading one line
  char readLine[256];
  // this pointer is used for reading a line and then it holds the splitted
  // line.
  char *pointerForReadingALineThenUsedForTokenizing;

  Student *previousStudent = NULL;
  // skip header
  fgets(readLine, 256, studentsFile);

  // loop for reading all the lines
  while (fgets(readLine, 256, studentsFile)) {

    // split the line by the delemiter
    pointerForReadingALineThenUsedForTokenizing = strtok(readLine, ";");

    // allocate memory for the new student struct
    Student *newStudent = (Student *)malloc(sizeof(Student));
    if (newStudent == NULL) {
      perror("Memory allocation failed for newStudent!");
      return NULL;
    }
    // index for the current data
    int counterForDataIndex = 0;

    while (pointerForReadingALineThenUsedForTokenizing != NULL ||
           counterForDataIndex < 12) {
      switch (counterForDataIndex) {
      case 0: // Nev
        strncpy(newStudent->nev, pointerForReadingALineThenUsedForTokenizing,
                MAX_NEV_HOSSZ + 1);
        break;
      case 1: // Neptun_kod
        strncpy(newStudent->neptun_kod,
                pointerForReadingALineThenUsedForTokenizing, NEPTUN_HOSSZ + 1);
        break;
      case 2: // Eloadas_csoport
        newStudent->elo_csoport =
            atoi(pointerForReadingALineThenUsedForTokenizing);
        break;
      case 3: // Gyakorlati_csoport
        strncpy(newStudent->gyak_csoport,
                pointerForReadingALineThenUsedForTokenizing, 10);
        break;
      case 4: // Hianyzasok
        newStudent->hianyzasok_szama =
            atoi(pointerForReadingALineThenUsedForTokenizing);
        break;

      case 5: // ZH1
      case 6: // ZH2
      case 7: // ZH3
      case 8: // ZH4
      case 9: // ZH5
        // (counterForDataIndex - 5) converts the index (5-9) to the array index
        // (0-4)
        newStudent->kis_zh_pontok[counterForDataIndex - 5] =
            atof(pointerForReadingALineThenUsedForTokenizing);
        break;

      case 10: // NZH_pont
        newStudent->nzh_pont =
            atof(pointerForReadingALineThenUsedForTokenizing);
        break;

      case 11: // Vizsga_pont
        newStudent->vizsga_pont =
            atof(pointerForReadingALineThenUsedForTokenizing);
        break;

      default:
        break;
      }
      // increment where to put the next data
      counterForDataIndex++;
      // move the tokenize the next part of the line
      pointerForReadingALineThenUsedForTokenizing = strtok(NULL, ";");
    }
    // set the newly created student nex to the previous
    newStudent->next = previousStudent;
    previousStudent = newStudent;
  }
  // closes the file
  fclose(studentsFile);

  return previousStudent;
}
void trimNewline(char *str) {
    if (str == NULL) return;
    size_t len = strlen(str);
    if (len > 0 && (str[len - 1] == '\n' || str[len - 1] == '\r')) {
        str[len - 1] = '\0';
        len--;
    }
    if (len > 0 && (str[len - 1] == '\n' || str[len - 1] == '\r')) {
        str[len - 1] = '\0';
    }
}

Teacher *readTeacherFileAndCreateTeacherList() {

  // read teachers file
  FILE *teachersFile = fopen("./data/teachers.csv", "r");

  // check if it succeded
  if (teachersFile == NULL) {
    perror("The Student file dosent exist!");

    printf("Press Enter to continue...");
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
      getchar();

    return NULL;
  }

  // variable for reading one line
  char readLine[256];
  // this pointer is used for reading a line and then it holds the splitted
  // line.
  char *pointerForReadingALineThenUsedForTokenizing;

  Teacher *previousTeacher = NULL;
  // skip header
  fgets(readLine, 256, teachersFile);

  // loop for reading all the lines
  while (fgets(readLine, 256, teachersFile)) {

    // split the line by the delemiter
    pointerForReadingALineThenUsedForTokenizing = strtok(readLine, ";");

    // allocate memory for the new student struct
    Teacher *newTeacher = (Teacher *)malloc(sizeof(Teacher));
    if (newTeacher == NULL) {
      perror("Memory allocation failed for newTeacher!");
      return NULL;
    }

    newTeacher->csoportok_szama = 0;

    // index for the current data
    int counterForDataIndex = 0;

    while (pointerForReadingALineThenUsedForTokenizing != NULL &&
           counterForDataIndex <= 10) {

      trimNewline(pointerForReadingALineThenUsedForTokenizing);

      switch (counterForDataIndex) {
      case 0: // Nev
        strncpy(newTeacher->nev, pointerForReadingALineThenUsedForTokenizing,
                MAX_OKTATO_NEV);
        newTeacher->nev[MAX_OKTATO_NEV - 1] = '\0';
        break;

      default:
        // Check if the group code is not empty
        if (strlen(pointerForReadingALineThenUsedForTokenizing) > 0) {

          int groupIndex = counterForDataIndex - 1;

          // code string
          strncpy(newTeacher->csoportok[groupIndex],
                  pointerForReadingALineThenUsedForTokenizing,
                  CSOPORT_KOD_HOSSZ);

          // Ensure termination
          newTeacher->csoportok[groupIndex][CSOPORT_KOD_HOSSZ - 1] = '\0';

          // Increment the counter for the number of groups successfully read
          newTeacher->csoportok_szama++;
        }
        break;
      }
      // increment where to put the next data
      counterForDataIndex++;
      // move the tokenize the next part of the line
      pointerForReadingALineThenUsedForTokenizing = strtok(NULL, ";"); //
    }
    // set the newly created teacher nex to the previous
    newTeacher->next = previousTeacher;
    previousTeacher = newTeacher;
  }
  // closes the file
  fclose(teachersFile);

  return previousTeacher;
}
// free functions
void freeStudentsLinkedList(Student *theFirstElementOfTheList) {
  Student *nextNode;
  Student *CurrentNode = theFirstElementOfTheList;
  while (CurrentNode != NULL) {
    nextNode = CurrentNode->next;
    free(CurrentNode);
    CurrentNode = nextNode;
  }
}
void freeTeachersLinkedList(Teacher *theFirstElementOfTheList) {
  Teacher *nextNode;
  Teacher *CurrentNode = theFirstElementOfTheList;
  while (CurrentNode != NULL) {
    nextNode = CurrentNode->next;
    free(CurrentNode);
    CurrentNode = nextNode;
  }
}
//////////////////////////////////////////
void saveStudentsToFile(Student *head) {
    FILE *file = fopen(STUDENT_FILE_PATH, "w");
    if (file == NULL) {
        perror("HIBA: Nem sikerült megnyitni a diákfájlt mentéshez!");
        return;
    }

    fprintf(file, "Nev;Neptun_kod;Eloadas_csoport;Gyakorlati_csoport;Hianyzasok;ZH1;ZH2;ZH3;ZH4;ZH5;NZH_pont;Vizsga_pont\n");

    Student *current = head;
    while (current != NULL) {
        fprintf(file, "%s;%s;%d;%s;%d;",
                current->nev,
                current->neptun_kod,
                current->elo_csoport,
                current->gyak_csoport,
                current->hianyzasok_szama);

        for (int i = 0; i < MAX_ZH_SZAM; i++) {
            fprintf(file, "%.2f;", current->kis_zh_pontok[i]);
        }

        fprintf(file, "%.2f;%.2f\n",
                current->nzh_pont,
                current->vizsga_pont);

        current = current->next;
    }

    fclose(file);
    printf("SIKER: Diák adatok mentve ide: %s\n", STUDENT_FILE_PATH);
}

void saveTeachersToFile(Teacher *head) {
    FILE *file = fopen(TEACHER_FILE_PATH, "w");
    if (file == NULL) {
        perror("HIBA: Nem sikerült megnyitni az oktatófájlt mentéshez!");
        return;
    }

    fprintf(file, "Nev;Csoport1;Csoport2;Csoport3;Csoport4;Csoport5;Csoport6;Csoport7;Csoport8;Csoport9;Csoport10\n");

    Teacher *current = head;
    while (current != NULL) {
        // Név
        fprintf(file, "%s", current->nev);

        // Csoportok
        for (int i = 0; i < MAX_CSOPORT_SZAM; i++) {
            fprintf(file, ";");
            if (i < current->csoportok_szama) {
                fprintf(file, "%s", current->csoportok[i]);
            }
        }
        fprintf(file, "\n");
        current = current->next;
    }

    fclose(file);
    printf("SIKER: Oktató adatok mentve ide: %s\n", TEACHER_FILE_PATH);
}

void saveAllData(Student *studentHead, Teacher *teacherHead) {
    printf("\n--- ADATOK MENTÉSE FÁJLBA ---\n");
    saveStudentsToFile(studentHead);
    saveTeachersToFile(teacherHead);
    printf("--- MENTÉS BEFEJEZVE ---\n");
}