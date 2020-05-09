/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** By Germain Gadel
*/

#ifndef MY_H_
#define MY_H_

#include <stdlib.h>

void my_putchar(char);
int my_put_nbr(int);
int my_putstr(char *);
int my_strlen(char const *);
int cntspace(char *, char);
char *fixstr(char *, char);
int my_little_len(char *, int, int *, char);
char *malloc_dest(char *, char *);
char *my_strcat(char *, char *);
char **my_strtwa(char *, char);
char **add_to_envp(char **, char **, int);
char *my_revstr(char *);
int my_strcmp(char const *, char const *);
char *my_clean_str(char *dest);
char **free_double(char **maze);
int my_getnbr(char const *str);
void get_pwd(void);
int len_double_array(char **);
char **remove_from_envp(char **, char **, int, int *);
char **fill_envp(char **, char **, int);
int find_envp_var_single(char **, char *);
char *replace_var(char *, char **, int);
char **check_commands_env(char *, char **, int *);
void print_env(char **);
void check_commands(char *, int *);
char **change_pwd(char **, char **);
char **set_home_path(char **, char **);
char **set_new_pwd(char **, char *, char **);
char **set_old_path(char **, char **);
char **check_cd(char *, char **, int *);
char **check_wich_cd(char **, char **);
char *get_user_var(char **);
char *get_user(char *);
char **launch_command(char *, char **);
char *command_exist(char **, char *);
void exec_command(char *, char **, char **);


#endif
