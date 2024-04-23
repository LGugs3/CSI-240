/*
* Author: Liam Gugliotta
Class: CSI-240-04
Assignment: Final Project Part 4
Date Assigned: 04/05/2024
Due Date: 04/20/2024
Description:
Function definitions for doctorOperations.h file
Certification of Authenticity:
I certify that this is entirely my own work, except where I have given
fully-documented references to the work of others. I understand the definition and
consequences of plagiarism and acknowledge that the assessor of this assignment
may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic staff;
and/or
- Communicate a copy of this assignment to a plagiarism checking service (which may
then retain a copy of this assignment on its database for the purpose of future
plagiarism checking)
*/

#include "doctorOperations.h"

void displayClosestDoctors(Doctor doctors[], string partialName, int numberOfDoctor)
{
    const int MAX_CLOSEST = 3;
    int i, j, closeNum = 0;
    string closestMatches[MAX_CLOSEST], tempStr, docName;

    for (i = 0; i < numberOfDoctor; i++)
    {
        if (closeNum >= MAX_CLOSEST) { break; }

        //resetting string
        tempStr = "";
        docName = doctors[i].getName();
        if (partialName.length() > docName.length()) { break; }

        //adding new name
        for (j = 0; j < partialName.length(); j++)
        {
            tempStr += docName[j];
        }

        //checking for match
        if (tempStr == partialName)
        {
            closestMatches[closeNum] = docName;
            closeNum++;
        }
        if (closeNum >= MAX_CLOSEST) { break; }
    }

    //printing closest to console
    for (i = 0; i < MAX_CLOSEST; i++)
    {
        if (closestMatches[i] == "") { continue; }
        cout << closestMatches[i] << endl;
    }
}

/*Pre: array contains all the doctors, the number of doctors in the mentioned array, and the name to find
* Post: index of doctor name in array
* Purpose: To get the index of a specific doctor in the array
*/
int getDoctorIndex(Doctor doctors[], int numberOfDoctor, string doctorName)
{
    int i;
    for (i = 0; i < numberOfDoctor; i++)
    {
        if (doctors[i].getName() == doctorName)
        {
            return i;
        }
    }
    
    //the doctor name does not match any in the array
    return -1;
}

/*Pre: array contains all the doctors, the number of doctors in the mentioned array, and the name to find
* Post: bool if the doctor inputed in the array
* Purpose: to check to see if a specific doctor exists
*/
bool isDoctorExist(Doctor doctors[], int numberOfDoctor, string doctorName)
{
    int i;
    for (i = 0; i < numberOfDoctor; i++)
    {
        if (doctors[i].getName() == doctorName)
        {
            return true;
        }
    }
    
    return false;
}

/*Pre: doctor object to be turned into a dynamic array
* Post: dynamic array of doctors filled with data from file
* Purpose: to load data from file into array
*/
int loadDoctor(Doctor*& doctors)
{
    ifstream fin;
    fin.open(DOCTOR_FILE_NAME);
    if (fin.fail())
    {
        cerr << "doctor file failed to open" << endl;
        return -1;
    }

    stringstream ss;
    int numDoctors, i, index, numPatients;;
    string junk, name, id;
    getline(fin, junk);
    numDoctors = stoi(junk);

    doctors = new Doctor[numDoctors];

    for (i = 0; i < numDoctors; i++)
    {
        getline(fin, name);
        getline(fin, id);
        getline(fin, junk);
        ss.clear();
        ss.str(junk);
        ss >> index >> numPatients;

        //address and phone number are left empty b/c not in file
        doctors[i] = Doctor(id, name, "", "", index, numPatients);
    }
    fin.close();
    return 0;
}

string searchDoctor(Doctor doctors[], int numberOfDoctor)
{
    cout << "Enter Name: ";
    char ch;
    string docName;

    //adding search string
    while ((ch = getch()) != 13)
    {
        if (ch == 8)//backspace key
        {
            if (docName.length() == 0) { continue; }

            docName.erase(docName.end() - 1);//erases last character
        }
        else if (ch == 127)//delete key
        {
            continue;
        }
        else
        {
            docName += ch;
        }
        clearScreen();
        std::cout << "Enter SSN: " << docName << endl;

        displayClosestDoctors(doctors, docName, numberOfDoctor);
    }
    clearScreen();
    cout << "Enter Doctor Name: " << docName << endl;

    //searching for doctor
    if (isDoctorExist(doctors, numberOfDoctor, docName))
    {
        return docName;
    }
    else
    {
        return "empty";
    }


}

/*Pre: array of doctors, number of doctors in array
* Post: doctors in array printed to file
* Purpose: To store doctors in a file
*/
void storeDoctor(Doctor doctors[], int numberOfDoctor)
{
    ofstream ofs;
    if (std::filesystem::exists(DOCTOR_FILE_NAME))//if the file already exists, delete it
    {
        remove(DOCTOR_FILE_NAME.c_str());
    }

    ofs.open(DOCTOR_FILE_NAME);
    if (ofs.fail())
    {
        cerr << "Doctor file failed to open" << endl;
    }
    
    ofs << numberOfDoctor << endl;
    int i;
    for (i = 0; i < numberOfDoctor; i++)
    {
        //outputting doctor data into doctor file
        ofs << doctors[i].getName() << endl
            << doctors[i].getId() << endl
            << doctors[i].getIndex() << " "
            << doctors[i].getNumberOfPatient()
            << endl;

    }
    ofs.close();
}
