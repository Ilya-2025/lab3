#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

enum class Choice {
    Rock = 1,
    Paper = 2,
    Scissors = 3
};

string choiceToString(Choice c) {
    switch (c) {
        case Choice::Rock:     return "Камень";
        case Choice::Paper:    return "Бумага";
        case Choice::Scissors: return "Ножницы";
        default:               return "?";
    }
}

class Player {
public:
    Choice choice;
    Player(Choice c = Choice::Rock) : choice(c) {}
};

class Game {
    Player player1;
    Player player2;
public:
    void play() {
        srand(time(0));

        int input;
        do {
            cout << "\n--- Новая игра ---\n";
            cout << "1. Камень\n2. Бумага\n3. Ножницы\n4. Выход\nВаш выбор (1-4): ";
            cin >> input;

            if (input == 4) {
                cout << "\nСпасибо за игру!\n";
                break;
            }

            if (input < 1 || input > 3) {
                cout << "\nНеверный ввод. Пожалуйста, введите 1, 2, 3 или 4.\n";
                continue;
            }

            player1 = Player(static_cast<Choice>(input));

            player2 = Player(static_cast<Choice>((rand() % 3) + 1));

            cout << "\nВы: " << choiceToString(player1.choice) << "\n";
            cout << "Комп: " << choiceToString(player2.choice) << "\n";
            cout << getResult() << "\n";

        } while (true);
    }
private:
    string getResult() const {
        if (player1.choice == player2.choice) return "--- Ничья! ---";
        if ((player1.choice == Choice::Rock && player2.choice == Choice::Scissors) ||
            (player1.choice == Choice::Paper && player2.choice == Choice::Rock) ||
            (player1.choice == Choice::Scissors && player2.choice == Choice::Paper))
            return "--- Вы победили! ---";
        return "--- Комп победил! ---";
    }
};

int main() {
    Game game;
    game.play();
    return 0;
}
