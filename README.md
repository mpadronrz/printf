# 🖨️ ft_printf — Custom Printf Implementation

![C](https://img.shields.io/badge/Language-C-blue) ![42 Project](https://img.shields.io/badge/42%20Project-ft_printf-orange) ![Grade](https://img.shields.io/badge/Grade-125%2F100-brightgreen)

**ft_printf** is a 42 project where I implemented a custom version of the C `printf` function.
It was **peer-graded**, and I received a **125/100**, including the bonus part.

This project allowed me to deepen my understanding of **C programming, string manipulation, and variadic functions**.

---

## 📑 Table of Contents

* [About the Project](#about-the-project)
* [Features](#features)
* [Compilation](#compilation)
* [Execution](#execution)
* [How It Works](#how-it-works)

---

### 🏫 About the Project <a id="about-the-project"></a>

**ft_printf** is part of the **42 curriculum**, focusing on implementing a custom version of the standard `printf` function in C.
It reinforces key **programming concepts**:

* Variadic functions and argument handling (`stdarg.h`)
* String parsing and formatting
* Memory management and modular code design

> Peer-graded at **42Barcelona** with a final grade of **125/100**, including the bonus.

---

### 🚀 Features <a id="features"></a>

**Conversion specifiers supported:**

| Specifier   | Description                                                   |
| ----------- | ------------------------------------------------------------- |
| `%c`        | Prints a single character                                     |
| `%s`        | Prints a string                                               |
| `%p`        | Prints a pointer in hexadecimal                               |
| `%d` / `%i` | Prints a signed decimal integer                               |
| `%u`        | Prints an unsigned decimal integer                            |
| `%x` / `%X` | Prints an unsigned integer in lowercase/uppercase hexadecimal |
| `%%`        | Prints a literal percent sign                                 |

**Bonus features included:**

* Field width (minimum field width / MFW)
* Precision for numeric and string outputs
* Flags: `-` (left-justify), `0` (zero-padding), `#` (prefix for hex), `+` (force sign), space (space for positive numbers)
* Handles multiple combinations of width, precision, and flags
* **Reference:** For full details about standard `printf` behavior, see `man 3 printf`

This allows the **bonus version** of `ft_printf` to behave like a reasonably complete version of the standard `printf`.

---

### ⚙️ Compilation <a id="compilation"></a>

The repository includes a **Makefile** that compiles the library:

* `make` or `make all` → builds the **mandatory version** (`libftprintf.a`)

  * Only parses conversion specifiers without flags, width, or precision
* `make bonus` → builds the **bonus version** (`libftprintf.a`)

  * Supports all bonus flags, precision, and minimum field width (MFW)

**Usage:**

1. Include the header in your project:

```c
#include "ft_printf.h"       // mandatory version
#include "ft_printf_bonus.h" // bonus version
```

2. Link your project with `libftprintf.a`:

```bash
gcc your_file.c -L. -lftprintf -o your_program
```

---

### 🕹️ Execution <a id="execution"></a>

Example usage:

```c
ft_printf("Hello %s! You have %d pending evaluations.\n", "mapadron", 5);
ft_printf("Number with width and flags: %+08d\n", 42); // bonus: prints "+00000042"
ft_printf("Hexadecimal number: %#x\n", 255);                  // bonus: prints "0xff"
ft_printf("String precision: %.5s\n", "HelloWorld");  // bonus: prints "Hello"
```

* Works with all mandatory conversion specifiers.
* Bonus version supports **flags, width, and precision**.

---

### 🧠 How It Works <a id="how-it-works"></a>

* Parses the format string character by character
* Uses **variadic functions (`va_list`)** to access arguments dynamically
* Handles each conversion specifier separately
* Applies **bonus formatting flags, width, and precision** (if using bonus version)
* Prints the formatted string to **standard output**
* Modular helper functions manage different types, memory, and formatting logic
