#include <iostream>
#include <string>

using namespace std;

struct Speaker
{
    string name;
    string telephoneNumber;
    string topic;
    double feeRequired;
};

void inputSpeakers(Speaker members[], int size, int& numSpeakers);
void updateSpeakers(Speaker members[], int numSpeakers, const string& speakerName);
void displaySpeakerInfo(const Speaker members[], const int numSpeakers, const string& speakerName);
void displayTopicsBySpeakers(const Speaker members[], int numSpeakers, const string& speakerTopic);
void displayAllSpeakers(const Speaker members[], const int numSpeakers);

//****************************************************************************************************

int main ()
{
    const int MAX_SPEAKER = 10;
    int numSpeaker = 0;
    Speaker* speakers = new Speaker[MAX_SPEAKER];
    string speakerName;
    string speakerTopic; 

    inputSpeakers(speakers, MAX_SPEAKER, numSpeaker);

    cout << "Enter the Name of the Speaker you wish to change: ";
    getline(cin, speakerName);
    updateSpeakers(speakers, numSpeaker, speakerName);

    cout << "Enter the Name of the Speaker you wish to retrieve information from: ";
    getline(cin, speakerName);
    
    displaySpeakerInfo(speakers, numSpeaker, speakerName);

    cout << "\nEnter the Specific Topic: ";
    getline(cin, speakerTopic);
    cout << endl;
    
    displayTopicsBySpeakers(speakers, numSpeaker, speakerTopic);

    cout << endl;
    cout << "Information of All Speakers\n";
    displayAllSpeakers(speakers, numSpeaker);

    delete[] speakers;

    return 0;
}

//****************************************************************************************************

void inputSpeakers(Speaker members[], int size, int& numSpeakers)
{
    bool feeValidity = false;

    for (int i = 0; i < size; i++)
    {
        cout << "Enter the Data for Speaker #" << numSpeakers + 1 << endl;

        cout << "Name: ";
        getline(cin, members[i].name);

        cout << "Telephone Number: ";
        getline(cin, members[i].telephoneNumber);

        cout << "Topic: ";
        getline(cin, members[i].topic);

        do 
        {
            cout << "Fee Required: ";
            cin >> members[i].feeRequired;

            if (members[i].feeRequired < 0)
            {
                cout << "Fee cannot be negative. Please try again." << endl;
            }
            else
            {
                feeValidity = true;
            }
        } 
        while (!feeValidity);

        cin.ignore();

        numSpeakers++;
        cout << endl;
    }
}

void updateSpeakers(Speaker members[], int numSpeakers, const string& speakerName)
{
    char choice;
    bool speakerFound = false;
    for (int i = 0; i < numSpeakers; i++)
    {
        if (members[i].name == speakerName)
        {
            speakerFound = true;
            cout << "New information is required for the speaker: " << speakerName << endl;

            cout << "Update Telephone Number? (Y/N): ";
            cin >> choice;

            cin.ignore();

            if (choice == 'Y' || choice == 'y')
            {
                cout << "Telephone Number: ";
                getline(cin, members[i].telephoneNumber);
            }

            cout << "Update Topic? (Y/N): ";
            cin >> choice;

            cin.ignore();

            if (choice == 'Y' || choice == 'y')
            {
                cout << "Topic: ";
                getline(cin, members[i].topic);
            }
            cout << "Update Fee Required? (Y/N): ";
            cin >> choice;

            cin.ignore();

            if (choice == 'Y' || choice == 'y')
            {
                do
                {
                    cout << "Fee Required: ";
                    cin >> members[i].feeRequired;

                    if (members[i].feeRequired < 0)
                    {
                        cout << "Fee cannot be negative. Please try again." << endl;
                    }
                } 
                
                while (members[i].feeRequired < 0);
            }

            cin.ignore();
        }
    }

    if (!speakerFound)
    {
        cout << "The Speaker: " << speakerName << " was invalid.\n\n";
    }

    cout << endl;
}

void displaySpeakerInfo(const Speaker members[], const int numSpeakers, const string& speakerName)
{
    bool found = false;

    for (int i = 0 ; i < numSpeakers; i++)
    {
        if (members[i].name == speakerName)
        {
            cout << "Information on the Speaker: " << endl;
            cout << "Name: " << members[i].name << endl;
            cout << "Telephone Number: " << members[i].telephoneNumber << endl;
            cout << "Topic: " << members[i].topic << endl;
            cout << "Fee Required: " << members[i].feeRequired << endl << endl;

            found = true;
        }
    }

    if(!found)
    {
        cout << "\nSpeaker: " << speakerName << " was not found.\n";
    }
}

