#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <ranges>
#include <utility>
#include <vector>

/* Read entire content of a file. */
std::string read_text(const std::string& filename)
{
    std::fstream f(filename, std::ios::in);
    if (!f) {
        std::cout << "Error opening file!\n";
        exit(1);
    }
    std::stringstream s;
    s << f.rdbuf();
    return s.str();
}

/* Remove punctuation and change to lowercase. */
void process_text_inplace(std::string& text)
{
    // For each character, if it's punctuation replace with a space, otherwise lowercase it.
    std::ranges::for_each(text, [](char& c) {
        constexpr std::string_view punctuation = "!\"&'()[]-,.:;?";
        if (punctuation.find(c) != std::string::npos) {
            c = ' ';
            return;
        }
        c = std::tolower(c);
    });
}

using dict = std::unordered_map<std::string, int>;

/* Count the number of times each word appears in input. */
dict count_appearances(const std::string& text)
{
    std::stringstream buffer(text);
    std::unordered_map<std::string, int> word_counts;
    do {
        std::string word;
        buffer >> word;
        word_counts[word]++; // The behaviour here is very different to Python! (zero initialization)
    } while (!buffer.eof());
    return word_counts;
}

/* Create a sorted vector from a map based on an item's value. */
std::vector<std::pair<std::string, int>> sorted_word_list(const dict& word_counts)
{
    using pair = std::pair<std::string, int>;
    std::vector<pair> word_counts_sorted {begin(word_counts), end(word_counts)};
    std::ranges::sort(word_counts_sorted, [](const auto& a, const auto& b){ return a.second > b.second; });
    return word_counts_sorted;
}

int main()
{
    auto text = read_text("data/shakespeare.txt");
    process_text_inplace(text);
    const auto word_counts = count_appearances(text);
    auto word_counts_sorted = sorted_word_list(word_counts);

    for (const auto& [word, count] : (word_counts_sorted | std::views::take(20))) {
        std::cout << word << " " << count << "\n";
    }
}