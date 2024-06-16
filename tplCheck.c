#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 60
#define MAX_USERNAME_LENGTH 30
#define MAX_PASSWORD_LENGTH 8
void teacherDashboard();
void studentDashboard();
void courseEnrollment();
void autoEnrollment(int n,char name[30]);
void showCourses(int semester);
int courseEnrollmentCheck(char name[25],char status[5]);
void updatePass();
struct  ui{//cd 'C:\TurboC++\Disk\TurboC3\BIN> /.tplCheck.exe'
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
            printf("Log In successfull...\n");
            teacherDashboard();
        }
    }
     while(fscanf(sfp, "%s %s", username,password) != EOF){
        if(strcmp(username,i.username)==0 && strcmp(password,i.password)==0){
            fclose(sfp);
            printf("Log In successfull...\n");
            studentDashboard();
        }
    }
    printf("Username or Password Incorrect....");
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
void courseEnrollment(){
    char txt[4]=".txt",name[30];
    printf("Enter Your Name:");
    gets(name);
    strcat(name,txt);
    int minusCourse = courseEnrollmentCheck(name,"Pass");
    int id,i,sem;
    printf("Enter Smester:");
    scanf("%d",&sem);
    showCourses(sem);
    if(minusCourse<5){
    for(i=0;i<5-minusCourse;i++){
        printf("Enter Course ID:");
        scanf("%s",&id);
    }
    }
    if(minusCourse>0){
       autoEnrollment(minusCourse,name);
    }
}
void autoEnrollment(int n,char name[30]){
    int i;
    char courseName[50],courseId[5],status[5];
    FILE *studentFileCheck = fopen(name,"a");
    while(fscanf(studentFileCheck,"%s %s %s\n",courseName,courseId,status)!=EOF){
        if(status=="Fail"){

        }
    }
}
void showCourses(int semester){
    int semster;
    FILE *sem;
    switch (semster)
    {
    case 1:
        sem = fopen("1st.txt","a");
        break;
    case 2:
        sem = fopen("1st.txt","a");
        break;
    case 3:
        sem = fopen("1st.txt","a");
        break;
    case 4:
        sem = fopen("1st.txt","a");
        break;
    case 5:
        sem = fopen("1st.txt","a");
        break;
    case 6:
        sem = fopen("1st.txt","a");
        break;
    case 7:
        sem = fopen("1st.txt","a");
        break;
        
    default:
        break;
    }
    char courseName[50],courseId[10];
    printf("Course ID         Coure Name\n");
    FILE *courseFile = fopen("courses.txt","r");
    while(fscanf(courseFile,"%s\n%s\n",courseName,courseId)!=EOF){
        puts(courseId);
        printf("        ");
        puts(courseName);
        printf("\n");
    }
}
int  courseEnrollmentCheck(char name[25],char status[5]){
    int i=0;
    char txt[4]=".txt",failOrPass[10]="Fail",courseName[50],courseId[5];
    strcat(name,txt);
    FILE *studentFileName = fopen(name,"r");
    if(name==NULL){
        printf("No Record Found...\n");
        return;
    }else{
        while(fscanf(studentFileName,"%s %s %s\n",courseName,courseId,status)!=EOF){
            if(strcmp(status,"Pass")==0){
                continue;
            }else if(strcmp(status,failOrPass)!=0){
                strcpy(status,"Fail");
                i++;
            }
        }
    }
    return i;
}
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