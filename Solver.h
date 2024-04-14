#ifndef SOLVER_H
#define SOLVER_H

#include "Parser.h"
#include<algorithm>

class Solver {

    Parser *parser;

public:

    vector<vector<double>> GRAPH;
    vector<tuple<int,int,int>> DEG; //количество исходящих вершин, номер вершины-истока, цвет - изначально нулевой для всех

    Solver(Parser *parser);
    ~Solver();

    void solve(Parser *parser, int N, int M);

};

Solver::Solver(Parser *parser) {

    GRAPH.resize(parser->get_N());

    vector<double> new_X = parser->get_X() ;
    vector<double> new_Y = parser->get_Y() ;

    for (int i = 0; i < new_X.size(); i++)
    {
        GRAPH[new_X[i]].push_back(new_Y[i]);
        GRAPH[new_Y[i]].push_back(new_X[i]);
    }

    DEG = parser->get_DEG();

}

Solver::~Solver() {

    GRAPH[0].clear();
    GRAPH[1].clear();
    DEG.clear();

}

void Solver::solve(Parser *parser, int N, int M) {

    int i, j, k;

    int colors_num = 1;

    sort(DEG.begin(),DEG.end(),
         [](auto&v1,auto&v2) {return v1 > v2;});


    i = 0;
    bool flag;

    while (i < N) //рассм. по очереди вершины из DEG
    {
    if (get<2>(DEG[i]) == 0)
    {
        DEG[i] = make_tuple(get<0>(DEG[i]),get<1>(DEG[i]),colors_num);
        for (j = i + 1; j < N; j++)
        {
            k = 0; flag = 1;
            while (k < get<0>(DEG[j]) && flag == 1)
            {
                if (get<2>(DEG[GRAPH[j][k]]) == colors_num) flag = 0;
                k++;
            }
            if (get<2>(DEG[j]) == 0 && flag == 1)
                DEG[j] = make_tuple(get<0>(DEG[j]),get<1>(DEG[j]),colors_num);
        }

        colors_num++;

    }
    i++;
    }

    for (i = 0; i < N; i++)
        cout << "Vertex num: " << get<1>(DEG[i]) << "\nColor: " << get<2>(DEG[i]) << endl;

    return;

}

#endif
