#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // printf("Enter time in minutes:");
    if(argc < 2) {
        printf("Enter starting time.\n");
        getchar();
        return 0;
    }
    int x = atoi(argv[1]);
    // scanf("%d", &x);
    x = x*60;
    while(x>=0) {
        printf("Remaining time is %02dm%02ds\r", x/60, x%60);
        fflush(stdout);
        x--;
        sleep(1);
    }
    getchar();
    printf("\n");
    return 0;
}
