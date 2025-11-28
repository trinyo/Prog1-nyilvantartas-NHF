#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "../include/adatkezeles.h"

#include <stdlib.h>

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

Student *sortStudentListByPointsDescending(Student *head) { return NULL; }

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
    clear_screen();

    char gradeStr[15];
    double totalScore;
    int index = 0;

    printf("\n--- Hallgatók minimalizált listája ---\n");

    printf("| Index | Név (20)             | Neptun | Összpont | Értékelés    |\n");
    printf("----------------------------------------------------------\n");

    Student *current = head;

    while (current != NULL) {
        totalScore = calculateTotalScore(current);
        calculateGrade(totalScore, gradeStr);

        printf("| %-5d | %-20s | %-6s | %-8.1f | %-11s |\n",
               index,
               current->nev,
               current->neptun_kod,
               totalScore,
               gradeStr);

        current = current->next;
        index++;
    }

    printf("----------------------------------------------------------\n");
    waitForEnter();
}

void listAllTeachers(Teacher *head) {
    if (head == NULL) {
        printf("\nA tanári lista üres.\n");
        return;
    }
    clear_screen();

    int index = 0;

    printf("\n--- OKTATÓI NYILVÁNTARTÁS ---\n");

    printf("| Index | %-30s | %-10s | Csoportok Listája\n", "Név", "Csoport Sz.");

    printf("---------------------------------------------------------------------------------\n");

    Teacher *current = head;

    while (current != NULL) {
        printf("| %-5d | %-30s | %-10d | ",
               index,
               current->nev,
               current->csoportok_szama);

        if (current->csoportok_szama > 0) {
            for (int i = 0; i < current->csoportok_szama; i++) {
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
        index++;
    }

    printf("---------------------------------------------------------------------------------\n");
    waitForEnter();
}

void listAllStudentsByGroup(Student *head) {
    if (head == NULL) {
        perror("The list is empty!");
        return;
    }

    printf("\n--- TANULÓ NYILVÁNTARTÁS CSOPORT ALAPJÁN ---\n");

    printf("| %-30s | %-10s | Csoportok Listája\n", "Név", "Csoport Sz.");
    printf("---------------------------------------------------------------------"
        "---\n");

    Student *current = head;

    while (current != NULL) {
        printf("| %-30s | %-30i | %-s \n", current->nev, current->elo_csoport,
               current->gyak_csoport);

        current = current->next;
    }

    printf("--------------------------------------------------\n");
    waitForEnter();
}

void listAllStudentsByRetake(Student *head) {
    if (head == NULL) {
        perror("The list is empty!");
        return;
    }
    clear_screen();
    printf("\n--- TANULÓ NYILVÁNTARTÁS PZH ALAPJÁN ---\n");

    printf("| %-30s | %-10s \n", "Név", "Elért pontszám");
    printf("---------------------------------------------------------------------"
        "---\n");

    Student *current = head;

    while (current != NULL) {
        if (current->nzh_pont < 25) {
            printf("| %-30s | %-30i \n", current->nev, (int) current->nzh_pont);
        }
        current = current->next;
    }

    printf("--------------------------------------------------\n");
    waitForEnter();
}


Student *createNewStudentInstance(Student *newStudent) {
    printf("Kérjük, adja meg a hallgató adatait egy sorban, pontosvesszővel (;) elválasztva. \n");
    printf("A bevitelt a következő formátumban várjuk:\n");
    printf(
        "Format: Nev;Neptun_kod;Eloadas_csoport;Gyakorlati_csoport;Hianyzasok;ZH1;ZH2;ZH3;ZH4;ZH5;NZH_pont;Vizsga_pont\n");
    printf(
        "Adat bevitele után nyomjon Entert. A bevitelt a sor elején lévő Ctrl+D (vagy Ctrl+Z) gombokkal fejezheti be.\n\n");
    int result = scanf(
        // 1. Nev, Neptun_kod (Strings with semicolon delimiter)
        "%50[^;];%6[^;];"

        // 2. Eloadas_csoport, Gyakorlati_csoport (Integer and String)
        "%d;%9[^;];"

        // 3. Hianyzasok (Integer)
        "%d;"

        // 4. 5x ZH scores (Doubles with semicolon delimiter)
        "%lf;%lf;%lf;%lf;%lf;"

        // 5. NZH_pont, Vizsga_pont (Doubles)
        "%lf;%lf",

        // --- Corresponding Variables ---
        newStudent->nev,
        newStudent->neptun_kod,
        &newStudent->elo_csoport,
        newStudent->gyak_csoport,
        &newStudent->hianyzasok_szama,
        &newStudent->kis_zh_pontok[0],
        &newStudent->kis_zh_pontok[1],
        &newStudent->kis_zh_pontok[2],
        &newStudent->kis_zh_pontok[3],
        &newStudent->kis_zh_pontok[4],
        &newStudent->nzh_pont,
        &newStudent->vizsga_pont
    );

    const int expected_items = 12; // 2 strings, 1 int, 1 string, 1 int, 7 doubles = 12 items

    if (result == EOF) {
        return NULL;
    }

    if (result != expected_items) {
        // Handle malformed line or read error
        fprintf(stderr, "Error: Only read %d out of %d expected items. Check your input format.\n", result,
                expected_items);
        waitForEnter();
        return NULL;
    }
    return newStudent;
}

Student *addNewStudent(Student *studentList, Student *newStudent) {
    if (newStudent == NULL) {
        return studentList; // Failure, return original list head
    }
    newStudent->next = NULL; // Ensure the new node is the tail

    // Case 1: List is empty
    if (studentList == NULL) {
        return newStudent; // newStudent becomes the new head
    }

    // Case 2: Find the last element
    Student *current = studentList;
    while (current->next != NULL) {
        current = current->next;
    }

    // Add the new student to the end
    current->next = newStudent;

    return studentList; // Return the original head
}

Teacher *createNewTeacherInstance(Teacher *newTeacher) {
    if (newTeacher == NULL) {
        return NULL;
    }

    printf("Kérjük, adja meg az oktató adatait egy sorban, pontosvesszővel (;) elválasztva. \n");
    printf("A bevitelt a következő formátumban várjuk (max %d csoportkóddal):\n", MAX_CSOPORT_SZAM);
    printf(
        "Format: Nev;Csoport_1;Csoport_2;...;Csoport_%d\n", MAX_CSOPORT_SZAM);
    printf(
        "Ha egy csoportkód nem releváns, írjon be helyette egy egyedi jelölést (pl. '-').\n");
    printf(
        "Adat bevitele után nyomjon Entert. A bevitelt a sor elején lévő Ctrl+D (vagy Ctrl+Z) gombokkal fejezheti be.\n\n");


    int result = scanf(
        "%50[^;];"

        "%9[^;];%9[^;];%9[^;];%9[^;];%9[^;];"
        "%9[^;];%9[^;];%9[^;];%9[^;];%9[^;]",

        newTeacher->nev,
        newTeacher->csoportok[0],
        newTeacher->csoportok[1],
        newTeacher->csoportok[2],
        newTeacher->csoportok[3],
        newTeacher->csoportok[4],
        newTeacher->csoportok[5],
        newTeacher->csoportok[6],
        newTeacher->csoportok[7],
        newTeacher->csoportok[8],
        newTeacher->csoportok[9]
    );

    const int expected_items = 11;

    if (result == EOF) {
        return NULL;
    }

    if (result != expected_items) {
        fprintf(
            stderr,
            "Error: Csak %d mezőt sikerült beolvasni a %d-ből. Ellenőrizze a pontosvesszőket és a formátumot!\n",
            result,
            expected_items);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        waitForEnter();
        return NULL;
    }

    newTeacher->csoportok_szama = 0;
    for (int i = 0; i < MAX_CSOPORT_SZAM; i++) {
        if (strcmp(newTeacher->csoportok[i], "-") != 0 && strlen(newTeacher->csoportok[i]) > 0) {
            newTeacher->csoportok_szama++;
        }
    }

    newTeacher->next = NULL;
    return newTeacher;
}

Teacher *addNewTeacher(Teacher *teacherListPtr, Teacher *newTeacher) {
    if (newTeacher == NULL) {
        return teacherListPtr;
    }
    newTeacher->next = NULL;

    if (teacherListPtr == NULL) {
        return newTeacher;
    }

    Teacher *current = teacherListPtr;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newTeacher;

    return teacherListPtr;
}

void mainLoopForAddNewStudent(Student *studentListPtr) {
    Student *newStudent = NULL;
    Student *result = NULL;

    newStudent = (Student *) malloc(sizeof(Student));
    if (newStudent == NULL) {
        perror("Hiba: Memória foglalás sikertelen!\n");
        waitForEnter();
        return;
    }

    newStudent = createNewStudentInstance(newStudent);

    if (newStudent == NULL) {
        perror("Hiba: Sikertelen adatbevitel vagy művelet!\n");
        waitForEnter();
        free(newStudent);
        return;
    }

    result = addNewStudent(studentListPtr, newStudent);

    if (result != NULL) {
        printf("Sikerült hozzáadni az új tanulót!\n");
    } else {
        perror("Hiba: Nem sikerült hozzáadni az új hallgatót a listához!\n");
        free(newStudent);
    }
    waitForEnter();
}

int updateStudent(Student *studentListPtr) {
    int indexOfStudentToUpdate;
    printf("Kerem, adja meg a frissiteni kivant diak indexet (0-tol kezdve): ");

    if (scanf("%d", &indexOfStudentToUpdate) != 1 || indexOfStudentToUpdate < 0) {
        perror("HIBA: Ervenytelen index lett megadva!");
        while (getchar() != '\n');
        return -3;
    }
    while (getchar() != '\n');

    Student *selectedStudent = NULL;
    Student *current = studentListPtr;

    printf("DEBUG: Kereses megkezdve a(z) %d. indexu diakhoz.\n", indexOfStudentToUpdate);

    for (int i = 0; current != NULL; i++) {
        if (i == indexOfStudentToUpdate) {
            selectedStudent = current;
            printf("DEBUG: Diak megtalalva a(z) %d. indexen.\n", i);
            break;
        }
        current = current->next;
    }

    if (selectedStudent == NULL) {
        perror("HIBA: A valasztott diak nem letezik (ervenytelen index vagy lista vege)!");
        return -1;
    }

    printf("\n--- Eredeti adatok: ---\n");
    printf("  Nev: %s\n", selectedStudent->nev);
    printf("  Neptun kod: %s\n", selectedStudent->neptun_kod);
    printf("  Eloadas csoport: %d\n", selectedStudent->elo_csoport);
    printf("  Gyakorlati csoport: %s\n", selectedStudent->gyak_csoport);
    printf("  Hianyzasok szama: %d\n", selectedStudent->hianyzasok_szama);
    printf("  Kis ZH pontok (%d db): %.2f; %.2f; %.2f; %.2f; %.2f\n", MAX_ZH_SZAM,
           selectedStudent->kis_zh_pontok[0], selectedStudent->kis_zh_pontok[1],
           selectedStudent->kis_zh_pontok[2], selectedStudent->kis_zh_pontok[3],
           selectedStudent->kis_zh_pontok[4]);
    printf("  Nagy ZH pont: %.2f\n", selectedStudent->nzh_pont);
    printf("  Vizsga pont: %.2f\n", selectedStudent->vizsga_pont);
    printf("------------------------\n");

    printf("\nKerem, adja meg az uj adatokat, minden adatot uj sorba irjon!\n");

    printf("1. Diak neve (max %d karakter):\n", MAX_NEV_HOSSZ);
    if (fgets(selectedStudent->nev, MAX_NEV_HOSSZ + 1, stdin) == NULL) {
        perror("HIBA: Nev beolvasasi hiba!");
        return -2;
    }
    selectedStudent->nev[strcspn(selectedStudent->nev, "\n")] = 0; // Sorvégi karakter eltávolítása

    printf("2. Neptun kod (max %d karakter):\n", NEPTUN_HOSSZ);
    if (fgets(selectedStudent->neptun_kod, NEPTUN_HOSSZ + 1, stdin) == NULL) {
        perror("HIBA: Neptun kod beolvasasi hiba!");
        return -2;
    }
    selectedStudent->neptun_kod[strcspn(selectedStudent->neptun_kod, "\n")] = 0;

    printf("3. Eloadas csoport szama (egesz szam):\n");
    if (scanf("%d", &selectedStudent->elo_csoport) != 1) {
        perror("HIBA: Eloadas csoport beolvasasi hiba!");
        while (getchar() != '\n');
        return -2;
    }
    while (getchar() != '\n');

    printf("4. Gyakorlati csoport kodja (max %d karakter):\n", 10 - 1);
    if (fgets(selectedStudent->gyak_csoport, 10, stdin) == NULL) {
        perror("HIBA: Gyakorlati csoport beolvasasi hiba!");
        return -2;
    }
    selectedStudent->gyak_csoport[strcspn(selectedStudent->gyak_csoport, "\n")] = 0;

    printf("5. Hianyzasok szama (egesz szam):\n");
    if (scanf("%d", &selectedStudent->hianyzasok_szama) != 1) {
        perror("HIBA: Hianyzasok szama beolvasasi hiba!");
        while (getchar() != '\n');
        return -2;
    }
    while (getchar() != '\n');

    printf("6. Kis ZH pontok (%d db, egyenkent kulon sorba):\n", MAX_ZH_SZAM);
    for (int i = 0; i < MAX_ZH_SZAM; i++) {
        printf("   Kis ZH %d. pont:\n", i + 1);
        if (scanf("%lf", &selectedStudent->kis_zh_pontok[i]) != 1) {
            perror("HIBA: Kis ZH pont beolvasasi hiba!");
            while (getchar() != '\n');
            return -2;
        }
        while (getchar() != '\n');
    }

    printf("11. Nagy ZH pont:\n");
    if (scanf("%lf", &selectedStudent->nzh_pont) != 1) {
        perror("HIBA: Nagy ZH pont beolvasasi hiba!");
        while (getchar() != '\n');
        return -2;
    }
    while (getchar() != '\n');

    printf("12. Vizsga pont:\n");
    if (scanf("%lf", &selectedStudent->vizsga_pont) != 1) {
        perror("HIBA: Vizsga pont beolvasasi hiba!");
        while (getchar() != '\n');
        return -2;
    }
    while (getchar() != '\n');


    printf("\nSIKER: A diak adatai sikeresen frissultek!\n");
    return 1;
}

int updateTeacher(Teacher *teacherListPtr) {
    int indexOfTeacherToUpdate;
    printf("Kerem, adja meg a frissiteni kivant oktato indexet (0-tol kezdve): ");

    if (scanf("%d", &indexOfTeacherToUpdate) != 1 || indexOfTeacherToUpdate < 0) {
        perror("HIBA: Ervenytelen index lett megadva!");
        while (getchar() != '\n');
        return -3;
    }
    while (getchar() != '\n');

    Teacher *selectedTeacher = NULL;
    Teacher *current = teacherListPtr;

    printf("DEBUG: Kereses megkezdve a(z) %d. indexu oktatohoz.\n", indexOfTeacherToUpdate);

    for (int i = 0; current != NULL; i++) {
        if (i == indexOfTeacherToUpdate) {
            selectedTeacher = current;
            printf("DEBUG: Oktato megtalalva a(z) %d. indexen.\n", i);
            break;
        }
        current = current->next;
    }

    if (selectedTeacher == NULL) {
        perror("HIBA: A valasztott oktato nem letezik (ervenytelen index vagy lista vege)!");
        return -1;
    }

    printf("\n--- Eredeti adatok: ---\n");
    printf("Nev: %s\n", selectedTeacher->nev);
    printf("Csoportok szama: %d\n", selectedTeacher->csoportok_szama);
    printf("Csoportok kodjai: ");
    for (int i = 0; i < selectedTeacher->csoportok_szama; i++) {
        printf("%s%s", selectedTeacher->csoportok[i], (i == selectedTeacher->csoportok_szama - 1) ? "" : ";");
    }
    printf("\n------------------------\n");

    printf("\nKerem, adja meg az uj adatokat. Minden adatot uj sorba irjon!\n");
    printf("1. Oktato neve (max %d karakter):\n", MAX_OKTATO_NEV);

    if (fgets(selectedTeacher->nev, MAX_OKTATO_NEV + 1, stdin) == NULL) {
        perror("HIBA: Nev beolvasasi hiba!");
        return -2;
    }
    selectedTeacher->nev[strcspn(selectedTeacher->nev, "\n")] = 0;


    printf("2. Csoportok szama (max %d):\n", MAX_CSOPORT_SZAM);
    int temp_csoportok_szama;
    int result_count = scanf("%d", &temp_csoportok_szama);

    if (result_count != 1 || temp_csoportok_szama < 0 || temp_csoportok_szama > MAX_CSOPORT_SZAM) {
        perror("HIBA: Ervenytelen csoportszam!");
        while (getchar() != '\n');
        return -2;
    }
    while (getchar() != '\n');

    selectedTeacher->csoportok_szama = temp_csoportok_szama;


    printf("3. Csoportok kodjai (kulon sorba, max %d karakter, pl. 'C1_HOSSZ'):\n", CSOPORT_KOD_HOSSZ);
    for (int i = 0; i < selectedTeacher->csoportok_szama; i++) {
        printf("Csoport %d: ", i);
        if (fgets(selectedTeacher->csoportok[i], CSOPORT_KOD_HOSSZ + 1, stdin) == NULL) {
            perror("HIBA: Csoportkod beolvasasi hiba!");
            // Puffer ürítése
            while (getchar() != '\n');
            return -2;
        }
        // Eltávolítjuk a sorvégi karaktert
        selectedTeacher->csoportok[i][strcspn(selectedTeacher->csoportok[i], "\n")] = 0;
    }


    printf("\nSIKER: Az oktato adatai sikeresen frissultek!\n");
    return 1;
}

int deleteStudent(Student *headRef) {
    if (headRef == NULL) {
        perror("HIBA: A diaklista ures, nincs mit torolni.");
        return -4;
    }

    int indexOfStudentToDelete;
    printf("\nKerem, adja meg a torolni kivant diak indexet (0-tol kezdve): ");

    if (scanf("%d", &indexOfStudentToDelete) != 1 || indexOfStudentToDelete < 0) {
        perror("HIBA: Ervenytelen index lett megadva!");
        while (getchar() != '\n');
        return -3;
    }
    while (getchar() != '\n');

    Student *current = headRef;
    Student *prev = NULL;
    int i = 0;

    while (current != NULL && i != indexOfStudentToDelete) {
        prev = current;
        current = current->next;
        i++;
    }

    if (current == NULL) {
        perror("HIBA: A valasztott index nem letezik a listaban!");
        return -1;
    }

    if (prev == NULL) {
        headRef = current->next;
    } else {
        prev->next = current->next;
    }

    printf("SIKER: A diak (%s) a(z) %d. indexen sikeresen torolve.\n", current->nev, indexOfStudentToDelete);
    free(current);
    return 1;
}

int deleteTeacher(Teacher *headRef) {
    if (headRef == NULL) {
        perror("HIBA: Az oktatolista ures, nincs mit torolni.");
        return -4;
    }

    int indexOfTeacherToDelete;
    printf("\nKerem, adja meg a torolni kivant oktato indexet (0-tol kezdve): ");

    if (scanf("%d", &indexOfTeacherToDelete) != 1 || indexOfTeacherToDelete < 0) {
        perror("HIBA: Ervenytelen index lett megadva!");
        while (getchar() != '\n');
        return -3;
    }
    while (getchar() != '\n');

    Teacher *current = headRef;
    Teacher *prev = NULL;
    int i = 0;

    while (current != NULL && i != indexOfTeacherToDelete) {
        prev = current;
        current = current->next;
        i++;
    }

    if (current == NULL) {
        perror("HIBA: A valasztott index nem letezik a listaban!");
        return -1;
    }

    if (prev == NULL) {
        headRef = current->next;
    } else {
        prev->next = current->next;
    }

    printf("SIKER: Az oktato (%s) a(z) %d. indexen sikeresen torolve.\n", current->nev, indexOfTeacherToDelete);
    free(current);
    return 1;
}


void mainLoopForAddNewTeacher(Teacher *teacherListPtr) {
    Teacher *newTeacher = NULL;

    newTeacher = (Teacher *) malloc(sizeof(Teacher));
    if (newTeacher == NULL) {
        perror("Hiba: Memória foglalás sikertelen (oktató)!\n");
        waitForEnter();
        return;
    }

    newTeacher = createNewTeacherInstance(newTeacher);

    if (newTeacher == NULL) {
        perror("Hiba: Sikertelen adatbevitel vagy művelet!\n");
        waitForEnter();
        free(newTeacher);
        return;
    }


    teacherListPtr = addNewTeacher(teacherListPtr, newTeacher);

    if (teacherListPtr != NULL) {
        printf("Sikerült hozzáadni az új oktatót!\n");
    } else {
        perror("Hiba: Sikertelen hozzáadás a listához (lista fej NULL)!\n");
    }

    waitForEnter();
}


void mainLoopForUpdateMenu(Student *studentList, Teacher *teacherList) {
    int userInput;
    do {
        clear_screen();
        displayDataManagementMenu();
        scanf("%i", &userInput);
        switch (userInput) {
            // Add update student
            case 1:
                updateStudent(studentList);
                break;
            // Add update teacher
            case 2:
                updateTeacher(teacherList);
                break;
            case 3:
                deleteStudent(studentList);
                break;
            case 4:
                deleteTeacher(teacherList);
                break;
            case 9:
                break;
            default:
                printf("Nem volt megfelelő a bemenet! Kérem, csak a menüpont számát adja meg. \n");
                waitForEnter();
        }
    } while (userInput != 9);
}

void mainLoopForCreateMenu(Student *studentList, Teacher *teacherList) {
    int userInput;

    do {
        clear_screen();
        displayNewDataMenu();
        scanf("%i", &userInput);
        switch (userInput) {
            // Add new student
            case 1:
                mainLoopForAddNewStudent(studentList);
                break;
            // Add new teacher
            case 2:
                mainLoopForAddNewTeacher(teacherList);
                break;

            case 9:
                break;
            default:
                printf("Nem volt megfelelő a bemenet! Kérem, csak a menüpont számát adja meg. \n");
                waitForEnter();
        }
    } while (userInput != 9);
}

void mainLoopForListMenu(Student *studentList, Teacher *teacherList) {
    int userInput;
    do {
        clear_screen();
        displayListMenu();
        scanf("%i", &userInput);
        switch (userInput) {
            case 11:
                listAllStudents(studentList);
                break;
            case 12:
                listAllTeachers(teacherList);
                break;
            case 13:
                listAllStudentsByGroup(studentList);
                break;
            case 21:
                listAllStudentsByRetake(studentList);
                break;
            case 31:
                // listAllStudentsByPointsDescending(studentList);
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

