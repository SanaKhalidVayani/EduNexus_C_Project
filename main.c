#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct Student
{
    char studentID[20];
    char name[50];
    char fatherName[50];
    char gender[10];
    int age;

    char department[50];
    char program[50];
    char batch[20];
    char section[10];

    int semester;

    char phone[20];
    char email[50];
    char password[20];

    char status[20];
};

struct Teacher
{
    char employeeID[20];
    char name[50];
    char gender[10];

    char department[50];
    char qualification[30];
    char designation[30];

    char subject[50];
    char room[20];

    int experience;

    char phone[20];
    char email[50];
    char password[20];

    char status[20];
};

struct Student s;
struct Teacher t;
struct Student tempStudent;
struct Teacher tempTeacher;

struct Attendance
{
    char studentID[20];
    char name[50];
    char date[20];
    char status[10];
};

struct Attendance a;

struct Assignment
{
    char subject[50];
    char title[100];
    char deadline[20];
};

struct Assignment assign;

struct Marks
{
    char studentID[20];
    char subject[50];
    int marks;
    float gradePoints;
};

struct Marks m;

struct Notice
{
    char title[100];
    char message[200];
};

struct Notice n;

struct Complaint
{
    char studentID[20];
    char subject[100];
    char message[200];
};

struct Complaint c;



struct Fee
{
    char studentID[20];
    int amount;
    char status[20];
    char date[20];
};

struct Fee f;

struct Timetable
{
    char id[20];

    char program[50];
    char batch[20];
    char section[10];

    char day[20];
    char time[30];
    char subject[50];
    char room[20];
};

struct Timetable tt;

struct Subject
{
    char code[20];
    char name[50];
    int creditHours;
};

struct Subject sub;

char line[500];

char currentStudentID[20];
char currentTeacherID[20];
char currentProgram[50];
char currentBatch[20];
char currentSection[10];

void mainMenu();

void studentPortal();
void teacherPortal();
void adminPortal();

void studentSignup();
void studentLogin();

void teacherSignup();
void teacherLogin();

void markAttendance();
void attendancePercentage();
void attendanceReport();

void postAssignments();
void enterMarks();
void performanceSummary();
void postAnnouncements();

void viewAttendance();
void viewAssignments();
void viewMarks();
void viewFeeStatus();
void submitComplaint();
void viewComplaintStatus();
void viewNotices();
void viewTimetable();
void viewStudentTimetable();
void viewTeacherTimetable();

float calculateGradePoints(int marks);

void adminLogin();

void approveStudents();
void approveTeachers();

void adminDashboard();

void postAdminAnnouncement();

void manageStudents();
void manageTeachers();

void assignSubjects();

void manageSubjects();
void manageTimetable();

void manageFees();

void manageComplaints();

void manageNotices();

void universityReport();
void smartDashboard();

void studentDashboard();
void teacherDashboard();

void markAttendance();
void viewAttendance();
void attendanceReport();

void generateDefaulterList();
void viewDefaulterList();

float calculateGradePoints(int marks)
{
    if(marks >= 85)
        return 4.00;
    else if(marks >= 80)
        return 3.70;
    else if(marks >= 75)
        return 3.30;
    else if(marks >= 70)
        return 3.00;
    else if(marks >= 65)
        return 2.70;
    else if(marks >= 61)
        return 2.30;
    else if(marks >= 58)
        return 2.00;
    else if(marks >= 55)
        return 1.70;
    else if(marks >= 50)
        return 1.00;
    else
        return 0.00;
}

int main()
{
    mainMenu();

    return 0;
}

void mainMenu()
{
    int choice;

    while(1)
    {
        printf("\n===== EduNexus =====");
        printf("\n1. Student Portal");
        printf("\n2. Teacher Portal");
        printf("\n3. Admin Portal");
        printf("\n4. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                studentPortal();
                break;

            case 2:
                teacherPortal();
                break;

            case 3:
                adminPortal();
                break;

            case 4:
                printf("\nThank you for using EduNexus!\n");
                exit(0);

            default:
                printf("\nInvalid Choice!\n");
        }
    }
}

void studentPortal()
{
    int choice;

    while(1)
    {
        printf("\n===== Student Portal =====");
        printf("\n1. Sign Up");
        printf("\n2. Login");
        printf("\n3. Back");

        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                studentSignup();
                break;

            case 2:
                studentLogin();
                break;

            case 3:
                return;

            default:
                printf("\nInvalid Choice!\n");
        }
    }
}

void teacherPortal()
{
    int choice;

    while(1)
    {
        printf("\n===== Teacher Portal =====");
        printf("\n1. Sign Up");
        printf("\n2. Login");
        printf("\n3. Back");

        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                teacherSignup();
                break;

            case 2:
                teacherLogin();
                break;

            case 3:
                return;

            default:
                printf("\nInvalid Choice!\n");
        }
    }
}

void adminPortal()
{
    int choice;

    while(1)
    {
        printf("\n===== Admin Portal =====");
        printf("\n1. Login");
        printf("\n2. Back");

        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                adminLogin();
                break;

            case 2:
                return;

            default:
                printf("\nInvalid Choice!\n");
        }
    }
}

void studentSignup()
{
    FILE *fp;

   fp = fopen("pending_students.txt", "a");
    if(fp == NULL)
{
    printf("File could not be opened!");
    return;
}

    printf("\n===== Student Registration =====");

    printf("\nEnter Student ID: ");
    scanf("%s", s.studentID);

    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);

    printf("Enter Father Name: ");
    scanf(" %[^\n]", s.fatherName);

    printf("Enter Gender: ");
    scanf("%s", s.gender);

    printf("Enter Age: ");
    scanf("%d", &s.age);

    printf("Enter Department: ");
    scanf(" %[^\n]", s.department);
    
    printf("Enter Program: ");
    scanf(" %[^\n]", s.program);
    
    printf("Enter Section: ");
    scanf(" %[^\n]", s.section);
    
    printf("Enter Batch: ");
    scanf(" %[^\n]", s.batch);

    printf("Enter Semester: ");
    scanf("%d", &s.semester);

    printf("Enter Phone Number: ");
    scanf("%s", s.phone);

    printf("Enter Email: ");
    scanf("%s", s.email);

    printf("Enter Password: ");
    scanf("%s", s.password);
    
    strcpy(s.status, "Pending");

    fprintf(fp,"%s|%s|%s|%s|%d|%s|%s|%s|%s|%d|%s|%s|%s|%s\n",
        s.studentID,
        s.name,
        s.fatherName,
        s.gender,
        s.age,
        s.department,
        s.program,
        s.batch,
        s.section,
        s.semester,
        s.phone,
        s.email,
        s.password,
        s.status);

    fclose(fp);

    printf("\nRegistration Successful!");
    printf("\nWait for Admin Approval.\n");
}

