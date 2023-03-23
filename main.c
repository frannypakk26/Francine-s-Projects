/*Employee Management System: It should keep track of when the employee signed in and out 
and needs to calculate the wages. It also should have multiple employees and all wages should be 
displayed separately by name and also together when needed (at least 10 employees). Sort by 
the field is required. 
*/
//Declaring header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//macro definitions
//allows for constant values to be declared throughout code, used globally
//macro definitions are not variables and cannot be changed

#define MAX_FIRST 30
//numeric constant called MAX_FIRST contains value 30
#define MAX_LAST 30
//numeric constant called MAX_LAST contains value 30
#define FILE_NAME "EmployeeDatabase.txt"
//string consant called FILE_NAME contains value "EmployeeDatabase.txt"
#define OUTPUT_FILE "EmployeeDatabaseRead.txt"

//define anonymous struct and give it alias Employee
//This struct is grouping several related variables into one place,
//This is our buffer

struct Employee{

    char FirstName[MAX_FIRST];
    char LastName[MAX_LAST];
    int employeeID;
    float salary;
    float net_salary;

};

//Declaring function prototypes for all the functions

void login();
void main_menu();
void showAllEmployees();
void manage_input(char);
void addEmployee();
void searchEmployee();
void welcomeMessage();
void logOut();
void BinaryToText();

//new_Employee n_employees[MAX_EMPLOYEE];

//struct for Employee , we gave it the name employees
//structs are used to group similar variables together.
struct Employee employees;

//Main function to call all of the functions
int main()
{
    //calls welcomeMessage function
    welcomeMessage();
    login();
    //calls main_menu function
    ///main_menu();
    return 0;
}

//The first page the user is redirected to
void welcomeMessage()
{

    printf("\n\n\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                  WELCOME                  =");
    printf("\n\t\t\t        =                    TO                     =");
    printf("\n\t\t\t        =               Employee Record             =");
    printf("\n\t\t\t        =                   SYSTEM                  =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\n\n\t\t\t Enter any key to continue.....\n\n");

    //getch() function will pause the output console until a key is pressed
    getch();
}

//Login function allows the user to log into the system

//Using pointer variables to store in strings

void login(){
	char *username = "EmployeeProject";
	char *password = "C&UNix22";
    time_t t;   // not a primitive datatype
    time(&t);
    int attempts = 4;
	char user[100];
    char pass[100];

//Loop to count the amount of attempts

    for(int i = 0; i < attempts; i++){

    printf("Enter the username: ");
	scanf("%s", &user);

	printf("\nEnter the password: ");
	scanf("%s", &pass);

//strcmp function compares the string arguments
//If statement that confirms the correct username and password
//==0 means true

    if(strcmp(username,user)==0 && strcmp(password,pass)==0){

    printf("\nYou've logged in at: %s", ctime(&t));

            main_menu();
        }
        else
        {
            printf("\t\t\t\tUserName or Password is invalid\n\n");

        }
    }


}

//After the user successfully logs in, the menu will be displayed
void main_menu()
{
    printf("\n\t\t\t--------------MENU---------------");
    printf("\n\t\t\t=================================");
   printf("\n\n\n\t\t\t1.Add Employee");
   printf("\n\t\t\t2.Search Employee");
   printf("\n\t\t\t3.Show Current Employees");
   printf("\n\t\t\t4.Logout");
   printf("\n\n\n\t\t\tEnter choice => ");

//create a variable to store the input
   char input;

//get char() reads a single character from the standard input stream stdin

//use getchar() to fetch input

//exit while loop if reaches end of line , EOF is received when there is no more input
   while ((input = getchar()) != EOF)
   {
       manage_input(input); //call manage_input with input
   }
}

//Function to get the input from the user to select an option
//Using switch cases to

void manage_input(char input)
{
    switch(input)
    {
        case '1':
            addEmployee();
            break;
        case '2':
            searchEmployee();
            break;
        case '3':
            showAllEmployees();
            break;
        case '4':
            logOut();
            break;
        case '5':
            printf("\n\n\n\t\t\t\tThank you!!!\n\n\n\n\n");
            exit(1);
            break;
        case '\n':
            break;
        default:
            printf("\n\n\n\t\t\tINVALID INPUT!!! Enter Choice =>");
    }                                           //Switch Ended
}

