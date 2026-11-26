# Core Review Report v0.0.4

Projet : Azure-8  
Version : v0.0.4  
Type : Revue Technique du Cœur Azure‑8  
Statut : Draft  
Cycle : Consolidation du Cœur

---

# Résumé Exécutif

Le présent document pilote l'ensemble des travaux de revue technique du cœur Azure‑8 dans le cadre du cycle de consolidation v0.0.4.

Il constitue le document de référence pour :

- la revue du code source ;
- la préparation des refactorisations ;
- l'identification de la dette technique ;
- le renforcement de la qualité ;
- l'amélioration de la maintenabilité ;
- le renforcement de la couverture de tests ;
- la préparation des évolutions futures.

La version v0.0.4 n'introduit aucune nouvelle fonctionnalité.

L'ensemble du cycle est consacré à la stabilisation et à la consolidation de l'existant.

---

# Principe Directeur

## Stabiliser avant d'étendre

La philosophie de la v0.0.4 est la suivante :

> Aucune nouvelle fonctionnalité ne doit être développée tant que le cœur Azure‑8 n'est pas considéré comme consolidé.

Cela implique notamment :

- aucune nouvelle instruction ASM ;
- aucune extension de l'ISA ;
- aucun SDK Azure‑8 ;
- aucun IDE Azure‑8 ;
- aucun système graphique ;
- aucune entrée utilisateur ;
- aucune ROM applicative complexe.

Le cycle v0.0.4 est exclusivement dédié à la qualité interne du moteur.

---

# Objectifs

La revue doit permettre de répondre aux questions suivantes.

## Architecture

- Le découpage actuel est-il maintenable ?
- Les responsabilités sont-elles correctement séparées ?
- Le CPU est-il suffisamment modulaire pour évoluer durablement ?

## Robustesse

- Les protections existantes sont-elles correctement implémentées ?
- Les cas limites sont-ils correctement couverts ?
- Les mécanismes critiques sont-ils testés ?

## Maintenabilité

- La taille des composants est-elle raisonnable ?
- Les responsabilités sont-elles clairement identifiées ?
- La duplication est-elle maîtrisée ?

## Évolutivité

- Le cœur peut-il supporter les versions futures ?
- L'assembleur futur pourra-t-il s'intégrer proprement ?
- Le futur SDK pourra-t-il s'appuyer sur une architecture stable ?
- Le futur IDE pourra-t-il réutiliser les composants existants ?

---

# Périmètre

## Sources

```text
src/
├─ main.cpp
│
├─ Azure8/
│  ├─ CPU.cpp
│  ├─ CPU.h
│  ├─ Memory.cpp
│  ├─ Memory.h
│  ├─ Emulator.cpp
│  ├─ Emulator.h
│  │
│  └─ CPU/
│     ├─ CPUFlags.cpp
│     ├─ CPUFlags.h
│     ├─ CPUInstructions.cpp
│     └─ CPUInstructions.h
│
└─ Core/
    └─ Type.h
```

---

## Tests

```text
tests/

TestCPU.cpp
TestMemory.cpp
TestStack.cpp
TestFlags.cpp

TestInstructionMOV.cpp
TestInstructionLOAD.cpp
TestInstructionSTORE.cpp

TestInstructionPUSH.cpp
TestInstructionPOP.cpp
TestInstructionCALL.cpp
TestInstructionRET.cpp

TestInstructionINC.cpp
TestInstructionDEC.cpp
TestInstructionADD.cpp
TestInstructionSUB.cpp
TestInstructionCMP.cpp

TestInstructionJMP.cpp
TestInstructionJZ.cpp
TestInstructionJNZ.cpp
```

---

# État Global

| Domaine | État |
|----------|----------|
| CPU | 🟡 |
| Mémoire | 🟡 |
| Pile | 🟡 |
| Emulator | 🟡 |
| FLAGS | ✅ |
| Tests | 🟡 |
| Refactorisation | ✅ |
| Optimisation | ⚪ |

### Légende

- ⚪ Non démarré
- 🟡 Analyse préparatoire réalisée
- ✅ Consolidé
- ❌ Action corrective requise

---

# Axe 1 — Revue CPU

## Fichiers

```text
CPU.h
CPU.cpp
```

---

## Objectifs

### Architecture

- [ ] Vérifier les responsabilités
- [ ] Vérifier le découpage actuel
- [ ] Vérifier la cohérence générale

### Lisibilité

- [ ] Vérifier le nommage
- [ ] Vérifier les commentaires
- [ ] Vérifier la taille des fonctions

### Robustesse

- [ ] Vérifier la gestion des FLAGS
- [ ] Vérifier la gestion des erreurs
- [ ] Vérifier les cas limites

### Maintenabilité

- [ ] Identifier les duplications
- [ ] Identifier les simplifications
- [ ] Identifier les zones sensibles

---

## Revue ISA

