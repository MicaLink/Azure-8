# Azure-8 Roadmap v0.0.4

Projet : Azure-8  
Version : v0.0.4  
Statut : En cours  
Type : Version de Consolidation  
Version Précédente : v0.0.3

---

# Vision

La version v0.0.4 constitue un cycle complet de consolidation du cœur Azure‑8.

Contrairement aux versions futures, cette version ne vise aucun ajout fonctionnel.

L'ensemble des efforts est consacré à :

- la réduction de la dette technique ;
- la validation du comportement du CPU ;
- le renforcement de la couverture de tests ;
- la modularisation de l'architecture interne ;
- l'amélioration de la maintenabilité ;
- l'organisation documentaire ;
- la préparation des évolutions futures.

---

# Objectif Principal

Finaliser le cœur Azure‑8 avant tout développement :

- d'un assembleur ;
- d'un SDK ;
- d'un IDE ;
- de ROMs applicatives avancées.

Le cœur doit devenir :

- fiable ;
- testable ;
- maintenable ;
- documenté ;
- extensible.

---

# État du Projet

## Documentation

✅ Réorganisée

✅ Documentation active séparée des archives

✅ Rapports v0.0.3 archivés

✅ Releases v0.0.3 archivées

---

## Analyse Technique

✅ Première revue du CPU réalisée

✅ Dette technique identifiée

✅ Plan de modularisation rédigé

✅ Checklist de refactorisation créée

✅ Cartographie des FLAGS produite

✅ Matrice des tests produite

---

## Constats Techniques

### Points Positifs

✅ CPU fonctionnel

✅ ISA complète de la v0.0.3 implémentée

✅ Gestion de pile présente

✅ Gestion des FLAGS présente

✅ Couverture fonctionnelle de base existante

### Points d'Attention

⚠ CPU.cpp monolithique

⚠ Switch d'opcodes centralisé

⚠ FLAGS insuffisamment validés par les tests

⚠ OVERFLOW insuffisamment démontré

⚠ Tests de robustesse manquants

---

# Principe Directeur

## Stabiliser avant d'étendre

Aucune nouvelle fonctionnalité ne sera développée durant le cycle v0.0.4.

La priorité absolue est :

> Renforcer la confiance dans le cœur existant.

---

## Autorisé

✅ Réorganisation documentaire

✅ Refactorisation

✅ Renforcement des tests

✅ Réduction de dette technique

✅ Modularisation CPU

✅ Amélioration de la maintenabilité

✅ Validation fonctionnelle

✅ Optimisation non fonctionnelle

---

## Interdit

❌ Nouvelle instruction ASM

❌ Extension ISA

❌ SDK Azure‑8

❌ IDE Azure‑8

❌ Assembleur Azure‑8

❌ Système graphique

❌ Entrées utilisateur

❌ Audio

❌ Snake

❌ Pong

❌ ROMs applicatives avancées

---

# Priorité Stratégique

L'analyse réelle du CPU et des tests a permis d'identifier une priorité plus importante que la modularisation :

## Validation des FLAGS

Le code implémente déjà :

```text
ZERO
NEGATIVE
CARRY
OVERFLOW
```

mais plusieurs comportements critiques ne sont actuellement pas démontrés par les tests.

Avant toute refactorisation du CPU, les scénarios critiques doivent être validés afin de disposer d'un filet de sécurité contre les régressions.

---

# Travaux Planifiés

---

# T1 — Clôture des Audits

## Objectif

Finaliser l'ensemble des remarques issues de la v0.0.3.

### Statut

🟡 En cours

### Priorité

P1

---

# T2 — Nettoyage Documentaire

## Objectif

Harmoniser la documentation existante.

### Statut

🟡 En cours

### Priorité

P1

---

# T2.1 — Réorganisation Documentaire

## Objectif

Séparer les documents actifs des archives.

### Résultat Attendu

```text
docs/archive/
```

contient exclusivement :

- releases historiques ;
- rapports historiques ;
- roadmaps historiques.

### Statut

✅ Réalisé

### Priorité

P1

---

# T3 — Validation Fonctionnelle des FLAGS

## Objectif

Valider explicitement les comportements des FLAGS au travers des instructions CPU.

### Contexte

Les tests actuels démontrent principalement :

- le fonctionnement des instructions ;
- le fonctionnement de l'API des FLAGS.

Ils ne démontrent pas suffisamment :

- ZERO ;
- NEGATIVE ;
- CARRY ;
- OVERFLOW.

---

## T3.1 — Validation ADD

Ajouter :

```text
TestADD_Zero
TestADD_Carry
TestADD_Negative
TestADD_Overflow
```

### Priorité

P1

### Statut

⚪ À réaliser

---

## T3.2 — Validation SUB

Ajouter :

```text
TestSUB_Zero
TestSUB_Carry
TestSUB_Negative
TestSUB_Overflow
```

### Priorité

P1

### Statut

⚪ À réaliser

---

## T3.3 — Validation INC

Ajouter :

```text
TestINC_Zero
TestINC_Negative
TestINC_Overflow
```

