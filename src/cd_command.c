/*
** EPITECH PROJECT, 2018
** cd_commands.c
** File description:
** By Germain Gadel
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "my.h"

char **check_wich_cd(char **cd_arg, char **envp)
{
    if (cd_arg[1] == NULL) {
        envp = set_home_path(envp, cd_arg);
        envp = change_pwd(envp, cd_arg);
        return (envp);
    } else if (my_strcmp(cd_arg[1], "-") == 0) {
        envp = set_old_path(envp, cd_arg);
        envp = change_pwd(envp, cd_arg);
        return (envp);
    } else {
        envp = change_pwd(envp, cd_arg);
    }
    return (envp);
}

char **check_cd(char *buffer, char **envp, int *state)
{
    char **cd_arg = my_strtwa(buffer, ' ');

    if (my_strcmp(cd_arg[0], "cd") == 0) {
        envp = check_wich_cd(cd_arg, envp);
        *state += 1;
    }
    return (envp);
}