#include <iostream>
#include <fstream>
#include <string>
#include "caesar_cipher.h"

/** 
* @brief Checks if a character is in the alphabet.
* 
* This function determines if a character is in the alphabet. It is used to check 
* uppercase (A-Z) and lowercase (a-z) letters.
*
* @param ch The character to check
* @return True if 'ch' is an alphabetic letter, false if it is not.
*/
bool is_alpha(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

/**
* @brief Checks if a character is an uppercase letter.
*
* This function is used to check if a letter is an uppercase (A-Z) or a lowercase (a-z).
* If a letter is uppercase it returns true and false if not.
*
* @param ch Is the character to check.
* @brief True if the character is an uppercase letter, false if not.
*/
bool is_upper(char ch) {
    return ch >= 'A' && ch <= 'Z';
}

/**
* @brief Converts an uppercase letter to a lowercase letter. 
*
* This function simply checks if a character is uppercase. If it is, it converts it to 
* a lowercase letter. If the said characacter is lowercase, it remains unchanged.
* @param The character to convert.
* @return The converted lowercase verison of 'ch' is returned. Otherwise, 'ch' itself.
*/
char to_lower(char ch) {
    if (is_upper(ch)) {
        return ch - 'A' + 'a';
    }
    return ch;
}

/**
* @brief Decrypts text encrypted with the caesar cipher.
*
* This function uses the Caesar cipher decryption process to a given string.
* Each character in the encrypted text is shifted backwards in the alphabet
* by the specified shift amount. Non alphabetic characters are to be unchanged.
*
* @param encryptedText Is the encrypted text to decrypt.
* @param shift Is the shift value used in the cipher. This value is subtracted
*              from each alphabetic character in the encrypted text
* @return The decrypted text
*/
std::string decryptCaesarCipher(const std::string& encryptedText, int shift) {
    std::string decryptedText = encryptedText;

    for (std::size_t i = 0; i < decryptedText.size(); ++i) {
        char& ch = decryptedText[i];
        if (is_alpha(ch)) {
            char base = is_upper(ch) ? 'A' : 'a';
            /** This applies the cipher decryption formula */
            ch = (ch - base - shift +26) % 26 + base;
        }
    }

    return decryptedText;
}

/** 
* @brief Counts the occurance of each letter in the text and prints the result.
*
* @param text This is the text to analyse.
*/
void character_count(const std::string& text){
    int freq[26] = {0};

    for (char ch : text) {
        if (is_alpha(ch)) {
            ch = to_lower(ch);
            freq[ch - 'a']++;
        }
    }

    for (int i = 0; i <26; ++i) {
        if (freq[i] > 0) {
            std::cout << "Letter '" << static_cast<char>('a' + i) << "' appears " << freq[i] << " times." << std::endl;
        }
    }
}


