#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *string;
int file_letezik(const string fajlnev)
{
    FILE *file = fopen(fajlnev, "r");
    if (file)
    {
        fclose(file);
        return 1;
    }
    return 0;
}
string c_nyelv =
    "#include <stdio.h>\n"
    "\n"
    "int main() {\n"
    "    printf(\"Hello, world!\\n\");\n"
    "    return 0;\n"
    "}\n";
string shell_nyelv =
    "#!/bin/bash\n\n"
    "echo \"Hello, world!\"\n";
string c_plus_nyelv =
    "#include <iostream>\n\n"
    "int main() {\n"
    "    std::cout << \"Hello, world!\\n\";\n"
    "    return 0;\n";
string java_nyelv =
    "public class Main {\n"
    "    public static void main(String[] args) {\n"
    "        System.out.println(\"Hello, world!\");\n"
    "    }\n"
    "}\n";
string csharp_nyelv =
    "using System;\n\n"
    "class Program {\n"
    "    static void Main() {\n"
    "        Console.WriteLine(\"Hello, world!\");\n"
    "    }\n"
    "}\n";
string python_nyelv =
    "#!/usr/bin/env python3\n\n"
    "def main():\n"
    "    print(\"Hello, world!\")\n\n"
    "if __name__ == \"__main__\":\n"
    "    main()\n";
string fortran_nyelv =
    "program hello\n"
    "  implicit none\n"
    "  print *, \"Hello, world!\"\n"
    "end program hello\n";
string rust_nyelv =
    "fn main() {\n"
    "    println!(\"Hello, world!\");\n"
    "}\n";
string assembly_nyelv =
    "section .data\n"
    "    msg db \"Hello, world!\", 0xA\n"
    "    len equ $ - msg\n\n"
    "section .text\n"
    "    global _start\n\n"
    "_start:\n"
    "    mov rax, 1\n"
    "    mov rdi, 1\n"
    "    mov rsi, msg\n"
    "    mov rdx, len\n"
    "    syscall\n\n"
    "    mov rax, 60\n"
    "    xor rdi, rdi\n"
    "    syscall\n";
void main_file_generalas(string nyelv)
{
    FILE *file;
    if (strcmp(nyelv, "c") == 0)
    {
        file = fopen("main.c", "w");
    }
    else if (strcmp(nyelv, "sh") == 0)
    {
        file = fopen("main.sh", "w");
    }
    else if (strcmp(nyelv, "cpp") == 0)
    {
        file = fopen("main.cpp", "w");
    }
    else if (strcmp(nyelv, "java") == 0)
    {
        file = fopen("Main.java", "w");
    }
    else if (strcmp(nyelv, "csharp") == 0)
    {
        file = fopen("Program.cs", "w");
    }
    else if (strcmp(nyelv, "py") == 0)
    {
        file = fopen("main.py", "w");
    }
    else if (strcmp(nyelv, "fort") == 0)
    {
        file = fopen("main.f90", "w");
    }
    else if (strcmp(nyelv, "rust") == 0)
    {
        file = fopen("main.rs", "w");
    }
    else if (strcmp(nyelv, "asm") == 0)
    {
        file = fopen("main.asm", "w");
    }
    else
    {
        printf("Megadott '%s' nyelvhez való alapkód készítés még nem támogatott!\n", nyelv);
        return;
    }

    if (file == NULL)
    {
        printf("Hiba: Nem sikerült a fájl létrehozása!\n");
        return;
    }

    if (strcmp(nyelv, "c") == 0)
    {
        fprintf(file, "%s", c_nyelv);
        fclose(file);
    }
    else if (strcmp(nyelv, "sh") == 0)
    {
        fprintf(file, "%s", shell_nyelv);
        fclose(file);
    }
    else if (strcmp(nyelv, "cpp") == 0)
    {
        fprintf(file, "%s", c_plus_nyelv);
        fclose(file);
    }
    else if (strcmp(nyelv, "java") == 0)
    {
        fprintf(file, "%s", java_nyelv);
        fclose(file);
    }
    else if (strcmp(nyelv, "csharp") == 0)
    {
        fprintf(file, "%s", csharp_nyelv);
        fclose(file);
    }
    else if (strcmp(nyelv, "py") == 0)
    {
        fprintf(file, "%s", python_nyelv);
        fclose(file);
    }
    else if (strcmp(nyelv, "fort") == 0)
    {
        fprintf(file, "%s", fortran_nyelv);
        fclose(file);
    }
    else if (strcmp(nyelv, "rust") == 0)
    {
        fprintf(file, "%s", rust_nyelv);
        fclose(file);
    }
    else if (strcmp(nyelv, "asm") == 0)
    {
        fprintf(file, "%s", assembly_nyelv);
        fclose(file);
    }
    printf(" A(z) %s alapkód fájl létrehozásra került!\n", nyelv);
}

