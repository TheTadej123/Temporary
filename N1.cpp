#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
using namespace std;

void sestevanje(vector<double> a, vector<double> b)
{

    vector<double> c;
    for (int i = 0; i < a.size(); i++)
    {
        c.push_back(a[i] + b[i]);
    }
}

void skalarniprodukt(vector<double> a, vector<double> b)
{

    double vsota = 0;
    for (int i = 0; i < a.size(); i++)
    {
        vsota += a[i] + b[i];
    }
}

void produkt(vector<vector<double>> a, vector<vector<double>> b)
{
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            for (int k = 0; k < a[i].size(); k++)
            {
            }
        }
    }
}

int main()
{
    cout << "Vnesite velikost matrik" << endl;
    int size;
    cin >> size;
    vector<double> a;
    vector<double> b;

    for (int i = 0; i < size; i++)
    {
        a.push_back(rand() % 100);
        b.push_back(rand() % 100);
    }
    
    auto begin = std::chrono::high_resolution_clock::now();

    for(int i=0;i<1000000;i++){
       sestevanje(a, b); 
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);
}
