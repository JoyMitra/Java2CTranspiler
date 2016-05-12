# TeamD
Points to note:

1. The source code for garbage collector and static libraries are in bin/esj/codegen/my_alloc.c and bin/esj/codegen/staticlib.o.
2. The generated C files from their corresponding Java source files are stored in bin/esj/codegen/
3. When you import this project do not forget to import bin. This is required when you run the test cases for the transpiler. 
4. To compile a generated C code manually.
        $ cd bin/esj/codegen
        $ gcc -o <c-file-name> <c-file-name>.c staticlib.o my_alloc.o
5. To execute a C code manually.
        $ bin/esj/codegen/<c-file-name>
