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


    std::string getName() const{return name;}


};


int getRandomInt(int start, int end); //random generating system
void fixDuplicates(Tower towers[], std::vector<Tower> hypeList, std::vector<Tower> allList); 


bool operator==(const Tower& t1, const Tower& t2){
    return (t1.getName() == t2.getName());
}

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


    std::string input;
    bool removeWaters = false;
    std::cout << "Enter 1 to remove water towers or press any other key to continue...\n";
    std::cin >> input;

    removeWaters = (input == "1" ? true : false);


    std::cout << (removeWaters ? "Water Towers Disabled!\n" : "Water Towers Enabled!\n");


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


            //keep water towers out of the list if not water map
            if(removeWaters){
                if(name == "Buccaneer" || name == "Submarine"){
                    continue;
                }
            }


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
    
    
        
    const int TOWER_CT = towerList.size()-1;
    const int POPS_ALL_CT = popsAllTowerList.size() -1;
    const int HYPE_CT = hypeTowerList.size() -1;

   

//ASSIGN INITIAL TOWERS
{
        /*PLAYER LOADOUT FORMATTING
            FIRST ELEMENT:      popsAll
            SECOND ELEMENT:     hype
            THIRD ELEMENT:      any tower
        */        

        int index;
    
    //Tower 1
        index = getRandomInt(0, POPS_ALL_CT); //get random number

        p1Towers[0] = popsAllTowerList[index]; //assign a tower from a random index

        index = getRandomInt(0, POPS_ALL_CT);

        p2Towers[0] = popsAllTowerList[index];
        
    //Tower 2
        index = getRandomInt(0, HYPE_CT);

        p1Towers[1] = hypeTowerList[index];

        index = getRandomInt(0, HYPE_CT);

        p2Towers[1] = hypeTowerList[index];

    //Tower 3
        index = getRandomInt(0, TOWER_CT);

        p1Towers[2] = towerList[index];

        index = getRandomInt(0, TOWER_CT);

        p2Towers[2] = towerList[index];
}


//CHECK FOR DUPLICATE TOWER

    fixDuplicates(p1Towers, hypeTowerList, towerList);
    fixDuplicates(p2Towers, hypeTowerList, towerList);
    

//OUTPUT DATA
    {
        std::cout << std::left;
        std::cout << "\n\n";

        std::cout << std::setw(50) << std::setfill('-') << "" << std::endl;    //line barrier
        std::cout<< std::setfill(' ') << std::setw(0)  << "";    //line barrier end

        //output all of player 1's towers
        std::cout << "PLAYER 1:\n";
        std::cout << "Tower 1: " << std::right << std::setw(FW) << p1Towers[0].getName();
        std::cout << std::setw(FW) << "(POPS ALL)" << '\n';
        std::cout << "Tower 2: " << std::right << std::setw(FW) << p1Towers[1].getName();
        std::cout << std::setw(FW) << "(HYPE)" << '\n';
        std::cout << "Tower 3: " << std::right << std::setw(FW) << p1Towers[2].getName() << '\n';

        std::cout << std::setw(50) << std::setfill('-') << "" << std::endl;    //line barrier
        std::cout<< std::setfill(' ') << std::setw(0)  << "";    //line barrier end

        //output all of player 2's towers
        std::cout << "PLAYER 2:\n";
        std::cout << "Tower 1: " << std::right << std::setw(FW) << p2Towers[0].getName();
        std::cout << std::setw(FW) << "(POPS ALL)" << '\n';
        std::cout << "Tower 2: " << std::right << std::setw(FW) << p2Towers[1].getName();
        std::cout << std::setw(FW) << "(HYPE)" << '\n';
        std::cout << "Tower 3: " << std::right << std::setw(FW) << p2Towers[2].getName()<< '\n';





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

void fixDuplicates(Tower towers[], std::vector<Tower> hypeList, std::vector<Tower> allList){


    /*REROLL PRIORITY
    if there is a duplicate, the tower to get rerolled is the one with lowest priority

    1. popsAll (index 0)
    2. hype (index 1)
    3. all towers (index 2)


    For example:
    If 0 and 1 match, reroll 2
    If 1 and 2 match, reroll 3
    If 0 and 2 match, reroll 2
    (basically rerolling the greater number index out of the two)

    (note that we do not pass in the popsAll vector bc index 0 will never be rerolled)

    */
    do{

        //check if the allTower needs to be redone
        if(towers[2] == towers[1] || towers[2] == towers[0]){

            int index = getRandomInt(0, allList.size()-1);

            towers[2] = allList[index];

            //check the condition again
            continue;

        }
        if(towers[0] == towers[1]){

            //reroll the tower
            int index = getRandomInt(0, hypeList.size()-1);

            towers[1] = hypeList[index];

            //check the condition again
            continue;
        }
        
    //  std::cout << "DUPE FOUND, change tower 2\n";


    }while(false);
}
