#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include<graphics.h>
// Structure Start
struct Faculty
{
    char name[20];
    char grade[20];
    char statusVR[12];
    char statusIE[10];
    // get data from here
    char department[20], program[10], month[15], course[30];
    char semester[10];
    char section[3];
    int class;
    // add lecture details
    char lecture[13][80], date[13][11], timein[13][10], timeout[13][10], remarks[13][15];
    char duration[13][4];
    // billing
    long int salary, total;
    float tax;
    long int  count;
} faculty;

// Structure end

// my function prototype
void menu();
void add();
void view();

void main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm, "C:\\TURBOC3\\BGI");
	cleardevice();
	//setbkcolor(BLUE);
	settextstyle(7,0,3);
	outtextxy(260,20,"WELCOME");
	settextstyle(7,0,3);
	outtextxy(300,60,"TO");
	settextstyle(7,0,3); //(style,direction 0 for v 1 for h,text size)
	outtextxy(55,110,"SINDH MADRESSATUL ISLAM UNIVERSITY");
	settextstyle(7,0,3);
	outtextxy(270,170,"KARACHI");
	settextstyle(7,0,3);
	outtextxy(55,240,"VISITING FACULTY MANAGEMENT SYSTEM");
	delay(500);
	//getch();
	cleardevice();
	settextstyle(8,0,3);
	outtextxy(1,50,"Press any key to continue...");
	menu();
	closegraph();
}

void menu()
{
    int choice;
    Menu:
    cleardevice();
    settextstyle(1,0,4);
    outtextxy(240,1,"Menu");
    line(240,35,320,35);
    line(240,40,320,40);
    settextstyle(2,0,6);
    outtextxy(1,55,"Enter a key to perform a task.");
    gotoxy(2,8);
    printf("1.");
    gotoxy(5,8);
    printf("Add Lecture Records");
    gotoxy(2,9);
    printf("2.");
    gotoxy(5,9);
    printf("View Lecture Records");
    gotoxy(2,10);
    printf("3.");
    gotoxy(5,10);
    printf("Exit");
    line(155,192,195,192);
    gotoxy(2,12);
    printf("Enter your Choice:");
    gotoxy(22,12);
    scanf("%d", &choice);
    cleardevice();
    switch (choice)
    {

    case 1:
	add();
	break;

	case 2:
	view();
	break;

    case 3:
	exit(0);
	break;

    default:
	cleardevice();
	gotoxy(25,12);
	printf("Please Enter a right key!");
	getch();
	cleardevice();
	break;
    }
    goto Menu;

}
// function defination

