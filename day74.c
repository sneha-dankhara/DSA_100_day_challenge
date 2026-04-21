#include <stdio.h>
#include <string.h>

int main() {
    int n;

    printf("Enter number of votes: ");
    scanf("%d", &n);

    char names[n][100];

    printf("Enter candidate names:\n");

    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int maxVotes = 0;
    char winner[100] = "";

    for (int i = 0; i < n; i++) {
        if (visited[i])
            continue;

        int count = 1;

        for (int j = i + 1; j < n; j++) {
            if (strcmp(names[i], names[j]) == 0) {
                count++;
                visited[j] = 1;
            }
        }

        if (count > maxVotes) {
            maxVotes = count;
            strcpy(winner, names[i]);
        } 
        else if (count == maxVotes) {
            if (strcmp(names[i], winner) < 0) {
                strcpy(winner, names[i]);
            }
        }
    }

    printf("\nWinner: %s %d\n", winner, maxVotes);

    return 0;
}