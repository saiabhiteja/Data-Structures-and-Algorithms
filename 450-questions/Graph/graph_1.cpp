#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9
#define vec vector<int>
#define pp pair<int,int>
/*
*/
void display_matrix(int graph[5][5]){
    cout<<"Matrix"<<endl;
    for(int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
            if(graph[i][j] == 1){
                cout<<i+1<<"->"<<j+1<<endl;
            }
        }
    }
    cout<<endl;
}
void display_adjancy(vector<int> adj[]){
for(int i = 1;i<=5;i++){
        cout<<i<<"-->" ;
        for(auto it:adj[i]){
            cout<<it<<"-";
        }
        cout<< "NULL" << endl;
    }
}
int main() {
/*
    creating a graph using adjacent matrix and as well as adjancy list
    undirected graph
    //matrix[i][j] = 1 -> There is an edge between from vertex i to vertex j
*/


int graph[5][5] = {{0,1,1,1,0},
                   {1,0,0,1,0},
                   {1,0,0,0,1},
                   {1,1,0,0,1},
                   {0,0,1,1,0} };
//space complexity : O(V+E)
    vector<int> adjancy_list[10];
    adjancy_list[1] = {2,3,4};
    adjancy_list[2] = {1,4};
    adjancy_list[3] = {1,5};
    adjancy_list[4] = {1,2,5};
    adjancy_list[5] = {3,4};

    //matrix
    display_matrix(graph);

    //list
    display_adjancy(adjancy_list);


return 0;
}