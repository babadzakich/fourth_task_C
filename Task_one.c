#include <stdio.h>

void printTime(int hours, int minutes, int seconds)
{
    printf("%02d:%02d:%02d\n", hours, minutes, seconds);
}

int main()
{
    int amount_of_times,time[60][60][24];
    scanf("%d", &amount_of_times);
    int hour, minute, second;
    for(int step = 0; step < amount_of_times; ++step)
    {
        scanf("%d %d %d", &hour, &minute, &second);
        time[second][minute][hour] ++;
    }
    for (int step = 0; step <= 23; ++step)
    {
        for (int step2 = 0; step2 <= 59; ++step2)
        {
            for (int step3 = 0; step3 <= 59; ++step3)
            {
                if(time[step3][step2][step] == 1)
                {
                    printTime(step, step2, step3);
                }
            }
        }
    }
    return 0;
}