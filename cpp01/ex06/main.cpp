#include "Harl.hpp"

int main(int ac, char **av)
{
   if(ac != 2)
   {
      std::cout << "Usage of the Programme : ./HarlFilter your command (DEBUG,INFO,WARNING,ERRO)" << std::endl;
      return (1);
   }
   Harl obj;
   std::string level = av[1];
   obj.complain(level);
   return 0;
}