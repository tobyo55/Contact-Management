Project Description:
The C++ Contact Management System is a console-based application that organizes contacts through a menu-driven interface. Users can add, search, delete, mark as favorite, display favorites, and edit contacts. Data is stored in a "number.txt" file, leveraging structures for contact representation and file handling for persistence. The program features input validation for phone numbers, and the main loop provides continuous user interaction until exit. This system offers a functional solution for managing contacts in a command-line environment.

Now discuss the code or project in details:
1. Header Files and Namespace:
The code includes several standard C++ header files, such as `<iostream>`, `<fstream>`, and `<bits/stdc++.h>`. The `namespace std` is also used.

2. Contact Structure:
The `Contact` structure is defined to represent a contact with attributes like first name (`fname`), last name (`lname`), phone number (`phone_num`), and a flag for whether it's a favorite (`isFavorite`).

3. Global Variables:
Global variables like `fname`, `lname`, and `phone_num` are declared, which might be considered as potential candidates for local variables within functions.

4. Function Prototypes:
Functions like `addContact()`, `searchContact()`, etc., are declared. These functions handle specific functionalities of the contact management system.

5. Main Function:
The `main` function contains the main logic of the program, providing a menu-driven interface using a `switch` statement. The user can choose options like adding, searching, deleting, marking as favorite, displaying favorites, editing, and accessing help.

6. Function Implementations:
•	`self_exit()`: Displays a closing message and exits the program.
•	`help()`: Displays a help menu explaining each option in the system.
•	`addContact()`: Adds a new contact by taking user input for first name, last name, and phone number, validating the input, and storing the contact information in a file named "number.txt".
•	`searchContact()`: Searches for a contact by first name or last name, displaying the contact details if found.
•	`deleteContact()`: Allows the user to delete a contact by entering the name. Updates the contact list in the "number.txt" file accordingly.
•	`markAsFavorite()`: Marks a contact as a favorite, updating the "number.txt" file.
•	`displayFavorites()`: Displays a list of contacts marked as favorites.
•	`editContact()`: Edits the information of an existing contact, updating the "number.txt" file.
•	`check_digits()` and `check_numbers()`: Helper functions for input validation.

7. File Operations:
The code uses file handling to read from and write to the "number.txt" file to persist contact information.

8. Input Validation:
The code incorporates basic input validation, ensuring that the phone number contains only digits and is 11 characters long.

9. Looping:
The program is designed to run in a loop until the user chooses the exit option.

10. Output Messages:
Various messages are displayed to the user indicating the success or failure of operations.

11. Menu Styling:
The code uses simple styling, like clearing the screen and setting color, to enhance the user interface.

12. Comments:
Although there are some comments in the code, additional comments could be added for clarity, especially in complex sections.

13. Exit Handling:
The `self_exit()` function handles the program exit, displaying a closing message.

Certainly, let's delve into more details:

14. File Structure:
The code consists of a single C++ source file, `contact_management_system.cpp`. Additionally, there's a "number.txt" file used for storing contact information persistently.

15. Contact Structure Usage:
The `Contact` structure serves as a convenient way to encapsulate the attributes of a contact, promoting code organization and readability.

16. Input Handling:
The program utilizes the `cin` object to gather user input for various operations. Input validation functions (`check_digits()` and `check_numbers()`) ensure the integrity of the entered data, particularly for the 11-digit phone number requirement.

17. Menu Interface:
The main loop presents a menu-driven interface, providing the user with a clear set of options. The `switch` statement efficiently directs the program flow based on the user's choice.

18. File I/O:
File handling operations are crucial for reading and writing contact information. The program uses `ofstream` to append new contacts to the "number.txt" file during addition and modifies the file during deletion, marking as favorite, and editing operations.

19. Dynamic Data Structures:
The program uses dynamic data structures, specifically a vector of `Contact` structures, when editing contacts. This allows for flexibility in managing contact information dynamically.

20. Error Handling:
The code incorporates basic error handling, such as checking whether the file is open during the addition of a new contact and displaying appropriate messages in case of errors.

21. User Feedback:
Informative messages are displayed to the user after each operation, indicating the success or failure of the performed action. This enhances user experience and provides clarity.

22. Styling and Aesthetics:
The use of `system("cls")’ clears the console screen, creating a cleaner user interface. Additionally, the `system("color 0A")` statement sets the console color to a combination of black background and green text for visual appeal.

23. Exit Handling:
The `self_exit()` function not only terminates the program but also displays a thank you message, providing a pleasant exit experience for the user.

How to build and run the project:
To run the provided C++ code, compile it using a C++ compiler or IDE such as Code::Blocks or Visual Studio. Execute the generated executable, follow on-screen prompts for contact management operations (add, search, delete, etc.), and exit by selecting option 8. Handle any compiler or runtime errors, and ensure the presence of necessary files like "number.txt" or adjust file paths in the code if needed.

Instructions or Dependencies:
The C++ code for the contact management system is functional but has room for improvement. Addressing platform dependencies with `<conio.h>` by exploring alternative console input/output methods is advised. Further enhancing input validation, ensuring file availability, and incorporating robust error handling can improve the code. Thorough testing, increased modularity, and user-friendly features, such as confirmation prompts, are essential. Clear documentation aids understanding, and attention to potential platform-specific code ensures cross-platform compatibility.



Name: Shahriar Hasan
ID: 222-115-230