void displayTopicsBySpeakers(const Speaker members[], int numSpeakers, const string& speakerTopic)
{
    bool found = false;
    int counter = 0;
    
    cout << "Speakers with common topics on " << speakerTopic << ":\n";

    for (int i = 0; i < numSpeakers; i++) 
    {
        if (members[i].topic == speakerTopic) 
        {
            cout << "Speaker[" << counter + 1 << "] " << endl;
            cout << "Speaker Name: " << members[i].name << endl;
            cout << "Telephone Number: " << members[i].telephoneNumber << endl;
            cout << "Topic: " << members[i].topic << endl;
            cout << "Fee Required: $" << members[i].feeRequired << endl;
            cout << endl;
            found = true;
            counter++;
        }
    }

    if (!found) {
        cout << "No speakers found for topic '" << speakerTopic << "'." << endl << endl;
    }
}

void displayAllSpeakers(const Speaker members[], const int numSpeakers)
{
    for (int i = 0; i < numSpeakers; i++)
    {
        cout << "Information on Speaker[" << i + 1 << "]: " << endl;
        cout << "Name: " << members[i].name << endl;
        cout << "Telephone Number: " << members[i].telephoneNumber << endl;
        cout << "Topic: " << members[i].topic << endl;
        cout << "Fee Required: " << members[i].feeRequired << endl << endl;
    }
}

/*

Enter the Data for Speaker #1
Name: Kyrie Irving
Telephone Number: 392-509-9123
Topic: Basketball
Fee Required: 999.99

Enter the Data for Speaker #2
Name: Michael Jordan
Telephone Number: 293-592-5690
Topic: Basketball
Fee Required: 999.99

Enter the Data for Speaker #3
Name: Bill Nye
Telephone Number: 239-192-5913
Topic: Solar System 
Fee Required: 579.99

Enter the Data for Speaker #4
Name: Michael Jackson
Telephone Number: 935-023-5913
Topic: Singing & Dancing
Fee Required: 299.99

Enter the Data for Speaker #5
Name: Serah Smith
Telephone Number: 329-595-1905
Topic: Raw Milk
Fee Required: 249.99

Enter the Data for Speaker #6
Name: Greta Thundberg
Telephone Number: 679.99
Topic: Climate Change
Fee Required: 239-950-1931

Enter the Data for Speaker #7
Name: Small Pox
Telephone Number: 239-590-3091
Topic: Chicken Soup
Fee Required: 149.99

Enter the Data for Speaker #8
Name: Jimmy Johns
Telephone Number: 291-039-9999
Topic: Pizza
Fee Required: 759.99

Enter the Data for Speaker #9
Name: Mark Zucky
Telephone Number: 291-904-9103
Topic: Social Media
Fee Required: 979.99

Enter the Data for Speaker #10
Name: Henry Quinton
Telephone Number: 291-035-9183
Topic: Presidential Election
Fee Required: 929.99

Enter the Name of the Speaker you wish to change: Greta Thundberg
New information is required for the speaker: Greta Thundberg
Update Telephone Number? (Y/N): Y
Telephone Number: 239-950-1931
Update Topic? (Y/N): n
Update Fee Required? (Y/N): y
Fee Required: 679.99

Enter the Name of the Speaker you wish to retrieve information from: Bill Nye
Information on the Speaker: 
Name: Bill Nye
Telephone Number: 239-192-5913
Topic: Solar System
Fee Required: 579.99


Enter the Specific Topic: Basketball

Speakers with common topics on Basketball:
Speaker[1] 
Speaker Name: Kyrie Irving
Telephone Number: 392-509-9123
Topic: Basketball
Fee Required: $999.99

Speaker[2] 
Speaker Name: Michael Jordan
Telephone Number: 293-592-5690
Topic: Basketball
Fee Required: $999.99


Information of All Speakers
Information on Speaker[1]: 
Name: Kyrie Irving
Telephone Number: 392-509-9123
Topic: Basketball
Fee Required: 999.99

Information on Speaker[2]:
Name: Michael Jordan
Telephone Number: 293-592-5690
Topic: Basketball
Fee Required: 999.99

Information on Speaker[3]:
Name: Bill Nye
Telephone Number: 239-192-5913
Topic: Solar System
Fee Required: 579.99

Information on Speaker[4]:
Name: Michael Jackson
Telephone Number: 935-023-5913
Topic: Singing & Dancing
Fee Required: 299.99

Information on Speaker[5]:
Name: Serah Smith
Telephone Number: 329-595-1905
Topic: Raw Milk
Fee Required: 249.99

Information on Speaker[6]:
Name: Greta Thundberg
Telephone Number: 239-950-1931
Topic: Climate Change
Fee Required: 679.99

Information on Speaker[7]:
Name: Small Pox
Telephone Number: 239-590-3091
Topic: Chicken Soup
Fee Required: 149.99

Information on Speaker[8]:
Name: Jimmy Johns
Telephone Number: 291-039-9999
Topic: Pizza
Fee Required: 759.99

Information on Speaker[9]:
Name: Mark Zucky
Telephone Number: 291-904-9103
Topic: Social Media
Fee Required: 979.99

Information on Speaker[10]:
Name: Henry Quinton
Telephone Number: 291-035-9183
Topic: Presidential Election
Fee Required: 929.99


*/