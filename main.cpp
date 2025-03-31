#include "header.h"

std::map<int, std::unique_ptr<User>> users;
std::map<int, std::unique_ptr<Transaction>> mempool;
std::shared_ptr<std::map<int, std::pair<unsigned, unsigned>>> scientists = std::make_shared<std::map<int, std::pair<unsigned, unsigned>>>();

int main() {
    int sc_john = createUser("John");
    int sc_oleg = createUser("Oleg");
    int vadim = createUser("Vadim");

    users[sc_john]->change_balance(1000, true);
    users[sc_oleg]->change_balance(5000, true);
    users[vadim]->change_balance(1000, true);

    users[sc_john]->get_info();
    users[sc_oleg]->get_info();
    users[vadim]->get_info();

    Article myArticle(vadim, "Very Interesting Article!!!");

    int scs[2] = {sc_john, sc_oleg};

    for (int i = 0; i < 2; i++) {
        article_review(scs[i]);
    }

    users[sc_john]->get_info();
    users[sc_oleg]->get_info();

    myArticle.total_review(article_handler);
    myArticle.get_info();
    
    myArticle.collect_donates(article_contract);

    myArticle.get_info();
    users[vadim]->get_info();
}