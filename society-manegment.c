#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_VISITORS 50

typedef struct {
    char name[50];
    char mobile[20];
    char house[10];
    time_t enter_time;
    time_t exit_time;
} Visitor;

int main() {
    Visitor visitors[MAX_VISITORS];
    int num_visitors = 0;

    printf("********************************************\n");
    printf("*      Welcome to Society Visitor Tracker   *\n");
    printf("********************************************\n");

    while (1) {
        printf("\nPlease select an option:\n");
        printf("1. Add a visitor\n");
        printf("2. Exit a visitor\n");
        printf("3. View current visitors\n");
        printf("4. Exit\n");
        printf("Your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (num_visitors >= MAX_VISITORS) {
                    printf("\nMaximum number of visitors reached.\n");
                    break;
                }

                Visitor new_visitor;

                printf("\nEnter visitor name: ");
                scanf("%s", new_visitor.name);

                printf("Enter visitor mobile number: ");
                scanf("%s", new_visitor.mobile);

                printf("Enter visitor house number: ");
                scanf("%s", new_visitor.house);

                printf("Enter visitor entry time (YYYY-MM-DD HH:MM:SS): ");
                char entry_time_str[20];
                scanf("%s", entry_time_str);
                struct tm entry_time_tm = {0};
                sscanf(entry_time_str, "%d-%d-%d %d:%d:%d", &entry_time_tm.tm_year, &entry_time_tm.tm_mon,
                        &entry_time_tm.tm_mday, &entry_time_tm.tm_hour, &entry_time_tm.tm_min, &entry_time_tm.tm_sec);
                entry_time_tm.tm_year -= 1900;  // Adjust year to be relative to 1900
                entry_time_tm.tm_mon -= 1;      // Adjust month to be in the range 0-11
                new_visitor.enter_time = mktime(&entry_time_tm);

                visitors[num_visitors++] = new_visitor;

                printf("\nVisitor added successfully.\n");

                break;
            }
            case 2: {
                printf("\nEnter visitor mobile number: ");
                char mobile[20];
                scanf("%s", mobile);

                int found = 0;
                for (int i = 0; i < num_visitors; i++) {
                    if (strcmp(visitors[i].mobile, mobile) == 0) {
                        if (visitors[i].exit_time == 0) {
                            printf("Enter visitor exit time (YYYY-MM-DD HH:MM:SS): ");
                            char exit_time_str[20];
                            scanf("%s", exit_time_str);
                            struct tm exit_time_tm = {0};
                            sscanf(exit_time_str, "%d-%d-%d %d:%d:%d", &exit_time_tm.tm_year, &exit_time_tm.tm_mon,
                                    &exit_time_tm.tm_mday, &exit_time_tm.tm_hour, &exit_time_tm.tm_min, &exit_time_tm.tm_sec);
                            exit_time_tm.tm_year -= 1900;  // Adjust year to be relative to 1900
                            exit_time_tm.tm_mon -= 1;      // Adjust month to be in the range 0-11
                            visitors[i].exit_time = mktime(&exit_time_tm);

                            printf("\n%s's visit has been recorded.\n", visitors
							[i].name);
found = 1;
} else {
printf("\n%s has already exited.\n", visitors[i].name);
}
break;
}
}
            if (!found) {
                printf("\nVisitor with mobile number %s not found.\n", mobile);
            }

            break;
        }
#define MAX_TIME_STR_LEN 50

case 3: {
    if (num_visitors == 0) {
        printf("\nNo visitors in the society.\n");
        break;
    }

    printf("\nCurrent visitors:\n");

    for (int i = 0; i < num_visitors; i++) {
        char enter_time_str[MAX_TIME_STR_LEN + 1];
        strftime(enter_time_str, sizeof(enter_time_str), "%Y-%m-%d %H:%M:%S", localtime(&visitors[i].enter_time));

        char exit_time_str[MAX_TIME_STR_LEN + 1];
        if (visitors[i].exit_time == 0) {
            strcpy(exit_time_str, "N/A");
        } else {
            strftime(exit_time_str, sizeof(exit_time_str), "%Y-%m-%d %H:%M:%S", localtime(&visitors[i].exit_time));
        }

        printf("%s (%s, House: %s, Entered: %s, Exited: %s)\n",
            visitors[i].name, visitors[i].mobile, visitors[i].house, enter_time_str, exit_time_str);
   
    break;
}

        case 4: {
            printf("\nExiting Society Visitor Tracker...\n");
            exit(0);
        }
        default: {
            printf("\nInvalid choice. Please try again.\n");
        }
    }
}
}
return 0;

}