# DSA-Snippets

Collection of small, focused DSA programs and exercises in C — each file demonstrates a single data structure / algorithm implementation (with minimal dependencies).
This repository is meant as a learning journal: short, well-documented programs you can compile, run, and study. <br>
The basic programs are in intermediate stage, now the rest of code related to Doubly Linked List, Trees and Graphs are remanining. I will update those as so as I cover them.

---

## 📌 About this repo
- Each file is a single, self-contained DSA program (e.g. `Stack1.c`).
- Goal: practice writing classic data-structure/algorithm implementations from scratch and keep a public, incremental record on GitHub.
- Not a production project — educational snippets with clear comments and usage examples.

---

## Getting Started
First clone the repo to your local machine by running the following command: <br>
```bash
git clone https://github.com/adarsh-v-h/DSA-with-C.git
```
The C code must be first compiled before running, here is how you can do it: <br>
Windows
```bash
gcc -o filename filename.c
filename
```
Linux
```bash
gcc -o filename filename.c
./filename
```

---

## 💫 **New Thing**
In /main/IMP I have added few user defined libraries for testing, and they are only linked with the main/IMP/QueueAndLinkedList.c. The header file is called "c_utils", the prototypes for the fucntions are in c_utils.h and the function definitions are in c_utils.c. <br>
To execute the program QueueAndLinkedList.c:
```bash
gcc -o app QueueAndLinkedList.c c_utils.c
# for windowspowershell
app
#for linux or mac or windows terminals 
./app
```
Or you can use the make command, this is how it works:
```bash
cd main/IMP
make Queue
```
This will build the executable file, then run
```bash
./app
```
After the end of program, its good practice to clean up left over file. For that run
```bash
make clean
```
This is currently only for QueueAndLinkedList.c program.<br>

---

## Before you go
All the programs in here, have bugs, loop holes and can be exploited, but conditions like wrong data input, overflow or underflow conditions. This whole thing is made for jusr understanding, and have a huge space to grow, into better codes.
