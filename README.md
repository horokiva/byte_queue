# Byte Queue Project

This project implements a byte queue in C using a static memory allocation technique. It provides functionality to enqueue and dequeue bytes while efficiently managing memory.

## Features

- Implements a byte queue with enqueue and dequeue operations.
- Includes error handling for illegal operations and memory exhaustion.
- Comes with a `Makefile` for easy compilation and testing.

## Building and Running the Project

### Clone the Repository
To download the project from GitHub, run:

```sh
git clone git@github.com:horokiva/byte_queue.git
cd byte_queue
```

### Using the Makefile
The Makefile automates the compilation process. It will automatically detect your OS. Here's how to use it:

- Build the Project:
```
make
```

This compiles the project and creates an executable file main/main.exe depending on your system

- Run the program
```
./main 
```
or

```
./main.exe
```
- Clean Build Files:

After the work is done, it is important to clean the workspace. You can do it by using command:
```
make clean
```

### Error Handling
The program exits with an error message in the following cases:

- Illegal operations (e.g., dequeueing from an empty queue).

- Memory exhaustion when no storage is available.

### Compatibility
- Works on Linux, macOS, and Windows (MinGW).

- Uses gcc as the default compiler.
