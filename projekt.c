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
        fprintf(file, "#include <stdio.h>\n\n");
        fprintf(file, "int main() {\n");
        fprintf(file, "    printf(\"Hello, world!\\n\");\n");
        fprintf(file, "    return 0;\n");
        fprintf(file, "}\n");
        fclose(file);
    }
    else if (strcmp(nyelv, "sh") == 0)
    {
        fprintf(file, "#!/bin/bash\n\n");
        fprintf(file, "echo \"Hello, world!\"\n");
        fclose(file);
        // system("chmod +x main.sh"); Windows támogatottság miatt kiszedve
    }
    else if (strcmp(nyelv, "cpp") == 0)
    {
        fprintf(file, "#include <iostream>\n\n");
        fprintf(file, "int main() {\n");
        fprintf(file, "    std::cout << \"Hello, world!\\n\";\n");
        fprintf(file, "    return 0;\n");
        fprintf(file, "}\n");
        fclose(file);
    }
    else if (strcmp(nyelv, "java") == 0)
    {
        fprintf(file, "public class Main {\n");
        fprintf(file, "    public static void main(String[] args) {\n");
        fprintf(file, "        System.out.println(\"Hello, world!\");\n");
        fprintf(file, "    }\n");
        fprintf(file, "}\n");
        fclose(file);
    }
    else if (strcmp(nyelv, "csharp") == 0)
    {
        fprintf(file, "using System;\n\n");
        fprintf(file, "class Program {\n");
        fprintf(file, "    static void Main() {\n");
        fprintf(file, "        Console.WriteLine(\"Hello, world!\");\n");
        fprintf(file, "    }\n");
        fprintf(file, "}\n");
        fclose(file);
    }
    else if (strcmp(nyelv, "py") == 0)
    {
        fprintf(file, "#!/usr/bin/env python3\n\n");
        fprintf(file, "def main():\n");
        fprintf(file, "    print(\"Hello, world!\")\n\n");
        fprintf(file, "if __name__ == \"__main__\":\n");
        fprintf(file, "    main()\n");
        fclose(file);
    }
    else if (strcmp(nyelv, "fort") == 0)
    {
        fprintf(file, "program hello\n");
        fprintf(file, "  implicit none\n");
        fprintf(file, "  print *, \"Hello, world!\"\n");
        fprintf(file, "end program hello\n");
        fclose(file);
    }
    else if (strcmp(nyelv, "rust") == 0)
    {
        fprintf(file, "fn main() {\n");
        fprintf(file, "    println!(\"Hello, world!\");\n");
        fprintf(file, "}\n");
        fclose(file);
    }
    else if (strcmp(nyelv, "asm") == 0)
    {
        fprintf(file, "section .data\n");
        fprintf(file, "    msg db \"Hello, world!\", 0xA\n");
        fprintf(file, "    len equ $ - msg\n\n");
        fprintf(file, "section .text\n");
        fprintf(file, "    global _start\n\n");
        fprintf(file, "_start:\n");
        fprintf(file, "    mov rax, 1\n");
        fprintf(file, "    mov rdi, 1\n");
        fprintf(file, "    mov rsi, msg\n");
        fprintf(file, "    mov rdx, len\n");
        fprintf(file, "    syscall\n\n");
        fprintf(file, "    mov rax, 60\n");
        fprintf(file, "    xor rdi, rdi\n");
        fprintf(file, "    syscall\n");
        fclose(file);
    } // ez az utasitas szintén csak linuxon müködik
    printf(" A(z) %s alapkód fájl létrehozásra került!\n", nyelv);
}

void main_file_generalas_stdoutra(string nyelv)
{
    if (strcmp(nyelv, "c") == 0)
    {
        printf("#include <stdio.h>\n\n");
        printf("int main() {\n");
        printf("    printf(\"Hello, world!\\n\");\n");
        printf("    return 0;\n");
        printf("}\n");
    }
    else if (strcmp(nyelv, "sh") == 0)
    {
        printf("#!/bin/bash\n\n");
        printf("echo \"Hello, world!\"\n");
    }
    else if (strcmp(nyelv, "cpp") == 0)
    {
        printf("#include <iostream>\n\n");
        printf("int main() {\n");
        printf("    std::cout << \"Hello, world!\\n\";\n");
        printf("    return 0;\n");
        printf("}\n");
    }
    else if (strcmp(nyelv, "java") == 0)
    {
        printf("public class Main {\n");
        printf("    public static void main(String[] args) {\n");
        printf("        System.out.println(\"Hello, world!\");\n");
        printf("    }\n");
        printf("}\n");
    }
    else if (strcmp(nyelv, "csharp") == 0)
    {
        printf("using System;\n\n");
        printf("class Program {\n");
        printf("    static void Main() {\n");
        printf("        Console.WriteLine(\"Hello, world!\");\n");
        printf("    }\n");
        printf("}\n");
    }
    else if (strcmp(nyelv, "py") == 0)
    {
        printf("#!/usr/bin/env python3\n\n");
        printf("def main():\n");
        printf("    print(\"Hello, world!\")\n\n");
        printf("if __name__ == \"__main__\":\n");
        printf("    main()\n");
    }
    else if (strcmp(nyelv, "fort") == 0)
    {
        printf("program hello\n");
        printf("  implicit none\n");
        printf("  print *, \"Hello, world!\"\n");
        printf("end program hello\n");
    }
    else if (strcmp(nyelv, "rust") == 0)
    {
        printf("fn main() {\n");
        printf("    println!(\"Hello, world!\");\n");
        printf("}\n");
    }
    else if (strcmp(nyelv, "asm") == 0)
    {
        printf("section .data\n");
        printf("    msg db \"Hello, world!\", 0xA\n");
        printf("    len equ $ - msg\n\n");
        printf("section .text\n");
        printf("    global _start\n\n");
        printf("_start:\n");
        printf("    mov rax, 1\n");
        printf("    mov rdi, 1\n");
        printf("    mov rsi, msg\n");
        printf("    mov rdx, len\n");
        printf("    syscall\n\n");
        printf("    mov rax, 60\n");
        printf("    xor rdi, rdi\n");
        printf("    syscall\n");
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
        printf("Alapkód generátor, Verzió 0.3, Barna István\n");
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