void studentLogin()
{
    FILE *fp;
    char line[500], copy[500];
    char studentID[20], password[20];
    char fileStudentID[20], filePassword[20];
    char *token;
    int found=0;

    printf("\n===== Student Login =====");

    printf("\nEnter Student ID: ");
    scanf("%s",studentID);

    printf("Enter Password: ");
    scanf("%s",password);

    fp=fopen("students.txt","r");

    if(fp!=NULL)
    {
        while(fgets(line,sizeof(line),fp)!=NULL)
        {
            strcpy(copy,line);

            token=strtok(copy,"|");
            strcpy(fileStudentID,token);

            token=strtok(NULL,"|");
            token=strtok(NULL,"|");
            token=strtok(NULL,"|");
            token=strtok(NULL,"|");
            token=strtok(NULL,"|");

            strcpy(currentProgram,token);

            token=strtok(NULL,"|");

            strcpy(currentBatch,token);

            token=strtok(NULL,"|");

            strcpy(currentSection,token);

            token=strtok(NULL,"|");
            token=strtok(NULL,"|");
            token=strtok(NULL,"|");
            token=strtok(NULL,"|");

            strcpy(filePassword,token);

            if(strcmp(studentID,fileStudentID)==0 &&
               strcmp(password,filePassword)==0)
            {
                found=1;

                strcpy(currentStudentID,studentID);

                break;
            }
        }

        fclose(fp);
    }

    if(found)
    {
        printf("\nLogin Successful!\n");
        studentDashboard();
        return;
    }

    fp=fopen("pending_students.txt","r");

    if(fp!=NULL)
    {
        while(fgets(line,sizeof(line),fp)!=NULL)
        {
            strcpy(copy,line);

            token=strtok(copy,"|");

            if(strcmp(token,studentID)==0)
            {
                fclose(fp);

                printf("\nYour account is pending approval.\n");
                printf("Please wait for admin approval.\n");

                return;
            }
        }

        fclose(fp);
    }

    printf("\nInvalid Student ID or Password!\n");
}
void teacherSignup()
{
    FILE *fp;

    fp = fopen("pending_teachers.txt", "a");

    if(fp == NULL)
    {
        printf("File could not be opened!");
        return;
    }

    printf("\n===== Teacher Registration =====");

    printf("\nEnter Employee ID: ");
    scanf("%s", t.employeeID);

    printf("Enter Name: ");
    scanf(" %[^\n]", t.name);

    printf("Enter Gender: ");
    scanf("%s", t.gender);

    printf("Enter Department: ");
    scanf(" %[^\n]", t.department);

    printf("Enter Qualification: ");
    scanf(" %[^\n]", t.qualification);

    printf("Enter Designation: ");
    scanf(" %[^\n]", t.designation);

    printf("Enter Subject: ");
    scanf(" %[^\n]", t.subject);

    printf("Enter Room Number: ");
    scanf("%s", t.room);

    printf("Enter Experience (Years): ");
    scanf("%d", &t.experience);

    printf("Enter Phone Number: ");
    scanf("%s", t.phone);

    printf("Enter Email: ");
    scanf("%s", t.email);

    printf("Enter Password: ");
    scanf("%s", t.password);

    strcpy(t.status, "Pending");

    fprintf(fp,"%s|%s|%s|%s|%s|%s|%s|%s|%d|%s|%s|%s|%s\n",
            t.employeeID,
            t.name,
            t.gender,
            t.department,
            t.qualification,
            t.designation,
            t.subject,
            t.room,
            t.experience,
            t.phone,
            t.email,
            t.password,
            t.status);

    fclose(fp);

    printf("\nRegistration Successful!");
    printf("\nWait for Admin Approval.\n");
}

void teacherLogin()
{
    FILE *fp;

    char line[500];
    char copy[500];

    char employeeID[20];
    char password[20];

    char fileEmployeeID[20];
    char filePassword[20];

    char *token;

    int found = 0;

    printf("\n===== Teacher Login =====");

    printf("\nEnter Employee ID: ");
    scanf("%s", employeeID);

    printf("Enter Password: ");
    scanf("%s", password);

    fp = fopen("teachers.txt", "r");

    if(fp != NULL)
    {
        while(fgets(line, sizeof(line), fp) != NULL)
        {
            strcpy(copy, line);

            token = strtok(copy, "|");
            strcpy(fileEmployeeID, token);

            token = strtok(NULL, "|"); // name
            token = strtok(NULL, "|"); // gender
            token = strtok(NULL, "|"); // department
            token = strtok(NULL, "|"); // qualification
            token = strtok(NULL, "|"); // designation
            token = strtok(NULL, "|"); // subject
            token = strtok(NULL, "|"); // room
            token = strtok(NULL, "|"); // experience
            token = strtok(NULL, "|"); // phone
            token = strtok(NULL, "|"); // email
            token = strtok(NULL, "|"); // password

            strcpy(filePassword, token);

            if(strcmp(employeeID, fileEmployeeID) == 0 &&
               strcmp(password, filePassword) == 0)
            {
                found = 1;
                strcpy(currentTeacherID, employeeID);
                break;
            }
        }

        fclose(fp);
    }

    if(found)
    {
        printf("\nLogin Successful!\n");
        teacherDashboard();
        return;
    }

    fp = fopen("pending_teachers.txt", "r");

    if(fp != NULL)
    {
        while(fgets(line, sizeof(line), fp) != NULL)
        {
            strcpy(copy, line);

            token = strtok(copy, "|");

            if(strcmp(token, employeeID) == 0)
            {
                fclose(fp);

                printf("\nAccount is not approved yet!");
                printf("\nPlease wait for admin approval.\n");

                return;
            }
        }

        fclose(fp);
    }

    printf("\nInvalid Employee ID or Password!\n");
}

void adminLogin()
{
    char adminID[20];
    char password[20];

    printf("\n===== Admin Login =====");

    printf("\nEnter Admin ID: ");
    scanf("%s", adminID);

    printf("Enter Password: ");
    scanf("%s", password);

    if(strcmp(adminID,"admin")==0 && strcmp(password,"admin123")==0)
    {
        printf("\nLogin Successful!\n");
        adminDashboard();
    }
    else
    {
        printf("\nInvalid Admin ID or Password!\n");
    }
}

void approveStudents()
{
    FILE *fp, *temp, *approved;
    char line[500], copy[500];
    char approveID[20], studentID[20];
    char *token;
    int found = 0;

    fp = fopen("pending_students.txt","r");

    if(fp==NULL)
    {
        printf("\nNo Pending Students Found!\n");
        return;
    }

    printf("\n===== Pending Students =====\n\n");

    while(fgets(line,sizeof(line),fp)!=NULL)
    {
        printf("%s",line);
    }

    fclose(fp);

    printf("\nEnter Student ID to approve: ");
    scanf("%s",approveID);

    fp = fopen("pending_students.txt","r");
    temp = fopen("temp.txt","w");
    approved = fopen("students.txt","a");

    while(fgets(line,sizeof(line),fp)!=NULL)
    {
        strcpy(copy,line);

        token=strtok(copy,"|");
        strcpy(studentID,token);

        if(strcmp(studentID,approveID)==0)
        {
            found=1;

            fprintf(approved,"%s",line);

            printf("\nStudent Approved Successfully!\n");
        }
        else
        {
            fprintf(temp,"%s",line);
        }
    }

    fclose(fp);
    fclose(temp);
    fclose(approved);

    remove("pending_students.txt");
    rename("temp.txt","pending_students.txt");

    if(found==0)
        printf("\nStudent ID not found!\n");
}