void add()
{
    int i;
    char yn = 'y',choice1, choice2, choice3, select;
    FILE *fp;
    fp = fopen("add_record.txt", "ab+");
    cleardevice();

    if (fp == NULL)
    {
	gotoxy(37,12);
	printf("Error opening file");
	delay(1000);
	exit(0);
    }
    fflush(stdin);

    while (yn == 'y' || yn == 'Y')
    {
	faculty.count = 0;
	settextstyle(1,0,5);
	outtextxy(60,1,"Teacher Data Registration");
	line(60,45,393,45);
	line(60,50,393,50);
	line(417,45,595,45);
	line(417,50,595,50);
	fflush(stdin);
	gotoxy(1,10);
	printf("Enter Your name: ");
	line(128,160,300,160);
	gets(faculty.name);

    back:
	settextstyle(1,0,5);
	outtextxy(60,1,"Teacher Data Registration");
	line(60,45,393,45);
	line(60,50,393,50);
	line(417,45,595,45);
	line(417,50,595,50);
	gotoxy(1,10);
	printf("Enter Your name: %s",faculty.name);
	line(128,160,300,160);
	gotoxy(1,12);
	printf("Select Your Grade:\n");
	printf("a. Professor\nb. Assistant Professor\nc. Lecturer\nd. Assistant Lecturer\n");
	line(145,192,165,192);
	fflush(stdin);
	gotoxy(20,12);
	choice1 = getchar();
	cleardevice();
	settextstyle(1,0,5);
	outtextxy(60,1,"Teacher Data Registration");
	line(60,45,393,45);
	line(60,50,393,50);
	line(417,45,595,45);
	line(417,50,595,50);
      if (choice1 == 'a' || choice1 == 'A')
	{
	    strcpy(faculty.grade, "Professor");
	    gotoxy(1,10);
	    printf("%s", faculty.grade);
	}
	else if (choice1 == 'b' || choice1 == 'B')
	{
	    strcpy(faculty.grade, "Assistant Professor");
	    gotoxy(1,10);
	    printf("%s", faculty.grade);
	}
	else if (choice1 == 'c' || choice1 == 'C')
	{
	    strcpy(faculty.grade, "Lecturer");
	    gotoxy(1,10);
	    printf("%s", faculty.grade);
	}
	else if (choice1 == 'd' || choice1 == 'D')
	{
	    strcpy(faculty.grade, "Assistant Lecturer");
	    gotoxy(1,10);
	    printf("%s", faculty.grade);
	}
	else
	{
	    cleardevice();
	    gotoxy(25,12);
	    printf("Please Enter a right key!");
	    getch();
	    cleardevice();
	    goto back;
	}

	backch2:
	cleardevice();
	settextstyle(1,0,5);
	outtextxy(60,1,"Teacher Data Registration");
	line(60,45,393,45);
	line(60,50,393,50);
	line(417,45,595,45);
	line(417,50,595,50);
	gotoxy(1,10);
	printf("%s", faculty.grade);
	gotoxy(1,15);
	printf("Enter Your Choice:\na. Internal\nb. External");
	line(147,240,165,240);
	fflush(stdin);
	gotoxy(20,15);
	choice2 = getchar();
	cleardevice();
	if (choice2 == 'a' || choice2 == 'A')
	{
	    strcpy(faculty.statusIE, "Internal");
	    gotoxy(1,10);
	    printf("%s/%s",faculty.grade,faculty.statusIE);
	}
	else if (choice2 == 'b' || choice2 == 'B')
	{
	    strcpy(faculty.statusIE, "External");
	    gotoxy(1,10);
	    printf("%s/%s",faculty.grade,faculty.statusIE);
	}
	else
	{   cleardevice();
	    gotoxy(25,12);
	    printf("Please Enter a right key!");
	    getch();
	    cleardevice();
	    goto backch2;
	}

	backch3:
	gotoxy(1,10);
	printf("%s/%s",faculty.grade,faculty.statusIE);
	settextstyle(1,0,5);
	outtextxy(60,1,"Teacher Data Registration");
	line(60,45,393,45);
	line(60,50,393,50);
	line(417,45,595,45);
	line(417,50,595,50);
	gotoxy(1,13);
	printf("Enter Your choice:\na. Visitor\nb. Regular");
	line(145,208,165,208);
	fflush(stdin);
	gotoxy(20,13);
	choice3 = getchar();
	cleardevice();
	settextstyle(1,0,5);
	outtextxy(60,1,"Teacher Data Registration");
	line(60,45,393,45);
	line(60,50,393,50);
	line(417,45,595,45);
	line(417,50,595,50);
	gotoxy(1,10);
	printf("%s/%s",faculty.grade,faculty.statusIE);
	if (choice3 == 'a' || choice3 == 'A')
	{
	    strcpy(faculty.statusVR, "Visitor");
	    gotoxy(1,7);
	    printf("%s/%s/%s",faculty.grade,faculty.statusIE,faculty.statusVR);
	}
	else if (choice3 == 'b' || choice3 == 'B')
	{
	    strcpy(faculty.statusVR, "Regular");
	    gotoxy(1,7);
	    printf("%s/%s/%s",faculty.grade,faculty.statusIE,faculty.statusVR);
	}
	else
	{   cleardevice();
	    gotoxy(25,12);
	    printf("Please Enter a right key!");
	    getch();
	    cleardevice();
	    goto backch3;
	}
	 cleardevice();
	settextstyle(1,0,5);
	outtextxy(60,1,"Teacher Data Registration");
	line(60,45,393,45);
	line(60,50,393,50);
	line(417,45,595,45);
	line(417,50,595,50);
	gotoxy(1,7);
	printf("%s/%s/%s",faculty.grade,faculty.statusIE,faculty.statusVR);
	fflush(stdin);
	gotoxy(1,10);
	line(135,160,350,160);
	printf("Enter Department: ");
	gets(faculty.department);
	gotoxy(1,12);
	line(113,192,250,192);
	printf("Enter Program: ");
	gets(faculty.program);
	fflush(stdin);
	gotoxy(1,14);
	line(100,224,180,224);
	printf("Enter Month: ");
	gets(faculty.month);
	fflush(stdin);
	gotoxy(1,16);
	line(105,256,350,256);
	printf("Enter Course: ");
	gets(faculty.course);
	gotoxy(1,18);
	line(120,288,160,288);
	printf("Enter Class No: ");
	fflush(stdin);
	scanf("%s", &faculty.class);
	gotoxy(1,20);
	line(116,320,135,320);
	printf("Enter Section: ");
	fflush(stdin);
	gets(faculty.section);
	gotoxy(1,22);
	line(125,352,155,352);
	printf("Enter Semester: ");
	fflush(stdin);
	gets(faculty.semester);
	// lecture added here
	cleardevice();
	for (i = 0; i < 13; i++)
	{
	settextstyle(1,0,5);
	outtextxy(60,1,"Teacher Data Registration");
	line(60,45,393,45);
	line(60,50,393,50);
	line(417,45,595,45);
	line(417,50,595,50);
	gotoxy(1,7);
	printf("%s/%s/%s",faculty.grade,faculty.statusIE,faculty.statusVR);
	    fflush(stdin);
	    gotoxy(1,9);
	    printf("Insert Lectures %d Details \n", i + 1);
	    gotoxy(1,12);
	    line(185,192,350,192);
	    printf("Enter lecture %d topics: ", i + 1);
	    gets(faculty.lecture[i]);
	    gotoxy(1,14);
	    line(185,224,300,224);
	    printf("Enter date(dd-mm-yyyy): ");
	    gets(faculty.date[i]);
	    gotoxy(1,16);
	    line(180,256,228,256);
	    printf("Enter Time in (hh:mm): ");
	    gets(faculty.timein[i]);
	    gotoxy(1,18);
	    line(185,288,237,288);
	    printf("Enter Time out (hh:mm): ");
	    gets(faculty.timeout[i]);
	    gotoxy(1,20);
	    line(175,320,220,320);
	    printf("Enter total Duration:  ");
	    fflush(stdin);
	    scanf("%s",&faculty.duration[i]);
	    fflush(stdin);
	back4:
	    gotoxy(1,22);
	    line(60,352,75,352);
	    printf("Select:");
	    gotoxy(1,24);
	    printf("Chose Remarks : \na) Present\nb) Absent\nc) Makeup \n");
	    gotoxy(9,22);
	    select = getchar();
	    if (select == 'a' || select == 'A')
	    {
		strcpy(faculty.remarks[i], "Present");
		faculty.count = faculty.count + 1;
	    }
	    else if (select == 'b' || select == 'B')
	    {
		strcpy(faculty.remarks[i], "Absent");
	    }
	    else if (select == 'c' || select == 'C')
	    {
		strcpy(faculty.remarks[i], "MakeUp");
		faculty.count = faculty.count + 1;
	    }
	    else
	    {   cleardevice();
		goto back4;
	    }
	    cleardevice();
	}
	//gotoxy();
	printf("Bill Generated\nTotal no of present is %d\n", faculty.count);
	// printf("total count %d\n", count);
	fflush(stdin);
	if (choice1 == 'a')
	{
	    cleardevice();
	    rectangle(1,100,639,352);// record
	    line(1,140,639,140);     //1 h
	    line(42,100,42,352);     //0-1 v  S.no.
	    line(240,100,240,352);   //1-2 v  Date
	    line(310,100,310,352);   //2-3 v  Time in
	    line(390,100,390,352);   //3-4 v  Time out
	    line(445,100,445,352);   //4-5 v  Total Hours taught
	    line(545,100,545,352);   //5-6 v  Teacher sign and Remarks
	    gotoxy(1,3);
	    printf("Name: %s",faculty.name);
	    gotoxy(40,3);
	    printf("Month: %s",faculty.month);
	    gotoxy(1,4);
	    printf("Department: %s",faculty.department);
	    gotoxy(40,4);
	    printf("Semester: %s",faculty.semester);
	    gotoxy(1,5);
	    printf("Program: %s",faculty.program);
	    gotoxy(40,5);
	    printf("Course: %s",faculty.course);
	    gotoxy(1,6);
	    printf("Section: %s",faculty.section);
	    gotoxy(2,8);
	    printf("S.No");
	    gotoxy(16,8);
	    printf("Topic");
	    gotoxy(7,10);
	    printf("%s",faculty.lecture[0]);
	    gotoxy(7,11);
	    printf("%s",faculty.lecture[1]);
	    gotoxy(7,12);
	    printf("%s",faculty.lecture[2]);
	    gotoxy(7,13);
	    printf("%s",faculty.lecture[3]);
	    gotoxy(7,14);
	    printf("%s",faculty.lecture[4]);
	    gotoxy(7,15);
	    printf("%s",faculty.lecture[5]);
	    gotoxy(7,16);
	    printf("%s",faculty.lecture[6]);
	    gotoxy(7,17);
	    printf("%s",faculty.lecture[7]);
	    gotoxy(7,18);
	    printf("%s",faculty.lecture[8]);
	    gotoxy(7,19);
	    printf("%s",faculty.lecture[9]);
	    gotoxy(7,20);
	    printf("%s",faculty.lecture[10]);
	    gotoxy(7,21);
	    printf("%s",faculty.lecture[11]);
	    gotoxy(7,22);
	    printf("%s",faculty.lecture[12]);
	    gotoxy(32,8);
	    printf("Time-In");
	    gotoxy(33,10);
	    printf("%s",faculty.timein[0]);
	    gotoxy(33,11);
	    printf("%s",faculty.timein[1]);
	    gotoxy(33,12);
	    printf("%s",faculty.timein[2]);
	    gotoxy(33,13);
	    printf("%s",faculty.timein[3]);
	    gotoxy(33,14);
	    printf("%s",faculty.timein[4]);
	    gotoxy(33,15);
	    printf("%s",faculty.timein[5]);
	    gotoxy(33,16);
	    printf("%s",faculty.timein[6]);
	    gotoxy(33,17);
	    printf("%s",faculty.timein[7]);
	    gotoxy(33,18);
	    printf("%s",faculty.timein[8]);
	    gotoxy(33,19);
	    printf("%s",faculty.timein[9]);
	    gotoxy(33,20);
	    printf("%s",faculty.timein[10]);
	    gotoxy(33,21);
	    printf("%s",faculty.timein[11]);
	    gotoxy(33,22);
	    printf("%s",faculty.timein[12]);
	    gotoxy(41,8);
	    printf("Time-Out");
	    gotoxy(42,10);
	    printf("%s",faculty.timeout[0]);
	    gotoxy(42,11);
	    printf("%s",faculty.timeout[1]);
	    gotoxy(42,12);
	    printf("%s",faculty.timeout[2]);
	    gotoxy(42,13);
	    printf("%s",faculty.timeout[3]);
	    gotoxy(42,14);
	    printf("%s",faculty.timeout[4]);
	    gotoxy(42,15);
	    printf("%s",faculty.timeout[5]);
	    gotoxy(42,16);
	    printf("%s",faculty.timeout[6]);
	    gotoxy(42,17);
	    printf("%s",faculty.timeout[7]);
	    gotoxy(42,18);
	    printf("%s",faculty.timeout[8]);
	    gotoxy(42,19);
	    printf("%s",faculty.timeout[9]);
	    gotoxy(42,20);
	    printf("%s",faculty.timeout[10]);
	    gotoxy(42,21);
	    printf("%s",faculty.timeout[11]);
	    gotoxy(42,22);
	    printf("%s",faculty.timeout[12]);
	    gotoxy(51,8);
	    printf("hours");
	    gotoxy(52,10);
	    printf("%s",faculty.duration[0]);
	    gotoxy(52,11);
	    printf("%s",faculty.duration[1]);
	    gotoxy(52,12);
	    printf("%s",faculty.duration[2]);
	    gotoxy(52,13);
	    printf("%s",faculty.duration[3]);
	    gotoxy(52,14);
	    printf("%s",faculty.duration[4]);
	    gotoxy(52,15);
	    printf("%s",faculty.duration[5]);
	    gotoxy(52,16);
	    printf("%s",faculty.duration[6]);
	    gotoxy(52,17);
	    printf("%s",faculty.duration[7]);
	    gotoxy(52,18);
	    printf("%s",faculty.duration[8]);
	    gotoxy(52,19);
	    printf("%s",faculty.duration[9]);
	    gotoxy(52,20);
	    printf("%s",faculty.duration[10]);
	    gotoxy(52,21);
	    printf("%s",faculty.duration[11]);
	    gotoxy(52,22);
	    printf("%s",faculty.duration[12]);
	    gotoxy(61,8);
	    printf("Date");
	    gotoxy(59,10);
	    printf("%s",faculty.date[0]);
	    gotoxy(59,11);
	    printf("%s",faculty.date[1]);
	    gotoxy(59,12);
	    printf("%s",faculty.date[2]);
	    gotoxy(59,13);
	    printf("%s",faculty.date[3]);
	    gotoxy(59,14);
	    printf("%s",faculty.date[4]);
	    gotoxy(59,15);
	    printf("%s",faculty.date[5]);
	    gotoxy(59,16);
	    printf("%s",faculty.date[6]);
	    gotoxy(59,17);
	    printf("%s",faculty.date[7]);
	    gotoxy(59,18);
	    printf("%s",faculty.date[8]);
	    gotoxy(59,19);
	    printf("%s",faculty.date[9]);
	    gotoxy(59,20);
	    printf("%s",faculty.date[10]);
	    gotoxy(59,21);
	    printf("%s",faculty.date[11]);
	    gotoxy(59,22);
	    printf("%s",faculty.date[12]);
	    gotoxy(72,8);
	    printf("Remarks");
	    gotoxy(72,10);
	    printf("%s",faculty.remarks[0]);
	    gotoxy(72,11);
	    printf("%s",faculty.remarks[1]);
	    gotoxy(72,12);
	    printf("%s",faculty.remarks[2]);
	    gotoxy(72,13);
	    printf("%s",faculty.remarks[3]);
	    gotoxy(72,14);
	    printf("%s",faculty.remarks[4]);
	    gotoxy(72,15);
	    printf("%s",faculty.remarks[5]);
	    gotoxy(72,16);
	    printf("%s",faculty.remarks[6]);
	    gotoxy(72,17);
	    printf("%s",faculty.remarks[7]);
	    gotoxy(72,18);
	    printf("%s",faculty.remarks[8]);
	    gotoxy(72,19);
	    printf("%s",faculty.remarks[9]);
	    gotoxy(72,20);
	    printf("%s",faculty.remarks[10]);
	    gotoxy(72,21);
	    printf("%s",faculty.remarks[11]);
	    gotoxy(72,22);
	    printf("%s",faculty.remarks[12]);
	    //lec no.
	    gotoxy(2,10);
	    printf("1");
	    gotoxy(2,11);
	    printf("2");
	    gotoxy(2,12);
	    printf("3");
	    gotoxy(2,13);
	    printf("4");
	    gotoxy(2,14);
	    printf("5");
	    gotoxy(2,15);
	    printf("6");
	    gotoxy(2,16);
	    printf("7");
	    gotoxy(2,17);
	    printf("8");
	    gotoxy(2,18);
	    printf("9");
	    gotoxy(2,19);
	    printf("10");
	    gotoxy(2,20);
	    printf("11");
	    gotoxy(2,21);
	    printf("12");
	    gotoxy(2,22);
	    printf("13");
	    faculty.salary = faculty.count * 3000;
	    gotoxy(1,24);
	    printf("Salary:%ld",(long int)faculty.salary);
	    faculty.tax = (faculty.salary * 15.0) / 100.0;
	    faculty.total = (faculty.salary - faculty.tax);
	    gotoxy(35,24);
	    printf("Tax:%.2f\n", faculty.tax);
	    gotoxy(60,24);
	    printf("Total Amount: %ld\n",(long int)faculty.total);
	    getch();
	}
	else if (choice1 == 'b')
	{
	    cleardevice();
	    rectangle(1,100,639,352);// record
	    line(1,140,639,140);     //1 h
	    line(42,100,42,352);     //0-1 v  S.no.
	    line(240,100,240,352);   //1-2 v  Date
	    line(310,100,310,352);   //2-3 v  Time in
	    line(390,100,390,352);   //3-4 v  Time out
	    line(445,100,445,352);   //4-5 v  Total Hours taught
	    line(545,100,545,352);   //5-6 v  Teacher sign and Remarks
	    gotoxy(1,3);
	    printf("Name: %s",faculty.name);
	    gotoxy(40,3);
	    printf("Month: %s",faculty.month);
	    gotoxy(1,4);
	    printf("Department: %s",faculty.department);
	    gotoxy(40,4);
	    printf("Semester: %s",faculty.semester);
	    gotoxy(1,5);
	    printf("Program: %s",faculty.program);
	    gotoxy(40,5);
	    printf("Course: %s",faculty.course);
	    gotoxy(1,6);
	    printf("Section: %s",faculty.section);
	    gotoxy(2,8);
	    printf("S.No");
	    gotoxy(16,8);
	    printf("Topic");
	    gotoxy(7,10);
	    printf("%s",faculty.lecture[0]);
	    gotoxy(7,11);
	    printf("%s",faculty.lecture[1]);
	    gotoxy(7,12);
	    printf("%s",faculty.lecture[2]);
	    gotoxy(7,13);
	    printf("%s",faculty.lecture[3]);
	    gotoxy(7,14);
	    printf("%s",faculty.lecture[4]);
	    gotoxy(7,15);
	    printf("%s",faculty.lecture[5]);
	    gotoxy(7,16);
	    printf("%s",faculty.lecture[6]);
	    gotoxy(7,17);
	    printf("%s",faculty.lecture[7]);
	    gotoxy(7,18);
	    printf("%s",faculty.lecture[8]);
	    gotoxy(7,19);
	    printf("%s",faculty.lecture[9]);
	    gotoxy(7,20);
	    printf("%s",faculty.lecture[10]);
	    gotoxy(7,21);
	    printf("%s",faculty.lecture[11]);
	    gotoxy(7,22);
	    printf("%s",faculty.lecture[12]);
	    gotoxy(32,8);
	    printf("Time-In");
	    gotoxy(33,10);
	    printf("%s",faculty.timein[0]);
	    gotoxy(33,11);
	    printf("%s",faculty.timein[1]);
	    gotoxy(33,12);
	    printf("%s",faculty.timein[2]);
	    gotoxy(33,13);
	    printf("%s",faculty.timein[3]);
	    gotoxy(33,14);
	    printf("%s",faculty.timein[4]);
	    gotoxy(33,15);
	    printf("%s",faculty.timein[5]);
	    gotoxy(33,16);
	    printf("%s",faculty.timein[6]);
	    gotoxy(33,17);
	    printf("%s",faculty.timein[7]);
	    gotoxy(33,18);
	    printf("%s",faculty.timein[8]);
	    gotoxy(33,19);
	    printf("%s",faculty.timein[9]);
	    gotoxy(33,20);
	    printf("%s",faculty.timein[10]);
	    gotoxy(33,21);
	    printf("%s",faculty.timein[11]);
	    gotoxy(33,22);
	    printf("%s",faculty.timein[12]);
	    gotoxy(41,8);
	    printf("Time-Out");
	    gotoxy(42,10);
	    printf("%s",faculty.timeout[0]);
	    gotoxy(42,11);
	    printf("%s",faculty.timeout[1]);
	    gotoxy(42,12);
	    printf("%s",faculty.timeout[2]);
	    gotoxy(42,13);
	    printf("%s",faculty.timeout[3]);
	    gotoxy(42,14);
	    printf("%s",faculty.timeout[4]);
	    gotoxy(42,15);
	    printf("%s",faculty.timeout[5]);
	    gotoxy(42,16);
	    printf("%s",faculty.timeout[6]);
	    gotoxy(42,17);
	    printf("%s",faculty.timeout[7]);
	    gotoxy(42,18);
	    printf("%s",faculty.timeout[8]);
	    gotoxy(42,19);
	    printf("%s",faculty.timeout[9]);
	    gotoxy(42,20);
	    printf("%s",faculty.timeout[10]);
	    gotoxy(42,21);
	    printf("%s",faculty.timeout[11]);
	    gotoxy(42,22);
	    printf("%s",faculty.timeout[12]);
	    gotoxy(51,8);
	    printf("hours");
	    gotoxy(52,10);
	    printf("%s",faculty.duration[0]);
	    gotoxy(52,11);
	    printf("%s",faculty.duration[1]);
	    gotoxy(52,12);
	    printf("%s",faculty.duration[2]);
	    gotoxy(52,13);
	    printf("%s",faculty.duration[3]);
	    gotoxy(52,14);
	    printf("%s",faculty.duration[4]);
	    gotoxy(52,15);
	    printf("%s",faculty.duration[5]);
	    gotoxy(52,16);
	    printf("%s",faculty.duration[6]);
	    gotoxy(52,17);
	    printf("%s",faculty.duration[7]);
	    gotoxy(52,18);
	    printf("%s",faculty.duration[8]);
	    gotoxy(52,19);
	    printf("%s",faculty.duration[9]);
	    gotoxy(52,20);
	    printf("%s",faculty.duration[10]);
	    gotoxy(52,21);
	    printf("%s",faculty.duration[11]);
	    gotoxy(52,22);
	    printf("%s",faculty.duration[12]);
	    gotoxy(61,8);
	    printf("Date");
	    gotoxy(59,10);
	    printf("%s",faculty.date[0]);
	    gotoxy(59,11);
	    printf("%s",faculty.date[1]);
	    gotoxy(59,12);
	    printf("%s",faculty.date[2]);
	    gotoxy(59,13);
	    printf("%s",faculty.date[3]);
	    gotoxy(59,14);
	    printf("%s",faculty.date[4]);
	    gotoxy(59,15);
	    printf("%s",faculty.date[5]);
	    gotoxy(59,16);
	    printf("%s",faculty.date[6]);
	    gotoxy(59,17);
	    printf("%s",faculty.date[7]);
	    gotoxy(59,18);
	    printf("%s",faculty.date[8]);
	    gotoxy(59,19);
	    printf("%s",faculty.date[9]);
	    gotoxy(59,20);
	    printf("%s",faculty.date[10]);
	    gotoxy(59,21);
	    printf("%s",faculty.date[11]);
	    gotoxy(59,22);
	    printf("%s",faculty.date[12]);
	    gotoxy(72,8);
	    printf("Remarks");
	    gotoxy(72,10);
	    printf("%s",faculty.remarks[0]);
	    gotoxy(72,11);
	    printf("%s",faculty.remarks[1]);
	    gotoxy(72,12);
	    printf("%s",faculty.remarks[2]);
	    gotoxy(72,13);
	    printf("%s",faculty.remarks[3]);
	    gotoxy(72,14);
	    printf("%s",faculty.remarks[4]);
	    gotoxy(72,15);
	    printf("%s",faculty.remarks[5]);
	    gotoxy(72,16);
	    printf("%s",faculty.remarks[6]);
	    gotoxy(72,17);
	    printf("%s",faculty.remarks[7]);
	    gotoxy(72,18);
	    printf("%s",faculty.remarks[8]);
	    gotoxy(72,19);
	    printf("%s",faculty.remarks[9]);
	    gotoxy(72,20);
	    printf("%s",faculty.remarks[10]);
	    gotoxy(72,21);
	    printf("%s",faculty.remarks[11]);
	    gotoxy(72,22);
	    printf("%s",faculty.remarks[12]);
	    //lec no.
	    gotoxy(2,10);
	    printf("1");
	    gotoxy(2,11);
	    printf("2");
	    gotoxy(2,12);
	    printf("3");
	    gotoxy(2,13);
	    printf("4");
	    gotoxy(2,14);
	    printf("5");
	    gotoxy(2,15);
	    printf("6");
	    gotoxy(2,16);
	    printf("7");
	    gotoxy(2,17);
	    printf("8");
	    gotoxy(2,18);
	    printf("9");
	    gotoxy(2,19);
	    printf("10");
	    gotoxy(2,20);
	    printf("11");
	    gotoxy(2,21);
	    printf("12");
	    gotoxy(2,22);
	    printf("13");
	    faculty.salary = faculty.count * 2500;
	    gotoxy(1,24);
	    printf("Salary:%ld",(long int)faculty.salary);
	    faculty.tax = (faculty.salary * 15.0) / 100.0;
	    gotoxy(37,24);
	    printf("Tax:%.2f\n", faculty.tax);
	    faculty.total = (faculty.salary - faculty.tax);
	   gotoxy(60,24);
	   printf("Total Amount: %ld\n",(long int) faculty.total);
	   getch();
	}
	else if (choice1 == 'c')
	{
	    cleardevice();
	    rectangle(1,100,639,352);// record
	    line(1,140,639,140);     //1 h
	    line(42,100,42,352);     //0-1 v  S.no.
	    line(240,100,240,352);   //1-2 v  Date
	    line(310,100,310,352);   //2-3 v  Time in
	    line(390,100,390,352);   //3-4 v  Time out
	    line(445,100,445,352);   //4-5 v  Total Hours taught
	    line(545,100,545,352);   //5-6 v  Teacher sign and Remarks
	    gotoxy(1,3);
	    printf("Name: %s",faculty.name);
	    gotoxy(40,3);
	    printf("Month: %s",faculty.month);
	    gotoxy(1,4);
	    printf("Department: %s",faculty.department);
	    gotoxy(40,4);
	    printf("Semester: %s",faculty.semester);
	    gotoxy(1,5);
	    printf("Program: %s",faculty.program);
	    gotoxy(40,5);
	    printf("Course: %s",faculty.course);
	    gotoxy(1,6);
	    printf("Section: %s",faculty.section);
	    gotoxy(2,8);
	    printf("S.No");
	    gotoxy(16,8);
	    printf("Topic");
	    gotoxy(7,10);
	    printf("%s",faculty.lecture[0]);
	    gotoxy(7,11);
	    printf("%s",faculty.lecture[1]);
	    gotoxy(7,12);
	    printf("%s",faculty.lecture[2]);
	    gotoxy(7,13);
	    printf("%s",faculty.lecture[3]);
	    gotoxy(7,14);
	    printf("%s",faculty.lecture[4]);
	    gotoxy(7,15);
	    printf("%s",faculty.lecture[5]);
	    gotoxy(7,16);
	    printf("%s",faculty.lecture[6]);
	    gotoxy(7,17);
	    printf("%s",faculty.lecture[7]);
	    gotoxy(7,18);
	    printf("%s",faculty.lecture[8]);
	    gotoxy(7,19);
	    printf("%s",faculty.lecture[9]);
	    gotoxy(7,20);
	    printf("%s",faculty.lecture[10]);
	    gotoxy(7,21);
	    printf("%s",faculty.lecture[11]);
	    gotoxy(7,22);
	    printf("%s",faculty.lecture[12]);
	    gotoxy(32,8);
	    printf("Time-In");
	    gotoxy(33,10);
	    printf("%s",faculty.timein[0]);
	    gotoxy(33,11);
	    printf("%s",faculty.timein[1]);
	    gotoxy(33,12);
	    printf("%s",faculty.timein[2]);
	    gotoxy(33,13);
	    printf("%s",faculty.timein[3]);
	    gotoxy(33,14);
	    printf("%s",faculty.timein[4]);
	    gotoxy(33,15);
	    printf("%s",faculty.timein[5]);
	    gotoxy(33,16);
	    printf("%s",faculty.timein[6]);
	    gotoxy(33,17);
	    printf("%s",faculty.timein[7]);
	    gotoxy(33,18);
	    printf("%s",faculty.timein[8]);
	    gotoxy(33,19);
	    printf("%s",faculty.timein[9]);
	    gotoxy(33,20);
	    printf("%s",faculty.timein[10]);
	    gotoxy(33,21);
	    printf("%s",faculty.timein[11]);
	    gotoxy(33,22);
	    printf("%s",faculty.timein[12]);
	    gotoxy(41,8);
	    printf("Time-Out");
	    gotoxy(42,10);
	    printf("%s",faculty.timeout[0]);
	    gotoxy(42,11);
	    printf("%s",faculty.timeout[1]);
	    gotoxy(42,12);
	    printf("%s",faculty.timeout[2]);
	    gotoxy(42,13);
	    printf("%s",faculty.timeout[3]);
	    gotoxy(42,14);
	    printf("%s",faculty.timeout[4]);
	    gotoxy(42,15);
	    printf("%s",faculty.timeout[5]);
	    gotoxy(42,16);
	    printf("%s",faculty.timeout[6]);
	    gotoxy(42,17);
	    printf("%s",faculty.timeout[7]);
	    gotoxy(42,18);
	    printf("%s",faculty.timeout[8]);
	    gotoxy(42,19);
	    printf("%s",faculty.timeout[9]);
	    gotoxy(42,20);
	    printf("%s",faculty.timeout[10]);
	    gotoxy(42,21);
	    printf("%s",faculty.timeout[11]);
	    gotoxy(42,22);
	    printf("%s",faculty.timeout[12]);
	    gotoxy(51,8);
	    printf("hours");
	    gotoxy(52,10);
	    printf("%s",faculty.duration[0]);
	    gotoxy(52,11);
	    printf("%s",faculty.duration[1]);
	    gotoxy(52,12);
	    printf("%s",faculty.duration[2]);
	    gotoxy(52,13);
	    printf("%s",faculty.duration[3]);
	    gotoxy(52,14);
	    printf("%s",faculty.duration[4]);
	    gotoxy(52,15);
	    printf("%s",faculty.duration[5]);
	    gotoxy(52,16);
	    printf("%s",faculty.duration[6]);
	    gotoxy(52,17);
	    printf("%s",faculty.duration[7]);
	    gotoxy(52,18);
	    printf("%s",faculty.duration[8]);
	    gotoxy(52,19);
	    printf("%s",faculty.duration[9]);
	    gotoxy(52,20);
	    printf("%s",faculty.duration[10]);
	    gotoxy(52,21);
	    printf("%s",faculty.duration[11]);
	    gotoxy(52,22);
	    printf("%s",faculty.duration[12]);
	    gotoxy(61,8);
	    printf("Date");
	    gotoxy(59,10);
	    printf("%s",faculty.date[0]);
	    gotoxy(59,11);
	    printf("%s",faculty.date[1]);
	    gotoxy(59,12);
	    printf("%s",faculty.date[2]);
	    gotoxy(59,13);
	    printf("%s",faculty.date[3]);
	    gotoxy(59,14);
	    printf("%s",faculty.date[4]);
	    gotoxy(59,15);
	    printf("%s",faculty.date[5]);
	    gotoxy(59,16);
	    printf("%s",faculty.date[6]);
	    gotoxy(59,17);
	    printf("%s",faculty.date[7]);
	    gotoxy(59,18);
	    printf("%s",faculty.date[8]);
	    gotoxy(59,19);
	    printf("%s",faculty.date[9]);
	    gotoxy(59,20);
	    printf("%s",faculty.date[10]);
	    gotoxy(59,21);
	    printf("%s",faculty.date[11]);
	    gotoxy(59,22);
	    printf("%s",faculty.date[12]);
	    gotoxy(72,8);
	    printf("Remarks");
	    gotoxy(72,10);
	    printf("%s",faculty.remarks[0]);
	    gotoxy(72,11);
	    printf("%s",faculty.remarks[1]);
	    gotoxy(72,12);
	    printf("%s",faculty.remarks[2]);
	    gotoxy(72,13);
	    printf("%s",faculty.remarks[3]);
	    gotoxy(72,14);
	    printf("%s",faculty.remarks[4]);
	    gotoxy(72,15);
	    printf("%s",faculty.remarks[5]);
	    gotoxy(72,16);
	    printf("%s",faculty.remarks[6]);
	    gotoxy(72,17);
	    printf("%s",faculty.remarks[7]);
	    gotoxy(72,18);
	    printf("%s",faculty.remarks[8]);
	    gotoxy(72,19);
	    printf("%s",faculty.remarks[9]);
	    gotoxy(72,20);
	    printf("%s",faculty.remarks[10]);
	    gotoxy(72,21);
	    printf("%s",faculty.remarks[11]);
	    gotoxy(72,22);
	    printf("%s",faculty.remarks[12]);
	    //lec no.
	    gotoxy(2,10);
	    printf("1");
	    gotoxy(2,11);
	    printf("2");
	    gotoxy(2,12);
	    printf("3");
	    gotoxy(2,13);
	    printf("4");
	    gotoxy(2,14);
	    printf("5");
	    gotoxy(2,15);
	    printf("6");
	    gotoxy(2,16);
	    printf("7");
	    gotoxy(2,17);
	    printf("8");
	    gotoxy(2,18);
	    printf("9");
	    gotoxy(2,19);
	    printf("10");
	    gotoxy(2,20);
	    printf("11");
	    gotoxy(2,21);
	    printf("12");
	    gotoxy(2,22);
	    printf("13");
	    faculty.salary = faculty.count * 2000;
	    faculty.tax = (faculty.salary * 15.0) / 100.0;
	    gotoxy(1,24);
	    printf("Salary:%ld",(long int)faculty.salary);
	    gotoxy(37,24);
	    printf("Tax:%.2f\n", faculty.tax);
	    faculty.total = (faculty.salary - faculty.tax);
	    gotoxy(60,24);
	    printf("Total Amount: %ld\n",(long int)faculty.total);
	    getch();
	}
	else if (choice1 == 'd')
	{
	    cleardevice();
	    rectangle(1,100,639,352);// record
	    line(1,140,639,140);     //1 h
	    line(42,100,42,352);     //0-1 v  S.no.
	    line(240,100,240,352);   //1-2 v  Date
	    line(310,100,310,352);   //2-3 v  Time in
	    line(390,100,390,352);   //3-4 v  Time out
	    line(445,100,445,352);   //4-5 v  Total Hours taught
	    line(545,100,545,352);   //5-6 v  Teacher sign and Remarks
	    gotoxy(1,3);
	    printf("Name: %s",faculty.name);
	    gotoxy(40,3);
	    printf("Month: %s",faculty.month);
	    gotoxy(1,4);
	    printf("Department: %s",faculty.department);
	    gotoxy(40,4);
	    printf("Semester: %s",faculty.semester);
	    gotoxy(1,5);
	    printf("Program: %s",faculty.program);
	    gotoxy(40,5);
	    printf("Course: %s",faculty.course);
	    gotoxy(1,6);
	    printf("Section: %s",faculty.section);
	    gotoxy(2,8);
	    printf("S.No");
	    gotoxy(16,8);
	    printf("Topic");
	    gotoxy(7,10);
	    printf("%s",faculty.lecture[0]);
	    gotoxy(7,11);
	    printf("%s",faculty.lecture[1]);
	    gotoxy(7,12);
	    printf("%s",faculty.lecture[2]);
	    gotoxy(7,13);
	    printf("%s",faculty.lecture[3]);
	    gotoxy(7,14);
	    printf("%s",faculty.lecture[4]);
	    gotoxy(7,15);
	    printf("%s",faculty.lecture[5]);
	    gotoxy(7,16);
	    printf("%s",faculty.lecture[6]);
	    gotoxy(7,17);
	    printf("%s",faculty.lecture[7]);
	    gotoxy(7,18);
	    printf("%s",faculty.lecture[8]);
	    gotoxy(7,19);
	    printf("%s",faculty.lecture[9]);
	    gotoxy(7,20);
	    printf("%s",faculty.lecture[10]);
	    gotoxy(7,21);
	    printf("%s",faculty.lecture[11]);
	    gotoxy(7,22);
	    printf("%s",faculty.lecture[12]);
	    gotoxy(32,8);
	    printf("Time-In");
	    gotoxy(33,10);
	    printf("%s",faculty.timein[0]);
	    gotoxy(33,11);
	    printf("%s",faculty.timein[1]);
	    gotoxy(33,12);
	    printf("%s",faculty.timein[2]);
	    gotoxy(33,13);
	    printf("%s",faculty.timein[3]);
	    gotoxy(33,14);
	    printf("%s",faculty.timein[4]);
	    gotoxy(33,15);
	    printf("%s",faculty.timein[5]);
	    gotoxy(33,16);
	    printf("%s",faculty.timein[6]);
	    gotoxy(33,17);
	    printf("%s",faculty.timein[7]);
	    gotoxy(33,18);
	    printf("%s",faculty.timein[8]);
	    gotoxy(33,19);
	    printf("%s",faculty.timein[9]);
	    gotoxy(33,20);
	    printf("%s",faculty.timein[10]);
	    gotoxy(33,21);
	    printf("%s",faculty.timein[11]);
	    gotoxy(33,22);
	    printf("%s",faculty.timein[12]);
	    gotoxy(41,8);
	    printf("Time-Out");
	    gotoxy(42,10);
	    printf("%s",faculty.timeout[0]);
	    gotoxy(42,11);
	    printf("%s",faculty.timeout[1]);
	    gotoxy(42,12);
	    printf("%s",faculty.timeout[2]);
	    gotoxy(42,13);
	    printf("%s",faculty.timeout[3]);
	    gotoxy(42,14);
	    printf("%s",faculty.timeout[4]);
	    gotoxy(42,15);
	    printf("%s",faculty.timeout[5]);
	    gotoxy(42,16);
	    printf("%s",faculty.timeout[6]);
	    gotoxy(42,17);
	    printf("%s",faculty.timeout[7]);
	    gotoxy(42,18);
	    printf("%s",faculty.timeout[8]);
	    gotoxy(42,19);
	    printf("%s",faculty.timeout[9]);
	    gotoxy(42,20);
	    printf("%s",faculty.timeout[10]);
	    gotoxy(42,21);
	    printf("%s",faculty.timeout[11]);
	    gotoxy(42,22);
	    printf("%s",faculty.timeout[12]);
	    gotoxy(51,8);
	    printf("hours");
	    gotoxy(52,10);
	    printf("%s",faculty.duration[0]);
	    gotoxy(52,11);
	    printf("%s",faculty.duration[1]);
	    gotoxy(52,12);
	    printf("%s",faculty.duration[2]);
	    gotoxy(52,13);
	    printf("%s",faculty.duration[3]);
	    gotoxy(52,14);
	    printf("%s",faculty.duration[4]);
	    gotoxy(52,15);
	    printf("%s",faculty.duration[5]);
	    gotoxy(52,16);
	    printf("%s",faculty.duration[6]);
	    gotoxy(52,17);
	    printf("%s",faculty.duration[7]);
	    gotoxy(52,18);
	    printf("%s",faculty.duration[8]);
	    gotoxy(52,19);
	    printf("%s",faculty.duration[9]);
	    gotoxy(52,20);
	    printf("%s",faculty.duration[10]);
	    gotoxy(52,21);
	    printf("%s",faculty.duration[11]);
	    gotoxy(52,22);
	    printf("%s",faculty.duration[12]);
	    gotoxy(61,8);
	    printf("Date");
	    gotoxy(59,10);
	    printf("%s",faculty.date[0]);
	    gotoxy(59,11);
	    printf("%s",faculty.date[1]);
	    gotoxy(59,12);
	    printf("%s",faculty.date[2]);
	    gotoxy(59,13);
	    printf("%s",faculty.date[3]);
	    gotoxy(59,14);
	    printf("%s",faculty.date[4]);
	    gotoxy(59,15);
	    printf("%s",faculty.date[5]);
	    gotoxy(59,16);
	    printf("%s",faculty.date[6]);
	    gotoxy(59,17);
	    printf("%s",faculty.date[7]);
	    gotoxy(59,18);
	    printf("%s",faculty.date[8]);
	    gotoxy(59,19);
	    printf("%s",faculty.date[9]);
	    gotoxy(59,20);
	    printf("%s",faculty.date[10]);
	    gotoxy(59,21);
	    printf("%s",faculty.date[11]);
	    gotoxy(59,22);
	    printf("%s",faculty.date[12]);
	    gotoxy(72,8);
	    printf("Remarks");
	    gotoxy(72,10);
	    printf("%s",faculty.remarks[0]);
	    gotoxy(72,11);
	    printf("%s",faculty.remarks[1]);
	    gotoxy(72,12);
	    printf("%s",faculty.remarks[2]);
	    gotoxy(72,13);
	    printf("%s",faculty.remarks[3]);
	    gotoxy(72,14);
	    printf("%s",faculty.remarks[4]);
	    gotoxy(72,15);
	    printf("%s",faculty.remarks[5]);
	    gotoxy(72,16);
	    printf("%s",faculty.remarks[6]);
	    gotoxy(72,17);
	    printf("%s",faculty.remarks[7]);
	    gotoxy(72,18);
	    printf("%s",faculty.remarks[8]);
	    gotoxy(72,19);
	    printf("%s",faculty.remarks[9]);
	    gotoxy(72,20);
	    printf("%s",faculty.remarks[10]);
	    gotoxy(72,21);
	    printf("%s",faculty.remarks[11]);
	    gotoxy(72,22);
	    printf("%s",faculty.remarks[12]);
	    //lec no.
	    gotoxy(2,10);
	    printf("1");
	    gotoxy(2,11);
	    printf("2");
	    gotoxy(2,12);
	    printf("3");
	    gotoxy(2,13);
	    printf("4");
	    gotoxy(2,14);
	    printf("5");
	    gotoxy(2,15);
	    printf("6");
	    gotoxy(2,16);
	    printf("7");
	    gotoxy(2,17);
	    printf("8");
	    gotoxy(2,18);
	    printf("9");
	    gotoxy(2,19);
	    printf("10");
	    gotoxy(2,20);
	    printf("11");
	    gotoxy(2,21);
	    printf("12");
	    gotoxy(2,22);
	    printf("13");
	    faculty.salary = faculty.count * 1500;
	    faculty.tax = (faculty.salary * 15.0) / 100.0;
	    gotoxy(1,24);
	    printf("Salary:%ld",(long int)faculty.salary);
	    gotoxy(37,24);
	    printf("Tax:%.2f\n", faculty.tax);
	    faculty.total = (faculty.salary - faculty.tax);
	    gotoxy(60,24);
	    printf("Total Amount: %ld\n",(long int)faculty.total);
	    getch();

	}

	fwrite(&faculty, sizeof(faculty), 1, fp);
	cleardevice();
	gotoxy(1,10);
	printf("Teacher lecture records added successfully...");
	gotoxy(1,12);
	printf("Do you want to add another registration (y/n) : ");
	fflush(stdin);
	yn = getchar();
    }

    fclose(fp);
    cleardevice();
    gotoxy(20,12);
    printf("Press any key to go for main menu : ");
    getch();
    //closegraph();
    menu();
}

