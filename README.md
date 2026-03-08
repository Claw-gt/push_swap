# 🔢 push_swap

> A sorting algorithm project using two stacks and a limited set of operations, developed as part of the 42 School curriculum.

---

## 📖 Description

**push_swap** is a project from the 42 curriculum that focuses on **algorithm design**, **data structures**, and **optimization**.

The objective is to sort a list of integers using **two stacks** (`a` and `b`) and a **restricted set of operations**.  
The challenge is not only to sort the numbers, but to do so using **the smallest possible number of operations**.

The program receives a list of integers as arguments and prints the sequence of operations required to sort them.

---

## 🎯 Objectives

- Implement efficient **sorting algorithms**
- Work with **stack-based data structures**
- Optimize the number of **operations**
- Handle **input validation and error management**
- Write clean and modular **C code**

---

## ⚙️ Program Behavior

The program takes a list of integers as arguments:

`./push_swap 4 67 3 87 23`

It outputs the sequence of operations required to sort the numbers:
```
pb
ra
sa
pa
```

The goal is to produce the smallest sequence of instructions possible.

## 🔧 Allowed Operations

#### Swap

| Instruction | Description                                |
| ----------- | ------------------------------------------ |
| `sa`        | Swap the first two elements of stack **a** |
| `sb`        | Swap the first two elements of stack **b** |
| `ss`        | `sa` and `sb` at the same time             |

#### Push

| Instruction | Description                            |
| ----------- | -------------------------------------- |
| `pa`        | Push the top element of **b** to **a** |
| `pb`        | Push the top element of **a** to **b** |

#### Rotate

| Instruction | Description                          |
| ----------- | ------------------------------------ |
| `ra`        | Shift up all elements of stack **a** |
| `rb`        | Shift up all elements of stack **b** |
| `rr`        | `ra` and `rb` simultaneously         |

#### Reverse Rotate

| Instruction | Description                            |
| ----------- | -------------------------------------- |
| `rra`       | Shift down all elements of stack **a** |
| `rrb`       | Shift down all elements of stack **b** |
| `rrr`       | `rra` and `rrb` simultaneously         |

---

## 🧠 Algorithm


<div align="center">
  
|      Algorithm      |
| :-----------------: |
| **Turkish Machine** |

</div>

The project uses the Turkish Machine sorting strategy, which is designed to efficiently handle large datasets while minimizing the number of operations.

---

## ⚙️ Compilation

Compile the program using:

`make`

This will generate:

`push_swap`

---

## 🧪 Testing Tools


<div align="center">
  
|                                Testers                                |  Author |
| :-------------------------------------------------------------------: | :-----: |
|     [Leaks Tester](https://github.com/IDC87/push_swap_leak_tester)    | `IDC87` |
| [Push Swap Visualizer](https://github.com/o-reo/push_swap_visualizer) | `o-reo` |

</div>

## 📊 Results

![Alt Text](https://github.com/Claw-gt/push_swap/blob/main/push_swap_visualizer.gif)

<div align="center">
  
|| 100 random numbers | 500 random numbers |
|--| :--------: | :------: |
| **Average Movements** | `572` :white_check_mark:| `4558` :white_check_mark:|

</div>


---

👤 Author

**clagarci**

42 Student

📜 License

This project is developed for educational purposes as part of the **42 School** curriculum.

## Introduction
Push_swap is a simple and very effective algorithm project, where you have to sort data.
You have at your disposal a set of integer values, 2 stacks and a set of instructions to manipulate both stacks.
What is your goal? Write a C program called push_swap. The program will calculate and display in the standard output the smallest program, created with the Push swap language instructions, that sorts the integers received as arguments.
