#include <stdio.h>
#include <math.h>

int main() {
    double A, B, step;
    int N;

    printf("Enter A: ");
    scanf_s("%lf", &A);
    printf("Enter B: ");
    scanf_s("%lf", &B);
    printf("Enter step: ");
    scanf_s("%lf", &step);
    printf("Enter number of iterations N: ");
    scanf_s("%d", &N);

    printf("\n   x\t\tTailorSeries\t\tln(x)\t\tDifference\n");
    printf("---------------------------------------------------------------\n");

    for (double x = A; x <= B; x += step) {
        if (x <= 0) continue;

        double q = (x - 1) / (x + 1);
        double sum = 0.0;

        for (int k = 0; k < N; k++) {
            sum += pow(q, 2 * k + 1) / (2 * k + 1);
        }

        sum *= 2.0;

        double exact = log(x);
        double diff = fabs(sum - exact);

        printf("%8.4f\t%15.10f\t%15.10f\t%15.10f\n", x, sum, exact, diff);
    }

    return 0;
}
