# 📘 Run C Programming

> 🎯 Goal: C Programming এর Basic Concepts (Hello World, Escape Sequences, Variables, Data Types, User Input, Naming Rules, Data Type Limitations, Operators) clearভাবে শেখা

---

## 📁 Project Structure

```text
Run C Programming/
├── hello.c
├── specialCharacter.c
├── variable/
│   └── hello_variable.c
├── dataTypes/
│   └── helloDataTypes.c
├── input/
│   └── takeInput.c
├── namingRules/
│   └── namingRules.c
├── dataTypeLimitations/
│   └── dataTypeLimit.c
├── operators/
│   └── operators.c
└── README.md
```

---

## 🚀 Getting Started

To compile and run any of the C files, use the following commands in your terminal:

```bash
# Compile a specific file
gcc filename.c

# Run the compiled program (on Windows)
a.exe

# On Linux/Mac, run the compiled output
./a.out
```

---

## 📄 File Explanations & Code

### 1. `hello.c` - Your First C Program

```c
#include <stdio.h>

int main() {
    printf("Hello World");
    return 0;
}
```

#### 🔍 Explanation
- `#include <stdio.h>` → Includes the Standard Input Output header file for functions like `printf()`.
- `int main()` → The main function where program execution begins.
- `printf()` → A function to display output on the console.
- `return 0;` → Indicates that the program ended successfully.

---

### 2. `specialCharacter.c` - Escape Sequences

```c
#include<stdio.h>

int main(){
    printf("New Line Example:\nHello\nWorld\n\n");
    printf("Tab Example:\tHello\tWorld\n\n");

    printf("Backslash: \\\n");
    printf("Double Quote: \"Hello\"\n");
    printf("Single Quote: \'A\'\n\n");

    printf("Alert Sound: \a\n");
    printf("Backspace: ABC\bD\n");
    printf("Carriage Return: Hello\rWorld\n");
    printf("Form Feed: Hello\fWorld\n");
    printf("Vertical Tab: Hello\vWorld\n");
    printf("Null Character: Hello\0World\n\n");
    printf("Percentage: 100%%\n\n");

    return 0;
}
```

#### 🔍 Explanation (Escape Sequences)

| Escape | Meaning      | Description                              |
| ------ | ------------ | ---------------------------------------- |
| `\n`   | New line     | Moves the cursor to the beginning of the next line. |
| `\t`   | Tab space    | Inserts a horizontal tab.                |
| `\\`   | Backslash    | Prints a single backslash character.     |
| `\"`   | Double quote | Prints a double quote character.         |
| `\'`   | Single quote | Prints a single quote character.         |
| `\a`   | Alert        | Produces a beep sound (may not work in all environments). |
| `\b`   | Backspace    | Moves the cursor one position back.      |
| `\r`   | Carriage Return | Moves the cursor to the beginning of the current line. |
| `\f`   | Form feed    | Moves the cursor to the next logical page (often a new page). |
| `\v`   | Vertical tab | Moves the cursor vertically.             |
| `\0`   | Null character | Acts as a string terminator; output stops here. |
| `%%`   | Percentage   | Prints a single percent sign.            |

---

### 3. `variable/hello_variable.c` - Variables

```c
#include<stdio.h>

int main(){
    int a = 10;
    char b = 'A';
    float c = 5.5;
    double d = 10.12345;

    printf("Integer: %d\n", a);
    printf("Character: %c\n", b);
    printf("Float: %f\n", c);
    printf("Double: %lf\n", d);

    return 0;
}
```

#### 🔍 Variable Theory
- **Variable** → A named storage location in memory to hold data.
- **Declaration**: `data_type variable_name;`
- **Initialization**: `data_type variable_name = value;`
- **Naming Rules**:
    - Can start with a letter or underscore (`_`).
    - Can contain letters, digits, and underscores.
    - Cannot start with a digit.
    - No spaces or special characters (except `_`).
    - Cannot be a C keyword (e.g., `int`, `return`).
- **Format Specifiers**:
    - `%d` or `%i` for `int`
    - `%f` for `float`
    - `%c` for `char`
    - `%s` for strings
    - `%lf` for `double`

