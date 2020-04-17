#include <iostream>
#include <vector>
#include <string>
#include "classDef.cpp"

using namespace std;

int main()
{
    SingleQuestion vince;
    vector<string> inputQuestion = {"Yes or no"};
    vector<string> inputAnswer = {"it actually doesnt have a key either"};
    vector<string> inputAnswerKey = {"it actually doesnt have a key either"};
    vince.setQuestion(inputQuestion);
    vince.setAnswer(inputAnswer);
    vince.setAnswerKey(inputAnswerKey);

    vince.gradeIt();

    cout<<vince.getGrade();

    return 0;
} 