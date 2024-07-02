#include <iostream>
#include <fstream>
#include "caesar_cipher.h"

/**
* @brief Entry point of the program
* This is the main function of the program. The function reads an encrypted text file, it the decrypts
* it using the Caesar Cipher. It then performs a character count on the encrypted text.
*
* The program expects an input file named 'encrypted_text.txt', which contains the encrypted text, 
* followed by the decryption shift value. The program then prints the decrypted text and shows a character
* count for each character in the output.
* 
* @return returns 0 upon successful execution. 1 is returned if the file cannot be opened.
*/
int main() {
    /** This attempts to open the text file.*/
    std::ifstream inputFile("encrypted_text.txt");

    /** Checks if the file opening has failed.*/
    if (!inputFile) {
        std::cerr << "Error opening file." <<std::endl;
        return 1;
    }

    /** Checks the encrypted text from the file.*/
    std::string encryptedText((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    int decryptionShift;

    /** Reads the decryption shift value.*/
    inputFile >> decryptionShift;

    /** Decrypts the text using the caesar cipher.*/
    std:: string decryptedText = decryptCaesarCipher(encryptedText, decryptionShift) ;

    /** Prints out the character count for each letter */
    character_count(encryptedText); 

    /** Closes the input file*/
    inputFile.close() ;

    void testIsAlpha();

    return 0;
}
