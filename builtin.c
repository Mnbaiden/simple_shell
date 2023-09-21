#include "shell.h"

/**
 * myls - Implementation of a basic 'ls' command
 * @info: Pointer to info_t structure
 * Return: Always returns 0
 */
int myls(info_t *info)
{
    DIR *dir;
    struct dirent *entry;

    if (info->argc != 1)
    {
        _eputs("Usage: myls\n");
        return (0);
    }

    dir = opendir(".");
    if (!dir)
    {
        perror("myls");
        return (0);
    }

    while ((entry = readdir(dir)) != NULL)
    {
        _puts(entry->d_name);
        _putchar('\n');
    }

    closedir(dir);
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
    info.env = add_node_end(&info.env, env[0], 0);

    myls(&info);

    free_list(&info.env);
    return (0);
}
