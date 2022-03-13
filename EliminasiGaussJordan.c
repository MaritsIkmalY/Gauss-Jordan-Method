#include <stdio.h>
#include <stdlib.h>

int ordo;

void konversiAugmentedKeDiagonal(float matriks[][ordo + 1]);
void cetakNilaiVariabel(float matriks[][ordo + 1]);

int main()
{
    printf("Masukkan ordo matriks : ");
    scanf("%d", &ordo);
    printf("Matriks %d x %d\n", ordo, ordo);
    float matriks[ordo][ordo + 1];
    printf("Silahkan diisi matriksnya ! \n");
    for (int i = 0; i < ordo; i++)
    {
        for (int j = 0; j < ordo + 1; j++)
        {
            if (j == 0)
                printf("Matriks baris ke-%d\n", i + 1);
            printf("Matriks indeks[%d][%d] : ", i + 1, j + 1);
            scanf("%f", &matriks[i][j]);
        }
    }
    puts("Awal Mula Matriks");
    for (int i = 0; i < ordo; i++)
    {
        for (int j = 0; j < ordo + 1; j++)
        {
            printf("%.3f\t", matriks[i][j]);
            if (j == ordo - 1)
                printf("|\t");
        }
        puts("");
    }
    konversiAugmentedKeDiagonal(matriks);
    cetakNilaiVariabel(matriks);
}

void konversiAugmentedKeDiagonal(float matriks[][ordo + 1])
{
    float rasio;
    int perubahan = 0;
    float temp;

    puts("\nPengkonversian Menjadi Matriks Diagonal");
    for (int i = 0; i < ordo; i++)
    {
        for (int j = 0; j < ordo; j++)
        {
            if (j != i)
            {
                // Mengubah isi Matriks
                rasio = matriks[j][i] / matriks[i][i];
                perubahan++;
                for (int k = 0; k < ordo + 1; k++)
                {
                    matriks[j][k] -= rasio * matriks[i][k];
                }

                // Hasil Perubahan Matriks
                printf("Perubahan ke-%d\n", perubahan);
                for (int x = 0; x < ordo; x++)
                {
                    for (int y = 0; y < ordo + 1; y++)
                    {
                        printf("%.3f\t", matriks[x][y]);
                        if (y == ordo - 1)
                            printf("|\t");
                    }
                    puts("");
                }
                puts("");
            }
        }
    }
}

void cetakNilaiVariabel(float matriks[][ordo + 1])
{
    puts("Nilai Semua Variabel");
    for (int i = 0; i < ordo; i++)
    {
        printf("Nilai Variabel X%d : %g\n", i + 1, matriks[i][ordo] / matriks[i][i]);
    }
}