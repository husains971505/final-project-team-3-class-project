// Text based adventure game
// COSC 1337
// Team 3 Project 

#include <iostream>
#include <string>

// Change list
// Change #1  - Changed function system("clc") due to OS specific command, changed to
// clearOutWin()
// Change #2 -  variable(s) not used, commented out
// Change #3 - Adding game loop functionality
// Change #4 - Added play again function


using namespace std;

void clearOutWin();
int askPlayAgain();

int main()
{
	const int MAX_ITEMS = 15;

	string player;
	//string gender;

	//char again = 'y';
	cout << "Enter your name: " << endl;
	cin >> player;

	// Gender not used
	//cout << "Enter your gender: " << endl;
	//cin >> gender;

	int playAgain = 1; // Adding game loop functionality

	while(playAgain)
	{
        string inventory[MAX_ITEMS];
        int numItems = 0;
        inventory[numItems++] = "flashlight";
        inventory[numItems++] = "pistol";
        inventory[numItems++] = "medical supplies";

        int choice1 = 1;
        int choice2 = 2;
        int choice3 = 3;
        int decision2;

        int decision3;
        int decisionE1;
        int decisionE2;

        while(true) // inner game loop
            {

                cout << "THIS GAME IS HARD AND YOU WILL DIE A LOT. GOOD LUCK!!!" << endl;


                cout << "Hello " << player << " you are lost on a space ship and an Alien lifeform is hunting you!" << endl;
                cout << "You must make the correct choices in order to escape!" << endl;

                cout << "You wake up dazed and confused, you slowly stand up and look around. Something is wrong, the power is off and the emergency alarm is on." << endl;
                cout << "You grab your backpack." << endl;
                cout << "You grab a flashlight, a gun, and medical supplies. " << endl;

                cout << "You check your inventory." << endl;

                cout << "Your inventory is:\n";
                for (int i = 0; i < numItems; ++i)
                {
                    cout << inventory[i] << endl;
                }




                cout << "You approach the door, you look left and then right. Which way do you want to go?" << endl;

                cout << "1. Go left." << endl;
                cout << "2. Go right." << endl;



                cin >> choice1;
                cin.ignore();
                clearOutWin();




                if (choice1 == 1)
                {
                    int decision1;
                    cout << "You head left." << endl;
                    cout << "You take out your flashlight and begin looking for any signs of survival. You see none. Everyone is missing...." << endl;
                    cout << "You approach an elevator." << endl;
                    cout << "The doors open ..." << endl;
                    cout << "In the middle of the elevator floor is a keycard ... You pick it up." << endl;


                    if (numItems < MAX_ITEMS)
                    {
                        inventory[numItems++] = "Keycard";
                    }
                    else
                    {
                        cout << "Your inventory is full.";
                    }
                    cout << "Your inventory is:\n";
                    for (int i = 0; i < numItems; ++i)
                    {
                        cout << inventory[i] << endl;
                    }
                    cout << "You insert the keycard into it's slot in the elevator." << endl;

                    cout << "There are 3 floors: Egine Room, Crew Quaters, Ships Command Center. " << endl;
                    cout << "Which floor do you choose?" << endl;
                    cout << "1. Engine Room. " << endl;
                    cout << "2. Crew Quarters. " << endl;
                    cout << "3. Ships Command Center." << endl;

                    cin >> decision1;
                    cin.ignore();
                    clearOutWin();

                    if (decision1 == 1)
                    {
                        cout << "You chose to explore the Egine Room" << endl;
                        cout << "You exit the elevator ..." << endl;
                        cout << "It's dark. You pull out your flashlight. " << endl;
                        cout << "The engine room is extremely loud ..." << endl;
                        cout << "You begin exploring but find no signs of life. " << endl;
                        cout << "You find a crow bar. " << endl;

                    if (numItems < MAX_ITEMS)
                    {
                        inventory[numItems++] = "Crowbar";
                    }
                    else
                    {
                        cout << "Your inventory is full.";
                    }
                    cout << "Your inventory is:\n";
                    for (int i = 0; i < numItems; ++i)
                    {
                        cout << inventory[i] << endl;
                    }
                    cout << "You explore further but hear something .... something lurking around .." << endl;
                    cout << "Something runs by quickly behind you! You turn but there is nothing ..." << endl;
                    cout << "You feel something wet dripping on your shoulder...." << endl;
                    cout << "You look up! The Alien pounces on you!!!! The flashlight flys out of your hand... " << endl;
                    cout << "You block its mouth with the crowbar ..." << endl;
                    cout << "It's to dark and the Alien is to big and strong... You died. " << endl;
                    break; // Died, so breaks out of loop

                    }
                    else if (decision1 == 2)
                    {
                        int decisionE1;
                        cout << "You chose to explore Crew Quarters" << endl;
                        cout << "The elevator door opens and you exit." << endl;
                        cout << "As soon as you exit, someone to you right yells freeze!!!! Don't move or I will kill you." << endl;
                        cout << "John: Turn and face me!" << endl;
                        cout << "You turn and see a middle aged man pointing a shotgun at you." << endl;
                        cout << "You notice the security badge on his shirt and the name tag that reads John. " << endl;
                        cout << player << ": John....Please don't kill me! I'm just trying to find a way off this ship. Can you help me?" << endl;
                        cout << "John: There is something on this ship. A man killer. It killed everyone .... everyone i know is dead." << endl;
                        cout << player << ": I'm sorry to hear that.... But please can you help me?" << endl;
                        cout << "John: ......Yes. " << endl;
                        cout << "John: Follow me." << endl;
                        cout << "You follow the man to the security room." << endl;
                        cout << "John: I've seen this thing..... this monster that's hunting everyone ... I saw it." << endl;
                        cout << player << ": Do you know what it is? " << endl;
                        cout << "John: No, but it's dangero-  uuuuuuughhhh ahhhh!!! " << endl;
                        cout << "The Alien kills John!" << endl;
                        cout << "What do you do?" << endl;
                        cout << "1. Nothing." << endl;
                        cout << "2. Fire your pistol" << endl;
                        cout << "3. Run!" << endl;




                    cin >> decisionE1;
                    cin.ignore();
                    clearOutWin();


                    if (decisionE1 == 1)
                    {
                        cout << "You do nothing, the Alien kills you instantly." << endl;
                        break; // Died, so breaks out of loop

                    }
                    else if (decisionE1 == 2)
                    {
                        cout << "You fire your pistol but its no use, the Alien kills you." << endl;
                        break; // Died, so breaks out of loop

                    }
                    else if (decisionE1 == 3)
                    {
                        cout << "You make a run for it!!! But, the Alien is faster than you. You died." << endl;
                        break; // Died, so breaks out of loop
                    }


                    }
                    else if (decision1 == 3)
                    {

                        cout << "You chose to explore the Ships Command Center" << endl;
                        cout << "You exit the elevator." << endl;
                        cout << "You enter the ships bridge." << endl;
                        cout << "You turn the ships power back on! " << endl;
                        cout << "You try to reach help by using the ships comms station. " << endl;
                        cout << "Nobody responds...." << endl;
                        cout << "You suddenly hear something ....." << endl;
                        cout << "What do you do? " << endl;
                        cout << "1. You pull your pistol out ..." << endl;
                        cout << "2. You hide." << endl;
                        cout << "3. You continue trying to establish comms for help" << endl;

                        cin >> decision2;
                        cin.ignore();
                        clearOutWin();

                    }

                    if (decision2 == 1)
                    {
                        cout << "You draw your pistol ... " << endl;
                        cout << "You listen ...." << endl;
                        cout << "You hear something crawling in the vents above...." << endl;
                        cout << "Adrenaline rushing and without thinking you fire 2 rounds into the air vent!" << endl;
                        cout << "You hear a horrifying screech .... green acid blood leaks from the bullet holes onto your face!" << endl;
                        cout << "Your face melts as you scream in pain .... You died." << endl;
                        break; // Died, so breaks out of loop

                    }
                    else if (decision2 == 2)
                    {
                        cout << "You quickly hide!" << endl;
                        cout << "You run to a near by locker and hide." << endl;
                        cout << "You hear something crawling in the vents above ... " << endl;
                        cout << "The Alien drops from a near by air vent ...." << endl;
                        cout << "It begins sniffing around ...hunting you." << endl;
                        cout << "It walks passed the locker you're hiding it." <<endl;
                        cout << "You think you're safe but all of sudden it turns, begins sniffing, and starts towards you. " << endl;
                        cout << "You lean back and hold your breath ..... you begin to run out of air ..... a little longer!!! " << endl;
                        cout << "It's no use, you let out a burst of air!!!" << endl;
                        cout << "The Alien screeches, rips the door off, and kills you." << endl;
                        cout << "You died." << endl;
                        break; // Died, so breaks out of loop

                    }
                    else if (decision2 == 3)
                    {
                        int decision3;
                        cout << "You contniue trying to establish comms" << endl;
                        cout << "You hear someone!!!" << endl;
                        cout << player << ": Hello? Hello? Can you hear me? Do you read? Something has happened to the crew, I need help. There is something on board! Something non-human. It's hunting me! DO YOU READ? Over." << endl;
                        cout << "S.S Rescue Ship: We read you. This is the S.S Rescue ship. An emergency respond beacon was initiated 36 hours ago. What do you mean something is hunting you? Something non-human. Can you explain, over." << endl;
                        cout << player << ": Something has killed the crew and is after me now. I think i'm the last survivor. There is no time for further explination. Please help me!" << endl;
                        cout << "You hear something...." << endl;
                        cout << "S.S Rescue Ship: We will dock at docking station 4. Meet us there, over and out. " << endl;
                        cout << player << ": Alright!!!!!" << endl;
                        cout << "You run towards the elevator .... " << endl;
                        cout << "The Alien drops from an air shaft behind you and begins chasing you!!!" << endl;
                        cout << "The Alien is gaining on you.....You can hear the horrible sreeching coming from the Alien as it's chasing you." << endl;
                        cout << "You make it to the elevator and quickly press Crew Quarters. " << endl;
                        cout << "The doors begin to shut but the Alien is getting closer!!!" << endl;
                        cout << "What do you do?" << endl;
                        cout << "1. Pull your pistol and shoot? " << endl;
                        cout << "2. Keep running!!!!!!!" << endl;


                    }
                    cin >> decision3;
                        cin.ignore();
                        clearOutWin();

                    if (decision3 == 1)
                    {
                        cout << "You pull your pistol and begin firing!! You hit the alien 3 times causing it to stumble. You make it to the elevator. The doors shut." << endl;
                        cout << "You make it to docking station 4." << endl;
                        cout << "You see S.S Rescue Ship docked and waiting...." << endl;
                        cout << "You hurry and begin running towards it!" << endl;
                        cout << "The Alien pounces out of the shadows and stops you dead in your tracks.... " << endl;
                        cout << "The Alien looks at you ... bleeding from the bullet wounds ... " << endl;
                        cout << "It's a final showdown .." << endl;
                        cout << "You look around and see a flamethrower..." << endl;
                        cout << player << ": Animals are scared of fire right!!!??" << endl;
                        cout << "You run and pick up the flamethrower!" << endl;


                        if (numItems < MAX_ITEMS)
                    {
                        inventory[numItems++] = "FlameThrower";
                    }
                    else
                    {
                        cout << "Your inventory is full.";
                    }
                    cout << "Your inventory is:\n";
                    for (int i = 0; i < numItems; ++i)
                    {
                        cout << inventory[i] << endl;
                    }


                    int decisionE2;
                    cout << "You blast the Alien with fire and it jumps back!!! " << endl;
                    cout << "You fire again!!! Burning the Alien.." << endl;
                    cout << "You notice an air lock button ..." << endl;
                    cout << "You stand infront of it waiting for the Alien to pounce! " << endl;
                    cout << "S.S Rescue Ship: Hurry and get to the ship!!!" << endl;
                    cout << player << ": Not until i kill this bitch!!! " << endl;
                    cout << "The Alien pounces!" << endl;
                    cout << player << " Quickly!!! Press the air lock button!!" << endl;
                    cout << "1. Press air lock button" << endl;
                    cout << "2. Do nothing." << endl;


                    }
                    else
                    {
                        cout << "You keep running but the Alien is fast. You died." << endl;
                        break; // Died, so breaks out of loop
                    }

                    cin >> decisionE2;
                    cin.ignore();
                    clearOutWin();

                    if (decisionE2 == 1)
                    {
                        cout << "You press the air lock button and dive out of the way!!!" << endl;
                        cout << "The Alien is sucked out into space ... you quickly close the air lock door before being sucked out into space. " << endl;
                        cout << "You board the S.S Rescue Ship." << endl;
                        cout << "Congratulations, you survived." << endl;
                        break; // You win, but break out of loop
                    }
                    else
                    {
                        cout << "You died." << endl;
                        break; // Died, so breaks out of loop
                    }




                }

                else if (choice2 ==2)
                {



                    cout << "You head right." << endl;
                    cout << "As you're walking you hear something ...." << endl;
                    cout << "It sounds like something is moving in the ceiling ..." << endl;
                    cout << "All of a sudden the Alien drops from an air vent!" << endl;
                    cout << "You freeze in terror..." << endl;
                    cout << "You slowly reach for your pistol." << endl;
                    cout << "The alien charges you! " << endl;
                    cout << "You manage to fire 2 rounds into the alien but it's no use, the alien kills you. " << endl;
                    cout << "You died. " << endl;
                    break; // Died, so breaks out of loop

                }
            }
            playAgain = askPlayAgain();
    }

	return 0;
}


void clearOutWin()
{
    // system("clc") is windows specific, use command below
    // ANSI escape codes for clearing and returing cursor
    // Found at stackoverflow
    cout << "\033[2J\033[1;1H";
    return;

}

int askPlayAgain()
{
    string pChoice = "n";

    cout << "\n\nWould you like to play again?(Yes or No) ";

    cin >> pChoice;

    pChoice = pChoice[0];

    if (pChoice == "n" || pChoice == "N")
    {
        cout << "Thanks for playing!!! Bye!";
        return 0;
    }
    cout <<"\n\n";

    return 1;


}



















