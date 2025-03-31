#include "header.h"

User::User(int private_key, int public_key, std::string username) : private_key{private_key}, public_key{public_key}, username{username}, value{0} {}

User::User(int private_key, int public_key) : User(private_key, public_key, "Anonim") {}

int User::get_public_key() const { return public_key; }
int User::get_private_key() const { return private_key; }

void User::change_balance(const unsigned long long& amount, bool isPlus) const { isPlus ? value += amount : value -= amount; }
void User::get_info() const {std::cout << "\nUser : " << username << "\nPublic key : " << public_key << "\nPrivate Key : " << private_key << "\nBalance : " << value << " FUTH\n"; }

unsigned long long User::get_balance() const { return value; }