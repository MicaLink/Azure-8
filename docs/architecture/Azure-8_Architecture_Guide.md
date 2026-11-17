# Azure-8 Architecture Guide

> Projet : **Azure-8**
>
> Document : **Guide d'Architecture**
>
> Version : **1.0**
>
> Statut : **Officiel**
>
> Public cible : **Développeurs et contributeurs**
>
> Version du module : **v0.0.3**

---

# Introduction

Ce document décrit l'organisation interne du projet Azure‑8.

Son objectif est d'aider les développeurs à comprendre :

```txt
La structure du projet

Les responsabilités de chaque composant

Le flux d'exécution

Les règles d'évolution du code

Le processus d'ajout de fonctionnalités
```

Contrairement aux spécifications techniques, ce document explique l'architecture logicielle du projet et la manière dont ses composants collaborent.

---

# Principes d'Architecture

Azure‑8 repose sur cinq principes fondamentaux :

```txt
Simplicité

Lisibilité

Modularité

Testabilité

Documentation
```

Chaque évolution doit respecter ces principes.

---

# Vue d'Ensemble

Architecture logique :

```txt
                     ROM
                      │
                      ▼

             +----------------+
             |   Emulator     |
             +--------+-------+
                      |
          +-----------+-----------+
          |                       |
          ▼                       ▼

    +-----------+         +-----------+
    |    CPU    |<------->|  Memory   |
    +-----------+         +-----------+
          |
          ▼

    +-----------+
    |   Stack   |
    +-----------+
```

---

# Organisation du Dépôt

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

# Source Code

L'intégralité du moteur est située dans :

```txt
src/
```

---

## Structure

```txt
src/

├── main.cpp

├── Azure8/
│   ├── CPU.cpp
│   ├── CPU.h
│   ├── Memory.cpp
│   ├── Memory.h
│   ├── Emulator.cpp
│   └── Emulator.h
│
└── Core/
    └── Type.h
```

---

# Composant CPU

## Responsabilités

Le CPU est chargé de :

```txt
Lire les opcodes

Décoder les instructions

Exécuter les instructions

Mettre à jour les registres

Mettre à jour les FLAGS
```

---

## Fichiers

```txt
CPU.cpp

CPU.h
```

---

## Registres

### Utilisateur

```txt
A

B

C

D
```

---

### Système

```txt
PC

SP

FLAGS
```

---

## Cycle d'Exécution

Chaque instruction suit :

```txt
FETCH

↓

DECODE

↓

EXECUTE
```

---

# Composant Memory

## Responsabilités

Le composant mémoire fournit :

```txt
Lecture mémoire

Écriture mémoire

Stockage ROM

Support pile
```

---

## Fichiers

```txt
Memory.cpp

Memory.h
```

---

## Adresse Mémoire

```txt
0x0000

↓

0xFFFF
```

---

## Taille

```txt
64 Ko
```

---

# Gestion de la Pile

La pile n'est pas implémentée dans une classe spécifique.

Elle est gérée par :

```txt
CPU

+

Memory

+

SP
```

---

## Fonctions

```txt
Push8()

Pop8()

Push16()

Pop16()
```

---

## Utilisation

```txt
PUSH

POP

CALL

RET
```

---

# Composant Emulator

## Responsabilités

L'émulateur orchestre l'ensemble du système.

---

## Fichiers

```txt
Emulator.cpp

Emulator.h
```

---

## Fonctions Principales

```txt
Reset()

LoadROM()

Run()
```

---

## Flux de Démarrage

```txt
Créer Emulator

↓

Reset()

↓

LoadROM()

↓

Run()
```

---

# Chargement des ROMs

Les ROMs sont stockées dans :

```txt
roms/
```

---

## Processus

```txt
Lecture du fichier

↓

Chargement mémoire

↓

Initialisation CPU

↓

Exécution
```

---

# Jeu d'Instructions

Version actuelle :

```txt
v0.0.3
```

---

## Contrôle CPU

```txt
NOP

HLT
```

---

## Manipulation des Données

```txt
MOV

LOAD

STORE
```

---

## Gestion de Pile

```txt
PUSH

POP

CALL

RET
```

---

## Arithmétique

```txt
INC

DEC

ADD

SUB
```

---

## Comparaison

```txt
CMP
```

---

## Branchements

```txt
JMP

JZ

JNZ
```

---

# Ajouter une Nouvelle Instruction

Toute nouvelle instruction doit suivre la procédure suivante.

---

## Étape 1

Implémentation dans :

```txt
CPU.cpp
```

---

## Étape 2

Ajout de la définition dans :

```txt
Azure-8_Instruction_Set_vX.X.X.md
```

---

## Étape 3

Création d'une ROM dédiée :

```txt
roms/
```

Exemple :

```txt
newinstruction.rom
```

---

## Étape 4

Création d'un test dédié :

```txt
TestInstructionXXX.cpp
```

---

## Étape 5

Validation des tests

```txt
Build Debug

Build Release
```

---

# Architecture des Tests

Les tests sont séparés du moteur.

---

## Répertoire

```txt
tests/
```

---

## Catégories

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
Un fichier par instruction.
```

Exemple :

```txt
TestInstructionADD.cpp

TestInstructionSUB.cpp
```

---

# Architecture des ROMs

Les ROMs sont organisées suivant leur objectif.

---

## Fondamentales

```txt
nop.rom

halt.rom

invalid.rom
```

---

## Instructions

```txt
Une ROM par instruction.
```

---

## Infrastructure

```txt
memory16.rom

stack8.rom

stack16.rom
```

---

# Règles de Développement

Toute modification du moteur doit respecter :

```txt
Code

↓

Tests

↓

ROM

↓

Documentation
```

Une fonctionnalité n'est considérée comme terminée que lorsque les quatre éléments sont présents.

---

# Critères de Qualité

Les nouvelles contributions doivent :

```txt
Préserver la lisibilité

Préserver la simplicité

Préserver les tests

Préserver la documentation
```

---

# Architecture Future

Les extensions prévues concernent :

```txt
Azure8-SDK

Azure8-IDE

Outils avancés

Intégration AzureEngine
```

Ces projets ne doivent pas modifier l'architecture fondamentale du cœur Azure‑8.

---

# Conclusion

L'architecture Azure‑8 repose sur un ensemble réduit de composants clairement séparés :

```txt
CPU

Memory

Stack

Emulator

ROMs

Tests
```

Cette organisation garantit un code simple à comprendre, facile à tester et facile à maintenir.

Le présent document constitue la référence architecturale destinée aux développeurs du projet Azure‑8.

---

**Fin du document**

**Azure-8_Architecture_Guide.md**

**Version : 1.0**

**Statut : Officiel**