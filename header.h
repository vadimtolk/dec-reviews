#include <iostream>
#include <random>
#include <memory>
#include <map>
#include <cstring>
#include <utility>

using ArticleHandler = std::pair<float, unsigned> (*)(std::shared_ptr<std::map<int, std::pair<unsigned, unsigned>>>& scientists);
using TransferContract = bool (*)(int from, int to, const unsigned long long& amount);
using ReviewContract = bool (*)(const int& scientist_public_key);
using ArticleContract = bool (*)(int to, const unsigned long long& amount, bool is_collect);

class User;
class Transaction;
class Article;

extern std::map<int, std::unique_ptr<User>> users;
extern std::map<int, std::unique_ptr<Transaction>> mempool;
extern std::shared_ptr<std::map<int, std::pair<unsigned, unsigned>>> scientists;

//utils.cpp
int get_key();
int pseudo_hash();
int createUser(std::string username);
unsigned sum(std::vector<unsigned>& marks);

//user.cpp
class User {
    private: 
        const int private_key;
        const int public_key;
        mutable unsigned long long value;
    public:
        User(int private_key, int public_key, std::string username);
        User(int private_key, int public_key);

        mutable std::string username;

        int get_public_key() const;
        int get_private_key() const;
        void get_info() const;
        
        void change_balance(const unsigned long long& amount, bool isPlus) const;
        unsigned long long get_balance() const;
};

//transactions.cpp
class Transaction {
    private:
        const int from;
        const int to;
        const unsigned long long amount;
    public:
        Transaction(int t_from, int t_to, unsigned long long value);

        const char* meta;
        mutable bool status;

        void transfer(TransferContract smart_contract) const;
        void get_info() const;
};

//contract.cpp
bool simple_transfer(int from, int to, const unsigned long long& amount);
bool article_contract(int address, const unsigned long long& amount, bool is_collect);
bool article_review(const int& scientist_public_key);

//handlers
std::pair<float, unsigned> article_handler(std::shared_ptr<std::map<int, std::pair<unsigned, unsigned>>>& scientists);

//articles.cpp
class Article {
    private:
        unsigned long long current_donates = 0;
        unsigned long long total_donates = 0;
        unsigned average_mark = 0;
        std::string article = "";
        const int author;
    public:
        Article(int author_public_key, std::string article);

        void total_review(ArticleHandler article_handler);
        void collect_donates(ArticleContract smartcontract);

        void change_article(std::string new_article);
        void get_info();
};

