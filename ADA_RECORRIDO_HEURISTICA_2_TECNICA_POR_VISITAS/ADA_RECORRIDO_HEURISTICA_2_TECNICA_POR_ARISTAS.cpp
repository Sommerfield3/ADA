#include <bits/stdc++.h>
using namespace std;
class Par{
public:
  int salida;
  int llegada;
  Par(int a, int b){
    salida=a;
    llegada=b;
  }
};
vector<pair<Par*,int>>::iterator next(vector<pair<Par*,int>>::iterator iterator)
{
    return ++iterator;
}
class Numb{
public:
  int enlacesCompleto; 
  vector<pair<Par*,int>> enlaces;
  map<int,int> enlacesCarga;
  int posActual;
  Numb(int x){
    enlacesCompleto=x;
  }
  ~Numb(){
    for(auto it=enlaces.begin();it!=enlaces.end();++it){
      delete[] it->first;
    }
  }
  bool noPassar(int x, int y){
    enlacesCarga[x]++;
    enlacesCarga[y]++;
    int completos=0;
    for(auto it=enlacesCarga.begin();it!=enlacesCarga.end();++it){
       if(it->second==2){
         completos++;     
       }
    }
    enlacesCarga[x]--;
    enlacesCarga[y]--;
    if(completos==enlacesCompleto){
      return 0;
    }
    if(enlacesCompleto-completos>=3){
      return 0;
    }
    return 1;
  }
  bool Integrando(int x,int y,int peso){
    if(enlacesCarga[x]==2 || enlacesCarga[y]==2){
      /*cout<<"\nNo es posible añadir la arista "<<x<<"-"<<y<<" con peso "<<peso<<".\n";*/
      return 0;
    }
    if((enlacesCarga[x]==1 && enlacesCarga[y]==1) && noPassar(x,y)==1){
      return 0;
    }
    enlacesCarga[x]++;
    enlacesCarga[y]++;
    Par* new_par=new Par(x,y);//Añadimos el par al mapa de enlaces
    enlaces.push_back(make_pair(new_par,peso));
    return 1;
  }
  void lectura(){
    cout<<"\nRECORRIDO DE LA SOLUCIÓN: ";
    for(auto it=enlaces.begin();it!=enlaces.end();++it){
      cout<<"("<<it->first->salida+1<<","<<it->first->llegada+1<<") ";//Agregamos 1 para iniciar siempre desde el nodo 1 hasta n.
    }
    int suma=0;
    cout<<"\nSUMA DE PESOS TOTAL DE LA SOLUCIÓN: ";
    for(auto it=enlaces.begin();it!=enlaces.end();++it){
      if(next(it)==enlaces.end()){
        cout<<it->second<<"=";
        suma=suma+it->second;
        break;
      }
      cout<<it->second<<"+";
      suma=suma+it->second;
    }
    cout<<suma<<"\n";
  }
};
void solve(vector<vector<int>> M, int numNode){
  if(numNode==0){
    return;
  }
  vector<vector<int>> Matrix(numNode);
  for(int l=0;l<numNode;l++){
    for(int m=0;m<numNode;m++){
      Matrix[l].push_back(M[l][m]);
      /*cout<<Matrix[l][m]<<" ";*/
    }
     /*cout<<"\n";*/
  }
  for(int l=0;l<numNode;l++){
    for(int m=l+1;m<numNode;m++){/*0 1..4 1 2..4 2 3..4 3 4..4*/
        cout<<"|CONEXION: "<<l+1<<"-"<<m+1<<", PESO: "<<Matrix[l][m]<<"|\t";
    }
     cout<<"\n";
  }
  Numb Res(numNode);
  int minim=0;
  int total=0;
  int i=0;
  /*cout<<"sa "<<minim<<" as"<<endl;*/
  int tempi, tempj;
  while(total<numNode){
    /*int tempi, tempj;*/
    for(int j=0;j<numNode;j++){
      if(Matrix[i][j]!=0 && minim==0){
        tempi=i;
        tempj=j;
        minim=Matrix[i][j];
        /*cout<<"CERO:"<<minim<<" "<<endl;*/
      }
      else if(Matrix[i][j]!=0 && Matrix[i][j]<minim){
        tempi=i;
        tempj=j;
        minim=Matrix[i][j];
        /*cout<<minim<<" "<<endl;*/
      }
    }
    if(i==numNode-1){
      if(minim==0){
        break;
      }
      if(Res.Integrando(tempi,tempj,minim)==1){
        Matrix[tempi][tempj]=0;
        Matrix[tempj][tempi]=0;
        /*cout<<endl<<"no: "<<minim<<endl;*/
        total++;
        minim=0;
        i=0;
      }else{
        Matrix[tempi][tempj]=0;
        Matrix[tempj][tempi]=0;
        minim=0;
        i=0;
      }
      /*Matrix[tempi][tempj]=0;
      Matrix[tempj][tempi]=0;
      i=0;*/
      continue;
    }
    i++;
  }
  Res.lectura();
  if(total==numNode){
    Res.lectura();
    return;
  }
  if(minim==0){//Caso hipotético, porque es un grafo completo.
    cout<<"\nNo existe una ruta para recorrer el grafo.\n";
    return;
  }
}
int main() {
  int numNodes=5;
  vector<vector<int>> Graph(numNodes);
  Graph={
  {0,10,55,25,45},
  {10,0,20,25,40},
  {55,20,0,15,30},
  {25,25,15,0,50},
  {45,40,30,50,0}
  };
  solve(Graph,numNodes);
  return 0;
}