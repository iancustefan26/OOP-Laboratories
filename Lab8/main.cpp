#include<iostream>
#include <map>
#include <string>
#include <queue>
#include <fstream>

std::ifstream f("data.txt");

std::string toLower(const std::string& str) {
	std::string result = str;
	std::transform(result.begin(), result.end(), result.begin(),
		[](unsigned char c) { return std::tolower(c); });
	return result;
}

void ReadAndSplit(std::string& buffer,  std::map<std::string, int>& table) {
	int lenght = buffer.size();
	std::string word;

	for (char ch : buffer) {
		if (ch == ' ' || ch == ',' || ch == '?' || ch == '.' || ch == '!') {
			if (!word.empty())
				table[toLower(word)]++, word.clear();
		}
		else
			word.push_back(ch);
	}
	if (!word.empty())
		table[word]++;
	
}

struct PairComparator {

	bool operator()(const std::pair<std::string, int>& lhs, const std::pair<std::string, int>& rhs) const {
		if (lhs.second == rhs.second) {
			return lhs.first > rhs.first;
		}
		return lhs.second > rhs.second;
	}
};


int main() {
	std::map<std::string, int> Map;
	std::string phrase;
	std::string buffer;
	std::priority_queue<std::pair<std::string, int>> queue;
	//std::cout << "Enter the phrase:\n";
	while (f >> buffer) {
		//std::cout << buffer << " ";
		phrase += buffer + " ";
	}
	ReadAndSplit(phrase, Map);
	for (auto& elem : Map)
		queue.push(elem);
		//std::cout << elem.first << " => " << elem.second << "\n";
	while (!queue.empty()) {
		auto element = queue.top();
		queue.pop();
		std::cout << element.first << " => " << element.second << "\n";
	}


	return 0;
}