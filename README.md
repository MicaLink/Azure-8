# Azure-8

![Version](https://img.shields.io/badge/version-v0.0.4-blue)
![Language](https://img.shields.io/badge/language-C%2B%2B17-orange)
![Status](https://img.shields.io/badge/status-consolidation-yellow)
![Platform](https://img.shields.io/badge/platform-Windows-lightgrey)

## Presentation

Azure-8 est une machine virtuelle 8 bits developpee dans le cadre de l'ecosysteme AzureEngine.

Le projet sert de plateforme d'experimentation pour :

- la conception d'architectures CPU virtuelles ;
- l'emulation logicielle ;
- les systemes memoire ;
- les outils de developpement bas niveau ;
- les futurs composants AzureEngine.

Azure-8 n'emule aucune machine existante.

Il s'agit d'une architecture proprietaire concue pour l'apprentissage, l'experimentation et la validation de concepts lies aux machines virtuelles.

---

# Etat du projet

##### Version actuelle

```text
v0.0.4
```

##### Statut

```text
Consolidation du coeur
```

Avancement :

- CPU : Termine
- Memoire : Termine
- Pile : Termine
- ISA v0.0.3 : Termine
- ROMs de validation : Termine
- Tests unitaires : Termine
- Documentation : Termine
- Consolidation v0.0.4 : En cours

---

# Utilisation de l'IA

L'intelligence artificielle est utilisee pour :

- la redaction documentaire ;
- les revues techniques ;
- l'analyse de dette technique ;
- la preparation des refactorisations ;
- les audits qualite ;
- les audits documentaires ;
- l'amelioration de la maintenabilite.

Tous les contenus generes sont verifies avant integration dans le projet.

---

## AzureEngine

Azure-8 est le premier module officiel de l'ecosysteme AzureEngine.

### Vision cible

```text
AzureEngine
|
+-- Azure-8
+-- Azure8-SDK
+-- Azure8-IDE
+-- CHIP-8
+-- CHIP8-SDK
+-- CHIP8-IDE
+-- Futurs modules
```

AzureEngine represente la plateforme.

Azure-8 constitue la premiere implementation de reference.

---

# Architecture

## CPU

Caracteristiques :

- Architecture 8 bits
- Adressage memoire 16 bits
- Little Endian
- 4 registres utilisateur
- 3 registres systeme

Registres utilisateur :

- A
- B
- C
- D

Registres systeme :

- PC
- SP
- FLAGS

Flags :

- ZERO
- CARRY
- NEGATIVE
- OVERFLOW

---

## Memoire

Caracteristiques :

- Taille : 64 Ko
- Adressage : 0x0000 - 0xFFFF
- Organisation : Little Endian

---

## Pile

Fonctions :

- Push8()
- Pop8()
- Push16()
- Pop16()

Protections :

- Detection Stack Overflow
- Detection Stack Underflow

---

# Jeu d'instructions

Controle CPU :

- NOP
- HLT

Manipulation de donnees :

- MOV
- LOAD
- STORE

Gestion de pile :

- PUSH
- POP
- CALL
- RET

Arithmetique :

- INC
- DEC
- ADD
- SUB

Comparaison :

- CMP

Branchements :

- JMP
- JZ
- JNZ

---

## Structure du projet

```text
Azure-8
|
+-- assets
+-- build
+-- docs
+-- roms
+-- samples
+-- src
+-- tests
+-- tools
|
+-- README.md
+-- CHANGELOG.md
+-- LICENSE
+-- azure8.module.json
```

---

## Organisation des sources

```text
src
|
+-- Azure8
|   +-- CPU.cpp
|   +-- CPU.h
|   +-- Emulator.cpp
|   +-- Emulator.h
|   +-- Memory.cpp
|   +-- Memory.h
|
+-- Core
    +-- Type.h
```

---

# Documentation

Dossiers principaux :

- architecture
- developpement
- roadmap
- reports
- specifications

Archives :

- releases
- reports
- roadmap
- specifications

Les documents actifs sont separes des archives historiques.

---

# Compilation

Sous Windows :

- Visual Studio
- Visual Studio Code
- MSVC

Les taches de compilation peuvent etre configurees dans :

.vscode/tasks.json

---

# Execution

Procedure generale :

1. Creer un Emulator
2. Initialiser le systeme
3. Charger une ROM
4. Executer la ROM

---

# ROMs de validation

ROMs fondamentales :

- nop.rom
- halt.rom
- invalid.rom

ROMs d'instructions :

- mov.rom
- load.rom
- store.rom
- push.rom
- pop.rom
- call.rom
- ret.rom
- inc.rom
- dec.rom
- add.rom
- sub.rom
- cmp.rom
- jmp.rom
- jz.rom
- jnz.rom

ROMs d'infrastructure :

- memory16.rom
- stack8.rom
- stack16.rom

---

# Tests

Tests d'infrastructure :

- TestCPU.cpp
- TestMemory.cpp
- TestStack.cpp
- TestFlags.cpp

Tests d'instructions :

- TestInstructionMOV.cpp
- TestInstructionLOAD.cpp
- TestInstructionSTORE.cpp
- TestInstructionPUSH.cpp
- TestInstructionPOP.cpp
- TestInstructionCALL.cpp
- TestInstructionRET.cpp
- TestInstructionINC.cpp
- TestInstructionDEC.cpp
- TestInstructionADD.cpp
- TestInstructionSUB.cpp
- TestInstructionCMP.cpp
- TestInstructionJMP.cpp
- TestInstructionJZ.cpp
- TestInstructionJNZ.cpp

---

# Documentation principale

Architecture :

- Azure-8_Architecture_Guide.md
- Azure-8_CPU_Architecture_v1.0.md

Specifications :

- Azure-8_Technical_Specification_v0.0.3.md
- Azure-8_Instruction_Set_v0.0.3.md
- Azure-8_Module_Specification_v1.0.md

Documentation v0.0.4 :

- Azure-8_Roadmap_v0.0.4.md
- Core_Consolidation_Report_v0.0.4.md
- Core_Review_Report_v0.0.4.md
- CPU_Modularization_Plan_v0.0.4.md
- CPU_Refactoring_Checklist_v0.0.4.md
- Technical_Debt_Report_v0.0.4.md
- Flag_Coverage_Report_v0.0.4.md
- Arithmetic_Flag_Validation_Plan_v0.0.4.md
- Test_Matrix_v0.0.4.md

---

# Feuille de route actuelle

La version v0.0.4 est consacree a :

- la consolidation du CPU ;
- la validation des FLAGS ;
- le renforcement des tests ;
- la modularisation du CPU ;
- la reduction de la dette technique ;
- l'amelioration de la maintenabilite ;
- la stabilisation du coeur Azure-8.

Aucune nouvelle fonctionnalite n'est prevue durant ce cycle.

---

# Philosophie

Azure-8 repose sur plusieurs principes :

- simplicite ;
- comprehension ;
- controle ;
- testabilite ;
- documentation ;
- evolutivite.

Le projet privilegie une architecture simple a comprendre et facile a maintenir.

---

# Auteur

Thomas Galliot

---

# Licence

Voir le fichier LICENSE.

---

# Futur du projet

Une fois la consolidation v0.0.4 terminee, les futures versions pourront preparer :

- Azure8-SDK ;
- Azure8-IDE ;
- nouvelles ROMs de demonstration ;
- outils d'analyse ;
- outils de developpement avances.

La priorite actuelle reste la consolidation complete du coeur Azure-8.