void approveTeachers()
{
    FILE *fp, *temp, *approved;

    char line[500];
    char copy[500];
    char approveID[20];
    char employeeID[20];
    char *token;

    int found = 0;

    fp = fopen("pending_teachers.txt","r");

    if(fp == NULL)
    {
        printf("\nNo Pending Teachers Found!\n");
        return;
    }

    printf("\n===== Pending Teachers =====\n\n");

    while(fgets(line,sizeof(line),fp)!=NULL)
    {
        printf("%s",line);
    }

    fclose(fp);

    printf("\nEnter Employee ID to approve: ");
    scanf("%s",approveID);

    fp = fopen("pending_teachers.txt","r");
    temp = fopen("temp.txt","w");
    approved = fopen("teachers.txt","a");

    while(fgets(line,sizeof(line),fp)!=NULL)
    {
        strcpy(copy,line);

        token = strtok(copy,"|");
        strcpy(employeeID,token);

        if(strcmp(employeeID,approveID)==0)
        {
            found = 1;

            char id[20],name[50],gender[10],dept[50];
            char qualification[30],designation[30];
            char subject[50],room[20];
            char phone[20],email[50],password[20],status[20];
            int experience;

            sscanf(line,
            "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%d|%[^|]|%[^|]|%[^|]|%[^|\n]",
            id,name,gender,dept,
            qualification,designation,
            subject,room,&experience,
            phone,email,password,status);

            fprintf(approved,
            "%s|%s|%s|%s|%s|%s|%s|%s|%d|%s|%s|%s|Approved\n",
            id,name,gender,dept,
            qualification,designation,
            subject,room,experience,
            phone,email,password);

            printf("\nTeacher Approved Successfully!\n");
        }
        else
        {
            fprintf(temp,"%s",line);
        }
    }

    fclose(fp);
    fclose(temp);
    fclose(approved);

    remove("pending_teachers.txt");
    rename("temp.txt","pending_teachers.txt");

    if(found==0)
    {
        printf("\nTeacher ID not found!\n");
    }
}

void adminDashboard()
{
    int choice;

    while(1)
    {
        printf("\n===== Admin Dashboard =====");

        printf("\n1. Approve Students");
        printf("\n2. Approve Teachers");
        printf("\n3. Manage Students");
        printf("\n4. Manage Teachers");
        printf("\n5. Manage Subjects");
        printf("\n6. Manage Timetable");
        printf("\n7. Manage Fees");
        printf("\n8. Manage Complaints");
        printf("\n9. Manage Notices");
        printf("\n10. Assign Subjects to Teachers");
        printf("\n11. Post University Announcement");
        printf("\n12. University Report");
        printf("\n13. Generate Defaulter List");
        printf("\n14. Smart Dashboard");
        printf("\n15. Logout");

        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                approveStudents();
                break;

            case 2:
                approveTeachers();
                break;

            case 3:
                manageStudents();
                break;

            case 4:
                manageTeachers();
                break;

            case 5:
                manageSubjects();
                break;

            case 6:
                manageTimetable();
                break;

            case 7:
                manageFees();
                break;

            case 8:
                manageComplaints();
                break;

            case 9:
                manageNotices();
                break;

            case 10:
            	assignSubjects();
            	break;
            	
            case 11:
            	postAdminAnnouncement();
            	break;
            
			case 12:
                universityReport();
                break;
                
            case 13:
                generateDefaulterList();
                break;
                
            case 14:
                smartDashboard();
                break;

            case 15:
                return;

            default:
                printf("\nInvalid Choice!\n");
        }
    }
}

void manageStudents()
{
    FILE *fp, *temp;
    char line[500], copy[500];
    char searchID[20], fileStudentID[20];
    char *token;
    int choice, found=0;

    while(1)
    {
        printf("\n===== Manage Students =====");
        printf("\n1. Add Student");
        printf("\n2. View Students");
        printf("\n3. Search Student");
        printf("\n4. Update Student");
        printf("\n5. Delete Student");
        printf("\n6. Back");

        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:

            fp = fopen("students.txt","a");

            if(fp==NULL)
            {
                printf("\nFile could not be opened!");
                break;
            }

            printf("\nEnter Student ID: ");
            scanf("%s",s.studentID);

            fflush(stdin);

            printf("Enter Name: ");
            scanf(" %[^\n]",s.name);

            printf("Enter Father Name: ");
            scanf(" %[^\n]",s.fatherName);

            printf("Enter Gender: ");
            scanf("%s",s.gender);

            printf("Enter Age: ");
            scanf("%d",&s.age);

            fflush(stdin);

            printf("Enter Department: ");
            scanf(" %[^\n]",s.department);

            printf("Enter Program: ");
            scanf(" %[^\n]",s.program);

            printf("Enter Batch: ");
            scanf(" %[^\n]",s.batch);

            printf("Enter Section: ");
            scanf(" %[^\n]",s.section);

            printf("Enter Semester: ");
            scanf("%d",&s.semester);

            printf("Enter Phone: ");
            scanf("%s",s.phone);

            printf("Enter Email: ");
            scanf("%s",s.email);

            printf("Enter CNIC: ");
            scanf("%s",s.password);

            strcpy(s.status,"Approved");

            fprintf(fp,"%s|%s|%s|%s|%d|%s|%s|%s|%s|%d|%s|%s|%s|%s\n",
                    s.studentID,
                    s.name,
                    s.fatherName,
                    s.gender,
                    s.age,
                    s.department,
                    s.program,
                    s.batch,
                    s.section,
                    s.semester,
                    s.phone,
                    s.email,
                    s.password,
                    s.status);

            fclose(fp);

            printf("\nStudent Added Successfully!\n");
            break;

        case 2:

            fp = fopen("students.txt","r");

            if(fp==NULL)
            {
                printf("\nNo Students Found!\n");
                break;
            }

            printf("\n===== Students =====\n\n");

            while(fgets(line,sizeof(line),fp)!=NULL)
            {
                printf("%s",line);
            }

            fclose(fp);
            break;

        case 3:

            printf("\nEnter Student ID: ");
            scanf("%s",searchID);

            fp = fopen("students.txt","r");

            found=0;

            while(fgets(line,sizeof(line),fp)!=NULL)
            {
                strcpy(copy,line);

                token = strtok(copy,"|");
                strcpy(fileStudentID,token);

                if(strcmp(searchID,fileStudentID)==0)
                {
                    printf("\n%s",line);
                    found=1;
                    break;
                }
            }

            fclose(fp);

            if(found==0)
                printf("\nStudent Not Found!\n");

            break;

        case 4:

    printf("\nEnter Student ID to Update: ");
    scanf("%s",searchID);

    fp = fopen("students.txt","r");
    temp = fopen("temp.txt","w");

    found=0;

    while(fgets(line,sizeof(line),fp)!=NULL)
    {
        sscanf(line,
               "%[^|]|%[^|]|%[^|]|%[^|]|%d|%[^|]|%[^|]|%[^|]|%[^|]|%d|%[^|]|%[^|]|%[^|]|%[^|\n]",
               tempStudent.studentID,
               tempStudent.name,
               tempStudent.fatherName,
               tempStudent.gender,
               &tempStudent.age,
               tempStudent.department,
               tempStudent.program,
               tempStudent.batch,
               tempStudent.section,
               &tempStudent.semester,
               tempStudent.phone,
               tempStudent.email,
               tempStudent.password,
               tempStudent.status);

        if(strcmp(searchID,tempStudent.studentID)==0)
        {
            found=1;

            fflush(stdin);

            printf("\nEnter New Department: ");
            scanf(" %[^\n]",tempStudent.department);

            printf("Enter New Program: ");
            scanf(" %[^\n]",tempStudent.program);

            printf("Enter New Semester: ");
            scanf("%d",&tempStudent.semester);

            fflush(stdin);

            printf("Enter New Section: ");
            scanf(" %[^\n]",tempStudent.section);

            printf("Enter New Status: ");
            scanf("%s",tempStudent.status);
        }

        fprintf(temp,"%s|%s|%s|%s|%d|%s|%s|%s|%s|%d|%s|%s|%s|%s\n",
                tempStudent.studentID,
                tempStudent.name,
                tempStudent.fatherName,
                tempStudent.gender,
                tempStudent.age,
                tempStudent.department,
                tempStudent.program,
                tempStudent.batch,
                tempStudent.section,
                tempStudent.semester,
                tempStudent.phone,
                tempStudent.email,
                tempStudent.password,
                tempStudent.status);
    }

    fclose(fp);
    fclose(temp);

    remove("students.txt");
    rename("temp.txt","students.txt");

    if(found)
        printf("\nStudent Updated Successfully!\n");
    else
        printf("\nStudent Not Found!\n");

    break;

        case 5:

            printf("\nEnter Student ID to Delete: ");
            scanf("%s",searchID);

            fp = fopen("students.txt","r");
            temp = fopen("temp.txt","w");

            found=0;

            while(fgets(line,sizeof(line),fp)!=NULL)
            {
                strcpy(copy,line);

                token = strtok(copy,"|");
                strcpy(fileStudentID,token);

                if(strcmp(searchID,fileStudentID)==0)
                {
                    found=1;
                }
                else
                {
                    fprintf(temp,"%s",line);
                }
            }

            fclose(fp);
            fclose(temp);

            remove("students.txt");
            rename("temp.txt","students.txt");

            if(found)
                printf("\nStudent Deleted Successfully!\n");
            else
                printf("\nStudent Not Found!\n");

            break;

        case 6:
            return;

        default:
            printf("\nInvalid Choice!\n");
        }
    }
}

