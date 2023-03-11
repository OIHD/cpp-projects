#include "Oyna.hpp"


const int genislik = 20 , yukseklik = 20 ;
int indexakonumyatay = genislik/2 , indexakonumdikey = yukseklik/2 , asayac = 0 , yilanboyutu = 1
, turbekle = 0 , haritadaelmasayisi=0 , elmax=0 , elmay=0 , 
gamespeed = 1;
bool baslangic = 1, oyundevam = 1 , blokkoyuldu = 0;

int yilanxkonum[genislik] = {};
int yilanykonum[yukseklik] = {};


void Oyna(char* input )
{
while(oyundevam){ ++asayac;
srand(time(nullptr)); // Başlangıç değerini zamanla belirler
            if (haritadaelmasayisi==0)
            {
                ++haritadaelmasayisi ;
                elmax = rand() % genislik; 
                elmay = rand() % yukseklik;
            }
            if (elmax == indexakonumyatay && elmay==indexakonumdikey)
            {
                --haritadaelmasayisi;
                elmax = 1;
                elmay = 1;
                ++yilanboyutu;
            }
            
            
            
            if (asayac >= yilanboyutu)
            asayac = 0 ;
            
                yilanxkonum[asayac] = indexakonumyatay;
                yilanykonum[asayac] = indexakonumdikey;

            for (size_t i = 0; i < yilanboyutu; i++)
            {
                if (yilanxkonum[i] == indexakonumyatay && yilanykonum[i] == indexakonumdikey)
                {
                    //oyundevam = 0;
                }
                
            }

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
                            --indexakonumdikey;
                            break;
                        case 's':
                            ++indexakonumdikey;
                            break;
                        case 'a':
                            --indexakonumyatay;
                            break;
                        case 'd':
                            ++indexakonumyatay;
                            break;
                        default:
                            break;
                        }

if (indexakonumyatay<=0||indexakonumyatay>=genislik||indexakonumdikey<=0||indexakonumdikey>=yukseklik)
    oyundevam = 0;
std::cout << "\n" << "son harf girdisi : "<< *input << "\n";
std::cout << "\n" << "konum X : "<< indexakonumyatay << " konum Y : "<< indexakonumdikey ;
std::cout << "\n" << "Toplam Donguler : "<< asayac << "\n";
std::cout <<  "1x :"<< yilanxkonum[1] << " 1y :" << yilanykonum[1] ;
std::cout <<  " |2x :"<< yilanxkonum[2] << " 2y: " << yilanykonum[2] ;
std::cout <<  " |3x :"<< yilanxkonum[3] << " 3y: " << yilanykonum[3] << "\n";
usleep(gamespeed*90000);
system("clear");}//WHİLE


std::cout << "---------------------------- OYUN BITTI ----------------------------"<<std::endl ;
}