#include <bits/stdc++.h>

using namespace std;
bool SortByPeso(pair<float,float> a,pair<float,float> b) {
    return (a.first < b.first);
}
bool SortByValor(pair<float,float> a,pair<float,float> b) {
    return (a.second > b.second);
}
bool SortByProm(pair<float,float> a,pair<float,float> b) {
    return (float(a.second/a.first) > float(b.second/b.first));
}


float mochila(int M, int N, vector<float> p, vector<float> b, int criteria){
  bool (*funcion[3]) (pair<float,float>,pair<float,float>)={SortByPeso,SortByValor,SortByProm};
  vector<pair<float,float>> ListValues;
  for(int i=0;i<N;i++){
    ListValues.push_back(make_pair(p[i],b[i]));
  }    
  sort(ListValues.begin(),ListValues.end(),funcion[criteria]);
  /*cout<<endl;
  for(int i=0;i<N;i++){
    cout<<ListValues[i].first<<"-"<<ListValues[i].second<<" ";
  }
  cout<<endl;*/
  float pesSum=0;
  float valSum=0;
  /*cout<<endl;*/
  for(int i=0;i<N;i++){
    /*cout<<endl<<pesSum<<endl;*/
    if(pesSum<M){
      if(pesSum+ListValues[i].first<=M){
        pesSum+=ListValues[i].first;
        valSum+=ListValues[i].second;
        /*cout<<ListValues[i].first<<"-"<<ListValues[i].second<<": "<<valSum<<" ";*/
      }else{
        valSum+=float((ListValues[i].second)/(ListValues[i].first)*(M-pesSum));
        pesSum+=(M-pesSum);
        /*cout<<ListValues[i].first<<"-"<<ListValues[i].second<<": " <<valSum<<"km";*/
      }
    }
    else if(pesSum==M){
      break;
    }else{
      cout<<"\nERROR CRÍTICO\n";
      return 0;
    }
  }
  /*cout<<endl;*/
  return valSum;
}
int main() {
  
  //Si se quisiera un número n de elementos, usar el siguiente comentario en lugar del caso de prueba
  
  /*
  int M; //Capacidad de la mochila
  int N; //Elementos disponibles
  cout<<"Ingrese la capacidad máxima de la mochila: ";
  cin>>M; 
  cout<<endl<<"Ingrese el número de elementos disponibles: ";
  cin>>N; 
  vector<float>  p;
  vector<float>  b;
  int a,b;
  cout<<endl;
  for(int i=0;i<N;i++){
    cout<<"Ingrese el peso del siguiente elemento: ";
    cin>>"a;
    cout<<"Ingrese el valor del elemento ingresado: ";
    cin>>"b;
    p.push_back(a);
    b.push_back(b);
  }*/
  /*Si no se quiere un número n de elementos a ingresar, caso de prueba a continuación.*/
  int M = 20;  //Capacidad de la mochila
  vector<float>  p={18,15,10};  // Pesos de los elementos
  vector<float>  b={25,24,15};  // Valores de los elementos
  int N = p.size();  // Número de elementos
  /*Caso contrario, comentar esto y descomentar el bloque anterior*/
  if (M == 0 || N == 0)
        return 0;
  float x=mochila(M,N,p,b,0);
  float y=mochila(M,N,p,b,1);
  float z=mochila(M,N,p,b,2);
  cout<<"PESOS POR ELEMENTO: "<<endl;
  for(int i=0;i<N;i++){
    if(i==N-1){
      cout<<p[i];
      break;
    }
    cout<<p[i]<<", ";
  }
  cout<<endl<<"VALORES POR ELEMENTO: "<<endl;
  for(int i=0;i<N;i++){
    if(i==N-1){
      cout<<b[i];
      break;
    }
    cout<<b[i]<<", ";
  }
  cout<<endl;
  cout << "El máximo valor obtenible usando el método de comparación de pesos es: "<<x<<endl;
  cout << "El máximo valor obtenible usando el método de comparación de valor por elemento es: "<<y<<endl;
  cout << "El máximo valor obtenible usando el método de comparación de proporción peso a valor es: "<<z<<endl;
  return 0;
}