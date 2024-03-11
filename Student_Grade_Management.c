#include <stdio.h>

// Define constants
#define MAX_STUDENTS 50
#define MAX_SUBJECTS 5

// Function prototypes
void inputStudentInfo(int index, char names[MAX_STUDENTS][50], int *numSubjects);
void inputSubjectScores(int numSubjects, float scores[MAX_STUDENTS][MAX_SUBJECTS]);
void calculateAverage(int numStudents, int numSubjects, float scores[MAX_STUDENTS][MAX_SUBJECTS], float averages[MAX_STUDENTS]);
void identifyMinMax(int numStudents, int numSubjects, float scores[MAX_STUDENTS][MAX_SUBJECTS], float *maxScore, float *minScore);
void displaySummary(int numStudents, int numSubjects, char names[MAX_STUDENTS][50], float scores[MAX_STUDENTS][MAX_SUBJECTS], float averages[MAX_STUDENTS], float maxScore, float minScore);

int main() {
    char names[MAX_STUDENTS][50];
    float scores[MAX_STUDENTS][MAX_SUBJECTS];
    float averages[MAX_STUDENTS];
    int numStudents, numSubjects;

    printf("Enter the number of students (up to %d): ", MAX_STUDENTS);
    scanf("%d", &numStudents);

    // Input student information and subject scores
    for (int i = 0; i < numStudents; i++) {
        inputStudentInfo(i, names, &numSubjects);
        inputSubjectScores(numSubjects, scores);
    }

    // Calculate averages
    calculateAverage(numStudents, numSubjects, scores, averages);

    // Identify highest and lowest scores
    float maxScore, minScore;
    identifyMinMax(numStudents, numSubjects, scores, &maxScore, &minScore);

    // Display summary
    displaySummary(numStudents, numSubjects, names, scores, averages, maxScore, minScore);

    return 0;
}

void inputStudentInfo(int index, char names[MAX_STUDENTS][50], int *numSubjects) {
    printf("\nEnter details for student %d:\n", index + 1);
    printf("Enter student name: ");
    scanf("%s", names[index]);

    printf("Enter the number of subjects for %s: ", names[index]);
    scanf("%d", numSubjects);
}

void inputSubjectScores(int numSubjects, float scores[MAX_STUDENTS][MAX_SUBJECTS]) {
    printf("Enter subject scores:\n");
    for (int i = 0; i < numSubjects; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%f", &scores[i]);
    }
}

void calculateAverage(int numStudents, int numSubjects, float scores[MAX_STUDENTS][MAX_SUBJECTS], float averages[MAX_STUDENTS]) {
    for (int i = 0; i < numStudents; i++) {
        float sum = 0;
        for (int j = 0; j < numSubjects; j++) {
            sum += scores[i][j];
        }
        averages[i] = sum / numSubjects;
    }
}

void identifyMinMax(int numStudents, int numSubjects, float scores[MAX_STUDENTS][MAX_SUBJECTS], float *maxScore, float *minScore) {
    *maxScore = *minScore = scores[0][0];
    for (int i = 0; i < numStudents; i++) {
        for (int j = 0; j < numSubjects; j++) {
            if (scores[i][j] > *maxScore) {
                *maxScore = scores[i][j];
            }
            if (scores[i][j] < *minScore) {
                *minScore = scores[i][j];
            }
        }
    }
}

void displaySummary(int numStudents, int numSubjects, char names[MAX_STUDENTS][50], float scores[MAX_STUDENTS][MAX_SUBJECTS], float averages[MAX_STUDENTS], float maxScore, float minScore) {
    printf("\nSummary:\n");
    printf("------------------------------------------------\n");
    printf("%-20s %-15s %-15s\n", "Student Name", "Average Score", "Subject Scores");
    printf("------------------------------------------------\n");

    for (int i = 0; i < numStudents; i++) {
        printf("%-20s %-15.2f", names[i], averages[i]);

        for (int j = 0; j < numSubjects; j++) {
            printf("%-10.2f", scores[i][j]);
        }

        printf("\n");
    }

    printf("------------------------------------------------\n");
    printf("Highest Score: %.2f\n", maxScore);
    printf("Lowest Score: %.2f\n", minScore);
}
