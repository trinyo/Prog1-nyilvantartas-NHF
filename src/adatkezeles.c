#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/adatkezeles.h"
#include "../include/strukturak.h"
#include "../include/menuElemek.h"



double calculateTotalScore(const Student *student_ptr) {
    double total = 0.0;
    for (int i = 0; i < MAX_ZH_SZAM; i++) {
        total += student_ptr->kis_zh_pontok[i];
    }
    total += student_ptr->nzh_pont;
    total += student_ptr->vizsga_pont;
    return total;
}

void calculateGrade(double totalScore, char *result) {
    if (totalScore >= 119.0) {
        strcpy(result, "Jeles (5)");
    } else if (totalScore >= 98.0) {
        strcpy(result, "Jó (4)");
    } else if (totalScore >= 77.0) {
        strcpy(result, "Közepes (3)");
    } else if (totalScore >= 56.0) {
        strcpy(result, "Elégséges (2)");
    } else {
        strcpy(result, "Elégtelen (1)");
    }
}



void listAllStudents(Student *head) {
    if (head == NULL) {
        fprintf(stderr, "A hallgatói lista üres!\n");
        waitForEnter();
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
        fprintf(stderr, "Az oktatói lista üres!\n");
        waitForEnter();
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
        fprintf(stderr, "A lista üres!\n");
        waitForEnter();
        return;
    }
    clear_screen();
    printf("\n--- TANULÓ NYILVÁNTARTÁS CSOPORT ALAPJÁN ---\n");
    printf("| %-30s | %-10s | Gyak. Csoport\n", "Név", "Előadás Cs.");
    printf("----------------------------------------------------------------------\n");

    Student *current = head;
    while (current != NULL) {
        printf("| %-30s | %-10i | %-s \n", current->nev, current->elo_csoport,
               current->gyak_csoport);
        current = current->next;
    }
    printf("--------------------------------------------------\n");
    waitForEnter();
}


void listAllStudentsByNZH(Student *head) {
    if (head == NULL) {
        fprintf(stderr, "A lista üres!\n");
        waitForEnter();
        return;
    }
    clear_screen();
    printf("\n--- TANULÓ NYILVÁNTARTÁS NZH ALAPJÁN ---\n");
    printf("| %-30s | %-10s |\n", "Név", "NZH Pontszám");
    printf("--------------------------------------------\n");

    Student *current = head;
    while (current != NULL) {
        printf("| %-30s | %-10.2f |\n", current->nev, current->nzh_pont);
        current = current->next;
    }
    printf("--------------------------------------------------\n");
    waitForEnter();
}

void listAllStudentsByKZH(Student *head) {
    if (head == NULL) {
        fprintf(stderr, "A lista üres!\n");
        waitForEnter();
        return;
    }
    clear_screen();
    printf("\n--- TANULÓ NYILVÁNTARTÁS KZH ALAPJÁN ---\n");
    printf("| %-30s | KZH1     | KZH2     | KZH3     | KZH4     | KZH5     |\n", "Név");
    printf("------------------------------------------------------------------\n");

    Student *current = head;
    while (current != NULL) {
        printf("| %-30s | %-8.2f | %-8.2f | %-8.2f | %-8.2f | %-8.2f |\n",
            current->nev,
            current->kis_zh_pontok[0],
            current->kis_zh_pontok[1],
            current->kis_zh_pontok[2],
            current->kis_zh_pontok[3],
            current->kis_zh_pontok[4]);
        current = current->next;
    }
    printf("------------------------------------------------------------------\n");
    waitForEnter();
}

void listAllStudentsByNEPTUN(Student *head) {
    if (head == NULL) {
        fprintf(stderr, "A lista üres!\n");
        waitForEnter();
        return;
    }
    clear_screen();
    printf("\n--- TANULÓ NYILVÁNTARTÁS NEPTUN KÓD ALAPJÁN ---\n");
    printf("| %-30s | %-10s |\n", "Név", "NEPTUN Kód");
    printf("--------------------------------------------\n");

    Student *current = head;
    while (current != NULL) {
        printf("| %-30s | %-10s |\n",
            current->nev,
            current->neptun_kod);
        current = current->next;
    }
    printf("--------------------------------------------\n");
    waitForEnter();
}

