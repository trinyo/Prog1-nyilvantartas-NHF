
# 🎓 Hallgatói és Oktatói Nyilvántartó Rendszer

## Bevezetés

Ez a projekt egy **C nyelvű, konzolos alkalmazás**, amely láncolt listák segítségével kezeli a hallgatói és oktatói rekordokat. A program menüvezérelt felületet biztosít az adatok megtekintéséhez, felvételéhez, módosításához és törléséhez. Az adatok perzisztens tárolása CSV fájlokban történik.

## 🌟 Fő Funkciók

A rendszer a következő alapvető adatkezelési funkciókat támogatja:

* **Betöltés és Mentés:** A hallgatói és oktatói adatok automatikus betöltése a **program futási könyvtárából** induláskor, és mentése kilépéskor.
* **Listázás:** Diákok és tanárok listázása, valamint hallgatók szűrése csoport, NZH/KZH eredmény, NEPTUN kód és PZH-ra kötelezettség szerint.
* **Adatbevitel (CREATE):** Új hallgatói vagy oktatói rekordok felvétele.
* **Módosítás (UPDATE):** Meglévő hallgatói és oktatói rekordok interaktív szerkesztése.
* **Törlés (DELETE):** Hallgatók és oktatók eltávolítása a láncolt listából.
* **Pontszámítás:** Összesített pontszámok és végső érdemjegy kiszámítása.

## 💻 Technológiai áttekintés

| Komponens | Technológia / Verzió | Megjegyzés |
| :--- | :--- | :--- |
| **Nyelv** | C | C11 szabvány használatával. |
| **Fordító** | GCC / Clang | Ajánlott fordítóprogramok. |
| **Build Rendszer** | **CMake** (3.10+) | A projekt fordításának menedzselésére. |
| **Adatszerkezet** | Láncolt listák | `Student` és `Teacher` struktúrák kezelésére. |
| **Adatformátum** | CSV (fájlok) | Pontosvesszővel (`;`) elválasztott adatok. |

## ⚙️ Fordítási és Futtatási Útmutató

A program fordításához és futtatásához szüksége lesz egy C fordítóra (GCC vagy Clang) és a **CMake** rendszerre.

### 1\. Projekt klónozása

```bash
git clone [A TE GIT REPO CÍMED]
cd [projekt-mappa-neve]
```

### 2\. Fordítás (Build)

A CMake használatával a forráskódot platformfüggetlenül lefordíthatjuk:

```bash
# Létrehozzuk a build mappát
mkdir build
cd build

# Előállítjuk a build fájlokat (pl. Makefile)
cmake ..

# Lefordítjuk a projektet
make
```

### 3\. Futtatás

A sikeres fordítás után a programot a `build` mappából futtathatja:

```bash
./HallgatoiNyilvantarto
```

## 📂 Adatfájl Szerkezet

**A program a CSV fájlokat közvetlenül a futtatható program (`./HallgatoiNyilvantarto`) mellett keresi és menti.**

* **`students.csv`**: A hallgatói rekordok tárolására szolgál.
* **`teachers.csv`**: Az oktatói rekordok tárolására szolgál.

> **FONTOS:** A program futtatásához mindkét CSV fájlnak (vagy a programnak, ha automatikusan hozza létre azokat) a **`build`** könyvtárban kell lennie a futtatás pillanatában.