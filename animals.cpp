#include <iostream>
#include "windows.h"
using namespace std;

struct entity
{
    int speed;
    char type[20];
    char color[20];

    // feature

    bool isHuman;
    bool isAnimal;
    bool isBird;

    float flightSpeed;
    bool artiodactyl;
    int iq;

    void GiveSpeed()
    {
        cout << "Enter entitie's speed: ";
        cin >> speed;
    }

    void GiveType()
    {
        cout << "Enter entitie's type: ";
        cin >> type;
    }

    void GiveColor()
    {
        cout << "Enter entitie's color: ";
        cin >> color;
    }


    // give feature
    void GiveFlightSpeed()
    {
        cout << "Enter entitie's flight speed: ";
        cin >> flightSpeed;
    }
  
    void GiveArtiodactyld()
    {
        cout << "Enter entitie's artiodactyl: ";
        cin >> artiodactyl;
    }

    void GiveIQ()
    {
        cout << "Enter entitie's IQ: ";
        cin >> iq;
    }

    // prints
    void PrintHuman()
    {
        cout << "type: " << type << endl;
        cout << "color of human: " << color << endl;
        cout << "speed of human: " << speed << endl;
        cout << "iq of human: " << iq << endl;
    }

    void PrintBird()
    {
        cout << "type: " << type << endl;
        cout << "color of bird: " << color << endl;
        cout << "speed of bird: " << speed << endl;
        cout << "flight speed of bird: " << flightSpeed << endl;
    }

    void PrintAnimal()
    {
        cout << "type: " << type << endl;
        cout << "color of animal: " << color << endl;
        cout << "speed of animal: " << speed << endl;
        cout << "Is artiodactyl: " << artiodactyl << endl;
    }

};


void WhatsType(entity structure);
void EditEntity(entity creatures[3]);
void SearchEntity(entity structure);

int main()
{
    entity Alex{};
    entity Cow{};
    entity Crow{};
    entity creatures[3] = {Alex, Cow, Crow};


    for (int i = 0; i < 3; i++)
    {
        creatures[i].GiveSpeed();
        creatures[i].GiveType();
        creatures[i].GiveColor();
        WhatsType(creatures[i]);
        Sleep(500);
        system("cls");
    }
   
    entity* ptr_creatures = creatures;
    EditEntity(ptr_creatures);

    int SearchValue;
    cout << "Enter creature to find it ( Alex - 1, Cow - 2, Crow - 3): ";
    cin >> SearchValue;
    SearchEntity(creatures[SearchValue - 1]);
}


void SearchEntity(entity structure)
{
    if (structure.isHuman)
    {
        structure.PrintHuman();
    }

    else if (structure.isAnimal)
    {
        structure.PrintAnimal();
    }

    else if (structure.isBird)
    {
        structure.PrintBird();
    }
}

void EditEntity(entity creatures[3])
{
    int numOfCreatures;
    cout << "Enter creature to edit it ( Alex - 1, Cow - 2, Crow - 3): ";
    cin >> numOfCreatures;

    numOfCreatures -= 1;

    creatures[numOfCreatures].GiveSpeed();
    creatures[numOfCreatures].GiveType();
    creatures[numOfCreatures].GiveColor();

    WhatsType(creatures[numOfCreatures]);
}

void WhatsType(entity structure)
{
    if (strcmp(structure.type, "human") == 0)
    {
        structure.GiveIQ();
        structure.PrintHuman();
        structure.isHuman = true;
    }

    else if (strcmp(structure.type, "animal") == 0)
    {
        structure.GiveArtiodactyld();
        structure.PrintAnimal();
        structure.isAnimal = true;
    }

    else if (strcmp(structure.type, "bird") == 0)
    {
        structure.GiveFlightSpeed();
        structure.PrintBird();
        structure.isBird = true;
    }
}

