#include "shell.h"

/**
 * myatoi - Converts a string to an integer
 * @str: The string to convert
 * Return: The integer value, or 0 if conversion fails
 */
int myatoi(char *str)
{
    int result = 0;
    int sign = 1;
    int i = 0;

    if (str == NULL || *str == '\0')
        return 0;

    if (str[0] == '-')
    {
        sign = -1;
        i++;
    }

    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
            return 0; // Invalid character in the string

        result = result * 10 + (str[i] - '0');
        i++;
    }

    return result * sign;
}

/**
 * main - Entry point for testing myatoi function
 * @argc: Argument count
 * @argv: Argument vector
 * Return: Always returns 0
 */
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        _eputs("Usage: myatoi <number>\n");
        return (EXIT_FAILURE);
    }

    int value = myatoi(argv[1]);
    if (value == 0 && argv[1][0] != '0')
    {
        _eputs("Error: Invalid input\n");
        return (EXIT_FAILURE);
    }

    _puts("Converted integer: ");
    print_d(value, STDOUT_FILENO);
    _putchar('\n');

    return (EXIT_SUCCESS);
}
