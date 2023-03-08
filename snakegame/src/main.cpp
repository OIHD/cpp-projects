#include <iostream>
#include <thread>
#include <unistd.h>
#include <cstdlib> 
#include <string.h>

#include <sys/select.h>
#include <termios.h>
#include <fcntl.h>
//-----MAIN----------
int main (int argc , char**argv)
{
const int genislik = 60 , yukseklik = 20 ;
int indexakonumyatay = 30 , indexakonumdikey = 10 , asayac = 1 ;
bool keyboardw = 0 , keyboarda = 0 , keyboards = 0 , keyboardd = 0 , oyundevam = 1 ;
char sondugme = 's' ;
//------------------------------------------------


  




while(oyundevam){

for (size_t yuksekligi = 0; yuksekligi < yukseklik; yuksekligi++)
    {
    std::cout << "\n" ; 

    for (size_t genisligi = 0; genisligi < genislik; genisligi++)
        {
            if (genisligi == indexakonumyatay && indexakonumdikey == yuksekligi)
            {





                    //-----------------------------------------
                    /*
                        switch (input)
                        {
                        case "w":
                            keyboardw = 1  ;
                            ++indexakonumdikey ;
                        case "a":
                            keyboarda = 1 ;
                            --indexakonumyatay;
                        case "s":
                            keyboards = 1 ;
                            --indexakonumdikey;
                        case "d":
                            keyboardd = 1 ;
                            ++indexakonumyatay;

                            break;
                        
                        default:
                            break;
                        }



                    */
                    //-----------------------------------------


                std::cout << "▓" ;
                std::cout.flush();
            }
            else        
                std::cout << "░" ;
        }
    }

if (indexakonumyatay<=0||indexakonumyatay>=genislik||indexakonumdikey<=0||indexakonumdikey>=yukseklik)
    oyundevam = 0;

usleep(100000);
std::cout << "\033[2J\033[1;1H"; // Ekrandaki içeriği temizler
}//WHİLE






std::cout << "--------------------------------------------------------------------"<<std::endl ;
std::cout << "---------------------------- OYUN BITTI ----------------------------"<<std::endl ;
std::cout << "--------------------------------------------------------------------"<<std::endl ;
//input_thread.join();
return 0 ;
}