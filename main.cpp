// =================================================================
//
// File: main.cpp
// Author: Arturo Diaz
// Date: 11/09/22
//
// =================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <string_view>
#include <algorithm>
#include <iomanip>
#include <ctime>

#include "sort.h"
using namespace std;

int main(int argc, char *argv[]){
  
  ifstream inputFile;
  ofstream outputFile;

  if (argc != 3){
    cout << "usage: " << argv[0] << " input_file output_file\n";
    return -1;
  }

  inputFile.open(argv[1]);
  outputFile.open(argv[2]);

  if (!inputFile.is_open()){
    cout << argv[0] << ": File \"" << argv[1] << "\" not found\n";
    return -1;
  }

  int n;
  std::string idSearch, date, time, port, id;

  struct registry{
    int year, month, day;
    string date_, time, port, id;
  };

  vector<registry> ships;

  inputFile >> n;
  inputFile >> idSearch;

  for (int i = 0; i < n; i++){
    inputFile >> date >> time >> port >> id;

    string day = date.substr(0, date.find("-"));
    string month = date.substr(3, date.find("-"));
    string year = date.substr(6);

    size_t found = id.rfind(idSearch);
    if (found != string::npos){
      ships.push_back({stoi(year), stoi(month), stoi(day), date, time, port, id});
    }
  }

  sortDay(ships);
  sortMonth(ships);

  for (int i = 0; i < ships.size(); i++){
    outputFile << ships[i].date_ << " " << ships[i].time << " " << ships[i].port << " " << ships[i].id << "\n";
  }

  inputFile.close();
  outputFile.close();

  return 0;
}