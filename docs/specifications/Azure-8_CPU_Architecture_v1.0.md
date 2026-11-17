# Azure-8 CPU Architecture v1.0

> Projet : **Azure-8**
>
> Document : **Architecture CPU**
>
> Version : **1.0**
>
> Statut : **Officiel**
>
> Architecture : **8 bits**
>
> Module : **Azure-8**

---

# Introduction

Ce document décrit l'architecture interne du processeur Azure‑8.

L'objectif du CPU Azure‑8 est de fournir une architecture simple, cohérente et documentée permettant :

```txt
L'apprentissage du bas niveau

L'expérimentation

La validation de concepts CPU

L'exécution de ROMs Azure‑8
```

Azure‑8 ne reproduit aucun processeur réel existant.

Il s'agit d'une architecture propriétaire conçue spécifiquement pour le projet.

---

# Vue Générale

Le processeur Azure‑8 est un CPU :

```txt
8 bits

Little Endian

Adressage mémoire 16 bits

Architecture à registres
```

---

# Caractéristiques

## Taille des données

```txt
8 bits
```

---

## Taille des adresses

```txt
16 bits
```

---

## Taille mémoire adressable

```txt
65536 octets

64 Ko
```

---

## Endianness

```txt
Little Endian
```

Exemple :

```txt
Valeur 0x1234

Mémoire :

34 12
```

---

# Registres

Le processeur dispose de sept registres.

---

## Registres Utilisateur

### A

```txt
Registre général
```

---

### B

```txt
Registre général
```

---

### C

```txt
Registre général
```

---

### D

```txt
Registre général
```

---

## Registres Système

### PC

Program Counter.

Type :

```txt
16 bits
```

Rôle :

```txt
Adresse de la prochaine instruction.
```

---

### SP

Stack Pointer.

Type :

```txt
16 bits
```

Rôle :

```txt
Sommet de la pile.
```

---

### FLAGS

Registre d'état.

Type :

```txt
8 bits
```

Rôle :

```txt
Conserver les indicateurs du processeur.
```

---

# Registre FLAGS

Les indicateurs actuellement définis sont :

---

## ZERO

```txt
Z
```

Positionné lorsque le résultat d'une opération vaut :

```txt
0
```

---

## CARRY

```txt
C
```

Positionné lorsqu'une opération génère une retenue.

---

## NEGATIVE

```txt
N
```

Positionné lorsqu'un résultat est négatif.

---

## OVERFLOW

```txt
V
```

Positionné lorsqu'un dépassement signé est détecté.

---

# Mémoire

Le CPU possède un espace mémoire unique.

---

## Adresse minimale

```txt
0x0000
```

---

## Adresse maximale

```txt
0xFFFF
```

---

## Taille totale

```txt
64 Ko
```

---

# Organisation de la Mémoire

Architecture actuelle :

```txt
0000h ────────────── FFFFh
│
└── RAM Azure‑8
```

La mémoire est entièrement adressable.

---

# Gestion de Pile

Le processeur utilise une pile logicielle.

---

## Registre utilisé

```txt
SP
```

---

## Opérations supportées

```txt
Push8()

Pop8()

Push16()

Pop16()
```

---

## Utilisation

La pile est utilisée par :

```txt
PUSH

POP

CALL

RET
```

---

# Cycle CPU

Le processeur fonctionne selon le cycle classique :

```txt
FETCH

↓

DECODE

↓

EXECUTE
```

---

## FETCH

Lecture de l'instruction située à l'adresse :

```txt
PC
```

---

## DECODE

Identification de l'opcode.

---

## EXECUTE

Exécution de l'instruction correspondante.

---

## Mise à jour

Le processeur ajuste :

```txt
PC

FLAGS

SP
```

si nécessaire.

---

# Jeu d'Instructions

Version :

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

# Interactions CPU

Le CPU interagit uniquement avec :

```txt
Mémoire

Pile

Registres

ROM exécutée
```

Le processeur ne possède actuellement :

```txt
Aucun système vidéo

Aucun système audio

Aucun périphérique
```

---

# Gestion des Erreurs

Le processeur doit être capable de gérer :

```txt
Opcode invalide

ROM invalide

Adresse incorrecte

Pile invalide
```

sans provoquer de comportement imprévisible.

---

# Limitations Actuelles

Version v0.0.3 :

```txt
Pas d'interruptions

Pas de DMA

Pas de MMU

Pas de gestion périphériques

Pas de mode privilégié
```

Ces fonctionnalités pourront être étudiées dans des versions futures.

---

# Objectifs de Conception

Le CPU Azure‑8 doit rester :

```txt
Simple

Lisible

Prévisible

Documenté

Facile à tester
```

afin de servir de plateforme pédagogique et technique.

---

# Conclusion

Le processeur Azure‑8 constitue le cœur de la machine virtuelle Azure‑8.

Son architecture volontairement simple permet :

```txt
L'apprentissage

L'expérimentation

Le développement bas niveau

La validation des outils Azure‑8
```

tout en servant de base technique pour l'évolution future du projet.

---

**Fin du document**

**Azure-8_CPU_Architecture_v1.0.md**

**Version : 1.0**

**Statut : Officiel**