| Instruction | État |
|------------|----------|
| NOP | ⚪ |
| HLT | ⚪ |
| MOV | ⚪ |
| LOAD | ⚪ |
| STORE | ⚪ |
| PUSH | ⚪ |
| POP | ⚪ |
| CALL | ⚪ |
| RET | ⚪ |
| INC | ⚪ |
| DEC | ⚪ |
| ADD | ⚪ |
| SUB | ⚪ |
| CMP | ⚪ |
| JMP | ⚪ |
| JZ | ⚪ |
| JNZ | ⚪ |

---

## Observations CPU

### Forces

-

### Faiblesses

-

### Risques

-

### Refactorisations Recommandées

-

---

# Axe 2 — Revue Mémoire

## Fichiers

```text
Memory.h
Memory.cpp
```

---

## Objectifs

### Architecture

- [ ] Interface cohérente
- [ ] Responsabilités limitées

### Robustesse

- [ ] Vérifier Read8
- [ ] Vérifier Write8
- [ ] Vérifier Read16
- [ ] Vérifier Write16

### Cas Limites

- [ ] Vérifier l'adresse 0x0000
- [ ] Vérifier l'adresse 0xFFFF
- [ ] Vérifier le wrap-around

### Maintenabilité

- [ ] Identifier les simplifications
- [ ] Identifier les duplications

---

## Observations Mémoire

### Forces

-

### Faiblesses

-

### Risques

-

### Refactorisations Recommandées

-

---

# Axe 3 — Revue Pile

## Objectifs

Valider complètement le comportement du système de pile.

---

## Fonctions

- [ ] Push8
- [ ] Pop8
- [ ] Push16
- [ ] Pop16
- [ ] CALL
- [ ] RET

---

## Protections

- [ ] Stack Overflow
- [ ] Stack Underflow

---

## Couverture

- [ ] Cas normaux
- [ ] Cas limites
- [ ] Gestion des erreurs

---

## Observations

### Forces

-

### Faiblesses

-

### Risques

-

---

# Axe 4 — Revue Emulator

## Fichiers

```text
Emulator.h
Emulator.cpp
```

---

## Objectifs

### Chargement ROM

- [ ] Vérifier les contrôles
- [ ] Vérifier les limites mémoire
- [ ] Vérifier les erreurs

### Exécution

- [ ] Vérifier Run()
- [ ] Vérifier MAX_CYCLES
- [ ] Vérifier les arrêts contrôlés

### Robustesse

- [ ] Vérifier les protections
- [ ] Vérifier les dépendances

---

## Observations Emulator

### Forces

-

### Faiblesses

-

### Risques

-

### Refactorisations Recommandées

-

---

# Axe 5 — Revue des Types Fondamentaux

## Fichier

```text
Type.h
```

---

## Vérifications

- [ ] Cohérence des types
- [ ] Compatibilité
- [ ] Utilisation homogène
- [ ] Documentation suffisante
- [ ] Absence de types inutiles

---

## Observations

### Forces

-

### Faiblesses

-

### Risques

-

---

# Axe 6 — Revue des FLAGS

## État Actuel

| Flag | État |
|----------|----------|
| ZERO | ✅ |
| NEGATIVE | ✅ |
| CARRY | ✅ |
| OVERFLOW | ✅ |

---

## Validation Requise

### ZERO

- ADD ✅
- SUB ✅
- INC ✅
- DEC ✅
- CMP ✅

### NEGATIVE

- ADD ✅
- SUB ✅
- INC ✅
- DEC ✅
- CMP ✅

### CARRY

- ADD ✅
- SUB ✅
- CMP ✅

### OVERFLOW

- ADD ✅
- SUB ✅
- INC ✅
- DEC ✅

---

## Risque Principal

La validation des FLAGS est terminée.

Le risque principal se situe désormais dans :
- la modularisation du CPU ;
- les tests de robustesse ;
- les protections mémoire et pile.

---

# Axe 7 — Modularisation du CPU

## Contexte

Le fichier :

```text
CPU.cpp
```

centralise actuellement plusieurs responsabilités.

Cette structure est adaptée au démarrage du projet mais deviendra progressivement plus difficile à maintenir.

La v0.0.4 a pour objectif de préparer une architecture CPU plus modulaire sans modifier le comportement du processeur.

---

## Principe de Modularisation

CPU.cpp et CPU.h restent les points d'entrée publics du processeur.

Les composants spécialisés sont déplacés vers :

```text
src/Azure8/CPU/
```

afin d'améliorer la maintenabilité sans complexifier l'architecture globale du projet.

---

## Architecture Actuelle

```text
src/Azure8/

CPU.cpp
CPU.h
```

---

## Architecture réalisée

```text
src/Azure8/

CPU.cpp
CPU.h

CPU/
├─ CPUFlags.cpp
├─ CPUFlags.h
├─ CPUInstructions.cpp
└─ CPUInstructions.h
```

---

## Répartition des Responsabilités

### CPU.cpp

Responsabilités :

- point d'entrée CPU ;
- cycle CPU ;
- orchestration ;
- exécution générale.

---

### CPUFlags.cpp

Responsabilités :

