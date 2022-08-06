#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct class{  //struct b/c each class has mult. traits
    char classname [50];
    int health;
    int money;
    char weapons[2][20]; //2D array for choosing a weapons
};

struct character{ //struct b/c character has mult. traits
    char name[50];
    int health;
    int money;
    char weapon[20];
    struct class *class; //making it a pointer to a structure saves space/memory
};

void choose_warrior(char a); //list of functions
char lowercase_string (char a[50]);
void forest();
void add_class(struct character *a, struct class *b); //func. w/ struct pointer argument
void choose_weapon(char a);
void stats();
void fight_dragon();
void dodge_dragon();
void win_game();

struct character player;
struct class wizard={"wizard", 150, 150, {{"wand"}, {"spellbook"}}};
struct class knight={"knight", 200, 100, {{"sword"}, {"axe"}}};
struct class assassin={"assassin", 80, 300,{{"dagger"}, {"chain"}}};
struct class monk={"monk", 200, 100, {{"karate"}, {"taekwondo"}}};


int main() //function that compiles and runs (hello-world concept)
{
    char warrior_choice='\0';
    char path_choice[10]={'\0'};
    printf("In the ancient Kingdom of Dressrosa, the adored Princess has been kidnapped by a dragon from afar.\n"
           "The King has sent out a message across his kingdom to find a brave adventurer who has the might to save the princess.\n"
           "'My brave warriors, the journey to fight the dragon and save the princess will be difficult, but rewarding.\n"
           "If you bring the Princess back home safely, you will be rewarded with a handsome amount of 10,000 doubloons.'\n");
    printf("\n");

    printf("Narrator: You have the choice of being 1 of the 4 warriors: a)Knight b)Assassin c)Wizard d)Monk\n"
           "Each character has a varying amount of health and doubloons (currency necessary for survival).\n"
           "You must decide carefully.\n");
    printf("\n");

    while (warrior_choice != 'a' && warrior_choice != 'b' &&  warrior_choice != 'c' && warrior_choice != 'd')
    {
        printf("Please press a,b,c, or d: ");
        scanf("%c", &warrior_choice); //note: if i enter more than one string, takes one character as an input at a time
        warrior_choice=tolower(warrior_choice);
        getchar(); //gets rid of newline
    }
    choose_warrior(warrior_choice);

    printf("Narrator: The King has heard of the good news that you will journey to rescue his daugther and has summoned you to his castle.\n");
    printf("\n");
    printf("King: My dear warrior, I give you honor and respect for being brave enough to go on this difficult journey.\n"
           "What is your name? ");

    scanf("%s", player.name);

    printf("\n");
    printf("It is my pleasure to meet you ");
    printf("%s.\n", player.name);
    printf("There will be many times when you face death, but if you bring my beloved daughter back safely, you will not only be rewarded handsomely but be named the hero of Dressrosa.\n"
           "Before you go, my prophet has warned me that you will need at least 100 doubloons to enter the city that the dragon lies in and at least 100 health points to fight off the dragon.\n"
           "May luck be with you.\n");
    printf("\n");

    printf("Narrator: The journey will be through a dangerous forest. Would you like to turn back or start the journey? (This is your last warning.)\n");

    while (strcmp(path_choice,"start")!= 0 && strcmp(path_choice, "turn")!=0) //only answer = either start or turn
    {
        printf("Please enter 'start' or 'turn': ");
        scanf("%s", path_choice);
        lowercase_string(path_choice);
    }

    if (strcmp(path_choice,"start")==0) // if start
    {
        printf("You have chosen to journey through the frightening forest.\n");
        printf("\n");
        forest();
    }
    else //else has to be turn
    {
        printf("\n");
        printf("You have chosen to turn back and stay safe.\n");
        printf("The princess was later eaten by dragon.\n");
        printf("Mission Failed.\n");
        return 0;
    }
    enter_city();
    fight_dragon(); //func. can only be reached if entered city
    win_game(); //func. can only be reached if defeated dragon

    return 0;
}

