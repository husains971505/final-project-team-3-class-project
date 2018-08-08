// Jungle Temple
// Part B of Test 1
// By Reynold Guzman 6/28/18

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string pcName = "Player";
    cout << "Welcome to the Jungle Temple game!\n\n";
	cout << "Please enter your name: ";
	cin >> pcName;

	cout << "Hello " << pcName << ". Here are some things you should know\n";
	cout << "The object of this game is to retrieve the golden jaguar statue...\n";
	cout << "But, your progress will be scored as well, so try to get a high score.\n";
	cout << "You get points finding lost Mayan artifacts...\n";
	cout << "Good luck...\n\n\n";



	// outer game loop
	int playAgain = 1;

	while(playAgain)
    {
        int playerScore = 0;
        int playerPosition = 0;
        const int ROOMS = 7;
        const int ITEMS = 7;
        bool treasureLock1 = false;
        bool treasureLock2 = false;

        //Build new rooms for story...
        enum roomNames {FOYER,TREASURE,LIBRARY,GRANARY,MAPROOM,ALTAR,WEAPON};
        string itemNames [] = {"Rope","Jaguar Statue","Gold Key","Silver Key",
        "Ancient Book","Some Hay","Ancient Sword"};
        bool newRoom[ROOMS];
        bool newItem[ITEMS];
        for(int i1 = 0; i1 < ROOMS; ++i1)
        {
            newRoom[i1] = true;
        }
        for(int i2 = 0; i2 < ITEMS; ++i2)
        {
            newItem[i2] = true;
        }
        // Make the backpack
        vector<string> backpack;
        backpack.push_back("Flashlight");

        //Intro
        cout << "Amazon Jungle - 1920\n\n";
        cout << "You are the famous lone wolf Archaeologist " << pcName << endl;
        cout << "You have spent the past ten years in search of the famous lost Temple of Oro"
        << endl;
        cout << "But now, you have finally found it. So what will you do now?\n";
        cout << "1 - Go into the temple and explore its wondrous majesty\n";
        cout << "2 - Eh. I'm gonna leave\n";
        cout << "Choice: (1 or 2) ";
        int introChoice = 1;
        cin >> introChoice;
        //first game end...
        if (introChoice == 1)
            {
                playerScore += 5;
                cout << "\nBefore you step into the cavelike opening, you make sure to check you backpack\n";
                cout << "for your belongings.\n";
                cout << "What I have:\n";
                for (unsigned int i=0; i<backpack.size();i++)
                    cout << backpack[i] << endl;
                cout << "\nYou curse the robber who mugged you back in Rio as you grab your flashlight from\n";
                cout << "the backpack and proceed inside.\n";
                backpack.clear();
            }
        //inner game loop
        int playerChoice = 1;
        int throwAway = 2;
        int throwThis = 0;
        int tryDoor = 0;
        string tempKey;
        bool gameWin = false;
        while(true)
        {
            if (gameWin)
                break;

            if (introChoice == 2)
                {
                    playerScore = -1000000;
                    cout << "\nLike the coward you are, you decide to leave.\n";
                    cout << "After all the years of effort you spent searching for the temple\n";
                    cout << "you let fear throw all of that away. Your journey is at an end.\n";
                    break;
                }
            if (playerPosition == FOYER)
            {
                if(newRoom[FOYER] == true)
                {
                    playerScore += 100;
                    cout <<"\nYou walk through a narrow passageway for quite awhile, nervous\n";
                    cout <<"about where the tunnel will lead. You see a opening up ahead that\n";
                    cout <<"seems to gleam every time you shine your flashlight through it. \n";
                    cout <<"Once you reach the opening, you gasp in realization that the gleam \n";
                    cout <<"was caused by the room itself. It is covered from floor to ceiling \n";
                    cout <<"in gold leaf! From your experience, you know the room you stand in is the\n";
                    cout <<"temple foyer.\n";
                    newRoom[FOYER] = false;

                }
                //foyer loop
                while(true)
                {
                    cout <<"\nRoom - Temple Foyer\n";
                    cout << "1 - Explore room\n";
                    cout << "2 - Go to room on right\n";
                    cout << "3 - Go to room on left \n";
                    cout << "4 - Look at door at end of room\n";
                    cout << "5 - See Inventory\n";
                    cout << "6 - Leave temple (you give up...)";
                    cout << "Choice: ";
                    cin >> playerChoice;

                    if (playerChoice == 1)
                    {
                        cout << "\n Looking around the room you see several intricate carvings all over the\n";
                        cout << "room. Several depict warriors fighting, people worshiping a jaguar ,and\n";
                        cout << "people harvesting crops. Apart from the heavy door on the far side of \n ";
                        cout << "the room, the room is empty.\n";
                        if(newItem[FOYER] == true)
                        {
                            cout << "\n On closer inspection, however, you see something sticking out of the heavy amount of dust\n";
                            cout << "covering the floor of the room. It's a rope! You decide to put it into your backpack.\n";
                            if (backpack.size() >= 4)
                            {
                                cout << "\nYour backpack is full, throw something away!\n";
                            }
                            else
                            {
                                playerScore += 0;
                                backpack.push_back(itemNames[FOYER]);
                                newItem[FOYER] = false;
                            }

                        }
                        continue;
                    }
                    if (playerChoice == 2)
                    {
                        playerPosition = MAPROOM;
                        break;

                    }
                    if (playerChoice == 3)
                    {
                        playerPosition = GRANARY;
                        break;
                    }
                    if (playerChoice == 4)
                    {
                        cout << "\nThe golden door is carved with various iconography displaying jaguars.\n";
                        cout << "Based on your knowledge of Mayan temples, you surmise the door is protecting\n";
                        cout << "the Golden Jaguar! But the door seems locked. There are two keyholes in the door.\n";
                        cout << "Use an item?\n";
                        cout << "\n1 - Yes\n";
                        cout << "2 - No\n";
                        cout << "Choice: ";
                        cin >> tryDoor;
                        if (tryDoor == 1)
                        {
                            cout << "\nWhat I have:\n";
                            for (int i=0; i<backpack.size();i++)
                                cout << i << " - " << backpack[i] << endl;
                            cout << "\nWhich item do you want to try to open the door with? (number only)\n";
                            cout << "Item: \n";
                            cin >> tryDoor;
                            if (backpack[tryDoor] == "Gold Key" || backpack[tryDoor] == "Silver Key" )
                            {
                                tempKey = backpack[tryDoor];
                                cout << "That worked! The door mechanism clanked and is now silent. It's missing something...";
                                backpack.erase(backpack.begin()+tryDoor);
                                cout << "\nWhat I have:\n";
                                for (int i=0; i<backpack.size();i++)
                                    cout << i << " - " << backpack[i] << endl;
                                cout << "\nWhich item do you want to try to open the door with? (number only)\n";
                                cout << "Item: \n";
                                cin >> tryDoor;
                                if (backpack[tryDoor] == "Gold Key" || backpack[tryDoor] == "Silver Key" )
                                {
                                    playerScore += 10000;
                                    cout << "The door rumbles, causing the whole temple to shake... the door opens!\n";
                                    cout << "The statue is yours. You win!!!";
                                    gameWin = true;
                                    break;
                                }
                                else
                                {
                                    cout << "\n That didn't work... Try something else.\n";
                                    cout << "The door resets itself after you try to open the door.\n";
                                    cout << "\n You put the first key back in your backpack.";
                                    backpack.push_back(tempKey);

                                }

                            }
                            else
                            {
                                cout << "\n That didn't work... Try something else.\n";
                            }

                        }

                    }
                    if (playerChoice == 5)
                    {
                        cout << "\nWhat I have:\n";
                        for (int i=0; i<backpack.size();i++)
                            cout << i << " - " << backpack[i] << endl;
                        cout << "\nDo you want throw something away?\n";
                        cout << "Warning: Items thrown away are lost forever...\n";
                        cout << "\n1 - Yes\n";
                        cout << "2 - No\n";
                        cout << "Choice: ";
                        cin >> throwAway;
                        if (throwAway == 1)
                        {
                            cout << "\nWhich one? (number only, 5 = cancel)\n";
                            cin >> throwThis;
                            if (throwThis == 5)
                                continue;
                            cout << "Item: " << backpack[throwThis] << " thrown away!\n";
                            backpack.erase(backpack.begin()+throwThis);



                        }
                        continue;

                    }
                    if (playerChoice == 6)
                    {
                        gameWin = true;
                        cout << "\nFor whatever reason, you decide to give up and walk away with what you have gathered.\n";
                        cout << "Your journey is at an end...\n";
                        break;
                    }

                }
                }
                if(playerPosition == MAPROOM)
                {
                    if(newRoom[MAPROOM] == true)
                    {
                        playerScore += 100;
                        cout <<"\nYou enter a large room, with tables and shelves piled with bark sheets.\n";
                        cout <<"You grab a sheet but it starts to disintegrate in your hand. Before it \n";
                        cout <<"collapsed completely, you realize it is a map. This room is filled with \n";
                        cout <<"to the brim with maps. You decide to call it the map room. Unfortunately, you \n";
                        cout <<"realize that you will need to leave the maps alone since they will probably \n";
                        cout <<"disintegrate like the other ones. \n";
                        newRoom[MAPROOM] = false;

                    }
                    while (true)
                    {
                        cout <<"\nRoom - Map Room\n";
                        cout << "1 - Explore room\n";
                        cout << "2 - Go back to previous room\n";
                        cout << "3 - Go to room on right\n";
                        cout << "4 - Go to room on left \n";
                        cout << "5 - See Inventory\n";
                        cout << "Choice: ";
                        cin >> playerChoice;

                        if (playerChoice == 1)
                        {
                            cout << "\n Looking around the room you see decaying maps and items of related to map\n";
                            cout << "making. These themselves would be fairly valuable and of interest to museums,\n";
                            cout << "however, they are extremely delicate, so it would be best to leave them be until  \n ";
                            cout << "another expedition can bring tools to scavenge the maps.\n";
                            if(newItem[MAPROOM] == true)
                            {
                                cout << "\n Passing by a table, you notice a remarkably preserved book. You gently pick it up \n";
                                cout << "and decide that it should be hardy enough to keep. You decide to put it in your backpack.\n";
                                if (backpack.size() >= 4)
                                {
                                    cout << "\nYour backpack is full, throw something away!\n";
                                }
                                else
                                {
                                    playerScore += 100;
                                    backpack.push_back(itemNames[MAPROOM]);
                                    newItem[MAPROOM] = false;
                                }

                            }
                            continue;
                        }
                        if (playerChoice == 2)
                        {
                            playerPosition = FOYER;
                            break;

                        }
                        if (playerChoice == 3)
                        {
                            playerPosition = ALTAR;
                            break;

                        }
                        if (playerChoice == 4)
                        {
                            playerPosition = LIBRARY;
                            break;

                        }
                        if (playerChoice == 5)
                        {
                            cout << "\nWhat I have:\n";
                            for (int i=0; i<backpack.size();i++)
                                cout << i << " - " << backpack[i] << endl;
                            cout << "\nDo you want throw something away?\n";
                            cout << "Warning: Items thrown away are lost forever...\n";
                            cout << "\n1 - Yes\n";
                            cout << "2 - No\n";
                            cout << "Choice: ";
                            cin >> throwAway;
                            if (throwAway == 1)
                            {
                                cout << "\nWhich one? (number only, 5 = cancel)\n";
                                cin >> throwThis;
                                if (throwThis == 5)
                                    continue;
                                cout << "Item: " << backpack[throwThis] << " thrown away!\n";
                                backpack.erase(backpack.begin()+throwThis);



                            }
                            continue;

                        }

                    }

                }
                if(playerPosition == ALTAR)
                {
                    if(newRoom[ALTAR] == true)
                    {
                        playerScore += 100;
                        cout <<"\nYou arrive a finely decorated room, with wall covered in gold leaf \n";
                        cout <<"and shards of colored glass. There is raised platform in the middle of the room \n";
                        cout <<"that you recognize as an altar. You know this was an altar room, made for worship. \n";
                        newRoom[ALTAR] = false;

                    }
                    while (true)
                    {
                        cout <<"\nRoom - Altar Room\n";
                        cout << "1 - Explore room\n";
                        cout << "2 - Go back to previous room\n";
                        cout << "3 - See Inventory\n";
                        cout << "Choice: ";
                        cin >> playerChoice;

                        if (playerChoice == 1)
                        {
                            cout << "\n Looking around the room you see various carving similar to the foyer.\n";
                            cout << "Taking a closer look at the alter, you see various pieces of wood and hay,\n";
                            cout << "probably used for effigy or symbols of religious worship.\n ";
                            if(newItem[ALTAR] == true)
                            {
                                cout << "\nDespite knowing the hay on the altar is more than likely ordinary, you cant help but want \n";
                                cout << "to take it with you. Perhaps it hold some sort of hay-related secret? \n";
                                if (backpack.size() >= 4)
                                {
                                    cout << "\nYour backpack is full, throw something away!\n";
                                }
                                else
                                {
                                    playerScore += 0;
                                    backpack.push_back(itemNames[ALTAR]);
                                    newItem[ALTAR] = false;
                                }

                            }
                            continue;
                        }
                        if (playerChoice == 2)
                        {
                            playerPosition = MAPROOM;
                            break;

                        }
                        if (playerChoice == 3)
                        {
                            cout << "\nWhat I have:\n";
                            for (int i=0; i<backpack.size();i++)
                                cout << i << " - " << backpack[i] << endl;
                            cout << "\nDo you want throw something away?\n";
                            cout << "Warning: Items thrown away are lost forever...\n";
                            cout << "\n1 - Yes\n";
                            cout << "2 - No\n";
                            cout << "Choice: ";
                            cin >> throwAway;
                            if (throwAway == 1)
                            {
                                cout << "\nWhich one? (number only, 5 = cancel)\n";
                                cin >> throwThis;
                                if (throwThis == 5)
                                    continue;
                                cout << "Item: " << backpack[throwThis] << " thrown away!\n";
                                backpack.erase(backpack.begin()+throwThis);



                            }
                            continue;

                        }

                    }

                }
                if(playerPosition == LIBRARY)
                {
                    if(newRoom[LIBRARY] == true)
                    {
                        playerScore += 100;
                        cout <<"\nYou arrive a fairly simple room, with bookshelves filled to the brim with bark paper books.\n";
                        cout <<"This is the first time you've seen a library in a Mayan temple and you are utterly fascinated \n";
                        cout <<"by the implications. Like the map room, you decide to leave the books be until another expedition.\n";
                        newRoom[LIBRARY] = false;

                    }
                    while (true)
                    {
                        cout <<"\nRoom - Library\n";
                        cout << "1 - Explore room\n";
                        cout << "2 - Go back to previous room\n";
                        cout << "3 - See Inventory\n";
                        cout << "Choice: ";
                        cin >> playerChoice;

                        if (playerChoice == 1)
                        {
                            cout << "\n The books themselves in fairly good condition but oddly the shelves seem to \n";
                            cout << "be falling apart. You take great effort to avoid touching any shelves.\n";
                            if(newItem[LIBRARY] == true)
                            {
                                cout << "\nOn one shelf, you see something glimmering. It's a gold key! You slowly \n";
                                cout << "grab the key, careful of not making sudden movements. But at last you are \n";
                                cout << "successful. You know have a key that can be used to open the treasure door! \n";
                                if (backpack.size() >= 4)
                                {
                                    cout << "\nYour backpack is full, throw something away!\n";
                                }
                                else
                                {
                                    playerScore += 1000;
                                    backpack.push_back(itemNames[LIBRARY]);
                                    newItem[LIBRARY] = false;
                                }

                            }
                            continue;
                        }
                        if (playerChoice == 2)
                        {
                            playerPosition = MAPROOM;
                            break;

                        }
                        if (playerChoice == 3)
                        {
                            cout << "\nWhat I have:\n";
                            for (int i=0; i<backpack.size();i++)
                                cout << i << " - " << backpack[i] << endl;
                            cout << "\nDo you want throw something away?\n";
                            cout << "Warning: Items thrown away are lost forever...\n";
                            cout << "\n1 - Yes\n";
                            cout << "2 - No\n";
                            cout << "Choice: ";
                            cin >> throwAway;
                            if (throwAway == 1)
                            {
                                cout << "\nWhich one? (number only, 5 = cancel)\n";
                                cin >> throwThis;
                                if (throwThis == 5)
                                    continue;
                                cout << "Item: " << backpack[throwThis] << " thrown away!\n";
                                backpack.erase(backpack.begin()+throwThis);



                            }
                            continue;

                        }

                    }

                }
                if(playerPosition == GRANARY)
                {
                    if(newRoom[GRANARY] == true)
                    {
                        playerScore += 100;
                        cout <<"\nYou arrive at a simple room, filled with pots and baskets of mummified grains You have stumbled on.\n";
                        cout <<"a granary or a storehouse for food. Other than some colorful pottery, there doesn't seem to be much of \n";
                        cout <<"interest in this room.\n";
                        newRoom[GRANARY] = false;

                    }
                    while (true)
                    {
                        cout <<"\nRoom - Temple Granary\n";
                        cout << "1 - Explore room\n";
                        cout << "2 - Go back to previous room\n";
                        cout << "3 - Go to Room straight ahead\n";
                        cout << "4 - See Inventory\n";
                        cout << "Choice: ";
                        cin >> playerChoice;

                        if (playerChoice == 1)
                        {
                            cout << "\n The pottery are fairly colorful for their age, depicting patterns similar to pots uncovered \n";
                            cout << "at Mayan dig sites. \n";
                            if(newItem[GRANARY] == true)
                            {
                                cout << "\nBefore you stop exploring, you see something glimmer as you move your flashlight. \n";
                                cout << "A silver key inside an empty pot! You quickly grab the key and place it into your  \n";
                                cout << "backpack. You now have a key that can be used to open the treasure door! \n";
                                if (backpack.size() >= 4)
                                {
                                    cout << "\nYour backpack is full, throw something away!\n";
                                }
                                else
                                {
                                    playerScore += 1000;
                                    backpack.push_back(itemNames[GRANARY]);
                                    newItem[GRANARY] = false;
                                }

                            }
                            continue;
                        }
                        if (playerChoice == 2)
                        {
                            playerPosition = FOYER;
                            break;

                        }
                        if (playerChoice == 3)
                        {
                            playerPosition = WEAPON;
                            break;

                        }
                        if (playerChoice == 4)
                        {
                            cout << "\nWhat I have:\n";
                            for (int i=0; i<backpack.size();i++)
                                cout << i << " - " << backpack[i] << endl;
                            cout << "\nDo you want throw something away?\n";
                            cout << "Warning: Items thrown away are lost forever...\n";
                            cout << "\n1 - Yes\n";
                            cout << "2 - No\n";
                            cout << "Choice: ";
                            cin >> throwAway;
                            if (throwAway == 1)
                            {
                                cout << "\nWhich one? (number only, 5 = cancel)\n";
                                cin >> throwThis;
                                if (throwThis == 5)
                                    continue;
                                cout << "Item: " << backpack[throwThis] << " thrown away!\n";
                                backpack.erase(backpack.begin()+throwThis);



                            }
                            continue;

                        }

                    }

                }
                if(playerPosition == WEAPON)
                {
                    if(newRoom[WEAPON] == true)
                    {
                        playerScore += 100;
                        cout <<"\nYou stumble into small room filled a racks of weapons. You've found an ancient armory of sorts. \n";
                        cout <<"It is bit unusual for a temple to have an armory but you know this temple is very special so you \n";
                        cout <<"just decide to roll with it. The racks are filled with various weapons but nothing else stands out.\n";
                        newRoom[WEAPON] = false;

                    }
                    while (true)
                    {
                        cout <<"\nRoom - Armory\n";
                        cout << "1 - Explore room\n";
                        cout << "2 - Go back to previous room\n";
                        cout << "3 - See Inventory\n";
                        cout << "Choice: ";
                        cin >> playerChoice;

                        if (playerChoice == 1)
                        {
                            cout << "\n The weapons seem in excellent condition, just covered in layers of dust and ancient  \n";
                            cout << "cobwebs.  \n";
                            if(newItem[WEAPON] == true)
                            {
                                cout << "\nYou decide to keep looking for anything interesting, among the otherwise normal spears \n";
                                cout << "and bow and arrows. You gasp in amazement at what seems to be an ancient sword! You've never \n";
                                cout << "heard or seen such a thing. It was crude but it is indeed something wondrous to discover!  \n";
                                if (backpack.size() >= 4)
                                {
                                    cout << "\nYour backpack is full, throw something away!\n";
                                }
                                else
                                {
                                    playerScore += 200;
                                    backpack.push_back(itemNames[WEAPON]);
                                    newItem[WEAPON] = false;
                                }

                            }
                            continue;
                        }
                        if (playerChoice == 2)
                        {
                            playerPosition = GRANARY;
                            break;

                        }
                        if (playerChoice == 3)
                        {
                            cout << "\nWhat I have:\n";
                            for (int i=0; i<backpack.size();i++)
                                cout << i << " - " << backpack[i] << endl;
                            cout << "\nDo you want throw something away?\n";
                            cout << "Warning: Items thrown away are lost forever...\n";
                            cout << "\n1 - Yes\n";
                            cout << "2 - No\n";
                            cout << "Choice: ";
                            cin >> throwAway;
                            if (throwAway == 1)
                            {
                                cout << "\nWhich one? (number only, 5 = cancel)\n";
                                cin >> throwThis;
                                if (throwThis == 5)
                                    continue;
                                cout << "Item: " << backpack[throwThis] << " thrown away!\n";
                                backpack.erase(backpack.begin()+throwThis);



                            }
                            continue;

                        }

                    }

                }


            }
            cout << "\n\nYour final score: " << playerScore << endl;
            cout << "\n\nPlay again? (Yes - 1 or No - 0) ";
            cin >> playAgain;


        }
        cout << "Thanks for playing! Come by again sometime...";
        cout  << "\n\n\t ... " << "\n\n\n\t\tPress a character and Enter to exit program. ";
        char holdscr;
        cin >> holdscr;

        return 0;



    }


