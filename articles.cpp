#include "header.h"

Article::Article(int author_public_key, std::string article) : author(author_public_key) { this->article = article; }

void Article::total_review(ArticleHandler article_handler) {
    std::pair<float, unsigned> data = article_handler(scientists);
    average_mark = data.first;

    if (data.second) {
        current_donates += data.second;
        total_donates += data.second;
    }
}

void Article::collect_donates(ArticleContract smartcontract) {
    if (smartcontract(author, current_donates, true)) {
        std::cout << "Succes. " << current_donates << " FUTH were transfered to : " << author << '\n';
        current_donates = 0;
    } else std::cout << "Something went wrong...\n";
} 

void Article::change_article(std::string new_article) { this->article = new_article; }
void Article::get_info() { std::cout << "\nArticle by : " << author << "\n" << article << "\nAverage mark : " << average_mark << "\nDonated : " << total_donates << " FUTH\n"; }