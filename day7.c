 #include <stdio.h>

// Recursive function to find nth Fibonacci number
int fib(int n)
{
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;

    printf("Enter value of n:\n");
    scanf("%d", &n);

    if(n < 0)
    {
        printf("Invalid input. n must be non-negative.\n");
        return 0;
    }

    int result = fib(n);

    printf("The %dth Fibonacci number is:\n", n);
    printf("%d\n", result);

    return 0;
}
