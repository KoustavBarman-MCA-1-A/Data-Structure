#include <stdio.h>
void towerOfHanoi(int n, char sc, char au, char de) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", sc, de);
        return;
    }
    towerOfHanoi(n - 1, sc, de, au);
    printf("Move disk %d from %c to %c\n", n, sc, de);
    towerOfHanoi(n - 1, au, sc, de);
}
int main() 
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}