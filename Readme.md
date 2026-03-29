# 📘 Run C Programming

> 🎯 Goal: C Programming এর Basic Concepts (Hello World, Escape Sequences, Variables, Data Types) clearভাবে শিখা

---

## 📁 Project Structure

```id="ps8x2a"
Run C Programming/
 ├── hello.c
 ├── specialCharacter.c
 ├── variable/
 │    └── hello_variable.c
 ├── dataTypes/
 │    └── helloDataTypes.c
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

### 🔍 Explanation

* `#include <stdio.h>` → Standard Input Output header
* `main()` → Program execution শুরু
* `printf()` → Output দেখায়
* `return 0;` → Program successfully শেষ

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

### 🔍 Variable Theory

* Variable = data store করার **container**
* Declaration: `data_type variable_name;`
* Initialization: `data_type variable_name = value;`
* Naming Rules: number দিয়ে শুরু ❌, space ❌, `_` ✅
* Format Specifiers: `%d`, `%f`, `%c`, `%s`, `%lf`

---

# 🧾 File: `dataTypes/helloDataTypes.c`

```c id="dt1"
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

# ▶️ How to Run

### 🔹 Compile

```id="compile"
gcc hello.c
gcc specialCharacter.c
gcc variable/hello_variable.c
gcc dataTypes/helloDataTypes.c
```

### 🔹 Run

```id="run"
a.exe
```

---

# 🧠 Final Summary

* C program execution `main()` থেকে শুরু
* `printf()` দিয়ে output দেখানো হয়
* Escape sequences → formatting control
* Variable → data store
* Data Type → variable এর type define করে

---

✨ **C Programming Basics + Escape + Variables + Data Types Completed 🚀**
