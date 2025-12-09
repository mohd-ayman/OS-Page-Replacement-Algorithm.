# Efficient Page Replacement Algorithm Simulator

## Project Overview
This project is a CLI-based simulation tool designed to demonstrate and compare the efficiency of various **Page Replacement Algorithms** used in Operating Systems memory management. It visualizes how pages are swapped in and out of memory frames and calculates the **Hit Ratio** and **Page Faults** for each algorithm.

## ⚙️ Algorithms Implemented
1.  **FIFO (First-In, First-Out):** Replaces the oldest page in memory.
2.  **LRU (Least Recently Used):** Replaces the page that hasn't been used for the longest time.
3.  **Optimal:** Replaces the page that will not be used for the longest duration in the future (theoretical benchmark).

## 🛠️ Technologies Used
* **Language:** C++ (Standard Template Library)
* **Tools:** VS Code, Git/GitHub


## 📊 Sample Output
The program generates a step-by-step visual table in the terminal:

```text
| Step | Page |  F1 |  F2 |  F3 | Status |
|    1 |    7 |   7 |   - |   - |   Miss |
|    2 |    0 |   7 |   0 |   - |   Miss |
|    3 |    1 |   7 |   0 |   1 |   Miss |
|    4 |    2 |   2 |   0 |   1 |   Miss |
...
Total Page Faults: 7
Hit Ratio: 25.00%
