#include "CaesarCipher.hpp"
#include "CipherMode.hpp"

#include <iostream>
#include <string>

CaesarCipher::CaesarCipher(const std::size_t cipherKey) {
    key_ = cipherKey;
}
CaesarCipher::CaesarCipher(const std::string cipherKey) {
    if (cipherKey.empty()) {
        key_ = 0;
    }
    else {
        key_ = std::stoul(cipherKey);
    }
}

std::string CaesarCipher::applyCipher(const std::string inputText, const CipherMode mode) {
    // Create the output string
    std::string outputText;

    // Create the alphabet container
    const std::size_t alphabetSize{alphabet_.size()};

    // Make sure that the key is in the range 0 - 25
    const std::size_t truncatedKey{key_ % alphabetSize};

    // Loop over the input text
    char processedChar{'x'};
    for (const auto& origChar : inputText) {
        // For each character in the input text, find the corresponding position in
        // the alphabet by using an indexed loop over the alphabet container
        for (size_t i{0}; i < alphabetSize; ++i) {
            if (origChar == alphabet_[i]) {
                // Apply the appropriate shift (depending on whether we're encrypting
                // or decrypting) and determine the new character
                // Can then break out of the loop over the alphabet
                switch (mode) {
                case CipherMode::encrypt:
                    processedChar = alphabet_[(i + truncatedKey) % alphabetSize];
                    break;
                case CipherMode::decrypt:
                    processedChar = alphabet_[(i + alphabetSize - truncatedKey) %
                                             alphabetSize];
                    break;
                }
                break;
            }
        }

        // Add the new character to the output text
        outputText += processedChar;
    }

    return outputText;
}

