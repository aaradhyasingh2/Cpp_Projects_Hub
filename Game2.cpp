#include <iostream>
#include <vector>
#include <string>

class Question {
public:
    std::string questionText;
    std::vector<std::string> options;
    int correctOption;

    Question(const std::string& question, const std::vector<std::string>& choices, int correct)
        : questionText(question), options(choices), correctOption(correct) {}

    bool isCorrect(int userChoice) const {
        return userChoice == correctOption;
    }
};

class Quiz {
public:
    std::vector<Question> questions;
    int score;

    Quiz() : score(0) {}

    void addQuestion(const Question& question) {
        questions.push_back(question);
    }

    void startQuiz() {
        for (const auto& question : questions) {
            displayQuestion(question);
            int userChoice = getUserChoice();
            if (question.isCorrect(userChoice)) {
                std::cout << "Correct!\n";
                score++;
            } else {
                std::cout << "Incorrect! The correct answer was option " << question.correctOption + 1 << ".\n";
            }
            std::cout << "-----------------\n";
        }

        std::cout << "Quiz completed! Your score: " << score << " out of " << questions.size() << "\n";
    }

private:
    void displayQuestion(const Question& question) const {
        std::cout << question.questionText << "\n";
        for (size_t i = 0; i < question.options.size(); ++i) {
            std::cout << i + 1 << ". " << question.options[i] << "\n";
        }
    }

    int getUserChoice() const {
        int choice;
        do {
            std::cout << "Your choice (1-" << questions.back().options.size() << "): ";
            std::cin >> choice;

            if (choice < 1 || choice > static_cast<int>(questions.back().options.size())) {
                std::cout << "Invalid choice. Please choose a valid option.\n";
            }
        } while (choice < 1 || choice > static_cast<int>(questions.back().options.size()));

        return choice - 1; // Adjust to 0-based index
    }
};

int main() {
    // Create questions and add to the quiz
    Question q1("What is the capital of France?", {"Paris", "Berlin", "Madrid", "Rome"}, 0);
    Question q2("Which planet is known as the Red Planet?", {"Earth", "Mars", "Jupiter", "Venus"}, 1);
    Question q3("What is the largest mammal?", {"Elephant", "Blue Whale", "Giraffe", "Hippopotamus"}, 1);

    Quiz quiz;
    quiz.addQuestion(q1);
    quiz.addQuestion(q2);
    quiz.addQuestion(q3);

    // Start the quiz
    quiz.startQuiz();

    return 0;
}
