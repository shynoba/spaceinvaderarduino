# 👾 Space Invader - Arduino Project

Un mini-jeu **Space Invader** inspiré des classiques d'arcade, développé en C++ pour Arduino UNO. Le jeu utilise une matrice **LED 8x8 MAX7219**, un **joystick analogique**, et un **écran LCD1602** (sans I2C) pour afficher les scores et les instructions.

---
## Photo

![schemareal](https://github.com/user-attachments/assets/761a1152-c8e7-42f1-b1f3-89de45503c2d)
![SchemaSpaceInvador](https://github.com/user-attachments/assets/122d409a-28b3-4754-8325-d89691f66915)



## 🕹️ Fonctionnalités

- Affichage d’un **logo "S"** sur la matrice MAX7219 en attendant le début de la partie
- **Écran d'accueil** sur le LCD1602 : `Space Invader` & `Move to play!`
- Le jeu démarre dès qu’on **bouge le joystick** sur l’axe **X**
- Contrôle du vaisseau de gauche à droite avec le joystick
- **Tirs automatiques** vers les aliens
- **Collision** entre les tirs et les aliens : +1 point
- Affichage du **score en temps réel** sur le LCD
- **Fin de partie** si un alien touche le joueur
- Redémarrage automatique après "game over"

---

## 🔧 Matériel nécessaire

| Composant        | Quantité |
|------------------|----------|
| Arduino UNO      | 1        |
| Joystick analogique | 1     |
| Matrice MAX7219 (8x8) | 1   |
| Écran LCD1602 (sans I2C) | 1 |
| Résistances 220 ohm, fils, breadboard | ✓ |

---

## ⚙️ Câblage (extrait)

### MAX7219 (LedControl)
| Module | Arduino |
|--------|---------|
| DIN    | Pin 11  |
| CLK    | Pin 13  |
| CS     | Pin 10  |

### LCD1602 (LiquidCrystal)
| LCD Pin | Arduino |
|---------|---------|
| RS      | Pin 8   |
| E       | Pin 7   |
| D4      | Pin 6   |
| D5      | Pin 5   |
| D6      | Pin 4   |
| D7      | Pin 3   |

### Joystick
| Joystick | Arduino |
|----------|---------|
| VRx      | A3      |
| GND/VCC  | GND/5V  |

---

## 🔌 Installation

1. Branche les composants comme indiqué ci-dessus
2. Téléverse le code depuis `SpaceInvader.ino` via l’IDE Arduino
3. Ouvre le moniteur série si besoin pour debug

---

## 🎮 Utilisation

1. Au démarrage, le LCD affiche :
Space Invader
Move to play!

Et un "S" s'affiche sur le MAX7219.
2. Bouge le joystick sur l'axe X pour démarrer.
3. Déplace ton vaisseau, évite les aliens, tire automatiquement.
4. Le score est affiché en temps réel sur le LCD.
5. Si un alien te touche → Game Over → retour à l'écran d'accueil.

---
---

## 🚀 Améliorations futures (idées)

- Ajouter un bouton pour tirer manuellement
- Ajouter plusieurs niveaux de difficulté (vitesse des aliens)
- Affichage du score final pendant 3 secondes avant le restart
- Intégrer un buzzer pour les effets sonores

Test 
---
