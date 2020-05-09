/*
** EPITECH PROJECT, 2018
** launch_command.c
** File description:
** By Germain Gadel
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "my.h"

void exec_command(char *command_first, char **command_arg, char **envp)
{
    pid_t id;
    int status;

    id = fork();
    if (command_first == NULL) {
        my_putstr(command_arg[0]);
        my_putstr(": Command not found.\n");
        exit(0);
    }
    if (id == 0) {
        status = execve(command_first, command_arg, envp);
        if (status == -1) {
            free(command_first);
            exit(0);
        }
    } else {
        wait(&status);
    }
}

char *command_exist(char **path_var_val, char *command_arg)
{
    int i = 0;
    char *com = NULL;

    for (;path_var_val[i] != NULL; i++) {
        if (access(my_strcat(my_strcat(path_var_val[i], "/"),
        command_arg), F_OK | X_OK)
        == 0) {
            return (my_strcat(my_strcat(path_var_val[i], "/"), command_arg));
            break;
        }
    }
    return (com);
}

char **launch_command(char *buffer, char **envp)
{
    char **command_arg = my_strtwa(buffer, ' ');
    int var_path_nb = find_envp_var_single(envp, "PATH");
    char **path_var = NULL;
    char **path_var_val = NULL;
    char *com = NULL;

    if (var_path_nb == -1)
        return (envp);
    path_var = my_strtwa(envp[var_path_nb], '=');
    path_var_val = my_strtwa(path_var[1], ':');
    com = command_exist(path_var_val, command_arg[0]);
    if (com != NULL) {
        exec_command(com, command_arg, envp);
    } else {
        my_putstr(command_arg[0]);
        my_putstr(": Command not found.\n");
    }
    return (envp);
}