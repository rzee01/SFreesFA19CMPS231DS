#include <unordered_map>
#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>
#include <string>
#include<bits/stdc++.h> 


class WordCount {
    public:
        WordCount() {
            word = "";
            count = 0;
        }
        WordCount(std::string word, unsigned int count) : word(word), count(count) {

        }
        std::string word;
        unsigned int count;
};
// Inherit using protected to shield the user of this class from 
// working with the underlying member methods of unordered list.
class WordCounter : protected std::unordered_map<std::string, unsigned int>
{
public:
    WordCounter(){}
    void add(const std::string word){
        // Clone the string because we are going to need to make
        // it into lower case.
        std::string _word(word);
        make_lower_case(_word);

        auto it = find(_word);
        if(it != end()) {
            // this word already exists.
            it->second++;
        } else {
            // word doesn't exist - add it.
            emplace(_word, 1);
        }
    }
    unsigned int count(const std::string word)  {
        std::string _word(word);
        make_lower_case(_word);
        unsigned int key_count = std::unordered_map<std::string, unsigned int>::count(_word);
        if ( key_count > 0 ) {
            return at(_word);
        } else {
            return 0;
        }
        
    }
    std::vector<WordCount> words() const {
        std::vector<WordCount> retval;
        for (auto w = this->begin(); w != this->end(); ++w) {
            retval.push_back(WordCount(w->first, w->second));
        }
        return retval;
    }


    private:

    
    void make_lower_case(std::string & word) const {
        std::transform(word.begin(), word.end(), word.begin(), ::tolower); 
    }

};
