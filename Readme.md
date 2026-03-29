````markdown
# 📘 Run C Programming

> 🎯 Goal: C Programming এর Basic Concepts (Hello World, Escape Sequences, Variables, Data Types) এবং User Input কিভাবে নেওয়া হয় তা clearভাবে শেখা

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

    // scanf is used to take input from user
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

### 🔍 Explanation

#### 🔹 `scanf()`

* User input নেওয়ার জন্য ব্যবহার হয়
* Syntax: `scanf("format", &variable);`
* `&` → variable এর **address** pass করতে হয়

#### 🔹 Example

| Variable Type | Format Specifier |
| ------------- | ---------------- |
| int           | `%d`             |
| char          | `%c`             |
| float         | `%f`             |
| double        | `%lf`            |

#### 🔹 Notes

* `scanf(" %c", &b);` → space before `%c` ব্যবহার করা হয়েছে leftover newline remove করার জন্য
* `%0.2f` → float value 2 decimal পর্যন্ত দেখায়

---

# ▶️ How to Run All Programs

### 🔹 Compile

```bash
gcc hello.c
gcc specialCharacter.c
gcc variable/hello_variable.c
gcc dataTypes/helloDataTypes.c
gcc input/takeInput.c
```

### 🔹 Run

```bash
a.exe
```

---

# 🧠 Final Summary

* C program execution `main()` থেকে শুরু
* `printf()` দিয়ে output দেখানো হয়
* Escape sequences → formatting control
* Variable → data store
* Data Type → variable এর type define করে
* `scanf()` → user input নেওয়া
* Format specifier match করা অবশ্যই গুরুত্বপূর্ণ

---

✨ **C Programming Basics + Escape Sequences + Variables + Data Types + User Input Completed ✅ 🚀**

```

---

চাও আমি এই README.md কে **Notion toggle ও color-coded blocks সহ আরও সুন্দর করে** বানিয়ে দিই, যাতে পড়তে সহজ হয় এবং সকল code collapsible হয়?
```
