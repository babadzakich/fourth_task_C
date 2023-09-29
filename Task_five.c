#include <stdio.h>
#include <string.h>
int bukvacheck(char *str)
{
    if ((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z'))
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}
char* counter(char *str, int *amount_counter, int *upper_counter)
{
    for (int step = 0; step < strlen(str); ++step)
    {
        if (*(str+step) >= 'A' && *(str+step) <= 'Z')
        {
            ++*upper_counter;
            ++*amount_counter;
        }
        else if (*(str+step) >= 'a' && *(str+step) <= 'z')
        {
            ++*amount_counter;
        }
    }
}

int main()
{
    int amount_of_letters = 0, flag = 0, amount = 0, upper = 0, step2 = 0;
    char line[1000000], res[100000];
    scanf("%s", line);
    for (int step = 0; step < strlen(line); ++step)
    {
        if (!flag && bukvacheck(&line[step]) == 1)
        {
            flag = 1;
            res[step2] = line[step];
            step2 ++;
        }
        else if (flag && bukvacheck(&line[step]) == 1)
        {
            res[step2] = line[step];
            step2 ++;
        }
        else if (flag && bukvacheck(&line[step]) == 0)
        {
            flag = 0;
            counter(res, &amount, &upper);
            printf("%d/%d %s\n", upper, amount, res);
            amount = 0;
            upper = 0;
            step2 = 0;
            memset(res, '\0', sizeof(res));
        }
        else{
            continue;
        }
    }
    return 0;
}   