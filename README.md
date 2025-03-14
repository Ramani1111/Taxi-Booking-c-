# Taxi Booking System

## Overview

This is a **Taxi Booking System** implemented in C++. The system allows users to book taxis, cancel reservations, and display booking details.

## Features

- Book a taxi based on available routes.
- Calculate the total fare based on the number of passengers.
- Cancel a reservation.
- Display booking details.

## Installation & Compilation

### **Using g++ (MinGW) on Windows**

1. Open **Command Prompt** or **Git Bash**.
2. Navigate to the project directory:
   ```sh
   cd path/to/project
   ```
3. Compile the program:
   ```sh
   g++ taxi.cpp -o taxi.exe
   ```
4. Run the executable:
   ```sh
   .\taxi.exe
   ```

### **Using Visual Studio**

1. Open Visual Studio.
2. Create a **C++ Console App** and add `taxi.cpp`.
3. Click **Build** → **Build Solution**.
4. Run the application.

## Usage

1. **Run the program**.
2. **Choose an option**:
   - `1` → Book a taxi.
   - `2` → Cancel a reservation.
   - `3` → Exit.
3. Follow the on-screen instructions for booking or canceling reservations.
4. **To continue**, press 'Y'. To exit, press 'X'.

## Example

```
-------------------------------TAXI SYSTEM---------------------------
|taxiNo|  taxi Name         |    Starting point  |   ending point  |
|1.    | call taxi 1        |      bus stand     |  railway station|
|2.    | call taxi 2        |      bus stand     |     airport     |
|3.    | call taxi 3        |      bazaar        |     bus stand   |
|4.    | call taxi 4        |      bazaar        |     food street |
---------------------------------------------------------------------
Enter the number of reservations: 1
1. taxi booking
2. Cancellation
3. Exit
Enter your choice: 1
----------------------------
Passenger 1:
----------------------------
Enter the no of passengers(max:5): 3
Enter the starting point: bus stand
Enter the destination point: airport

Starting point: bus stand
Destination Point: airport
Name of the taxi: call taxi 2
Price per person: 20
Total amount: 60
```

## Known Issues

- The taxi ID (`tid`) is not displayed.
- User input validation could be improved.
- Support for additional locations can be added.

## Future Enhancements

- Implement a graphical user interface (GUI).
- Add an option for fare estimation before booking.
- Integrate a database for storing user reservations.

## Author

Developed by S.Ramani -CSE

Mepco Schelenk Engineering College ,Sivakasi.