void assignSubjects()
{
    FILE *fp;

    char employeeID[20];
    char subjectCode[20];

    fp=fopen("teacher_subjects.txt","a");

    if(fp==NULL)
    {
        printf("\nFile Error!");
        return;
    }

    printf("\nEnter Employee ID: ");
    scanf("%s",employeeID);

    printf("Enter Subject Code: ");
    scanf("%s",subjectCode);

    fprintf(fp,"%s|%s\n",employeeID,subjectCode);

    fclose(fp);

    printf("\nSubject Assigned Successfully!\n");
}

void postAdminAnnouncement()
{
    FILE *fp;

    char title[100];
    char message[200];

    fp=fopen("admin_notices.txt","a");

    if(fp==NULL)
    {
        printf("\nFile error!");
        return;
    }

    fflush(stdin);

    printf("\nEnter Title: ");
    scanf(" %[^\n]",title);

    printf("Enter Message: ");
    scanf(" %[^\n]",message);

    fprintf(fp,"%s|%s\n",title,message);

    fclose(fp);

    printf("\nAnnouncement Posted Successfully!\n");
}

void manageTeachers()
{
    FILE *fp, *temp;
    char line[500], copy[500];
    char searchID[20], fileEmployeeID[20];
    char *token;
    int choice, found=0;

    while(1)
    {
        printf("\n===== Manage Teachers =====");
        printf("\n1. Add Teacher");
        printf("\n2. View Teachers");
        printf("\n3. Search Teacher");
        printf("\n4. Update Teacher");
        printf("\n5. Delete Teacher");
        printf("\n6. Back");

        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {

        case 1:

            fp = fopen("teachers.txt","a");

            if(fp==NULL)
            {
                printf("\nFile could not be opened!");
                break;
            }

            printf("\nEnter Employee ID: ");
            scanf("%s",t.employeeID);

            fflush(stdin);

            printf("Enter Name: ");
            scanf(" %[^\n]",t.name);

            printf("Enter Gender: ");
            scanf("%s",t.gender);

            fflush(stdin);

            printf("Enter Department: ");
            scanf(" %[^\n]",t.department);

            printf("Enter Qualification: ");
            scanf(" %[^\n]",t.qualification);

            printf("Enter Designation: ");
            scanf(" %[^\n]",t.designation);

            printf("Enter Subject: ");
            scanf(" %[^\n]",t.subject);

            printf("Enter Room Number: ");
            scanf("%s",t.room);

            printf("Enter Experience: ");
            scanf("%d",&t.experience);

            printf("Enter Phone: ");
            scanf("%s",t.phone);

            printf("Enter Email: ");
            scanf("%s",t.email);

            printf("Enter CNIC: ");
            scanf("%s",t.password);

            strcpy(t.status,"Approved");

            fprintf(fp,"%s|%s|%s|%s|%s|%s|%s|%s|%d|%s|%s|%s|%s\n",
                    t.employeeID,
                    t.name,
                    t.gender,
                    t.department,
                    t.qualification,
                    t.designation,
                    t.subject,
                    t.room,
                    t.experience,
                    t.phone,
                    t.email,
                    t.password,
                    t.status);

            fclose(fp);

            printf("\nTeacher Added Successfully!\n");

            break;


        case 2:

            fp = fopen("teachers.txt","r");

            if(fp==NULL)
            {
                printf("\nNo Teachers Found!\n");
                break;
            }

            printf("\n===== Teachers =====\n\n");

            while(fgets(line,sizeof(line),fp)!=NULL)
            {
                printf("%s",line);
            }

            fclose(fp);

            break;


        case 3:

            printf("\nEnter Employee ID: ");
            scanf("%s",searchID);

            fp = fopen("teachers.txt","r");

            found=0;

            while(fgets(line,sizeof(line),fp)!=NULL)
            {
                strcpy(copy,line);

                token = strtok(copy,"|");
                strcpy(fileEmployeeID,token);

                if(strcmp(searchID,fileEmployeeID)==0)
                {
                    printf("\n%s",line);
                    found=1;
                    break;
                }
            }

            fclose(fp);

            if(found==0)
                printf("\nTeacher Not Found!\n");

            break;


        case 4:

            printf("\nEnter Employee ID to Update: ");
            scanf("%s",searchID);

            fp = fopen("teachers.txt","r");
            temp = fopen("temp.txt","w");

            found=0;

            while(fgets(line,sizeof(line),fp)!=NULL)
            {
                sscanf(line,
                       "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%d|%[^|]|%[^|]|%[^|]|%[^|\n]",
                       tempTeacher.employeeID,
                       tempTeacher.name,
                       tempTeacher.gender,
                       tempTeacher.department,
                       tempTeacher.qualification,
                       tempTeacher.designation,
                       tempTeacher.subject,
                       tempTeacher.room,
                       &tempTeacher.experience,
                       tempTeacher.phone,
                       tempTeacher.email,
                       tempTeacher.password,
                       tempTeacher.status);

                if(strcmp(searchID,tempTeacher.employeeID)==0)
                {
                    found=1;

                    fflush(stdin);

                    printf("\nEnter New Department: ");
                    scanf(" %[^\n]",tempTeacher.department);

                    printf("Enter New Designation: ");
                    scanf(" %[^\n]",tempTeacher.designation);

                    printf("Enter New Subject: ");
                    scanf(" %[^\n]",tempTeacher.subject);

                    printf("Enter New Room Number: ");
                    scanf("%s",tempTeacher.room);

                    printf("Enter New Status: ");
                    scanf("%s",tempTeacher.status);
                }

                fprintf(temp,"%s|%s|%s|%s|%s|%s|%s|%s|%d|%s|%s|%s|%s\n",
                        tempTeacher.employeeID,
                        tempTeacher.name,
                        tempTeacher.gender,
                        tempTeacher.department,
                        tempTeacher.qualification,
                        tempTeacher.designation,
                        tempTeacher.subject,
                        tempTeacher.room,
                        tempTeacher.experience,
                        tempTeacher.phone,
                        tempTeacher.email,
                        tempTeacher.password,
                        tempTeacher.status);
            }

            fclose(fp);
            fclose(temp);

            remove("teachers.txt");
            rename("temp.txt","teachers.txt");

            if(found)
                printf("\nTeacher Updated Successfully!\n");
            else
                printf("\nTeacher Not Found!\n");

            break;


        case 5:

            printf("\nEnter Employee ID to Delete: ");
            scanf("%s",searchID);

            fp = fopen("teachers.txt","r");
            temp = fopen("temp.txt","w");

            found=0;

            while(fgets(line,sizeof(line),fp)!=NULL)
            {
                strcpy(copy,line);

                token = strtok(copy,"|");
                strcpy(fileEmployeeID,token);

                if(strcmp(searchID,fileEmployeeID)==0)
                {
                    found=1;
                }
                else
                {
                    fprintf(temp,"%s",line);
                }
            }

            fclose(fp);
            fclose(temp);

            remove("teachers.txt");
            rename("temp.txt","teachers.txt");

            if(found)
                printf("\nTeacher Deleted Successfully!\n");
            else
                printf("\nTeacher Not Found!\n");

            break;


        case 6:
            return;


        default:
            printf("\nInvalid Choice!\n");
        }
    }
}

