# 📘 Run C Programming

> 🎯 Goal: Basic C Programming (Hello World, Escape Sequences, Variables) clearভাবে শিখা

---

## 📁 Project Structure

```id="ps8x2a"
Run C Programming/
 ├── hello.c
 ├── specialCharacter.c
 ├── variable/
 │    └── hello_variable.c
 └── README.md
```

---

# 🧾 File: `hello.c`

```c id="c1k9pz"
#include <stdio.h>

int main() {
    printf("Hello World");
    return 0;
}
```

---

## 🔍 Explanation (hello.c)

### 🔹 `#include <stdio.h>`

* Standard Input Output header
* `printf`, `scanf` use করার জন্য লাগে

### 🔹 `main()`

* Program এখান থেকে শুরু হয়

### 🔹 `printf()`

* Output দেখায়

### 🔹 `return 0;`

* Program successfully শেষ

---

# 🧾 File: `specialCharacter.c`

```c id="f3l2dw"
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

---

## 🔍 Explanation (Escape Sequences)

### 🔹 Escape Sequence কি?

👉 `\` দিয়ে শুরু হয় এমন special character
👉 output control করার জন্য ব্যবহার হয়

---

### 🔹 Most Used

| Escape | Meaning      |
| ------ | ------------ |
| `\n`   | New line     |
| `\t`   | Tab space    |
| `\\`   | Backslash    |
| `\"`   | Double quote |
| `\'`   | Single quote |

---

### 🔹 Others

| Escape | Meaning      |
| ------ | ------------ |
| `\a`   | Alert        |
| `\b`   | Backspace    |
| `\r`   | Overwrite    |
| `\f`   | Form feed    |
| `\v`   | Vertical tab |
| `\0`   | Stop output  |

---

# 🧾 File: `variable/hello_variable.c`

```c id="q9x4bn"
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

---

## 🔍 Variable Theory

### 🔹 Variable কি?

👉 Variable হলো একটি **container (box)**
👉 যেখানে data store করা হয়

---

### 🔹 Declaration

```id="u2m8kd"
int a;
float b;
char c;
```

---

### 🔹 Initialization

```id="r5n1xp"
int a = 10;
```

---

### 🔹 Data Types

| Type   | Example |
| ------ | ------- |
| int    | 10      |
| float  | 5.5     |
| double | 10.123  |
| char   | 'A'     |

---

### 🔹 Naming Rules

* number দিয়ে শুরু করা যাবে না ❌
* space দেওয়া যাবে না ❌
* `_` use করা যাবে ✅

---

### 🔹 Format Specifiers

| Specifier | Meaning |
| --------- | ------- |
| `%d`      | integer |
| `%f`      | float   |
| `%c`      | char    |
| `%s`      | string  |
| `%lf`     | double  |

---

# ▶️ How to Run

### 🔸 Compile

```id="n4k7qs"
gcc hello.c
gcc specialCharacter.c
gcc variable/hello_variable.c
```

---

### 🔸 Run

```id="v8t2yz"
a.exe
```

---

# 🧠 Final Summary

* C program `main()` থেকে শুরু
* `printf()` দিয়ে output
* Escape sequence দিয়ে formatting
* Variable দিয়ে data store

---

✨ **C Programming Basics Completed 🚀**
