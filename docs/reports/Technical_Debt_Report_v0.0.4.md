# Technical Debt Report v0.0.4

Projet : Azure-8  
Version : v0.0.4  
Type : Rapport de Dette Technique  
Statut : Validation Finale
Cycle : Consolidation du Cœur

---

# Résumé Exécutif

Le présent document recense les dettes techniques identifiées lors de la clôture de la v0.0.3 et durant la préparation du cycle v0.0.4.

Le but de ce rapport est de :

- identifier les risques techniques ;
- prioriser les travaux de consolidation ;
- réduire la dette de maintenance ;
- renforcer la qualité du code ;
- renforcer la couverture de tests ;
- améliorer l'organisation documentaire ;
- préparer les futures évolutions du projet.

La dette technique actuelle est principalement concentrée sur :

- l'architecture interne du CPU ;
- la couverture des FLAGS ;
- la couverture des mécanismes de protection ;
- la maintenabilité du code ;
- certaines portions de l'organisation documentaire.

---

# État Global de la Dette

| Domaine | Niveau |
|----------|----------|
| CPU | 🟡 |
| Architecture interne | 🟡 |
| Couverture FLAGS | 🟢 |
| Tests de robustesse | 🟢 |
| Maintenabilité | 🟡 |
| Documentation | 🟡 |
| Organisation documentaire | 🟢 |
| Mémoire | 🟡 |

### Légende

- 🔴 Dette élevée
- 🟡 Dette modérée
- 🟢 Dette faible ou traitée

---

# Politique de Priorisation

## P1 — Critique

Doit être traité durant le cycle v0.0.4.

Impact direct sur :

- stabilité ;
- qualité ;
- maintenabilité ;
- évolutivité.

---

## P2 — Important

Doit être traité prochainement.

Impact indirect mais significatif.

---

## P3 — Amélioration

Peut être traité ultérieurement.

---

# Dette d'Architecture

---

## TD-ARCH-001

### Titre

CPU monolithique

### Priorité

P1

### Niveau de risque

Élevé

### Description

Le fichier :

```text
src/Azure8/CPU.cpp
```

porte actuellement plusieurs responsabilités :

- exécution CPU ;
- décodage des opcodes ;
- gestion des FLAGS ;
- implémentation des instructions.

### Impact

- difficulté de maintenance ;
- coût croissant des modifications ;
- risque de régression élevé.

### Action corrective

Mettre en œuvre le plan :

```text
CPU_Modularization_Plan_v0.0.4.md
```

### Statut

🟡 En réduction

---

## TD-ARCH-002

### Titre

Gestion des FLAGS non isolée

### Priorité

P1

### Niveau de risque

Élevé

### Description

La logique des FLAGS est couplée à la logique générale du CPU.

### Impact

- faible réutilisabilité ;
- difficulté de validation ;
- difficulté de maintenance.

### Action corrective

Créer :

```text
src/Azure8/CPU/

CPUFlags.cpp
CPUFlags.h
```

### Statut

✅ Résolu

---

## TD-ARCH-003

### Titre

Implémentation des instructions non isolée

### Priorité

P1

### Niveau de risque

Moyen

### Description

Les instructions de l'ISA sont fortement couplées au cœur CPU.

### Action corrective

Créer :

```text
src/Azure8/CPU/

CPUInstructions.cpp
CPUInstructions.h
```

### Statut

✅ Résolu

---

## TD-ARCH-004

### Titre

Switch d'opcodes centralisé

### Priorité

P1

### Niveau de risque

Élevé

### Description

Le switch principal d'exécution concentre progressivement toute la logique des instructions.

### Impact

- baisse de lisibilité ;
- coût croissant de maintenance ;
- difficulté de revue.

### Action corrective

Extraction progressive des comportements dans :

```cpp
ExecuteADD();
ExecuteMOV();
ExecuteCALL();
```

### Statut

✅ Résolu

---

# Dette de Tests

---

## TD-TEST-001

### Titre

Validation OVERFLOW incomplète

### Priorité

P1

### Niveau de risque

Modéré

### Description

La couverture du flag OVERFLOW n'est pas démontrée de manière explicite pour l'ensemble des instructions concernées.

### Instructions concernées

ADD : ✅ Validé
SUB : ✅ Validé
INC : ✅ Validé
DEC : ✅ Validé

### Action corrective

Ajout de scénarios dédiés.

### Référence

```text
Flag_Coverage_Report_v0.0.4.md
```

### Statut

✅ Résolu

---

## TD-TEST-002

### Titre

Absence de test Stack Overflow

### Priorité

P1

### Niveau de risque

Élevé

### Action corrective

Créer :

```text
TestStackOverflow.cpp
```

### Statut

✅ Résolu

---

## TD-TEST-003

### Titre

Absence de test Stack Underflow

### Priorité

P1

### Niveau de risque

Élevé

### Action corrective

Créer :

```text
TestStackUnderflow.cpp
```

### Statut

✅ Résolu

---

## TD-TEST-004

### Titre

Absence de test MAX_CYCLES

### Priorité

P1

### Niveau de risque

Élevé

### Action corrective

Créer :

```text
TestMaxCycles.cpp
```

### Statut

✅ Résolu

---

## TD-TEST-005

### Titre

Absence de test ROM surdimensionnée

### Priorité

P1

### Niveau de risque

Élevé

