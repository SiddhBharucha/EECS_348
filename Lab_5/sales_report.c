#include <stdio.h>
#include <stdlib.h>

const char *months[12] = {
    "Jan", "Feb", "Mar", "Apr",
    "May", "Jun", "Jul", "Aug",
    "Sep", "Oct", "Nov", "Dec"
};

/**
 * The function `readData` reads float data from a file and returns a pointer to an array containing
 * the data.
 * 
 * @param filename The filename parameter is a string that represents the name of the file from which
 * the data will be read.
 * 
 * @return a pointer to a float array.
 */
float *readData(const char *filename) {
    const int months = 12;
    float *data = (float*)malloc(sizeof(float) * months);

    FILE *fp = fopen(filename, "r+");
    if(fp == NULL){
        printf("Please check your file again!\n");
    }

    for (int i = 0; i < months; i++) {
        fscanf(fp, "%f", &data[i]);
    }

    return data;
}

/**
 * The function "printMonthlySales" prints the monthly sales values stored in an array.
 * 
 * @param sales The parameter "sales" is a pointer to a float array. It is expected to contain the
 * monthly sales data for a year, with each element representing the sales for a specific month.
 */
void printMonthlySales(float *sales) {
    for (int i = 0; i < 12; i++) {
        printf("%s : $%.2f\n", months[i], sales[i]);
    }
}

/**
 * The function `printMinMaxAverage` calculates and prints the minimum, maximum, and average values of
 * an array of sales data.
 * 
 * @param sales The parameter `sales` is a pointer to an array of floats. It represents the monthly
 * sales data for a year, with each element of the array representing the sales for a specific month.
 */
void printMinMaxAverage(float *sales) {
    float sum = 0;
    float avg = 0;
    int minMonth = 0;
    int maxMonth = 0;

    float min = sales[0];
    float max = sales[0];

    for (int i = 0; i < 12; i++) {
        if (sales[i] < min) {
            minMonth = i;
            min = sales[i];
        }

        if (sales[i] > max) {
            maxMonth = i;
            max = sales[i];
        }

        sum += sales[i];
    }

    avg = sum / 12;

    printf("Min: $%.2f (%s)\n", min, months[minMonth]);
    printf("Max: $%.2f (%s)\n", max, months[maxMonth]);
    printf("Avg: $%.2f\n", avg);
}

/**
 * The function calculates and prints the six-month moving average of sales data.
 * 
 * @param sales The "sales" parameter is a pointer to an array of floats, representing the sales data
 * for each month.
 */
void printSixMonthMovingAverage(float *sales) {
    float movingAvg[7];

    for (int i = 0; i <= 6; i++) {
        float sum = 0;

        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }

        movingAvg[i] = sum / 6;
    }

    for (int i = 0; i <= 6; i++) {
        printf("%s - %s : $%.2f\n", months[i], months[i + 5], movingAvg[i]);
    }
}

/**
 * The function "printSortedData" takes an array of sales data and sorts it in descending order, then
 * prints the sorted data along with the corresponding month names.
 * 
 * @param sales The parameter `sales` is a pointer to an array of floats. It represents the sales data
 * for each month of the year.
 */
void printSortedData(float *sales) {
    int indices[12];

    for (int i = 0; i < 12; i++) {
        indices[i] = i;
    }

    for (int i = 0; i < 12; i++) {
        for (int j = i + 1; j < 12; j++) {
            if (sales[indices[i]] < sales[indices[j]]) {
                float temp = indices[i];
                indices[i] = indices[j];
                indices[j] = temp;
            }
        }
    }

    for (int i = 0; i < 12; i++) {
        printf("%s : $%.2f\n", months[indices[i]], sales[indices[i]]);
    }
}

/**
 * The main function reads sales data from a file, prints a monthly sales report, calculates and prints
 * the minimum, maximum, and average sales, calculates and prints the six-month rolling average, and
 * prints the sales data in descending order.
 * 
 * @return The main function is returning an integer value of 0.
 */
int main() {
    float *sales = readData("sales.txt");

    printf("--------------------\n");
    printf("Monthly Sales Report\n");
    printf("--------------------\n");
    printMonthlySales(sales);

    printf("--------------------\n");
    printf("Min, Max, Avg. Sales\n");
    printf("--------------------\n");
    printMinMaxAverage(sales);

    printf("--------------------\n");
    printf("6-Month Rolling Avg.\n");
    printf("--------------------\n");
    printSixMonthMovingAverage(sales);

    printf("--------------------\n");
    printf("Sales Report (Desc.)\n");
    printf("--------------------\n");
    printSortedData(sales);

    printf("--------------------\n");
    return 0;
}