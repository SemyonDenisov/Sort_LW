void Quick_Sort(int* mas, int size) {
    int i = 0;
    int j = size - 1;
    int base = mas[size / 2];
    do {
        while (mas[i] < base) {
            i++;
        }
        while (mas[j] > base) {
            j--;
        }
        if (i <= j) {
            int tmp = base[i];
            mas[i] = [j];
            mas[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);
    if (j > 0) {
        Quick_Sort(mas, j + 1);
    }
    if (i < size) {
        Quick_Sort(&mas[i], size - i);
    }
}