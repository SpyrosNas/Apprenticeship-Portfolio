//Project for the 2nd semester in programming with C++.
//Teacher: Ioannidis Rizos.
//Student: Nasopoulos Spyridon.
//This game is called Yper Atou (Top Trumps) and it is a card game 
//played between 2 players (or in this situation between the user and the pc)
//where each player picks up a random card and compare one of the three stats 
//each card have. Whoever has the bigger stat selected in the card wins the round.

#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
using namespace std;

class Car{
	protected:
    	string name;
		int speed, acceleration, power;
	public:
    	Car();
    	Car(string, int, int, int);
    	string get_name();
    	int get_speed();
    	int get_acceleration();
    	int get_power();
    	void set_name(string x);
    	void set_speed(int x);
    	void set_acceleration(int x);
    	void set_power(int x);
};
Car::Car() : name(""), speed(0), acceleration(0), power(0) {}
Car::Car(string n, int s, int a, int p) : name(n), speed(s), acceleration(a), power(p) {}
string Car::get_name(){
	return name;
}
int Car::get_speed(){
	return speed;
}
int Car::get_acceleration(){
	return acceleration;
}
int Car::get_power(){
	return power;
}
void Car::set_name(string x){
	name=x;
}
void Car::set_speed(int x){
	speed=x;
}
void Car::set_acceleration(int x){
	acceleration=x;
}
void Car::set_power(int x){
	power=x;
}
void draw_line(int n, char ch) {
    for (int i = 0; i < n; i++) {
        cout<<ch;
    }
    cout<<endl;
}
void initializeCars(Car Cars[], int brand){ // Create 15 car cards with random attributes
    string CarNames[]={
        "Ferrari", "Lamborghini", "Porsche", "McLaren", "Bugatti",
        "Aston Martin", "Maserati", "Koenigsegg", "Pagani", "BMW",
        "Mercedes", "Audi", "Jaguar", "Tesla", "Ford Mustang"
    };
    srand(static_cast<unsigned int>(time(0)));
    for (int i=0; i<brand; ++i){
        int speed=rand() % 201 + 100;           // Speed between 100 and 300
        int acceleration=rand() % 6 + 1;        // Acceleration between 1 and 6
        int power=rand() % 501 + 200;           // Power between 200 and 700
        Cars[i]=Car(CarNames[i], speed, acceleration, power);
    }
}
void printCar(Car &Car){
    cout<< "Name: " <<Car.get_name()<<endl;
    cout<< "Speed: " <<Car.get_speed()<<endl;
    cout<< "Acceleration: " <<Car.get_acceleration()<<endl;
    cout<< "Power: " <<Car.get_power()<<endl;
}
void playRound (string userName, Car &Car1, Car &Car2, int attribute, int &userScore, int &computerScore){
    int value1, value2;
    string attributeName;
    switch (attribute){
        case 1:
            value1 = Car1.get_speed();
            value2 = Car2.get_speed();
            attributeName = "Speed";
            break;
        case 2:
            value1 = Car1.get_acceleration();
            value2 = Car2.get_acceleration();
            attributeName = "Acceleration";
            break;
        case 3:
            value1 = Car1.get_power();
            value2 = Car2.get_power();
            attributeName = "Power";
            break;
    }
    cout<< "Comparing " << attributeName << "..." <<endl;
    cout<<userName<< "'s " << attributeName << ": " <<value1<<endl;
    cout<< "Computer's " << attributeName << ": " <<value2<<endl;
    if (value1 > value2){
        cout<< userName << " wins this round!" <<endl;
        userScore++;
    }else if (value1 < value2){
        cout<< "Computer wins this round!" <<endl;
        computerScore++;
    }else{
        cout<< "It's a tie!" <<endl;
    }
}
int main(){
    const int numCars = 15;
    Car Cars[numCars];
    initializeCars(Cars, numCars);
    draw_line(50, '=');
    cout<< "\n\n\n\n\tWelcome to the Top Trumps Car Game!\n\n\n\n" <<endl;
    draw_line(50, '=');
    string userName;
    cout<< "\nEnter your name: ";
    cin>>userName;
    char playAgain;
    do{
        int userScore = 0;
        int computerScore = 0;
        for (int round = 1; round <= 10; round++) {
            cout << "\nRound " << round << " of 10" <<endl;
            srand(static_cast<unsigned int>(time(0))); //---|
            int card1Index = rand() % numCars; //------------} Simulate drawing 2 random cards
            int card2Index; //------------------------------|
            do{
                card2Index = rand() % numCars;
            }while (card2Index == card1Index);
            Car Car1 = Cars[card1Index];
            Car Car2 = Cars[card2Index];
            int attribute;
            bool validAttribute = false; //Set the validation flag to false
            while (!validAttribute) { //Loop until a valid attribute is selected
                cout<< "Choose an attribute to compare: (1) Speed (2) Acceleration (3) Power" <<endl;
                cin>> attribute; //Get user's choise
                if (attribute >= 1 && attribute <= 3) { //Check if the input is valid
                    validAttribute = true; //If valid, exit the loop(s)
                }else {
                    cout<< "Invalid attribute selected!" <<endl;
                }
            }
            cout<< userName << "'s card:" <<endl;
            printCar(Car1);
            cout<<endl;
            cout<< "Computer's card:" <<endl;
            printCar(Car2);
            cout<<endl;
            playRound(userName, Car1, Car2, attribute, userScore, computerScore);
        }
        cout<< "\nGame Over! Final Scores:" <<endl;
        cout<< userName << ": " << userScore <<endl;
        cout<< "Computer: " << computerScore <<endl;
        if (userScore > computerScore) {
            cout<< userName << " wins the game!" <<endl;
        }else if (userScore < computerScore) {
            cout<< "Computer wins the game!" <<endl;
        }else{
            cout<< "It's a tie!" <<endl;
        }
        cout<< "Do you want to play again? (y/n): ";
        cin>> playAgain;
    }while (playAgain == 'y' || playAgain == 'Y');
    cout<< "Thank you for playing the Top Trumps Car Game!" <<endl;
    return 0;
}