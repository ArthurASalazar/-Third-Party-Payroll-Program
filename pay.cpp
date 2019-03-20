#include "person.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

void readData(vector<Person> &emp);
void getCompanies(vector<Person> &emp, vector<string> &compa);
void printHighestPaid(vector<Person> &emp);
void separateAndSave(vector<Person> &emp, vector<string> &compa);

int main()
{
  vector<Person> employees;
  vector<string> companyNames;

  readData(employees);
  getCompanies(employees, companyNames);
  printHighestPaid(employees);
  separateAndSave(employees, companyNames);

  return 0;
}

void readData(vector<Person> &emp)
{
  string fname, lname, compname;
  int employID;
  float hourworked, payrate;
  Person Human;

  ifstream infile;
  infile.open("input.txt");

  if(!infile)
  {
    cout<<"Could not open file. Terminating program." << endl;
    exit(1);
  }

  while(!infile.eof())
  {
    infile >> fname >> lname >> employID
           >> compname >> hourworked >> payrate;
    infile >> ws;

    Human.setFirstName(fname);
    Human.setLastName(lname);
    Human.setEmployeeId(employID);
    Human.setCompanyName(compname);
    Human.setHoursWorked(hourworked);
    Human.setPayRate(payrate);

    emp.push_back(Human);
  }
}

void getCompanies(vector<Person> &emp, vector<string> &compa)
{
  for (int i = 0; i < emp.size(); i++)
  {
    string temp = emp.at(i).getCompanyName();
    compa.push_back(temp);
  }
}

void printHighestPaid(vector<Person> &emp)
{
  float max = 0.0;
  int business;

  for (int i = 0; i < emp.size(); i++)
  {
    if (emp.at(i).totalPay() > max)
    {
      max = emp.at(i).totalPay();
      business = i;
    }
  }

  cout << "Highest Paid: " << emp.at(business).fullName() << endl;
  cout << "Employer ID: " << emp.at(business).getEmployeeId() << endl;
  cout << "Employer: " << emp.at(business).getCompanyName() << endl;
  cout << "Total Pay: $" << fixed << setprecision(2) << emp.at(business).totalPay() << endl;
}

void separateAndSave(vector<Person> &emp, vector<string> &compa)
{
  float total = 0.0;
  ofstream outfile;

  outfile.open("Intel.txt");
  outfile << "Intel.txt" << endl;
  outfile << "-------------------------------------" << endl;
  for (int i = 0; i< compa.size(); i++)
  {
    if (compa.at(i) == "Intel")
    {
      outfile << emp.at(i).fullName();
      outfile << emp.at(i).getEmployeeId();
      outfile << emp.at(i).getCompanyName();
      outfile << "$" << emp.at(i).totalPay();
      outfile << endl;
      total += emp.at(i).totalPay(); //
    }
  }
  outfile <<"Total: $"<<total;
  outfile.close();

  total = 0.0;
  outfile.open("Boeing.txt");
  outfile << "Boeing.txt" << endl;
  outfile << "-------------------------------------" << endl;
  for (int i = 0; i< compa.size(); i++)
  {
    if (compa.at(i) == "Boeing")
    {
      outfile << emp.at(i).fullName();
      outfile << emp.at(i).getEmployeeId();
      outfile << emp.at(i).getCompanyName();
      outfile << fixed << setprecision(2) << "$" << emp.at(i).totalPay();
      outfile << endl;
      total += emp.at(i).totalPay();
    }
  }
  outfile <<"Total: $"<<total;
  outfile.close();

  total = 0.0;
  outfile.open("Douglas.txt");
  outfile << "Douglas.txt" << endl;
  outfile << "-------------------------------------" << endl;
  for (int i = 0; i< compa.size(); i++)
  {
    if (compa.at(i) == "Douglas")
    {
      outfile << emp.at(i).fullName();
      outfile << emp.at(i).getEmployeeId();
      outfile << emp.at(i).getCompanyName();
      outfile << fixed << setprecision(2) << "$" << emp.at(i).totalPay();
      outfile << endl;
      total += emp.at(i).totalPay();
    }
  }
  outfile <<"Total: $"<<total;
  outfile.close();

  total = 0.0;
  outfile.open("Raytheon.txt");
  outfile << "Raytheon.txt" << endl;
  outfile << "-------------------------------------" << endl;
  for (int i = 0; i< compa.size(); i++)
  {
    if (compa.at(i) == "Raytheon")
    {
      outfile << emp.at(i).fullName();
      outfile << emp.at(i).getEmployeeId();
      outfile << emp.at(i).getCompanyName();
      outfile << fixed << setprecision(2) << "$" << emp.at(i).totalPay();
      outfile << endl;
      total += emp.at(i).totalPay();
    }
  }
  outfile <<"Total: $"<<total;
  outfile.close();

  total = 0.0;
  outfile.open("HealthTech.txt");
  outfile << "HealthTech.txt" << endl;
  outfile << "-------------------------------------" << endl;
  for (int i = 0; i< compa.size(); i++)
  {
    if (compa.at(i) == "HealthTech")
    {
      outfile << emp.at(i).fullName();
      outfile << emp.at(i).getEmployeeId();
      outfile << emp.at(i).getCompanyName();
      outfile << fixed << setprecision(2) << "$" << emp.at(i).totalPay();
      outfile << endl;
      total += emp.at(i).totalPay();
    }
  }
  outfile <<"Total: $"<<total;
  outfile.close();
}
