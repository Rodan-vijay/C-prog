#include <stdio.h>
#include <string.h>
#include <time.h>
FILE *fptr;
int i,j;

struct Task {
    char title[50];
    int priority;
    int completed;
};

struct Task tasks[100];
int n_tasks = 0;

void addTask(const char *title, int priority) {
    if (n_tasks < 100) {
        strcpy(tasks[n_tasks].title, title);
        tasks[n_tasks].priority = priority;
    
        tasks[n_tasks].completed = 0;
        n_tasks++;
    } else {
        printf("Maximum number of tasks reached!\n");
    }
}

void sort() {
struct Task temp;
      for( i = 0; i < n_tasks; i++) {
        for( j= 0; j < n_tasks - 1 - i; j++) {
            if (tasks[j].priority < tasks[j + 1].priority) {
                temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }
}

void print_tasks() {
    fptr = fopen("Todolist.txt", "w");

    time_t now;
    time(&now);
    char date[20];
    strftime(date, 20, "%d/%m/%y", localtime(&now));
    printf("Tasks for today %s \n", date);
    fprintf(fptr, "Tasks for today %s\n", date);
    for (i = 0; i < n_tasks; i++) {
        if (tasks[i].completed == 0){
            printf("[ ] ");
            fprintf(fptr, "[ ] ");
        } else {
            printf("[\u2713] ");
            fprintf(fptr, "[\u2713] ");
        }
        printf("%s (Priority: %d)\n", tasks[i].title, tasks[i].priority);
        fprintf(fptr, "%s (Priority: %d)\n", tasks[i].title, tasks[i].priority);
    }
    fclose(fptr);
}

int main() {
    int choice;
    int n, i;
    char title[50];
    int priority;

    printf("Welcome to the to-do list maker!\n");
    do {
        printf("---------------------------------------------------\n");
        printf("Do you want to add tasks or view existing tasks?\n");
        printf("1. Add tasks\n");
        printf("2. View existing tasks for today\n");
        printf("3. Mark the completion of tasks\n");
        printf("4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("How many tasks do you want to add? ");
            scanf("%d", &n);

            for (i = 0; i < n; i++) {
                printf("\nEnter title for task %d: ", i + 1);
                scanf(" %s", title);
                printf("\nEnter priority for task %d (0 - Low, 1 - Medium, 2 - High): ", i + 1);
                scanf("%d", &priority);
                addTask(title, priority);
            }
            sort();
        } 
        else if (choice == 2) {
            print_tasks();
        } 
        else if (choice == 3) {
            print_tasks();
            int n = 0;
            while (1) {
                printf("Enter the task number : ");
                scanf("%d", &n);
                if (n == -1)
                    break;
                tasks[n - 1].completed = 1;
            }
        }
    } while (choice <= 3 && choice >= 1);

    return 0;
}
