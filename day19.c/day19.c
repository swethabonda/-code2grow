#include <stdio.h>

int main() {
    int attendance[5][5];
    int marks[5][5];
    char names[5][20];

    int i, j, choice;

    
    printf("Enter names of 5 students:\n");
    for(i=0; i<5; i++) {
        printf("Student %d name: ", i+1);
        scanf("%s", names[i]);
    }

    printf("\nEnter Attendance (1 = Present, 0 = Absent)\n");
    for(i=0; i<5; i++) {
        printf("\n--- Attendance for %s ---\n", names[i]);
        for(j=0; j<5; j++) {
            printf("Subject %d: ", j+1);
            scanf("%d", &attendance[i][j]);
        }
    }

    printf("\nEnter Marks (0–100)\n");
    for(i=0; i<5; i++) {
        printf("\n--- Marks for %s ---\n", names[i]);
        for(j=0; j<5; j++) {
            printf("Subject %d: ", j+1);
            scanf("%d", &marks[i][j]);
        }
    }


    int totalAttendance[5] = {0};
    int totalAbsence[5] = {0};
    int totalMarks[5] = {0};
    float average[5];

    for(i=0; i<5; i++) {
        for(j=0; j<5; j++) {
            totalAttendance[i] += attendance[i][j];
            totalAbsence[i] += (attendance[i][j] == 0);
            totalMarks[i] += marks[i][j];
        }
        average[i] = totalMarks[i] / 5.0;
    }

    
    int maxAtt = 0, minAtt = 0;
    for(i=1; i<5; i++) {
        if(totalAttendance[i] > totalAttendance[maxAtt]) maxAtt = i;
        if(totalAttendance[i] < totalAttendance[minAtt]) minAtt = i;
    }

    
    int topper = 0, lowPerf = 0;
    for(i=1; i<5; i++) {
        if(totalMarks[i] > totalMarks[topper]) topper = i;
        if(totalMarks[i] < totalMarks[lowPerf]) lowPerf = i;
    }

    
  
    while(1) {
        printf("\n========= MENU =========\n");
        printf("1. Display Attendance Matrix\n");
        printf("2. Display Marks Matrix\n");
        printf("3. Attendance Report\n");
        printf("4. Performance Report\n");
        printf("5. Grade Report\n");
        printf("6. Exit\n");
        printf("=========================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("\n--- Attendance Matrix ---\n");
                for(i=0; i<5; i++) {
                    printf("%s : ", names[i]);
                    for(j=0; j<5; j++) {
                        printf("%d ", attendance[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 2:
                printf("\n--- Marks Matrix ---\n");
                for(i=0; i<5; i++) {
                    printf("%s : ", names[i]);
                    for(j=0; j<5; j++) {
                        printf("%d ", marks[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 3:
                printf("\n--- Attendance Report ---\n");
                for(i=0; i<5; i++) {
                    printf("%s - Present: %d | Absent: %d\n",
                           names[i], totalAttendance[i], totalAbsence[i]);
                }
                printf("\nHighest Attendance: %s\n", names[maxAtt]);
                printf("Lowest Attendance : %s\n", names[minAtt]);
                break;

            case 4:
                printf("\n--- Performance Report ---\n");
                for(i=0; i<5; i++) {
                    printf("%s - Total Marks: %d | Average: %.2f\n",
                           names[i], totalMarks[i], average[i]);
                }
                printf("\nClass Topper: %s\n", names[topper]);
                printf("Lowest Performer: %s\n", names[lowPerf]);
                break;

            case 5:
                printf("\n--- Grade Report ---\n");
                for(i=0; i<5; i++) {
                    char grade;
                    float avg = average[i];

                    if(avg >= 90) grade = 'A';
                    else if(avg >= 80) grade = 'B';
                    else if(avg >= 70) grade = 'C';
                    else if(avg >= 60) grade = 'D';
                    else grade = 'F';

                    printf("%s - Average: %.2f | Grade: %c\n",
                           names[i], avg, grade);
                }
                break;

            case 6:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}