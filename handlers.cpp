#include "header.h"

std::pair<float, unsigned> article_handler(std::shared_ptr<std::map<int, std::pair<unsigned, unsigned>>>& scientists) {
    std::vector<unsigned> marks = {};
    unsigned donates = 0;
    std::map<int, std::pair<unsigned int, unsigned int>>::iterator it = scientists->begin();

    while (it != scientists->end()) {
        marks.push_back(it->second.first);
        if (it->second.second) donates += it->second.second;
        it++;
    }

    return std::make_pair(static_cast<float>(sum(marks) / marks.size()), donates);
}
