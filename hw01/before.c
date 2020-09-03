// vim: fileencoding=utf8 expandtab tabstop=4 shiftwidth=4
#include <stdio.h>
#include <stdlib.h>
const int NUM_HOMEWORK=15
const float HOMEWORK_SCORES[]={100,100,100,100,70,80,100,80,100,100,80,100,70,80,100};
const float HOMEWORK_WEIGHTS[]={1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0};
const int NUM_EXAMS=3;
const float EXAM_SCORES[]={80,95,85,85};
const float EXAM_WEIGHTS[]={0.25,0.25,0.25,0.25};
const float BONUS_POINTS=3.0;
const float PARTICIPATION_POINTS=2.0;
float average(const float values[], const int num_values) {
float sum = 0.0;
int i=0;
for(; i < num_values; i++)
sum += values[i];
return sum / num_values;
}
float weighted_sum(const float values[], const float weights[], const int num_values) {
float sum = 0.0;
int i = 0;
for(; i < num_values; i++)
sum += values[i] * weights[i];
return sum;
}
float weighted_average(const float values[], const float weights[], const int num_values) {
return weighted_sum(values, weights, num_values) / num_values;
}
int main(int argc, char *argv[]) {
float exam_score = weighted_sum(EXAM_SCORES,EXAM_WEIGHTS,NUM_EXAMS);
float hw_score = weighted_average(HOMEWORK_SCORES,HOMEWORK_WEIGHTS,NUM_HOMEWORK);
float summary_score=exam_score*0.5+hw_score*0.5+PARTICIPATION_POINTS*0.10+BONUS_POINTS*1.0;
printf("summary_score == %.2f\n", summary_score);
print_grade(summary_score);
return EXIT_SUCCESS;
}
