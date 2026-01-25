# Undo-Redo Feature in Text Editor

---

## Overview
This project implements a simple text editor using the C programming language with support for undo and redo operations. The main objective is to demonstrate the practical use of the stack data structure in managing user actions efficiently. Undo and redo are essential features in modern text editors, allowing users to reverse mistakes and restore previous changes during text editing.

---

## Concepts Used
- Stack Data Structure  
- Last-In-First-Out (LIFO) principle  
- Structured Programming in C  

---

## Features
- Type text into the editor  
- Delete a word using index position  
- Undo the most recent action  
- Redo previously undone actions  
- Display the current text content  
- Menu-driven command-line interface  

---

## Working Principle
The text editor uses two stacks: an Undo Stack and a Redo Stack. Every action performed by the user, such as inserting or deleting text, is stored in the undo stack. When an undo operation is performed, the most recent action is removed from the undo stack and pushed onto the redo stack, reversing its effect on the text. When a redo operation is executed, the action is taken from the redo stack, reapplied to the editor, and pushed back onto the undo stack. This approach ensures efficient execution with constant time complexity for undo and redo operations.

---

## Technologies Used
- C Programming Language  
- Standard C Libraries (stdio.h, stdlib.h, string.h)  

---

## How to Run
1. Compile the program:
   gcc text_editor.c -o text_editor
2. Run the executable:
   ./text_editor

---

## Learning Outcome
This project helps in understanding stack operations, memory management, and the internal working of undo-redo mechanisms in text editing applications.

---

## Author
   Dheekshita R

---
