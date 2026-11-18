# Azure-8 Architecture Overview v1.0

> Projet : **Azure-8**
>
> Document : **Vue d'Ensemble de l'Architecture**
>
> Version : **1.0**
>
> Statut : **Officiel**
>
> Type : **Architecture Système**
>
> Auteur : **Thomas GALLIOT**

---

# Introduction

Ce document présente l'architecture générale du projet Azure‑8.

Son objectif est de fournir une vue d'ensemble des composants principaux de la machine virtuelle ainsi que de leurs interactions.

Contrairement au document :

```txt
Azure-8_CPU_Architecture_v1.0.md
```

qui décrit le fonctionnement interne du processeur, ce document décrit l'organisation globale du système Azure‑8.

---

# Objectifs

L'architecture Azure‑8 a été conçue pour être :

```txt
Simple

Modulaire

Prévisible

Facile à maintenir

Facile à tester

Facile à documenter
```

Elle sert également de base technique pour les futurs outils :

```txt
Azure8-SDK

Azure8-IDE
```

---

# Vue Générale

Architecture logique :

```txt
                     ROM
                      │
                      ▼
             +----------------+
             |    Emulator    |
             |  (LoadROM)     |
             +--------+-------+
                      │
          +-----------+-----------+
          │                       │
          ▼                       ▼
    +-----------+ <----------> +-----------+
    |    CPU    |              |  Memory   |
    +-----------+              +-----------+
          │
          ▼
    +-------------------------------+
    | Stack Mechanism               |
    | (SP + Push/Pop + Memory)      |
    +-------------------------------+

Remarque :

Le ROM Loader n'est pas implémenté comme un composant logiciel distinct.
Le chargement des ROMs est assuré par la fonction Emulator::LoadROM().

Le mécanisme de pile n'est pas implémenté comme une classe autonome.
La pile est réalisée conjointement par le registre SP, les fonctions Push8(),
Pop8(), Push16(), Pop16() du CPU et l'espace mémoire associé.
        
```

---

# Composants Principaux

## Emulator

L'émulateur est le point central du système.

Responsabilités :

```txt
Initialisation du système

Chargement des ROMs

Gestion du cycle CPU

Contrôle de l'exécution

Coordination des composants
```

Fichiers :

```txt
Emulator.cpp

Emulator.h
```

---

## CPU

Le CPU constitue le cœur de la machine virtuelle.

Responsabilités :

```txt
Lecture des instructions

Décodage

Exécution

Gestion des registres

Gestion des FLAGS
```

Fichiers :

```txt
CPU.cpp

CPU.h
```

---

## Memory

Le composant mémoire représente les 64 Ko adressables de la machine.

Responsabilités :

```txt
Lecture mémoire

Écriture mémoire

Stockage des ROMs

Support de la pile
```

Fichiers :

```txt
Memory.cpp

Memory.h
```

---

### Chargement des ROMs

Le chargement des ROMs est assuré par la fonction
Emulator::LoadROM().

Le projet ne possède pas de composant logiciel
ROM Loader indépendant.

Responsabilités :

- ouverture du fichier ROM ;
- lecture binaire ;
- copie en mémoire ;
- validation du chargement.

---

# Organisation des Sources

```txt
src/

├── main.cpp

├── Azure8/
│   │
│   ├── CPU.cpp
│   ├── CPU.h
│   │
│   ├── Memory.cpp
│   ├── Memory.h
│   │
│   ├── Emulator.cpp
│   └── Emulator.h
│
└── Core/
    │
    └── Type.h
```

---

# Flux d'Exécution

Le cycle classique d'exécution est :

```txt
1. Chargement ROM

↓

2. Initialisation CPU

↓

3. Initialisation mémoire

↓

4. Initialisation registres

↓

5. Début exécution

↓

6. FETCH

↓

7. DECODE

↓

8. EXECUTE

↓

9. Répétition

↓

10. HLT
```

---

# Flux Mémoire

La mémoire est utilisée par :

```txt
CPU

Pile

ROM
```

Représentation :

```txt
        CPU
         │
         ▼

+-----------------+
|     Memory      |
+-----------------+
         ▲
         │

       Stack
```

---

# Registres

## Utilisateur

```txt
A

B

C

D
```

Utilisation :

```txt
Calculs

Manipulation données

Stockage temporaire
```

---

## Système

```txt
PC

SP

FLAGS
```

---

# Gestion des Instructions

Le CPU exécute les instructions en trois étapes.

---

## Fetch

Lecture de l'opcode.

Source :

```txt
Memory
```

---

## Decode

Identification de l'instruction.

---

## Execute

Exécution de l'opération demandée.

---

# Gestion des FLAGS

Les FLAGS sont mis à jour après certaines opérations.

FLAGS disponibles :

```txt
ZERO

CARRY

NEGATIVE

OVERFLOW
```

---

# Gestion des ROMs

Les ROMs sont stockées dans :

```txt
roms/
```

---

# Catégories de ROMs

## Validation CPU

```txt
nop.rom

halt.rom

invalid.rom
```

---

## Validation Instructions

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

## Validation Infrastructure

```txt
memory16.rom

stack8.rom

stack16.rom
```

---

# Architecture de Test

Les tests sont séparés du moteur.

Structure :

```txt
tests/
```

Objectifs :

```txt
Validation CPU

Validation mémoire

Validation pile

Validation instructions
```

---

# Outils

Le projet prévoit des outils dédiés.

Structure :

```txt
tools/

├── disassembler/

├── rom-dumper/

└── rom-validator/
```

---

# Samples

Exemples d'utilisation :

```txt
samples/

├── HelloWorld/

├── Counter/

├── MemoryDemo/

└── StackDemo/
```

Objectif :

```txt
Apprentissage

Validation

Démonstration
```

---

# Dépendances Internes

Relations entre composants :

```txt
Emulator

↓

CPU

↓

Memory

↓

Stack
```

---

# Contraintes Architecturales

Le projet suit plusieurs principes :

```txt
Simplicité

Prévisibilité

Faible complexité

Faible couplage

Testabilité
```

---

# Évolutions Futures

Versions futures :

```txt
Azure8-SDK

Azure8-IDE

Intégration AzureEngine

Outils de développement avancés
```

Aucune de ces fonctionnalités ne modifie l'architecture fondamentale du cœur Azure‑8.

---

# Architecture v0.0.3

État actuel :

```txt
CPU             ✅

Mémoire         ✅

Pile            ✅

Instructions    ✅

ROM Loader      ✅

Tests           ✅

Documentation   ✅
```

---

# Conclusion

L'architecture Azure‑8 repose sur un ensemble réduit et clairement identifié de composants :

```txt
Emulator
CPU
Memory
Mécanisme de pile

```

Cette organisation permet de maintenir une machine virtuelle simple, robuste et facile à faire évoluer tout en conservant une excellente lisibilité du code et de la documentation.

---

**Fin du document**

**Azure-8_Architecture_Overview_v1.0.md**

**Version : 1.0**

**Statut : Officiel**