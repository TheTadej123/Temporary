#include <iostream>
#include <vector>
#include <chrono>
#include <sstream>
#include <bitset>
#include <string>
#include <thread>
#include <random>
#include <cmath>
#include <omp.h>
#include <functional>
#include <stdlib.h>

using namespace std;
char hx[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
char bn[] = {'0', '1'};
int nfes = 0;

string hex_string(int lenght)
{
    string out;
    for (int i = 0; i < lenght; i++)
    {

        int rnd = rand() % 16;

        out = out + hx[rnd];
    }
    return out;
}

string binary_string(int lenght)
{
    string out;
    for (int i = 0; i < lenght; i++)
    {

        int rnd = rand() % 2;

        out = out + bn[rnd];
    }
    return out;
}
string hex_to_bin(string in)
{
    long int i = 0;
    string out = "";
    while (in[i])
    {
        switch (in[i])
        {
        case '0':
            out = out + "0000";
            break;
        case '1':
            out = out + "0001";
            break;
        case '2':
            out = out + "0010";
            break;
        case '3':
            out = out + "0011";
            break;
        case '4':
            out = out + "0100";
            break;
        case '5':
            out = out + "0101";
            break;
        case '6':
            out = out + "0110";
            break;
        case '7':
            out = out + "0111";
            break;
        case '8':
            out = out + "1000";
            break;
        case '9':
            out = out + "1001";
            break;
        case 'A':
        case 'a':
            out = out + "1010";
            break;
        case 'B':
        case 'b':
            out = out + "1011";
            break;
        case 'C':
        case 'c':
            out = out + "1100";
            break;
        case 'D':
        case 'd':
            out = out + "1101";
            break;
        case 'E':
        case 'e':
            out = out + "1110";
            break;
        case 'F':
        case 'f':
            out = out + "1111";
            break;
        default:
            cout << "Nepravilen vnos!" << endl;
        }
        i++;
    }
    return out;
}
string bin_to_hex(string a)
{
    string input = a;
    while (input.size() % 4 != 0)
    {
        input = "0" + input;
    }
    string output = string(input.size() / 4, '0');
    int outputoffset = 0;
    for (int i = 0; i < input.size(); i += 4)
    {
        int val = 0;
        for (int j = 0; j < 4; j++)
        {
            if (input[i + j] == '1')
            {
                val += (1 << (3 - j));
            }
        }
        output[outputoffset++] = hx[val];
    }
    return output;
}
int CharValue(char a)
{
    if (a == '0')
    {
        return 1;
    }
    if (a == '1')
    {
        return -1;
    }
    return 0;
}

int Ck(string a, int k)
{
    int out = 0;
    for (int i = 0; i < a.size() - k; i++)
    {

        int i1 = CharValue(a[i]);
        int i2 = CharValue(a[i + k]);
        int val = (i1 * i2);
        out += val;
    }
    nfes++;

    return out;
}

int PSL(string a)
{
    int max = 0;
    for (int k = 1; k < a.size(); k++)
    {
        int val1 = Ck(a, k);
        if (val1 > max)
        {
            max = val1;
        }
    }

    return max;
}
double MF(string a)
{
    double vsota = 0;

    for (int k = 1; k < a.size(); k++)
    {
        int val1 = Ck(a, k);
        vsota += (val1 * val1);
    }
    vsota = vsota * 2;

    double out = (a.size() * a.size()) / (vsota);
    return out;
}

string find_neighbour(string a, int poz)
{
    string out = a;
    if (a[poz] == '0')
    {
        out[poz] = '1';
    }
    else if (a[poz] == '1')
    {
        out[poz] = '0';
    }
    return out;
}

int main(int argc, char **argv)
{
    int l = atoi(argv[1]);
    int nfesLmt = atoi(argv[4]);
    int threads_num = atoi(argv[5]);
    string sequence;
    double mf = 0;
    int psl = 1000000000;
    srand(atoi(argv[3]));
    string type = argv[2];
    cout << "start" << endl;
    omp_set_num_threads(threads_num);
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    while (nfes < nfesLmt)
    {
        vector<string> opravila;
        string bin_pivot = binary_string(l);
        opravila.push_back(bin_pivot);
        for (int i = 1; i < threads_num; i++)
        {
            string bin_sosed = find_neighbour(bin_pivot, l - i);
            opravila.push_back(bin_sosed);
        }

        #pragma omp parallel
        {
        int id=omp_get_thread_num();
            if (type == "MF")
            {
                    double mf1 = MF(opravila[id]);
                    if (mf1 > mf)
                    {
                        mf = mf1;
                        sequence = opravila[id];
                    }
            }
             else if (type == "PSL")
            {
                int psl1 = PSL(opravila[id]);
                if (psl1 < psl)
                {
                    psl = psl1;
                    sequence = opravila[id];
                }
            
            }
        }
    }

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    int runtime = (std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()) / 1000000.0;
    double speed;
    if (runtime == 0)
    {
        speed = nfes;
    }
    else
    {
        speed = nfes / runtime;
    }

    cout << "L: " << l << endl;
    cout << "nfesLmt: " << nfesLmt << endl;
    cout << "seed: " << atoi(argv[3]) << endl;
    cout << "nfes: " << nfes << endl;
    cout << "runtime (sec): " << runtime << endl;
    cout << "speed: " << speed << endl;
    cout << "sequence: " << bin_to_hex(sequence) << endl;
    if (type == "MF")
    {
        cout << "MF: " << mf << endl;
    }
    else if (type == "PSL")
    {
        cout << "PSL: " << psl << endl;
    }
}
