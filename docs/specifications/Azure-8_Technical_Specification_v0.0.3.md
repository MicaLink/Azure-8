# Azure-8 Technical Specification v0.0.3

> Projet : **Azure-8**
>
> Document : **Spécification Technique**
>
> Version : **0.0.3**
>
> Statut : **Officiel**
>
> Type : **Machine Virtuelle 8 bits**
>
> Auteur : **Thomas GALLIOT**

---

# Introduction

Azure‑8 est une machine virtuelle 8 bits développée dans le cadre de l'écosystème AzureEngine.

Cette machine a pour objectif de fournir :

```txt
Une architecture simple

Une plateforme d'expérimentation

Un support pédagogique

Une base technique pour AzureEngine
```

Azure‑8 est une architecture propriétaire.

Elle n'émule aucun processeur réel existant.

---

# Objectifs

Azure‑8 a été conçu pour :

```txt
Comprendre l'architecture des processeurs

Apprendre le développement bas niveau

Expérimenter les machines virtuelles

Disposer d'un environnement simple à documenter

Valider l'architecture AzureEngine
```

---

# Caractéristiques Générales

## Architecture

```txt
CPU 8 bits

Adressage mémoire 16 bits

Architecture à registres

Little Endian
```

---

## Version

```txt
0.0.3
```

---

## Type

```txt
Machine virtuelle
```

---

# Vue d'Ensemble

Architecture générale :

```txt
               +-----------+
               |    ROM    |
               +-----+-----+
                     |
                     v

+---------+    +-----------+
| Mémoire |<-->|    CPU    |
+---------+    +-----------+
                     |
                     v

               +-----------+
               |   Pile    |
               +-----------+
```

---

# CPU

## Type

```txt
8 bits
```

---

## Registres Utilisateur

Le processeur possède quatre registres généraux.

```txt
A

B

C

D
```

Ces registres sont utilisés pour :

```txt
Calcul

Stockage temporaire

Manipulation de données
```

---

## Registres Système

### PC

Program Counter.

```txt
16 bits
```

Contient :

```txt
Adresse de l'instruction courante.
```

---

### SP

Stack Pointer.

```txt
16 bits
```

Contient :

```txt
Adresse du sommet de pile.
```

---

### FLAGS

Registre d'état.

```txt
8 bits
```

---

# FLAGS

## ZERO

```txt
Z
```

Activé lorsque :

```txt
Résultat = 0
```

---

## CARRY

```txt
C
```

Activé lorsqu'une retenue est générée.

---

## NEGATIVE

```txt
N
```

Activé lorsqu'un résultat négatif est détecté.

---

## OVERFLOW

```txt
V
```

Activé lorsqu'un débordement signé est détecté.

---

# Mémoire

## Taille Totale

```txt
65536 octets

64 Ko
```

---

## Adresse Minimale

```txt
0x0000
```

---

## Adresse Maximale

```txt
0xFFFF
```

---

## Fonctions

```txt
Read8()

Write8()

Read16()

Write16()
```

---

# Format Little Endian

Azure‑8 utilise le format :

```txt
Little Endian
```

Exemple :

```txt
Valeur :

0x1234
```

Mémoire :

```txt
34 12
```

---

# Pile

La pile est utilisée pour :

```txt
CALL

RET

Sauvegarde temporaire
```

---

## Registre

```txt
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

# Cycle CPU

Le processeur fonctionne selon le cycle :

```txt
FETCH

↓

DECODE

↓

EXECUTE
```

---

## FETCH

Lecture de l'opcode à l'adresse :

```txt
PC
```

---

## DECODE

Identification de l'instruction.

---

## EXECUTE

Exécution de l'instruction.

---

# Jeu d'Instructions

## Contrôle CPU

```txt
NOP

HLT
```

---

## Manipulation de Données

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

# Chargement d'une ROM

Le moteur Azure‑8 peut charger une ROM binaire.

Processus :

```txt
Lecture fichier

↓

Copie en mémoire

↓

Initialisation CPU

↓

Exécution
```

---

# Gestion des Erreurs

Le moteur doit être capable de gérer :

```txt
ROM inexistante

ROM vide

Opcode invalide

Adresse mémoire invalide

Pile invalide
```

sans provoquer de comportement imprévisible.

---

# ROMs Officielles

## ROMs Fondamentales

```txt
nop.rom

halt.rom

invalid.rom
```

---

## ROMs d'Instructions

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

# Tests

## Infrastructure

```txt
TestCPU

TestMemory

TestStack

TestFlags
```

---

## Instructions

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

# Performances

Objectifs de conception :

```txt
Simple

Prévisible

Déterministe

Facile à déboguer

Facile à tester
```

La performance maximale n'est pas l'objectif principal du projet.

---

# Limitations Actuelles

Version v0.0.3 :

```txt
Pas de gestion vidéo

Pas de gestion audio

Pas d'interruptions

Pas de DMA

Pas de MMU

Pas de périphériques
```

---

# Versions Futures

Fonctionnalités envisagées :

```txt
Nouvelles instructions

Outils de développement

SDK dédié

IDE dédié

Intégration AzureEngine
```

---

# État de la Version

## CPU

```txt
✅ Stable
```

---

## Mémoire

```txt
✅ Stable
```

---

## Pile

```txt
✅ Stable
```

---

## Jeu d'Instructions

```txt
✅ Stable
```

---

## ROMs

```txt
✅ Stable
```

---

## Tests

```txt
✅ Disponibles
```

---

# Conclusion

Azure‑8 v0.0.3 constitue une machine virtuelle complète et fonctionnelle destinée à l'étude des architectures 8 bits et à la validation de l'écosystème AzureEngine.

Cette version représente :

```txt
La première implémentation stable d'Azure‑8

Le premier module officiel AzureEngine

La base de développement des futurs outils
```

---

**Fin du document**

**Azure-8_Technical_Specification_v0.0.3.md**

**Version : 0.0.3**

**Statut : Officiel**