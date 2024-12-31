
# Philosophers - Dining Table Simulation  
![Philosophers Banner](https://github.com/user-attachments/assets/56960126-b10c-414d-818b-3422e5fbb609)
*A project simulating the famous "Dining Philosophers Problem" to explore concurrency, threads, and synchronization.*  

---

## Overview  

The **philosophers** project is a fascinating challenge that involves simulating a group of philosophers dining at a table while avoiding deadlocks and ensuring smooth execution of concurrent operations. This project is part of the 1337 School curriculum and focuses on concepts like **multithreading**, **mutexes**, and **race conditions**.  

---

## Key Objectives  

- Understand and implement **threads** and **processes** for parallelism.  
- Master the use of **mutexes** and other synchronization tools to prevent race conditions and deadlocks.  
- Explore real-time resource sharing and allocation problems.  

---

## Features  

- Simulates a table with philosophers and forks.  
- Philosophers perform three key actions: **eating**, **thinking**, and **sleeping**.  
- Prevents deadlocks by managing access to shared resources (forks).  
- Implements efficient synchronization using mutexes.  

---

## The Problem  

The problem involves `n` philosophers sitting around a circular dining table. Each philosopher alternates between thinking, eating, and sleeping. However:  

1. Each philosopher can only eat if they have access to the two forks adjacent to them.  
2. Only one philosopher can hold a fork at a time.  
3. If all philosophers attempt to pick up their forks simultaneously, a deadlock can occur.  

The goal is to implement a solution that prevents deadlocks and ensures all philosophers can eventually eat.  

---

## Project Structure  

| File                    | Description                                      |  
|-------------------------|--------------------------------------------------|  
| `philosophers.c`        | Main simulation logic for philosophers' actions. |  
| `threads.c`             | Functions for creating and managing threads.     |  
| `utils.c`               | Utility functions for timing and synchronization.|  
| `philosophers.h`        | Header file with definitions and function prototypes. |  
| `Makefile`              | Script to compile the project.                   |  

---

## Usage  

1. **Clone the repository**:  
   ```bash  
   git clone https://github.com/mkatfi/philosophers.git  
   cd philosophers  
   ```  

2. **Compile the program**:  
   ```bash  
   make  
   ```  

3. **Run the simulation**:  
   ```bash  
   ./philosophers [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat (optional)]  
   ```  

   - `number_of_philosophers`: Number of philosophers at the table.  
   - `time_to_die`: Time (in ms) before a philosopher dies if they don’t start eating.  
   - `time_to_eat`: Time (in ms) it takes for a philosopher to eat.  
   - `time_to_sleep`: Time (in ms) a philosopher spends sleeping.  
   - `number_of_times_each_philosopher_must_eat`: Optional parameter to stop the simulation when each philosopher has eaten this many times.  

4. **Example**:  
   ```bash  
   ./philosophers 5 800 200 200  
   ```  

---

## Implementation Details  

### Threads  

Each philosopher is represented by a thread, and the simulation runs concurrently. Threads execute actions like picking up forks, eating, thinking, and sleeping.  

### Mutexes  

Forks are represented as mutexes to ensure that only one philosopher can hold a fork at a time.  

### Synchronization  

The simulation ensures that:  
- No two philosophers hold the same fork simultaneously.  
- Deadlocks are avoided using appropriate locking and unlocking strategies.  

---

## Challenges  

- **Deadlock Prevention**:  
  Implemented strategies to avoid circular waiting among philosophers.  
- **Race Conditions**:  
  Used mutexes to ensure proper access to shared resources.  
- **Performance**:  
  Optimized thread synchronization to avoid unnecessary delays.  

---

## Testing  

### Test Cases  

1. **Basic Simulation**:  
   ```bash  
   ./philosophers 5 800 200 200  
   ```  
   Observes five philosophers alternating between eating, thinking, and sleeping without issues.  

2. **Stress Test**:  
   ```bash  
   ./philosophers 200 800 200 200  
   ```  
   Handles a large number of philosophers without performance degradation.  

3. **Edge Cases**:  
   - One philosopher:  
     ```bash  
     ./philosophers 1 800 200 200  
     ```  
   - Tight timing constraints:  
     ```bash  
     ./philosophers 5 60 50 50  
     ```  
