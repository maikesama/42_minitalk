#include "minitalk.h"

void convert_the_prayer(char *prayer, int pid)
{
    int     i;
    int     j;
    char    c;

    i = 0;
    while (i < ft_strlen(prayer))
    {
        c = prayer[i];
        j = 7;
        while (j >= 0)
        {
            ((c & 1 << j) ? kill(pid, SIGUSR1) : kill(pid, SIGUSR2));
            usleep(50);
            j--;
        }
        i++;
    }
}

int dont_try_to_fuck_with_god(int argc, char **argv)
{
    int i;

    i = -1;
    if (argc != 3)
    {
        printf("Are you trying to send me some BS son? Try again, you will be luckier(maybe)!\n");
        return(0);
    }
    while(argv[1][++i])
    {
        if(!ft_isdigit(argv[1][i]))
        {
            printf("God's pid it's composed by number. CAN YOU DO IT RIGHT SON?");
            return(0);
        }
    }
    return(1);
}

int main(int argc, char **argv)
{
    int                 pid;
    if(!dont_try_to_fuck_with_god(argc, argv))
        return(0);
    pid = ft_atoi(argv[1]);
    convert_the_prayer(argv[2], pid);
    return(0);
}