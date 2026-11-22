# Arithmetic Flag Validation Plan v0.0.4

Projet : Azure-8  
Version : v0.0.4  
Type : Plan de Validation des FLAGS  
Statut : Draft  
Cycle : Consolidation du Cœur

---

# Objectif

Le présent document définit la stratégie de validation des FLAGS arithmétiques du processeur Azure‑8.

L'analyse du CPU et des tests existants a montré que :

- les FLAGS sont implémentés ;
- les mécanismes de calcul sont présents ;
- les scénarios de validation sont partiellement couverts ;
- plusieurs cas critiques ne sont actuellement pas démontrés par les tests.

La validation des FLAGS constitue la priorité technique principale de la v0.0.4.

---

# Périmètre

Les FLAGS concernés sont :

| Flag | Description |
|----------|----------|
| ZERO | Résultat nul |
| NEGATIVE | Bit de signe actif |
| CARRY | Retenue ou emprunt |
| OVERFLOW | Dépassement signé |

---

# Objectifs de Validation

La validation doit démontrer :

- le comportement nominal ;
- les cas limites ;
- les transitions critiques ;
- la cohérence avec l'ISA ;
- l'absence de régression lors de la future modularisation du CPU.

---

# État Actuel

## Couverture Confirmée

| Instruction | Couverture Actuelle |
|----------|----------|
| CMP | ✅ Bonne |
| ADD | ⚠ Partielle |
| SUB | ⚠ Partielle |
| INC | ⚠ Partielle |
| DEC | ⚠ Partielle |

---

## Constat

CMP dispose déjà de scénarios validant :

- ZERO ;
- NEGATIVE ;
- CARRY.

Les autres instructions valident principalement le résultat final mais pas les FLAGS associés.

---

# Validation de ADD

## Situation Actuelle

Validé :

```text
10 + 32 = 42
```

---

## Tests à Ajouter

### ADD_Zero

Objectif :

```text
0 + 0 = 0
```

Validation :

- ZERO = true
- NEGATIVE = false
- CARRY = false
- OVERFLOW = false

---

### ADD_Carry

Objectif :

```text
255 + 1 = 0
```

Validation :

- ZERO = true
- CARRY = true

---

### ADD_Negative

Objectif :

```text
64 + 64 = 128
```

Validation :

- NEGATIVE = true

---

### ADD_Overflow

Objectif :

```text
127 + 1
```

Validation :

- NEGATIVE = true
- OVERFLOW = true

---

# Validation de SUB

## Situation Actuelle

Validé :

```text
50 - 8 = 42
```

---

## Tests à Ajouter

### SUB_Zero

Objectif :

```text
42 - 42 = 0
```

Validation :

- ZERO = true

---

### SUB_Negative

Objectif :

```text
5 - 8
```

Validation :

- NEGATIVE = true

---

### SUB_Carry

Objectif :

```text
0 - 1
```

Validation :

- CARRY = true

---

### SUB_Overflow

Objectif :

```text
-128 - 1
```

Représentation :

```text
0x80 - 0x01
```

Validation :

- OVERFLOW = true

---

# Validation de INC

## Situation Actuelle

Validé :

```text
41 -> 42
```

---

## Tests à Ajouter

### INC_Zero

Objectif :

```text
255 -> 0
```

Validation :

- ZERO = true

---

### INC_Negative

Objectif :

```text
127 -> 128
```

Validation :

- NEGATIVE = true

---

### INC_Overflow

Objectif :

```text
127 -> 128
```

Validation :

- OVERFLOW = true

---

# Validation de DEC

## Situation Actuelle

Validé :

```text
42 -> 41
```

---

## Tests à Ajouter

### DEC_Zero

Objectif :

```text
1 -> 0
```

Validation :

- ZERO = true

---

### DEC_Negative

Objectif :

```text
0 -> 255
```

Validation :

- NEGATIVE = true

---

### DEC_Overflow

Objectif :

```text
128 -> 127
```

Validation :

- OVERFLOW = true

---

# Validation de CMP

## Situation Actuelle

CMP dispose déjà de trois scénarios :

### CMP Equal

Validation :

- ZERO ;
- NEGATIVE ;
- CARRY.

---

### CMP Greater

Validation :

- ZERO ;
- NEGATIVE ;
- CARRY.

---

### CMP Less

Validation :

- ZERO ;
- NEGATIVE ;
- CARRY.

---

## Vérification Requise

Point à vérifier :

```text
CMP doit-il mettre à jour OVERFLOW ?
```

Cette question devra être validée à partir :

- des spécifications ISA ;
- du comportement attendu de l'architecture.

---

# Priorisation

## Priorité 1

### ADD

- ADD_Zero
- ADD_Carry
- ADD_Negative
- ADD_Overflow

---

### SUB

- SUB_Zero
- SUB_Carry
- SUB_Negative
- SUB_Overflow

---

## Priorité 2

### INC

- INC_Zero
- INC_Negative
- INC_Overflow

---

### DEC

- DEC_Zero
- DEC_Negative
- DEC_Overflow

---

## Priorité 3

### CMP

Vérification documentaire concernant OVERFLOW.

---

# Plan d'Implémentation

## Phase 1

ADD

État :

⚪

---

## Phase 2

SUB

État :

⚪

---

## Phase 3

INC

État :

⚪

---

## Phase 4

DEC

État :

⚪

---

## Phase 5

CMP

État :

⚪

---

## Phase 6

Mise à jour des rapports

Documents concernés :

```text
Flag_Coverage_Report_v0.0.4.md

Core_Review_Report_v0.0.4.md

Technical_Debt_Report_v0.0.4.md
```

État :

⚪

---

# Critères de Validation

La validation des FLAGS sera considérée comme terminée lorsque :

✅ ADD valide tous ses FLAGS

✅ SUB valide tous ses FLAGS

✅ INC valide tous ses FLAGS

✅ DEC valide tous ses FLAGS

✅ CMP est documenté complètement

✅ OVERFLOW est démontré explicitement

✅ Aucun scénario ambigu n'existe

✅ Les nouveaux tests sont intégrés au harnais principal

---

# Couverture Attendue

| Instruction | ZERO | NEGATIVE | CARRY | OVERFLOW |
|------------|---------|---------|---------|---------|
| ADD | ✅ | ✅ | ✅ | ✅ |
| SUB | ✅ | ✅ | ✅ | ✅ |
| INC | ✅ | ✅ | N/A | ✅ |
| DEC | ✅ | ✅ | N/A | ✅ |
| CMP | ✅ | ✅ | ✅ | À vérifier |

---

# Checklist

## ADD

- [ ] Zero
- [ ] Carry
- [ ] Negative
- [ ] Overflow

---

## SUB

- [ ] Zero
- [ ] Carry
- [ ] Negative
- [ ] Overflow

---

## INC

- [ ] Zero
- [ ] Negative
- [ ] Overflow

---

## DEC

- [ ] Zero
- [ ] Negative
- [ ] Overflow

---

## CMP

- [ ] Comportement documenté
- [ ] OVERFLOW vérifié

---

# Décision

Résultat :

☒ Plan rédigé

☐ Implémentation démarrée

☐ Validation partielle

☐ Validation complète

☐ Couverture consolidée

---

**Fin du document**  
**Arithmetic_Flag_Validation_Plan_v0.0.4.md**  
**Version : v0.0.4**  
**Statut : Draft**