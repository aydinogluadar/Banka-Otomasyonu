#include<stdio.h> 
#include<string.h>

int giris(void)
{
	char sifre[10];
	char dogrusifre[]= "2456";
	int hak = 3;
	
	while(hak > 0)
{
	printf("- xBank sifrenizi giriniz ( %d hakkiniz kaldi ): ",hak);
	fgets(sifre, sizeof(sifre), stdin);
	sifre[strcspn(sifre,"\n")] = '\0';
	
	if (strcmp( sifre , dogrusifre )==0)
	{
		printf("- Basarili Giris.\n\n");
		return 1;
	}	

	else 
	{
		hak --;
		printf("- %d hakkiniz kaldi, tekrar deneyiniz.\n\n",hak);
		
		if (hak == 0)
		{
		printf("\n- Giris basarisiz , sistemden cikiliyor.");
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
float bakiye = 1000.0;
float miktar;

	while(1)
{
	printf("1-Para yatir \n2-Para cek \n3-Bakiye ogrenme \n4-Cikis yap \nYapmak istediginiz islemi secin: ");
	fgets (islem, sizeof(islem), stdin);
	
	if (strcmp(islem, "1\n") ==0 )
	{
		printf("\n- Yatiracaginiz miktari girin: ");
		scanf("%f",&miktar);
		bakiye += miktar;
		printf("\n- Islem sonu bakiyeniz: %.2f TL\n",bakiye);
		getchar();
	}
	else if (strcmp(islem, "2\n") ==0 )	
	{
	while(1)
{
		printf("\n- Cekeceginiz miktari girin: ");
		scanf("%f",&miktar);
		getchar();
	
	if(bakiye<miktar)
	{
		printf("\n\t-Yetersiz Bakiye.Mevcut bakiyeniz: %.2f TL\n", bakiye);
	}
	else 
	{
		bakiye -= miktar;
		printf("\n- Islem sonu bakiyeniz: %.2f TL\n",bakiye);
		break;
    }
}
	}
	else if (strcmp (islem,"3\n") ==0) 
	{
		printf ("\n- Bakiyeniz: %.2f TL\n",bakiye);
	}
	
	else if (strcmp (islem,"4\n") ==0)
	{
		printf("\n- Otomasyondan cikis yapildi , iyi gunler\n");
		break;
	}
	
	else 
	{
		printf("\nHatali giris!\n\nLutfen belirtilen seceneklerden birini giriniz.\n");
	}

	while(1)
{
	printf("\n- Baska bir islem yapmak istiyor musunuz? (E/h) : ");
	fgets(devam ,sizeof(devam), stdin);
	printf("\n");
	
	if (strcmp(devam, "H\n")==0 || strcmp(devam, "h\n")==0)
	{
		printf("\n- Otomasyondan cikis yapildi , iyi gunler.\n");
		return ;
	} 
	else if(strcmp(devam, "E\n")==0 || strcmp(devam, "e\n")==0 )
	{
		break;
	}
	else 
	{
		printf("- Lutfen Evet veya Hayir seceneklerini tuslayiniz.\n");	
	}
	printf("\n");
}
}
}

int main()
{
	if(giris())
	{
		secim ();
	}
	return 0;
}
