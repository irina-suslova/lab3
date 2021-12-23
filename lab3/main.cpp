#include <iostream>
#include <fstream>
#include <cmath>
#include "graph.h"
#include "tests.h"
using namespace std;

// граф (неориентированный) - 6, ориент - 5 ???
// путь кратч - 5
// путь на большом 8
// пропускная способность 7
// генерация - 10
// отрисовка - 3 ???
// динамика - 10

// git
// сайт
// тесты +

int main(int argc, char *argv[]) {
    Graph graph1;
    pair<double, vector<Node*>> path1;
    graph1.Generate(8);
    path1 = graph1.SearchBestPathThroughput(graph1.GetVertex(0), graph1.GetVertex(7));
    graph1.DrawInFilePath("path.png", "Graph", path1.second);

    if (argc < 5) return 0;
    string GraphType = argv[1];
    int n_vertex = atoi(argv[2]);
    int n_arcs = atoi(argv[3]);
    string TaskType = argv[4];

    bool mode = (GraphType == "Graph") ? true : false;

    Graph graph;
    pair<double, vector<Node*>> path;
    graph.Generate(n_vertex, n_arcs, mode);
    if (TaskType == "BestPath") {
        path = graph.SearchBestPath(graph.GetVertex(0), graph.GetVertex(n_vertex - 1));
    }
    else if (TaskType == "BestPathThroughput") {
        path = graph.SearchBestPathThroughput(graph.GetVertex(0), graph.GetVertex(n_vertex - 1));
    }
    graph.DrawInFilePath("path.png", "Graph", path.second);
    ofstream len_of_path("len.txt");
    if (abs(path.first - 1e10) < 1e-1) len_of_path << "Нет пути, связывающего эти вершины";
    else len_of_path << path.first;
    len_of_path.close();
    return 0;
}
