# 📊 Smart Data Structure Visualizer & Simulator

<p align="center">
  <img src="https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/>
  <img src="https://img.shields.io/badge/Platform-Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white"/>
  <img src="https://img.shields.io/badge/Interface-Console-1C1C1C?style=for-the-badge&logo=gnometerminal&logoColor=white"/>
  <img src="https://img.shields.io/badge/Version-1.0-brightgreen?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/License-MIT-yellow?style=for-the-badge"/>
</p>

<p align="center">
  <b>An interactive, color-coded console application to visualize and simulate core data structures — built entirely in C++.</b>
</p>

---

## 🧠 About

**DS Visualizer** is an educational console application designed to help students **learn, interact with, and understand data structures** through real-time visual simulation — right in the terminal.

No GUI frameworks. No external libraries. Just pure **C++**, ANSI color codes, and clever console rendering.

> Built by **Krishno Mondol**, Department of Computer Science and Engineering, Khulna University of Engineering & Technology (KUET).

---

## ✨ Features

- 🔐 **User Authentication System** — Sign up / Sign in with email, username, and password (stored persistently in `Users.txt`)
- 🎨 **Colored Console Output** — Rich ANSI color-coded UI for an engaging terminal experience
- 📦 **9 Data Structure Modules** — Each with its own interactive visualizer and operation menu
- 🔁 **Session Management** — Multi-user support with sign-in/sign-out flow

---

## 📐 Supported Data Structures

| # | Data Structure | Module File |
|---|----------------|-------------|
| 0 | Array | `arrayEngine.hpp` |
| 1 | Stack | `stackengine.hpp` |
| 2 | Queue | `QueueEngine.hpp` |
| 3 | Expression Conversion (Infix/Postfix/Prefix) | `Evaluation.hpp` |
| 4 | Singly Linked List | `LinkListEngine.hpp` |
| 5 | Doubly Linked List | `DoublyLinkListEngine.hpp` |
| 6 | Graph | `GraphEngine.hpp` |
| 7 | Binary Search Tree (BST) | `BSTEngine.hpp` |
| 8 | Heap (Min/Max) | `HeapEngine.hpp` |

---

## 🗂️ Project Structure

```
DS-Visualizer/
│
├── main.cpp                    # Entry point — auth system & main menu
├── colors.hpp                  # ANSI color code definitions
│
├── arrayEngine.hpp             # Array visualizer & operations
├── stackengine.hpp             # Stack visualizer & operations
├── QueueEngine.hpp             # Queue visualizer & operations
├── Evaluation.hpp              # Expression conversion (Infix ↔ Postfix ↔ Prefix)
├── LinkListEngine.hpp          # Singly Linked List visualizer
├── DoublyLinkListEngine.hpp    # Doubly Linked List visualizer
├── GraphEngine.hpp             # Graph visualizer (adjacency-based)
├── BSTEngine.hpp               # Binary Search Tree visualizer
├── HeapEngine.hpp              # Heap visualizer & operations
│
└── Users.txt                   # Persistent user data (auto-generated)
```

---

## 🚀 Getting Started

### Prerequisites

- A C++ compiler supporting **C++11 or later** (e.g., `g++`, MinGW on Windows)
- Windows OS recommended (uses `<conio.h>` for password masking)
- A terminal that supports **ANSI escape codes** (Windows Terminal, VS Code Terminal, etc.)

### Compilation

```bash
g++ main.cpp -o DSVisualizer
```

Or with explicit standard:

```bash
g++ -std=c++17 main.cpp -o DSVisualizer
```

### Run

```bash
./DSVisualizer
```

---

## 🖥️ How to Use

1. **Launch** the application — you'll be greeted with the DS Visualizer title screen.
2. **Sign Up** with your email, username, and a password (min. 6 characters).
   - Each email can be used for up to **3 accounts**.
   - Usernames must be **unique**.
3. **Sign In** using your email or username.
4. From the **main menu**, choose any data structure (0–8) to open its visualizer.
5. Each module has its own **interactive menu** with operations like insert, delete, search, traverse, and more.
6. **Sign Out** when done (option 9), or **Exit** from the home screen (option 4).

---

## 🔐 Authentication Details

- Credentials are stored in `Users.txt` in a simple comma-separated format.
- Password input is **masked** with `*` using `getch()` from `<conio.h>`.
- Basic validation includes duplicate username checks and email account limits.

> ⚠️ **Note:** Passwords are stored in **plain text** for simplicity. This project is intended for **educational and academic purposes only** — not for production use.

---

## 🎨 Color Theme

The application uses a custom `colors.hpp` header with ANSI escape codes:

| Color Token | Usage |
|-------------|-------|
| `BBLUE` | Section headings |
| `BMAGENTA` | Input prompts |
| `BGREEN` | Success messages |
| `BRED` | Error messages |
| `BG_RED` | Critical warnings |
| `BG_GREEN` | Confirmation banners |
| `BG_YELLOW` | UI borders and titles |
| `BCYAN` | Information text |

---

## 📸 Demo (Console Preview)

```
======================
|   DS Visualizer    |
======================
[1] Sign In
[2] Sign Up
[3] About
[4] EXIT
Enter your choice: _
```

```
[0] Array
[1] Stack
[2] Queue
[3] Expression Convertion
[4] Linked List
[5] Doubly Linked List
[6] Graph
[7] Binary Search Tree
[8] Heap
[9] Sign Out
Enter your choice: _
```

---

## 🛠️ Technologies Used

| Technology | Role |
|------------|------|
| **C++17** | Core language |
| **STL** (`vector`, `fstream`, `sstream`) | Data management & file I/O |
| **ANSI Escape Codes** | Color & formatting |
| **`<conio.h>`** | Masked password input |

---

## 👨‍💻 Author

**Krishno Mondol**
Student, Department of Computer Science and Engineering
Khulna University of Engineering & Technology (KUET)

---

## 📄 License

This project is licensed under the [MIT License](LICENSE).

---

## 🙏 Acknowledgements

- Developed as an academic project to demonstrate the practical use of data structures.
- Inspired by the need to make abstract CS concepts tangible and interactive.

---

<p align="center">© 2026 DS Visualizer — Made with ❤️ and C++</p>