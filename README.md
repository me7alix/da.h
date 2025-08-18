# da.h — Lightweight Header-Only Dynamic Array Library for C

`da.h` is a minimal, header-only library for managing dynamic arrays in C.  
It provides simple macros to handle resizable arrays without manual capacity tracking or boilerplate code.

## Features

- Single-header implementation
- No external dependencies
- Automatic resizing (grow/shrink)
- Familiar API for C developers
- Optional debug safety checks

## Installation

Simply include the header in your project:

```c
#include "da.h"
````

Optionally, define `DA_DEBUG` before including it to enable runtime checks:

```c
#define DA_DEBUG
#include "da.h"
```

## Usage

### Define a Dynamic Array

You can define your own struct:

```c
typedef struct {
    int *items;
    size_t count;
    size_t capacity;
} IntArray;
```

Or use the provided macro:

```c
da(int) my_array = {0};
```

### Basic Operations

```c
da_append(my_array, 42);          // Append element
da_insert(my_array, 0, 13);       // Insert element at index
int x = da_get(my_array, 1);      // Access element at index
int last = da_last(my_array);     // Access the last element
int removed = da_pop(my_array);   // Remove and return the last element

da_unordered_remove(my_array, 0); // Remove element fast (order not preserved)
da_ordered_remove(my_array, 0);   // Remove element preserving order

da_free(my_array);                // Release memory
```

### Automatic Capacity Management

* Array grows when full (capacity × 2)
* Array shrinks when usage falls below 25%

### Debugging

Define `DA_DEBUG` to enable runtime checks such as:

* Out-of-bounds access
* Pop from empty array

Error messages are printed to `stderr` and abort the program.
For release builds, omit `DA_DEBUG` to remove these checks.

## License

MIT License
