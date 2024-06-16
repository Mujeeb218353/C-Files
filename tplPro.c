#include <stdio.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

struct User {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

void signUp() {
	struct User un; 
    printf("Enter username: ");
    scanf("%s",un.username);
    
    printf("Enter password: ");
    scanf("%s", un.password);
    printf("Sign up successful!\n");
}

void signIn() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int i;
    printf("Enter username: ");
    scanf("%s", username);
    
    printf("Enter password: ");
    scanf("%s", password);
    
    for (i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Sign in successful!\n");
            return;
        }
    }
    
    printf("Invalid username or password. Sign in failed.\n");
}

int main() {
    int choice;
    
    do {
        printf("1. Sign Up\n");
        printf("2. Sign In\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                signUp();
                break;
            case 2:
                signIn();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
        
        printf("\n");
    } while (choice != 3);
    
    return 0;
}

