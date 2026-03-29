# 📘 Run C Programming

> 🎯 Goal: C Programming এর Basic Concepts (Hello World, Escape Sequences, Variables, Data Types, User Input, Naming Rules, Data Type Limitations) clearভাবে শেখা

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
├── input/                  # How to Take Input in C
│   └── takeInput.c
├── namingRules/
│   └── namingRules.c
├── dataTypeLimitations/
│   └── dataTypeLimit.c
└── README.md
````

---

# 🧾 File: `hello.c`

```c
#include <stdio.h>

int main() {
    printf("Hello World");
    return 0;
}
```

### 🔍 Explanation

* `#include <stdio.h>` → Standard Input Output header
* `main()` → Program execution শুরু
* `printf()` → Output দেখায়
* `return 0;` → Program successfully শেষ

---

# 🧾 File: `specialCharacter.c`

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

### 🔍 Explanation (Escape Sequences)

| Escape | Meaning      |
| ------ | ------------ |
| `\n`   | New line     |
| `\t`   | Tab space    |
| `\\`   | Backslash    |
| `\"`   | Double quote |
| `\'`   | Single quote |
| `\a`   | Alert        |
| `\b`   | Backspace    |
| `\r`   | Overwrite    |
| `\f`   | Form feed    |
| `\v`   | Vertical tab |
| `\0`   | Stop output  |

---

# 🧾 File: `variable/hello_variable.c`

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

### 🔍 Variable Theory

* Variable = data store করার **container**
* Declaration: `data_type variable_name;`
* Initialization: `data_type variable_name = value;`
* Naming Rules: number দিয়ে শুরু ❌, space ❌, `_` ✅
* Format Specifiers: `%d`, `%f`, `%c`, `%s`, `%lf`

---

# 🧾 File: `dataTypes/helloDataTypes.c`

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

### 🔍 Data Types Theory

| Data Type | Size (approx) | Example        | Description      |
| --------- | ------------- | -------------- | ---------------- |
| int       | 4 bytes       | `int a = 10;`  | Integer number   |
| float     | 4 bytes       | `float c=5.5;` | Decimal number   |
| double    | 8 bytes       | `double d;`    | Big decimal      |
| char      | 1 byte        | `char b='A';`  | Single character |

* Data Type → Variable কত ধরনের value store করবে তা define করে
* Format Specifier → Data print করার format `%d, %f, %lf, %c`

---

# 🧾 File: `input/takeInput.c`

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

### 🔍 Explanation (User Input)

* `scanf()` → user input নেওয়ার জন্য
* Syntax: `scanf("format", &variable);`
* `&` → variable এর **address** pass করতে হয়

| Variable Type | Format Specifier |
| ------------- | ---------------- |
| int           | `%d`             |
| char          | `%c`             |
| float         | `%f`             |
| double        | `%lf`            |

* Notes: `scanf(" %c", &b);` → leftover newline remove
* `%0.2f` → float value 2 decimal পর্যন্ত দেখায়

---

# 🧾 File: `namingRules/namingRules.c`

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

### 🔍 Rules of Naming Variables in C

1. Variable name **letters বা underscore `_` দিয়ে শুরু হবে**
2. Variable name **letters, digits, underscore** থাকতে পারবে
3. Variable name এ **spaces, special characters, keywords** ব্যবহার করা যাবে না
4. Variable name **case-sensitive** (e.g., `a` ≠ `A`)
5. Descriptive name ব্যবহার করা ভালো (example: `totalScore`, `first_name`)

---

# 🧾 File: `dataTypeLimitations/dataTypeLimit.c`

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

### 🔍 Data Types Limitation in C

* Integer overflow → value range exceed করলে garbage value বা overflow হয়
* Float/Double limitation → precision limited, very big number approximate হবে
* Data Type Size → variable কত value store করতে পারবে তা নির্ধারণ করে

| Data Type | Range (approx)                       |
| --------- | ------------------------------------ |
| int       | -2,147,483,648 to 2,147,483,647      |
| float     | ±3.4e38 (7 decimal digits precision) |
| double    | ±1.7e308 (15 decimal digits)         |
| char      | -128 to 127                          |

---

# ▶️ How to Compile & Run

```bash
gcc hello.c
gcc specialCharacter.c
gcc variable/hello_variable.c
gcc dataTypes/helloDataTypes.c
gcc input/takeInput.c
gcc namingRules/namingRules.c
gcc dataTypeLimitations/dataTypeLimit.c

a.exe
```

---

# 🧠 Final Summary

* `main()` → program execution শুরু
* `printf()` → output দেখায়
* `scanf()` → user input নেওয়া
* Escape sequences → formatting control
* Variable → data store
* Data Type → variable এর type define করে
* Naming Rules → variable name define করার নিয়ম
* Data Type Limitation → variable কত বড় value store করতে পারবে তা নির্ধারণ করে

---

✨ **C Programming Basics + Escape Sequences + Variables + Data Types + User Input + Naming Rules + Data Type Limitations Completed ✅ 🚀**
