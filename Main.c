#include <stdio.h>
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


char commands(){
        //return all commands in the softaware
        char command[20];

        return command;
}


int main(){
        // main action loop for user to do something
        char user_input[20]; // stores user input

        while (strcmp(user_input, "exit") != 0)  {
                printf("\nWhat you want to do?\n");
                printf("<<< ");
                scanf("%s", &user_input);

                // make all characters in user_input to lowcase
                for(int i = 0; user_input[i]; i++) {
                        user_input[i] = tolower(user_input[i]);
                }

                printf("Users selection: %s and its hash %d\n", &user_input, hash(user_input));  // debug

                switch (hash(user_input)) {
                case EXIT:
                        // exits programm
                        printf("Exiting programm\n");
                        break;

                case HELP:
                        // prints out all commands
                        break;

                default:
                        // if no commands were correct
                        printf("No such commands exists\n");


                }


        }

        return 0;
}
