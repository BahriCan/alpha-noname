#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#define MAX_LEN 128
// just a few more cleanups, then restructing the code to work with just lowercase input.
// We can use this typedef struct for monsters and the player(s), it'll especially be useful if we ever put in a multiplayer mode.
// Tomorrow morning we'll be doing a cleanup now that the isInvalidInput variable has been deprecated and the user prompt is a function now..
// ahh much better now that the code is reformatted
char user_input[255]; // now to refactor the code...
void print_image(FILE * imagefile);
void user_prompt();
//now.. what were we doing? oh yeah.. the user stat function. and structures... i think that's where we left off
typedef struct
{
    char name[255]; // this motherfucker right here fucks it all up... or as far as i understand it. pointers man... welp apparently the guy on stackoverflow cursed me with having to use malloc() for this name variable. this is my life now
    int health_points; // do max point versions of these variables as well!
    int defense_points;
    int attack_points;
    int mana_points;
} basic_character_structure;


// now to add in a function to print the enemy's status. the function will take an argument, and it'll print the status of a certain thing depending on the argument it receives. it'll also turn a value true (if the user already fought that monster before), which'll be useful for the free-fighting mode
int main() // add in command-line options with int argc, char *argv[]... it'll need a refactoring
{
    // a new version, we'll be using fgets() instead of scanf() now. i see that it is dangerous...
    //int punch_attack_power; oh yeah.. CHECK IN WITH THIS VARIABLE, WE MIGHT HAVE TO CREATE A SPECIAL STRUCTURE FOR THE PLAYER THEMSELVES AND THE MONSTERS SEPARATELY
    //char character_name[255]; // SHIIIT IF I DO NOT PROVIDE A VALUE IT'LL NEVER BE BUFFER OVERRUN FUCK YEAAH| this one could remind me that I can't = fgets() in the future
    // never mind.. i have to provide a value for single-dimensional arrays. OR I COULD JUST = TO FGETS... nah not gonna happen :/
    // eh fuck it I'll just use an integer variable to define true or false values. 0-false, 1-true.
    //int goblin_is_defeated = 1; cant we loop this with do-while, 1, break, continue?
    int left_path_wood_is_taken = 0; // I consider zero to be false, 1 to be true. The woods in the left path are initially not taken, they will be once the player goes to the left path.
    int right_path_wood_is_taken = 0;
    int straight_path_wood_is_taken = 0;
    int user_wood_amount = 0;
    int player_took_jacket = 0;
    int player_is_wearing_jacket = 0;
    // man I said a clean-up... not more messy, deprecated, commented out code!! | I should've tested before deprecating random shit.
    basic_character_structure player;
    player.attack_points = 10;
    player.defense_points = 20;
    player.health_points = 200;
    player.mana_points = 30;
    player.name; // curious... what if i... nah didn't work
    // yeah player.name comes in after the game starts and the user chooses a name. | I LITERALLY TESTED IT BEFORE WHY DOESN'T THE SAME THING WORK NOW

    printf("Welcome to the alpha version of <insert game name here>.\nCOPYRIGHT u/Bahrican798.\n"); // I gotta find a name, man... Zagros maybe? does a game with that name exist?
    printf("I know, it's not much, obviously. This is as much as I can get done in this environment...\n");
    printf("It is recommended that you play this game in fullscreen.\n");
    printf("===================================================\n");
    printf("\t\t<insert game name here>\t\t\n");
    printf("\t\t TYPE \"Start\" TO PLAY\t\t\t\n");
    printf("===================================================\n");
    do
    {
        user_prompt();// try fgets maybe... I'm tired. the if statements dont work... skips directly to else and returns 2.
        //user_input[strcspn(user_input, "\n")] = 0; // I could  potentially put this in user_prompt() ... should I?
        //printf("%s",user_input); okay fgets works fine... although strcmp is not happy with how I compare strings now that I use fgets it seems.
        // printf("you wrote: %s", user_input); // although when checked in with printf, it seems that scanf reads everything, not just the first character only... I guess it does not store it as a variable then?
        // FIXED IT :D the "\n" is important in fgets apparently, never forget that!!! never forget the \n!!! hold the fuck up something's wrong here... the ".n" is printed onto a newline? this shit could prove to be a problem in the future, better solve it now. Alright it's fixed! learned how to get rid of the attached newline on the string!
        if(strcmp(user_input,"start\n") == 0)// FUCK YES FINALLY IT CAN START
        {
            // do-while condition is set to false, hence ending the loop and achieving what we did with goto. no more spaghetti code that's hard to track, yaaay!!.. it's fucking, what, 2am? im tired..
            // phew... almost lost all progress there, LiveOSes are a dangerous environment to do development on!
            printf("Choose your name, choose wisely for it can NOT be changed later on! Max. 255 characters >||: "); // yeah something broke, potentially around these parts. wtf happened, this part should work just fine
            fgets(player.name,255,stdin); // why does fgets not work? does it have something to do with the loop? the if statement bothers it maybe? fuck im tired
            // yeah replaced the scanf here and everywhere else with fgets, I have seen that it crashes if the user inputs an overflowing value.. and there is nothing to stop the user from doing that :P
            // we could perhaps make this user_prompt() function receive arguments and replace the fgets(user_input,255,stdin) with something else with those arguments..
            player.name[strcspn(player.name, "\n")] = 0; // i hope this works... if i put it in user_prompt() I'll never need to remember the \n again! I don't see the issue here... I'll do it after I think about the possible outcomes
            printf("Your name is %s.", player.name);
            sleep(1); //okay screw the sleep lines for testing purposes
            printf(" Welcome... to a new world.\n");
            sleep(1.5);
            printf("You're wondering around.\n");
            sleep(1.5);
            printf("You keep walking for hours on end.\n");
            sleep(3);
            printf("It's getting late...\n");
            do // im so sleepy lloll ..... apparently there is alternatives to goto.. stupid fucking book telling me to use goto...
            {
                printf("You stumble upon a little cave. Go inside? [Y/n] ");
                user_prompt();
                // I gotta get some work done on this...
                // I better put it into the "to be done" section, I usually don't read comments.
                //printf("%s.n", user_input);
                // okay we either use fgets and chop off the attached newline each time, which is a bother, or just include in the newline when comparing strings and only chop off the newline when needed to which'll result in fewer lines of code. latter sounds better, right?
                if (strcmp(user_input, "y\n") == 0 || user_input[1] == '\0') // fuck how do I detect if the user just pressed enter, do I just not let them? okay nevermind figured that part out
                {
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
                else if (strcmp(user_input, "n\n") == 0) // I could use strncmp to make the check case-insensitive, which would shorten the code.. but do I really wanna use strncmp? looks like a bother to me
                {
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
                    do // the threeway path loop, Left, Right, Straight.
                    {
                        printf("Go [L]eft,[R]ight,[S]traight, [G]o back. ");
                        user_prompt();
                        //stupid me, I forgot the \n in the user string :DDD such a relief, it is better than an orgasm| yeah, as can be seen here, I often forget the \n attached to the string in fgets
                        if(strcmp(user_input, "l\n") == 0)
                        {
                            printf("\nYou chose to go left.\n");
                            if(left_path_wood_is_taken == 0)
                            {
                                printf("You found 2 pieces of wood! And some blood stains...\n"); // we can connect this to the story later on.. use left_path_wood_is_taken to check if this place has been visited, to ensure the player saw the blood stains. Then type in "The blood in the forest must belong to this wounded man..." Rest is a secret ;) wait until the game comes out in a full demo for it
                        sleep(2);
                                do
                                {
                                    printf("There's a jacket on the blood-stained rock. Take it? [Y/n] ");
                                    user_prompt();
                                    if (strcmp(user_input,"y\n") == 0 || user_input[1] == '\0')
                                    {
                                        player_took_jacket = 1; // can or not wear the jacket- let's give them a choice and have it effect their gameplay again
                                        do
                                        {
                                            printf("You took the jacket. Put it on now? (You are well advised to.)[Y/n]");
                                            user_prompt();
                                            if (strcmp(user_input, "y\n") == 0 || user_input[1] == '\0')
                                            {
                                                printf("You wear the jacket.\n");
                                                                        sleep(3);
                                                printf(".\t");
                                                                     sleep(2);
                                                printf(".\t");
                                                                sleep(2);
                                                printf(".\n");
                                                                sleep(3); // huh? what was i doing again?
                                                player_is_wearing_jacket = 1;
                                                printf("You start feeling warmer.\n");
                                                break;
                                            }
                                            else if(strcmp(user_input, "n\n") == 0)
                                            {
                                                printf("You chose to not wear the jacket now. It's a bit cold though, you should wear it soon...\n");
                                                break;
                                            }
                                        }
                                        while(1);
                                        break;
                                    }
                                    else if (strcmp(user_input, "n\n") == 0)
                                    {
                                        printf("You chose not to take the bloody jacket.\n");
                                        break;
                                    }
                                }
                                while(1);
                                left_path_wood_is_taken = 1;
                                user_wood_amount += 2;
                            }
                            else if(left_path_wood_is_taken != 0)
                            {
                                printf("There's nothing here....\n");
                            }
                            // now to write a loop that'll take the user here again if they wanna, and check if the wood here has been already taken.
                            //gotta loop this user input part such that it'll come back here when they input an invalid command.. it's getting messier even with astyle
                            //FUUCK I LOVE DOING THIS SO MUCH, I LOVE PROGRAMMING I'M JUST _FLOWING_ WITH IDEAS RIGHT NOW!!♥♥♥
                            //ahh no wait.. should I really use goto here? I mean, I can write comments to explain why and where exactly it is heading, and I can refactor it later on if it starts getting messy with goto and replace it with do-while...
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
                }
                else
                {
                    continue;
                }
                break;
            }
            while(1);
            // here's where you make a campfire
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
                player.defense_points -= 5; // I will forgive the player if they decide to do a morning run and warm up. (player_defense += 5;)
                printf("Do a morning run and stretches to warm up? [Y/n]  ");
                user_prompt();
                if(strcmp(user_input, "Y\n") == 0 || strcmp(user_input, "y\n") == 0 || user_input[1] == '\0')
                {
                    printf("You start running around in the cave, while trying not to get lost.\n");
                    sleep(5);
                    printf("You get tired. You stop before you start sweating.\n");
                    sleep(3);
                    printf("You gained 2 defense points. You're still sore from sleeping on the ground, and your nose is runny.\n");
                    player.defense_points += 2; // good thinking with the player_* variable naming! it made it real easy to replace!!
                    sleep(4);
                }
                else if(strcmp(user_input, "N\n") == 0 || strcmp(user_input,"n\n") == 0)
                {
                    printf("You decide to just look at the task at hand.\n");
                    sleep(3);
                }
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
                player.defense_points += 5;
                printf("You wake up.\n");
                printf("\nYour defense has increased by 5! You did morning stretches and had a good sleep.\n");
            }
            // owh... my brain..
            printf("It's still snowing outside.\n");
            sleep(3);
            printf("You look at your campfire.\n");
            sleep(3);
            printf("It's out, unfortunately.\n");
            sleep(3);
            printf("You are out of wood as well. Not much to do besides stay in right now and wait the snow out.\n");
            sleep(5);
            do
            {
                printf("What will you do? [W]ait out in the cave / I love [e]xploring ");
                user_prompt();
                if(strcmp(user_input,"w\n") == 0 || user_input[1] == '\0')
                {
                    sleep(3);
                    printf("You decided to wait it out inside the cave.\n");
                    sleep(3);
                    printf("3 days have passed and you have died of hunger. Game over!\n"); // you got the coward ending...
                    return 0; // print "COWARD" in ASCII values here :DDD
                }
                else if(strcmp(user_input,"e\n") == 0)
                {
                    // check if the player is wearing their jacket or not, and prompt them to wear it one more time
                    printf("You decided to go out exploring, in the snow."); // i was going to do SOMETHING important.... oh yeah, do-while loop
                    if (player_is_wearing_jacket == 0 && player_took_jacket == 1) // we need to make sure the player has the jacket AND not wearing it!! it could be that they dont wear it since they dont have it, which'd be stupid..
                    {
                        do
                        {
                            printf("You are currently not wearing your jacket. Wanna wear it now? [Y/n] ");
                            user_prompt();
                            if(strcmp(user_input,"y\n") == 0 || user_input[1] == '\0')
                            {
                                sleep(3);
                                printf("You are wearing the jacket.\n");
                                sleep(1);
                                printf(".\n");
                                sleep(1);
                                printf("..\n");
                                sleep(1);
                                printf("...\n");
                                sleep(2);
                                player_is_wearing_jacket = 1;
                                printf("You wore the jacket.\n");
                                break;
                            }
                            else if(strcmp(user_input,"n\n") == 0)
                            {
                                sleep(2);
                                printf("You decided not to wear the jacket. It's really cold outside, you should've worn it when you had the chance to.\n");
                                sleep(4);
                                player.defense_points -= 1;
                                printf("You lost 1 defense point. You are feeling very cold...\n");
                                break;
                            }
                        }
                        while(1);
                    }
                    else if (player_is_wearing_jacket == 1)
                    {
                        printf("You go out with your jacket.\n");
                        break;
                    } // should we do something for when they already have their jacket on? i think so, we'll do that next
                    break;
                }
            }
            while(1);
            printf("You start wandering around.\n");
            sleep(2);
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
            printf("-The print_info function should be checked another time, you need to learn how to refer to an object by a string. For now just dont implement the function to print enemy info...\n");
            printf("-Search how to pass the user input as an argument or whatever to a function... It'll be useful after the user encounters a few monsters and bosses and whatnot.\n");
            //printf("-Hold the fuck up this is getting more and more complicated.. If I am going to be writing the same scenario again in another decision later on, this'll double the amount of code and the time to write it! There MUST be a way to join the both ends into the same route... I need to get out of the if statements.. Should we use goto/longjmp? I think so..");
            printf("-Add defense points too! Oh and have a multiplier for the attack powers! Like in pokémon, but simplified!! Your attack power will be multiplied by a random number between 0.5 and 1.0!!\n");
            printf("Added/fixed stuff:\n");
            printf("+Finally stopped using goto, I am using for loops instead now that for stopped being such a dick and started working...\n");
            printf("+Got rid of scanf, using fgets now.\n");
            printf("+Added sleep so that it waits between printing stuff!\n");
            printf("+Replaced every prompt with the new user_prompt() function\n");
            printf("This is all for now I guess. New ideas come by every now and then, which I'll note down here in this 'Easter Egg' :P.\n");

        }

        else if(strcmp(user_input, "test\n") == 0)
        {
            /* printf("Test input >> ");
             char char_name[255];
             fgets(player.name, 255,stdin); // but i dont understand... it worked before?? why doesn't it work now? i did literally nothing wrong
             printf("\n Input is %s", player.name); */ // the struct?? wtf what is wrong with you YOU FUCKING SON OF A BITCH JUST WORK ALREADY
            /*isInvalidInput = 0; // ends the do-while loop by setting the loop condition to false
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
            */
            /*user_prompt();
            if(strcmp(user_input, "tes\n") == 0)
            {
                printf("\nSuccess!");
            }*/
            /* // should these lines really stay? how many are they exactly.. around 60 lines of commented out test code, no harm for now... it's not even code, it's just comment so I'll let it stay.
                        user_prompt();
                        if(strcmp(user_input, "print\ goblin\n") == 0) // ugh i hate the space... why do i always forget the \n ? XD
                        {
                            basic_character_structure goblin;
                            goblin.attack_points = 10;
                            goblin.defense_points = 5;
                            goblin.health_points = 25;
                            goblin.name = "Goblin";
                            printf("\nEnemy name: %s\n", goblin.name);
                            printf("Enemy max. health: %d\n", goblin.health_points);
                            printf("Enemy Attack points: %d\n", goblin.attack_points);
                            printf("Enemy Defense Points: %d\n", goblin.defense_points);
                            return 0;
                        }
                        else if (strcmp(user_input, "print\ player\n") == 0)
                        {
                            basic_character_structure player;
                            player.name = "John";
                            player.attack_points = 10;
                            player.health_points = 100;
                            player.defense_points = 20;
                            printf("\nPlayer name: %s\n", player.name);
                            printf("Player AP: %d\n", player.attack_points);
                            printf("Player DP: %d\n", player.defense_points);
                            printf("Player HP: %d\n", player.health_points);
                            return 0;
                        }*/ // O- kay!! the structs are preeety much finished... this'll make my stuff easier. I just gotta add the mana in, and I'm done for now with the basic character structure I guess. I'll just do a few corrections and deprecations here and there... deprecate the current player variables and replace them with the struct ones, do corrections inside the game (player_defense -= 5; X player.defense_points -= 5; !)
            // Here's an idea.. don't erase the stuff you put in this chunk of code. Instead just comment them out, or put in goto statements and special commands which'll allow you to jump among testing grounds
            /*user_prompt();
             if(strcmp(user_input, "goblin\n") == 0)
             {
                 //user_input[strcspn(user_input,"\n")] = 0;

                 printf("Health is %d, name is %s", goblin.health_points, goblin.name);
                 // find a way to turn the entire input into lowercase already!! this is getting stressing...
             }*/
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
            sleep(3); // yup.. added in a newline to mountains.txt, now the sleep() issue is fixed. although it makes me wonder why it doesn't happen with other files...
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
    while(1);
    return 0;

}

void print_image(FILE * imagefile)
{
    char read_string[MAX_LEN];

    while(fgets(read_string,sizeof(read_string),imagefile) != NULL)
        printf("%s",read_string);
}
void user_prompt() // the only thing that's changed.
{
    printf(">||: ");
    fgets(user_input,255,stdin); // oh yeah... only for user_input, not character_name
    for (int i = 0; user_input[i]; i++)
    {
        user_input[i] = tolower(user_input[i]);
    }
} // and it doesnt even have to do with this!.. or does it? it does not apparently D:
/*
int user_prompt()
{
    static char user_input[255];
    printf("\n>||: ");                  To be used later on... needs a lot of refactoring for the code and I can't do that now
    fgets(user_input,255,stdin);
    printf("\n%s", user_input);


}*/
