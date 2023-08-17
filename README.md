# get_next_line

`get_next_line` is a function that reads and returns a single line from a file descriptor each time it's called, until the end of the file is reached.

## Description

The `get_next_line` function reads text from the given file descriptor and returns it line by line. It uses a buffer to store the read content and processes it to provide a line every time the function is called. The function is designed to handle multiple file descriptors simultaneously and keep track of the progress for each file descriptor independently.

## Usage

1. Clone this repository to your project directory:

   ```bash
   git clone https://github.com/abbastoof/get_next_line.git
   ```

2. Include the `get_next_line.h` header in your code.

3. Call the `get_next_line` function with the file descriptor you want to read from as an argument. The function will return a pointer to a string containing the next line read from the file.

4. Free the allocated memory when done with each line.

## Compilation

Compile your program with the `get_next_line` function:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 your_program.c get_next_line.c get_next_line_utils.c -o your_program
```

Adjust `BUFFER_SIZE` as needed to set the buffer size for reading data.

## Examples

Usage example:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        free(line);
    }

    close(fd);
    return 0;
}
```

## Contributing

Contributions are welcome! Open a pull request for improvements or issues.
