#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

struct Person
{
    char firstName[31];
    char familyName[31];
    int favnum;
} person;

bool exist(char *name)
{
    FILE *f = fopen(name, "rb");
    fclose(f);

    return !!f;
}

void readPerson()
{
    cout << "First name: ";
    gets(person.firstName);
    cout << "Family name: ";
    gets(person.familyName);
    cout << "Favorite number: ";
    cin >> person.favnum;
    getchar();
}

void clearPerson()
{
    person.favnum = 0;

    for (int i = 0; i < 31; i++)
    {
        person.familyName[i] = 0;
        person.firstName[i] = 0;
    }
}

void createFile(char *name)
{
    if (exist(name))
    {
        cout << "File exists" << endl;
        return;
    }

    FILE *f = fopen(name, "wb");
    fclose(f);
    cout << "File successfully created" << endl;
}

void delFile(char *name)
{
    if (!exist(name))
    {
        cout << 'File doesnt exist' << endl;
        return;
    }

    remove(name);
    cout << "File successfully deleted" << endl;
}

void addNumber(char *name)
{
    if (!exist(name))
    {
        cout << "File doesnt exist" << endl;
        return;
    }

    char contin = 'y';
    int number;
    FILE *f = fopen(name, "a+b");

    while (contin == 'y')
    {
        cout << "Number to add: ";
        cin >> number;
        getchar();

        fwrite(&number, sizeof(int), 1, f);

        cout << "Would you like to add another number? (y/n) ";
        contin = getchar();
        getchar();
    }

    fclose(f);
}

void removeNumber(char *name)
{
    if (!exist(name))
    {
        cout << "File doesnt exist" << endl;
        return;
    }

    FILE *f = fopen(name, "rb");
    FILE *fReplace = fopen("replace.dat", "w+b");
    char rem = 'y';
    int numberToRemove, number;

    while (!feof(f) || rem == 'y')
    {
        cout << "Number to remove: ";
        cin >> numberToRemove;
        getchar();

        fread(&number, sizeof(int), 1, f);
        if (number != numberToRemove)
        {
            fwrite(&number, sizeof(int), 1, fReplace);
        }

        if (!feof(f))
        {

            cout << "Would you like to remove another number? (y/n) ";
            rem = getchar();
            getchar();
        }
    }

    fclose(f);
    fclose(fReplace);
    remove(name);
    rename("replace.dat", name);
}

void showNumbers(char *name)
{
    if (!exist(name))
    {
        cout << "File doesnt exist" << endl;
        return;
    }

    FILE *f = fopen(name, "rb");
    int number, repeats = 0;

    fread(&number, sizeof(int), 1, f);
    while (!feof(f))
    {

        cout << number << endl;
        repeats++;
        fread(&number, sizeof(int), 1, f);
    }

    if (repeats == 0)
    {
        cout << "File is empty" << endl;
    }

    fclose(f);
}

void replaceNumber(char *name)
{
    if (!exist(name))
    {
        cout << "File doesnt exist" << endl;
        return;
    }

    char replace = 'y';
    int numberToReplace, number;

    while (replace == 'y')
    {
        cout << "Number to replace: ";
        cin >> numberToReplace;
        getchar();

        FILE *f = fopen(name, "rb");
        FILE *fReplace = fopen("replace.dat", "wb");

        int repeats = 0;

        fread(&number, sizeof(int), 1, f);
        while (!feof(f))
        {

            if (number == numberToReplace && repeats == 0)
            {
                cout << "Replace number with: ";
                cin >> number;
                getchar();
                repeats++;
            }
            fwrite(&number, sizeof(int), 1, fReplace);
            fread(&number, sizeof(int), 1, f);
        }

        if (repeats == 0)
        {
            if (number == numberToReplace)
            {
                cout << "Replace number with: ";
                cin >> number;
                getchar();
                fwrite(&number, sizeof(int), 1, fReplace);
            }
            else
            {

                cout << "No number was replaced" << endl;
            }
        }

        fclose(f);
        fclose(fReplace);
        remove(name);
        rename("replace.dat", name);

        cout << "Would you like to replace another number? (y/n) ";
        replace = getchar();
        getchar();
    }
}

int main()
{
    char play = 'y';
    char fileName[33];
    int funcNum;

    cout << "Enter file name: ";
    gets(fileName);
    strcat(fileName, ".dat");

    while (play == 'y')
    {
        cout << "Menu of functions" << endl
             << "1 - Create file" << endl
             << "2 - Delete file" << endl
             << "3 - Add number" << endl
             << "4 - Remove number" << endl
             << "5 - Show numbers" << endl
             << "6 - Replace number" << endl
             << "0 - Exit" << endl
             << "Choose function: ";

        cin >> funcNum;
        getchar();

        if (!funcNum)
            break;

        switch (funcNum)
        {
        case 1:
            createFile(fileName);
            break;
        case 2:
            delFile(fileName);
            break;
        case 3:
            addNumber(fileName);
            break;
        case 4:
            removeNumber(fileName);
            break;
        case 5:
            showNumbers(fileName);
            break;
        case 6:
            replaceNumber(fileName);
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