#include <stdio.h>
#include <string.h>

// Recursive function to print string in reverse
void reverse(char str[], int index)
{
    if(index < 0)
        return;

    printf("%c", str[index]);
    reverse(str, index - 1);
}

int main()
{
    char str[100];

    printf("Enter the code name:\n");
    scanf("%s", str);

    int length = strlen(str);

    printf("Mirror format of the code name is:\n");
    reverse(str, length - 1);

    printf("\n");

    return 0;
}
