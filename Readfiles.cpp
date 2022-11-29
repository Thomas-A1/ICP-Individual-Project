//
// Created by THOMAS QUARSHIE on 11/27/2022.
//

#include "Readfiles.h"
#include <string>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>

/**
 * Description: Reading each csv file into an array and then adding them to an ArrayList to be returned
 * This is done by splitting the csv file using the comma as the delimeter
 */
std::vector<std::string> split(const std::string& s, char delimeter)
{
    vector<string> tokens;
    string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimeter))
    {
        tokens.push_back((token));
    }
    return tokens;
}

vector<vector<std::string>> Readfile(const string& filename) {
    ifstream details;
    details.open(filename);
    vector<vector<string>> rows;
    vector<string> contents;
    string token;


    if (details.fail()) {
        cerr << "Unable to open the file " << filename << endl;
    }
    while (details.peek() != EOF) {
        string records;
        getline(details, records, '\n');
        contents.push_back(records);
    }

    for(const string& content: contents){
        rows.push_back(split(content, ','));
    }
    /**
     * Printing out the first row in the vector
     */
    for (int i = 0; i < rows[0].size(); i++) {
        //cout << fieldobjects[0][i] << " ";
    }
    // Closing file
    details.close();
    return rows;
}





