# 👾 Space Invader - Arduino Project

Un mini-jeu **Space Invader** inspiré des classiques d'arcade, développé en C++ pour Arduino UNO. Le jeu utilise une matrice **LED 8x8 MAX7219**, un **joystick analogique**, et un **écran LCD1602** (sans I2C) pour afficher les scores et les instructions.

---

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
| Résistances, fils, breadboard | ✓ |

---

## ⚙️ Câblage (extrait)

### MAX7219 (LedControl)
| Module | Arduino |
|--------|---------|
| DIN    | Pin 2   |
| CLK    | Pin 3   |
| CS     | Pin 4   |

### LCD1602 (LiquidCrystal)
| LCD Pin | Arduino |
|---------|---------|
| RS      | Pin 7   |
| E       | Pin 8   |
| D4      | Pin 9   |
| D5      | Pin 10  |
| D6      | Pin 11  |
| D7      | Pin 12  |

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
