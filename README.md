# Brainfuck-Utils
A silly project that provides a few utility tools for the programming language brainfuck...

More about brainfuck here: https://en.wikipedia.org/wiki/Brainfuck.

## Modules

- stringToBF.cpp is a tool to convert any string into a brainfuck script with optional save-to-file (output.bf).
- BFInterpreter.cpp is the brainfuck interpreter, mainly used to test the previously generated script but can also accept hand-typed code as well.

## Usage

Just use whatever IDE you have, or if you don't:

- stringToBF
```
g++ stringToBF.cpp -o stringToBF.exe
./stringToBF.exe
```

- BFInterpreter
```
g++ BFInterpreter.cpp -o BFInterpreter.exe
./BFInterpreter.exe
```
