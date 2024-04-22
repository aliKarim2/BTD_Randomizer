#include <iostream>

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







    std::cout << "Program Terminated";
  return 0;
}