#ifndef CAESAR_CIPHER_H
#define CAESAR_CIPHER_H

#include <string>

bool is_alpha(char ch);
bool is_upper(char ch);
std::string decryptCaesarCipher(const std::string& encryptedText, int shift);
void character_count(const std::string& text);


#endif
