#include <string>
#include <vector>

using namespace std;

class assesments {
    protected:

    vector<string> question;
    vector<string> answer;
    vector<string> answerKey;

    int grade;

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

    virtual void gradeIt() {
        for(int i = 0;i < answer.size();i++) {
            if (answer[i] == answerKey[i]) {
                grade = 100;
            }
        }
    }
    virtual int getGrade() {
        return grade;
    }

};

class SingleQuestion : public assesments {
    public:
    virtual void setQuestion(vector<string> inputQuestion) {
        question.push_back(inputQuestion[0]);
    }
    virtual void setAnswer(vector<string> inputAnswer) {
        answer.push_back(inputAnswer[0]);
    }
    virtual void setAnswerKey(vector<string> inputAnswerKey) {
        answerKey.push_back(inputAnswerKey[0]);
    }

    virtual void gradeIt() {
        if(answer[0] == answerKey[0]) {
            grade = 100;
        } else {
            grade = 0;
        }
    }
};

class Homework : assesments {
    public:
    virtual void setQuestion(vector<string> inputQuestion, int size) {
        for(int i = 0; i < size; i++) {
            question.push_back(inputQuestion[i]);
        }
    }
    virtual void setAnswer(vector<string> inputAnswer, int size) {
        for(int i = 0; i < size; i++) {
            answer.push_back(inputAnswer[i]);
        }
    }
    virtual void setAnswerKey(vector<string> inputAnswerKey, int size) {
        for(int i = 0; i < size; i++) {
            answerKey.push_back(inputAnswerKey[i]);
        }
    }

    virtual void gradeIt() {
        grade = 0; //automatically give 0 if we aren't going to grade it at the moment
    }
};

class Exam : assesments {
    public:
    virtual void setQuestion(vector<string> inputQuestion, int size) {
        for(int i = 0; i < size; i++) {
            question.push_back(inputQuestion[i]);
        }
    }
    virtual void setAnswer(vector<string> inputAnswer, int size) {
        for(int i = 0; i < size; i++) {
            answer.push_back(inputAnswer[i]);
        }
    }
    virtual void setAnswerKey(vector<string> inputAnswerKey, int size) {
        for(int i = 0; i < size; i++) {
            answerKey.push_back(inputAnswerKey[i]);
        }
    }

    virtual void gradeIt() {
        int pointsize = 100 / answer.size(); // getting number of questions so we can divde evenly how much each question is worth
        grade = 0;
        for(int i = 0;i < answer.size(); i++) {
            if (answer[i] == answerKey[i]) {
                grade = grade + pointsize;
            }
        }
    }
};

class Quiz : public assesments {
    public:
    virtual void setQuestion(vector<string> inputQuestion) {
        for(int i = 0; i < 5; i++) {
            question.push_back(inputQuestion[i]);
        }
    }
    virtual void setAnswer(vector<string> inputAnswer) {
        for(int i = 0; i < 5; i++) {
            answer.push_back(inputAnswer[i]);
        }
    }
    virtual void setAnswerKey(vector<string> inputAnswerKey) {
        for(int i = 0; i < 5; i++) {
            answerKey.push_back(inputAnswerKey[i]);
        }
    }

    virtual void gradeIt() {
        int pointsize = 100 / 5; // quizes are always of size 5
        grade = 0;
        for(int i = 0;i < 5; i++) {
            if (answer[i] == answerKey[i]) {
                grade = grade + pointsize;
            }
        }
    }
};

class Essay : public assesments {
    private:
        int essayLength;
    public:
    void setEssayLength(int length) {
        essayLength = length;
    }

    virtual void setQuestion(vector<string> inputQuestion) {
        question.push_back(inputQuestion[0]);
    }
    virtual void setAnswer(vector<string> inputAnswer) {
        answer.push_back(inputAnswer[0]);
    }
    virtual void setAnswerKey(vector<string> inputAnswerKey) {
        answerKey.push_back(inputAnswerKey[0]);
    }

    virtual void gradeIt() {
        int count = 0;
        for(int i = 0; i < answer[0].size();i++) {
            if(answer[0][i] == ' ') {
                count++;
            }
        }
        if(count == essayLength) {
            grade = 000;
        } else {
            grade = 0;
        }
    }
};
