# Yet Another BrainFuck Interpreter
Yabfi is one of the shortest brainFuck interpreters (14 lines or 757 characters)
![image](/res/code.jpg)


## What is BrainFuck?
Brainfuck is one of the most famous esoteric programming languages.
This Turing language is complete, which means you can write anything on it
Language contains only 8 commands:
* '+' - increment the byte at the data pointer.
* '-' - decrement the byte at the data pointer.
* '>' - increment the data pointer (to point to the next cell to the right).
* '<' - decrement the data pointer (to point to the next cell to the left).
* '.' - output the byte at the data pointer.
* ',' - accept one byte of input, storing its value in the byte at the data pointer.
* '[' - if the byte at the data pointer is zero, then instead of moving the instruction pointer forward to the next command, jump it forward to the command after the matching ] command.
* ']' - if the byte at the data pointer is nonzero, then instead of moving the instruction pointer forward to the next command, jump it back to the command after the matching [ command

[Wikipedia](https://en.wikipedia.org/wiki/Brainfuck)


## Work examples
Test programs are in the 'test' folder.
Screenshots in 'res' folder


## What is the peculiarity of this?
This interpreter is one of the smallest.
This is possible due to the simple language and features of C.
The interpreter size:
* 14 lines
* 757 characters


## Build
```
git clone https://github.com/xDiaym/Yabfi
cd Yabfi/src
mkdir build
cd build
cmake ../CMakeLists.txt
make
```

## Usage
```
yabfi [path-to-file]
```


## NOTE
In the small version, the check for exceeding the stack size is disabled!
For debugging use the full version
