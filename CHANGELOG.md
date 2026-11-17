# Changelog

Toutes les évolutions importantes du projet **Azure‑8** sont documentées dans ce fichier.

Le format s'inspire de **Keep a Changelog** et suit le versioning défini pour l'écosystème AzureEngine.

---

# [0.0.3] - En préparation

## Vue d'ensemble

Première release officielle d'Azure‑8.

Cette version marque :

- l'achèvement de la première machine virtuelle Azure‑8 ;
- la validation complète du cœur CPU ;
- la validation du système mémoire ;
- la validation du système de pile ;
- la validation du jeu d'instructions v0.0.3 ;
- la transformation d'Azure‑8 en premier module officiel AzureEngine.

---

## Ajouté

### Architecture CPU

- CPU 8 bits
- adressage mémoire 16 bits
- architecture Little Endian
- registres utilisateur A, B, C et D
- registre PC (Program Counter)
- registre SP (Stack Pointer)
- registre FLAGS

---

### Gestion mémoire

- Read8()
- Write8()
- Read16()
- Write16()

---

### Gestion de pile

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

### Jeu d'instructions

#### Contrôle CPU

- NOP
- HLT

#### Manipulation des données

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

### ROMs de validation

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

### Tests automatisés

#### Infrastructure

- TestCPU
- TestMemory
- TestStack
- TestFlags

#### Instructions

- TestMOV
- TestLOAD
- TestSTORE
- TestPUSH
- TestPOP
- TestCALL
- TestRET
- TestINC
- TestDEC
- TestADD
- TestSUB
- TestCMP
- TestJMP
- TestJZ
- TestJNZ

---

### Documentation

Ajout des documents suivants :

- README.md
- Azure-8_CPU_Architecture_v1.0.md
- Azure-8_Technical_Specification_v0.0.3.md
- Azure-8_Instruction_Set_v0.0.3.md
- Azure-8_Architecture_Guide.md
- Azure-8_Roadmap_v0.0.3.md
- Azure-8_v0.0.3_Release_Notes.md
- Security_Audit_v0.0.3.md
- Quality_Audit_v0.0.3.md
- Documentation_Audit_v0.0.3.md
- Release_Report_v0.0.3.md
- Azure-8_v0.0.3_Release_Checklist.md

---

### Structure du dépôt

Réorganisation complète du dépôt :

```txt
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

Azure‑8 devient officiellement :

```txt
Premier module officiel AzureEngine
```

Ajout :

- azure8.module.json
- compatibilité avec le modèle de module AzureEngine
- préparation de l'intégration future dans AzureEngine

---

## Modifié

- restructuration complète de la documentation ;
- harmonisation des spécifications techniques ;
- uniformisation des conventions de nommage ;
- séparation du projet Azure‑8 du dépôt AzureEngine ;
- préparation du processus de release.

---

## Corrigé

- incohérences documentaires historiques ;
- organisation des spécifications ;
- archivage des anciennes spécifications techniques v0.0.1 et v0.0.2.

---

## Sécurité

Audit en cours avant publication officielle :

- validation mémoire ;
- validation pile ;
- validation CPU ;
- validation chargement ROM ;
- validation gestion des erreurs.

---

## État de la release

```txt
Statut : Préparation Release

Tag cible : azure8-v0.0.3

Publication : En attente des audits finaux
```

---

# [0.0.2]

## Réalisé

- évolution du processeur Azure‑8 ;
- amélioration du système mémoire ;
- ajout d'instructions supplémentaires ;
- extension de la couverture de tests ;
- amélioration de la documentation technique.

---

# [0.0.1]

## Réalisé

- création du projet Azure‑8 ;
- implémentation initiale du CPU ;
- implémentation initiale de la mémoire ;
- premières ROMs de test ;
- premiers tests unitaires ;
- premières spécifications techniques.

---

## Versions

| Version | Statut |
|----------|----------|
| 0.0.1 | Historique |
| 0.0.2 | Historique |
| 0.0.3 | Préparation Release |

---

**Projet : Azure‑8**

**Écosystème : AzureEngine**

**Premier module officiel AzureEngine**