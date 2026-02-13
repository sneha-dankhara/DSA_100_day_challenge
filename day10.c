#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];

    printf("Enter a string:\n");
    scanf("%s", str);

    int left = 0;
    int right = strlen(str) - 1;
    int isPalindrome = 1;

    while(left < right)
    {
        if(str[left] != str[right])
        {
            isPalindrome = 0;
            break;
        }
        left++;
        right--;
    }

    if(isPalindrome == 1)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
