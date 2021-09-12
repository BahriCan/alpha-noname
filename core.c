#include <stdio.h>
#include <string.h>

int main()
{
    int monster_alpha;
    int player_health;
    int punch_attack_power;
    char character_name[255];
    char special_character[1] = "[";
    // eh fuck it I'll just use an integer variable to define true or false values. 0-false, 1-true.
    int goblin_is_defeated = 0;
    monster_alpha = 15;
    player_health = 200;
    punch_attack_power = 5;

    printf("Welcome to the pre-alpha(?) version of <insert game name here>.\nCOPYRIGHT u/Bahrican798\n"); //you may not modify the source code, you can't fork it, you are only allowed to view it for the time being. LOLOLOL it has GPL v3 now, anyone can fork it, they have to return the changed code though :P
    printf("I know, it's not much, obviously. This is as much as I can get done in this environment...\n");
    char user_input[100];
    printf("===================================================\n");
    printf("\t\t TYPE \"Start\" TO PLAY\t\t\t\n");
    printf("===================================================\n");
    printf("  > ");
    scanf("%s", user_input);    // try fgets maybe... I'm tired. the if statements dont work... skips directly to else and returns 2.
   // printf("you wrote: %s", user_input); // although when checked in with printf, it seems that scanf reads everything, not just the first character only... I guess it does not store it as a variable then?
    if(strcmp(user_input, "Start") == 0) // FUCK YES FINALLY IT CAN START
    {
        // phew... almost lost all progress there, LiveOSes are a dangerous environment to do development on!
        printf("Choose your name, choose wisely for it can NOT be changed later on! Max. 255 characters: ");
        scanf("%s", character_name);
        printf("Your name is %s\n", character_name);
        printf("Welcome... to a new world.\n");
        printf("You're wondering around.\n");
        printf("You keep walking for hours on end.\n");
        printf("It's getting late...\n");
        printf("You stumble upon a little cave. Go inside? Y/n\n");
         // I need to find a way to print [], (), {}....
         // well making a string variable and putting '[' in it and printing it via printf %s IS an option... but not efficient. There MUST be a way to just print those characters without a hassle!
         // I gotta get some work done on this...
         // I better put it into the "to be done" section, I usually don't read comments.
        scanf("%s", user_input);
        if (strcmp(user_input, "Y") == 0 || strcmp(user_input, "\ ") == 0) // fuck how do I detect if the user just pressed enter, do I just not let them?
        {
            printf("debug is working fine\n");

        }
        return 0;
    }

    else if (strcmp(user_input, "easter") == 0) // Fuck man I can't put in spaces there... I'll figure that out later, I need to make a release now
    {
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
        printf("-Have a stamina that increases on a timer. I don't know how I'll implement that in a console game, I'll keep reading the book to see if there is something like waiting a few seconds, otherwise I'll set up a loop with while or for, and calculate the time that passes by, and increase the stamina variable that way.\n");
        printf("-Be able to learn new abilites.. Reminds me of M&L: Superstar Saga\n");
        printf("-Settings? Maybe? what would one want to change in this \"game\" anyway\n");
        printf("-The player will be able to see how much exp left to level up... I'm still considering this, it's possible but why should I let them?\n");
        printf("-Adventure/Story Mode, Free fighting mode. The free fighting will only allow you to battle with monster you've fought before. To determine that, I'll use boolean again... Damn I'm getting too dependent on boolean, and it doesn't even exist in C.\n");
        printf("-Give the user a limited amount of health potions to begin with.\n");
        printf("-Stats, probably. This one didn't go well apparently in C#. I'll attempt it here, what could go wrong? Let the user see their stats, health, exp, level etc.\n");
        printf("-Setting max values for stuff like player_health, if it exceeds it's max value, make it equal to it's max value again. Perhaps I'll use a separate, untouched variable for this called 'max_health'.\n");
        printf("-A start menu wouldn't be so bad, like the ncurses menus in shell scripts!\n");
        printf("-Let the user choose their character's name.\n");
        printf("-Send the user back to the prompt if they input something not related or whatever.\n");
        printf("-Add an option to save the game... I don't know how to do that, I'll do it but not today.\n");
        printf("- Make a function in a separate file, prototype this first in Python though. Some sort of a loop, a while loop, that'll take different values like how for or printf does. This loop will be used for fights. It'll be a barebones function, we'll fill in the blanks--- string to print out like 'You defeated the boss!', 'You used punch, you did 20 damage'--- ourselves.\n");
        printf("-Randomize monsters' attacks. They'll have various attacks that do different amounts of damage. Use a random number generator or something ;_;\n");
        printf("Find a way to printf the following character, it's in the source code. Here I'll even print it here, BUT this is a troublesome way to print out a '%s'.\n", special_character);
        printf("-Separate the source files\n");
        //printf("- DONT use goto! Apparently it's bad practice... find an alternative. Should be worth it, especially when you look at the old CS source code.. Damn that sure was one helluva spaghetti code.\n");
        printf("Added/fixed stuff:\n");
        printf("+Finally stopped using goto, I am using for loops instead now that for stopped being such a dick and started working...\n");
        printf("This is all for now I guess. New ideas come by every now and then, which I'll note down here in this 'Easter Egg' :P.\n");
        return 1;

    }
    else if(strcmp(user_input, "test") == 0)
    {
        for( ; monster_alpha > 0;) // I FUCKING HATE THE FOR STATEMENT IN C WHY DO I HAVE TO "iNItiaLiZE" SHIT I JUST WANNA GIVE A SINGLE CONDITION AND BE FUCKING DONE WITH IT
        // Oh nevermind ._. apparently I can just put in a semicolon and fuck off with it... why didn't work the first time I tried it though? I did the exact same thing..
        // this is pain
        // hold on, just a few more lines and we can release the pre-alpha version
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
    else
    {
        printf("Please type \"Start\" to play.\n");
        printf("I couldn't write something to send the user back to the prompt, sorry.."); // Well I COULD use goto... but this thing is about to evolve into a few thousand lines of code, doesn't feel right to use goto
        return 2;
    }

}