void manageSubjects()
{
    FILE *fp, *temp;
    char line[500];
    char copy[500];
    char searchCode[20];
    char fileCode[20];
    char *token;
    int choice, found = 0;

    while(1)
    {
        printf("\n===== Manage Subjects =====");
        printf("\n1. Add Subject");
        printf("\n2. View Subjects");
        printf("\n3. Search Subject");
        printf("\n4. Delete Subject");
        printf("\n5. Back");

        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:

                fp = fopen("subjects.txt","a");

                if(fp == NULL)
                {
                    printf("\nFile could not be opened!");
                    break;
                }

                printf("\nEnter Subject Code: ");
                scanf("%s",sub.code);

                fflush(stdin);

                printf("Enter Subject Name: ");
                scanf(" %[^\n]",sub.name);

                printf("Enter Credit Hours: ");
                scanf("%d",&sub.creditHours);

                fprintf(fp,"%s|%s|%d\n",
                        sub.code,
                        sub.name,
                        sub.creditHours);

                fclose(fp);

                printf("\nSubject Added Successfully!\n");
                break;

            case 2:

                fp = fopen("subjects.txt","r");

                if(fp == NULL)
                {
                    printf("\nNo Subjects Found!\n");
                    break;
                }

                printf("\n===== Subjects =====\n\n");

                while(fgets(line,sizeof(line),fp)!=NULL)
                {
                    printf("%s",line);
                }

                fclose(fp);
                break;

            case 3:

                printf("\nEnter Subject Code: ");
                scanf("%s",searchCode);

                fp = fopen("subjects.txt","r");

                found = 0;

                while(fgets(line,sizeof(line),fp)!=NULL)
                {
                    strcpy(copy,line);

                    token = strtok(copy,"|");
                    strcpy(fileCode,token);

                    if(strcmp(searchCode,fileCode)==0)
                    {
                        printf("\n%s",line);
                        found = 1;
                        break;
                    }
                }

                fclose(fp);

                if(found==0)
                {
                    printf("\nSubject Not Found!\n");
                }

                break;

            case 4:

                printf("\nEnter Subject Code to Delete: ");
                scanf("%s",searchCode);

                fp = fopen("subjects.txt","r");
                temp = fopen("temp.txt","w");

                found = 0;

                while(fgets(line,sizeof(line),fp)!=NULL)
                {
                    strcpy(copy,line);

                    token = strtok(copy,"|");
                    strcpy(fileCode,token);

                    if(strcmp(searchCode,fileCode)==0)
                    {
                        found = 1;
                    }
                    else
                    {
                        fprintf(temp,"%s",line);
                    }
                }

                fclose(fp);
                fclose(temp);

                remove("subjects.txt");
                rename("temp.txt","subjects.txt");

                if(found)
                    printf("\nSubject Deleted Successfully!\n");
                else
                    printf("\nSubject Not Found!\n");

                break;

            case 5:
                return;

            default:
                printf("\nInvalid Choice!\n");
        }
    }
}

void manageTimetable()
{
    FILE *fp;
    int choice;

    while(1)
    {
        printf("\n===== Manage Timetable =====");
        printf("\n1. Assign Student Timetable");
        printf("\n2. Assign Teacher Timetable");
        printf("\n3. Back");

        printf("\n\nEnter Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:

fp=fopen("student_timetable.txt","a");

if(fp==NULL)
{
    printf("\nFile could not be opened!\n");
    break;
}

fflush(stdin);

printf("\nEnter Program: ");
scanf(" %[^\n]",tt.program);

printf("Enter Batch: ");
scanf(" %[^\n]",tt.batch);

printf("Enter Section: ");
scanf(" %[^\n]",tt.section);

printf("Enter Day: ");
scanf(" %[^\n]",tt.day);

printf("Enter Time: ");
scanf(" %[^\n]",tt.time);

printf("Enter Subject: ");
scanf(" %[^\n]",tt.subject);

printf("Enter Room: ");
scanf("%s",tt.room);

fprintf(fp,"%s|%s|%s|%s|%s|%s|%s\n",
        tt.program,
        tt.batch,
        tt.section,
        tt.day,
        tt.time,
        tt.subject,
        tt.room);

fclose(fp);

printf("\nStudent Timetable Assigned Successfully!\n");

break;

            case 2:

                fp=fopen("teacher_timetable.txt","a");

                if(fp==NULL)
                {
                    printf("\nFile could not be opened!\n");
                    break;
                }

                printf("\nEnter Teacher ID: ");
                scanf("%s",tt.id);

                fflush(stdin);

                printf("Enter Day: ");
                scanf(" %[^\n]",tt.day);

                printf("Enter Time: ");
                scanf(" %[^\n]",tt.time);

                printf("Enter Subject: ");
                scanf(" %[^\n]",tt.subject);

                printf("Enter Room: ");
                scanf("%s",tt.room);

                fprintf(fp,"%s|%s|%s|%s|%s\n",
                        tt.id,
                        tt.day,
                        tt.time,
                        tt.subject,
                        tt.room);

                fclose(fp);

                printf("\nTeacher Timetable Assigned Successfully!\n");

                break;


            case 3:
                return;

            default:
                printf("\nInvalid Choice!\n");
        }
    }
}

void manageFees()
{
    FILE *fp;

    fp = fopen("fees.txt","a");

    if(fp == NULL)
    {
        printf("\nFile could not be opened!");
        return;
    }

    printf("\n===== Manage Fees =====");

    printf("\nEnter Student ID: ");
    scanf("%s",f.studentID);

    printf("Enter Amount: ");
    scanf("%d",&f.amount);

    printf("Enter Status (Paid/Unpaid): ");
    scanf("%s",f.status);

    printf("Enter Date (DD/MM/YYYY): ");
    scanf("%s",f.date);

    fprintf(fp,"%s|%d|%s|%s\n",
        f.studentID,
        f.amount,
        f.status,
        f.date);

    fclose(fp);

    printf("\nFee Record Added Successfully!\n");
}

