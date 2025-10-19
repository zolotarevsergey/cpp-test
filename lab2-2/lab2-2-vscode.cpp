#include <iostream>
#include <iomanip> // for setw, setprecision
#include <cmath>   // for pow, log, fabs
using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;
using std::setw;

int main()
{
    double A, B, step;
    int N;

    cout << "Enter A:" << endl;
    cin >> A;
    cout << "Enter B:" << endl;
    cin >> B;
    cout << "Enter step:" << endl;
    cin >> step;
    cout << "Enter number of iterations N:" << endl;
    cin >> N;

    cout << "\n   x\t\tTailorSeries\t\tln(x)\t\tDifference" << endl;
    cout << "---------------------------------------------------------------\n";

    for (double x = A; x <= B; x += step)
    {
        if (x <= 0)
            continue;

        double q = (x - 1) / (x + 1);
        double sum = 0.0;

        for (int k = 0; k < N; k++)
        {
            sum += pow(q, 2 * k + 1) / (2 * k + 1);
        }

        sum *= 2.0;

        double exact = log(x);
        double diff = fabs(sum - exact);

        cout << fixed
             << setw(8) << setprecision(4) << x << '\t'
             << setprecision(10)
             << setw(15) << sum << '\t'
             << setw(15) << exact << '\t'
             << setw(15) << diff << '\n';
    }

    return 0;
}
