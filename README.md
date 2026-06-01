# C_projekt

Egyszerű parancssori segédprogram különböző programozási nyelvekhez tartozó alapkódok generálására.

## Funkciók

* Több programozási nyelv támogatása
* Automatikus alapkód generálás
* Alapkód terminálba kiírása fájl létrehozása nélkül
* Verzióinformáció megjelenítése
* Beépített használati útmutató

## Használat

```bash
./a.out <programozási nyelv> [opciók]
```

## Elérhető opciók

| Opció             | Leírás                                              |
| ----------------- | --------------------------------------------------- |
| `-v`, `--version` | Verziószám megjelenítése                            |
| `-h`, `--help`    | Használati útmutató megjelenítése                   |
| `--stdout`        | Az alapkód terminálba írása fájl generálása helyett |

## Támogatott programozási nyelvek

| Nyelv    | Leírás             |
| -------- | ------------------ |
| `c`      | C forráskód        |
| `sh`     | Bash script        |
| `cpp`    | C++ forráskód      |
| `java`   | Java forráskód     |
| `csharp` | C# forráskód       |
| `py`     | Python forráskód   |
| `fort`   | Fortran forráskód  |
| `rust`   | Rust forráskód     |
| `asm`    | Assembly forráskód |

## Példák

C alapkód generálása:

```bash
./a.out_neve c
```

Python alapkód terminálba kiírása:

```bash
./a.out py --stdout
```

Használati útmutató megjelenítése:

```bash
./a.out --help
```

## Fordítás

Makefile-val érdemes

```bash
makefile c
```

## Licenc

MIT License
