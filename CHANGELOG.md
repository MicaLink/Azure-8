# Changelog

Toutes les évolutions significatives du projet **Azure‑8** sont documentées dans ce fichier.

Le format adopté s'inspire de **Keep a Changelog** tout en restant adapté à l'écosystème **AzureEngine**.

---

# [0.0.4] - En cours

## Vue d'ensemble

La version v0.0.4 est un cycle de consolidation du cœur Azure‑8.

Cette version ne vise aucun ajout fonctionnel.

Les objectifs sont :

- la réduction de la dette technique ;
- l'amélioration de la qualité du code ;
- le renforcement des tests ;
- la consolidation du CPU ;
- l'amélioration de la maintenabilité ;
- la réorganisation documentaire ;
- la préparation des futures évolutions de l'écosystème AzureEngine.

---

## Ajouté

### Gouvernance Technique

- Core_Consolidation_Report_v0.0.4.md
- Core_Review_Report_v0.0.4.md
- Technical_Debt_Report_v0.0.4.md

### Refactorisation

- CPU_Modularization_Plan_v0.0.4.md
- CPU_Refactoring_Checklist_v0.0.4.md

### Validation

- Flag_Coverage_Report_v0.0.4.md
- Test_Matrix_v0.0.4.md
- Arithmetic_Flag_Validation_Plan_v0.0.4.md

### Planification

- Azure-8_Roadmap_v0.0.4.md

---

## Analysé

### CPU

Première revue complète de :

```text
src/Azure8/CPU.h
src/Azure8/CPU.cpp
```

Constats :

- CPU fonctionnel ;
- architecture globalement saine ;
- responsabilités fortement centralisées ;
- modularisation recommandée.

---

### Architecture

Identification des éléments suivants :

- CPU monolithique ;
- logique FLAGS non isolée ;
- logique ISA non isolée ;
- switch d'opcodes centralisé.

---

### Tests

Analyse complète des scénarios existants :

```text
TestFlags.cpp
TestInstructionADD.cpp
TestInstructionSUB.cpp
TestInstructionINC.cpp
TestInstructionDEC.cpp
TestInstructionCMP.cpp
```

Constats :

- CMP correctement couvert ;
- couverture OVERFLOW insuffisamment démontrée ;
- couverture des FLAGS arithmétiques incomplète.

---

## Réorganisé

### Documentation

Séparation complète de :

```text
Documentation active
```

et

```text
Archives historiques
```

---

### Archivage

Création de :

```text
docs/archive/
```

pour accueillir :

- roadmaps historiques ;
- releases historiques ;
- rapports historiques ;
- anciennes spécifications.

---

### Rapports

Archivage des rapports v0.0.3 :

- Architecture_Consistency_Report_v0.0.3.md
- Documentation_Audit_v0.0.3.md
- Quality_Audit_v0.0.3.md
- Release_Report_v0.0.3.md
- Security_Audit_v0.0.3.md

---

### Releases

Archivage des livrables :

- Azure-8_v0.0.3_Release_Checklist.md
- Azure-8_v0.0.3_Release_Notes.md
- Release_Criteria_v0.0.3.md

---

## Documenté

### Dette Technique

Identification et classification :

- dette d'architecture ;
- dette de tests ;
- dette documentaire ;
- dette de maintenabilité.

---

### Couverture des FLAGS

Cartographie complète de :

- ZERO ;
- NEGATIVE ;
- CARRY ;
- OVERFLOW.

---

### Couverture des Tests

Identification :

- tests existants ;
- tests manquants ;
- zones de risque ;
- priorités de validation.

---

## Prévu

### Validation des FLAGS

Ajout des scénarios :

```text
ADD_Zero
ADD_Carry
ADD_Negative
ADD_Overflow

SUB_Zero
SUB_Carry
SUB_Negative
SUB_Overflow

INC_Zero
INC_Negative
INC_Overflow

DEC_Zero
DEC_Negative
DEC_Overflow
```

---

### Modularisation CPU

Structure cible :

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

### Réduction du Switch

Extraction progressive de la logique metier :

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

---

### Tests de Robustesse

Creation des tests :

```text
TestStackOverflow.cpp
TestStackUnderflow.cpp
TestMaxCycles.cpp
TestLargeROM.cpp
TestMemoryBoundary.cpp
```

---

## État

Statut :

```text
Consolidation en cours
```

---

# [0.0.3] - Première Release Officielle

## Vue d'ensemble

Première version officiellement publiée d'Azure‑8.

Cette version marque :

- l'achèvement de la première machine virtuelle Azure‑8 ;
- la validation du CPU ;
- la validation de la mémoire ;
- la validation du système de pile ;
- la validation du jeu d'instructions v0.0.3 ;
- l'intégration officielle dans l'écosystème AzureEngine.

---

## Ajouté

### Architecture CPU

- CPU 8 bits
- adressage mémoire 16 bits
- architecture Little Endian
- registres utilisateur A, B, C, D
- registre PC
- registre SP
- registre FLAGS

---

### Mémoire

- Read8()
- Write8()
- Read16()
- Write16()

---

### Pile

- Push8()
- Pop8()
- Push16()
- Pop16()

---

### FLAGS

- ZERO
- CARRY
- NEGATIVE
- OVERFLOW

---

### Jeu d'Instructions

#### Contrôle CPU

- NOP
- HLT

#### Manipulation de données

- MOV
- LOAD
- STORE

#### Gestion de pile

- PUSH
- POP
- CALL
- RET

#### Arithmétique

- INC
- DEC
- ADD
- SUB

#### Comparaison

- CMP

#### Branchements

- JMP
- JZ
- JNZ

---

### ROMs de Validation

#### ROMs fondamentales

- nop.rom
- halt.rom
- invalid.rom

#### ROMs d'instructions

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

#### ROMs d'infrastructure

- memory16.rom
- stack8.rom
- stack16.rom

---

### Tests Automatisés

#### Infrastructure

- TestCPU.cpp
- TestMemory.cpp
- TestStack.cpp
- TestFlags.cpp

#### Instructions

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

### Documentation

Création de :

- README.md
- CHANGELOG.md
- Azure-8_CPU_Architecture_v1.0.md
- Azure-8_Technical_Specification_v0.0.3.md
- Azure-8_Instruction_Set_v0.0.3.md
- Azure-8_Module_Specification_v1.0.md

---

## Réorganisé

### Dépôt

Structure normalisee :

```text
assets/
docs/
roms/
samples/
src/
tests/
tools/
```

---

### Écosystème AzureEngine

Azure-8 devient officiellement :

```text
Premier module officiel AzureEngine
```

Ajout de :

```text
azure8.module.json
```

---

# [0.0.2]

## Réalisé

- amélioration du processeur Azure‑8 ;
- extension du jeu d'instructions ;
- amélioration du système mémoire ;
- enrichissement des tests ;
- amélioration de la documentation.

---

# [0.0.1]

## Réalisé

- création du projet Azure‑8 ;
- implémentation initiale du CPU ;
- implémentation initiale de la mémoire ;
- premières ROMs de validation ;
- premiers tests unitaires ;
- premières spécifications.

---

## Historique des versions

| Version | Statut |
|----------|----------|
| 0.0.1 | Historique |
| 0.0.2 | Historique |
| 0.0.3 | Premiere release officielle |
| 0.0.4 | Consolidation en cours |

---

Projet : Azure-8

Ecosysteme : AzureEngine

Premier module officiel AzureEngine