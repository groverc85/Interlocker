#include "parts_graph.h"

using namespace std;


Graph::Graph(int vertexCount) {
    this->vertexCount = vertexCount;
    
    connection = new bool*[vertexCount];
    connection_axis = new bool**[vertexCount];
    
    for (int i = 0; i < vertexCount; i++) {
        connection[i] = new bool[vertexCount];
        connection_axis[i] = new bool*[vertexCount];
        for (int j = 0; j < vertexCount; j++){
            connection[i][j] = false;
            // D(A, B) could have at most 3 free axis directions
            connection_axis[i][j] = new bool[3];
            for (int k = 0; k < 3; k++)
            {
                connection_axis[i][j][k] = false;
            }
        }
    }
}


void Graph::addEdge(int v, int w, int direction) {
    // self-self would be false
    if (v >= 0 && v < vertexCount && w > 0 && w < vertexCount) {
        connection[v][w] = true;
        connection[w][v] = true;
        connection_axis[v][w][direction] = true;
        connection_axis[w][v][direction] = true;
        
    }
}


void Graph::removeEdge(int v, int w) {
    if (v >= 0 && v < vertexCount && w > 0 && w < vertexCount) {
        connection[v][w] = false;
        connection[w][v] = false;
        for (int i = 0; i < 3; i++)
        {
            connection_axis[v][w][i] = false;
            connection_axis[w][v][i] = false;
        }
    }
}

Graph::~Graph() {
    delete []connection;
    delete []connection_axis;
}

void Graph::setLIGs(std::vector<int> cycle) {
    cycles.push_back(cycle);
}

void Graph::printLIGs() {
    for (int i = 0; i < cycles.size(); i++)
    {
        for (int j = 0; j < cycles[i].size(); j++)
        {
            printf("%d ", cycles[i][j]);
        }
        printf("\n");
    }
}

// test conditions like D(P1, P2) \ D(P1, P8) \ D(P1, P3)
// check to see if all these joints con- sistently allow d(k1) as the free axial direction to move k1 out of the assembly.
int Graph::helper_union(int index) {
    // get the axis connection status with all the rest
    
    // how many intersactions
    int count=0;
    // # of intersaction in each dimension
    int x_count=0, y_count=0, z_count=0;
    
    for (int i = 0; i < vertexCount; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (connection_axis[index][i][j] != false)
            {
                count += 1;
                switch (j) {
                    case 0:
                    {
                        // x axis
                        x_count+=1;
                        break;
                    }
                    case 1:
                    {
                        // y axis
                        y_count+=1;
                        break;
                    }
                    case 2:
                    {
                        // z axis
                        z_count+=1;
                        break;
                    }
                    default:
                        break;
                }
            }
        }
    }
    
    if (count == x_count && count != 0)
        return X;
    else if (count == y_count && count != 0)
        return Y;
    else if (count == z_count && count != 0)
        return Z;
    else
        return NO_AXIS;
}


void Graph::confirmK1() {
    int firstKey;
    
    cout << "Insert the part's number that you would like to remove first\n";
    cin >> firstKey;
    
    for (int i = 0; i < vertexCount; i++)
    {
        cout << connection[firstKey][i] << "\n";
        cout << connection_axis[firstKey][i] << "\n";
    }
    
    int examine = helper_union(firstKey);
    
    if (examine != NO_AXIS){
        cout << "Yes you can remove it in " << examine << "direction.\n";
        k1 = firstKey;
        direction = examine;
    }
    else {
        cout << "You cannot start from here, please select again\n";
        confirmK1();
    }
}


void Graph::constructG1() {
    // k1_connection contains nodes that are connected to key k1
    vector<int> k1_connection;
    
    for (int i = 0; i < vertexCount; i++) {
        if (connection[k1][i] == true)
            k1_connection.push_back(i);
    }
    
    // k1_connection.size() must be equal or great than 2
    for (int i = 0; i < k1_connection.size(); i++) {
        for (int j = i+1; j < k1_connection.size(); j++) {
            vector<int> tmp;
            // 3-node cycle case
            tmp.push_back(k1);
            tmp.push_back(k1_connection[i]);
            tmp.push_back(k1_connection[j]);
            
            // find intersaction between i node and j node
            for (int k = 0; k < vertexCount; k++) {
                // 4-node cycle case
                if (connection[k1_connection[i]][k] == true && connection[k1_connection[j]][k] == true && k != k1) {
                    // k1, k1_connection[i], k1_connection[j], k would form a cycle
                    tmp.push_back(k);
                }
            }
            //
            k1_cycles.push_back(tmp);
        }
    }
}

void Graph::assemblyVerify() {
    
}

















