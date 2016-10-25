#include <stdlib.h> /* srand, rand */
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <queue>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <utility>
#include <deque>
#include <set>

using namespace std;

template <typename T> 
void printv2(vector<T> v, const string &s=string("Printing vector: ")){
    // s is a const& - constant reference;
    //   -content of s is constant; content can not be changed through s 
    //   -s is a reference, so no copying
    //   -In effect: Use s directly with no danger of mutation

    cout << s;
    for(auto it=v.begin(); it!=v.end(); it++){
        cout << *it << ", ";
    }
    cout << endl;
}

template <typename T>
void printM(vector<vector<T>> M){

    for(auto it=M.begin(); it!=M.end(); it++){
        printv2(*it, "");
    }
}


void pushNextMoves(pair<int,int> &p, deque<pair<int,int>> &q, set<pair<int,int>> &visited, vector<vector<int>> &M){
    int w=M[0].size()-1;
    int h=M.size()-1;

    int r = p.first;
    int c = p.second;

    pair<int, int> nextCell;

    // right
    nextCell = make_pair(r, c+1);
    if (visited.count(nextCell)==0 && r>=0 && r<=h && c+1>=0 && c+1<=w){
        q.push_back(nextCell);
    }

    // left
    nextCell = make_pair(r, c-1);
    if (visited.count(nextCell)==0 && r>=0 && r<=h && c-1>=0 && c-1<=w){
        q.push_back(nextCell);
    }

    // up
    nextCell = make_pair(r-1, c);
    if (visited.count(nextCell)==0 && r-1>=0 && r-1<=h && c>=0 && c<=w){
        q.push_back(nextCell);
    }
    
    // down
    nextCell = make_pair(r+1, c);
    if (visited.count(nextCell)==0 && r+1>=0 && r+1<=h && c>=0 && c<=w){
        q.push_back(nextCell);
    }

}

bool robot(vector<vector<int>> M){
    pair<int, int> cell;
    deque< pair<int, int> > qA;
    deque< pair<int, int> > qB;
    set< pair<int, int> > visitedA;
    set< pair<int, int> > visitedB;
    cell = make_pair(0,0);
    qA.push_back(cell);
    cell = make_pair(M.size()-1, M[0].size()-1);
    qB.push_back(cell);

    
    int turn=0;
    int qA_size = 0;
    int qB_size = 0;
    while(qA.size()!=0 || qB.size()!=0){

        // A's turn
        if(turn%2==0){
            qA_size = qA.size();
            
            // get all next BFS node into qA
            for(int i=0; i < qA_size; i++){

                // reached solution!
                if (visitedB.count(qA.front())!=0){
                    // what return type do we want??
                    return true;
                }
                else{
                    pushNextMoves(qA.front(), qA, visitedA, M);
                    visitedA.insert(qA.front());
                    qA.pop_front();
                }
            }
        }
        else{
        }

        turn++;
    }
    

    return 0;
}




int main(){
    vector<vector<int>> M;
    M = {
        {1,1,1,1},
        {1,0,0,1},
        {1,0,0,1},
        {1,1,1,-1}
    };

    printM(M);
    return 0;
}

