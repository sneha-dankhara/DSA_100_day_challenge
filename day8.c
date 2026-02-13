 #include <stdio.h>

// Recursive function to calculate a^b
int power(int a, int b)
{
    if(b == 0)
        return 1;              // Base case: a^0 = 1
    else
        return a * power(a, b - 1);
}

int main()
{
    int a, b;

    printf("Enter base and exponent:\n");
    scanf("%d %d", &a, &b);

    if(b < 0)
    {
        printf("Exponent must be non-negative.\n");
        return 0;
    }

    int result = power(a, b);

    printf("%d raised to power %d is:\n", a, b);
    printf("%d\n", result);

    return 0;
}