void manageComplaints()
{
    FILE *fp, *temp;
    char line[500];
    char searchID[20];
    int choice, found;

    while(1)
    {
        printf("\n===== Manage Complaints =====");
        printf("\n1. View Complaints");
        printf("\n2. Resolve Complaint");
        printf("\n3. Back");

        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:

                fp = fopen("complaints.txt","r");

                if(fp == NULL)
                {
                    printf("\nNo Complaints Found!\n");
                    break;
                }

                printf("\n===== Complaints =====\n\n");

                while(fgets(line,sizeof(line),fp)!=NULL)
                {
                    printf("%s",line);
                }

                fclose(fp);

                break;

            case 2:

                printf("\nEnter Student ID whose complaint is resolved: ");
                scanf("%s",searchID);

                fp = fopen("complaints.txt","r");
                temp = fopen("temp.txt","w");

                found = 0;

                while(fgets(line,sizeof(line),fp)!=NULL)
                {
                    if(strstr(line,searchID)!=NULL)
                    {
                        char id[20], subject[100], message[200], status[20];

                        sscanf(line,"%[^|]|%[^|]|%[^|]|%[^|\n]",
                               id,subject,message,status);

                        fprintf(temp,"%s|%s|%s|Resolved\n",
                                id,subject,message);

                        found = 1;
                    }
                    else
                    {
                        fprintf(temp,"%s",line);
                    }
                }

                fclose(fp);
                fclose(temp);

                remove("complaints.txt");
                rename("temp.txt","complaints.txt");

                if(found)
                    printf("\nComplaint Resolved Successfully!\n");
                else
                    printf("\nComplaint Not Found!\n");

                break;

            case 3:
                return;

            default:
                printf("\nInvalid Choice!\n");
        }
    }
}

void manageNotices()
{
    FILE *fp, *temp;
    char searchTitle[100];
    char line[500];
    int choice, found;

    while(1)
    {
        printf("\n===== Manage Notices =====");
        printf("\n1. View Notices");
        printf("\n2. Delete Notice");
        printf("\n3. Back");

        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:

                fp = fopen("notices.txt","r");

                if(fp == NULL)
                {
                    printf("\nNo Notices Found!\n");
                    break;
                }

                printf("\n===== Notices =====\n\n");

                while(fgets(line,sizeof(line),fp)!=NULL)
                {
                    printf("%s",line);
                }

                fclose(fp);
                break;

            case 2:

                found = 0;

                fflush(stdin);

                printf("\nEnter Notice Title to Delete: ");
                scanf(" %[^\n]",searchTitle);

                fp = fopen("notices.txt","r");
                temp = fopen("temp.txt","w");

                while(fgets(line,sizeof(line),fp)!=NULL)
                {
                    if(strstr(line,searchTitle) != NULL)
                    {
                        found = 1;
                    }
                    else
                    {
                        fprintf(temp,"%s",line);
                    }
                }

                fclose(fp);
                fclose(temp);

                remove("notices.txt");
                rename("temp.txt","notices.txt");

                if(found)
                    printf("\nNotice Deleted Successfully!\n");
                else
                    printf("\nNotice Not Found!\n");

                break;

            case 3:
                return;

            default:
                printf("\nInvalid Choice!\n");
        }
    }
}

void universityReport()
{
    FILE *fp;
    char line[500];

    int students = 0;
    int teachers = 0;
    int subjects = 0;
    int attendance = 0;
    int defaulters = 0;
    int assignments = 0;
    int notices = 0;
    int complaints = 0;

    fp = fopen("students.txt","r");
    if(fp != NULL)
    {
        while(fgets(line,sizeof(line),fp)!=NULL)
            students++;
        fclose(fp);
    }

    fp = fopen("teachers.txt","r");
    if(fp != NULL)
    {
        while(fgets(line,sizeof(line),fp)!=NULL)
            teachers++;
        fclose(fp);
    }

    fp = fopen("subjects.txt","r");
    if(fp != NULL)
    {
        while(fgets(line,sizeof(line),fp)!=NULL)
            subjects++;
        fclose(fp);
    }

    fp = fopen("attendance.txt","r");
    if(fp != NULL)
    {
        while(fgets(line,sizeof(line),fp)!=NULL)
            attendance++;
        fclose(fp);
    }

    fp = fopen("defaulters.txt","r");
    if(fp != NULL)
    {
    while(fgets(line,sizeof(line),fp)!=NULL)
        defaulters++;
    fclose(fp);
    }

    fp = fopen("assignments.txt","r");
    if(fp != NULL)
    {
        while(fgets(line,sizeof(line),fp)!=NULL)
            assignments++;
        fclose(fp);
    }

    fp = fopen("notices.txt","r");
    if(fp != NULL)
    {
        while(fgets(line,sizeof(line),fp)!=NULL)
            notices++;
        fclose(fp);
    }

    fp = fopen("complaints.txt","r");
    if(fp != NULL)
    {
        while(fgets(line,sizeof(line),fp)!=NULL)
            complaints++;
        fclose(fp);
    }

    printf("\n=================================");
    printf("\n       UNIVERSITY REPORT");
    printf("\n=================================");

    printf("\nTotal Students           : %d",students);
    printf("\nTotal Teachers           : %d",teachers);
    printf("\nTotal Subjects           : %d",subjects);
    printf("\nTotal Attendance Records : %d",attendance);
    printf("\nTotal Defaulters         : %d",defaulters);
    printf("\nTotal Assignments        : %d",assignments);
    printf("\nTotal Notices            : %d",notices);
    printf("\nTotal Complaints         : %d",complaints);

    printf("\n=================================\n");
}

void smartDashboard()
{
    FILE *fp;
    int students=0, teachers=0, subjects=0, complaints=0;
    int notices=0, assignments=0;

    /* Students */
    fp=fopen("students.txt","r");

    if(fp!=NULL)
    {
        while(fgets(line,sizeof(line),fp)!=NULL)
            students++;

        fclose(fp);
    }

    /* Teachers */
    fp=fopen("teachers.txt","r");

    if(fp!=NULL)
    {
        while(fgets(line,sizeof(line),fp)!=NULL)
            teachers++;

        fclose(fp);
    }

    /* Subjects */
    fp=fopen("subjects.txt","r");

    if(fp!=NULL)
    {
        while(fgets(line,sizeof(line),fp)!=NULL)
            subjects++;

        fclose(fp);
    }

    /* Complaints */
    fp=fopen("complaints.txt","r");

    if(fp!=NULL)
    {
        while(fgets(line,sizeof(line),fp)!=NULL)
            complaints++;

        fclose(fp);
    }

    /* Notices */
    fp=fopen("notices.txt","r");

    if(fp!=NULL)
    {
        while(fgets(line,sizeof(line),fp)!=NULL)
            notices++;

        fclose(fp);
    }

    /* Assignments */
    fp=fopen("assignments.txt","r");

    if(fp!=NULL)
    {
        while(fgets(line,sizeof(line),fp)!=NULL)
            assignments++;

        fclose(fp);
    }

    printf("\n=================================");
    printf("\n         SMART DASHBOARD");
    printf("\n=================================");

    printf("\nTotal Students    : %d",students);
    printf("\nTotal Teachers    : %d",teachers);
    printf("\nTotal Subjects    : %d",subjects);
    printf("\nComplaints        : %d",complaints);
    printf("\nNotices           : %d",notices);
    printf("\nAssignments       : %d",assignments);

    printf("\n=================================\n");
}

