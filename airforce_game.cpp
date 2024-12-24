#include <iostream>
#include <thread>
#include <chrono>

// ANSI escape codes for colors
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

// Function to print colored text
void printColoredText(const std::string& text, const std::string& color) {
    std::cout << color << text << RESET << std::endl;
}

// Function to display the main menu
void displayMenu() {
    printColoredText("Welcome to the Air Force Trivia Game!", BLUE);
    printColoredText("1. Start Game", CYAN);
    printColoredText("2. View Rules", CYAN);
    printColoredText("3. Exit", CYAN);
    std::cout << "Enter your choice: ";
}

// Function for user input validation (for answers)
int getValidAnswer() {
    int answer;
    while (true) {
        std::cout << "Enter your answer (1-4 or 0 to exit): ";
        std::cin >> answer;
        if (answer >= 0 && answer <= 4) {
            return answer;
        } else {
            printColoredText("Invalid input. Please choose a number between 0 and 4.", RED);
        }
    }
}

// Function to animate correct answer feedback
void animateCorrectAnswer() {
    printColoredText("Correct!", GREEN);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

// Function to animate incorrect answer feedback
void animateIncorrectAnswer() {
    printColoredText("Incorrect!", RED);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

// Function to start the trivia game
void startGame() {
    int score = 0;
    int totalQuestions = 30;
    int answer;

    // Air Force questions and answers
    std::string questions[30] = {
        "What is the primary purpose of a pavement operator in the Air Force?",
        "Which equipment is used to perform grading and excavation tasks?",
        "What is the maximum allowable slope for a runway?",
        "Which type of asphalt mixture is typically used for military airfields?",
        "What is the proper method for conducting a compaction test?",
        "Which safety equipment is required for heavy machinery operators?",
        "What is the standard size of a runway for military aircraft?",
        "Which material is commonly used as a base layer in road construction?",
        "What is the purpose of seal coating on asphalt?",
        "How often should pavement inspections be conducted?",
        "What is the primary function of a grader?",
        "What does the term 'compaction' refer to in pavement construction?",
        "What is the most common cause of cracks in asphalt pavement?",
        "Which type of concrete is used for high-strength applications?",
        "What is the main function of a bulldozer?",
        "What is the ideal temperature for laying hot mix asphalt?",
        "What is a core sample used for in pavement testing?",
        "What is the standard width of a military taxiway?",
        "What is the primary purpose of an airfield lighting system?",
        "What does the term 'aggregate' refer to in pavement materials?",
        "What is the main purpose of a pavement maintenance plan?",
        "Which test measures the load-bearing capacity of soil?",
        "What is the purpose of a culvert in road construction?",
        "What is the standard thickness of asphalt layers for airfields?",
        "What is the recommended slope for drainage on a runway?",
        "What is the main use of a nuclear density gauge?",
        "Which type of crack is caused by freeze-thaw cycles?",
        "What is the purpose of a prime coat in asphalt paving?",
        "What is the most effective method for repairing potholes?",
        "What is the primary use of a backhoe in construction?"
    };

    std::string options[30][4] = {
        {"1. To operate military aircraft", "2. To construct and maintain airfields", "3. To train new recruits", "4. To manage logistics"},
        {"1. Bulldozer", "2. Excavator", "3. Grader", "4. Forklift"},
        {"1. 1% to 2%", "2. 2% to 3%", "3. 3% to 4%", "4. 5% to 6%"},
        {"1. Hot mix asphalt", "2. Cold mix asphalt", "3. Concrete", "4. Gravel"},
        {"1. Visual inspection", "2. Nuclear density gauge", "3. Manual compaction", "4. Core sample extraction"},
        {"1. Hard hat and gloves", "2. Safety vest and boots", "3. Both 1 and 2", "4. None of the above"},
        {"1. 150 feet", "2. 200 feet", "3. 300 feet", "4. 500 feet"},
        {"1. Gravel", "2. Sand", "3. Crushed stone", "4. Asphalt"},
        {"1. Increase durability", "2. Prevent water penetration", "3. Enhance appearance", "4. All of the above"},
        {"1. Weekly", "2. Monthly", "3. Annually", "4. Every two years"},
        {"1. Leveling", "2. Excavating", "3. Compacting", "4. Demolishing"},
        {"1. Strengthening the soil", "2. Removing debris", "3. Increasing density", "4. Laying asphalt"},
        {"1. Heavy traffic", "2. Poor compaction", "3. Temperature changes", "4. All of the above"},
        {"1. Reinforced concrete", "2. Precast concrete", "3. High-performance concrete", "4. None of the above"},
        {"1. Excavating", "2. Leveling", "3. Demolishing", "4. Compacting"},
        {"1. 150°F", "2. 200°F", "3. 250°F", "4. 300°F"},
        {"1. Measuring thickness", "2. Determining strength", "3. Analyzing composition", "4. All of the above"},
        {"1. 25 feet", "2. 50 feet", "3. 75 feet", "4. 100 feet"},
        {"1. Increase visibility", "2. Improve aesthetics", "3. Enhance durability", "4. None of the above"},
        {"1. Sand", "2. Gravel", "3. Crushed stone", "4. All of the above"},
        {"1. Prevent failures", "2. Improve safety", "3. Reduce costs", "4. All of the above"},
        {"1. CBR test", "2. Density test", "3. Load test", "4. Penetration test"},
        {"1. Divert water", "2. Support the road", "3. Prevent erosion", "4. All of the above"},
        {"1. 2 inches", "2. 4 inches", "3. 6 inches", "4. 8 inches"},
        {"1. 0.5%", "2. 1%", "3. 1.5%", "4. 2%"},
        {"1. Determine moisture content", "2. Measure compaction", "3. Analyze soil strength", "4. All of the above"},
        {"1. Fatigue cracks", "2. Alligator cracks", "3. Thermal cracks", "4. Longitudinal cracks"},
        {"1. Increase adhesion", "2. Seal the surface", "3. Prevent water infiltration", "4. All of the above"},
        {"1. Cold patching", "2. Hot mix patching", "3. Throw-and-roll", "4. Semi-permanent repair"},
        {"1. Excavating", "2. Loading", "3. Digging trenches", "4. All of the above"}
    };

    int correctAnswers[30] = {
        2, 3, 1, 1, 2, 3, 3, 3, 4, 3,
        1, 3, 4, 1, 2, 3, 4, 3, 1, 4,
        4, 1, 4, 2, 2, 2, 3, 4, 2, 4
    };

    // Ask the questions
    for (int i = 0; i < totalQuestions; i++) {
        std::cout << "\nQuestion " << (i + 1) << ": " << questions[i] << std::endl;
        for (int j = 0; j < 4; j++) {
            std::cout << options[i][j] << std::endl;
        }

        answer = getValidAnswer();

        if (answer == 0) {
            printColoredText("\nExiting the game...", MAGENTA);
            break;
        }

        if (answer == correctAnswers[i]) {
            animateCorrectAnswer();
            score++;
        } else {
            animateIncorrectAnswer();
            printColoredText("The correct answer was: " + options[i][correctAnswers[i] - 1], GREEN);
        }

        std::cout << "Your score: " << score << "/" << (i + 1) << std::endl;
    }

    printColoredText("\nGame Over! Final Score: " + std::to_string(score), MAGENTA);
}

// Function to show the rules of the game
void showRules() {
    printColoredText("Air Force Trivia Game Rules:", YELLOW);
    printColoredText("1. Answer the questions by choosing a number (1-4).", YELLOW);
    printColoredText("2. Enter 0 at any time to exit the game.", YELLOW);
    printColoredText("3. There is no time limit to answer each question.", YELLOW);
    printColoredText("4. You earn 1 point for each correct answer.", YELLOW);
    printColoredText("5. If you answer incorrectly, the correct answer will be displayed.", YELLOW);
    printColoredText("6. Have fun!", YELLOW);
}

int main() {
    int choice;
    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                startGame();
                break;
            case 2:
                showRules();
                break;
            case 3:
                printColoredText("Thank you for playing!", MAGENTA);
                return 0;
            default:
                printColoredText("Invalid choice. Please try again.", RED);
        }
    }
}
