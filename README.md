# Diákigazolvány adminisztráló

## Az appról

Ez egy prototípus asztali alkalmazás, a diákigazolványok adminisztrálására és matricázására.
Utóbbi tokenje egy online API-ból jön, ami hiba esetén kézzel is beírható.

Funkciók:
- Fájl...
    - létrehozása mentéssel
    - megnyitása
    - mentés másként
- Diákok...
    - listázása táblázatban
    - felvitele (dialógus ablakban)
    - módosítása (előbbi dialógus ablakban)
    - törlése (DELETE vagy BACKSPACE gombok)
- Diákigazolvány matrica generálása

## Célja 

A program célja a leendő, kártyás diákigazolványt digitalizálni hivatott szakdolgozatomnak az asztali
felületének kiszolgálása (mivel a matrica generálást sem a mobilappban, sem a webappban nem tervezem
elérhetővé tenni). A jelenlegi működés még csak prototípus szintű, a véglegesben saját adatbázisban
szeretném a tokeneket nyomon követni és saját metódus alapján generálni őket.

## Futtatás

1. Nyissuk meg projektként a `CMakeLists.txt` fájlt.
2. Indítsuk el a programot.
3. Használjuk teszteléshez a gyökérmappában lévő `.csv` fájlokat.