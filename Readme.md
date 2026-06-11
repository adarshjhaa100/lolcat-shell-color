# lolcat — README

Small CLI program implemented in `main.c` that colorizes text output (reads files or stdin).

## Build
Compile with a C compiler:
```
gcc -O2 main.c -o lolcat
```

## Usage
```
input | ./lolcat

```

## Sample Output
<img width="1905" height="358" alt="image" src="https://github.com/user-attachments/assets/47dd57ab-92ee-4025-bc58-72fd771d9cdf" />


## Notes
- Behavior and supported flags are determined by the code in `main.c`. Use `./lolcat --help` to see the exact options implemented.
- Tested with GCC on Unix-like systems.
