#include "header.h"

int get_key() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> dis(1000, 9999);
    
    return dis(gen);
}

int pseudo_hash() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> dis(100000, 999999);
    
    return dis(gen);
}

int createUser(std::string username) {
    const int public_key = get_key();
    const int private_key = get_key();

    users[public_key] = std::make_unique<User>(private_key, public_key, username);

    return public_key;
}

int createTransaction(int from, int to, unsigned long long value) {
    const int hash = pseudo_hash();
    mempool[hash] = std::make_unique<Transaction>(from, to, value);
    return hash;
}

unsigned sum(std::vector<unsigned>& marks) {
    unsigned summa = 0;
    for (const auto& mark : marks) { 
        summa += mark; 
    }
    return summa;
}