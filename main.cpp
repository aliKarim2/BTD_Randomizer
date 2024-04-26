#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <random>
#include <algorithm>

class Tower{
    std::string name;
    bool popsAll;   //if tower can pop all types of balloons 
    bool hype;  //if tower is fun to use    

public:
    Tower(std::string xName, bool xPopsAll, bool xHype): 
    name(xName), popsAll(xPopsAll), hype(xHype){
        
        
    }
    Tower() = default;


    std::string getName(){return name;}
    bool getPopsAll(){return popsAll;}
    bool getHype(){return hype;}

};


int getRandomInt(int start, int end);
int getRandomInt(int start, int end, std::vector<int>& used);


int main(){
    const int FW = 20;

    std::vector<Tower> towerList;               //list of all towers
    std::vector<Tower> popsAllTowerList;        //list of popsAll towers
    std::vector<Tower> hypeTowerList;           //list of hype towers


    //player inventories
    Tower p1Towers[3];
    Tower p2Towers[3];


    //data file variables
    std::ifstream inFile;
    const std::string FILE_NAME = "towers.txt";


    //open file
    inFile.open(FILE_NAME);


    //if it isnt opening, shut program down
    if(!inFile.is_open()){
        std::cout << "Error opening file.";
        return 0;
    }



    //Read data into towerList vector
    {
        std::string line;
        while(std::getline(inFile, line)){//while inFile is getting a sampleName

            std::istringstream iss(line);
            std::string name;
            bool popsAll;
            bool hype;

            std::getline(iss, name, ',');
            

            //if its the first line (headers)
            if(name == "Name") 
                continue;//we dont want it in our lists

            iss >> popsAll;
            iss >> hype;


            Tower sampleTower(name, popsAll, hype);



            //Add towers to their belonging lists
            if(popsAll)
                popsAllTowerList.push_back(sampleTower);
            if(hype)
                hypeTowerList.push_back(sampleTower);

            //towerList is the general list that gets all towers
            towerList.push_back(sampleTower);

        }
    }
    
    
        
    const int PLAYER_LOADOUT_SIZE = 3;
    const int TOWER_CT = towerList.size()-1;

    std::vector<int> p1UsedIndexes;
    std::vector<int> p2UsedIndexes;

        /*PLAYER LOADOUT FORMATTING
        FIRST ELEMENT:      popsAll
        SECOND ELEMENT:     hype
        THIRD ELEMENT:      any tower
        */        


    for(int i = 0; i < PLAYER_LOADOUT_SIZE; i++){

        int p1Index = getRandomInt(0, TOWER_CT, p1UsedIndexes); //get a new, random tower that is not in p1's loadout (avoid dupes)

         p1Towers[i] = towerList[p1Index]; //add that tower to p1's loadout
        // std::cout << "Adding " << towerList[p1Index].getName() << '\n';


        p1UsedIndexes.push_back(p1Index); //now that we used p1Index, we need to update the "used" towers


        //do the exact same thing for player 2
        int p2Index = getRandomInt(0, TOWER_CT), p2UsedIndexes;

        p2Towers[i] = towerList[p2Index]; //add that tower to p1's loadout

        p1UsedIndexes.push_back(p2Index); //now that we used p1Index, we need to update the "used" towers
    }


    // std::cin.get();
    // return 0;


    //Output Data
    {
        std::cout << std::left;
        std::cout << "\n\n";

        //output all of player 1's towers
        std::cout << "PLAYER 1:\n";
        std::cout << "Tower 1: " << std::right << std::setw(FW) << p1Towers[0].getName() << '\n';
        std::cout << "Tower 2: " << std::right << std::setw(FW) << p1Towers[1].getName() << '\n';
        std::cout << "Tower 3: " << std::right << std::setw(FW) << p1Towers[2].getName() << '\n';

        std::cout << std::setw(50) << std::setfill('-') << "" << std::endl;    //line barrier
        std::cout<< std::setfill(' ') << std::setw(0)  << "";    //line barrier end

        //output all of player 2's towers
        std::cout << "PLAYER 2:\n";
        std::cout << "Tower 1: " << std::right << std::setw(FW) << p2Towers[0].getName() << '\n';
        std::cout << "Tower 2: " << std::right << std::setw(FW) << p2Towers[1].getName() << '\n';
        std::cout << "Tower 3: " << std::right << std::setw(FW) << p2Towers[2].getName() << '\n';





        std::cout << std::setw(50) << std::setfill('-') << "" << std::endl;    //line barrier
        std::cout<< std::setfill(' ') << std::setw(0)  << "";    //line barrier end

    }
    


    std::cout << "Program Terminated";
  return 0;
}

int getRandomInt(int start, int end){
            // Set up a random number generator
            static std::random_device rd;  // Use hardware entropy if available

            std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()

            // Define a distribution (for example, integers between 1 and 100)
            std::uniform_int_distribution<> distribution(start, end);

            // Generate and print a random number
            return distribution(gen);
        }
int getRandomInt(int start, int end, std::vector<int>& used){
            int num;
            // Set up a random number generator
            static std::random_device rd;  // Use hardware entropy if available

            std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()

            // Generate and print a random number

            // Define a distribution (for example, integers between 1 and 100)
                std::uniform_int_distribution<> distribution(start, end);
            if(!used.empty()){
                do{
                    num = distribution(gen); //make new number

                    //find returns used.end() if num is nowhere to be seen in the vector
                    if(std::find(used.begin(), used.end(), num) == used.end()){ //checks if num is already in used
                        //we found good number
                        break;
                    }

                }while(true);
            }
            else{
                num = distribution(gen);
            }
            




            return num;
        }