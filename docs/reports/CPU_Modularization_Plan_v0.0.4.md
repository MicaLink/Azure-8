# CPU Modularization Plan v0.0.4

Projet : Azure-8  
Version : v0.0.4  
Type : Plan de Modularisation du CPU  
Statut : Draft  
Cycle : Consolidation du Cœur

---

# Objectif

Le présent document définit la stratégie de modularisation du composant CPU dans le cadre du cycle de consolidation v0.0.4.

L'objectif n'est pas d'ajouter de nouvelles fonctionnalités.

L'objectif est de :

- améliorer la lisibilité ;
- améliorer la maintenabilité ;
- préparer les futures évolutions ;
- réduire la taille de CPU.cpp ;
- mieux séparer les responsabilités ;
- faciliter les futurs travaux sur l'assembleur, le SDK et l'IDE.

---

# Principe Directeur

## Stabiliser avant d'étendre

La modularisation doit respecter une règle absolue :

> Aucune modification fonctionnelle n'est autorisée.

Le comportement du CPU doit rester strictement identique avant et après la modularisation.

Les opérations réalisées devront être uniquement :

- structurelles ;
- organisationnelles ;
- architecturales.

---

# État Actuel

## Structure

```text
src/Azure8/

CPU.cpp
CPU.h

Memory.cpp
Memory.h

Emulator.cpp
Emulator.h
```

---

## Constats

### Positifs

✅ Structure simple

✅ Facile à comprendre

✅ Peu de fichiers

---

### Limites

⚠ CPU.cpp centralise plusieurs responsabilités.

⚠ Gestion des FLAGS mélangée à l'exécution des instructions.

⚠ Logique des instructions regroupée dans un seul fichier.

⚠ Le switch d'opcodes risque de croître continuellement.

⚠ La maintenance deviendra plus difficile avec l'évolution du projet.

---

# Structure Cible

## Organisation Générale

```text
src/
├─ Azure8/
│
├─ CPU.cpp
├─ CPU.h
│
├─ Memory.cpp
├─ Memory.h
│
├─ Emulator.cpp
├─ Emulator.h
│
└─ CPU/
   ├─ CPUFlags.cpp
   ├─ CPUFlags.h
   ├─ CPUInstructions.cpp
   └─ CPUInstructions.h

src/Core/
└─ Type.h
```

---

# Architecture Cible

## CPU.cpp

### Rôle

Le composant CPU principal reste le point d'entrée public du processeur.

### Responsabilités

- cycle CPU ;
- orchestration ;
- coordination ;
- appel des composants spécialisés.

### Responsabilités Exclues

- calcul détaillé des FLAGS ;
- implémentation complète des instructions.

---

## CPUFlags

### Fichiers

```text
CPUFlags.cpp
CPUFlags.h
```

### Responsabilités

- flag ZERO ;
- flag NEGATIVE ;
- flag CARRY ;
- flag OVERFLOW ;
- helpers associés.

### Avantages

- logique des FLAGS centralisée ;
- meilleure testabilité ;
- meilleure lisibilité.

---

## CPUInstructions

### Fichiers

```text
CPUInstructions.cpp
CPUInstructions.h
```

### Responsabilités

- MOV ;
- LOAD ;
- STORE ;
- PUSH ;
- POP ;
- CALL ;
- RET ;
- INC ;
- DEC ;
- ADD ;
- SUB ;
- CMP ;
- JMP ;
- JZ ;
- JNZ ;
- NOP ;
- HLT.

### Avantages

- ISA regroupée ;
- maintenance simplifiée ;
- préparation des évolutions futures.

---

# Réduction du Switch d'Opcode

## État Actuel

Architecture supposée :

```cpp
switch(opcode)
{
    ...
}
```

Cette architecture est acceptable pour un nombre réduit d'instructions.

---

## Objectif v0.0.4

Conserver le switch tout en extrayant progressivement la logique métier.

---

## Architecture Intermédiaire

```cpp
switch(opcode)
{
    case MOV:
        ExecuteMOV();
        break;

    case LOAD:
        ExecuteLOAD();
        break;

    case STORE:
        ExecuteSTORE();
        break;
}
```