---

### 4. `dataTypes/helloDataTypes.c` - Data Types

```c
#include<stdio.h>

int main(){
    int a = 10;
    char b = 'A';
    float c = 5.250;

    printf("Integer : %d\n", a);
    printf("Character : %c\n", b);
    printf("Float : %f\n", c);

    return 0;
}
```

#### 🔍 Data Types Theory
A **data type** defines the type of data a variable can store and the operations that can be performed on it.

| Data Type | Size (approx) | Format Specifier | Example        | Description                |
| --------- | ------------- | ---------------- | -------------- | -------------------------- |
| `int`     | 2 or 4 bytes  | `%d`, `%i`       | `int a = 10;`  | Stores integer numbers.    |
| `float`   | 4 bytes       | `%f`             | `float c = 5.5;` | Stores single-precision decimal numbers. |
| `double`  | 8 bytes       | `%lf`            | `double d;`    | Stores double-precision decimal numbers. |
| `char`    | 1 byte        | `%c`             | `char b='A';`  | Stores a single character. |

---

### 5. `input/takeInput.c` - User Input

```c
#include<stdio.h>

int main(){
    int a;
    printf("Enter an integer: ");
    scanf("%d", &a);

    char b;
    printf("Enter a character: ");
    scanf(" %c", &b);

    float c;
    printf("Enter a float: ");
    scanf(" %f", &c);

    printf("You Entered Integer: %d\n", a);
    printf("You Entered Character: %c\n", b);
    printf("You Entered Float: %0.2f\n", c);

    return 0;
}
```

#### 🔍 Explanation (User Input)
- `scanf()` → A function to read formatted input from the user.
- **Syntax**: `scanf("format", &variable_name);`
- `&` → The **address-of operator**. It is required to pass the memory address of the variable where the input will be stored.
- `" %c"` → The space before `%c` is used to consume any leftover newline characters from previous inputs, preventing it from being skipped.
- `%0.2f` → Formats the `float` value to show only 2 decimal places.

| Variable Type | Format Specifier |
| ------------- | ---------------- |
| int           | `%d`             |
| char          | `%c`             |
| float         | `%f`             |
| double        | `%lf`            |

---

### 6. `namingRules/namingRules.c` - Naming Rules in Practice

```c
#include<stdio.h>

int main(){
    int age = 25;
    int _salary = 5000;
    int total_score1 = 100;

    printf("Age: %d\n", age);
    printf("Salary: %d\n", _salary);
    printf("Total Score: %d\n", total_score1);

    return 0;
}
```

#### 🔍 Summary of Naming Rules
1.  Variable name **must start with a letter or underscore (`_`)**.
2.  It can contain **letters, digits, and underscores**.
3.  **No spaces, special characters (like `@`, `#`, `$`), or C keywords** are allowed.
4.  C is **case-sensitive**, so `age`, `Age`, and `AGE` are all different.
5.  Use **descriptive names** for better code readability (e.g., `studentAge`, `totalMarks`).

---

### 7. `dataTypeLimitations/dataTypeLimit.c` - Data Type Limitations

```c
#include<stdio.h>

int main(){
    int a = 2147483647;   // max int
    int b = 2147483648;   // overflow
    float c = 3.4028235e38; // max float
    double d = 1.7976931348623157e308; // max double

    printf("Int Max: %d\n", a);
    printf("Int Overflow Example: %d\n", b);
    printf("Float Max: %f\n", c);
    printf("Double Max: %lf\n", d);

    return 0;
}
```

#### 🔍 Data Type Limitations
Every data type has a limited range. Exceeding this range causes **overflow**, which results in unexpected or garbage values.

| Data Type | Range (approx)                       | Notes                                   |
| --------- | ------------------------------------ | --------------------------------------- |
| `int`     | -2,147,483,648 to 2,147,483,647      | For a standard 4-byte `int`.            |
| `float`   | ±3.4e38                              | Has about 7 decimal digits of precision.|
| `double`  | ±1.7e308                             | Has about 15 decimal digits of precision.|
| `char`    | -128 to 127                          | For signed `char`.                      |

