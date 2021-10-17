#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
using namespace std;

void sestevanje(vector<double> a, vector<double> b)
{
    auto begin = std::chrono::high_resolution_clock::now();
    for (int k = 0; k < 1; k++)
    {
        vector<double> c;
        for (int i = 0; i < a.size(); i++)
        {
            c.push_back(a[i] + b[i]);
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);
}

void skalarniprodukt(vector<double> a, vector<double> b)
{
    auto begin = std::chrono::high_resolution_clock::now();
    for (int k = 0; k < 10; k++)
    {
        double vsota = 0;
        for (int i = 0; i < a.size(); i++)
        {
            vsota += a[i] + b[i];
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);
}

void produkt(vector<vector<double>> a, vector<vector<double>> b)
{
    auto begin = std::chrono::high_resolution_clock::now();
    for (int n = 0; n < 10; n++)
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
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);
}

int main()
{
    cout << "Vnesite velikost matrik" << endl;
    int size;
    cin >> size;

    vector<vector<double>> a;
    vector<vector<double>> b;

    for (int i = 0; i < size; i++)
    {
        vector<double> temp;
        for (int j = 0; j < size; j++)
        {
            temp.push_back(rand() % 100);
        }
        a.push_back(temp);
        b.push_back(temp);
    }

    produkt(a, b);
}
