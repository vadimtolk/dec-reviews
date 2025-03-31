#include "header.h"

Transaction::Transaction(int from, int to, unsigned long long value) : from(from), to(to), amount(value), status(false), meta(__TIMESTAMP__) {}

void Transaction::transfer(TransferContract smart_contract) const {
    if (smart_contract(from, to, amount)) {
        status = true;
        std::cout << "Transaction from : " << from << " to " << to << " (" << amount << " FUTH) was success.\n";
    } else std::cout << "Invalid sign or low balance.";
}

void Transaction::get_info() const { std::cout << "\nTransaction (Timestamp : " << meta << ") :\nFrom : " << from << "\nTo : " << to << "\nValue : " << amount << " FUTH\nStatus : " << status << '\n'; }