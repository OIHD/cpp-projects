#include "Oyna.hpp"

char girdi = 'w' ;
char a = 'w';
void fonksiyon1 () {
    char girdi;
    struct termios oldSettings, newSettings;
    tcgetattr(STDIN_FILENO, &oldSettings); // terminal ayarlarını al
    newSettings = oldSettings;
    newSettings.c_lflag &= ~(ICANON | ECHO); // terminal ayarlarını değiştir
    tcsetattr(STDIN_FILENO, TCSANOW, &newSettings); 
    bool whileboole = true ;
    while (whileboole)
    {
        girdi = getchar();
        a = girdi ;
        if (a == 'q')
        {
            whileboole = false ;
        }   
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &oldSettings); 
}
void fonksiyon2 ()  {Oyna(&a);}
int main (int argc , char**argv)
{
    std::thread t1(fonksiyon1) ; 
    std::thread t2(fonksiyon2) ;
    t1.join() ;
    t2.detach() ;
    return 0 ;
}