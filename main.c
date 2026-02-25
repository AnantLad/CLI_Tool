#include <stdio.h>
#include <string.h>

#define TASK_FILE "tasks.txt"
     
int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Usage: devlog <command> [task]\n");
        return 1;
    }

    if (strcmp(argv[1], "add") == 0) {
        if(argc < 3){
            printf("Usage: devlog add <task description>\n");
            return 1;
        }
    
    FILE *file = fopen(TASK_FILE, "a");
    if(file == NULL){
        printf("Error opening file.\n");
        return 1;
    }
    
    for(int i = 2; i < argc; i++){
        fprintf(file, "%s", argv[i]);
        if(i < argc - 1) fprintf(file, " ");
    }
    fprintf(file , "\n");
    fclose(file);

    printf("Task added successfully.\n");
    }


    else if (strcmp(argv[1], "list") == 0) {
        FILE *file = fopen(TASK_FILE , "r");
        if(file == NULL){
            printf("No task found.\n");
            return 0;
        }

        char line[256];
        int count = 1;
        while(fgets(line, sizeof(line), file)){
            printf("%d. %s", count, line);
            count++;
        }
        fclose(file);
    }

    else if (strcmp(argv[1], "delete") == 0){

        printf("Remove command detected\n");
    }
    
    else {
        printf("Unknown command\n");
    }

    return 0;
}