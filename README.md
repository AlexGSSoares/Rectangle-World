# Rectangle World 

## 🧾 Project Overview

This project simulates a "Rectangle World" in which users can create, move, and merge rectangles through text-based commands. It expands upon the functionality developed in Formative Activity 3 (AF3), introducing new features such as rectangle merging and automatic overlap detection.

### Goals:
- Apply modular programming techniques
- Use dynamic data structures (linked lists)
- Implement visual representation in the terminal
- Handle geometric interactions between objects

---

## 📁 Project Structure

| File               | Description                                                             |
|--------------------|-------------------------------------------------------------------------|
| `main.c`           | Main program loop that handles user input and invokes processing logic. |
| `comandos.c/h`     | Parses and interprets user commands.                                    |
| `retangulos.c/h`   | Core logic for rectangle creation, movement, gravity, and merging.      |
| `visualizacao.c/h` | Responsible for drawing the world using ASCII characters.               |
| `config.h`         | Defines data types and global constants (e.g., world size).             |
| `testes.c`         | Unit tests using a lightweight testing framework.                       |
| `minunit.h`        | Minimal unit testing macros used in `testes.c`.                         |

---

## ✅ Features Implemented

- `create x,y+width,height`: Creates a rectangle at position `(x,y)`
- `moveleft x,y+distance`: Moves the rectangle to the left
- `moveright x,y+distance`: Moves the rectangle to the right
- Gravity: Rectangles fall and rest on others if unsupported
- Visual output: Borders filled with `'X'`, inside filled with `'O'`
- `merge x1,y1+x2,y2`: Merges two aligned and overlapping rectangles
- Automatic detection of rectangles eligible for merging
- Alerts user when such overlaps are detected
- Unit tests for main operations including merge

---

## 🧪 Example Commands

```text
create 1,3+15,5
create 23,12+6,5
moveleft 23,7+1
moveright 1,1+1
merge 23,2+23,7
