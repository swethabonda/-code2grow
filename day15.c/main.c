#include <stdio.h>

int main() {
    int n, i;
    int marks[10];
    int total = 0;
    int highest, lowest;
    int passed = 0, failed = 0;
    int gradeAplus = 0, gradeA = 0, gradeB = 0, gradeC = 0, gradeD = 0;

    printf("===== Student Performance Analyzer =====\n");

    
    printf("Enter total number of students (max 10): ");
    scanf("%d", &n);

    
    for (i = 0; i < n; i++) {
        printf("Enter marks of student %d: ", i + 1);
        scanf("%d", &marks[i]);
    }

    
    highest = marks[0];
    lowest = marks[0];

    
    for (i = 0; i < n; i++) {
        total += marks[i];

        
        if (marks[i] > highest)
            highest = marks[i];
        if (marks[i] < lowest)
            lowest = marks[i];

        
        if (marks[i] >= 90)
            gradeAplus++;
        else if (marks[i] >= 80)
            gradeA++;
        else if (marks[i] >= 70)
            gradeB++;
        else if (marks[i] >= 60)
            gradeC++;
        else if (marks[i] >= 50)
            gradeD++;
        else
            failed++;
    }

    // Calculate average
    float average = (float) total / n;

    // Count passed students (marks >= 50)
    passed = n - failed;

    
    printf("\n===== Result Summary =====\n");
    printf("Average Marks: %.2f\n", average);
    printf("Highest Marks: %d\n", highest);
    printf("Lowest Marks : %d\n", lowest);
    printf("\nTotal Passed Students: %d\n", passed);
    printf("Total Failed Students: %d\n", failed);

    
    printf("\nGrade Distribution:\n");
    printf("A+ : %d\n", gradeAplus);
    printf("A  : %d\n", gradeA);
    printf("B  : %d\n", gradeB);
    printf("C  : %d\n", gradeC);
    printf("D  : %d\n", gradeD);
    printf("Fail : %d\n", failed);

    printf("=====================================\n");

    return 0;
}
