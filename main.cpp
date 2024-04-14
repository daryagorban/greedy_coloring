#include<iostream>
#include "Parser.h"
#include "Solver.h"

int main() {


    Parser parser("gc_250_7");
    parser.set_N();
    vector<double> new_vector_X, new_vector_Y;
    vector<tuple<int,int,int>> vector_DEG;
    parser.Parse(new_vector_X,new_vector_Y,vector_DEG);

    Solver solver(&parser);
    solver.solve(&parser,parser.get_N(),parser.get_M());

    return 0;
}
