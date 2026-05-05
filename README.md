# ❌⭕ Tic-Tac-Toe

A terminal-based 2-player Tic-Tac-Toe game written in **C++14** — designed with clean OOP principles and multiple Low-Level Design (LLD) patterns.

![C++](https://img.shields.io/badge/C++-14-00599C?logo=c%2B%2B) ![Build](https://img.shields.io/badge/Build-Makefile-green) ![Platform](https://img.shields.io/badge/Platform-Linux%20%2F%20macOS-lightgrey)

---

## ✨ Features

- 2-player local gameplay in the terminal
- Custom player names
- Input validation (non-integer, out-of-range, already-occupied cell)
- O(1) win detection — no board scanning
- Clean separation of game logic, board state, and UI

---

## 🏗️ Architecture

```
┌─────────────────────────────────────────────────────┐
│                      main.cpp                        │
│  Entry point — wires UI + TicTacToe, runs game loop  │
└──────────────────────┬──────────────────────────────┘
                       │
          ┌────────────┴────────────┐
          │                         │
    ┌─────▼──────┐           ┌──────▼─────┐
    │     UI     │           │ TicTacToe  │  ← Controller / Facade
    │  (View)    │           │            │
    │ displayMenu│           │  Board     │  ← Model (state)
    │ getChoice  │           │  Player1   │  ← Model (win tracking)
    │ displayBoard│          │  Player2   │
    └────────────┘           └────────────┘
```

---

## 🔄 Game Flow

```
main()
  │
  ▼
ui.displayMenu()  →  getChoice()
  │
  ├── Exit  →  exit()
  │
  └── PlayGame  →  play(ttt, ui)
                      │
                      ▼
               setPlayersNames()
                      │
                      ▼
               ┌─── Game Loop ───────────────────────┐
               │  ttt.Status() == NotFinished?        │
               │         │                            │
               │         ▼                            │
               │  Prompt current player for move[1-9] │
               │         │                            │
               │         ▼                            │
               │  getMove() → getRowAndCol()          │
               │         │                            │
               │         ▼                            │
               │  ttt.playMove(row, col)              │
               │    ├── isValidMove()?                │
               │    ├── board.updateBoard()           │
               │    ├── player.updateWinparameter()   │
               │    └── check Tie (9 moves played)    │
               │         │                            │
               │  ui.displayCurrentBoard()            │
               └─────────────────────────────────────┘
                      │
                      ▼
               Display winner / Tie
```

---

## 🧩 LLD Design Patterns

### 1. 🏛️ MVC (Model-View-Controller)

The codebase cleanly separates into three layers:

| Layer | Class | Responsibility |
|---|---|---|
| **Model** | `Board` | Stores the 3×3 grid state |
| **Model** | `Player` | Tracks win parameters per player |
| **Controller** | `TicTacToe` | Orchestrates game logic, move validation, win/tie detection |
| **View** | `UI` | All terminal I/O — display board, menu, get input |

`main.cpp` wires them together but contains no business logic.

---

### 2. 🎭 Facade Pattern

`TicTacToe` acts as a **Facade** — it hides the complexity of coordinating `Board` and `Player` behind a single clean interface:

```cpp
// Caller only needs to know this:
ttt.playMove(row, col);   // internally updates Board + Player + GameStatus
ttt.Status();             // GameStatus::NotFinished / Finished
ttt.Result();             // GameResult::Tie / Player1 / Player2
```

The caller (`main.cpp`) never directly touches `Board` or `Player` for game logic.

---

### 3. 🔒 Encapsulation (OOP)

All data members are `private`. State is only mutated through well-defined public methods:

```cpp
// Board — internal matrix is private
board.updateBoard(row, col, player);
board.checktileStatus(row, col);  // returns enum, not raw int

// Player — win counters are private
player.updateWinparameter(row, col);  // returns true if player wins
player.getName();
```

---

### 4. 📦 Single Responsibility Principle (SRP)

Each class has exactly one reason to change:

| Class | Single Responsibility |
|---|---|
| `Board` | Manage the grid state |
| `Player` | Track whether a player has won |
| `TicTacToe` | Run game rules and state transitions |
| `UI` | Handle all terminal input/output |

---

### 5. ⚡ O(1) Win Detection (Optimized Algorithm)

Instead of scanning the entire board after every move (O(N²)), `Player` maintains **counters** for each row, column, and diagonal:

```cpp
int rows[N];      // rows[i] = moves played by this player in row i
int cols[N];      // cols[j] = moves played by this player in col j
int diags[2];     // diags[0] = main diagonal, diags[1] = anti-diagonal
```

On each move, only the relevant counters are incremented. Win is detected when any counter reaches `N`:

```cpp
bool Player::updateWinparameter(int row, int col) {
    if (++rows[row] == N) return true;
    if (++cols[col] == N) return true;
    if (row == col && ++diags[0] == N) return true;          // main diagonal
    if (row + col == N-1 && ++diags[1] == N) return true;   // anti-diagonal
    return false;
}
```

**Complexity:** O(1) per move vs O(N²) for board scan.

---

### 6. 🏷️ Namespaced Enums (Conflict Resolution)

C++ enums without namespaces pollute the global scope. This project wraps each enum in its own namespace to avoid naming conflicts:

```cpp
namespace TileStatus { enum TileStatus { Empty, Player1, Player2 }; }
namespace Players    { enum Players    { Player1=1, Player2=2 };    }
namespace GameStatus { enum GameStatus { NotFinished, Finished };   }
namespace GameResult { enum GameResult { Tie, Player1, Player2 };   }
```

Usage: `TileStatus::TileStatus::Empty`, `GameResult::GameResult::Tie` — unambiguous everywhere.

---

### 7. 🗺️ Move Mapping (1–9 → row/col)

Player input is a single integer 1–9 (intuitive numpad layout). `getRowAndCol()` maps it to `(row, col)`:

```
1 | 2 | 3        (0,0) | (0,1) | (0,2)
---------   →   -------+-------+-------
4 | 5 | 6        (1,0) | (1,1) | (1,2)
---------        -------+-------+-------
7 | 8 | 9        (2,0) | (2,1) | (2,2)
```

---

## 📁 Project Structure

```
Tic-Tac-Toe/
├── main.cpp        # Entry point — game loop, input handling, wiring
├── tictactoe.h/cpp # Controller/Facade — game rules, move validation, state
├── board.h/cpp     # Model — 3×3 grid state
├── player.h/cpp    # Model — win parameter tracking (O(1) detection)
├── ui.h/cpp        # View — terminal display and input
└── makefile        # Build system
```

---

## 🚀 Getting Started

### Build

```bash
git clone https://github.com/tarunyadav148/Tic-Tac-Toe.git
cd Tic-Tac-Toe
make
```

### Run

```bash
./TicTacToe
```

### Clean

```bash
make clean
```

### Requirements

- g++ with C++14 support (`g++ --version`)
- Linux or macOS

---

## 🎮 Gameplay

```
            Tic-Tac-Toe
Enter 0 for exit
Enter 1 for play
Enter your choice: 1

Enter name of player 1: Alice
Enter name of player 2: Bob

   |   |   |
   |   |   |
   |   |   |

Alice Enter a move [1-9]: 5

   |   |   |
   | O |   |
   |   |   |
```

Player 1 is `O`, Player 2 is `X`.

---

## 🛠️ Tech Stack

| Technology | Purpose |
|---|---|
| C++14 | Core language |
| Makefile | Build system — compiles each `.cpp` to `.o` separately |
| STL (`std::pair`, `std::string`) | Move mapping, player names |

---

## 📄 License

MIT
