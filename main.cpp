#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

class Tower{
    std::string name;
    bool metal;
    bool camo;

public:
    Tower(std::string xName, bool xMetal, bool xCamo): 
    name(xName), metal(xMetal), camo(xCamo){
        
        
    }


    std::string getName(){return name;}
    bool getMetal(){return metal;}
    bool getCamo(){return camo;}


};


int main(){
    const int FW = 20;


    
    std::cout << std::left;
    std::cout << "\n\n";

    //output all of player 1's towers
    std::cout << "PLAYER 1:\n";
    std::cout << "Tower 1: " << std::right << std::setw(FW) << "XXXXX" << '\n';
    std::cout << "Tower 2: " << std::right << std::setw(FW) << "YYYYY" << '\n';
    std::cout << "Tower 3: " << std::right << std::setw(FW) << "ZZZZZ" << '\n';

    std::cout << std::setw(50) << std::setfill('-') << "" << std::endl;    //line barrier
    std::cout<< std::setfill(' ') << std::setw(0)  << "";    //line barrier end

    //output all of player 2's towers
    std::cout << "PLAYER 2:\n";
    std::cout << "Tower 1: " << std::right << std::setw(FW) << "XXXXX" << '\n';
    std::cout << "Tower 2: " << std::right << std::setw(FW) << "YYYYY" << '\n';
    std::cout << "Tower 3: " << std::right << std::setw(FW) << "ZZZZZ" << '\n';





    std::cout << std::setw(50) << std::setfill('-') << "" << std::endl;    //line barrier
    std::cout<< std::setfill(' ') << std::setw(0)  << "";    //line barrier end



    std::cout << "Program Terminated";
  return 0;
}