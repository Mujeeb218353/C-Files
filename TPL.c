#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 60
#define MAX_USERNAME_LENGTH 30
#define MAX_PASSWORD_LENGTH 8
void teacherDashboard();
void studentDashboard();
void updatePass();
struct  ui{
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};
int usersCounter() {
    FILE *sfp = fopen("student.txt", "r");
    int count = 0;
    char ch;
    while ((ch = fgetc(sfp)) != EOF) {
        if (ch == '\n') {
            count++;
        }
    }
    fclose(sfp);
    return count;
}
void signUp() {
    struct ui u;
    FILE *sfp,*tfp;
    char studentOrTeacher;
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char ch;
    sfp = fopen("student.txt", "a");
    tfp = fopen("teacher.txt", "a");
    if(sfp==NULL){
    	printf("Error...");
    	return;
	}
    printf("Enter Username:");
    scanf("%s",u.username);
    printf("Enter Password:");
    scanf("%s",u.password);
    while(fscanf(tfp, "%s %s", username,password) != EOF){
	    if(strcmp(username,u.username)==0 && strcmp(password,u.password)==0){
           printf("\nIt's Already Exist...");
           return;
        }
    }
    while(fscanf(sfp, "%s %s", username,password) != EOF){
	    if(strcmp(username,u.username)==0 && strcmp(password,u.password)==0){
           printf("\nIt's Already Exist...");
           return;
        }
    }
    fclose(sfp);
    fclose(tfp);
    printf("Are you student(y/n):");
    studentOrTeacher = getch();
    if(studentOrTeacher=='y' || studentOrTeacher=='Y'){
        sfp = fopen("student.txt", "a"); 
        if(usersCounter()>=MAX_USERS){
        	printf("User registration limit reached...\nYou can't SignUp\n");
        	return;
		}else{
            fprintf(sfp, "%s %s\n", u.username, u.password);
            printf("\nStudent SignUp Successfully...\n");
        }
    }else{
        tfp = fopen("teacher.txt", "a");
        fputs(username,tfp);
        fputs(password,tfp);
        printf("\nTeacher SignUp Successfully...\n");
    }
    fclose(sfp);
    fclose(tfp);
}
void signIn() {
    struct ui i;
    FILE *sfp,*tfp;
    sfp = fopen("student.txt", "r");
    tfp = fopen("teacher.txt", "r");
    printf("Enter username: ");
    scanf("%s",i.username);
    printf("Enter password: ");
    scanf("%s",i.password);
    char username[MAX_USERNAME_LENGTH], password[MAX_PASSWORD_LENGTH];
    while(fscanf(tfp, "%s %s", username,password) != EOF){
        if(strcmp(username,i.username)==0 && strcmp(password,i.password)==0){
            fclose(tfp);
            printf("LogIn successfull!\n");
            teacherDashboard();
        }
    }
     while(fscanf(sfp, "%s %s", username,password) != EOF){
        if(strcmp(username,i.username)==0 && strcmp(password,i.password)==0){
            fclose(sfp);
            printf("LogIn successfull\n");
            studentDashboard();
        }
    }
}
void teacherDashboard(){
	int choice;
    while (1) {
        printf("1. Maitain Attendence\n");
        printf("2. Assign Marks\n");
        printf("3. Update Password\n");
        printf("4. Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                //maintainAttendence();
                break;
            case 2:
                //assignMarks();
                break;
            case 3:
                updatePass();
                break;
            case 4:
                main();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}
void studentDashboard(){
    int choice;
    while (1) {
        printf("1. Course Enrollment\n");
        printf("2. View Marks\n");
        printf("3. Generate Transcipt\n");
        printf("4. Update Password\n");
        printf("5. Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                //courseEnrollment();
                break;
            case 2:
                //viewMarks();
                break;
            case 3:
                //generateTranscipt(); 
                break;
            case 4:
                updatePass();
                break;
            case 5:
                main();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}
//void courseEnrollment(){
//
//}
//void viewMarks(){
//
//}
//void generateTranscipt(){
//
//}
void updatePass(){
	struct ui i;
	char username[30],oldPass[8],newPass[8];
    FILE *sfp = fopen("student.txt","r");
    FILE *tfp = fopen("teacher.txt","r");
    FILE *temp = fopen("temp.txt","w");
    printf("Enter Username:");
    scanf("%s",i.username);
    printf("Enter Old Password:");
    scanf("%s",i.password);
    while(fscanf(sfp,"%s %s",&username,&oldPass)!=EOF){
        if(strcmp(username,i.username)==0 && strcmp(oldPass,i.password)==0){
        	printf("Enter New Password:");
            scanf("%s",&newPass);
			fprintf(temp,"%s %s\n",username,newPass);
            printf("Password Updated Successfully.....\n");
        }else{
        	fprintf(temp,"%s %s\n",username,oldPass);
		}
    } 
    fclose(temp);
	fclose(sfp);
	remove("student.txt");
	rename("temp.txt","student.txt");
	temp = fopen("temp.txt","w");
    while(fscanf(tfp,"%s %s\n",username,&oldPass)!=EOF){
        if(strcmp(username,i.username)==0 && strcmp(oldPass,i.password)==0){
        	printf("Enter New Password:");
            scanf("%s",&newPass);
			fprintf(temp,"%s %s\n",username,newPass);
            printf("Password Updated Successfully.....\n"); 
        }else{
        	fprintf(temp,"%s %s\n",username,oldPass);
		}
    }  
	fclose(temp);
	fclose(tfp);
	remove("teacher.txt");
	rename("temp.txt","teacher.txt"); 
}
int main() {
    int choice;
    while (1) {
        printf("1. Sign Up\n");
        printf("2. Sign In\n");
        printf("3. Exit\n");
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
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}