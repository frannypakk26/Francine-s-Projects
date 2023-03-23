//Francine Dela Cruz
/*Shell System that takes the following commands: pwd, cd, ls. mkdir, rmdir, help
Flawed: help, mkdir, and rmdir not working properly
*/

# include <stdio.h> 
# include <stdlib.h>   // used to execute subprocess and commands
# include <string.h>   
# include <unistd.h>   // used for exit, getcwd, read, write, exec
# include <sys/wait.h>  
# include <sys/types.h> //used for rmdir, pid_t data type
# include <dirent.h> // for ls
# include <errno.h> 
# include <sys/stat.h> //use for mkdir
# include <fcntl.h>  // used for open



// read command line for the input line in shell
char *read_line(void){
    char *command =NULL;
    size_t buffer = 0;
    getline(&command, &buffer, stdin);
    return command;
}

// parse the input command
//breaks the two individual strings 
char **parse(char *my_line, char *command){
   int len = 0;
   int size = 64;
   
   /*were assigning a variable that points to a pointer and its assigned to a memory 
   allocator that manages a single block of memory with s specified size*/
   char **commandTokens = malloc(size * sizeof(char*));

   char *commandToken = strtok(my_line, " \t\n\r");

   while(commandToken != NULL){
    commandTokens[len]= commandToken;
    len++;

    if(len >= size){
      size = (int) (size * 1.5);
      commandTokens = realloc(commandTokens, size * sizeof(char*)); 
    }
    commandToken = strtok(NULL, " \t\n\r");
   }
   commandTokens[len] = NULL;
   //printf("%s",*commandTokens);
   return commandTokens;
}

void shellExec(char ** argv){
    /*pid_t: process IDs; used to represent process IDs; it is a signed integer type
    fork(): used for creating the duplicate of the calling process and forms two types of processes
        -parent process: from which a duplicate process has formed
        -child process: created by the prarent process in an OS using the fork()  system call
    */

    pid_t childProID = fork();
    

    if(childProID == 0){
        if(execvp(argv[0], argv) == -1){
            printf("Error: child process execution failed\n");
            exit(1); 
        }
        
    }else if(childProID > 0){
        int status;
        /* a type of system calls that allow a process to run any program files, which include binary executable or a shell script
        first arg: a character string that contains the name of a file to be executed
        second arg: a pointer of anarray of character strings.
        */
        do {
            /*waitpid(): suspends ethe calling process 
            until a child process ends or is stopped
            WUNTRACED: reports on child process as well as terminaed ones
            WIFEXISTED: query status to see if a child process ended normally
            WIFSIGNALED: query status to see if a child process ended abnormally
            */
            waitpid(childProID, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    } else {
        perror("Unable to process");
    }
}
    


void cdCommand(char *directory){
    if (chdir(directory) == -1) {
        perror("error changing directory");
        }
}



int main(int argc, char** argv){
     char *commandArg = argv[64];

    while(1){
        printf(">>");
        //reads the input from the user
        char *command = read_line();
        // Splits input to an array of tokens which can help distinguish the command and its arguments
        char **parseLine = parse(command, *argv); 

        /*if(parseLine[0] != NULL){
            shellExec(parseLine);
        }*/

        if(strcmp(parseLine[0], "pwd")==0){
            char pwd[1000];
            printf("%s", getcwd(pwd, sizeof(parseLine))); 

        }else if(strcmp(parseLine[0], "ls") == 0){
            DIR *lsCommand;
            struct dirent *listDir;

            lsCommand = opendir("."); 

            if(lsCommand){ //If the director stream is opened
                while ((listDir = readdir(lsCommand)) != NULL){ 
                    printf("%s\n", listDir->d_name);
            }
            closedir(lsCommand);
            }else{
            perror("error opening directory");
            } 

        }else if(strcmp(parseLine[0], "cd") == 0){
            cdCommand(parseLine[1]);
	        
        }else if(strcmp(parseLine[0], "mkdir") == 0){
            char dirName[1024];
            int ret = 0;

            printf("Enter directory name: ");
            scanf("%s", dirName);

            ret = mkdir(dirName, 0755);
            if (ret == 0){
            printf("Directory created successfully\n");
            }else{
                printf("Unable to create directory %s\n", dirName);
                return 0;
            }
        }else if(strcmp(parseLine[0], "rmdir") == 0){
            char *dirName;
            printf("Enter the directory you'd like to remove: ");
            scanf("%s", dirName);

            int status = rmdir(dirName);

            if (status == 0){
            printf("Directory removed successfully\n");
            }else{
                printf("Unable to remove directory %s\n", dirName);
                exit(1);
            }

        }else if(strcmp(parseLine[0], "help") == 0){
             if (argc > 1 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)) {
                if(parseLine[1] == NULL){
                // display general help information
                printf("Welcome to the shell. Here are the available commands:\n");
                printf("1. pwd: prints out the current working directory\n");
                printf("2. ls: prints out a list of files and directories located in the current directory\n");
                printf("3. cd: allows you to change directories\n");
                printf("4. mkdir: creates a new directory\n");
                printf("5. rmdir: removes a directory\n");
                printf("6. help: provides information about the following functions\n");
            }
        }
        
        }
        shellExec(parseLine);
        /*deallocates the memory that pwas previously allocated by a call from any of the alloc functions: calloc, malloc, and realloc 
        this frees the space before looping back for the next command input*/
        free(parseLine);
        free(command);

    ///printf("Welcome to Assignment 1 !\n");
    
}
    
}