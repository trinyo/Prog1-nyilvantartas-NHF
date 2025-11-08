#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void displayMainMenu() {
  printf("==========================================\n");
  printf("|       HALLGATÓI NYILVÁNTARTÁS          |\n");
  printf("==========================================\n\n");

  printf("Válasszon menüpontot a számozott opciók közül:\n\n");

  printf("[1]  Listázás (Adatok szűrése, rangsorolása)\n");
  printf("[2]  Új adat felvétele (Hallgató/Oktató rögzítése)\n");
  printf("[3]  Információ szerkesztése / törlése\n");
  printf("------------------------------------------\n");
  printf("[0]  Kilépés a programból\n\n");

  printf("Adja meg a választott számot: ");
}

void displayListMenu() {
  printf("\n==========================================\n");
  printf("|            LISTÁZÁS MENÜ               |\n");
  printf("==========================================\n");

  printf("\nVálasszon egy listázási / elemzési opciót:\n");

  printf("\n--- ALAP LISTÁK ---\n");
  printf("[11] Összes hallgatói rekord listázása\n");
  printf("[12] Összes oktatói rekord listázása\n");
  printf("[13] Hallgatók listázása csoport szerint (pl. G01)\n");

  printf("\n--- SZŰRÉS ÉS PÓTLÁS ---\n");
  printf("[21] PZH-ra kötelezett hallgatók listája (Pót-ZH)\n");
  printf("[22] Pótlásra kötelezett hallgatók listája (Nagy házi, labor)\n");

  printf("\n--- RANGSOROLÁS ÉS STATISZTIKA ---\n");
  printf(
      "[31] Hallgatói rangsor (Összpontszám szerint, csökkenő sorrendben)\n");
  printf("[32] Legtöbbet hiányzó hallgatók listája\n");
  printf("[33] Csoportok összehasonlítása (Átlagpontszám szerint)\n");

  printf("------------------------------------------\n");
  printf("[9]  Vissza a főmenübe\n\n");

  printf("Adja meg a választott számot: ");
}

void displayNewDataMenu() {
  printf("\n==========================================\n");
  printf("|       ÚJ ADAT FELVÉTELE MENÜ           |\n");
  printf("==========================================\n\n");

  printf("Milyen típusú új rekordot szeretne felvenni?\n\n");

  printf("[1]  Új HALLGATÓ felvétele\n");
  printf("[2]  Új OKTATÓ felvétele\n");
  printf("------------------------------------------\n");
  printf("[9]  Vissza a főmenübe\n\n");

  printf("Adja meg a választott számot: ");
}

void clear_screen() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

int main(int argc, char *argv[]) {
  int userInput;
  clear_screen();
  displayMainMenu();
  do {
    scanf("%i", &userInput);
    switch (userInput) {
    case 1:
      clear_screen();
      displayListMenu();
      break;
    case 2:
      clear_screen();
      displayNewDataMenu();
      break;
    case 3:
      clear_screen();
      break;
    case 9:
      displayMainMenu();
    }
  } while (userInput != 0);

  return EXIT_SUCCESS;
}
