#include <iostream>
#include "bits/stdc++.h"
using namespace std;
/*
    checking wether given graph is tree or not
    if they mention binary tree -> then we have to check wether 
    every node has at most k connections or not
    2. graph should not have cycle
    3.graph must be connected

*/

bool istree(vector<int> adj[],int n){
    //cycle cheking
    //components checking
    //bfs cycle check
   
    vector<int> vis(n,0) ;
    bool is_not_conn = false;
    for(int i = 0;i<n;i++){
        if(!vis[i]){
            if(is_not_conn){
                //graph is not connected
                return false;
            }
            queue<pair<int,int>> q ;
            q.push({i,-1}) ;
            vis[i] = 1;
            while(q.size()!=0){
                auto t = q.front();
                q.pop();
                int node = t.first ;
                int prev = t.second ;
                for(auto it: adj[node]){
                    if(!vis[it]){
                        vis[it] = 1;
                        q.push({it,node});
                    }
                    else if (it!=prev){
                        //here we found cycle so tree is not possible
                            return false;
                    }
                }
            }
            //if we enter this section again that means
            //we have disconnected graph
            //so if we make is_not_conn = true then if there is next
            //time then it will return false
            is_not_conn = true ;
            /*
            Time : O(V+E) //just a bfs
            Space : O(V)
            */
        }
    }
    //cycle checked
    //components checked
    //if both are okay then it is a tree
    return true;


}
int main(){

    //space complexity : O(V+E)
    vector<int> adjancy_list[10];
    adjancy_list[0] = {1,2,3};
    adjancy_list[1] = {0,2};
    adjancy_list[2] = {0};
    adjancy_list[3] = {0,4};
    adjancy_list[4] = {3};

    for(int i = 1;i<=5;i++){
        cout<<i<<"-->" ;
        for(auto it:adjancy_list[i]){
            cout<<it<<"-";
        }
        cout<< "NULL" << endl;
    }

    if(istree(adjancy_list,5)){
        cout<<"Tree"<<endl;
    }
    else{
        cout<<"Not A Tree"<<endl;
    }
    return 0;
}
