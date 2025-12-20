# LRU Cache in C++

A production-style implementation of an **LRU (Least Recently Used) Cache** in modern C++, designed with clean architecture principles and fully tested using GoogleTest.

---

## 🚀 Features

- **O(1) get and put operations**
- Clean separation between cache storage and eviction logic
- Eviction handled via **Strategy Pattern**
- Modern C++ practices (RAII, smart pointers)
- Comprehensive unit tests
- CMake-based project structure (application + tests)

---

## 🧠 Design Overview

The cache is composed of two main parts:

- **LRUCache**  
  Responsible for:
  - Managing key–value storage
  - Enforcing capacity constraints
  - Delegating eviction decisions

- **Eviction Policy (Strategy Pattern)**  
  - Defined via an abstract interface (`IEvictionPolicy`)
  - Implemented as `LRUPolicy`
  - Tracks access order and determines eviction candidates

This design allows the eviction strategy to be replaced (e.g. FIFO, LFU) without modifying the cache logic.

---

## ⚙️ Data Structures Used

To guarantee constant-time operations:

- `std::unordered_map` for fast key lookup
- `std::list` for maintaining usage order (MRU ↔ LRU)
- Iterators stored in a hash map for O(1) updates

---

## 🧪 Testing

All core behaviors are covered by unit tests using **GoogleTest**, including:

- Cache hit and miss behavior
- Updating existing keys
- Correct LRU eviction
- Access-based MRU updates
- Manual key removal (`erase`)

Tests are built and run as a separate CMake target.

---

## 🛠️ Build & Run

### Requirements
- C++17 or newer
- CMake 3.20+
- A C++ compiler (GCC / Clang / MSVC)

### Build
```bash
cmake -S . -B build
cmake --build build
---

### 📁 Project Structure
.
├── include/
│   ├── LRUCache.h
│   ├── IEvictionPolicy.h
│   └── LRUPolicy.h
├── src/
│   ├── LRUCache.cpp
│   └── LRUPolicy.cpp
├── tests/
│   └── tests_LRU.cpp
├── CMakeLists.txt
└── README.md
---

### 📌 Key Learnings

- Applying object-oriented design and runtime polymorphism in C++
- Using Strategy Pattern to decouple behavior
- Designing efficient data structures with strict complexity guarantees
- Writing meaningful unit tests for non-trivial logic
- Managing a clean, multi-target CMake project
