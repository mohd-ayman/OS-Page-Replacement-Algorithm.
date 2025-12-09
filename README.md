📖 Project Overview.
This project is a C++ based simulation tool designed to visualize and analyze the efficiency of various Page Replacement Algorithms used in Operating Systems.

In a system with limited physical memory (Frames), the OS must decide which page to swap out when a new page (Page Fault) needs to be loaded. This simulator implements the three most fundamental algorithms to demonstrate this decision-making process:

FIFO (First-In, First-Out)

LRU (Least Recently Used)

Optimal (Future Lookahead)

The tool provides a step-by-step visual table of memory states, highlights Hits vs. Misses, and calculates performance metrics like Hit Ratio and Total Page Faults.

Key Features.
Menu-Driven Interface: User-friendly CLI to select and run specific algorithms.

Dynamic Inputs: Supports custom input for the number of Frames and Reference Strings.

Visual Simulation: Displays the content of memory frames at every step of execution.

Performance Metrics: Automatically calculates and compares the efficiency (Hit Ratio) of different algorithms.

Comparative Mode: "Run All" feature to compare FIFO, LRU, and Optimal side-by-side.