void choose_warrior(char a)
{
    if (a == 'a') { //if, else if, else statement to choose specific class for character
        printf("You have chosen to be a Knight.\n");
        add_class(&player, &knight);
        printf("\n");
        printf("Here are the attributes of a Knight.\n");
        stats();
    } else if (a == 'b') {
        printf("You have chosen to be an Assassin.\n");
        add_class(&player, &assassin);
        printf("\n");
        printf("Here are the attributes of an Assassin.\n");
        stats();
    } else if (a == 'c') {
        printf("You have chosen to be a Wizard.\n");
        add_class(&player, &wizard);
        printf("\n");
        printf("Here are the attributes of a Wizard.\n");
        stats();
    } else { // the only other possible option after filtering out to leave 4 possible words
        printf("You have chosen to be a Monk.\n");
        add_class(&player, &monk);
        printf("\n");
        printf("Here are the attributes of a Monk.\n");
        stats();
    }
    choose_weapon(a); //assigns a weapon depending on class type
    printf("\n");
}

void choose_weapon(char a)
{
    char weapon[20];
    int decision=0; //for specifying weapon in array

    if (a == 'a')
    { //since same conditions for choose_warrior func, already set it up for this (already filtered for a,b,c,d and assigned class)
        printf("A Knight can choose one of two weapons: sword or axe.\n");
        while (strcmp(weapon,"sword")!=0 && strcmp(weapon,"axe")!=0) //asnwer can only be sword or axe
        {
            printf("Please enter 'sword' or 'axe': ");
            scanf("%s", weapon);
            lowercase_string(weapon);
        }
        if (strcmp(weapon,"sword")==0) {
            decision = 0;
        }
        else // only other choice is axe
        {
            decision =1;
        }
        printf("You chose ");
        printf("%s.\n", player.class->weapons[decision]); //already set up from prev func

        for(int i= 0; i < strlen(player.class->weapons[decision]); i++) {
            player.weapon[i] = player.class->weapons[decision][i];

        }
    }
    else if (a=='b')
    {
        printf("An Assassin can choose one of two weapons: dagger or chain.\n");
        while (strcmp(weapon,"dagger")!=0 && strcmp(weapon,"chain")!=0)
        {
            printf("Please enter 'dagger' or 'chain': ");
            scanf("%s", weapon);
            lowercase_string(weapon);
        }
        if (strcmp(weapon,"dagger")==0) {
            decision = 0;
        }
        else
        {
            decision =1;
        }
        printf("You chose ");
        printf("%s.\n", player.class->weapons[decision]);

        for(int i= 0; i < strlen(player.class->weapons[decision]); i++) {
            player.weapon[i] = player.class->weapons[decision][i];
        }
    }
    else if (a=='c')
    {
        printf("A Wizard can choose one of two weapons: wand or spellbook.\n");
        while (strcmp(weapon,"wand")!=0 && strcmp(weapon,"spellbook")!=0)
        {
            printf("Please enter 'wand' or 'spellbook': ");
            scanf("%s", weapon);
            lowercase_string(weapon);
        }
        if (strcmp(weapon,"wand")==0) {
            decision = 0;
        }
        else
        {
            decision =1;
        }
        printf("You chose ");
        printf("%s.\n", player.class->weapons[decision]);

        for(int i= 0; i < strlen(player.class->weapons[decision]); i++) {
            player.weapon[i] = player.class->weapons[decision][i];
        }
    }
    else
    {
        printf("A monk can choose one of two fighting skills: karate or taekwondo.\n");
        while (strcmp(weapon,"karate")!=0 && strcmp(weapon,"taekwondo")!=0)
        {
            printf("Please enter 'karate' or 'taekwondo': ");
            scanf("%s", weapon);
            lowercase_string(weapon);
        }
        if (strcmp(weapon,"karate")==0) {
            decision = 0;
        }
        else
        {
            decision =1;
        }
        printf("You chose ");
        printf("%s.\n", player.class->weapons[decision]);

        for(int i= 0; i < strlen(player.class->weapons[decision]); i++) {
            player.weapon[i] = player.class->weapons[decision][i];
        }
    }
}

char lowercase_string (char a[50])
{
    int i;
    for (i=0; i<strlen(a); i++)
    {
        a[i]=tolower(a[i]);
    }
    return *a;
}

void add_class(struct character *a, struct class *b) //pointer to actually change it
{
    a->class = b; //pointer class = specific struct class
    a->money = b->money;
    a->health=b->health; //class's health and money become character's health and money
}

void stats() //made into func b/c displayed often
{
    printf("Health: ");
    printf("%d points\n", player.health);
    printf("Money: ");
    printf("%d doubloons\n", player.money);
}

