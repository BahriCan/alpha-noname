#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define MAX_LEN 128
// ahh much better now that the code is reformatted

void print_image(FILE * imagefile);
int user_prompt();

int main()
{
    // a new version, we'll be using fgets() instead of scanf() now. i see that it is dangerous...
    int monster_alpha;
    int player_health;
    int player_defense;
    int punch_attack_power;
    char character_name[255]; // SHIIIT IF I DO NOT PROVIDE A VALUE IT'LL NEVER BE BUFFER OVERRUN FUCK YEAAH
    // never mind.. i have to provide a value for single-dimensional arrays. OR I COULD JUST = TO FGETS... nah not gonna happen :/
    // eh fuck it I'll just use an integer variable to define true or false values. 0-false, 1-true.
    int goblin_is_defeated = 1;
    int left_path_wood_is_taken = 0; // I consider zero to be false, 1 to be true. The woods in the left path are initially not taken, they will be once the player goes to the left path.
    int right_path_wood_is_taken = 0;
    int straight_path_wood_is_taken = 0;
    int user_wood_amount = 0;
    int isInvalidInput = 1; // this variable is to detect whether or not the user entered a correct value, it'll turn into a 0 and be considered false, and end the loop and continue off of that IF/ELSE block.
    //int isInvalidInput2 = 1; // another variable bcuz i cant use the same one in nested do-while loops
    monster_alpha = 15;
    player_health = 200;
    player_defense = 10;
    punch_attack_power = 5;

    printf("Welcome to the alpha version of <insert game name here>.\nCOPYRIGHT u/Bahrican798.\n"); // I gotta find a name, man... Zagros maybe? does a game with that name exist?
    printf("I know, it's not much, obviously. This is as much as I can get done in this environment...\n");
    printf("It is recommended that you play this game in fullscreen.\n");
    char user_input[255];
    printf("===================================================\n");
    printf("\t\t<insert game name here>\t\t\n");
    printf("\t\t TYPE \"Start\" TO PLAY\t\t\t\n");
    printf("===================================================\n");
    do
    {
        printf(">||: ");
        fgets(user_input,255,stdin);    // try fgets maybe... I'm tired. the if statements dont work... skips directly to else and returns 2.
        user_input[strcspn(user_input, "\n")] = 0;
        //printf("%s",user_input); okay fgets works fine... although strcmp is not happy with how I compare strings now that I use fgets it seems.
        // printf("you wrote: %s", user_input); // although when checked in with printf, it seems that scanf reads everything, not just the first character only... I guess it does not store it as a variable then?
        // FIXED IT :D the "\n" is important in fgets apparently, never forget that!!! never forget the \n!!! hold the fuck up something's wrong here... the ".n" is printed onto a newline? this shit could prove to be a problem in the future, better solve it now. Alright it's fixed! learned how to get rid of the attached newline on the string!
        if(strcmp(user_input,"Start") == 0 || strcmp(user_input, "start") == 0)// FUCK YES FINALLY IT CAN START
        {
            isInvalidInput = 0; // do-while condition is set to false, hence ending the loop and achieving what we did with goto. no more spaghetti code that's hard to track, yaaay!!.. it's fucking, what, 2am? im tired..
            // phew... almost lost all progress there, LiveOSes are a dangerous environment to do development on!
            printf("Choose your name, choose wisely for it can NOT be changed later on! Max. 255 characters: ");
            fgets(character_name,255,stdin); // why does fgets not work? does it have something to do with the loop? the if statement bothers it maybe? fuck im tired
            // yeah replaced the scanf here and everywhere else with fgets, I have seen that it crashes if the user inputs an overflowing value.. and there is nothing to stop the user from doing that :P
            character_name[strcspn(character_name, "\n")] = 0;
            printf("Your name is %s.", character_name);
            sleep(1);
            printf(" Welcome... to a new world.\n");
            sleep(1.5);
            printf("You're wondering around.\n");
            sleep(1.5);
            printf("You keep walking for hours on end.\n");
            sleep(3);
            printf("It's getting late...\n");
            isInvalidInput = 1;
            do
            {
                printf("You stumble upon a little cave. Go inside? [Y/n] >||: ");
                // I need to find a way to print [], (), {}....
                // well making a string variable and putting '[' in it and printing it via printf %s IS an option... but not efficient. There MUST be a way to just print those characters without a hassle!
                // I gotta get some work done on this...
                // I better put it into the "to be done" section, I usually don't read comments.
                fgets(user_input,255,stdin);
                //printf("%s.n", user_input);
                // okay we either use fgets and chop off the attached newline each time, which is a bother, or just include in the newline when comparing strings and only chop off the newline when needed to which'll result in fewer lines of code. latter sounds better, right?
                if (strcmp(user_input, "Y\n") == 0 || strcmp(user_input, "y\n") == 0 || user_input[1] == '\0') // fuck how do I detect if the user just pressed enter, do I just not let them? okay nevermind figured that part out
                {
                    isInvalidInput = 0;
                    char * filename = "mountains.txt";
                    FILE * imagefile = NULL;

                    if((imagefile = fopen(filename,"r")) == NULL)
                    {
                        fprintf(stderr,"error opening %s\n",filename);
                        return -1;
                    }

                    print_image(imagefile);

                    fclose(imagefile);
                    sleep(1);
                    printf("\nYou feel a cold breeze. You think of starting a campfire, and go out.\n");
                    sleep(6); // something's disturbing about these sleep statements..
                    filename = "snowing.txt";
                    if((imagefile = fopen(filename,"r")) == NULL)
                    {
                        fprintf(stderr,"error opening %s\n",filename);
                        return -1;
                    }
                    print_image(imagefile);
                    fclose(imagefile);
                    printf("\nIt's snowing.\n");
                    sleep(4);
                    // perhaps give the player a jacket/coat? inside the cave perhaps?
                    printf("You find 4 pieces of wood and decide to go back, it is too cold to be outside right now.\n");
                    user_wood_amount = user_wood_amount + 4;

                    break;

                }
                else if (strcmp(user_input, "N\n") == 0 || strcmp(user_input, "n\n") == 0) // I could use strncmp to make the check case-insensitive, which would shorten the code.. but do I really wanna use strncmp? looks like a bother to me
                {

                    isInvalidInput = 0;
                    printf("You decided not to go inside the cave.\n");
                    sleep(3);
                    printf("It's getting cold... You imagine a warm campfire, and set out to get some firewood.\n");
                    printf(".\n");
                    sleep(1);
                    printf("..\n");
                    sleep(1);
                    printf("...\n");
                    sleep(5);
                    printf("You wander in the forest, searching for some wood.\n");
                    sleep(0.5);
                    printf("You have three paths ahead of you.\n");
                    sleep(0.5);
                    do
                    {
                        printf("Go [L]eft,[R]ight,[S]traight, [G]o back. >||: ");
                        fgets(user_input, 255, stdin);
                        //stupid me, I forgot the \n in the user string :DDD such a relief, it is better than an orgasm
                        if(strcmp(user_input, "L\n") == 0 || strcmp(user_input, "l\n") == 0)
                        {
                            isInvalidInput = 0;
                            printf("\nYou chose to go left.\n");
                            if(left_path_wood_is_taken == 0)
                            {
                                printf("You found 2 pieces of wood! And some blood stains...\n"); // we can connect this to the story later on.. use left_path_wood_is_taken to check if this place has been visited, to ensure the player saw the blood stains. Then type in "The blood in the forest must belong to this wounded man..." Rest is a secret ;) wait until the game comes out in a full demo for it
                                left_path_wood_is_taken = 1;
                                user_wood_amount += 2;
                            }
                            else if(left_path_wood_is_taken != 0)
                            {
                                printf("There's nothing here....\n");
                            }
                            // now to write a loop that'll take the user here again if they wanna, and check if the wood here has been already taken.

                            //gotta loop this user input part such that it'll come back here when they input an invalid command.. it's getting messier even with astyle

                            /*printf("Go back?(Y/n) >||: ");
                            //FUUCK I LOVE DOING THIS SO MUCH, I LOVE PROGRAMMING I'M JUST _FLOWING_ WITH IDEAS RIGHT NOW!!♥♥♥
                            fgets(user_input, 255, stdin);
                            //ahh no wait.. should I really use goto here? I mean, I can write comments to explain why and where exactly it is heading, and I can refactor it later on if it starts getting messy with goto and replace it with do-while...
                            if(strcmp(user_input, "Y\n") == 0 || strcmp(user_input, "y\n") == 0 || user_input[1] == '\0')
                            {
                                printf("\ntest code 2, isInvalidinput is %d\n", isInvalidInput2);
                                break;
                                printf("\ntest, isInvalidInput is %d, isInvalidInput2 is %d\n", isInvalidInput, isInvalidInput2);

                            }
                            else if(strcmp(user_input, "N\n") == 0 || strcmp(user_input, "n\n") == 0)
                            {
                                printf("\ntest code");
                                printf("\ntest, isInvalidInput is %d, isInvalidInput2 is %d\n", isInvalidInput, isInvalidInput2);
                                break;
                                unneeded code... will be removed later on
                            }*/


                        }
                        else if(strcmp(user_input, "R\n") == 0 || strcmp(user_input, "r\n") == 0)
                        {
                            printf("\nYou chose to go right.\n");
                            if(right_path_wood_is_taken == 0)
                            {
                                printf("You found 3 pieces of wood!\n");
                                right_path_wood_is_taken = 1;
                                user_wood_amount += 3;
                            }
                            else if(right_path_wood_is_taken != 0)
                            {
                                printf("There's nothing here....\n");
                            }

                        }
                        else if(strcmp(user_input, "S\n") == 0 || strcmp(user_input, "s\n") == 0)
                        {
                            printf("\nYou chose to go straight ahead.\n");
                            if(straight_path_wood_is_taken == 0)
                            {
                                printf("You found a piece of wood.\n");
                                straight_path_wood_is_taken = 1;
                                user_wood_amount++;
                            }
                            else if(straight_path_wood_is_taken != 0)
                            {
                                printf("There's nothing here....\n");
                            }
                        }
                        else if(strcmp(user_input, "G\n") == 0 || strcmp(user_input,"g\n") == 0)
                        {
                            break;
                        }
                        // else if (user_input[1] == '\0')
                        //   isInvalidInput = 1;
                    }
                    while(1);
                  //  printf("\ntest, isInvalidInput is %d", isInvalidInput );
                }
                else
                {
                    continue;
                }
                break;
            }
            while(isInvalidInput);
               // printf("\nhere's where you make a campfire");
            printf("\nYou return to the cave.\n");
            sleep(3);
            if(user_wood_amount <= 2)
            {
                printf("You have %d piece(s) of wood. You make a small fire, but it's shortlived.\n",user_wood_amount);
                sleep(3);
                printf("You decide to sleep while it's still feeling warm enough.\n");
                sleep(2);
                printf(".\n");
                sleep(2);
                printf("..\n");
                sleep(2);
                printf("...\n");
                sleep(1);
                printf("Your defense dropped by 5. You got a cold and your back hurts because you sleeped on the cold, hard ground.\n");// i can either make a boolean variable, check this in later outside of the campfire scene, or print it out inside here...
                player_defense -= 5;
            }
            if(user_wood_amount > 2 && user_wood_amount <= 5)
            {
                printf("You throw in some sticks to get the fire started.\n");
                sleep(3);
                printf("The cave has lightened up, and it's quite warm now.\n");
                sleep(5);
                printf("You feel warm and cozy.\n");
                sleep(2);
                printf("It's midnight.\n");
                sleep(2);
                printf("You decide to take a short nap. Be on the lookout for the fire.\n");
                sleep(3);
                printf(".\n");
                sleep(2);
                printf("..\n");
                sleep(2);
                printf("...\n");
            }
            if(user_wood_amount == 6)
            {
                printf("You come back with lots of wood in your arms.\n");
                sleep(4);
                char * filename = "campfire.txt";
                FILE * imagefile = NULL;
                if((imagefile = fopen(filename,"r")) == NULL)
                {
                    fprintf(stderr,"error opening %s",filename);
                    return -1;
                }
                print_image(imagefile);
                fclose(imagefile);
                sleep(1);
                printf("\nYou make a fire. It's damn cozy now, and bright.\n");
                sleep(3);
                printf("You decide to sleep, the fire should last until morning sun.\n");
                sleep(4); // something is reaally wrong with these sleep statements....
                printf(".\n");
                sleep(2);
                printf("..\n");
                sleep(2);
                printf("...\n");
                sleep(5);
                player_defense += 5;
                printf("\nYour defense has increased by 5! You did morning stretches and had a good sleep.\n");
            }
            printf("\n\tSorry, folks. This is the demo for now! Check in later for progression and stay tuned!\n");
            return 0;
        }

        else if (strcmp(user_input, "easter") == 0) // Fuck man I can't put in spaces there... I'll figure that out later, I need to make a release now
        {
            //isInvalidInput = 0; // sets the do-while condition to false, ending the loop
            printf("Welcome to the pre-alpha release. This command is only known by those who observe the source code :D\n"); // Fuck I can't make a smiley ( ;) )
            printf("To do stuff:\n");
            printf("Ideas to be added:\n");
            printf("- Different routes.\n");
            printf("-Shops, alongside routes.\n");
            printf("-Show the user their options, how many paths they can take at that moment, what's nearby etc.\n");
            printf("-Experience points, leveling up and having your stats go up etc. Maybe I'll add the option to select which stat you wanna upgrade, like in Paper Mario\n");
            printf("-Small creatures on the road, and the option to fight them or leave them alone. I'll try to use boolean to determine if they are defeated or not, which then will block the user from killing the same creature again and again for free EXP and HP. Now that I mention this.. a new idea popped in, check the next one for it.\n");
            printf("-Be able to go back the routes you take... I'm not sure how I'll do that, I'll figure it out. But not today.\n");
            printf("-Earn money, exp etc. from killed creatures.\n");
            printf("-Have a stamina that increases on a timer. I don't know how I'll implement that in a console game, I'll keep reading the book to see if there is something like waiting a few seconds, otherwise I'll set up a loop with while or for, and calculate the time that passes by, and increase the stamina variable that way. We can do this with a function and the sleep command! sleep for e.g 5 seconds, mana += 20!!\n");
            printf("-Be able to learn new abilites.. Reminds me of M&L: Superstar Saga\n");
            printf("-Settings? Maybe? what would one want to change in this \"game\" anyway\n");
            printf("-The player will be able to see how much exp left to level up... I'm still considering this, it's possible but why should I let them?\n");
            printf("-Adventure/Story Mode, Free fighting mode. The free fighting will only allow you to battle with monster you've fought before. To determine that, I'll use boolean again... Damn I'm getting too dependent on boolean, and it doesn't even exist in C.\n");
            printf("-Give the user a limited amount of health potions to begin with.\n");
            printf("-Stats, probably. This one didn't go well apparently in C#. I'll attempt it here, what could go wrong? Let the user see their stats, health, exp, level etc.\n");
            printf("-Setting max values for stuff like player_health, if it exceeds it's max value, make it equal to it's max value again. Perhaps I'll use a separate, untouched variable for this called 'max_health'.\n");
            printf("-A start menu wouldn't be so bad, like the ncurses menus in shell scripts!\n");
            //printf("-Let the user choose their character's name.\n");
            printf("-Send the user back to the prompt if they input something not related or whatever.\n");
            printf("- Add an inventory command, the player can check their inventory and see what they have at any time. Make it a function perhaps? check structs as well\n");
            printf("-Add an option to save the game... I don't know how to do that, I'll do it but not today.\n");
            printf("- Make a function in a separate file, prototype this first in Python though. Some sort of a loop, a while loop, that'll take different values like how for or printf does. This loop will be used for fights. It'll be a barebones function, we'll fill in the blanks--- string to print out like 'You defeated the boss!', 'You used punch, you did 20 damage'--- ourselves.\n");
            printf("-Randomize monsters' attacks. They'll have various attacks that do different amounts of damage. Use a random number generator or something ;_;\n");
            //printf("Find a way to printf the following character, it's in the source code. Here I'll even print it here, BUT this is a troublesome way to print out a '%s'.\n", special_character);
            //printf("- DONT use goto! Apparently it's bad practice... find an alternative. Should be worth it, especially when you look at the old CS source code.. Damn that sure was one helluva spaghetti code.\n");
            printf("-Give the user a limited inventory, like in uhh.. umm.... i dont fucking remember the game name just give the user a small inventory and items around them to pick up/drop.\n");
            printf("-Either use command line options like --start, --debug and whatever, or use an in-game prompt like we are now.\n");
            printf("-Perhaps make the variables an array? IF we ever add difficulty options to this, that could be useful to load in different values, e.g 10 damage for a monster in easy mode, 15 in normal, 20 in expert, 300/200/150 player health etc.\n");
            //printf("-Check fgets, scanf seems to be a pain...\n");
            printf("-The save/load feature can be a function!\n");
            //printf("-Hold the fuck up this is getting more and more complicated.. If I am going to be writing the same scenario again in another decision later on, this'll double the amount of code and the time to write it! There MUST be a way to join the both ends into the same route... I need to get out of the if statements.. Should we use goto/longjmp? I think so..");
            printf("-Add defense points too! Oh and have a multiplier for the attack powers! Like in pokémon, but simplified!! Your attack power will be multiplied by a random number between 0.5 and 1.0!!\n");
            printf("Added/fixed stuff:\n");
            printf("+Finally stopped using goto, I am using for loops instead now that for stopped being such a dick and started working...\n");
            printf("+Got rid of scanf, using fgets now.\n");
            printf("+Added sleep so that it waits between printing stuff!\n");
            printf("This is all for now I guess. New ideas come by every now and then, which I'll note down here in this 'Easter Egg' :P.\n");

        }
        else if(strcmp(user_input, "test") == 0)
        {
            isInvalidInput = 0; // ends the do-while loop by setting the loop condition to false
            for( ; monster_alpha > 0;) // I FUCKING HATE THE FOR STATEMENT IN C WHY DO I HAVE TO "iNItiaLiZE" SHIT I JUST WANNA GIVE A SINGLE CONDITION AND BE FUCKING DONE WITH IT
                // Oh nevermind ._. apparently I can just put in a semicolon and fuck off with it... why didn't work the first time I tried it though? I did the exact same thing..
                // this is pain
                // hold on, just a few more lines and we can release the pre-alpha version
                // alpha-release note, I could potentially replace this for loop with a do-while loop. i dont know which is more efficient...
                // do-while seems more explanotary, i mean i had a fucking heart-stroke while trying to understand this loop i wrote..
            {
                printf("test: ");
                scanf("%s", user_input);
                if(strcmp(user_input, "1") == 0)
                {
                    monster_alpha = monster_alpha - punch_attack_power;
                    printf("%d\t%d", monster_alpha, punch_attack_power);

                }

            }

            // Here's an idea.. don't erase the stuff you put in this chunk of code. Instead just comment them out, or put in goto statements and special commands which'll allow you to jump among testing grounds
        }
        else if (strcmp(user_input, "demo") == 0)
        {
            printf("In a far away, distant land...\n");
            char * filename = "mountains.txt";
            FILE * imagefile = NULL;

            if((imagefile = fopen(filename,"r")) == NULL)
            {
                fprintf(stderr,"error opening %s\n",filename);
                return -1;
            }

            print_image(imagefile);
            fclose(imagefile);
            sleep(3);
            printf("\nYou take off on an adventure...\n");
            sleep(3);
            filename = "rocky-mountains.txt";

            if((imagefile = fopen(filename,"r")) == NULL)
            {
                fprintf(stderr,"error opening %s\n", filename);
                return -1;
            }

            print_image(imagefile);

            fclose(imagefile);
            //sleep(3);
            printf("\nYou overcome the hardest challenges..!\n");

            sleep(3);
            filename = "goblin.txt";
            if((imagefile = fopen(filename,"r")) == NULL)
            {
                fprintf(stderr,"error opening %s\n", filename);
                return -1;
            }
            print_image(imagefile);
            fclose(imagefile);
            printf("\nFight the hardest foes...\n");
            sleep(3);
            filename = "maze.txt";
            if((imagefile = fopen(filename,"r")) == NULL)
            {
                fprintf(stderr,"error opening %s\n", filename);
                return -1;
            }
            print_image(imagefile);
            fclose(imagefile);
            printf("\nGet confused a lot...\n");
            sleep(3);
            filename = "snowing.txt";
            if((imagefile = fopen(filename,"r")) == NULL)
            {
                fprintf(stderr,"error opening %s\n", filename);
                return -1;
            }
            print_image(imagefile);
            fclose(imagefile);
            printf("\nGo through cold, harsh nights...\n");
            sleep(3);
            filename = "pow!.txt";
            if((imagefile = fopen(filename,"r")) == NULL)
            {
                fprintf(stderr,"error opening %s\n", filename);
                return -1;
            }
            print_image(imagefile);
            fclose(imagefile);
            printf("\nThink your way through fights harder than the existential crisis you have at 3AM strategically! Every choice you make affects the game!\n");
            sleep(0.4);
            printf("Challenge yourself in <insert game name here>!\n");
            isInvalidInput = 1;
        }
        else if(strcmp(user_input, "exit") == 0)
        {
            printf("\nThank you for playing!\n");
            return 5;

        }
        else
        {
            printf("Please type \"Start\" to play.\n");
            //printf("I couldn't write something to send the user back to the prompt, sorry.."); // Well I COULD use goto... but this thing is about to evolve into a few thousand lines of code, doesn't feel right to use goto
            //^ NOT TRUE ANYMORE!! Finally figured out how to set up that do-while loop!! :DD so happy... wonder if u/Urthemando_Mod will be pleased with this "progress"... probs not, still. i finally got rid of the burden that is goto.
        }
    }
    while(isInvalidInput);
    return 0;

}

void print_image(FILE * imagefile)
{
    char read_string[MAX_LEN];

    while(fgets(read_string,sizeof(read_string),imagefile) != NULL)
        printf("%s",read_string);
}

/*
int user_prompt()
{
    static char user_input[255];
    printf("\n>||: ");                  To be used later on... needs a lot of refactoring for the code and I can't do that now
    fgets(user_input,255,stdin);
    printf("\n%s", user_input);


}*/
