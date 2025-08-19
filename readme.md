# Hexdump

---

This is a implementation of Hexdump Linux command written in C.

---

### Here is explanation of the project:

- [`hexdump.h`](./include/hexdump.h): main header file used to define the only function
and use it in [`main.c`](./src/main.c) file.
- [`hexdump.c`](./src/hexdump.c): main implementation of `hexdump.h`. Defines
the core logic:

  - `int read_file(const char *path, const char *mode)`: waits for the path of
  the binary file and permissions to open it.

    - first, a pointer of `FILE` data type is created to represent the file that
      will be open.

    - an array of type char called `buffer` is create to store data that will be
      collected from the opened file.

    - the file [`file.bin`](./tests/file.bin) is opened using `fopen()` function
    and stored in `file` variable.

    - there is a simple condition to verify if the file exists.

    - as in `xxd` command, an offset integer to represents the current read byte is
    created.
    
      - a line of a binary file can store at last 16 bytes, so the offset
      represents the first byte in a line.

    - the file is read using the following parameters:

      - store each encountered char in the `buffer` array
      - each char must have 1 byte
      - read 16 bytes (a line)
      - read `file` variable

    - the `while` loop continues to iterate while there's lines to be read.

      - `offset` variable is printed with length of 8.
      
      - the first `for` loop is used to print values of `buffer` in hexadecimal
        format.

      - the second one is almost the same the first, but it's used to print the ASCII
      character corresponding to the current byte (`buffer[i]`), if available.
      If not, prints a dot.

      - offset increases its value in 16 (next line).

      - `read` variable is redefined to read the next line.

    - the file reading is closed.

- [`main.c`](./src/main.c): is only used to call `read_file` function.

- [`file.bin`](./tests/file.bin): example binary file used.

---

> [!TIP]
> You can use another binary file for tests!

---

### How to run it?

Use the [`Makefile`](./Makefile):

1. compile all files:

```bash
make all
```

2. run the main file:

```bash
make run
```

3. (Extra) compares with Hexdump:

```bash
xxd ./tests/file.bin
```

4. clean build files:

```bash
make clean
```

---

That's it!
