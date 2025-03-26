# Philosophers - Dining Philosophers Problem Simulation

A simulation of the classic dining philosophers problem, implemented in C to explore concepts of multithreading, process synchronization, and avoiding deadlocks.

---

## 🧠 What It Does

- Simulates philosophers who alternately **eat**, **think**, and **sleep**.
- Manages resource allocation (forks) to prevent deadlocks and ensure proper synchronization.
- Provides options to configure the number of philosophers and timing parameters.
- No data races, memory leaks.

---

## ⚙️ How to Run

1. **Compile the Program**:
   ```bash
   make
   ```

2. **Execute the Simulation**:
   ```bash
   ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
   ```
   - `number_of_philosophers`: Total number of philosophers (and forks).
   - `time_to_die`: Time (in milliseconds) a philosopher can remain without eating before dying.
   - `time_to_eat`: Time (in milliseconds) a philosopher spends eating.
   - `time_to_sleep`: Time (in milliseconds) a philosopher spends sleeping.
   - `number_of_times_each_philosopher_must_eat` (optional): If specified, simulation ends when each philosopher has eaten this many times.

---

## 📦 Features

- ✅ **Thread Management**: Utilizes threads to represent each philosopher.
- ✅ **Mutex Synchronization**: Implements mutexes to handle fork access and prevent data races.
- ✅ **Configurable Parameters**: Allows customization of philosopher count and timing settings.
- ✅ **Robust Error Handling**: Gracefully manages invalid inputs and system errors.

---

## 🧰 Tech Stack

- **Language**: C
- **Concurrency**: POSIX Threads (pthreads)
- **Synchronization**: Mutexes
- **Build System**: `Makefile`

---

## 🏗️ Room for Improvements

- [ ] **Graphical Visualization**: Implement a GUI to visualize philosopher states in real-time.
- [ ] **Dynamic Adjustment**: Allow dynamic changes to parameters during simulation.
- [ ] **Enhanced Logging**: Provide detailed logs for analysis and debugging.

---

## ⚠️ Known Limitations

- **Resource Constraints**: Performance may degrade with a very high number of philosophers due to system limitations.
- **Simplified Assumptions**: Assumes ideal conditions; real-world thread scheduling may introduce variability.

---