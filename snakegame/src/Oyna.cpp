#include "Oyna.hpp"

const int genislik = 20 , yukseklik = 20 ;
int indexakonumyatay = genislik/2 , indexakonumdikey = yukseklik/2 , asayac = 0 , yilanboyutu = 1
, turbekle = 0 , haritadaelmasayisi=0 , elmax=0 , elmay=0 , cakisma=0 , elmaskor=0 , oyunhizi , otorestart = 0 ,
gamespeed = 1;
bool baslangic = 1, oyundevam = 1 , blokkoyuldu = 0;
char sontus = 'w';
int yilanxkonum[genislik] = {};
int yilanykonum[yukseklik] = {};

void Oyna(char* input )
{
basla:
while(oyundevam){ ++asayac;
srand(time(nullptr));
oyunhizi = (gamespeed*110000)-((elmaskor+1)*5000);
            if (haritadaelmasayisi==0)
            {
                ++elmaskor;
                ++haritadaelmasayisi ;
                elmax = 1+(rand() % (genislik-1)); 
                elmay = 1+(rand() % (yukseklik-1));
                for (size_t i = 0; i < yilanboyutu; i++)
                {
                    if (elmax == yilanxkonum[i]&&elmay==yilanykonum[i])
                    {
                        elmax = 1+(rand() % (genislik-1)); 
                        elmay = 1+(rand() % (yukseklik-1));
                    } 
                }                
            }
            if (elmax == indexakonumyatay && elmay==indexakonumdikey)
            {
                --haritadaelmasayisi;
                elmax = 0;
                elmay = 0;
                ++yilanboyutu;
            }
            if (asayac >= yilanboyutu)
            asayac = 0 ;
            
                yilanxkonum[asayac] = indexakonumyatay;
                yilanykonum[asayac] = indexakonumdikey;

            for (size_t k = 0; k < yilanboyutu; k++)
            {
                for (size_t j = 0; j < yilanboyutu; j++)
                {
                    if(yilanxkonum[j] == yilanxkonum[k] && yilanykonum[j] == yilanykonum[k])
                    ++cakisma;
                    if ( cakisma >= (yilanboyutu+1) )
                    {
                    oyundevam = 0;
                    }
                }   
            }
            cakisma = 0 ;

for (size_t yuksekligi = 1; yuksekligi < yukseklik; yuksekligi++)
    {
    std::cout << "\n" ; 
    for (size_t genisligi = 1; genisligi < genislik; genisligi++)
        {
                for (size_t i = 0; i < yilanboyutu; i++)
                {
                if (genisligi == yilanxkonum[i] && yuksekligi == yilanykonum[i] && blokkoyuldu == 0)
                    {
                        std::cout << "▓▓" ;
                        blokkoyuldu = 1 ;
                    }
                    else if (genisligi==elmax && yuksekligi == elmay && blokkoyuldu == 0)
                    {
                        std::cout << "▒▒" ;
                        blokkoyuldu = 1 ;
                    }
                    else if (i == yilanboyutu-1 && blokkoyuldu == 0)
                    {
                        std::cout << "░░" ; 
                    }
                }
                blokkoyuldu = 0 ;
        }
    }
switch (*input)
                        {
                        case 'w':
                            if(sontus=='s'){++indexakonumdikey;}else{
                            --indexakonumdikey;sontus = 'w';}
                            break;
                        case 's':
                            if(sontus=='w'){--indexakonumdikey;}else{
                            ++indexakonumdikey;sontus = 's';}
                            break;
                        case 'a':
                            if(sontus=='d'){++indexakonumyatay;}else{
                            sontus = 'a';--indexakonumyatay;}
                            break;
                        case 'd':
                            if(sontus=='a'){--indexakonumyatay;}else{
                            sontus = 'd';++indexakonumyatay;}
                            break;
                        default:
                            *input = sontus ;
                            break;
                        }
if (indexakonumyatay<=0||indexakonumyatay>=genislik||indexakonumdikey<=0||indexakonumdikey>=yukseklik)
    oyundevam = 0;
std::cout << "\n" << "- Oyun Başladı , Toplam skor : "<< elmaskor*100 <<" -"<< "\n";
usleep(oyunhizi);
system("clear");}//WHİLE
for (size_t yuksekligi = 1; yuksekligi < yukseklik; yuksekligi++)
    {
    std::cout << "\n" ; 
    for (size_t genisligi = 1; genisligi < genislik; genisligi++)
        {
                        std::cout << "▒▒" ; 
        }
    }
    std::cout << "\n" << "- Toplam skor " << elmaskor*100 <<" -"<< "\n";
    std::cout << "\n" << "- cikmak icin 'q' ya basın -"<< "\n";
        while (!oyundevam)
    {
        if (otorestart)
        {
        otorestart =0;
        indexakonumyatay = genislik/2 , indexakonumdikey = yukseklik/2 , asayac = 0 , yilanboyutu = 1
        , turbekle = 0 , haritadaelmasayisi=0 , elmax=0 , elmay=0 , cakisma=0 , elmaskor=0 , oyunhizi ,
        gamespeed = 1;
        baslangic = 1, oyundevam = 1 , blokkoyuldu = 0;
        sontus = 'w';
        for (size_t i = 0; i < genislik; i++)
        {
            yilanxkonum[i] = {};
        }
        for (size_t i = 0; i < genislik; i++)
        {
            yilanykonum[i] = {};
        }
            system("clear");
            goto basla ;
        }
        else
        {
            for (int i = 3; i >= 0; --i) {
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout<<"\n - oto restart "<< i <<" saniye içinde olcak -";
                otorestart=1;
             }
        }
        usleep(100000);
    }
}
