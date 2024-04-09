//  filename:  person.cpp

/*
Author:  Wei Kian Chen
Class:  CSI-240-04
Assignment: Final Project - Part 2
Date Assigned: April 5, 2024
Due Date: April 12, 2024

Description:
  Simulating a database for clinic.

  The purpose of this file is to define the Person class


Disclaimer:
  All comments are removed and please tell me how easy it is to read my code

Certification of Authenticity:
  I certify that this is entirely my own work, except where I have given
  fully-documented references to the work of others.I understand the definition
  and consequences of plagiarism and acknowledge that the assessor of this
  assignment may, for the purpose of assessing this assignment:
  - Reproduce this assignment and provide a copy to another member of academic
    staff; and/or
  - Communicate a copy of this assignment to a plagiarism checking service (which
    may then retain a copy of this assignment on its database for the purpose
    of future plagiarism checking)
*/


#include "person.h"


/*
Pre: A Person object is instantiated
Post: The Person object is initialized
Purpose: Initialize the Person object
*/
Person::Person()
{
   mAddress     = "";
   mId          = "";
   mName        = "";
   mPhoneNumber = "";
}


/*
Pre: ID, name, address and phone number of a person
Post: The Person object is initialized with the values provided
Purpose: Initialize the Person object with values provided
*/
Person::Person(string id, string name, string address, string phoneNumber)
{
   mAddress     = address;
   mId          = id;
   mName        = name;
   mPhoneNumber = phoneNumber;
}


/*
Pre: a Person object
Post: The current Person object is initialized with the object provided
Purpose: Initialize the Person object using another Person object
*/
Person::Person(const Person &obj)
{
   mAddress = obj.mAddress;
   mId = obj.mId;
   mName = obj.mName;
   mPhoneNumber = obj.mPhoneNumber;
}


/*
Pre: A Person object is instantiated
Post: None
Purpose: This is an empty destructor
*/
Person::~Person()
{
	//  intentionally empty
}


/******************  assessor  ******************/

/*
Pre: A Person object is instantiated
Post: The address is returned
Purpose: Return address of the person object
*/
string Person::getAddress()
{
   return mAddress;
}


/*
Pre: A Person object is instantiated
Post: The ID is returned
Purpose: Return ID of the person object
*/
string Person::getId()
{
   return mId;
}


/*
Pre: A Person object is instantiated
Post: The name is returned
Purpose: Return name of the person object
*/
string Person::getName()
{
   return mName;
}


/*
Pre: A Person object is instantiated
Post: The phone number is returned
Purpose: Return phone number of the person object
*/
string Person::getPhoneNumber()
{
   return mPhoneNumber;
}


/******************  mutator  ******************/

/*
Pre: The value for address
Post: The address is updated
Purpose: Update the value for address with the provided value
*/
void Person::setAddress(string address)
{
   mAddress = address;
}


/*
Pre: The value for ID
Post: The ID is updated
Purpose: Update the value for ID with the provided value
*/
void Person::setId(string id)
{
   mId = id;
}


/*
Pre: The value for name
Post: The name is updated
Purpose: Update the value for name with the provided value
*/
void Person::setName(string name)
{
   mName = name;
}


/*
Pre: The value for phone number
Post: The phone number is updated
Purpose: Update the value for phone number with the provided value
*/
void Person::setPhoneNumber(string phoneNumber)
{
   mPhoneNumber = phoneNumber;
}



/******************  overloading operators  ******************/

/*
Pre: The value for ID on the RHS
Post: True if the ID of the class object on the LHS matched with
      the string value on the RHS; otherwise return false
Purpose: Compare a Person object (LHS) with a string (RHS);
         Person == string
*/
bool Person::operator==(string id)
{
   return mId == id;
}


/*
Pre: The value for Person object on the RHS
Post: True if the ID of the Person object on the LHS matched with
      the ID of the Person object on the RHS; otherwise return false
Purpose: Compare two Person objects; Person == Person
*/
bool Person::operator==(Person rhs)
{
   return mId == rhs.mId;
}


/*
Pre: The value for ID on the LHS and Person object on the RHS
Post: True if the string value on LHS matched with the ID of the
      class object on the RHS; otherwise return false
Purpose: Compare a string (LHS) with a Person object (RHS); 
         string == Person
*/
bool operator==(string lhs, Person rhs)
{
   return lhs == rhs.mId;
}
      

/*
Pre: The value for a Person object on the RHS
Post: True if the ID of the Person object on LHS is less than
      the ID of the Person object on the RHS; otherwise return false
Purpose: Compare two Person objects; Person < Person
*/
bool Person::operator<(Person rhs)
{
   return mId < rhs.mId;
}


/*
Pre: The value for ID on the LHS and Person object on the RHS
Post: True if the ID on LHS is greater than the ID of the
      RHS; otherwise return false
Purpose: Compare a Person (LHS) with a Person object (RHS); 
         Person > Person
*/
bool Person::operator>(Person rhs)
{
   return mId > rhs.mId;
}


/*
Pre: The Person object on the LHS and the value for ID on the RHS 
Post: True if the ID of the class object on the LHS does not match
      the string value on RHS; otherwise return false
Purpose: Compare a Person object (LHS) with a string (RHS); 
         Person != string
*/ 
bool Person::operator!=(string rhs)
{
   return !(mId == rhs);
}


/*
Pre: The Person object on the RHS
Post: True if the ID of the class object on both the LHS and RHS 
      does not match; otherwise return false
Purpose: Compare two Person objects; Person != Person
*/ 
bool Person::operator!=(Person rhs)
{
   return !(mId == rhs.mId);
}


/*
Pre: The value for ID on the LHS and Person object on the RHS  
Post: True if the ID on the LHS does not match the ID of the 
      class object on the RHS; otherwise return false
Purpose: Compare a Person object (RHS) with a string (LHS); 
         string != Person
*/ 
bool operator!=(string lhs, Person rhs)
{
   return !(lhs == rhs.mId);
}


/******************  friend functions  ******************/
/*
Pre: The Person object is instantiated 
Post: Information for the Person object is displayed on the screen
Purpose: Display the information for the Person object to the screen
*/
void Person::display()
{
   cout << "          ID:  " << mId << endl
        << "        Name:  " << mName << endl
        << "     Address:  " << mAddress << endl
        << "Phone Number:  " << mPhoneNumber << endl;
}


/******************  friend functions  ******************/

/*
Pre: The istream and Person objects
Post: Read the Person object using istream and the istream
      is returned to the caller
Purpose: Read Person object via the istream
*/ 
istream& operator>>(istream &input, Person &obj)
{
   getline(input, obj.mId);
   getline(input, obj.mName);
   getline(input, obj.mAddress);
   getline(input, obj.mPhoneNumber);

   return input;
}


/*
Pre: The ostream and Person objects
Post: Output the Person object using ostream and the
      ostream is returned to the caller
Purpose: Output Person object via the ostream
*/ 
ostream& operator<<(ostream &output, Person obj)
{
   output << obj.mId << endl
          << obj.mName << endl
          << obj.mAddress << endl
          << obj.mPhoneNumber;

   return output;
}