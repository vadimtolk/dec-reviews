#include "header.h"

bool simple_transfer(int from, int to, const unsigned long long& amount) {
    auto sender = users.find(from);
    auto getter = users.find(to);

    int entered_private_key = 0;
    std::cout << "Sign transaction with your private key: ";
    std::cin >> entered_private_key;

    if (entered_private_key != sender->second->get_private_key() || sender->second->get_balance() < amount) return false; 

    sender->second->change_balance(amount, false);
    getter->second->change_balance(amount, true);

    return true;
}

bool article_contract(int address, const unsigned long long& amount, bool is_collect) {
    auto user = users.find(address);
    int entered_private_key = 0;

    if (is_collect) {
        std::cout << "Sign getting donates with your private key: ";
        std::cin >> entered_private_key;
    
        if (entered_private_key != user->second->get_private_key()) return false; 
    
        user->second->change_balance(amount, true);
    } else {
        std::cout << "Sign donate with your private key: ";
        std::cin >> entered_private_key;

        if (entered_private_key != user->second->get_private_key() || user->second->get_balance() < amount) return false; 

        user->second->change_balance(amount, false);
    }

    return true;
}

bool article_review(const int& scientist_public_key) {
    std::map<int, std::unique_ptr<User>>::iterator it = users.find(scientist_public_key);

    if (it == users.end()) return false;

    unsigned mark = 0;
    unsigned donate = 0;

    std::cout << "\nHello, " << scientist_public_key <<" !\nEnter your mark : ";
    std::cin >> mark;

    std::cout << "Enter your donate (if you don't to do this, enter 0) : ";
    std::cin >> donate;

    if (donate && it->second->get_balance() >= donate) article_contract(scientist_public_key, donate, false);
    else return false;

    scientists->insert( {it->first, std::make_pair(mark, donate)} );

    return true;
}