void enter_city()
{
    printf("You have finally reached the city that the dragon lies in.\n"
           "However, you are stopped at the gate into the city by a guard.\n"
           "Guard: The entrance fee into the city is 100 doubloons. No trespassers will be allowed.\n");
    printf("\n");

    printf("Narrator: You currently have ");
    printf("%d", player.money);
    printf(" doubloons.\n");

    if (player.money<100)
    {
        printf("\n");
        printf("Sorry, you do not have enough doubloons. You must journey back to Dressrosa.\n");
        printf("Mission Failed.\n");
        exit(0);
    }
    else
    {
        printf("You have enough money to pass. You have paid the fee.\n");
        player.money-=100;
        printf("You now have ");
        printf("%d", player.money);
        printf(" doubloons.\n");
        printf("\n");
    }
}

void fight_dragon()
{
    int x=0;
    char hit='a'; // initialized to non 'x' character
    printf("Narrator: With the directions given by the villagers, you were able to find the path to the dragon's lair.\n"
           "You have now finally reached the dragon and the princess.\n"
           "You slowly walk into the lair and see the princess trapped in a prison cell while the dragon is sleeping next to it.\n"
           "The princess sees you and whispers...\n"
           "Princess: My hero, thank you for coming to save me. I cannot wait to go back home!\n"
           "You attempt to reach for the key behind the dragon, but you accidentally drop it.\n"
           "The dragon hears the drop and opens its eyes ...\n");
    printf("\n");
    printf("Dargon: Who dare come into my lair! Anyone who tries to take the princess will pay with their life!\n"
            "You and the dragon start fighting.\n");
    printf("\n");
    printf("To defeat him, you must hit him 15 times by entering the letter 'x' 15 times.\n");
    printf("\n");

    do {
        printf("You have hit the dragon ");
        printf("%d", x);
        printf(" times.\n");
        printf("Enter 'x': ");
        scanf("%c", &hit);
        hit=getchar();

        while (hit != 'x') //not typing in x = missing hit; nested while loop to filter out non 'x' inputs
        {
            printf("You missed the hit. Try again!\n");
            printf("Enter 'x': ");
            scanf("%c", &hit);
            hit=getchar();
        }

        if (x==8)
        {
            printf("Narrator: The dragon is breathing fire now! ");
            printf("You must dodge the fire by entering 'dodge' 3 times!\n");
            dodge_dragon();
        }

        x++;
    } while (x < 15);
    printf("You have hit the dragon 15 times.\n"); //simple way around do-while annoyance
    printf("\n");
    printf("You are standing your ground, but the dragon is a formidable opponent.\n"
            "The dragon gives you a 50 points of health damage.\n");
    printf("\n");

    player.health-=50;
    printf("Your health is at ");
    printf("%d points.\n", player.health);
    printf("\n");

    if(player.health>100) {
        printf("You have won the battle and slain the dragon!\n"
               "You successfully unlock the princess's prison cell.\n");
        printf("\n");
        printf("Princess: Oh, thank you so much my brave warrior. What is your name?\n");
        printf("Narrator: You tell her your name.\n");
        printf("\n");
        printf("Princess: My dear ");
        printf("%s", player.name);
        printf(", you are my hero. Words cannot express my gratitude.\n");
        printf("\n");
    }
    else
    {
        printf("You were defeated by the dragon.\n");
        printf("Mission Failed.\n");
        exit(0);
    }
}

void dodge_dragon()
{
    int i=0;
    char dodge[20];

    while(i<3)
    {
        printf("Enter 'dodge': \n");
        scanf("%s", dodge);
        lowercase_string(dodge);

        while (strcmp(dodge,"dodge")!=0)
        {
            printf("You couldn't dodge the hit!\n"
                   "You lost 10 health points!\n");
            player.health-=10;
            printf("Your health is at ");
            printf("%d points.\n", player.health);
            printf("\n");

            if (player.health<=0) //checks if player's alive
            {
                printf("Narrator:Your health has run out.\n"
                       "You have lost to the dragon!\n"
                       "Mission Failed.\n");
                exit(0);
            }

            printf("Please enter 'dodge': ");
            scanf("%s", dodge);
            lowercase_string(dodge);
        }
        i++;
    }
    printf("You successfully dodged all the dragon's fire attacks!\n");

}