Le switch reste présent mais ne contient plus l'implémentation détaillée.

---

## Architecture Future

Hors périmètre v0.0.4.

Possibilités :

```cpp
InstructionDispatcher
```

ou

```cpp
InstructionTable
```

Ces évolutions seront étudiées dans des versions ultérieures.

---

# Plan de Migration

## Phase 1 — Analyse

Objectif :

Documenter l'existant.

### Travaux

- inventaire des responsabilités ;
- inventaire des dépendances ;
- cartographie CPU → FLAGS ;
- cartographie CPU → Instructions.

### Critères

- [ ] Inventaire terminé
- [ ] Dépendances identifiées

---

## Phase 2 — Création de la Structure

Objectif :

Préparer l'arborescence cible.

### Travaux

Création du dossier :

```text
src/Azure8/CPU/
```

Création des fichiers :

```text
CPUFlags.cpp
CPUFlags.h

CPUInstructions.cpp
CPUInstructions.h
```

### Critères

- [ ] Structure créée
- [ ] Compilation maintenue

---

## Phase 3 — Extraction des FLAGS

Objectif :

Isoler complètement la logique des FLAGS.

### Travaux

Migration :

- ZERO ;
- NEGATIVE ;
- CARRY ;
- OVERFLOW.

### Critères

- [ ] CPU compile
- [ ] Comportement identique
- [ ] Tests existants valides

---

## Phase 4 — Extraction des Instructions

Objectif :

Déplacer progressivement l'ISA.

### Travaux

Migration :

- MOV ;
- LOAD ;
- STORE ;
- PUSH ;
- POP ;
- CALL ;
- RET ;
- INC ;
- DEC ;
- ADD ;
- SUB ;
- CMP ;
- JMP ;
- JZ ;
- JNZ ;
- NOP ;
- HLT.

### Critères

- [ ] Compilation réussie
- [ ] ISA inchangée
- [ ] Tests valides

---

## Phase 5 — Allègement du Switch

Objectif :

Réduire la complexité du switch principal.

### Travaux

Remplacement progressif des blocs logiques par :

```cpp
ExecuteMOV();
ExecuteLOAD();
ExecuteSTORE();
```

### Critères

- [ ] Switch simplifié
- [ ] Lisibilité améliorée
- [ ] Comportement inchangé

---

## Phase 6 — Validation Finale

Objectif :

Valider la modularisation complète.

### Vérifications

- [ ] Build Debug
- [ ] Build Release
- [ ] Harnais de tests
- [ ] Documentation cohérente
- [ ] Aucun comportement modifié

---

# Risques

## R1 — Régression Fonctionnelle

Impact :

Élevé

Mesure :

- aucune modification fonctionnelle ;
- validation continue des tests.

---

## R2 — Dépendances Cachées

Impact :

Moyen

Mesure :

- cartographie préalable ;
- migration progressive.

---

## R3 — Fragmentation Excessive

Impact :

Moyen

Mesure :

- limiter le découpage aux responsabilités clairement identifiées.

---

# Critères de Validation

La modularisation sera considérée comme terminée lorsque :

✅ CPU.cpp est allégé

✅ Le dossier :

```text
src/Azure8/CPU/
```

est en place

✅ CPUFlags est isolé

✅ CPUInstructions est isolé

✅ Les responsabilités sont correctement séparées

✅ Tous les tests existants restent valides

✅ Aucune régression n'est observée

✅ Aucun comportement CPU n'est modifié

---

# Checklist de Clôture

## Structure

- [ ] Dossier CPU créé
- [ ] CPUFlags créé
- [ ] CPUInstructions créé

---

## Migration

- [ ] FLAGS migrés
- [ ] Instructions migrées
- [ ] Switch allégé

---

## Validation

- [ ] Build Debug valide
- [ ] Build Release valide
- [ ] Tests valides
- [ ] Documentation mise à jour

---

# Décision

Résultat :

☐ Non commencé

☒ Plan rédigé

☐ Analyse terminée

☐ Migration en cours

☐ Migration terminée

☐ Modularisation validée

---

**Fin du document**  
**CPU_Modularization_Plan_v0.0.4.md**  
**Version : v0.0.4**  
**Statut : Draft**