# C Programming — Quick Summary

> সব গুরুত্বপূর্ণ concept এক জায়গায়। পড়লেই মাথায় থাকবে।

---

## 01 · Program Structure

```c
#include <stdio.h>   // stdio library লোড করে (printf, scanf)

int main() {         // execution এখান থেকে শুরু
    printf("Hello"); // screen-এ print করে
    return 0;        // 0 = সফলভাবে শেষ
}
```

| `#include` | Library যোগ করে |
|---|---|
| `int main()` | প্রোগ্রামের শুরুর বিন্দু |
| `printf()` | output দেয় |
| `return 0` | সফল সমাপ্তি |
| `;` | প্রতিটি statement শেষে দিতে হয় |

---

## 02 · Escape Sequences

| Sequence | কাজ |
|---|---|
| `\n` | নতুন লাইন |
| `\t` | Tab space |
| `\\` | Backslash print করে |
| `\"` | Double quote print করে |
| `\0` | String শেষের চিহ্ন |
| `%%` | `%` print করে |

---

## 03 · Variables

```c
int    a = 10;       // declaration + initialization
char   b = 'A';
float  c = 5.5;
double d = 10.12345;
```

**তিনটি অপারেশন:**
- **Declaration:** `int age;` — variable তৈরি (garbage value থাকে)
- **Initialization:** `int age = 25;` — তৈরি + value দেওয়া
- **Assignment:** `age = 30;` — পরে value পরিবর্তন

### Format Specifiers

| Type | printf/scanf |
|---|---|
| `int` | `%d` |
| `float` | `%f` |
| `double` | `%lf` |
| `char` | `%c` |
| String | `%s` |

---

## 04 · Data Types

| Type | Size | Range | ব্যবহার |
|---|---|---|---|
| `int` | 4 bytes | -2.1B থেকে 2.1B | পূর্ণ সংখ্যা |
| `float` | 4 bytes | ±3.4e38 | দশমিক (~7 digit) |
| `double` | 8 bytes | ±1.7e308 | বেশি precision |
| `char` | 1 byte | -128 থেকে 127 | একটি character |

**Modifiers:** `short` · `long` · `unsigned` · `signed`

---

## 05 · User Input — scanf()

```c
int a;
printf("Enter: ");
scanf("%d", &a);      // & দিতে হবে — address pass করে

char b;
scanf(" %c", &b);    // char এর আগে space দিতে হবে!
```

> ⚠️ `&` না দিলে program crash করবে। `char` এর আগে space না দিলে input skip হবে।

---

## 06 · Naming Rules

✅ **হবে:** letters, underscore `_`, digit (প্রথমটা বাদে)  
❌ **হবে না:** digit দিয়ে শুরু, space, special chars (`@#$`), C keywords

```
✅ age, _salary, total1
❌ 1place, student name, int
```

> C **case-sensitive** — `age`, `Age`, `AGE` তিনটি আলাদা variable।

**Conventions:** `snake_case` (variables) · `UPPER_CASE` (constants)

---

## 07 · Data Type Limitations

| Type | Max Value | Overflow হলে |
|---|---|---|
| `int` | 2,147,483,647 | Negative হয়ে wrap করে |
| `float` | ~3.4e38 | Precision হারায় |
| `char` | 127 | Wrap করে |

- **Overflow:** Max ছাড়ালে unexpected value আসে
- **Truncation:** `int x = 5.9;` → x = 5 (দশমিক কাটা)
- **Precision Loss:** `0.1 + 0.2 != 0.3` (float এর famous bug)

---

## 08 · Operators

### Arithmetic
| `+` | `-` | `*` | `/` | `%` |
|---|---|---|---|---|
| যোগ | বিয়োগ | গুণ | ভাগ (int কাটে) | ভাগশেষ |

### Relational (result: 1=true, 0=false)
| `==` | `!=` | `>` | `<` | `>=` | `<=` |
|---|---|---|---|---|---|
| সমান | সমান না | বড় | ছোট | বড়/সমান | ছোট/সমান |

### Logical
| `&&` | `||` | `!` |
|---|---|---|
| AND (দুটোই true) | OR (একটি true) | NOT (উল্টো) |

### Increment / Decrement
```c
x++   // আগে use, তারপর বাড়ায়
++x   // আগে বাড়ায়, তারপর use
x--   // আগে use, তারপর কমায়
--x   // আগে কমায়, তারপর use
```