void win_game()//only runs if you have won
{
    printf("Narrator: You have brought the princess home.\n"
           "The King has thrown a celebration, with you as the Hero of Dressrosa.\n");
    printf("\n");
    printf("King: Thank you ");
    printf("%s ", player.name);
    printf("for saving my daughter!\n");
    printf("You will now be known as the kingdom's hero!\n"
           "And I did not forget about your reward!\n"
           "Have some health potions to heal and here are your 10,000 doubloons!\n");
    printf("\n");
    player.health+=500;
    player.money+=10000;
    printf("Narrator: You have gained 500 health points and 10,000 doubloons.\n");
    printf("\n");
    printf("Here are your end stats: \n");
    stats();
    printf("\n");
    printf("Congratulations! You have won the game!\n");
    printf("Mission Successful!");
    exit(0);
}

void forest() {
    int i, x = 0; //counters
    char guess[20];
    char hit = 'a'; // initialized to non 'x' character
    printf("As you are walking along, a gnome pops out of the ground and says you cannot pass until you answer his riddle.\n");
    printf("Gnome: I am tall when I am young, and I am short when I am old. What am I?\n");
    printf("You have 3 attempts. Each time you guess wrong, I will take away 10 doubloons.\n");
    printf("\n");

    for (i = 0; i < 3; i++) //chose for loop b/c we can choose number of times it iterates; don't want player to lose all their money
    {
        printf("Guess: ");
        scanf("%s", guess);

        if (strcmp(guess, "candle") == 0)
        {
            printf("\n");
            printf("Gnome: You have correctly guessed it.\n");
            printf("Here have some health potions and doubloons.\n");
            printf("You have gained +50 health and +40 doubloons and are allowed to pass.\n");
            printf("\n");
            player.health += 50;
            player.money += 40;
            break;
        } else {
            if (i == 2) {
                printf("As I thought, you have lost! It's a candle!\n");
                player.money -= 10; // do it here bc breaks out
                break;
            }
            printf("You humans are idiots! Guess again!\n");
            player.money -= 10; //taking away 10 doubloons each time
            stats(); //printing stats after each loss
        }
    }

    printf("Here are the current stats: \n"); //show stats after gnome
    stats();
    printf("\n");

    printf("Narrator: You survived the Gnome!\n"
           "You have almost reached the city of the dragon.\n");
    printf("\n");
    printf("However, you feel uneasy all of a sudden.\n"
           "A cyclops appears in front of you and starts attacking!\n"
           "To defeat him, you must hit him 10 times by entering the letter 'x' 10 times.\n");
    printf("\n");

    do { //do while loop to show that at first, no hits have been made
        printf("You have hit the cyclops ");
        printf("%d", x);
        printf(" times.\n");
        printf("Enter 'x': ");
        scanf("%c", &hit);
        hit=getchar();

        while (hit != 'x') //not typing in x = missing hit
        {
            printf("You missed the hit. Try again!\n");
            printf("Enter 'x': ");
            scanf("%c", &hit);
            hit=getchar();
        }

        x++;
    } while (x < 10);
    printf("You have hit the cyclops 10 times.\n"); //simple way around do-while annoyance
    printf("\n");

    if (strcmp(player.weapon, "sword") == 0 ||
        strcmp(player.weapon, "dagger") == 0 ||
        strcmp(player.weapon, "wand") == 0 ||
        strcmp(player.weapon, "karate") == 0) //4 weapons that can defend against cyclops
    { //if one true, condition true
        printf("Your ");
        printf("%s", player.weapon); //all first elements
        printf(" was able to successfully defeat the cyclops!\n");
        printf("You lost no health and gained 20 doubloons.\n");

        player.money+=20;

        printf("Here are your current stats: \n");
        stats();

    } else // rest 4 weapons are losing weapons
    {
        printf("Your ");
        printf("%s", player.weapon); // need to specify 2nd elements b/c referring to class not an actual characteristic of player
        printf(" was not strong enough to defeat the cyclops...\n");
        printf("However, you were able to successfully run away.\n"
               "You lost 10 health points and 20 doubloons.\n");
        printf("\n");

        player.health-=10;
        player.money-=20;

        printf("Here are your current stats: \n");
        stats();
        printf("\n");
    }
}