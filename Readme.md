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

## Examples
Colorize a file:
```
./lolcat README.md
```
Pipe from another command:
```
echo "hello world" | ./lolcat
```
Adjust speed and seed:
```
./lolcat -s 0.5 -S 42 file.txt
```

## Notes
- Behavior and supported flags are determined by the code in `main.c`. Use `./lolcat --help` to see the exact options implemented.
- Tested with GCC on Unix-like systems.