void main_file_generalas_stdoutra(string nyelv)
{
    if (strcmp(nyelv, "c") == 0)
    {
        printf("%s", c_nyelv);
    }
    else if (strcmp(nyelv, "sh") == 0)
    {
        printf("%s", shell_nyelv);
    }
    else if (strcmp(nyelv, "cpp") == 0)
    {
        printf("%s", c_plus_nyelv);
    }
    else if (strcmp(nyelv, "java") == 0)
    {
        printf("%s", java_nyelv);
    }
    else if (strcmp(nyelv, "csharp") == 0)
    {
        printf("%s", csharp_nyelv);
    }
    else if (strcmp(nyelv, "py") == 0)
    {
        printf("%s", python_nyelv);
    }
    else if (strcmp(nyelv, "fort") == 0)
    {
        printf("%s", fortran_nyelv);
    }
    else if (strcmp(nyelv, "rust") == 0)
    {
        printf("%s", rust_nyelv);
    }
    else if (strcmp(nyelv, "asm") == 0)
    {
        printf("%s", assembly_nyelv);
    }
    else
    {
        printf("Megadott '%s' nyelvhez való alapkód készítés még nem támogatott!\n", nyelv);
        return;
    }
}

void Utmutato(string prog_nyelv)
{
    printf("Használat: %s <programozási nyelv> [<opciók(kapcsolók)>]\n", prog_nyelv);
    puts("Opciók(kapcsolók):");
    puts("  -v, --version\t\tVerziószám megjelenítése");
    puts("  -h, --help\t\tHasználati útmutató megjelenítése.");
    puts("  --stdout\t\tAlapkód terminálba való kiírása alapkód fájl generálása helyett.");
    puts("Támogatott nyelvek:");
    puts("programozási nyelv\tleírás\n \tc\t\t C forráskód\n \tsh\t\t Bash script forráskód\n \tcpp\t\t C++ forráskód\n \tjava\t\t Java forráskód\n \tcsharp\t\t C# forráskód\n \tpy\t\t Python forráskód\n \tfort\t\t Fortran forráskód\n \trust\t\t Rust forráskód\n \tasm\t\t Assembly forráskód");
}

int main(int argc, string argv[])
{
    if (argc == 1)
    {
        Utmutato(argv[0]);
        return 1;
    }
    string kapcsolo = argv[1];
    if (strcmp(kapcsolo, "--version") == 0 || strcmp(kapcsolo, "-v") == 0)
    {
        printf("Alapkód generátor, Verzió 0.4, Barna István\n");
        return 0;
    }

    if (strcmp(kapcsolo, "--help") == 0 || strcmp(kapcsolo, "-h") == 0)
    {
        Utmutato(argv[0]);
        return 0;
    }

    if (strcmp(kapcsolo, "--stdout") == 0)
    {
        printf("Hiba: '--stdout' nem használható mint nyelv! Csak a kód parancsorba való kiírására használható!.\n");
        return 1;
    }

    if (argc == 2)
    {
        string nyelv = kapcsolo;
        if (strcmp(nyelv, "c") == 0 && file_letezik("main.c"))
        {
            printf("Hiba: main.c (C alapkód) már létezik!\n");
            return 1;
        }
        if (strcmp(nyelv, "sh") == 0 && file_letezik("main.sh"))
        {
            printf("Hiba: main.sh (Bash Scipt alapkód) már létezik!\n");
            return 1;
        }
        if (strcmp(nyelv, "cpp") == 0 && file_letezik("main.cpp"))
        {
            printf("Hiba: main.cpp (C++ alapkód) már létezik!\n");
            return 1;
        }
        if (strcmp(nyelv, "java") == 0 && file_letezik("Main.java"))
        {
            printf("Hiba: Main.java (Java alapkód) már létezik!\n");
            return 1;
        }
        if (strcmp(nyelv, "csharp") == 0 && file_letezik("Program.cs"))
        {
            printf("Hiba: Program.cs (C# alapkód) már létezik!\n");
            return 1;
        }
        if (strcmp(nyelv, "py") == 0 && file_letezik("main.py"))
        {
            printf("Hiba: main.py (Python alapkód) már létezik!\n");
            return 1;
        }
        if (strcmp(nyelv, "fort") == 0 && file_letezik("main.f90"))
        {
            printf("Hiba: main.f90 (Fortran alapkód) már létezik!\n");
            return 1;
        }
        if (strcmp(nyelv, "rust") == 0 && file_letezik("main.rs"))
        {
            printf("Hiba: main.rs (Rust alapkód) már létezik!\n");
            return 1;
        }
        if (strcmp(nyelv, "asm") == 0 && file_letezik("main.asm"))
        {
            printf("Hiba: main.asm (Assembly alapkód) már létezik!\n");
            return 1;
        }
        main_file_generalas(nyelv);
    }
    else if (argc == 3 && strcmp(argv[2], "--stdout") == 0)
    {
        string nyelv = kapcsolo;
        main_file_generalas_stdoutra(nyelv);
    }
    else
    {
        printf("Hibás argumentumok!\n");
        Utmutato(argv[0]);
        return 1;
    }

    return 0;
}