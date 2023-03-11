#include "Oyna.hpp"


const int genislik = 60 , yukseklik = 20 ;
int indexakonumyatay = 30 , indexakonumdikey = 10 , asayac = 1 ;
bool keyboardw = 0 , keyboarda = 0 , keyboards = 0 , keyboardd = 0 , oyundevam = 1 ;



void Oyna(char* input )
{
while(oyundevam){ ++asayac;
system("clear");



for (size_t yuksekligi = 0; yuksekligi < yukseklik; yuksekligi++)
    {
    std::cout << "\n" ; 

    for (size_t genisligi = 0; genisligi < genislik; genisligi++)
        {
            if (genisligi == indexakonumyatay && yuksekligi == indexakonumdikey)
            {
                std::cout << "▓" ;
                std::cout.flush();
            }
            else        
                std::cout << "░" ;
        }
    }



switch (*input)
                        {
                        case 'w':
                            keyboardw = 1  ;
                            --indexakonumdikey;
                            break;
                        case 's':
                            keyboarda = 1 ;
                            ++indexakonumdikey;
                            break;
                        case 'a':
                            keyboards = 1 ;
                            --indexakonumyatay;
                            break;
                        case 'd':
                            keyboardd = 1 ;
                            ++indexakonumyatay;
                            break;
                        default:
                            break;
                        }

if (indexakonumyatay<=0||indexakonumyatay>=genislik||indexakonumdikey<=0||indexakonumdikey>=yukseklik)
    oyundevam = 0;

std::cout << "\n" << "son harf girdisi : "<< *input << "\n";
std::cout << "\n" << "konum X : "<< indexakonumyatay << "\n";
std::cout << "\n" << "konum Y : "<< indexakonumdikey << "\n";
std::cout << "\n" << "Toplam Donguler : "<< asayac << "\n";
usleep(60000);
}//WHİLE


std::cout << "---------------------------- OYUN BITTI ----------------------------"<<std::endl ;
}