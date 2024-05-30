#include <windows.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
    PlaySound("C:/NNN.wav",NULL, SND_ASYNC);
    printf("輸入一個整數: ");
    int n;
    scanf("%d", &n);
}
