#include<iostream>
#include <string>
using namespace std;

class taxi {
protected:
    static int tid;
    int taxiid;
    string taxi_name;
public:
    taxi();
    void get_details();
    static int get_tid();
};

int taxi::tid = 1;

taxi::taxi() {
    cout << "-----------------------TAXI SYSTEM------------------------" << endl;
}

void taxi::get_details() {
    taxiid = tid++;
}

int taxi::get_tid() {
    return tid;
}

class calltaxi : public taxi {
protected:
    int number_of_passengers,price,amount;
    string from, to, name;
    bool cancelled; // New member variable to track cancellation status
public:
    calltaxi();
    void passenger_details();
    bool cancel_reservation();
    void display();
};

calltaxi::calltaxi() {
    cancelled = false; // Initialize cancellation status to false
}

void calltaxi::passenger_details() {
    cout << "enter the no of passengers(max:5): ";
    cin >> number_of_passengers;

    bool validEntry = false;
    while (!validEntry) {
	cin.ignore();
        cout << "Enter the starting point: ";
        getline(cin,from);
        cout << "Enter the destination point: ";
        getline(cin,to);

        if (from == "bus stand" && to == "railway station") {
	    price=30;
	    amount=price*number_of_passengers;	
            taxi_name = "Call taxi 1";
            validEntry = true;
        }
        else if (from == "bus stand" && to == "airport") {
	    price=20;
	    amount=price*number_of_passengers;
            taxi_name = "call taxi 2";
            validEntry = true;
        }
        else if (from == "bazaar" && to == "bus stand") {
	    price=25;
	    amount=price*number_of_passengers;
            taxi_name = "call taxi 3";
            validEntry = true;
        }
        else if (from == "bazaar" && to == "food street") {
	    price=50;
	    amount=price*number_of_passengers;
            taxi_name = "call taxi 4";
            validEntry = true;
        }
        else {
            cout << "Invalid entry. Please enter valid 'from' and 'to' points." << endl;
        }
    }
}

bool calltaxi::cancel_reservation() {
    if (cancelled) {
        cout << "Reservation has already been canceled." << endl;
        return false; // Return false to indicate cancellation was unsuccessful
    }
    else {
        cancelled = true;
        cout << "Reservation is canceled." << endl;
        return true; // Return true to indicate cancellation was successful
    }
}

void calltaxi::display() {
    cout << "*" << endl;
    cout << "Starting point: " << from << endl;
    cout << "Destination Point: " << to << endl;
    cout << "Name of the taxi: " << taxi_name << endl;
    cout << "Price per person: " << price << endl;
    cout << "Total amount: " << amount << endl;
    cout << "**" << endl;
}

int main() {
    int n, op;

    do {
        cout << "-------------------------------TAXI SYSTEM---------------------------" << endl;
        cout << "---------------------------------------------------------------------" << endl;
        cout << "|taxiNo|  taxi Name         |    Starting point  |   ending point  | " << endl;
        cout << "---------------------------------------------------------------------" << endl;
        cout << "|1.    | call taxi 1        |      bus stand     |  railway station| " << endl;
        cout << "|2.    | call taxi 2        |      bus stand     |     airport     | " << endl;
        cout << "|3.    | call taxi 3        |      bazaar        |     bus stand   | " << endl;
        cout << "|4.    | call taxi 4        |      bazaar        |     food street | " << endl;
        cout << "---------------------------------------------------------------------" << endl;

        cout << "Enter the number of reservations: ";
        cin >> n;

        calltaxi taxi[n];

        cout << "1. taxi booking" << endl;
        cout << "2. Cancellation" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> op;

        switch (op) {
            case 1: {
                for (int res = 0; res < n; res++) {
                    cout << "----------------------------" << endl;
                    cout << "Passenger " << res + 1 << ":" << endl;
                    cout << "----------------------------" << endl;
                    taxi[res].get_details();
                    taxi[res].passenger_details();
		    taxi[res].display();
                }
                break;
            }
            case 2: {
                int Choice;
                cout << "Enter the reservation number to cancel (Enter 0 to exit): ";
                cin >> Choice;

                while (Choice != 0) {
                    if (Choice <= n && Choice > 0) {
                        if (taxi[Choice - 1].cancel_reservation()) {
                            // Cancellation successful, perform any additional cleanup or processing
                        }
                    }
                    else {
                        cout << "Invalid reservation number." << endl;
                    }

                    cout << "Enter the reservation number to cancel (Enter 0 to exit): ";
                    cin >> Choice;
                }
                break;
            }
            case 3: {
                return 0;
            }
            default: {
                cout << "Enter a valid choice...." << endl;
            }
        }

        char continue_choice;
        cout << "Press 'Y' to continue and 'X' to exit: ";
        cin >> continue_choice;
        if (continue_choice != 'Y' && continue_choice != 'y') {
            return 0;
        }
    } while (true);

    return 0;
}
