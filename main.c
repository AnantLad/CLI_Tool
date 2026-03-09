#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "tasks.h"

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Usage: devlog <add|list|done|delete>\n");
        return 1;
    }

    if (strcmp(argv[1], "add") == 0) {
        add_task(argc, argv);
    }
    else if (strcmp(argv[1], "list") == 0) {
        list_tasks();
    }
    else if (strcmp(argv[1], "done") == 0) {
        if (argc < 3) {
            printf("Usage: devlog done <task_number>\n");
            return 1;
        }
        mark_done(atoi(argv[2]));
    }
    else if (strcmp(argv[1], "delete") == 0) {
        if (argc < 3) {
            printf("Usage: devlog delete <task_number>\n");
            return 1;
        }
        delete_task(atoi(argv[2]));
    }
    
    else {
        printf("Unknown command\n");
    }

    return 0;
}