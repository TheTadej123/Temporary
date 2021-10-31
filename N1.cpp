#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
using namespace std;


vector<double> c;
vector<vector<double>> c2;
double vsota = 0;

void sestevanje(vector<double> a, vector<double> b,int begin, int end)
{

    
    for (int i = begin; i < end; i++)
    {
        c[i]=a[i] + b[i];

    }

}

void skalarniProdukt(vector<double> a, vector<double> b,int begin, int end)
{

    
    for (int i = 0; i < a.size(); i++)
    {
        vsota += a[i] + b[i];
    }
}

void produkt(vector<vector<double>> a, vector<vector<double>> b)
{

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b[i].size(); j++)
        {
            for (int k = 0; k < a[i].size(); k++)
            {
              c2[i][j]+=a[i][k]*b[j][k];
            }
        }
    }
}



int main()
{
    int type;
    cout << "Vnesite tip izracuna " << endl;
    cin >> type;
    int threads;
    cout << "Vnesite stevilo niti " << endl;
    cin >> threads;
    cout << "Vnesite velikost matrik" << endl;
    int size;
    cin >> size;
    vector<double> a;
    vector<double> b;

    vector<double> a2;
    vector<double> b2;
    if(type==1){
    for (int i = 0; i < size; i++)
    {
        a.push_back(rand() % 100);
        b.push_back(rand() % 100);
    }
    c.resize(size);
    }
    if(type==3){

    for (int i = 0; i < size; i++)
    {
       vector<double> c1;
       for (int i = 0; i < size; i++)
       {
        
          c1.push_back(rand() % 100);
          c1.push_back(rand() % 100);
        }
        a2.push_back(c1);
        b2.push_back(c1);
    }
    c2.resize(size);
    }
   
    int n4=a.size()/4;
    int n8=a.size()/8;
    if(type==1){
    for(int i=0;i<1000000;i++){
       if(threads==1){
       std::thread t1(sestevanje, a, b,0,a.size());
       t1.join(); 

       }

       if(threads==2){
       std::thread t1(sestevanje, a, b,0,a.size()/2);
       std::thread t2(sestevanje, a, b,a.size()/2,a.size());
       t1.join(); 
       t2.join(); 

       }

       if(threads==4){
       
       std::thread t1(sestevanje, a, b,0,n4);
       std::thread t2(sestevanje, a, b,n4,n4+n4);
       std::thread t3(sestevanje, a, b,n4+n4,n4+n4+n4);
       std::thread t4(sestevanje, a, b,n4+n4+n4,a.size()); 
       t1.join(); 
       t2.join(); 
       t3.join(); 
       t4.join(); 

       }

       if(threads==8){
       
       std::thread t1(sestevanje, a, b,0,n8);
       std::thread t2(sestevanje, a, b,n8,n8+n8);
       std::thread t3(sestevanje, a, b,n8+n8,n8+n8+n8);
       std::thread t4(sestevanje, a, b,n8+n8+n8,n8+n8+n8+n8); 
       std::thread t5(sestevanje, a, b,n8+n8+n8+n8,n8+n8+n8+n8+n8);
       std::thread t6(sestevanje, a, b,n8+n8+n8+n8+n8,n8+n8+n8+n8+n8+n8);
       std::thread t7(sestevanje, a, b,n8+n8+n8+n8+n8+n8,n8+n8+n8+n8+n8+n8+n8);
       std::thread t8(sestevanje, a, b,n8+n8+n8+n8+n8+n8+n8,a.size()); 
       t1.join(); 
       t2.join(); 
       t3.join(); 
       t4.join(); 
       t5.join(); 
       t6.join(); 
       t7.join(); 
       t8.join(); 

       }

    }
}
   if(type==2){
    for(int i=0;i<1000000;i++){
       if(threads==1){
       std::thread t1(skalarniProdukt, a, b,0,a.size());
       t1.join(); 

       }

       if(threads==2){
       std::thread t1(skalarniProdukt, a, b,0,a.size()/2);
       std::thread t2(skalarniProdukt, a, b,a.size()/2,a.size());
       t1.join(); 
       t2.join(); 

       }

       if(threads==4){
       
       std::thread t1(skalarniProdukt, a, b,0,n4);
       std::thread t2(skalarniProdukt, a, b,n4,n4+n4);
       std::thread t3(skalarniProdukt, a, b,n4+n4,n4+n4+n4);
       std::thread t4(skalarniProdukt, a, b,n4+n4+n4,a.size()); 
       t1.join(); 
       t2.join(); 
       t3.join(); 
       t4.join(); 

       }

       if(threads==8){
       
       std::thread t1(skalarniProdukt, a, b,0,n8);
       std::thread t2(skalarniProdukt, a, b,n8,n8+n8);
       std::thread t3(skalarniProdukt, a, b,n8+n8,n8+n8+n8);
       std::thread t4(skalarniProdukt, a, b,n8+n8+n8,n8+n8+n8+n8); 
       std::thread t5(skalarniProdukt, a, b,n8+n8+n8+n8,n8+n8+n8+n8+n8);
       std::thread t6(skalarniProdukt, a, b,n8+n8+n8+n8+n8,n8+n8+n8+n8+n8+n8);
       std::thread t7(skalarniProdukt, a, b,n8+n8+n8+n8+n8+n8,n8+n8+n8+n8+n8+n8+n8);
       std::thread t8(skalarniProdukt, a, b,n8+n8+n8+n8+n8+n8+n8,a.size()); 
       t1.join(); 
       t2.join(); 
       t3.join(); 
       t4.join(); 
       t5.join(); 
       t6.join(); 
       t7.join(); 
       t8.join(); 

       }
}
    }
if(type=3){
    for(int i=0;i<1000000;i++){
       if(threads==1){
       std::thread t1(produkt, a, b,0,a.size());
       t1.join(); 
         for (int i = 0; i < c2.size(); i++)
    {
        for (int j = 0; j < c2[i].size(); j++)
        {
            cout<<c2[i][j];
        }
cout<<endl;
    }

       }

       if(threads==2){
       std::thread t1(produkt, a, b,0,a.size()/2);
       std::thread t2(produkt, a, b,a.size()/2,a.size());
       t1.join(); 
       t2.join(); 

       }

       if(threads==4){
       
       std::thread t1(produkt, a, b,0,n4);
       std::thread t2(produkt, a, b,n4,n4+n4);
       std::thread t3(produkt, a, b,n4+n4,n4+n4+n4);
       std::thread t4(produkt, a, b,n4+n4+n4,a.size()); 
       t1.join(); 
       t2.join(); 
       t3.join(); 
       t4.join(); 

       }

       if(threads==8){
       
       std::thread t1(produkt, a, b,0,n8);
       std::thread t2(produkt, a, b,n8,n8+n8);
       std::thread t3(produkt, a, b,n8+n8,n8+n8+n8);
       std::thread t4(produkt, a, b,n8+n8+n8,n8+n8+n8+n8); 
       std::thread t5(produkt, a, b,n8+n8+n8+n8,n8+n8+n8+n8+n8);
       std::thread t6(produkt, a, b,n8+n8+n8+n8+n8,n8+n8+n8+n8+n8+n8);
       std::thread t7(produkt, a, b,n8+n8+n8+n8+n8+n8,n8+n8+n8+n8+n8+n8+n8);
       std::thread t8(produkt, a, b,n8+n8+n8+n8+n8+n8+n8,a.size()); 
       t1.join(); 
       t2.join(); 
       t3.join(); 
       t4.join(); 
       t5.join(); 
       t6.join(); 
       t7.join(); 
       t8.join(); 

       }

    }


    }
    






    

}
