#include "CaesarCipher.hpp"

#include <iostream>
#include "CipherMode.hpp"

std::string runCaesarCipher(const std::string& inputText, const std::size_t key,
                            const bool encrypt);

CaesarCipher::CaesarCipher(std::size_t key)
{
    key_ = key;
}

CaesarCipher::CaesarCipher(std::string key)
{
    if (!key.empty()) {
        // Before doing the conversion we should check that the string contains a
        // valid positive integer.
        // Here we do that by looping through each character and checking that it
        // is a digit. What is rather hard to check is whether the number is too
        // large to be represented by an unsigned long, so we've omitted that for
        // the time being.
        // (Since the conversion function std::stoul will throw an exception if the
        // string does not represent a valid unsigned long, we could check for and
        // handled that instead but we only cover exceptions very briefly on the
        // final day of this course - they are a very complex area of C++ that
        // could take an entire course on their own!)

        for (const auto& elem : key) {
            if (!std::isdigit(elem)) {
                std::cerr
                    << "[error] cipher key must be an unsigned long integer for Caesar cipher,\n"
                    << "        the supplied key (" << key_
                    << ") could not be successfully converted" << std::endl;
            }
        }
        key_ = std::stoul(key);  // converts string to unsigned long
    }
}

std::string CaesarCipher::applyCipher(const std::string& inputText, const bool encrypt)
{
    return runCaesarCipher(inputText, key_, encrypt);
}