# 📘 Run C Programming

## 📁 Project Structure

```
Run C Programming/
 ├── hello.c
 ├── specialCharacter.c
 └── README.md
```

---

## 🧾 File: `hello.c`

```c
#include <stdio.h>

int main() {
    printf("Hello World");
    return 0;
}
```

---

## 🔍 Code Explanation (hello.c)

### 🔹 `#include <stdio.h>`

* এটি একটি **header file**
* এর পূর্ণরূপ 👉 **Standard Input Output**
* `printf`, `scanf` এর মতো function use করার জন্য লাগে

---

### 🔹 `int main()`

* Program এখান থেকে শুরু হয়
* এটাকে **main function** বলা হয়

---

### 🔹 `printf("Hello World");`

* Screen এ output দেখায়

---

### 🔹 `return 0;`

* Program successfully শেষ হয়েছে বোঝায়

---

## 🧾 File: `specialCharacter.c`

```c
#include<stdio.h>

int main(){

    // Escape Sequences Example
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

    // Format Specifiers
    int a = 10;
    float b = 5.5;
    char c = 'A';
    char str[] = "Hello";
    double d = 10.12345;
    long int li = 123456;
    long long int lli = 1234567890;

    printf("Integer: %d\n", a);
    printf("Float: %f\n", b);
    printf("Character: %c\n", c);
    printf("String: %s\n", str);
    printf("Pointer: %p\n", &a);
    printf("Unsigned: %u\n", a);
    printf("Hexadecimal: %x\n", a);
    printf("Octal: %o\n", a);
    printf("Long: %ld\n", li);
    printf("Double: %lf\n", d);
    printf("Long Long: %lld\n", lli);

    return 0;
}
```

---

## 🔍 Code Explanation (specialCharacter.c)

### 🔹 Escape Sequences

* `\n` → new line
* `\t` → tab space
* `\\` → backslash
* `\"` → double quote
* `\'` → single quote
* `\a` → alert sound
* `\b` → backspace
* `\r` → carriage return
* `\f` → form feed
* `\v` → vertical tab
* `\0` → null character

---

### 🔹 Format Specifiers

* `%d` → integer
* `%f` → float
* `%c` → character
* `%s` → string
* `%p` → pointer
* `%u` → unsigned integer
* `%x` → hexadecimal
* `%o` → octal
* `%ld` → long
* `%lf` → double
* `%lld` → long long

---

## ▶️ How to Run

### 🔸 Step 1: Open Terminal / CMD

### 🔸 Step 2: Compile

```
gcc hello.c
gcc specialCharacter.c
```

---

### 🔸 Step 3: Run

```
a.exe
```

---

## 🧠 Summary

* `stdio.h` = Standard Input Output
* `main()` = Program start point
* `printf()` = Output দেখায়
* Escape sequence = special output control
* Format specifier = data print করার format

---

✨ **Basic C Programming + Special Characters Completed!**
