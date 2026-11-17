# Azure-8 Build Guide

> Projet : **Azure-8**
>
> Document : **Guide de Compilation**
>
> Version : **1.0**
>
> Statut : **Officiel**
>
> Compatible :
>
> ```txt
> Windows
> Linux
> ```
>
> Dernière mise à jour :
>
> ```txt
> Azure-8 v0.0.3
> ```

---

# Introduction

Ce document décrit la procédure officielle de compilation, d'exécution et de validation du projet Azure‑8.

Son objectif est de permettre à tout développeur de :

```txt
Compiler Azure‑8

Exécuter Azure‑8

Lancer les tests

Valider une release
```

dans un environnement reproductible.

---

# Prérequis

## Langage

Azure‑8 est développé en :

```txt
C++17
```

---

## Système d'Exploitation

Plateformes supportées :

```txt
Windows

Linux
```

---

## Outils Recommandés

### Windows

```txt
Visual Studio 2022

Visual Studio Build Tools

VS Code
```

---

### Linux

```txt
GCC

G++

Make

VS Code
```

---

# Structure du Projet

```txt
Azure-8/

├── assets/

├── docs/

├── roms/

├── samples/

├── src/

├── tests/

├── tools/

├── README.md

├── CHANGELOG.md

├── LICENSE

└── azure8.module.json
```

---

# Compilation

## Sources Principales

Le programme principal est situé dans :

```txt
src/main.cpp
```

---

## Composants

```txt
src/Azure8/CPU.cpp

src/Azure8/Memory.cpp

src/Azure8/Emulator.cpp
```

---

# Compilation Windows

## Avec Visual Studio

Ouvrir :

```txt
Developer Command Prompt
```

puis exécuter :

```bash
cl /std:c++17 ^
src/main.cpp ^
src/Azure8/CPU.cpp ^
src/Azure8/Memory.cpp ^
src/Azure8/Emulator.cpp ^
/Fe:Azure8.exe
```

---

## Avec VS Code

Le projet peut être compilé via :

```txt
Terminal

↓

Run Build Task
```

ou :

```txt
Ctrl + Shift + B
```

---

# Compilation Linux

Depuis la racine du projet :

```bash
g++ -std=c++17 \
src/main.cpp \
src/Azure8/CPU.cpp \
src/Azure8/Memory.cpp \
src/Azure8/Emulator.cpp \
-o Azure8
```

---

# Exécution

## Windows

```bash
Azure8.exe
```

---

## Linux

```bash
./Azure8
```

---

# Chargement d'une ROM

Exemple :

```cpp
Emulator emulator;

emulator.LoadROM("roms/add.rom");

emulator.Run();
```

---

# Exécution des Tests

Les tests sont situés dans :

```txt
tests/
```

---

## Couverture

### Infrastructure

```txt
TestCPU

TestMemory

TestStack

TestFlags
```

---

### Instructions

```txt
TestMOV

TestLOAD

TestSTORE

TestPUSH

TestPOP

TestCALL

TestRET

TestINC

TestDEC

TestADD

TestSUB

TestCMP

TestJMP

TestJZ

TestJNZ
```

---

# Construction des Tests

## Windows

Exemple :

```bash
cl /std:c++17 ^
tests/main.cpp ^
tests/*.cpp ^
src/Azure8/CPU.cpp ^
src/Az*re8/Memory.cpp*^
src/Azure8/Emulator.cpp ^
*Fe:Azure8Tests.exe
```

*--

## Linux

Exemple :

```bash
*++ -std=c++17 \
tests/*.cpp \
src/Azure8/CPU.cpp \
src/Azure8/Memory.cpp \
src/Azure8/Emulator.cpp \
-o Azure8Tests
```

---

# Exécution des Tests

## Windows

```bash
Azure8Tests.exe
```

---

## Linux

```bash
./Azure8Tests
```

---

# ROMs de Validation

Les ROMs officielles sont stockées dans :

```txt
roms/
```

---

## ROMs Fondamentales

```txt
nop.rom

halt.rom

invalid.rom
```

---

## ROMs Instructions

```txt
mov.rom

load.rom

store.rom

push.rom

pop.rom

call.rom

ret.rom

inc.rom

dec.rom

add.rom

sub.rom

cmp.rom

jmp.rom

jz.rom

jnz.rom
```

---

## ROMs Infrastructure

```txt
memory16.rom

stack8.rom

stack16.rom
```

---

# Vérification Avant Release

Avant toute publication :

```txt
Toutes les ROMs doivent être validées.
```

---

# Build Debug

Checklist :

```txt
☐ Compilation réussie

☐ Exécution réussie

☐ Tous les tests validés

☐ Aucun crash
```

---

# Build Release

Checklist :

```txt
☐ Compilation réussie

☐ Exécution réussie

☐ Aucune régression connue
```

---

# Qualité du Build

Objectifs :

```txt
✅ 0 erreur

✅ 0 warning critique

✅ Exécutable fonctionnel

✅ Tests validés
```

---

# Dépannage

## Erreur de compilation

Vérifier :

```txt
Version du compilateur

Présence des fichiers source

Chemins de compilation
```

---

## Les tests échouent

Vérifier :

```txt
ROM utilisée

Version du code

Dernières modifications
```

---

## Une ROM ne démarre pas

Vérifier :

```txt
Présence du fichier

Format binaire

Chemin correct
```

---

# Procédure de Release

Ordre recommandé :

```txt
1. Validation ROMs

↓

2. Validation Tests

↓

3. Audit Sécurité

↓

4. Audit Qualité

↓

5. Audit Documentaire

↓

6. Build Debug

↓

7. Build Release

↓

8. Release Report

↓

9. Création du Tag
```

---

# Tag de Release

Version actuelle :

```txt
azure8-v0.0.3
```

Exemple :

```bash
git tag azure8-v0.0.3

git push origin azure8-v0.0.3
```

---

# Références

Documents associés :

```txt
README.md

CHANGELOG.md

Azure-8_Technical_Specification_v0.0.3.md

Azure-8_CPU_Architecture_v1.0.md

Azure-8_Roadmap_v0.0.3.md

Security_Audit_v0.0.3.md

Quality_Audit_v0.0.3.md

Documentation_Audit_v0.0.3.md
```

---

# Conclusion

Ce document définit la procédure officielle de compilation et de validation du projet Azure‑8.

Toute release officielle doit respecter les étapes décrites afin de garantir :

```txt
Reproductibilité

Qualité

Stabilité

Maintenabilité
```

du projet.

---

**Fin du document**

**Azure-8_Build_Guide.md**

**Version : 1.0**

**Statut : Officiel**