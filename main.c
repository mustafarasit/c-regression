#include <stdio.h>
#include <stdlib.h>

int main()
{
    int satir,i,j;
    float deger,xy,sonuc;
    float dizi[100][100];
    float x_toplam,x_kare,topla_carp;
    float y_toplam;

    printf("2 Sutunlu istediginiz kadar satirli regresyon hesaplama programi\n\n\n");
    printf("Kac satir olsun :");
    scanf("%d",&satir);


    if(satir >100){

        printf("Cok yuksek deger girildi, 100 den kuuk bir deger giriniz.");
        return 0;

    }


    //degerleri sýfýra eþitledik
     x_toplam =0;
     y_toplam =0;
     x_kare =0;
     topla_carp =0;

     //satir ve sutun için for yapýsý
    for(i=1; i<=2; i++){

        for(j=1; j<=satir; j++){

           printf("%d satirin %d degerini giriniz: ",i,j);
           scanf("%f",&deger);

           //degerleri diziye aktarýyorum
           dizi[i][j] = deger;

            //program basit olduðu için satýrlar arasý iþlemi böyle yaptým.
            //burda x , y kareyi ve toplamlarýný hesaplýyoruz.
           if(i==1){
            x_toplam+=deger;
            topla_carp = topla_carp +(deger*deger);
           }else if(i==2){
            y_toplam+=deger;
           }
        }
    }
    //x deðerlerinin toplamýnýn karelerini alýyoruz.
    x_kare = x_toplam*x_toplam;
    xy=0;

    //burada x*y yapýyoruz.
        for(i=1;i<=2;i++){

        for(j=1;j<=satir;j++){

        xy +=dizi[i][j]*dizi[i+1][j];
            }
        }

        float a,b;

        b=0;
        a=0;
        //b deðerini hesaplýyorum
        b = (xy - ((x_toplam * y_toplam)/satir)) / (topla_carp - ((x_toplam*x_toplam)/satir));

        //a deðerini hesaplýyorum
        a= (y_toplam/satir) - ((x_toplam/satir)*b);

        //sonuçlarý ekrana yazdýrýyorum.
        printf("b : %f", b);
        printf("a : %f", a);
        printf("Sonuc denklemi : y = %f + %f x",a,b);

    return 0;
}
