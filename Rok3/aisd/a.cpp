
#include <cmath>
#include<stdio.h>
#include<bits/stdc++.h>
#include<set>
#include<map>

using namespace std;

struct brick{
    int middle;
    int right;
};


class Graph {

    list <brick> *adj;
    set<int> Set;
    map<int,brick> mapa;
    

    public:
        Graph(int v);
        void AddEdge(int v, brick e);
        bool is_zero_Cycle();
        bool find_path_to_zero(int v);
        map<int,brick> wynik();
        
};
    map<int,brick>Graph::wynik(){
        return mapa;
    };
    Graph::Graph(int v){
         adj = new list<brick>[v]; 
         Set = {};
         mapa = {};
         };

    void Graph::AddEdge(int v, brick e){
        adj[v].push_back(e);
        Set.insert(v);
    };
       

    bool Graph::find_path_to_zero(int v) 
        { 
            const bool is_in = Set.find(v) != Set.end();
            if(is_in) 
            {   
                Set.erase(v);
                if (v == 0 ){
                    return true;
                    }
                list<brick>::iterator i; 
                for(i = adj[v].begin(); i != adj[v].end(); ++i) 
                {   mapa.insert_or_assign(v,(*i));
                    if (find_path_to_zero((*i).right))
                    {   
                        return true;
                    }
                    mapa.erase(v);                   
                } 
            } 
            return false; 
        } 

    bool Graph::is_zero_Cycle(){

        list<brick>::iterator i;
    
        for(i = adj[0].begin(); i != adj[0].end(); ++i)
        {
            mapa.insert_or_assign(0,(*i));
            if (find_path_to_zero((*i).right)) 
                return true;
        }
        return false;

    }


int main(){
    ios::sync_with_stdio(false);
    int number_of_bricks;
    cin>>number_of_bricks;
    Graph Graf = Graph(number_of_bricks);  
    int l;
    brick temp;
    
    for(int i=0; i < number_of_bricks; ++i){  
        cin>>l>>temp.middle>>temp.right;
        Graf.AddEdge(l,temp);
    }
    if(Graf.is_zero_Cycle()){
        map<int,brick> wynik = Graf.wynik();
        int key = 0 ;

        cout<<wynik.size()<<endl;
        while(true){
            cout<<key<<" "<<wynik[key].middle<<" "<<wynik[key].right<<endl;
            if (wynik[key].right == 0){break;}
            else{key = wynik[key].right;}
        }
    }
    else
    {
        cout<<"BRAK";
    }
    
    return 0;
}