#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int is_prime(int n)
{
    if (n < 2)
        return 0;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    int n, start, end;
    printf("Enter the number of random numbers to generate: ");
    scanf("%d", &n);
    printf("Enter the range (start and end): ");
    scanf("%d %d", &start, &end);
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        int num = rand() % (end - start + 1) + start;
        printf("%d ", num);
        if (is_prime(num)) {
            printf("(prime)");
        }
        printf("\n");
    }
    return 0;
}

