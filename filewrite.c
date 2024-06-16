#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50

int main() {
    FILE *file;
    char password[MAX_LENGTH];

    // Open the file in write mode
    file = fopen("users.txt", "w");

    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    printf("Enter a new password: ");
    fgets(password, sizeof(password), stdin);

    // Remove the newline character from the password
    password[strcspn(password, "\n")] = '\0';

    // Write the password to the file
    fprintf(file, "%s", password);

    fclose(file);

    printf("Password overwritten successfully.\n");

    return 0;
}