void studentDashboard()
{
    int choice;

    while(1)
    {
        printf("\n===== Student Dashboard =====");

        printf("\n1. View Attendance");
        printf("\n2. View Assignments");
        printf("\n3. View Marks and GPA");
        printf("\n4. View Fee Status");
        printf("\n5. Submit Complaint");
        printf("\n6. View Complaint Status");
        printf("\n7. View Notices");
        printf("\n8. View Student Timetable");
        printf("\n9. Logout");

        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
{
    case 1:
        viewAttendance();
        break;

    case 2:
        viewAssignments();
        break;

    case 3:
        viewMarks();
        break;

    case 4:
        viewFeeStatus();
        break;

    case 5:
        submitComplaint();
        break;
        
    case 6:
        viewComplaintStatus();
        break;

    case 7:
        viewNotices();
        break;

    case 8:
        viewStudentTimetable();
        break;

    case 9:
        return;

    default:
        printf("\nInvalid Choice!\n");
}
    }
}

void teacherDashboard()
{
    int choice;

    while(1)
    {
        printf("\n===== Teacher Dashboard =====");

        printf("\n1. Mark Attendance");
        printf("\n2. View Attendance Report");
        printf("\n3. Post Assignments");
        printf("\n4. Enter Marks");
        printf("\n5. View Performance Summary");
        printf("\n6. Post Announcements");
        printf("\n7. View Teacher Timetable");
        printf("\n8. View Defaulter List");
        printf("\n9. Logout");

        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
{
    case 1:
        markAttendance();
        break;

    case 2:
        attendanceReport();
        break;

    case 3:
        postAssignments();
        break;

    case 4:
        enterMarks();
        break;

    case 5:
        performanceSummary();
        break;

    case 6:
        postAnnouncements();
        break;

    case 7:
        viewTeacherTimetable();
        break;
        
    case 8:
        viewDefaulterList();
        break;

    case 9:
        return;

    default:
        printf("\nInvalid Choice!\n");
}
    }
}

void markAttendance()
{
    FILE *fp;

    fp = fopen("attendance.txt","a");

    if(fp == NULL)
    {
        printf("\nFile could not be opened!");
        return;
    }

    printf("\n===== Mark Attendance =====");

    printf("\nEnter Student ID: ");
    scanf("%s",a.studentID);

    fflush(stdin);

    printf("Enter Student Name: ");
    scanf(" %[^\n]",a.name);

    printf("Enter Date (DD/MM/YYYY): ");
    scanf("%s",a.date);

    printf("Enter Status (Present/Absent): ");
    scanf("%s",a.status);

    fprintf(fp,"%s|%s|%s|%s\n",
            a.studentID,
            a.name,
            a.date,
            a.status);

    fclose(fp);

    printf("\nAttendance Marked Successfully!\n");
}

void viewAttendance()
{
    FILE *fp;

    int total = 0, present = 0;
    float percentage;

    fp = fopen("attendance.txt","r");

    if(fp == NULL)
    {
        printf("\nNo Attendance Record Found!\n");
        return;
    }

    printf("\n===== My Attendance =====\n\n");

    while(fscanf(fp,"%[^|]|%[^|]|%[^|]|%[^\n]\n",
                 a.studentID,
                 a.name,
                 a.date,
                 a.status)!=EOF)
    {
        if(strcmp(a.studentID,currentStudentID)==0)
        {
            printf("%s | %s\n",a.date,a.status);

            total++;

            if(strcmp(a.status,"Present")==0)
            {
                present++;
            }
        }
    }

    fclose(fp);

    if(total == 0)
    {
        printf("\nNo Attendance Found!\n");
        return;
    }

    percentage = (float)present * 100 / total;

    printf("\nAttendance Percentage = %.2f%%\n",percentage);

    if(percentage < 75)
    {
        printf("\nWARNING: Attendance below 75%%!\n");
    }
}
void attendanceReport()
{
    FILE *fp;

    fp = fopen("attendance.txt","r");

    if(fp == NULL)
    {
        printf("\nNo Attendance Record Found!\n");
        return;
    }

    printf("\n===== Attendance Report =====\n\n");

    while(fgets(line,sizeof(line),fp)!=NULL)
    {
        printf("%s",line);
    }

    fclose(fp);
}

void generateDefaulterList()
{
    FILE *attendanceFile, *studentFile, *defaulterFile;

    int total, present;
    float percentage;

    attendanceFile = fopen("attendance.txt","r");
    studentFile = fopen("students.txt","r");
    defaulterFile = fopen("defaulters.txt","w");

    if(attendanceFile==NULL || studentFile==NULL || defaulterFile==NULL)
    {
        printf("\nRequired file missing!\n");
        return;
    }

    while(fgets(line,sizeof(line),studentFile)!=NULL)
    {
        sscanf(line,"%[^|]|%[^|]",
               s.studentID,
               s.name);

        rewind(attendanceFile);

        total=0;
        present=0;

        while(fscanf(attendanceFile,"%[^|]|%[^|]|%[^|]|%[^\n]\n",
                     a.studentID,
                     a.name,
                     a.date,
                     a.status)!=EOF)
        {
            if(strcmp(a.studentID,s.studentID)==0)
            {
                total++;

                if(strcmp(a.status,"Present")==0)
                {
                    present++;
                }
            }
        }

        if(total>0)
        {
            percentage=(float)present*100/total;

            if(percentage<75)
            {
                fprintf(defaulterFile,
                        "%s | %s | %.2f%%\n",
                        s.studentID,
                        s.name,
                        percentage);
            }
        }
    }

    fclose(attendanceFile);
    fclose(studentFile);
    fclose(defaulterFile);

    printf("\nDefaulter List Generated Successfully!\n");
}

void viewDefaulterList()
{
    FILE *fp;

    fp=fopen("defaulters.txt","r");

    if(fp==NULL)
    {
        printf("\nNo Defaulters Found!\n");
        return;
    }

    printf("\n===== Defaulter List =====\n\n");

    while(fgets(line,sizeof(line),fp)!=NULL)
    {
        printf("%s",line);
    }

    fclose(fp);
}

void postAssignments()
{
    FILE *fp;

    fp = fopen("assignments.txt","a");

    if(fp == NULL)
    {
        printf("\nFile could not be opened!");
        return;
    }

    printf("\n===== Post Assignment =====");

    fflush(stdin);

    printf("\nEnter Subject: ");
    scanf(" %[^\n]",assign.subject);

    printf("Enter Title: ");
    scanf(" %[^\n]",assign.title);

    printf("Enter Deadline: ");
    scanf("%s",assign.deadline);

    fprintf(fp,"%s|%s|%s\n",
            assign.subject,
            assign.title,
            assign.deadline);

    fclose(fp);

    printf("\nAssignment Posted Successfully!\n");
}

void enterMarks()
{
    FILE *fp;

    fp = fopen("marks.txt","a");

    if(fp == NULL)
    {
        printf("\nFile could not be opened!");
        return;
    }

    printf("\n===== Enter Marks =====");

    printf("\nEnter Student ID: ");
    scanf("%s",m.studentID);

    fflush(stdin);

    printf("Enter Subject: ");
    scanf(" %[^\n]",m.subject);

    printf("Enter Marks: ");
    scanf("%d",&m.marks);

    m.gradePoints = calculateGradePoints(m.marks);

    fprintf(fp,"%s|%s|%d|%.2f\n",
            m.studentID,
            m.subject,
            m.marks,
            m.gradePoints);

    fclose(fp);

    printf("\nMarks Entered Successfully!\n");
}

