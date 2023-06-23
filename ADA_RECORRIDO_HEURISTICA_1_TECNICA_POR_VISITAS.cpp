#include <bits/stdc++.h>
using namespace std;
void VertexApproach(vector<vector<int>> Matrix,int numNode){
  map<int,int> visitados;
  vector<int> ordenVisita;
  int InitNode=rand()%numNode;
  int FIRST=InitNode;
  int i=0; 
  int tempNode,min;
  min=0;
  tempNode=-1;
  /*for(int j=0;j<numNode;j++){
    if(Matrix[InitNode][j]>0){
      min=Matrix[InitNode][j];
      break;  
    }
  }*/
  /*for(int x=0;x<numNode;x++){
    visitados[x]=0;
  }*/
  visitados[FIRST]=1;
  /*cout<<"RANDOM:"<<InitNode<<"\n";*/
  while(true){
    if(min==0 && Matrix[InitNode][i]!=0 && visitados[i]==0){
      min=Matrix[InitNode][i];
      tempNode=i;
      /*cout<<"\nMIN: "<<min;*/
    }
    else if(Matrix[InitNode][i]<min && Matrix[InitNode][i]!=0 && visitados[i]==0){
      min=Matrix[InitNode][i];
      /*cout<<"\n NEWMIN"<<Matrix[InitNode][i];*/
      tempNode=i;
      //cout<<"\nCAMBIO"<<i;
    }
    if(i+1==numNode && tempNode!=-1){
      visitados[tempNode]=min;
      InitNode=tempNode;
      ordenVisita.push_back(tempNode);
      min=0;
      tempNode=-1;
      i=0;
      if(ordenVisita.size()==numNode-1){
        visitados[FIRST]=0;
        //cout<<"\nAAAAAAAAA";
      }
       //cout<<"\nINSIDE:";
      //cout<<InitNode<<"\n";
      continue;
    }
    if(ordenVisita.size()==numNode){
      /*cout<<endl;
      for(auto s=visitados.begin();s!=visitados.end();++s){
        cout<<s->first<<":";
        cout<<s->second<<" ";
      }
      cout<<endl;*///Probando los valores:
      break;
    }
    if(i+1==numNode){
      break;
    }
    i++;
    //cout<<"\n"<<i;
  }
  if(visitados.size()!=numNode){
    cout<<"\nNo existen caminos para recorrer el grafo completamente.\n";
    return;
  } 
  int suma=0;
  cout<<"VALORES CON LOS CUALES SE LLEGA A DICHO NODO: \n";
  for(auto s=visitados.begin();s!=visitados.end();++s){
    cout<<"NODO "<<s->first+1<<": ";
    suma=suma+s->second; 
    cout<<s->second<<"\n";
  }
  cout<<"\nORDEN DE RECORRIDO COMENZANDO DESDE EL NODO "<<FIRST+1<<":\n"; 
  cout<<FIRST+1;
  if(ordenVisita.size()>1){
    cout<<"-->";
  }
  for(int l=0;l<ordenVisita.size();l++){
    if(l==ordenVisita.size()-1){
      cout<<ordenVisita[l]+1<<"\n";
      break;
    }
    cout<<ordenVisita[l]+1<<"->";
  }
  cout<<"EL PESO TOTAL DEL RECORRIDO ES: "<<suma<<"\n";
}
int main() {
  srand(time(NULL));
  int numNodes=5;
  vector<vector<int>> Graph(numNodes);
  Graph={
  {0,10,55,25,45},
  {10,0,20,25,40},
  {55,20,0,15,30},
  {25,25,15,0,50},
  {45,40,30,50,0}
  };
  VertexApproach(Graph,numNodes);
}