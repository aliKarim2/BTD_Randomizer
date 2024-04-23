#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <sstream>


class Tower{
    std::string name;
    bool popsAll;   //if tower can pop all types of balloons 
    bool hype;  //if tower is fun to use    

public:
    Tower(std::string xName, bool xPopsAll, bool xHype): 
    name(xName), popsAll(xPopsAll), hype(xHype){
        
        
    }


    std::string getName(){return name;}
    bool getPopsAll(){return popsAll;}
    bool getHype(){return hype;}

};


int main(){
    const int FW = 20;

    std::vector<Tower> towerList;

    std::ifstream inFile;
    const std::string FILE_NAME = "towers.txt";


    //open file
    inFile.open(FILE_NAME);


    //if it isnt opening, shut program down
    if(!inFile.is_open()){
        std::cout << "Error opening file.";
        return 0;
    }



    std::string line;

    while(std::getline(inFile, line)){//while inFile is getting a sampleName

        std::istringstream iss(line);
        std::string name;
        bool popsAll;
        bool hype;

        std::getline(iss, name, ',');
        

        //if its the first line (headers)
        if(name == "name")
            continue;

        iss >> popsAll;
        iss >> hype;

        std::cout << name << ' ' << popsAll << ' ' << hype << '\n';
        std::cin.get();

        Tower sampleTower(name, popsAll, hype);

    }
            




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