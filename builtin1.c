#include "shell.h"

/**
 * mycat - Implementation of a basic 'cat' command
 * @info: Pointer to info_t structure
 * Return: Always returns 0
 */
int mycat(info_t *info)
{
    int fd, n;
    char buffer[READ_BUF_SIZE];

    if (info->argc != 2)
    {
        _eputs("Usage: mycat <file>\n");
        return (0);
    }

    fd = open(info->argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("mycat");
        return (0);
    }

    while ((n = read(fd, buffer, READ_BUF_SIZE)) > 0)
        write(STDOUT_FILENO, buffer, n);

    if (n == -1)
        perror("mycat");

    close(fd);
    return (0);
}

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 * @env: Environment variables
 * Return: Always returns 0
 */
int main(int argc, char *argv[], char *env[])
{
    info_t info = INFO_INIT;

    (void)argc;
    (void)argv;
    info.env = add_node_end(&info.env, env[0]);

    mycat(&info);

    free_list(&info.env);
    return (0);
}
