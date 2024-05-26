#include <stdio.h>
#include <string.h>

typedef struct Mahasiswa {
    char nrp[10];
    char nama[50];
    int kelas;
} Mahasiswa;

void inputMahasiswa(Mahasiswa *m) {
    printf("Masukkan NRP: ");
    scanf("%9s", m->nrp);

    printf("Masukkan nama: ");
    scanf(" %49[^\n]", m->nama);

    printf("Masukkan kelas: ");
    scanf("%d", &m->kelas);
}

void bubbleSortNRP(Mahasiswa data[], int n) {
    int i, j;
    int swapped;

    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(data[j].nrp, data[j + 1].nrp) > 0) {
                Mahasiswa temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

void bubbleSortNRPFlag(Mahasiswa data[], int n) {
    int i, j;
    int swapped;

    do {
        swapped = 0;
        for (i = 0; i < n - 1; i++) {
            if (strcmp(data[i].nrp, data[i + 1].nrp) > 0) {
                Mahasiswa temp = data[i];
                data[i] = data[i + 1];
                data[i + 1] = temp;
                swapped = 1;
            }
        }
        n--;
    } while (swapped);
}

void shellSortNRP(Mahasiswa data[], int n) {
    int gap, i, j;

    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            Mahasiswa current = data[i];
            j = i;
            while (j >= gap && strcmp(data[j - gap].nrp, current.nrp) > 0) {
                data[j] = data[j - gap];
                j -= gap;
            }
            data[j] = current;
        }
    }
}

void printMahasiswa(Mahasiswa m) {
    printf("NRP: %s, Nama: %s, Kelas: %d\n", m.nrp, m.nama, m.kelas);
}

void printAllMahasiswa(Mahasiswa data[], int n) {
    for (int i = 0; i < n; i++) {
        printMahasiswa(data[i]);
    }
}

int soal4() {
    int n;

    printf("Masukkan jumlah data mahasiswa: ");
    scanf("%d", &n);

    Mahasiswa data[n];
    Mahasiswa data_copy[n];

    for (int i = 0; i < n; i++) {
        printf("\nData mahasiswa ke-%d\n", i + 1);
        inputMahasiswa(&data[i]);
    }

    printf("\nData sebelum diurutkan:\n");
    printAllMahasiswa(data, n);

    memcpy(data_copy, data, sizeof(data));
    bubbleSortNRP(data_copy, n);
    printf("\nSetelah pengurutan (Bubble Sort):\n");
    printAllMahasiswa(data_copy, n);

    memcpy(data_copy, data, sizeof(data));
    bubbleSortNRPFlag(data_copy, n);
    printf("\nSetelah pengurutan (Bubble Sort dengan Flag):\n");
    printAllMahasiswa(data_copy, n);

    memcpy(data_copy, data, sizeof(data));
    shellSortNRP(data_copy, n);
    printf("\nSetelah pengurutan (Shell Sort):\n");
    printAllMahasiswa(data_copy, n);

    return 0;
}
