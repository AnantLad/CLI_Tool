#ifndef TASKS_H
#define TASKS_H

void add_task(int argc, char *argv[]);
void list_tasks();
void mark_done(int task_number);
void delete_task(int task_number);

#endif