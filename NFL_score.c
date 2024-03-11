#include <stdio.h>

int main() {
    int input;

    printf("Enter 0 or 1 to STOP\n");
    printf("Enter the NFL score: ");
    scanf("%d", &input);
    printf("\nPossible combination of scoring plays:\n");

    for (int td_plusTwo = 0; td_plusTwo * 8 <= input; td_plusTwo++) {
        for (int td_plusOne = 0; td_plusOne * 7 <= input; td_plusOne++) {
            for (int td = 0; td * 6 <= input; td++) {
                for (int field_goal = 0; field_goal * 3 <= input; field_goal++) {
                    for (int safety_worth = 0; safety_worth * 2 <= input; safety_worth++) {
                        int total_score = td_plusTwo * 8 + td_plusOne * 7 + td * 6 + field_goal * 3 + safety_worth * 2;
                        if (total_score == input) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td_plusTwo, td_plusOne,td, field_goal, safety_worth);
                        }
                    }
                }
            }
        }
    }
}
