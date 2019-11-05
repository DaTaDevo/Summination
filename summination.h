#include <iostream>
#include <vector>
#include <string>

using namespace std;

static bool first = false;

struct numbers {
    int num = 0;
    string solution = "";
};

bool check(vector<numbers> *check, numbers number)
{
    bool add = false;
    if (first == false)
    {
        check->push_back(number);
        first = true;
    }
    
    for(unsigned int i = 0; i < check->size(); i++)
    {
        if (check->at(i).num != number.num)
        {
            add = true;
        }
        else
        {
            check->at(i).solution = number.solution;
            add = false;
            break;
        }
    }
    return add;
}

void sigma(int max,vector<numbers> *sort)
{
    for(int r = 1; r != max;r++)
    {
        numbers sum;
        for(int i = r;i<=max;i++)
        {
            string strI = to_string(i);
            sum.solution += strI +"+";
            sum.num+= i;
        }
        sum.solution += "= ";
        if(check(sort, sum))
        {
            sort->push_back(sum);
            
            for(unsigned long i = sort->size()-1; i > 0; i--)
            {
                if(sort->at(i).num < sort->at(i-1).num)
                {
                    swap(sort->at(i-1), sort->at(i));
                }
            }
        }
    }
}


void showVector(vector<numbers>* vec)
{
    for(unsigned int i = 0; i < vec->size(); i++)
        cout <<vec->at(i).solution << vec->at(i).num<< endl;
}

void  summination (unsigned int max, vector<numbers> sortVector)
{
    
    for(int i = 1; i <= max; i++)
    sigma(i,&sortVector);
    
    showVector(&sortVector);
    
}
