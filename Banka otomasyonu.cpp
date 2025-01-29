#include <stdio.h>
#include <string.h>

int giris(void)
{
    char sifre[10];
    char dogru_sifre[] = "2456";
    int hak = 3;

    while (hak > 0)
    {
        printf("- xBank sifrenizi giriniz ( %d hakkiniz kaldi ): ", hak);
        fgets(sifre, sizeof(sifre), stdin);
        sifre[strcspn(sifre, "\n")] = '\0';

        if (strcmp(sifre, dogru_sifre) == 0)
        {
            printf("- Basarili giris!\n\n");
            return 1;
        }
        else
        {
            hak--;
            printf("- %d hakkiniz kaldi, tekrar deneyiniz.\n\n", hak);

            if (hak == 0)
            {
                printf("\n- Giris basarisiz, sistemden cikiliyor.\n");
                return 0;
            }
        }
    }
    return 0;
}

void secim(void)
{
    char islem[20];
    char devam[10];
    float bakiye = 1000;
    int tutar, orjinal_tutar;
    int ikiyuz ,yuz, elli, yirmi, on;

    while (1)
    {
        printf("\n1-Para yatir \n2-Para cek \n3-Bakiye ogrenme \n4-Cikis yap \nYapmak istediginiz islemi secin: ");
        fgets(islem, sizeof(islem), stdin);

        if (strcmp(islem, "1\n") == 0)
        {
            float miktar;
            printf("\n- Yatiracaginiz miktari girin: ");

            if (scanf("%f", &miktar) != 1) 
            {
                printf("- Hata! Lutfen sadece sayi giriniz.\n");
                while (getchar() != '\n'); 
                continue;
            }
            getchar(); 

            bakiye += miktar;
            printf("\n- Islem sonu bakiyeniz: %.2f TL\n", bakiye);
        }
        else if (strcmp(islem, "2\n") == 0)
        {
            while (1)
            {
                printf("\n- Cekmek istediginiz tutari girin (10 ve katlari): ");

                if (scanf("%d", &tutar) != 1)
                {
                    printf("- Hata! Lutfen sadece sayi giriniz.\n");
                    while (getchar() != '\n'); 
                    continue;
                }

                getchar(); 

                if (tutar % 10 != 0)
                {
                    printf("- Hata! Lutfen 10'un katlarini giriniz.\n");
                    continue;
                }

                if (bakiye < tutar)
                {
                    printf("\n- Yetersiz bakiye! Mevcut bakiyeniz: %.2f TL\n", bakiye);
                    continue;
                }

                orjinal_tutar = tutar;
                ikiyuz = yuz = elli = yirmi = on = 0;

                while (tutar > 0)
                {
                    if (tutar >= 200) { tutar -= 200; ikiyuz++; }
                    else if (tutar >= 100) { tutar -= 100; yuz++; }
                    else if (tutar >= 50) { tutar -= 50; elli++; }
                    else if (tutar >= 20) { tutar -= 20; yirmi++; }
                    else if (tutar >= 10) { tutar -= 10; on++; }
                }

                bakiye -= orjinal_tutar;
                printf("\n\n%d adet 200 TL\n%d adet 100 TL\n%d adet 50 TL\n%d adet 20 TL\n%d adet 10 TL\n", ikiyuz, yuz, elli, yirmi, on);
                printf("\n- Islem sonu bakiyeniz: %.2f TL\n", bakiye);
                break;
            }
        }
        else if (strcmp(islem, "3\n") == 0)
        {
            printf("\n- Bakiyeniz: %.2f TL\n", bakiye);
        }
        else if (strcmp(islem, "4\n") == 0)
        {
            printf("\n- Otomasyondan cikis yapildi, iyi gunler!\n");
            break;
        }
        else
        {
            printf("\nHatali giris!\n\nLutfen belirtilen seceneklerden birini giriniz.\n");
        }

        while (1)
        {
            printf("\n- Baska bir islem yapmak istiyor musunuz? (E/h) : ");
            fgets(devam, sizeof(devam), stdin);

            if (strcmp(devam, "H\n") == 0 || strcmp(devam, "h\n") == 0)
            {
                printf("\n- Otomasyondan cikis yapildi, iyi gunler!\n");
                return;
            }
            else if (strcmp(devam, "E\n") == 0 || strcmp(devam, "e\n") == 0)
            {
                break;
            }
            else
            {
                printf("- Lutfen 'E/e' veya 'H/h' tuslayiniz.\n");
            }
        }
    }
}

int main()
{
    if (giris())
    {
        secim();
    }
    return 0;
}