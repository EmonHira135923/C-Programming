#include<stdio.h>
int main(){
    // \n is used to print in new line
    // \t is used to print in tab space
    // \\ is used to print backslash
    // \" is used to print double quote
    // \' is used to print single quote
    // \a is used to print alert sound
    // \b is used to print backspace
    // \r is used to print carriage return
    // \f is used to print form feed
    // \v is used to print vertical tab
    // \0 is used to print null character
    // %% is used to print percentage
    // /? is used to print question mark
    // \x is used to print hexadecimal value
    // \u is used to print unicode character
    // \U is used to print unicode character
    // /* is used to print multi line comment
    // */ is used to print multi line comment
    // \ is used to print backslsh
    // %d is used to print integer
    // %f is used to print float
    // %c is used to print character
    // %s is used to print string
    // %p is used to print pointer
    // %u is used to print unsigned integer
    // %x is used to print hexadecimal integer
    // %o is used to print octal integer
    // %ld is used to print long integer
    // %lf is used to print double
    // %lld is used to print long long integer

    // Escape Sequences
    printf("New Line Example:\nHello\nWorld\n\n");

    printf("Tab Example:\tHello\tWorld\n\n");

    printf("Backslash: \\\n");
    printf("Double Quote: \"Hello\"\n");
    printf("Single Quote: \'A\'\n\n");

    printf("Alert Sound: \a\n"); // beep (may not work in all systems)

    printf("Backspace: ABC\bD\n"); // output: ABD
    printf("Carriage Return: Hello\rWorld\n"); // overwrite
    printf("Form Feed: Hello\fWorld\n");
    printf("Vertical Tab: Hello\vWorld\n");

    printf("Null Character: Hello\0World\n\n"); // stops after Hello

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

    
}