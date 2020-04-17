#include <string>
#include <vector>

using namespace std;

class assesments {
    protected:

    vector<string> question;
    vector<string> answer;
    vector<string> answerKey;

    vector<int> grade;

    public:

    virtual vector<string> getQuestion() {
        return question;
    }
    virtual vector<string> getAnswer() {
        return answer;
    }
    virtual vector<string> getAnswerKey() {
        return answerKey;
    }

    virtual void setQuestion(vector<string> inputQuestion) {
        question = inputQuestion;
    }
    virtual void setAnswer(vector<string> inputAnswer) {
        answer = inputAnswer;
    }
    virtual void setAnswerKey(vector<string> inputAnswerKey) {
        answerKey = inputAnswerKey;
    }

    virtual void grade() {
        for(int i = 0;i < answer.size();i++) {
            if (answer[i] == answerKey[i]) {
                grade.push_back(100);
            }
        }
    }

};

class SingleQuestion : assesments {
    public:
    virtual string getQuestion() {
        return question[1];
    }
};

class Homework : assesments {

};

class Exam : assesments {

};

class Quiz : assesments {

};

class Essay : assesments {

};
