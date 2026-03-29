# 📘 C Programming — Week 01 Summary

> 🎯 Goal: C Programming এর Basic Concepts clearভাবে শেখা (Hello World, Escape Sequences, Variables, Data Types, User Input, Naming Rules, Data Type Limitations)

---

## 🗂️ Week-01 Overview (Topics)

| Topic | Short Description | File / Folder |
| ----- | ---------------- | ------------- |
| Hello World | Basic program output | `hello.c` |
| Escape Sequences | Formatting control (\n, \t, \\, etc) | `specialCharacter.c` |
| Variables | Data store করার container | `variable/hello_variable.c` |
| Data Types | Variable এর type define করে | `dataTypes/helloDataTypes.c` |
| User Input | `scanf()` ব্যবহার করে input নেওয়া | `input/takeInput.c` |
| Naming Rules | Variable name এর নিয়মাবলী | `namingRules/namingRules.c` |
| Data Type Limitations | Primitive type limitations | `dataTypeLimitations/dataTypeLimit.c` |

---

## 1️⃣ Hello World

- **Purpose:** প্রথম program, screen এ output দেখানো  
- **File:** `hello.c`  
- **Key Points:**  
  - `#include <stdio.h>` → Standard Input Output header  
  - `main()` → Program execution start  
  - `printf()` → Output  
  - `return 0;` → Program successful exit  

---

## 2️⃣ Escape Sequences

- **Purpose:** Output format control  
- **File:** `specialCharacter.c`  
- **Most Used:**  

| Escape | Meaning      |
| ------ | ------------ |
| `\n`   | New line     |
| `\t`   | Tab space    |
| `\\`   | Backslash    |
| `\"`   | Double quote |
| `\'`   | Single quote |

- **Others:**  

| Escape | Meaning      |
| ------ | ------------ |
| `\a`   | Alert        |
| `\b`   | Backspace    |
| `\r`   | Overwrite    |
| `\f`   | Form feed    |
| `\v`   | Vertical tab |
| `\0`   | Stop output  |

---

## 3️⃣ Variables

- **Purpose:** Data store করার container  
- **File:** `variable/hello_variable.c`  
- **Declaration:** `data_type variable_name;`  
- **Initialization:** `data_type variable_name = value;`  
- **Format Specifiers:** `%d, %f, %c, %s, %lf`  

---

## 4️⃣ Data Types

- **Purpose:** Variable কত ধরনের value store করবে তা define করে  
- **File:** `dataTypes/helloDataTypes.c`  

| Type   | Size (approx) | Example | Description |
| ------ | ------------- | ------- | ----------- |
| int    | 4 bytes       | 10      | Integer     |
| float  | 4 bytes       | 5.5     | Decimal     |
| double | 8 bytes       | 10.123  | Big decimal |
| char   | 1 byte        | 'A'     | Single character |

- **Format Specifiers:** `%d, %f, %lf, %c`  

---

## 5️⃣ User Input

- **Purpose:** User থেকে data input নেওয়া  
- **File:** `input/takeInput.c`  
- **Function:** `scanf()`  
- **Syntax:** `scanf("format", &variable);`  

| Variable Type | Format Specifier |
| ------------- | ---------------- |
| int           | `%d`             |
| char          | `%c`             |
| float         | `%f`             |
| double        | `%lf`            |

**Note:**  
- `scanf(" %c", &b);` → space before `%c` removes leftover newline  
- `%0.2f` → float 2 decimal পর্যন্ত দেখায়  

---

## 6️⃣ Naming Rules

- Variable name এর নিয়মাবলী:  
  - Number দিয়ে শুরু করা যাবে না ❌  
  - Space দেওয়া যাবে না ❌  
  - `_` ব্যবহার করা যাবে ✅  
- Example: `int myVar = 10;` ✅, `int 1var;` ❌  

---

## 7️⃣ Data Type Limitations

- Primitive data types এর limitation:  

| Data Type | Size | Min Value | Max Value |
| --------- | ---- | --------- | --------- |
| int       | 4B   | -2,147,483,648 | 2,147,483,647 |
| float     | 4B   | ±1.2E-38 to ±3.4E+38 | - |
| double    | 8B   | ±2.2E-308 to ±1.8E+308 | - |
| char      | 1B   | -128       | 127 |

---

## ▶️ How to Run Week-01 Programs

```bash
gcc hello.c
gcc specialCharacter.c
gcc variable/hello_variable.c
gcc dataTypes/helloDataTypes.c
gcc input/takeInput.c
gcc namingRules/namingRules.c
gcc dataTypeLimitations/dataTypeLimit.c

a.exe
````

---

## 🧠 Week-01 Summary

* C program execution `main()` থেকে শুরু
* `printf()` → output দেখানো
* Escape sequences → formatting control
* Variable → data store
* Data Type → variable এর type define করে
* `scanf()` → user input নেওয়া
* Naming rules → valid variable naming
* Data Type limitations → primitive type max/min

---

✨ **Week-01 Completed ✅ — Full Basic C Programming Summary Ready**
