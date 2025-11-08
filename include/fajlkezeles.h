#ifndef FAJLKEZELES_H
#define FAJLKEZELES_H
/**
 * @brief Reads the files from the data directory.
 * If reading fails it calls createNonExistantFiles.
 *
 */
void readFromFiles();
/**
 * @brief Creates the files.
 */
void createNonExistantFiles();
/**
 * @brief Saves the list in to text format in the data directory.
 */
void writeToFiles();
#endif