void view()
{
    FILE *fp;
    char sname[20], smonth[15];
    cleardevice();
    printf("Which data you want to view \n");
    printf("Enter Name for search : ");
    fflush(stdin);
    gets(sname);

    fp = fopen("add_records.txt", "rb+");
    if (fp == NULL)
    {
	printf("Error! File Not Read");
	getch();
	exit(0);
    }
    while (fread(&faculty, sizeof(faculty), 1, fp) == 1)
    {
	if (strcmp(sname, faculty.name) == 0)
	{
	    printf("Which month data you want to view : ");
	    fflush(stdin);
	    gets(smonth);
	    fflush(stdin);
	    if (strcmp(smonth, faculty.month) == 0)
	    {
	    cleardevice();
	    rectangle(1,100,639,352);// record
	    line(1,140,639,140);     //1 h
	    line(42,100,42,352);     //0-1 v  S.no.
	    line(240,100,240,352);   //1-2 v  Date
	    line(310,100,310,352);   //2-3 v  Time in
	    line(390,100,390,352);   //3-4 v  Time out
	    line(445,100,445,352);   //4-5 v  Total Hours taught
	    line(545,100,545,352);   //5-6 v  Teacher sign and Remarks
	    gotoxy(1,3);
	    printf("Name: %s",faculty.name);
	    gotoxy(40,3);
	    printf("Month: %s",faculty.month);
	    gotoxy(1,4);
	    printf("Department: %s",faculty.department);
	    gotoxy(40,4);
	    printf("Semester: %s",faculty.semester);
	    gotoxy(1,5);
	    printf("Program: %s",faculty.program);
	    gotoxy(40,5);
	    printf("Course: %s",faculty.course);
	    gotoxy(1,6);
	    printf("Section: %s",faculty.section);
	    gotoxy(2,8);
	    printf("S.No");
	    gotoxy(16,8);
	    printf("Topic");
	    gotoxy(7,10);
	    printf("%s",faculty.lecture[0]);
	    gotoxy(7,11);
	    printf("%s",faculty.lecture[1]);
	    gotoxy(7,12);
	    printf("%s",faculty.lecture[2]);
	    gotoxy(7,13);
	    printf("%s",faculty.lecture[3]);
	    gotoxy(7,14);
	    printf("%s",faculty.lecture[4]);
	    gotoxy(7,15);
	    printf("%s",faculty.lecture[5]);
	    gotoxy(7,16);
	    printf("%s",faculty.lecture[6]);
	    gotoxy(7,17);
	    printf("%s",faculty.lecture[7]);
	    gotoxy(7,18);
	    printf("%s",faculty.lecture[8]);
	    gotoxy(7,19);
	    printf("%s",faculty.lecture[9]);
	    gotoxy(7,20);
	    printf("%s",faculty.lecture[10]);
	    gotoxy(7,21);
	    printf("%s",faculty.lecture[11]);
	    gotoxy(7,22);
	    printf("%s",faculty.lecture[12]);
	    gotoxy(32,8);
	    printf("Time-In");
	    gotoxy(33,10);
	    printf("%s",faculty.timein[0]);
	    gotoxy(33,11);
	    printf("%s",faculty.timein[1]);
	    gotoxy(33,12);
	    printf("%s",faculty.timein[2]);
	    gotoxy(33,13);
	    printf("%s",faculty.timein[3]);
	    gotoxy(33,14);
	    printf("%s",faculty.timein[4]);
	    gotoxy(33,15);
	    printf("%s",faculty.timein[5]);
	    gotoxy(33,16);
	    printf("%s",faculty.timein[6]);
	    gotoxy(33,17);
	    printf("%s",faculty.timein[7]);
	    gotoxy(33,18);
	    printf("%s",faculty.timein[8]);
	    gotoxy(33,19);
	    printf("%s",faculty.timein[9]);
	    gotoxy(33,20);
	    printf("%s",faculty.timein[10]);
	    gotoxy(33,21);
	    printf("%s",faculty.timein[11]);
	    gotoxy(33,22);
	    printf("%s",faculty.timein[12]);
	    gotoxy(41,8);
	    printf("Time-Out");
	    gotoxy(42,10);
	    printf("%s",faculty.timeout[0]);
	    gotoxy(42,11);
	    printf("%s",faculty.timeout[1]);
	    gotoxy(42,12);
	    printf("%s",faculty.timeout[2]);
	    gotoxy(42,13);
	    printf("%s",faculty.timeout[3]);
	    gotoxy(42,14);
	    printf("%s",faculty.timeout[4]);
	    gotoxy(42,15);
	    printf("%s",faculty.timeout[5]);
	    gotoxy(42,16);
	    printf("%s",faculty.timeout[6]);
	    gotoxy(42,17);
	    printf("%s",faculty.timeout[7]);
	    gotoxy(42,18);
	    printf("%s",faculty.timeout[8]);
	    gotoxy(42,19);
	    printf("%s",faculty.timeout[9]);
	    gotoxy(42,20);
	    printf("%s",faculty.timeout[10]);
	    gotoxy(42,21);
	    printf("%s",faculty.timeout[11]);
	    gotoxy(42,22);
	    printf("%s",faculty.timeout[12]);
	    gotoxy(51,8);
	    printf("hours");
	    gotoxy(52,10);
	    printf("%s",faculty.duration[0]);
	    gotoxy(52,11);
	    printf("%s",faculty.duration[1]);
	    gotoxy(52,12);
	    printf("%s",faculty.duration[2]);
	    gotoxy(52,13);
	    printf("%s",faculty.duration[3]);
	    gotoxy(52,14);
	    printf("%s",faculty.duration[4]);
	    gotoxy(52,15);
	    printf("%s",faculty.duration[5]);
	    gotoxy(52,16);
	    printf("%s",faculty.duration[6]);
	    gotoxy(52,17);
	    printf("%s",faculty.duration[7]);
	    gotoxy(52,18);
	    printf("%s",faculty.duration[8]);
	    gotoxy(52,19);
	    printf("%s",faculty.duration[9]);
	    gotoxy(52,20);
	    printf("%s",faculty.duration[10]);
	    gotoxy(52,21);
	    printf("%s",faculty.duration[11]);
	    gotoxy(52,22);
	    printf("%s",faculty.duration[12]);
	    gotoxy(61,8);
	    printf("Date");
	    gotoxy(59,10);
	    printf("%s",faculty.date[0]);
	    gotoxy(59,11);
	    printf("%s",faculty.date[1]);
	    gotoxy(59,12);
	    printf("%s",faculty.date[2]);
	    gotoxy(59,13);
	    printf("%s",faculty.date[3]);
	    gotoxy(59,14);
	    printf("%s",faculty.date[4]);
	    gotoxy(59,15);
	    printf("%s",faculty.date[5]);
	    gotoxy(59,16);
	    printf("%s",faculty.date[6]);
	    gotoxy(59,17);
	    printf("%s",faculty.date[7]);
	    gotoxy(59,18);
	    printf("%s",faculty.date[8]);
	    gotoxy(59,19);
	    printf("%s",faculty.date[9]);
	    gotoxy(59,20);
	    printf("%s",faculty.date[10]);
	    gotoxy(59,21);
	    printf("%s",faculty.date[11]);
	    gotoxy(59,22);
	    printf("%s",faculty.date[12]);
	    gotoxy(72,8);
	    printf("Remarks");
	    gotoxy(72,10);
	    printf("%s",faculty.remarks[0]);
	    gotoxy(72,11);
	    printf("%s",faculty.remarks[1]);
	    gotoxy(72,12);
	    printf("%s",faculty.remarks[2]);
	    gotoxy(72,13);
	    printf("%s",faculty.remarks[3]);
	    gotoxy(72,14);
	    printf("%s",faculty.remarks[4]);
	    gotoxy(72,15);
	    printf("%s",faculty.remarks[5]);
	    gotoxy(72,16);
	    printf("%s",faculty.remarks[6]);
	    gotoxy(72,17);
	    printf("%s",faculty.remarks[7]);
	    gotoxy(72,18);
	    printf("%s",faculty.remarks[8]);
	    gotoxy(72,19);
	    printf("%s",faculty.remarks[9]);
	    gotoxy(72,20);
	    printf("%s",faculty.remarks[10]);
	    gotoxy(72,21);
	    printf("%s",faculty.remarks[11]);
	    gotoxy(72,22);
	    printf("%s",faculty.remarks[12]);
	    //lec no.
	    gotoxy(2,10);
	    printf("1");
	    gotoxy(2,11);
	    printf("2");
	    gotoxy(2,12);
	    printf("3");
	    gotoxy(2,13);
	    printf("4");
	    gotoxy(2,14);
	    printf("5");
	    gotoxy(2,15);
	    printf("6");
	    gotoxy(2,16);
	    printf("7");
	    gotoxy(2,17);
	    printf("8");
	    gotoxy(2,18);
	    printf("9");
	    gotoxy(2,19);
	    printf("10");
	    gotoxy(2,20);
	    printf("11");
	    gotoxy(2,21);
	    printf("12");
	    gotoxy(2,22);
	    printf("13");
	    gotoxy(1,24);
	    fflush(stdout);
	    gotoxy(1,24);
	    printf("Salary:%ld",(long int)faculty.salary);
	    gotoxy(37,24);
	    printf("Tax:%.2f\n", faculty.tax);
	    gotoxy(60,24);
	    printf("Total Amount: %ld\n",(long int)faculty.total);
	    getch();
	    }
	    printf("Bill View Successfuly");
	}
    }
    //printf("Bill View Successfuly");
    fclose(fp);
    getch();
    menu();
}
