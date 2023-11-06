#include<iostream>
#include<queue>
#include<thread>
using namespace std;

queue<string> input_Q_N_A()
{
    queue<string> questionQueue;
    string text;
    int numberOfQuestions;
    cout<<"how many questions you want to ask (please enter an integer)?: ";
    cin>>numberOfQuestions;

    cin.ignore();

    for(int i=0; i<numberOfQuestions; i++)
    {
        cout<<"enter your question "<<i+1<<"/"<<numberOfQuestions<<": ";
        getline(cin, text);
        questionQueue.push(text);
    }
    return questionQueue;
}

void officeHour()
{
    queue<string> q = input_Q_N_A();
    int count=1;
    int S=q.size();
    srand((unsigned) time(NULL));
    while(!q.empty())
    {
        int random=1+(rand()%3);
        cout<<"Question "<<count++<<"/"<< S <<": "<<q.front()<<endl;
        q.pop();
        this_thread::sleep_for(chrono::seconds(random));
        cout<<"......Processed: "<<random<<" seconds......"<<endl
        <<"Professor: That's a great question!"<<endl<<endl;
    }
    cout<<"All questions answered!"<<endl;
}

int main()
{
    officeHour();
}