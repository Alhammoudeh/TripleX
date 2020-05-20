#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    //Print welcome messages to the terminal
    std::cout << "\n\nYou have been captured and need to escape room "<< Difficulty;
    std::cout << "! \nYou will need to enter the correct code to continue towards the next room...\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    // Declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //print CodeSum and CodeProduct to the terminal
    std::cout << "- There are 3 numbers in the code";
    std::cout << "\n- The codes add up to: " << CodeSum;
    std::cout << "\n- The codes multiply to give: "<<CodeProduct;

    std::cout << "\n\nEnter your three values: ";

    //Store Player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //Check if players guess is correct
    if(GuessSum == CodeSum && GuessProduct == CodeProduct){
        std::cout << "\nCongratulations! Please move on to the next room.";
        return true;
    }
    else{
        std::cout << "\nThat is incorrect. Please try again!";
        return false;
    }

}

int main()
{
    srand(time(NULL)); // create new random sequence based on time of day

    int LevelDifficulty = 1;
    const int MaxDifficulty = 8;

    while(LevelDifficulty <= MaxDifficulty) // Loop game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //Clears any errors
        std::cin.ignore(); //Discards the buffer

        if(bLevelComplete)
        {
            //increase level difficulty
            ++LevelDifficulty;
        }
        
    }
    
    std::cout << "Congratulations! You have escaped all rooms.";
    return 0;
}