### Assignment
`=` · `+=` · `-=` · `*=` · `/=` · `%=`

### Ternary
```c
max = (a > b) ? a : b;   // condition ? true_value : false_value
```

### Bitwise
| `&` | `|` | `^` | `~` | `<<` | `>>` |
|---|---|---|---|---|---|
| AND | OR | XOR | NOT | Left shift | Right shift |

### Precedence (উপর = আগে)
```
() []  →  ++ -- ! ~ sizeof  →  * / %  →  + -
→  << >>  →  < <= > >=  →  == !=
→  &  →  ^  →  |  →  &&  →  ||  →  ?:  →  = +=...  →  ,
```

---

## 09 · Conditional Statements

### if / if-else
```c
if (condition) {
    // true হলে
} else {
    // false হলে
}
```

### else-if Ladder
```c
if (marks >= 90)      printf("A+");
else if (marks >= 80) printf("A");
else if (marks >= 70) printf("B");
else                  printf("F");
// প্রথম true condition চলে, বাকি skip
```

### switch-case
```c
switch (choice) {
    case 1:  printf("One");  break;  // break না দিলে fall-through!
    case 2:  printf("Two");  break;
    default: printf("Other");
}
```
> ⚠️ `break` না দিলে পরের case-ও execute হয়। `switch` শুধু int/char নেয়।

### Nested if
```c
if (age >= 18) {
    if (hasID) printf("Entry allowed");
    else       printf("Need ID");
} else {
    printf("Too young");
}
```

---

## 10 · Loops

### for Loop — known count এর জন্য
```c
for (int i = 1; i <= 5; i++) {
    printf("%d ", i);
}
// Flow: Init → Check → Body → Update → Check → ...
```

### while Loop — unknown count এর জন্য
```c
int i = 1;
while (i <= 5) {
    printf("%d ", i);
    i++;  // update ভুললে infinite loop!
}
// প্রথমে condition check — false হলে 0 বারও চলে না
```

### do-while Loop — কমপক্ষে 1 বার চালাতে
```c
do {
    printf("Enter choice: ");
    scanf("%d", &choice);
} while (choice != 0);
// Body আগে চলে, তারপর condition check
```

### Loop তুলনা

| বিষয় | `for` | `while` | `do-while` |
|---|---|---|---|
| Condition check | আগে | আগে | পরে |
| Min execution | 0 বার | 0 বার | 1 বার |
| Best for | Known count | Input validation | Menu/retry |

### Loop Control
```c
break;     // loop থেকে সম্পূর্ণ বের হয়
continue;  // এই iteration skip, পরেরটায় যায়
```

### Nested Loop
```c
for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
        printf("%d ", i * j);
    }
    printf("\n");
}
// Total = outer × inner = 9 iterations
```

---

## Quick Reference

### Common scanf Patterns
```c
scanf("%d", &num);        // integer
scanf(" %c", &ch);        // char (আগে space!)
scanf("%f", &price);      // float
scanf("%d %d", &a, &b);  // multiple input
```

### Compilation
```bash
gcc file.c -o output   # compile
./output               # run (Linux/macOS)
gcc -Wall file.c       # warnings সহ compile
```

---

## ✅ Checklist (24 Topics)

- [x] Program Structure · Escape Sequences · Variables · Data Types
- [x] Format Specifiers · scanf() · Naming Rules · Overflow
- [x] Arithmetic · Relational · Logical · Bitwise · Assignment Operators
- [x] Increment/Decrement · Ternary · sizeof
- [x] if · if-else · else-if · Nested if · switch-case
- [x] for · while · do-while · Nested Loop · break · continue

---

## ⚠️ Common Mistakes

| ভুল | সঠিক |
|---|---|
| `scanf("%c", &ch)` | `scanf(" %c", &ch)` — space দাও |
| `if(a = 5)` | `if(a == 5)` — assignment না, comparison |
| switch এ break ভুলা | প্রতিটি case এ `break;` দাও |
| while এ update ভুলা | loop এর ভেতরে `i++` দাও |
| uninitialized variable | সবসময় value দিয়ে শুরু করো |

---

## 🚀 Next Topics

**Functions** → **Arrays** → **Pointers** → **Strings** → **Structures** → **File I/O** → **Dynamic Memory**

---

*C Programming Fundamentals · 2026*
