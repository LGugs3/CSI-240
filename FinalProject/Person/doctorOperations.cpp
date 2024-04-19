
#include "doctorOperations.h"

/*Pre: array contains all the doctors, the number of doctors in the mentioned array, and the name to find
* Post: index of doctor name in array
* Purpose: To get the index of a specific doctor in the array
*/
int getDoctorIndex(Doctor doctors[], int numberOfDoctor, string doctorName)
{
    int i;
    for (i = 0; i < numberOfDoctor; i++)
    {
        if (doctors[i] == doctorName)
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
        if (doctors[i] == doctorName)
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
