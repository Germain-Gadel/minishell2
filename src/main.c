/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** By Germain Gadel
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "my.h"

char **check_slash(char *command, char **envp, int *status)
{
    char **command_arg = NULL;
    char *test_command = NULL;

    if (command[0] == '.' && command[1] == '/') {
        *status += 1;
        command_arg = my_strtwa(command, ' ');
        test_command = my_strcat(my_strcat(getcwd(NULL, 0), "/"),
        command_arg[0]);
        if (access(test_command, R_OK | X_OK) == -1) {
            perror(test_command);
            return (envp);
        }
        exec_command(test_command, command_arg, envp);
    }
    return (envp);
}

char **does_command_semicolon_exist(char *buffer, char **envp)
{
    char **semicolon_com = my_strtwa(buffer, ';');
    int state = 0;
    int len_buffer = my_strlen(buffer);

    if (len_buffer == 0)
        return (envp);
    for (int i = 0; semicolon_com[i] != NULL; i++) {
        check_commands(semicolon_com[i], &state);
        envp = check_commands_env(semicolon_com[i], envp, &state);
        envp = check_cd(semicolon_com[i], envp, &state);
        envp = check_slash(semicolon_com[i], envp, &state);
        if (state == 0)
            envp = launch_command(semicolon_com[i], envp);
        state = 0;
    }
    semicolon_com = free_double(semicolon_com);
    return (envp);
}

int main(__attribute__((unused))int ac,
__attribute__((unused))char **av, char **envp)
{
    int state = 0;
    char *buffer = NULL;
    size_t buff = 5;

    if (envp[0] == NULL)
        return (84);
    my_putstr(get_user_var(envp));
    while (state == 0 && (getline(&buffer, &buff, stdin) != -1)) {
        buffer[my_strlen(buffer) - 1] = '\0';
        envp = does_command_semicolon_exist(my_clean_str(buffer), envp);
        my_putstr(get_user_var(envp));
    }
    free(buffer);
    return (0);
}