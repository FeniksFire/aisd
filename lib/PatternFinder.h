#pragma once

#include <string>
#include <vector>
#include <algorithm>

class PatternFinder {
public:
	virtual ~PatternFinder() = default;
	
	std::vector<int> KMP(std::string text, std::string pattern) const
	{
		auto prefixTable = [](std::string text)
		{
			std::vector<int> table(text.size());
			int count = 0;
			
			for(int i = 1; i<text.size(); i++)
			{
				while (count > 0 && text[count] != text[i])
					count = table[count-1];
				
				if (text[count] == text[i])
					count++;
				table[i] = count;
			}
			return table;
		};
		std::vector<int> indexes;
		
		auto lps = prefixTable(pattern);
		
		for(int i = 0, j = 0; i < text.size(); )
		{
			if(text[i] == pattern[j])
			{
				j++; i++;
			}
			if(j == pattern.size())
			{
				indexes.push_back(i-j);
				j = lps[j-1];
			}
			else if(i<text.size() && text[i] != pattern[j])
			{
				if (j != 0)
					j = lps[j - 1];
				else
					i = i + 1;
			}
		}
		return indexes;
	}
	
	std::vector<int> BoyerMoore(std::string text, std::string pattern) const {
		std::vector<int> ret;
		
		for(int i=0,j=0; i < text.size(), i < text.size()-j; j++)
		{
			int shift = 0;
			auto patternIndex = pattern.size() - j - 1;
			auto textIndex = patternIndex+i;
			
			if(pattern[patternIndex] == text[textIndex] && j == pattern.size()-1)
			{
				ret.push_back(i);
				shift++;
			}
			else if(pattern[patternIndex] != text[textIndex])
			{
				shift = pattern.size() - j;
				for(int k = patternIndex; k>=0; k--)
				{
					if(pattern[k] == text[textIndex])
					{
						shift = patternIndex - k;
						break;
					}
				}
			}
			if(shift)
			{
				i+=shift;
				j = -1;
			}
		}
		return ret;
	}
	
	std::vector<int> KarpRabin(std::string text, std::string pattern) const {
		std::vector<int> indexes;
		auto hashpattern = std::hash<std::string>{}(pattern);
		for(int i=0; i < text.size() - pattern.size(); i++)
			if(std::hash<std::string>{}(text.substr(i, pattern.size())) == hashpattern)
				indexes.push_back(i);
		return indexes;
	}
};