- ZERO ;
- NEGATIVE ;
- CARRY ;
- OVERFLOW ;
- fonctions utilitaires associées.

---

### CPUInstructions.cpp

Responsabilités :

- implémentation des instructions ;
- regroupement logique de l'ISA ;
- exécution des opérations.

---

## Validation

✅ Structure implémentée
✅ CPUFlags extrait
✅ CPUInstructions extrait
✅ Compatibilité préservée
✅ Tests validés

---

# Axe 8 — Réduction du Switch d'Opcode

## Contexte

L'exécution des instructions repose actuellement sur un mécanisme centralisé basé sur les opcodes.

À mesure que l'ISA grandira, ce mécanisme deviendra plus difficile à maintenir.

---

## Objectif

Préparer une architecture plus modulaire sans modifier le comportement du processeur.

---

## Architecture Intermédiaire

Extraction de la logique des instructions dans des fonctions spécialisées :

```cpp
ExecuteMOV();
ExecuteLOAD();
ExecuteSTORE();

ExecuteINC();
ExecuteDEC();
ExecuteADD();
ExecuteSUB();
ExecuteCMP();

ExecuteJMP();
ExecuteJZ();
ExecuteJNZ();

ExecutePUSH();
ExecutePOP();

ExecuteCALL();
ExecuteRET();
```

Le switch est conservé mais devient progressivement plus léger.

---

## Architecture Future

Hors périmètre v0.0.4 :

```cpp
InstructionDispatcher
```

ou

```cpp
InstructionTable
```

---

## Validation

✅ Instructions extraites
✅ Handlers créés
✅ Switch allégé
✅ Compatibilité validée

---

# Axe 9 — Revue des Tests

## Couverture Existante

| Domaine | État |
|----------|----------|
| CPU | ☒ |
| Mémoire | ☒ |
| Pile | ☒ |
| FLAGS | ☒ |
| ISA | ☒ |

---

## Tests de Consolidation Manquants

| Test | Statut |
|----------|----------|
| TestStackOverflow.cpp | 🔴 |
| TestStackUnderflow.cpp | 🔴 |
| TestMaxCycles.cpp | 🔴 |
| TestLargeROM.cpp | 🔴 |
| TestMemoryBoundary.cpp | 🔴 |

---

## Validation des FLAGS

- [ ] ZERO
- [ ] NEGATIVE
- [ ] CARRY
- [ ] OVERFLOW

---

# Plan de Consolidation

| Phase | Objectif | État |
|---------|-----------|---------|
| 1 | Analyse du cœur | 🟡 |
| 2 | Cartographie des risques | ⚪ |
| 3 | Modularisation CPU | ✅ |
| 4 | Réduction du switch | ⚪ |
| 5 | Renforcement des tests | ⚪ |
| 6 | Validation finale | ⚪ |

---

# Critères de Sortie

La revue est terminée lorsque :

- [ ] CPU analysé
- [ ] Mémoire analysée
- [ ] Pile analysée
- [ ] Emulator analysé
- [ ] Duplications identifiées
- [ ] Simplifications identifiées
- [ ] Plan de modularisation validé
- [ ] Plan de réduction du switch validé
- [ ] Lacunes de tests identifiées
- [ ] Priorités de consolidation définies

---

# Évaluation Finale

| Domaine | État |
|----------|----------|
| CPU | ⚪ |
| Mémoire | ⚪ |
| Pile | ⚪ |
| Emulator | ⚪ |
| FLAGS | ✅ |
| Tests | ⚪ |
| Maintenabilité | ⚪ |
| Robustesse | ⚪ |

---

# Décision

- [ ] Non commencé
- [x] Préparation terminée
- [ ] Analyse en cours
- [ ] Analyse terminée
- [ ] Consolidation validée

---

# Journal de Suivi

## Session 1

### Actions réalisées

- Création du rapport.
- Définition du périmètre.
- Définition des axes de consolidation.
- Identification des lacunes de tests.
- Ajout du chantier de modularisation CPU.
- Ajout du chantier de réduction du switch d'opcodes.

### Observations

- La couverture fonctionnelle actuelle est déjà importante.
- La validation complète des FLAGS a été réalisée.
- ADD, SUB, INC et DEC disposent d'une couverture explicite du comportement ZERO, NEGATIVE, CARRY et/ou OVERFLOW selon les besoins de l'instruction.
- CMP est documenté et OVERFLOW est déclaré non applicable à l'implémentation actuelle.
- Le risque principal se déplace progressivement vers les tests de robustesse.
- CPU.cpp devra être découpé pour améliorer sa maintenabilité.

### Décisions

- Consolider les FLAGS avant toute évolution fonctionnelle.
- Ajouter les tests de robustesse manquants.
- Préparer la structure :
  - CPU.cpp ;
  - CPUFlags.cpp ;
  - CPUInstructions.cpp.
- Préparer la réduction progressive du switch monolithique.

---

**Fin du document**  
**Core_Review_Report_v0.0.4.md**  
**Version : v0.0.4**  
**Statut : Draft**