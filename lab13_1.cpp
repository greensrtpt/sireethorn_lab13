#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}
void stat(const double data[], int size, double results[]) {
    double sum = 0.0, sumSq = 0.0, product = 1.0, harmonicSum = 0.0;
    double maxVal = numeric_limits<double>::min();
    double minVal = numeric_limits<double>::max();

    for (int i = 0; i < size; i++) {
        double value = data[i];
        sum += value;
        sumSq += value * value;
        product *= value;
        harmonicSum += 1.0 / value;
        if (value > maxVal) maxVal = value;
        if (value < minVal) minVal = value;
    }

    double mean = sum / size;
    results[0] = mean;
    results[1] = sqrt(sumSq / size - mean * mean);
    results[2] = pow(product, 1.0 / size);
    results[3] = size / harmonicSum;
    results[4] = maxVal;
    results[5] = minVal;
}