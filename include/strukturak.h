#ifndef STRUKTURAK_H
#define STRUKTURAK_H

#define MAX_NEV_HOSSZ 50
#define NEPTUN_HOSSZ 6
#define MAX_ZH_SZAM 5 // Fixen 5 kis ZH

typedef struct {
  // --- Személyes és Csoport Adatok ---
  char nev[MAX_NEV_HOSSZ + 1];       // Hallgató neve
  char neptun_kod[NEPTUN_HOSSZ + 1]; // Neptun kód (6 karakter + lezáró \0)
  int elo_csoport;                   // Előadás csoport száma (pl. 1)
  char gyak_csoport[10];             // Gyakorlati csoport kódja (pl. "G01")

  // --- Eredmények és Teljesítmények ---
  int hianyzasok_szama;
  double kis_zh_pontok[MAX_ZH_SZAM]; // 5 db kis ZH pontszám
  double nzh_pont;                   // Nagy ZH pontszám
  double vizsga_pont;                // Vizsgapont
} Student;

#define MAX_OKTATO_NEV 50
#define MAX_CSOPORT_SZAM 10 // Fixen max 10 csoportot tarthat egy oktató
#define CSOPORT_KOD_HOSSZ 9 // Pl. "G01" vagy "L07"

typedef struct {
  char nev[MAX_OKTATO_NEV + 1]; // Oktató neve

  // Mely csoportokat tartja
  char csoportok[MAX_CSOPORT_SZAM][CSOPORT_KOD_HOSSZ + 1];
  int csoportok_szama; // Az aktuálisan tartott csoportok száma
} Teacher;
#endif
