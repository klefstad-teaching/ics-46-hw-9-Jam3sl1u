#include "ladder.h"
#include <queue>
#include <vector>
#include <set>
#include <cmath>
#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}

using namespace std;

void error(string word1, string word2, string msg) {
    cout << "Error: " << msg << ": " << word1 << " - " << word2;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    int str1_size = str1.size();
    int str2_size = str2.size();
    if (abs(str1_size - str2_size) > d) return false;
    int edit_counter = 0;
    int idx_str1 = 0;
    int idx_str2 = 0;
    while (idx_str1 < str1_size && idx_str2 < str2_size) {
        if (str1[idx_str1] != str2[idx_str2]) {
            edit_counter++;
            if (str1_size == str2_size) {
                idx_str1++;
                idx_str2++;
            } else if (str1_size > str2_size) {
                idx_str1++;
            } else {
                idx_str2++;
            }
        } else {
            idx_str1++;
            idx_str2++;
        }
    }
    if (str1_size > str2_size) {
        edit_counter += str1_size - idx_str1;
    } else if (str2_size > str1_size) {
        edit_counter += str2_size - idx_str2;
    }
    return edit_counter <= d;
}

bool is_adjacent(const string& word1, const string& word2) {
    return edit_distance_within(word1, word2, 1);
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {
    if (begin_word == end_word) {
        error(begin_word, end_word, "Same Word");
        return {};
    }
    queue<vector<string>> ladder_queue;
    ladder_queue.push({begin_word});
    set<string> visited;
    visited.insert(begin_word);
    while (!ladder_queue.empty()) {
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();
        string last_word = ladder.back();
        for (string word : word_list) {
            if (is_adjacent(last_word, word)) {
                if (visited.find(word) == visited.end()) {
                    visited.insert(word);
                    vector<string> new_ladder(ladder);
                    new_ladder.push_back(word);
                    if (word == end_word) {
                        return new_ladder;
                    }
                    ladder_queue.push(new_ladder);
                }
            }
        }
    }
    return {};
}

void load_words(set<string> & word_list, const string& file_name) {
    ifstream in(file_name);
    if (!in) {
        throw runtime_error("Can't open input file");
    }
    string line;
    while(in >> line) {
        word_list.insert(line);
    }
    in.close();
}

void print_word_ladder(const vector<string>& ladder) {
    if (!ladder) {
        cout << "No word ladder found." << endl;
        return;
    }
    cout << "Word ladder found: "
    for(string word : ladder) {
        cout << word << " ";
    }
    cout << endl;
}

void verify_word_ladder() {
    set<string> word_list;
    load_words(word_list, "src/words.txt");
    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}
