/*
** EPITECH PROJECT, 2018
** change_envp.c
** File description:
** By Germain Gadel
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"

char **set_old_path(char **envp, char **cd_arg)
{
    int var_exist_oldhome = -1;
    int var_exist_path = -1;
    char **path = NULL;

    cd_arg[0] = "PWD";
    var_exist_path = find_envp_var_single(envp, cd_arg[0]);
    cd_arg[0] = "OLDPWD";
    var_exist_oldhome = find_envp_var_single(envp, cd_arg[0]);
    if (var_exist_path != -1 && var_exist_oldhome != -1) {
        path = my_strtwa(envp[var_exist_path], '=');
        envp[var_exist_oldhome] = my_strcat("OLDPWD=", path[1]);
    } else
        return (envp);
    path = free_double(path);
    return (envp);
}

char **set_new_pwd(char **envp, char *pwd, char **cd_arg)
{
    int var_exist_path = -1;

    cd_arg[0] = "PWD";
    var_exist_path = find_envp_var_single(envp, cd_arg[0]);
    if (var_exist_path != -1) {
        envp[var_exist_path] = my_strcat("PWD=", pwd);
    } else
        return (envp);
    return (envp);
}

char **set_home_path(char **envp, char **cd_arg)
{
    int var_exist_home = -1;
    int var_exist_path = -1;
    char **path = NULL;
    char pwd[FILENAME_MAX];

    cd_arg[0] = "PWD";
    var_exist_path = find_envp_var_single(envp, cd_arg[0]);
    cd_arg[0] = "HOME";
    var_exist_home = find_envp_var_single(envp, cd_arg[0]);
    if (var_exist_path != -1 && var_exist_home != -1) {
        path = my_strtwa(envp[var_exist_home], '=');
        envp[var_exist_path] = my_strcat("PWD=", path[1]);
    } else
        return (envp);
    chdir(path[1]);
    getcwd(pwd, sizeof(pwd));
    envp = set_old_path(envp, cd_arg);
    envp = set_new_pwd(envp, pwd, cd_arg);
    path = free_double(path);
    return (envp);
}

void print_error_cd(char *error)
{
    int dir = 0;

    dir = open(error, O_RDONLY);
    if (dir == -1) {
        my_putstr(error);
        my_putstr(": No such file or directory.\n");
    } else {
        my_putstr(error);
        my_putstr(": Not a directory.\n");
    }
    close(dir);
}

char **change_pwd(char **envp, char **cd_arg)
{
    char pwd[FILENAME_MAX];

    if (cd_arg[1] != NULL && my_strcmp(cd_arg[1], "-") == 0) {
        envp = set_old_path(envp, cd_arg);
        envp = set_new_pwd(envp, pwd, cd_arg);
    } else if (chdir(cd_arg[1]) != -1) {
        getcwd(pwd, sizeof(pwd));
        envp = set_old_path(envp, cd_arg);
        envp = set_new_pwd(envp, pwd, cd_arg);
    } else if (cd_arg[1] != NULL) {
        print_error_cd(cd_arg[1]);
    }
    return (envp);
}