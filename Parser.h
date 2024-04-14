#ifndef PARSER_H
#define PARSER_H


#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;

class Parser{

public:

    Parser(string STR);
    ~Parser();

    vector<double> X, Y;
    vector<tuple<int,int,int>> DEG_x2;

    void Parse(vector<double> X, vector<double> Y, vector<tuple<int,int,int>> DEG_x2);

    int get_N();
    int get_M();
    void set_N();
    vector<double> get_X();
    vector<double> get_Y();
    vector<tuple<int,int,int>> get_DEG();

private:

    string filename;
    fstream f_in;
    int N, M;

};

Parser::Parser(string STR) {

    filename = STR;
    f_in.open(filename);

}

Parser::~Parser()
{

    filename.clear();
    f_in.close();

    X.clear();
    Y.clear();
    DEG_x2.clear();

}

int Parser::get_N()
{
    return N;
}

int Parser::get_M()
{
    return M;
}

void Parser::set_N()
{

    string STR;
    N = 0;
    getline(f_in,STR,' ');
    N = stoi(STR);
    getline(f_in,STR,'\n');
    M = stoi(STR);
    f_in.clear();

}

vector<double> Parser::get_X() { return X; }
vector<double> Parser::get_Y() { return Y; }
vector<tuple<int,int,int>> Parser::get_DEG() { return DEG_x2; }

void Parser::Parse(vector<double> new_X, vector<double> new_Y, vector<tuple<int,int,int>> new_DEG_x2)
{
    string STR, x, y;

    int i;

    for (i = 0; i < N; i++) {
        new_DEG_x2.push_back( make_tuple(0,i,0) );
    }

    i = 0;
    char div = ' ';

    while( i < M ){

        getline(f_in,x,div);
        getline(f_in,y,'\n');

        new_X.push_back(stoi(x));
        new_Y.push_back(stoi(y));

        new_DEG_x2[stoi(x)] = make_tuple(get<0>(new_DEG_x2[stoi(x)])+1,get<1>(new_DEG_x2[stoi(x)]),get<2>(new_DEG_x2[stoi(x)]));
        new_DEG_x2[stoi(y)] = make_tuple(get<0>(new_DEG_x2[stoi(y)])+1,get<1>(new_DEG_x2[stoi(y)]),get<2>(new_DEG_x2[stoi(y)]));


        i++;

    }

    X = new_X;
    Y = new_Y;

    DEG_x2 = new_DEG_x2;

    return;

}

#endif