### Action corrective

Créer :

```text
TestLargeROM.cpp
```

### Statut

✅ Résolu

---

## TD-TEST-006

### Titre

Couverture incomplète des frontières mémoire

### Priorité

P1

### Niveau de risque

Moyen

### Action corrective

Créer :

```text
TestMemoryBoundary.cpp
```

### Statut

✅ Résolu

---

## TD-TEST-007

### Titre

Cartographie des FLAGS historiquement absente

### Priorité

P1

### Niveau de risque

Moyen

### Action corrective

Produire :

```text
Flag_Coverage_Report_v0.0.4.md
```

### Statut

✅ Traité

---

## TD-TEST-008

### Titre

Cartographie globale des tests historiquement absente

### Priorité

P1

### Niveau de risque

Moyen

### Action corrective

Produire :

```text
Test_Matrix_v0.0.4.md
```

### Statut

✅ Traité

---

# Dette de Maintenabilité

---

## TD-MAINT-001

### Titre

Absence de modularisation du CPU

### Priorité

P1

### Niveau de risque

Élevé

### Description

Le processeur n'est pas encore découpé en composants spécialisés.

### Action corrective

Création de :

```text
src/Azure8/CPU/
```

### Statut

✅ Résolu

---

## TD-MAINT-002

### Titre

Couplage excessif des responsabilités CPU

### Priorité

P1

### Niveau de risque

Élevé

### Description

Les FLAGS, les instructions et l'exécution CPU sont fortement couplés.

### Action corrective

Séparer :

```text
CPUFlags

CPUInstructions
```

### Statut

✅ Résolu

---

## TD-MAINT-003

### Titre

Plan de modularisation absent

### Priorité

P1

### Niveau de risque

Moyen

### Action corrective

Créer :

```text
CPU_Modularization_Plan_v0.0.4.md
```

### Statut

✅ Traité

---

## TD-MAINT-004

### Titre

Suivi détaillé de la refactorisation absent

### Priorité

P1

### Niveau de risque

Faible

### Action corrective

Créer :

```text
CPU_Refactoring_Checklist_v0.0.4.md
```

### Statut

✅ Traité

---

## TD-MAINT-005

### Titre

Revue technique du cœur absente

### Priorité

P1

### Niveau de risque

Moyen

### Action corrective

Créer :

```text
Core_Review_Report_v0.0.4.md
```

### Statut

✅ Traité

---

# Dette Documentaire

---

## TD-DOC-001

### Titre

Harmonisation documentaire incomplète

### Priorité

P2

### Niveau de risque

Faible

### Description

Plusieurs documents nécessitent encore une harmonisation finale.

### Statut

🟡 En cours

---

## TD-DOC-002

### Titre

Documentation de la modularisation inexistante

### Priorité

P1

### Niveau de risque

Moyen

### Action corrective

Créer :

```text
CPU_Modularization_Plan_v0.0.4.md
```

### Statut

✅ Traité

---

## TD-DOC-003

### Titre

Organisation documentaire incomplète

### Priorité

P1

### Niveau de risque

Moyen

### Description

Les artefacts historiques de la v0.0.3 étaient mélangés aux documents actifs de la v0.0.4.

### Action corrective

Séparation :

```text
docs/archive/
```

et

```text
docs/reports/
```

### Résultat

- releases v0.0.3 archivées ;
- rapports v0.0.3 archivés ;
- documents actifs v0.0.4 conservés séparément.

### Statut

✅ Résolu

---

# Synthèse des Priorités

## Priorité P1

### Architecture

- CPU monolithique (en réduction)

---

## Priorité P2

### Documentation

- Harmonisation finale.

---

# Plan de Traitement

| Phase | Objectif | État |
|---------|-----------|---------|
| 1 | Réorganisation documentaire | ✅ |
| 2 | Analyse du CPU | ✅ |
| 3 | Modularisation CPU | ✅ |
| 4 | Réduction du switch | ✅ |
| 5 | Renforcement des tests | ✅ |
| 6 | Validation finale | 🟡 |

---

# Critères de Clôture

La dette technique sera considérée comme suffisamment réduite lorsque :

[x] CPU modularisé
[x] FLAGS isolés
[x] Instructions isolées
[x] Couverture OVERFLOW validée
[x] Test Stack Overflow présent
[x] Test Stack Underflow présent
[x] Test MAX_CYCLES présent
[x] Test ROM surdimensionnée présent
[x] Test frontières mémoire présent
[x] Switch simplifié
[ ] Documentation harmonisée

---

# Évaluation Finale

| Domaine | Niveau |
|----------|----------|
| CPU | ✅ |
| Architecture CPU | ✅ |
| FLAGS | ✅ |
| Tests de robustesse | ✅ |
| Mémoire | 🟡 |
| Documentation | 🟡 |
| Organisation documentaire | ✅ |
| Dette globale | 🟡 |

---

# Décision

Résultat :

☒ Dette identifiée

☒ Réorganisation documentaire réalisée

☒ Modularisation CPU terminée

☒ Réduction de dette validée

☐ Dette consolidée

---

# Prochaine Action Recommandée

Priorité immédiate :

Validation finale du cycle v0.0.4
et harmonisation documentaire.

---

**Fin du document**  
**Technical_Debt_Report_v0.0.4.md**  
**Version : v0.0.4**  
**Statut : Validation Finale**