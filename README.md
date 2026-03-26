# Data Structures and Algorithms

## Overview
This repository is a collection of C and C++ projects focused on core computer science fundamentals. The code demonstrates sorting, linked list design, templates, generic programming, and pointer-based data structure implementation.

## Projects Included

### 1. Generic Heap Sort in C++
File: `generic_heapsort_cpp.cpp`

A templated heap sort implementation that can sort arrays of different data types using max-heap logic.

### 2. Generic Heap Sort in C
File: `generic_heapsort_c.c`

A C implementation of heap sort using `void*`, element sizes, and comparator functions to create generic sorting behavior similar to standard library patterns.

### 3. Integer Linked List
File: `integer_linked_list.cpp`

A custom integer linked list with operations such as insertion, popping, index-based removal, and membership checking.

### 4. Templated Linked List
File: `templated_linked_list.cpp`

A generic linked list built with C++ templates, including support for applying a function to all elements and printing list contents.

### 5. Improved Linked List Header and Test Program
Files:
- `better_linkedlist.h`
- `linked_list_test.cpp`

A more reusable linked list implementation with iterator support, queue-style operations, indexed access, and test cases demonstrating how the structure can work with integers and custom objects.

## Skills Demonstrated
- C
- C++
- Data structures
- Heap sort
- Templates
- Generic programming
- Linked lists
- Iterators
- Pointers and dynamic memory

## Why This Repo Matters
This repo shows the kind of foundational programming work that supports larger software projects. It highlights my understanding of core algorithms and the ability to build data structures from scratch in both C and C++.

## Suggested Compile Commands

### Generic Heap Sort in C++
```bash
g++ -std=c++11 generic_heapsort_cpp.cpp -o generic_heapsort_cpp
```

### Generic Heap Sort in C
```bash
gcc generic_heapsort_c.c -o generic_heapsort_c
```

### Integer Linked List
```bash
g++ -std=c++11 integer_linked_list.cpp -o integer_linked_list
```

### Templated Linked List
```bash
g++ -std=c++11 templated_linked_list.cpp -o templated_linked_list
```

### Linked List Test Program
```bash
g++ -std=c++11 linked_list_test.cpp -o linked_list_test
```

## Notes
These projects came from coursework and were cleaned up for portfolio presentation. The goal of this repo is to clearly show my experience with core data structures and algorithm implementation.
