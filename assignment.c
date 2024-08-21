#include <stdio.h>
#include <stdlib.h>

#define MAX_DATA_POINTS 1000

void find_peaks(double data[], int size, int maxima[], int *max_count, int minima[], int *min_count) {
    *max_count = 0;
    *min_count = 0;
    
    for (int i = 1; i < size - 1; i++) {
        if (data[i] > data[i-1] && data[i] > data[i+1]) {
            maxima[*max_count] = i;
            (*max_count)++;
        } else if (data[i] < data[i-1] && data[i] < data[i+1]) {
            minima[*min_count] = i;
            (*min_count)++;
        }
    }
}

int main() {
    double data[MAX_DATA_POINTS];
    int maxima[MAX_DATA_POINTS], minima[MAX_DATA_POINTS];
    int max_count, min_count;
    int i = 0;
    FILE *file = fopen("Data_1.txt", "r");
    
    if (!file) {
        printf("Error opening file.\n");
        return 1;
    }
    
    while (fscanf(file, "%lf", &data[i]) != EOF && i < MAX_DATA_POINTS) {
        i++;
    }
    fclose(file);
    
    find_peaks(data, i, maxima, &max_count, minima, &min_count);
    
    printf("Maxima indices: ");
    for (int j = 0; j < max_count; j++) {
        printf("%d ", maxima[j]);
    }
    printf("\nMinima indices: ");
    for (int j = 0; j < min_count; j++) {
        printf("%d ", minima[j]);
    }
    printf("\n");

    return 0;
}