### Priorité

P1

### Statut

⚪ À réaliser

---

## T3.4 — Validation DEC

Ajouter :

```text
TestDEC_Zero
TestDEC_Negative
TestDEC_Overflow
```

### Priorité

P1

### Statut

⚪ À réaliser

---

## T3.5 — Vérification CMP

Vérifier la cohérence entre :

- implémentation ;
- documentation ISA ;
- comportement attendu concernant OVERFLOW.

### Priorité

P1

### Statut

⚪ À réaliser

---

# T4 — Consolidation du Cœur

## Objectif

Réduire la dette technique du moteur.

### Priorité

P1

### Statut

⚪ À réaliser

---

## T4.1 — Refactorisation Contrôlée

### Objectif

Améliorer la maintenabilité sans modifier le comportement.

### Critère

Aucune modification fonctionnelle.

---

## T4.2 — Modularisation du CPU

### Objectif

Isoler les responsabilités du processeur.

### Structure Cible

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

### Priorité

P1

### Statut

⚪ À réaliser

---

## T4.3 — Réduction du Switch d'Opcode

### Objectif

Réduire la complexité du switch principal.

### Architecture Cible

```cpp
ExecuteMOV();
ExecuteLOAD();
ExecuteSTORE();

ExecuteADD();
ExecuteSUB();

ExecutePUSH();
ExecutePOP();

ExecuteCALL();
ExecuteRET();
```

### Priorité

P1

### Statut

⚪ À réaliser

---

# T5 — Tests de Robustesse

## T5.1 — Stack Overflow

Livrable :

```text
TestStackOverflow.cpp
```

### Statut

⚪ À réaliser

---

## T5.2 — Stack Underflow

Livrable :

```text
TestStackUnderflow.cpp
```

### Statut

⚪ À réaliser

---

## T5.3 — MAX_CYCLES

Livrable :

```text
TestMaxCycles.cpp
```

### Statut

⚪ À réaliser

---

## T5.4 — ROM Surdimensionnée

Livrable :

```text
TestLargeROM.cpp
```

### Statut

⚪ À réaliser

---

## T5.5 — Frontières Mémoire

Livrable :

```text
TestMemoryBoundary.cpp
```

### Statut

⚪ À réaliser

---

# Livrables

## Rapports

```text
Core_Consolidation_Report_v0.0.4.md

Core_Review_Report_v0.0.4.md

CPU_Modularization_Plan_v0.0.4.md

CPU_Refactoring_Checklist_v0.0.4.md

Flag_Coverage_Report_v0.0.4.md

Technical_Debt_Report_v0.0.4.md

Test_Matrix_v0.0.4.md
```

---

## Nouveaux Tests Attendus

```text
TestADD_Zero
TestADD_Carry
TestADD_Negative
TestADD_Overflow

TestSUB_Zero
TestSUB_Carry
TestSUB_Negative
TestSUB_Overflow

TestINC_Zero
TestINC_Negative
TestINC_Overflow

TestDEC_Zero
TestDEC_Negative
TestDEC_Overflow

TestStackOverflow.cpp

TestStackUnderflow.cpp

TestMaxCycles.cpp

TestLargeROM.cpp

TestMemoryBoundary.cpp
```

---

# Ordre Recommandé d'Exécution

## Phase 1

Validation des FLAGS

1. ADD
2. SUB
3. INC
4. DEC
5. CMP

---

## Phase 2

Modularisation CPU

1. Création du dossier CPU
2. Extraction CPUFlags
3. Extraction CPUInstructions
4. Réduction du switch

---

## Phase 3

Tests de robustesse

1. Stack Overflow
2. Stack Underflow
3. MAX_CYCLES
4. ROM surdimensionnée
5. Frontières mémoire

---

# Critères de Sortie

La v0.0.4 sera considérée comme terminée lorsque :

✅ Documentation harmonisée

✅ Documentation réorganisée

✅ CPU consolidé

✅ Mémoire consolidée

✅ Pile consolidée

✅ FLAGS validés

✅ OVERFLOW démontré

✅ CPU modularisé

✅ Switch simplifié

✅ Tests de robustesse présents

✅ Aucun point critique ouvert

✅ Aucune régression observée

---

# Décision

État actuel :

☐ Non commencé

☒ Analyse terminée

☒ Préparation terminée

☒ Réorganisation documentaire terminée

☐ Validation FLAGS en cours

☐ Modularisation CPU en cours

☐ Consolidation validée

---

# Préparation de la Suite

La version suivante ne pourra commencer qu'après :

- validation complète des FLAGS ;
- modularisation du CPU ;
- validation des protections critiques ;
- clôture de la dette technique principale.

Les sujets suivants restent hors périmètre jusqu'à la fin de la v0.0.4 :

- Assembleur Azure‑8
- SDK Azure‑8
- IDE Azure‑8
- ROMs applicatives avancées
- Snake
- Pong

---

**Fin du document**  
**Azure-8_Roadmap_v0.0.4.md**  
**Version : v0.0.4**  
**Statut : En cours**