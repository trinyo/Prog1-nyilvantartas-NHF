#ifndef MENUELEMEK_H
#define MENUELEMEK_H
/**
 * @brief Displays the main menu of the console application.
 *
 * This menu serves as the primary navigation hub, providing access to all major functions
 * (Listing, Data Creation, Data Management, and Exit).
 *
 * @return void
 */
void displayMainMenu();

/**
 * @brief Displays the submenu for data listing and viewing.
 *
 * This menu allows the user to select various options for viewing and analyzing the stored data,
 * such as listing all students, teachers, or students based on scores/groups.
 *
 * @return void
 */
void displayListMenu();

/**
 * @brief Displays the submenu for adding new data.
 *
 * This menu is used to select whether the user wants to add a new student or a new teacher record.
 *
 * @return void
 */
void displayNewDataMenu();

/**
 * @brief Displays the submenu for data management (update and delete operations).
 *
 * This menu allows the user to select options for modifying existing records (update) or
 * permanently removing them (delete).
 *
 * @return void
 */
void displayDataManagementMenu();

/**
 * @brief Clears the console screen.
 *
 * Utility function to improve readability and user experience when switching between menus.
 * The implementation depends on the operating system (e.g., using system("clear") or system("cls")).
 *
 * @return void
 */
void clear_screen();

/**
 * @brief Pauses the program execution until the user presses the ENTER key.
 *
 * Utility function used after displaying information or error messages to ensure the user has time to read the output.
 *
 * @return void
 */
void waitForEnter();
#endif
