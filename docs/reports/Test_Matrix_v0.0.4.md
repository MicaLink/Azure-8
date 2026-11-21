# Test Matrix v0.0.4

Projet : Azure-8  
Version : v0.0.4  
Type : Matrice de Couverture des Tests  
Statut : Draft

---

# Objectif

Le présent document fournit une vue consolidée de la couverture de test du projet Azure‑8.

Il sert à :

- inventorier les tests existants ;
- identifier les composants couverts ;
- identifier les zones insuffisamment testées ;
- préparer les travaux de consolidation de la v0.0.4 ;
- orienter les futures campagnes de refactorisation.

Ce document ne mesure pas le pourcentage de couverture.

Il identifie uniquement la présence ou l'absence de scénarios de test observés.

---

# Périmètre

Le rapport couvre :

- CPU ;
- mémoire ;
- pile ;
- FLAGS ;
- instructions ;
- mécanismes de protection.

---

# Matrice Composants → Tests

## CPU

| Fonctionnalité | Test |
|----------|----------|
| Reset CPU | TestCPU.cpp |
| Registres | TestCPU.cpp |
| FLAGS | TestFlags.cpp |
| État HALT | TestCPU.cpp |

Statut :

🟡 Couverture partielle observée

---

## Mémoire

| Fonctionnalité | Test |
|----------|----------|
| Read8 | TestMemory.cpp |
| Write8 | TestMemory.cpp |
| Read16 | TestMemory.cpp |
| Write16 | TestMemory.cpp |

Statut :

🟡 Couverture de base observée

Zones à renforcer :

- frontières mémoire ;
- wrap-around ;
- cas limites.

---

## Pile

| Fonctionnalité | Test |
|----------|----------|
| Push8 | TestStack.cpp |
| Pop8 | TestStack.cpp |
| Push16 | TestStack.cpp |
| Pop16 | TestStack.cpp |

Statut :

🟡 Couverture de base observée

Zones à renforcer :

- Stack Overflow ;
- Stack Underflow.

---

# Matrice ISA → Tests

## Contrôle CPU

| Instruction | Test |
|----------|----------|
| NOP | Non identifié |
| HLT | Non identifié |

Statut :

🟡 À vérifier

---

## Manipulation de Données

| Instruction | Test |
|----------|----------|
| MOV | TestInstructionMOV.cpp |
| LOAD | TestInstructionLOAD.cpp |
| STORE | TestInstructionSTORE.cpp |

Statut :

✅ Tests identifiés

---

## Gestion de Pile

| Instruction | Test |
|----------|----------|
| PUSH | TestInstructionPUSH.cpp |
| POP | TestInstructionPOP.cpp |
| CALL | TestInstructionCALL.cpp |
| RET | TestInstructionRET.cpp |

Statut :

✅ Tests identifiés

---

## Arithmétique

| Instruction | Test |
|----------|----------|
| INC | TestInstructionINC.cpp |
| DEC | TestInstructionDEC.cpp |
| ADD | TestInstructionADD.cpp |
| SUB | TestInstructionSUB.cpp |

Statut :

✅ Tests identifiés

---

## Comparaison

| Instruction | Test |
|----------|----------|
| CMP | TestInstructionCMP.cpp |

Statut :

✅ Test identifié

---

## Branchements

| Instruction | Test |
|----------|----------|
| JMP | TestInstructionJMP.cpp |
| JZ | TestInstructionJZ.cpp |
| JNZ | TestInstructionJNZ.cpp |

Statut :

✅ Tests identifiés

---

# Matrice FLAGS → Tests

## ZERO

| Instruction | Couverture |
|----------|----------|
| INC | 🟡 |
| DEC | 🟡 |
| ADD | 🟡 |
| SUB | 🟡 |
| CMP | 🟡 |

---

## NEGATIVE

| Instruction | Couverture |
|----------|----------|
| INC | 🟡 |
| DEC | 🟡 |
| ADD | 🟡 |
| SUB | 🟡 |
| CMP | 🟡 |

---

## CARRY

| Instruction | Couverture |
|----------|----------|
| ADD | 🟡 |
| SUB | 🟡 |
| CMP | 🟡 |

---

## OVERFLOW

| Instruction | Couverture |
|----------|----------|
| INC | 🔴 |
| DEC | 🔴 |
| ADD | 🔴 |
| SUB | 🔴 |
| CMP | 🔴 |

Observations :

Le flag OVERFLOW constitue la principale zone de risque identifiée durant le cycle v0.0.4.

La présence de scénarios dédiés n'est actuellement pas démontrée.

---

# Matrice Protections → Tests

| Protection | Test Existant |
|----------|----------|
| Opcode invalide | À vérifier |
| Registre invalide | À vérifier |
| Stack Overflow | Aucun |
| Stack Underflow | Aucun |
| MAX_CYCLES | Aucun |
| ROM surdimensionnée | Aucun |

---

# Tests de Consolidation Planifiés

## Nouveaux Tests

| Test | Objectif |
|----------|----------|
| TestStackOverflow.cpp | Validation Overflow |
| TestStackUnderflow.cpp | Validation Underflow |
| TestMaxCycles.cpp | Validation MAX_CYCLES |
| TestLargeROM.cpp | Validation ROM surdimensionnée |
| TestMemoryBoundary.cpp | Validation frontières mémoire |

---

# Zones Prioritaires

## Priorité P1

### Protection de la Pile

À implémenter :

- Stack Overflow ;
- Stack Underflow.

---

### Protection d'Exécution

À implémenter :

- MAX_CYCLES.

---

### Protection de Chargement

À implémenter :

- ROM surdimensionnée.

---

### Couverture OVERFLOW

À démontrer pour :

- INC ;
- DEC ;
- ADD ;
- SUB ;
- CMP.

---

# Synthèse

## Couverture Observée

✅ CPU

✅ Mémoire

✅ Pile

✅ Instructions principales

✅ FLAGS de base

---

## Couverture Partielle

🟡 NOP

🟡 HLT

🟡 CARRY

🟡 NEGATIVE

🟡 ZERO

---

## Couverture Insuffisamment Démontrée

🔴 OVERFLOW

🔴 Stack Overflow

🔴 Stack Underflow

🔴 MAX_CYCLES

🔴 ROM surdimensionnée

🔴 Frontières mémoire

---

# Critères de Validation

La matrice sera considérée comme satisfaisante lorsque :

✅ Toutes les instructions disposeront d'un test identifié

✅ Toutes les protections disposeront d'un test identifié

✅ Tous les FLAGS disposeront de scénarios de validation explicites

✅ Tous les tests de consolidation v0.0.4 seront présents

✅ Les zones rouges auront disparu

---

# Décision

Résultat :

☒ Inventaire initial réalisé

☐ Couverture validée

☐ Couverture consolidée

☐ Matrice complète

---

**Fin du document**  
**Test_Matrix_v0.0.4.md**  
**Version : v0.0.4**  
**Statut : Draft**