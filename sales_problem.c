#include <stdio.h>

void monthly_sales_report(float num_array[]);
void sales_summary(float num_array[]);
void six_month_moving_average_report(float num_array[]);
void salesReport_high_to_low(float num_array[]);

int main() {
    float num_array[12] = {23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 60200.22, 72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22};

    monthly_sales_report(num_array);
    sales_summary(num_array);
    six_month_moving_average_report(num_array);
    salesReport_high_to_low(num_array);

    return 0;
}

void monthly_sales_report(float num_array[]) {
    char report_title[] = "Monthly sales report for 2022:\n\nMonth\t  Sales\n\n";
    char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    char *printReady_report[12];

    printf("%s", report_title);

    for (int i = 0; i < 12; i++) {
        printf("%-10s$%.2f\n", months[i], num_array[i]);
    }

    printf("\n");
}

void sales_summary(float num_array[]) {
    char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    double min = num_array[0];
    char *min_month = months[0];
    double max = num_array[0];
    char *max_month = months[0];
    double avg = 0;

    for (int i = 0; i < 12; i++) {
        if (num_array[i] < min) {
            min = num_array[i];
            min_month = months[i];
        }

        if (num_array[i] > max) {
            max = num_array[i];
            max_month = months[i];
        }

        avg = avg + num_array[i];
    }

    avg = avg/12;

    printf("Sales summary:\n\nMinimum sales:\t$%.2f\t(%s)\n", min, min_month);
    printf("Maximum sales:\t$%.2f\t(%s)", max, max_month);
    printf("\nAverage sales:\t$%.2f", avg);
}

void six_month_moving_average_report(float num_array[]) {
    char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    printf("\n\nSix-Month Moving Average Report:\n\n");

    for (int i = 0; i < 7; i++) {
        double avg = 0;
        char *startMonth = months[i];
        char *endMonth = months[i + 5];

        for (int j = i; j < i + 6; j++) {
            avg = avg + num_array[j];
        }
        avg = avg/6;

        if (i == 0) {
            printf("%s\t\t- %s\t\t$%.2f\n", startMonth, endMonth, avg);
        } else if (i == 1) {
            printf("%s\t- %s\t\t$%.2f\n", startMonth, endMonth, avg);
        } else {
            printf("%s\t\t- %s\t$%.2f\n", startMonth, endMonth, avg);
        }
    }
}

void salesReport_high_to_low(float num_array[]) {
    char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    printf("\nSales Report (Highest to Lowest):\n\n Month\t\t  Sales\n\n");
    double ordered_num_array[12];
    char *ordered_month_array[12];
    int cur_hi;

    for (int i = 0; i < 12; i++) {
        int cur_hi = i;
        for (int j = i + 1; j < 12; j++) {
            if (num_array[j] > num_array[cur_hi]) {
                cur_hi = j;
            }
        }
        double temp = num_array[i];
        num_array[i] = num_array[cur_hi];
        num_array[cur_hi] = temp;

        char *temp_month = months[i];
        months[i] = months[cur_hi];
        months[cur_hi] = temp_month;
    }

    for (int i = 0; i < 12; i++) {
        ordered_num_array[i] = num_array[i];
        ordered_month_array[i] = months[i];
    }

    for (int i = 0; i < 12; i++) {
        if (i == 2 || i == 3 || i == 5 || i == 6 || i == 7 || i == 9 || i == 10 || i == 11) {
            printf("%s\t\t%.2f\n", ordered_month_array[i], ordered_num_array[i]);
        } else {
            printf("%s\t%.2f\n", ordered_month_array[i], ordered_num_array[i]);
        }
    }
}