---

### 8. `operators/operators.c` - Operators

```c
#include<stdio.h>

int main(){

    int a = 10, b = 3;

    // Arithmetic Operators
    printf("Arithmetic:\n");
    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d\n", a / b);
    printf("a %% b = %d\n\n", a % b);

    // Relational Operators
    printf("Relational:\n");
    printf("a == b : %d\n", a == b);
    printf("a != b : %d\n", a != b);
    printf("a > b  : %d\n", a > b);
    printf("a < b  : %d\n", a < b);
    printf("a >= b : %d\n", a >= b);
    printf("a <= b : %d\n\n", a <= b);

    // Logical Operators
    printf("Logical:\n");
    printf("(a > 5 && b < 5) : %d\n", (a > 5 && b < 5));
    printf("(a > 5 || b > 5) : %d\n", (a > 5 || b > 5));
    printf("!(a > b) : %d\n\n", !(a > b));

    // Bitwise Operators
    printf("Bitwise:\n");
    printf("a & b = %d\n", a & b);
    printf("a | b = %d\n", a | b);
    printf("a ^ b = %d\n", a ^ b);
    printf("a << 1 = %d\n", a << 1);
    printf("a >> 1 = %d\n\n", a >> 1);

    // Assignment Operators
    int x = 5;
    printf("Assignment:\n");
    x += 2;
    printf("x += 2 : %d\n", x);
    x -= 1;
    printf("x -= 1 : %d\n\n", x);

    // Increment & Decrement
    int y = 5;
    printf("Increment/Decrement:\n");
    printf("y++ = %d\n", y++);
    printf("After y++ : %d\n", y);
    printf("++y = %d\n\n", ++y);

    // Conditional Operator
    int max = (a > b) ? a : b;
    printf("Conditional:\n");
    printf("Max = %d\n\n", max);

    // Comma Operator
    int m;
    m = (a = 2, b = 4, a + b);
    printf("Comma:\n");
    printf("m = %d\n\n", m);

    // sizeof Operator
    printf("Sizeof:\n");
    printf("Size of int = %lu bytes\n\n", sizeof(int));

    return 0;
}
```

#### 🔍 Operators Theory
Operators are symbols that perform operations on operands (variables and values).

| Category | Operators | Description |
| :--- | :--- | :--- |
| **Arithmetic** | `+`, `-`, `*`, `/`, `%` | Perform mathematical calculations. |
| **Relational** | `==`, `!=`, `>`, `<`, `>=`, `<=` | Compare two values. Result is `1` (true) or `0` (false). |
| **Logical** | `&&`, `\|\|`, `!` | Combine or negate conditional expressions. |
| **Bitwise** | `&`, `\|`, `^`, `<<`, `>>` | Perform operations at the bit level. |
| **Assignment** | `=`, `+=`, `-=`, `*=`, `/=`, `%=` | Assign values to variables. |
| **Increment/Decrement** | `++`, `--` | Increase or decrease a variable's value by 1. |
| **Conditional (Ternary)** | `? :` | A shorthand for `if-else`. Syntax: `condition ? value_if_true : value_if_false`. |
| **Comma** | `,` | Allows multiple expressions to be evaluated in a single statement. |
| **`sizeof`** | `sizeof()` | Returns the size, in bytes, of a data type or variable. |

---

## 🧠 Final Summary

This guide covers the fundamental building blocks of C programming:

- **Basic Structure**: `#include`, `main()`, `printf()`, `return 0;`
- **Escape Sequences**: Using `\n`, `\t`, etc., to format output.
- **Variables & Data Types**: Storing and managing different kinds of data (`int`, `float`, `char`, `double`).
- **User Input**: Using `scanf()` to get data from the user.
- **Naming Rules**: Conventions for creating valid and readable variable names.
- **Data Type Limitations**: Understanding the range and precision of data types.
- **Operators**: Using a variety of operators to manipulate data.

✨ **C Programming Basics + Escape Sequences + Variables + Data Types + User Input + Naming Rules + Data Type Limitations + Operators Completed ✅ 🚀**