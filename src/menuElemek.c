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

void displayDataManagementMenu() {
  printf("\n==========================================\n");
  printf("|        ADATKEZELÉSI MENÜ              |\n");
  printf("==========================================\n\n");

  printf("Milyen típusú műveletet szeretne végrehajtani?\n\n");

  printf("--- FRISSÍTÉS ---\n");
  printf("[1]   HALLGATÓ adatainak frissítése\n");
  printf("[2]   OKTATÓ adatainak frissítése\n\n");

  printf("--- TÖRLÉS ---\n");
  printf("[3]   HALLGATÓ törlése a listából\n");
  printf("[4]   OKTATÓ törlése a listából\n");
  printf("------------------------------------------\n");

  printf("[9]  Vissza a főmenübe\n\n");

  printf("Adja meg a választott számot: ");
}
void clear_screen() {
#ifdef _WIN32
  system( "chcp 65001 >nul" );
  system("cls");
#else
  system("clear");
#endif
}
void waitForEnter() {
  printf("\nNyomd meg az ENTER billentyűt a továbblépéshez...");

  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }

  getchar();
}
