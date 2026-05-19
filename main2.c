#include <stdio.h>
#include <string.h>

//define structure to hold student information 

typedef struct
{
    char name[50];
    int admissionNo;
    int age;
    float marks[3];
    float average;
    char grade;
} Student;
//Adding of global array and counter
Student students[50];
int count=0;

//function prototypes to calculate grade

char calculateGrade(float avg);

//Function to add new student

void addStudent()
{
    if(count>=50){
        printf("Storage full\n");
        return;
    }
    Student s;
    //Inputting student details

    printf("Enter name:");
    scanf("%s",s.name);
    printf("Enter admission number:");
    scanf("%d",&s.admissionNo);
    printf("Enter age:");
    scanf("%d",&s.age);

    //Marks for the three subjects
    float sum=0;
    for(int i=0;i<3;i++){
        printf("Enter the marks for the subject %d:",i+1);
        scanf("%f",&s.marks[i]);
        sum +=s.marks[i];
    }   
    //Calculating average grade

    s.average=sum/3;
    s.grade=calculateGrade(s.average);
    students[count++]=s;
    printf("Student added successfully\n");
}
//Function to display all students

void displayStudents()
{
if(count==0){
    printf("No student to display.\n");
    return;
}
for(int i=0;i<count;i++){
    printf("\nName: %s\nAdmissionNo: %d\nAge: %d\nAverage: %.2f\nGrade: %c\n",students[i].name,students[i].admissionNo,students[i].age,students[i].average,students[i].grade);
}
}
//Function to search student by admission number

void searchStudent()
{
int adm;
printf("Enter admission number:");
scanf("%d",&adm);
//Looping through students to find match
for(int i=0;i<count;i++){
    if(students[i].admissionNo==adm){
        printf("\nFound student:\nName:%s\nAge:%d\nAverage:%.2f\nGrade:%c\n",students[i].name,students[i].age,students[i].average,students[i].grade);
        return;
    }
}
printf("Student not found.\n");
}
//Function to update student marks
void updateStudent()
{
int adm;
printf("Enter admission number to update:");
scanf("%d",&adm);
//Searching for students
for(int i=0;i<count;i++){
    if(students[i].admissionNo==adm){
        float sum=0;
        for(int j=0;j<3;j++){
            printf("Enter new marks for subject %d: ", j+1);
                scanf("%f", &students[i].marks[j]);
                sum += students[i].marks[j];
            }
            students[i].average = sum/3;
            students[i].grade = calculateGrade(students[i].average);

            printf("Marks updated successfully\n");
            return;
        }
    }
    printf("Student not found.\n");
}
//Function to calculate grade based on average marks
char calculateGrade(float avg){
    if(avg >= 70) return 'A';
    else if(avg >= 60) return 'B';
    else if(avg >= 50) return 'C';
    else if(avg >= 40) return 'D';
    else return 'E';
}
//Function to find and display best performing students
void bestStudent() {
    if(count == 0) {
        printf("No students available.\n");
        return;
    }

    int bestIndex = 0;
    for(int i=1; i<count; i++) {
        if(students[i].average > students[bestIndex].average) {
            bestIndex = i;
        }
    }
//Display best student details
    printf("\n===== Best Performing Student =====\n");
    printf("Name: %s\nAdmission No: %d\nAge: %d\nAverage: %.2f\nGrade: %c\n",
           students[bestIndex].name,
           students[bestIndex].admissionNo,
           students[bestIndex].age,
           students[bestIndex].average,
           students[bestIndex].grade);
}



int main()
{
    int choice;

    do
    {
        printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:addStudent();
            break;
            case 2:displayStudents();
            break;
            case 3:searchStudent();
            break;
            case 4:updateStudent();
            break;
            case 5:bestStudent();
            break;
            case 6:printf("Exiting...\n");
            break;
            default:printf("Invalid choice.\n");
        }

    } while (choice != 6);

    return 0;
}