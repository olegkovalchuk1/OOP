#ifndef AVERAGE_H
#define AVERAGE_H


template <typename T>
double calculateAverage(const T array[], int size) {
    if (size <= 0) {
        return 0.0;
    }

    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += static_cast<double>(array[i]);
    }

    return sum / size;
}

#endif 