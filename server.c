#include "minitalk.h"

void    god_hand(int wyw)
{
    static int i;
    static char    byte;

    if (wyw == SIGUSR1)
    {
        (byte |= (0x80 >> i));
        i++;
    }
    else
        i++;
    if (i == 8)
    {
        write(1, &byte, 1);
        i = 0;
        byte = 0;
    }
}

int     main()
{
    ft_printf("God pid is %d, send your prayer!\n", getpid());
    if (signal(SIGUSR1, god_hand) == SIG_ERR)
    {
        ft_printf("Error.\n");
        exit(1);
    }
    else if (signal(SIGUSR2, god_hand) == SIG_ERR)
    {
        ft_printf("Error.\n");
        exit(1);
    }
    while(1);
}

