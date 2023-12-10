#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

	printf("takvimi yazdirilacak yili secin: ");
	int yil;
	scanf("%i",&yil);

	//girilen yilin ilk haftasindaki artik yillari hesaplar. Mesela 2 sonucu bulunduysa ocak ayi carsambadan baslamali
	int artikgun =  ((yil-1) / 4 - (yil-1)/100 + (yil-1)/400 + 365*(yil-1))% 7;

	int gun,ay,bosluksayaci,sayac,satir;

	//sirayla 12 ayin bilgisini alir
	for (ay = 1;ay <=12;ay++){
		switch(ay){
			case 1:
				printf("     Ocak %i\n",yil);
				gun = 31;
				break;
			case 2:
				printf("     Subat %i\n",yil);
				if (yil % 4 == 0){
					if (yil % 100 == 0){
						if (yil % 400 == 0){
							gun = 29;
						}
						else{
							gun = 28;
						}
					}
					else{
						gun = 29;
					}
				}
				else{
					gun = 28;
				}
				break;
			case 3:
				printf("     Mart %i\n",yil);
				gun = 31;
				break;
			case 4:
				printf("     Nisan %i\n",yil);
				gun = 30;
				break;
			case 5:
				printf("     Mayis %i\n",yil);
				gun = 31;
				break;
			case 6:
				printf("     Haziran %i\n",yil);
				gun = 30;
				break;
			case 7:
				printf("     Temmuz %i\n",yil);
				gun = 31;
				break;
			case 8:
				printf("     Agustos %i\n",yil);
				gun = 31;
				break;
			case 9:
				printf("     Eylul %i\n",yil);
				gun = 30;
				break;
			case 10:
				printf("     Ekim %i\n",yil);
				gun = 31;
				break;
			case 11:
				printf("     Kasim %i\n",yil);
				gun = 30;
				break;
			case 12:
				printf("     Aralik %i\n",yil);
				gun = 31;
				break;
		}
		printf("Pt Sa Ca Pe Cu Ct Pa\n");

		//elimizdeki artik gun kadar bosluk birakir
		for (bosluksayaci = artikgun,satir = 1;bosluksayaci>0;bosluksayaci--,satir++){
			printf("   ");
		}
		for (sayac = 1;sayac<=gun;sayac++,satir++){
			if(sayac < 10){
				printf("%i  ",sayac);
			}
			else if(sayac >= 10){
				printf("%i ",sayac);
			}
			// her 7 karakterde \n atar bosluklarda karakter sayilir
			if (satir % 7 == 0){
				printf("\n");
			}
		}
		printf("\n\n\n");

		//sonraki ayin artik gununu hesaplar
		artikgun = (artikgun + gun) % 7;
	}
	return 0;
}