void addEmployee()
{

    FILE *fp;

    //Open file for writing in binary mode.
    //If the file exists, its contents are overwritten. If the file does not exist, it will be created.
    fp = fopen(FILE_NAME, "ab+");

    // //Check file exist or not
    // if(fp == NULL)
    // {
    //     printf("File cannot be opened\n");
    //     exit(1);
    // }

    printf("-------------- Add Employee(s) to System ---------------\n");

    int add = 0;
    int i;
    //user inputs the number of employees to be added
    printf("How many employees would you like to add?  ");
    scanf("%d", &add);

    //use for loop to add each employee until max number is reached
    printf("Enter %d Employee Details \n \n",add);
    for(i=0; i < add ; i++){
        printf("\nEmployee %d:- \n",i+1);


        //Prompts user to enter last name
        printf("Enter Last Name: ");
        scanf("%s", employees.LastName);

        //prompts user to enter first name
        printf("Enter First Name: ");
        scanf("%s", employees.FirstName);

        //prompts user to enter the employee ID
        printf("Enter Employee ID: ");
        scanf("%d",&employees.employeeID);

        //prompts user to enter the gross salary
        printf("Enter Gross Salary: ");
        scanf("%f",&employees.salary);

        printf("\n");

        //Display Deductions and taxes to user
        printf("\nHRA is 10%% of gross salary.");
        printf("\nDA is 5%% of gross salary.");
        printf("\nPF is 8%% of gross salary.");

        //calculate net salary from gross salary by using deductions and taxes
        employees.net_salary = employees.salary - (employees.salary*0.10 + employees.salary*0.05 + employees.salary*0.08);

        printf("\n\nCalculating Net Salary... \n");
        printf("\nNet Salary: %.2f \n", employees.net_salary);

        //fwrite() function writes binary and text data from an array to a given data stream.
        //buffer: points to the first object in the array to be written
        //size: the item size in bytes
        //count: the number of the objects to be written
        //stream: points to a FILE object that specifies an output stream

        fwrite(&employees, sizeof(employees), 1, fp);



    }
    //fprintf(fp, "Employee: %d %-32s %s %d %.2f %.2f \n",  employees[i].FirstName, employees[i].LastName, employees[i].employeeID, employees[i].salary, employees[i].net_salary);
    fclose(fp);
    puts("\n\nAddition to System Successful");

    // go back to main menu when done
    main_menu();
}

void searchEmployee()
{
    FILE*fp;
    //Open file for reading in binary mode.
    //If the file does not exist, fopen( ) returns NULL.
	fp=fopen(FILE_NAME,"rb");
	if(fp==NULL){
		printf("The file cannot be opened!");
		exit(1);
	}


    printf("-------------- Search for an Employee ---------------\n");
    int id;
    //Ask user to enter employee ID in order to find specifc employee
    printf("Enter Employee ID: ");
    scanf("%d", &id);


    //fread reads data from a file and stores it in a buffer
    //fread takes in parameters
    //Buffer: Pointer to the buffer where data will be stored. A buffer is a region of memory used to temporarily store data
    //Size: The size of each element to be read in bytes
    //Count: Number of elements to be read
    //Stream: Pointer to the FILE object from where data is to be read

    //&emploeyees points to the struct and stores into the struct

    while(fread(&employees,sizeof(employees),1,fp)==1)
    {
        //if the employee ID entered by the user matches an employee ID in the struct
        if(id==employees.employeeID)
        {
            //proceed to print out all of the employee information that matches the employee ID
            printf("Name:  ");
            printf("%s %s \n",employees.FirstName, employees.LastName);

            printf("Employee Id:  ");
            printf("%d \n",employees.employeeID);

            printf("Salary: ");
            printf("$%.2f \n",employees.salary);

            printf("Net Salary: ");
            printf("$%.2f \n",employees.net_salary);
            //printf("%s\t\t%s\t\t%d\t\t%f\n",employees.FirstName, employees.LastName,employees.employeeID,employees.net_salary);
        }
    }
    fclose(fp);
    main_menu();

}



void showAllEmployees()
{
    FILE*fp;
    //Open file for reading in binary mode.
    //If the file does not exist, fopen( ) returns NULL.
	fp=fopen(FILE_NAME,"rb");
	if(fp==NULL){
		printf("The file cannot be opened!");
		exit(1);
	}
    //printf("-------------- All Employees Details ---------------\n");
    printf("============================================================================================\n");
    printf("Employee First Name\t Employee Last Name\t Employee ID\t    Net Salary\n\n");
    printf("============================================================================================\n");

    //fread reads data from a file and stores it in a buffer
    //fread takes in parameters
    //Buffer: Pointer to the buffer where data will be stored. A buffer is a region of memory used to temporarily store data
    //Size: The size of each element to be read in bytes
    //Count: Number of elements to be read
    //Stream: Pointer to the FILE object from where data is to be read

     while(fread(&employees,sizeof(employees),1,fp)==1)
    {
        printf("%-s %28s %28d $%28.2f\n",employees.FirstName, employees.LastName,employees.employeeID,employees.net_salary);
    }
    puts("\n\nRecords Updated");

    main_menu();

    // go back to main menu when done


}

//LogOut function to allow the user to log out
//time_t is a datatype from the <time.h> header file,
//This system's time values are returned from the standard library function named time().

void logOut(){
    time_t t;   // not a primitive datatype
    time(&t);

//Clear the screen
    system("CLS");
    printf("Log out successful");

//The function ctime() returns a string that represents the local time based on tm (argument) timer.
//The ctime() function is defined in time.h header file.

    printf("\nYou've logged out at: %s", ctime(&t));

    exit(0);
    }


