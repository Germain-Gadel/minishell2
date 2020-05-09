/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** return a number from the string
*/

int maxint(int n, int mem)
{
    if (n < 0 && mem > 0)
        return (0);
    else if (n > 0 && mem < 0)
        return (0);
    else
        return (mem);
}

int justonemore(int *mem, int *n)
{
    *mem = *n;
    *n = *n * 10;
    *mem = maxint(*n, *mem);
    return (0);
}

int loopstr(char const *str, int neg, int *cnt)
{
    while (str[*cnt] == '+' || str[*cnt] == '-') {
        if (str[*cnt] == '-')
            neg = neg * -1;
        *cnt += 1;
    }
    return (neg);
}

int my_getnbr(char const *str)
{
    int n = 0;
    int neg = 1;
    int cnt = 0;
    int mem = 0;

    neg = loopstr(str, neg, &cnt);
    while (str[cnt] != '\0') {
        if (str[cnt] >= '0' && str[cnt] <= '9') {
            justonemore(&mem, &n);
            if (mem == 0 && n > 1)
                return (0);
            n = n + str[cnt] - '0';
            cnt++;
        }
        else
            return (n * neg);
    }
    return (n * neg);
}
