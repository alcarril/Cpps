#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>

template<typename T>
typename T::const_iterator easyFind(const T &container, int search) {
	typename T::const_iterator itRet = std::find(container.begin(), container.end(), search);
	if (itRet != container.end()) {
		return itRet;
	}
	else 
		throw std::logic_error("Element not found\n");
}

template<typename T>
typename T::iterator easyFindnoalgorithm(const T &container, int search) {
	typename T::iterator itRet;
	for (itRet = container.begin(); itRet != container.end(); ++itRet) {
		if (*itRet == search) {
			return itRet;
		}
	}
	throw std::logic_error("Element not found\n");
}

template<typename It, typename V>
typename It::iterator myFind(It &start, It &end, const V& value) {
	for (; start <= end; start++) {
		if (*start == value) {
			return start;
		}
	}
    throw std::logic_error("Element not found\n");
}

#endif