void performanceSummary()
{
    FILE *fp;

    int highest=0;
    int lowest=100;
    int totalMarks=0;
    int totalSubjects=0;

    fp=fopen("marks.txt","r");

    if(fp==NULL)
    {
        printf("\nNo Marks Record Found!\n");
        return;
    }

    while(fscanf(fp,"%[^|]|%[^|]|%d|%f\n",
                 m.studentID,
                 m.subject,
                 &m.marks,
                 &m.gradePoints)!=EOF)
    {
        if(m.marks>highest)
            highest=m.marks;

        if(m.marks<lowest)
            lowest=m.marks;

        totalMarks+=m.marks;
        totalSubjects++;
    }

    fclose(fp);

    printf("\n===== Performance Summary =====");

    printf("\nHighest Marks : %d",highest);

    printf("\nLowest Marks : %d",lowest);

    if(totalSubjects>0)
    {
        printf("\nAverage Marks : %.2f",
               (float)totalMarks/totalSubjects);
    }

    printf("\n");
}

void postAnnouncements()
{
    FILE *fp;

    fp = fopen("notices.txt","a");

    if(fp == NULL)
    {
        printf("\nFile could not be opened!");
        return;
    }

    printf("\n===== Post Announcement =====");

    fflush(stdin);

    printf("\nEnter Title: ");
    scanf(" %[^\n]",n.title);

    printf("Enter Message: ");
    scanf(" %[^\n]",n.message);

    fprintf(fp,"%s|%s\n",
            n.title,
            n.message);

    fclose(fp);

    printf("\nAnnouncement Posted Successfully!\n");
}

void viewTeacherTimetable()
{
    FILE *fp;
    char line[500], copy[500], fileID[20];
    char *token;
    int found=0;

    fp=fopen("teacher_timetable.txt","r");

    if(fp==NULL)
    {
        printf("\nNo Timetable Found!\n");
        return;
    }

    printf("\n===== Teaching Timetable =====\n\n");

    while(fgets(line,sizeof(line),fp)!=NULL)
    {
        strcpy(copy,line);

        token=strtok(copy,"|");
        strcpy(fileID,token);

        if(strcmp(fileID,currentTeacherID)==0)
        {
            printf("%s",line);
            found=1;
        }
    }

    fclose(fp);

    if(found==0)
        printf("\nNo Timetable Assigned!\n");
}

void viewStudentTimetable()
{
    FILE *fp;
    char line[500];
    char program[50],batch[20],section[10];
    char day[20],time[30],subject[50],room[20];

    int found=0;

    fp=fopen("student_timetable.txt","r");

    if(fp==NULL)
    {
        printf("\nNo Timetable Found!\n");
        return;
    }

    printf("\n===== My Timetable =====\n\n");

    while(fgets(line,sizeof(line),fp)!=NULL)
    {
        sscanf(line,
        "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|\n]",
        program,batch,section,day,time,subject,room);

        if(strcmp(program,currentProgram)==0 &&
           strcmp(batch,currentBatch)==0 &&
           strcmp(section,currentSection)==0)
        {
            printf("%s | %s | %s | %s\n",
                   day,time,subject,room);

            found=1;
        }
    }

    fclose(fp);

    if(found==0)
        printf("\nNo Timetable Assigned!\n");
}

void viewAssignments()
{
    FILE *fp;

    char line[500];

    fp = fopen("assignments.txt","r");

    if(fp == NULL)
    {
        printf("\nNo Assignments Found!\n");
        return;
    }

    printf("\n===== Assignments =====\n\n");

    while(fgets(line,sizeof(line),fp)!=NULL)
    {
        printf("%s",line);
    }

    fclose(fp);
}

void viewMarks()
{
    FILE *fp;

    char line[500];
    char copy[500];
    char fileStudentID[20];
    char *token;

    float totalGP = 0;
    int count = 0;

    fp = fopen("marks.txt","r");

    if(fp == NULL)
    {
        printf("\nNo Marks Record Found!\n");
        return;
    }

    printf("\n===== My Marks =====\n\n");

    while(fgets(line,sizeof(line),fp)!=NULL)
    {
        strcpy(copy,line);

        token = strtok(copy,"|");
        strcpy(fileStudentID,token);

        if(strcmp(currentStudentID,fileStudentID)==0)
        {
            printf("%s",line);

            token = strtok(NULL,"|"); // subject
            token = strtok(NULL,"|"); // marks
            token = strtok(NULL,"|"); // grade point

            totalGP += atof(token);
            count++;
        }
    }

    fclose(fp);

    if(count > 0)
    {
        printf("\nSubject\tMarks\tGP\n");
        printf("--------------------------\n");
		printf("\nCurrent CGPA = %.2f\n",totalGP/count);
    }
    else
    {
        printf("\nNo Subjects Found!\n");
    }
}

void viewFeeStatus()
{
    FILE *fp;

    char id[20], status[20], date[20];
    int amount;
    int found = 0;

    fp = fopen("fees.txt","r");

    if(fp == NULL)
    {
        printf("\nNo Fee Record Found!\n");
        return;
    }

    printf("\n===== Fee Status and Payment History =====\n\n");

    while(fscanf(fp,"%[^|]|%d|%[^|]|%[^\n]\n",
                 id,
                 &amount,
                 status,
                 date)!=EOF)
    {
        if(strcmp(id,currentStudentID)==0)
        {
            printf("Amount : %d",amount);
            printf("\nStatus : %s",status);
            printf("\nDate   : %s\n\n",date);

            found = 1;
        }
    }

    fclose(fp);

    if(found==0)
    {
        printf("\nNo Fee Record Found!\n");
    }
}

void submitComplaint()
{
    FILE *fp;

    fp = fopen("complaints.txt","a");

    if(fp == NULL)
    {
        printf("\nFile could not be opened!");
        return;
    }

    printf("\n===== Submit Complaint =====");

    strcpy(c.studentID,currentStudentID);

    fflush(stdin);

    printf("\nEnter Subject: ");
    scanf(" %[^\n]",c.subject);

    printf("Enter Message: ");
    scanf(" %[^\n]",c.message);

    fprintf(fp,"%s|%s|%s|Pending\n",
        c.studentID,
        c.subject,
        c.message);

    fclose(fp);

    printf("\nComplaint Submitted Successfully!\n");
}

void viewNotices()
{
    FILE *fp;

    char line[500];

    fp = fopen("notices.txt","r");

    if(fp == NULL)
    {
        printf("\nNo Notices Found!\n");
        return;
    }

    printf("\n===== Notices =====\n\n");

    while(fgets(line,sizeof(line),fp)!=NULL)
    {
        printf("%s",line);
    }

    fclose(fp);
}

void viewComplaintStatus()
{
    FILE *fp;

    char id[20],subject[100],message[200],status[20];

    fp=fopen("complaints.txt","r");

    if(fp==NULL)
    {
        printf("\nNo Complaints Found!\n");
        return;
    }

    printf("\n===== My Complaints =====\n\n");

    while(fscanf(fp,"%[^|]|%[^|]|%[^|]|%[^\n]\n",
                 id,
                 subject,
                 message,
                 status)!=EOF)
    {
        if(strcmp(id,currentStudentID)==0)
        {
            printf("\nSubject : %s",subject);
            printf("\nMessage : %s",message);
            printf("\nStatus  : %s\n",status);
        }
    }

    fclose(fp);
}








