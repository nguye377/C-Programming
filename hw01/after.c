// vim: fileencoding=utf8 expandtab tabstop=4 shiftwidth=4
#include <stdio.h>
#include <stdlib.h>
const int NUM_HOMEWORK = 15;
const float HOMEWORK_SCORES[] = {
    100,  // hw1
    100,  // hw2
    100,  // hw3
    100,  // hw4
     70,  // hw5
     80,  // hw6
    100,  // hw7
     80,  // hw8
    100,  // hw9
    100,  // hw10
     80,  // hw11
    100,  // hw12
     70,  // hw13
     80,  // hw14
    100   // hw15
};
const float HOMEWORK_WEIGHTS[] = {
    1.0,  // hw1
    1.0,  // hw2
    1.0,  // hw3
    1.0,  // hw4
    1.0,  // hw5
    1.0,  // hw6
    1.0,  // hw7
    1.0,  // hw8
    1.0,  // hw9
    1.0,  // hw10
    1.0,  // hw11
    1.0,  // hw12
    1.0,  // hw13
    1.0,  // hw14
    1.0   // hw15
};
const int NUM_EXAMS = 3;
const float EXAM_SCORES[] = {
     80,  // exam1
     95,  // exam2
     85,  // exam3
     85   // exam4 (final)
};
const float EXAM_WEIGHTS[] = {
   0.25,  // exam1
   0.25,  // exam2
   0.25,  // exam3
   0.25   // exam4 (final)
};
const float BONUS_POINTS = 3.0;
const float PARTICIPATION_POINTS = 2.0;
float average(const float values[], const int num_values) {
    float sum = 0.0;
    for(int i = 0; i < num_values; i++) {
        sum += values[i];
    }
    return sum / num_values;
}
float weighted_sum(const float values[], const float weights[], const int num_values) {
    float sum = 0.0;
    for(int i = 0; i < num_values; i++) {
        sum += values[i] * weights[i];
    }
    return sum;
}
float weighted_average(const float values[], const float weights[], const int num_values) {
    return weighted_sum(values, weights, num_values) / num_values;
}
void print_grade(float summary_score) {
    if(summary_score >= 85) {
        printf("A\n");
    }
    else if(summary_score >= 82) {
        printf("A-\n");
    }
    else if(summary_score >= 78) {
        printf("B+\n");
    }
    else if(summary_score >= 75) {
        printf("B\n");
    }
    else if(summary_score >= 72) {
        printf("B-\n");
    }
    else if(summary_score >= 68) {
        printf("C+\n");
    }
    else if(summary_score >= 65) {
        printf("C\n");
    }
    else if(summary_score >= 62) {
        printf("C-\n");
    }
    else if(summary_score >= 58) {
        printf("D+\n");
    }
    else if(summary_score >= 55) {
        printf("D\n");
    }
    else if(summary_score >= 50) {
        printf("D-\n");
    }
    else {
        printf("F\n");
    }
}
int main(int argc, char *argv[]) {
    float exam_score = weighted_sum(EXAM_SCORES, EXAM_WEIGHTS, NUM_EXAMS);
    float hw_score = weighted_average(HOMEWORK_SCORES, HOMEWORK_WEIGHTS, NUM_HOMEWORK);
    float summary_score = exam_score * 0.5
                        + hw_score   * 0.5
                        + PARTICIPATION_POINTS
                        + BONUS_POINTS;
    print_grade(summary_score);
    return EXIT_SUCCESS;
}
