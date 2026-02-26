#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tasks.h"

#define TASK_FILE "tasks.txt"
#define MAX_LINE 256

void add_task(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: devlog add <task>\n");
        return;
    }

    FILE *file = fopen(TASK_FILE, "a");
    if (!file) {
        printf("Error opening file\n");
        return;
    }

    fprintf(file, "0|");
    for (int i = 2; i < argc; i++) {
        fprintf(file, "%s", argv[i]);
        if (i < argc - 1) fprintf(file, " ");
    }
    fprintf(file, "\n");

    fclose(file);
    printf("Task added!\n");
}

void list_tasks() {
    FILE *file = fopen(TASK_FILE, "r");
    if (!file) {
        printf("No tasks found.\n");
        return;
    }

    char line[MAX_LINE];
    int count = 1;

    while (fgets(line, sizeof(line), file)) {
        int status;
        char task[MAX_LINE];

        sscanf(line, "%d|%[^\n]", &status, task);

        if (status == 0)
            printf("%d. [ ] %s\n", count, task);
        else
            printf("%d. [✓] %s\n", count, task);

        count++;
    }

    fclose(file);
}

void mark_done(int task_number) {
    FILE *file = fopen(TASK_FILE, "r");
    if (!file) return;

    FILE *temp = fopen("temp.txt", "w");
    if (!temp) return;

    char line[MAX_LINE];
    int count = 1;

    while (fgets(line, sizeof(line), file)) {
        int status;
        char task[MAX_LINE];

        sscanf(line, "%d|%[^\n]", &status, task);

        if (count == task_number)
            fprintf(temp, "1|%s\n", task);
        else
            fprintf(temp, "%d|%s\n", status, task);

        count++;
    }

    fclose(file);
    fclose(temp);

    remove(TASK_FILE);
    rename("temp.txt", TASK_FILE);

    printf("Task marked as done!\n");
}

void delete_task(int task_number) {
    FILE *file = fopen(TASK_FILE, "r");
    if (!file) return;

    FILE *temp = fopen("temp.txt", "w");
    if (!temp) return;

    char line[MAX_LINE];
    int count = 1;

    while (fgets(line, sizeof(line), file)) {
        if (count != task_number)
            fputs(line, temp);

        count++;
    }

    fclose(file);
    fclose(temp);

    remove(TASK_FILE);
    rename("temp.txt", TASK_FILE);

    printf("Task deleted!\n");

}