void listAllStudentsByRetake(Student *head) {
    if (head == NULL) {
        fprintf(stderr, "A lista üres!\n");
        waitForEnter();
        return;
    }
    clear_screen();
    printf("\n--- PZH-ra KÖTELEZETT HALLGATÓK (NZH < 25) ---\n");
    printf("| %-30s | %-10s |\n", "Név", "NZH Pontszám");
    printf("--------------------------------------------\n");

    Student *current = head;
    while (current != NULL) {
        if (current->nzh_pont < 25.0) {
            printf("| %-30s | %-10.2f |\n", current->nev, current->nzh_pont);
        }
        current = current->next;
    }
    printf("--------------------------------------------\n");
    waitForEnter();
}



Student *createNewStudentInstance(Student *newStudent) {
    printf("Kérjük, adja meg a hallgató adatait egy sorban, pontosvesszővel (;) elválasztva. \n");
    printf(
        "Format: Nev;Neptun_kod;Eloadas_csoport;Gyakorlati_csoport;Hianyzasok;ZH1;ZH2;ZH3;ZH4;ZH5;NZH_pont;Vizsga_pont\n");
    printf(
        "Adat bevitele után nyomjon Entert. A bevitelt a sor elején lévő Ctrl+D (vagy Ctrl+Z) gombokkal fejezheti be.\n\n");

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    int result = scanf(
        // 1. Nev, Neptun_kod (Strings with semicolon delimiter)
        " %50[^;];%6[^;];"

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

    const int expected_items = 12;

    if (result == EOF) {
        return NULL;
    }

    while ((c = getchar()) != '\n' && c != EOF);

    if (result != expected_items) {
        fprintf(stderr, "Hiba: Csak %d adatot sikerült beolvasni a %d-ből. Ellenőrizze a formátumot.\n", result,
                expected_items);
        return NULL;
    }
    return newStudent;
}

Student *addNewStudent(Student *studentList, Student *newStudent) {
    if (newStudent == NULL) {
        return studentList;
    }
    newStudent->next = NULL;

    if (studentList == NULL) {
        return newStudent;
    }

    Student *current = studentList;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newStudent;

    return studentList;
}

Teacher *createNewTeacherInstance(Teacher *newTeacher) {
    if (newTeacher == NULL) {
        return NULL;
    }

    printf("Kérjük, adja meg az oktató adatait egy sorban, pontosvesszővel (;) elválasztva. \n");
    printf("A bevitelt a következő formátumban várjuk (max %d csoportkóddal):\n", MAX_CSOPORT_SZAM);
    printf(
        "Format: Nev;Csoport_1;Csoport_2;...;Csoport_%d (nem relevánsra írjon be '-'-t)\n", MAX_CSOPORT_SZAM);

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    int result = scanf(
        " %50[^;];"
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

    while ((c = getchar()) != '\n' && c != EOF);

    if (result != expected_items) {
        fprintf(
            stderr,
            "Hiba: Csak %d mezőt sikerült beolvasni a %d-ből. Ellenőrizze a pontosvesszőket és a formátumot!\n",
            result,
            expected_items);
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

void mainLoopForAddNewStudent(Student **studentListHead) {
    Student *newStudent = NULL;

    newStudent = (Student *) malloc(sizeof(Student));
    if (newStudent == NULL) {
        perror("Hiba: Memória foglalás sikertelen");
        waitForEnter();
        return;
    }

    if (createNewStudentInstance(newStudent) == NULL) {
        fprintf(stderr, "Hiba: Sikertelen adatbevitel vagy művelet!\n");
        waitForEnter();
        free(newStudent);
        return;
    }

    Student *newHead = addNewStudent(*studentListHead, newStudent);

    if (newHead != NULL) {
        *studentListHead = newHead;
        printf("Sikerült hozzáadni az új tanulót!\n");
    } else {
        fprintf(stderr, "Hiba: Nem sikerült hozzáadni az új hallgatót a listához!\n");
        free(newStudent);
    }
    waitForEnter();
}

void mainLoopForAddNewTeacher(Teacher **teacherListHead) {
    Teacher *newTeacher = NULL;

    newTeacher = (Teacher *) malloc(sizeof(Teacher));
    if (newTeacher == NULL) {
        perror("Hiba: Memória foglalás sikertelen (oktató)!");
        waitForEnter();
        return;
    }

    if (createNewTeacherInstance(newTeacher) == NULL) {
        fprintf(stderr, "Hiba: Sikertelen adatbevitel vagy művelet!\n");
        waitForEnter();
        free(newTeacher);
        return;
    }

    Teacher *newHead = addNewTeacher(*teacherListHead, newTeacher);

    if (newHead != NULL) {
        *teacherListHead = newHead;
        printf("Sikerült hozzáadni az új oktatót!\n");
    } else {
        fprintf(stderr, "Hiba: Nem sikerült hozzáadni az új oktatót a listához!\n");
        free(newTeacher);
    }
    waitForEnter();
}



int updateStudent(Student *studentListPtr) {
    int indexOfStudentToUpdate;
    printf("Kérem, adja meg a frissíteni kívánt diák indexét (0-tól kezdve): ");

    if (scanf("%d", &indexOfStudentToUpdate) != 1 || indexOfStudentToUpdate < 0) {
        fprintf(stderr, "HIBA: Érvénytelen index lett megadva!\n");
        while (getchar() != '\n');
        return -3;
    }
    while (getchar() != '\n');

    Student *selectedStudent = NULL;
    Student *current = studentListPtr;

    for (int i = 0; current != NULL; i++) {
        if (i == indexOfStudentToUpdate) {
            selectedStudent = current;
            break;
        }
        current = current->next;
    }

    if (selectedStudent == NULL) {
        fprintf(stderr, "HIBA: A választott diák nem létezik (érvénytelen index vagy lista vége)!\n");
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

    printf("\nKérem, adja meg az új adatokat, minden adatot új sorba írjon!\n");

    printf("1. Diák neve (max %d karakter):\n", MAX_NEV_HOSSZ);
    if (fgets(selectedStudent->nev, MAX_NEV_HOSSZ + 1, stdin) == NULL) {
        fprintf(stderr, "HIBA: Név beolvasási hiba!\n");
        return -2;
    }
    selectedStudent->nev[strcspn(selectedStudent->nev, "\n")] = 0;

    printf("2. Neptun kód (max %d karakter):\n", NEPTUN_HOSSZ);
    if (fgets(selectedStudent->neptun_kod, NEPTUN_HOSSZ + 1, stdin) == NULL) {
        fprintf(stderr, "HIBA: Neptun kód beolvasási hiba!\n");
        return -2;
    }
    selectedStudent->neptun_kod[strcspn(selectedStudent->neptun_kod, "\n")] = 0;

    printf("3. Előadás csoport száma (egész szám):\n");
    if (scanf("%d", &selectedStudent->elo_csoport) != 1) {
        fprintf(stderr, "HIBA: Előadás csoport beolvasási hiba!\n");
        while (getchar() != '\n');
        return -2;
    }
    while (getchar() != '\n');

    printf("4. Gyakorlati csoport kódja (max %d karakter):\n", 9);
    if (fgets(selectedStudent->gyak_csoport, 10, stdin) == NULL) {
        fprintf(stderr, "HIBA: Gyakorlati csoport beolvasási hiba!\n");
        return -2;
    }
    selectedStudent->gyak_csoport[strcspn(selectedStudent->gyak_csoport, "\n")] = 0;

    printf("5. Hiányzások száma (egész szám):\n");
    if (scanf("%d", &selectedStudent->hianyzasok_szama) != 1) {
        fprintf(stderr, "HIBA: Hiányzások száma beolvasási hiba!\n");
        while (getchar() != '\n');
        return -2;
    }
    while (getchar() != '\n');

    printf("6. Kis ZH pontok (%d db, egyenként külön sorba):\n", MAX_ZH_SZAM);
    for (int i = 0; i < MAX_ZH_SZAM; i++) {
        printf("   Kis ZH %d. pont:\n", i + 1);
        if (scanf("%lf", &selectedStudent->kis_zh_pontok[i]) != 1) {
            fprintf(stderr, "HIBA: Kis ZH pont beolvasási hiba!\n");
            while (getchar() != '\n');
            return -2;
        }
        while (getchar() != '\n');
    }

    printf("11. Nagy ZH pont:\n");
    if (scanf("%lf", &selectedStudent->nzh_pont) != 1) {
        fprintf(stderr, "HIBA: Nagy ZH pont beolvasási hiba!\n");
        while (getchar() != '\n');
        return -2;
    }
    while (getchar() != '\n');

    printf("12. Vizsga pont:\n");
    if (scanf("%lf", &selectedStudent->vizsga_pont) != 1) {
        fprintf(stderr, "HIBA: Vizsga pont beolvasási hiba!\n");
        while (getchar() != '\n');
        return -2;
    }
    while (getchar() != '\n');


    printf("\nSIKER: A diák adatai sikeresen frissültek!\n");
    return 1;
}

int updateTeacher(Teacher *teacherListPtr) {
    int indexOfTeacherToUpdate;
    printf("Kérem, adja meg a frissíteni kívánt oktató indexét (0-tól kezdve): ");

    if (scanf("%d", &indexOfTeacherToUpdate) != 1 || indexOfTeacherToUpdate < 0) {
        fprintf(stderr, "HIBA: Érvénytelen index lett megadva!\n");
        while (getchar() != '\n');
        return -3;
    }
    while (getchar() != '\n');

    Teacher *selectedTeacher = NULL;
    Teacher *current = teacherListPtr;

    for (int i = 0; current != NULL; i++) {
        if (i == indexOfTeacherToUpdate) {
            selectedTeacher = current;
            break;
        }
        current = current->next;
    }

    if (selectedTeacher == NULL) {
        fprintf(stderr, "HIBA: A választott oktató nem létezik (érvénytelen index vagy lista vége)!\n");
        return -1;
    }

    printf("\n--- Eredeti adatok: ---\n");
    printf("Név: %s\n", selectedTeacher->nev);
    printf("Csoportok szama: %d\n", selectedTeacher->csoportok_szama);
    printf("Csoportok kódjai: ");
    for (int i = 0; i < selectedTeacher->csoportok_szama; i++) {
        printf("%s%s", selectedTeacher->csoportok[i], (i == selectedTeacher->csoportok_szama - 1) ? "" : ";");
    }
    printf("\n------------------------\n");

    printf("\nKérem, adja meg az új adatokat. Minden adatot új sorba írjon!\n");
    printf("1. Oktató neve (max %d karakter):\n", MAX_OKTATO_NEV);

    if (fgets(selectedTeacher->nev, MAX_OKTATO_NEV + 1, stdin) == NULL) {
        fprintf(stderr, "HIBA: Név beolvasási hiba!\n");
        return -2;
    }
    selectedTeacher->nev[strcspn(selectedTeacher->nev, "\n")] = 0;


    printf("2. Csoportok száma (max %d):\n", MAX_CSOPORT_SZAM);
    int temp_csoportok_szama;
    int result_count = scanf("%d", &temp_csoportok_szama);

    if (result_count != 1 || temp_csoportok_szama < 0 || temp_csoportok_szama > MAX_CSOPORT_SZAM) {
        fprintf(stderr, "HIBA: Érvénytelen csoportszám!\n");
        while (getchar() != '\n');
        return -2;
    }
    while (getchar() != '\n');

    selectedTeacher->csoportok_szama = temp_csoportok_szama;


    printf("3. Csoportok kódjai (külön sorba, max %d karakter, pl. 'G01'):\n", CSOPORT_KOD_HOSSZ);
    for (int i = 0; i < selectedTeacher->csoportok_szama; i++) {
        printf("Csoport %d: ", i);
        if (fgets(selectedTeacher->csoportok[i], CSOPORT_KOD_HOSSZ + 1, stdin) == NULL) {
            fprintf(stderr, "HIBA: Csoportkód beolvasási hiba!\n");
            while (getchar() != '\n');
            return -2;
        }
        selectedTeacher->csoportok[i][strcspn(selectedTeacher->csoportok[i], "\n")] = 0;
    }

    for (int i = selectedTeacher->csoportok_szama; i < MAX_CSOPORT_SZAM; i++) {
        selectedTeacher->csoportok[i][0] = '\0';
    }


    printf("\nSIKER: Az oktató adatai sikeresen frissültek!\n");
    return 1;
}

int deleteStudent(Student **studentListHead) {
    if (*studentListHead == NULL) {
        fprintf(stderr, "HIBA: A diáklista üres, nincs mit törölni.\n");
        return -4;
    }

    int indexOfStudentToDelete;
    printf("\nKérem, adja meg a törölni kívánt diák indexét (0-tól kezdve): ");

    if (scanf("%d", &indexOfStudentToDelete) != 1 || indexOfStudentToDelete < 0) {
        fprintf(stderr, "HIBA: Érvénytelen index lett megadva!\n");
        while (getchar() != '\n');
        return -3;
    }
    while (getchar() != '\n');

    Student *current = *studentListHead;
    Student *prev = NULL;
    int i = 0;

    while (current != NULL && i != indexOfStudentToDelete) {
        prev = current;
        current = current->next;
        i++;
    }

    if (current == NULL) {
        fprintf(stderr, "HIBA: A választott index nem létezik a listában!\n");
        return -1;
    }

    if (prev == NULL) {
        *studentListHead = current->next;
    } else {
        prev->next = current->next;
    }

    printf("SIKER: A diák (%s) a(z) %d. indexen sikeresen törölve.\n", current->nev, indexOfStudentToDelete);
    free(current);
    return 1;
}

int deleteTeacher(Teacher **teacherListHead) {
    if (*teacherListHead == NULL) {
        fprintf(stderr, "HIBA: Az oktatólista üres, nincs mit törölni.\n");
        return -4;
    }

    int indexOfTeacherToDelete;
    printf("\nKérem, adja meg a törölni kívánt oktató indexét (0-tól kezdve): ");

    if (scanf("%d", &indexOfTeacherToDelete) != 1 || indexOfTeacherToDelete < 0) {
        fprintf(stderr, "HIBA: Érvénytelen index lett megadva!\n");
        while (getchar() != '\n');
        return -3;
    }
    while (getchar() != '\n');

    Teacher *current = *teacherListHead;
    Teacher *prev = NULL;
    int i = 0;

    while (current != NULL && i != indexOfTeacherToDelete) {
        prev = current;
        current = current->next;
        i++;
    }

    if (current == NULL) {
        fprintf(stderr, "HIBA: A választott index nem létezik a listában!\n");
        return -1;
    }

    if (prev == NULL) {
        *teacherListHead = current->next;
    } else {
        prev->next = current->next;
    }

    printf("SIKER: Az oktató (%s) a(z) %d. indexen sikeresen törölve.\n", current->nev, indexOfTeacherToDelete);
    free(current);
    return 1;
}


void mainLoopForCreateMenu(Student **studentListHead, Teacher **teacherListHead) {
    int userInput;

    do {
        clear_screen();
        displayNewDataMenu();
        scanf("%i", &userInput);
        switch (userInput) {
            case 1:
                mainLoopForAddNewStudent(studentListHead);
                break;
            case 2:
                mainLoopForAddNewTeacher(teacherListHead);
                break;

            case 9:
                break;
            default:
                printf("Nem volt megfelelő a bemenet! Kérem, csak a menüpont számát adja meg. \n");
                waitForEnter();
        }
    } while (userInput != 9);
}

void mainLoopForUpdateMenu(Student **studentListHead, Teacher **teacherListHead) {
    int userInput;
    do {
        clear_screen();
        displayDataManagementMenu();
        scanf("%i", &userInput);
        switch (userInput) {
            case 1:
                updateStudent(*studentListHead);
                break;
            case 2:
                updateTeacher(*teacherListHead);
                break;
            case 3:
                deleteStudent(studentListHead);
                break;
            case 4:
                deleteTeacher(teacherListHead);
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
            case 14:
                listAllStudentsByNZH(studentList);
                break;
            case 15:
                listAllStudentsByKZH(studentList);
                break;
            case 16:
                listAllStudentsByNEPTUN(studentList);
                break;
            case 21:
                listAllStudentsByRetake(studentList);
                break;
            default:
                break;
        }
    } while (userInput != 9);
}