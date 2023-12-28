#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

struct Plant
{
    char type[10];

    float age, weight, height;
} plant;

const int maxPlantCount = 10;
Plant plants[maxPlantCount];
int plantCount = 0;

void readPlant()
{
    cout << "Plant type: ";
    gets(plant.type);
    cout << "Plant age (yrs): ";
    cin >> plant.age;
    cout << "Plant weight (g): ";
    cin >> plant.weight;
    cout << "Plant height (cm): ";
    cin >> plant.height;
    getchar();
}

void clearPlant(Plant *plant)
{
    plant->age = 0;
    plant->weight = 0;
    plant->height = 0;

    for (int i = 0; i < 10; i++)
    {
        plant->type[i] = 0;
    }
}

void addPlant()
{
    char play = 'y';

    while (plantCount < maxPlantCount && play == 'y')
    {
        readPlant();

        plants[plantCount].age = plant.age;
        plants[plantCount].height = plant.height;
        plants[plantCount].weight = plant.weight;
        strcpy(plants[plantCount].type, plant.type);

        plantCount++;

        cout << "Would you like to add another plant? (y/n) ";
        play = getchar();
        getchar();
    }

    if (plantCount == 10)
    {
        cout << "Maximum amount of plants reached, " << maxPlantCount << " is the max." << endl;
    }
    clearPlant(&plant);
}

void delPlant()
{
    char play = 'y';
    char plantType[10];
    int repetitions = 0;

    while (plantCount > 0 && play == 'y')
    {

        cout << "Plant type to delete: ";
        gets(plantType);

        for (int i = 0; i < plantCount; i++)
        {
            if (strcmp(plants[i].type, plantType) == 0)
            {
                clearPlant(&plants[i]);
                plantCount--;
            }
            repetitions++;
        }
        if (repetitions == 0)
        {
            cout << "No such plant was found" << endl;
        }
        else
        {
            cout << plantType << " was deleted." << endl;
        }

        repetitions = 0;

        cout << "Would you like to delete another plant? (y/n) ";
        play = getchar();
        getchar();
    }

    if (plantCount == 0)
    {
        cout << "There are no plants left" << endl;
    }
}

void showPlants()
{
    for (int i = 0; i < plantCount; i++)
    {
        cout << "Plant " << (i + 1) << ":"
             << " Type - " << plants[i].type
             << " | age - " << plants[i].age
             << "y | height - " << plants[i].height
             << "cm | weight - " << plants[i].weight << "g" << endl;
    }

    if (plantCount == 0)
    {
        cout << "There are no plants" << endl;
    }
}

void tallerThanMeter()
{
    int tallerThanMeterCount = 0;

    for (int i = 0; i < plantCount; i++)
    {
        if (plants[i].height > 100)
            tallerThanMeterCount++;
    }

    if (plantCount == 0)
    {
        cout << "There are no plants" << endl;
    }
    else
    {
        float percent = 100 / ((float)plantCount / tallerThanMeterCount);
        cout << fixed << setprecision(2) << percent << "\% of plants are taller than 1m" << endl;
    }
}

int main()
{
    int funcNum;
    char play = 'y';

    while (play == 'y')
    {

        cout << "Menu of functions" << endl
             << "1 - Add plant" << endl
             << "2 - Delete plant" << endl
             << "3 - Show plants" << endl
             << "4 - Percent of plants taller than 1m" << endl
             << "0 - Exit" << endl;

        cout << "Choose function: ";
        cin >> funcNum;
        getchar();

        if (funcNum == 0)
            break;

        switch (funcNum)
        {
        case 1:
            addPlant();
            break;
        case 2:
            delPlant();
            break;
        case 3:
            showPlants();
            break;
        case 4:
            tallerThanMeter();
            break;
        default:
            break;
        }

        cout << "Would you like to continue? (y/n) ";
        play = getchar();
        getchar();
    }

    return 0;
}