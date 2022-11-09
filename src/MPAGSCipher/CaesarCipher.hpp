#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include <string>

class CaesarCipher {
    public:
        explicit CaesarCipher(std::size_t key);
        explicit CaesarCipher(std::string key);

        std::string applyCipher(const std::string& inputText, const bool encrypt);
    
    private:
        std::size_t key_;

};

#endif