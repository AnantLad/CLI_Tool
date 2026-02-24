#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Usage: devlog <command>\n");
        return 1;
    }

    if (strcmp(argv[1], "add") == 0) {
        printf("Add command detected\n");
    }
    else if (strcmp(argv[1], "list") == 0) {
        printf("List command detected\n");
    }
    else if (strcmp(argv[1], "remove") == 0){
        printf("Remove command detected\n");
    }
    
    else {
        printf("Unknown command\n");
    }

    return 0;
}