#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


// remember that these are done with all lowcase keys
#ifndef SYMBOL
#define EXIT 2090237503
#define HELP 2090324718
#endif

const unsigned long hash(const char *str) {
        // returns strings hash, can be nicely used in switch case
        unsigned long hash = 5381;
        int c;

        while ((c = *str++))
                hash = ((hash << 5) + hash) + c;

        return hash;
}

void print_commands(){
        //return all commands in the softaware

        FILE *list_of_commands;
        list_of_commands = fopen("list_of_commands.txt", "r");
        char line[150];

        // if file is not null read the file
        printf("\n--------------------------------\n");
        printf("COMMANDS:");
        printf("\n--------------------------------\n");

        // read file if it's nut NULL
        if (list_of_commands != NULL) {
                // read lines while the line is not NULL, if line becames NULL terminate loop.
                while ( fgets(line, 30, list_of_commands) != NULL ) {
                        printf("%s", line);
                }

        }else{
                printf("File was NULL\n");
        }
}

void add_person(/* arguments */) {
        /* TODO code */
}

void remove_person(/* arguments */) {
        /* TODO code */
}

void edit_person(/* arguments */) {
        /* TODO code */
}

void main(){
        // main action loop for user to do something
        char user_input[20]; // stores user input

        while (strcmp(user_input, "exit") != 0)  {

                printf("\nWhat you want to do? (type help for commands)\n");
                printf("<<< ");
                fgets(user_input, 20, stdin);

                // removes newline from fgets. If the user names is longer than 0 and if the last chracter is \n
                if ((strlen(user_input) > 0) && (user_input[strlen (user_input) - 1] == '\n')) {
                        user_input[strlen (user_input) - 1] = '\0';  // the \n chatacter is replaced with null terminator
                }

                // make all characters in user_input to lowcase
                for(int i = 0; user_input[i]; i++) {
                        user_input[i] = tolower(user_input[i]);
                }

                printf("Users selection: %s and its hash %d\n", &user_input, hash(user_input));  // debug

                switch (hash(user_input)) {
                case EXIT:
                        // exits program
                        printf("Exiting program\n");
                        break;

                case HELP:
                        // prints out all commands
                        print_commands();
                        break;

                default:
                        // if no commands were correct
                        printf(">>> No such commands exists!!!\n");


                }


        }

}
