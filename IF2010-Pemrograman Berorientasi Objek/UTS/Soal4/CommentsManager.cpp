#include "CommentsManager.hpp"
#include <algorithm>
#include <iterator>

void CommentsManager::kickSpammer(int threshold_score) {
    chat_log_.erase(std::remove_if(chat_log_.begin(), chat_log_.end(),[this, threshold_score](const Comment& c) {
        auto it = reputation_.find(c.getUsername());
        int rep = (it != reputation_.end()) ? it->second : 0;
        return rep > threshold_score;}),
        chat_log_.end());
}

void CommentsManager::printViolation(){
    bool found = false;
    std::for_each(chat_log_.begin(),chat_log_.end(),[this, &found](const Comment& c){
         std::for_each(c.getWords().begin(), c.getWords().end(),[this,&found,&c](const std::string& w){
            if (blacklist_.find(w) != blacklist_.end()){
                    std::cout << "kata \"" << w << "\" oleh akun \"" << c.getUsername() << "\"" << std::endl;
                    found = true;
                    } });
            } );
            if (!found){
                std::cout << "TIDAK ADA PELANGGARAN" << std::endl;
            }
}

std::string CommentsManager::quizWinner(const std::set<std::string>& passwords){
    auto i = std::find_if(chat_log_.begin(),chat_log_.end(),[&passwords](const Comment& c){
            return std::any_of(c.getWords().begin(), c.getWords().end(), [&passwords](const std::string& word){
                    return passwords.count(word);});
            });
    if (i != chat_log_.end()) return i->getUsername();
    return "BELUM ADA PEMENANG";
}

void CommentsManager::upVIPComment(){
    std::vector<Comment> vip;
    std::vector<Comment> nonvip;
    std::copy_if(chat_log_.begin(), chat_log_.end(),std::back_inserter(vip),[](const Comment& c){
        return c.isVip();});
    std::copy_if(chat_log_.begin(), chat_log_.end(),std::back_inserter(nonvip),[](const Comment& c){
        return !c.isVip();});
        chat_log_.clear();
        chat_log_.insert(chat_log_.begin(),vip.begin(),vip.end());
        chat_log_.insert(chat_log_.end(),nonvip.begin(),nonvip.end());
}
