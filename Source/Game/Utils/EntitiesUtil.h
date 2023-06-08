#pragma once
#include <vector>

using namespace std;

namespace game_framework
{

	template <typename E>
	constexpr typename std::underlying_type<E>::type convertEnum(E e) noexcept {
		return static_cast<typename std::underlying_type<E>::type>(e);
	}

	template<class c>
	static bool findObjInVector(vector<c> vec, c obj)
	{
		auto it = find(vec.begin(), vec.end(), obj);
		if (it != vec.end()) {
			return true;;
		}
		return false;
	}

	template<class c>
	static void deleteObjInVector(vector<c>* vec, c obj)
	{
		auto it = find(vec->begin(), vec->end(), obj);
		if (it != vec->end()) {
			vec->erase(it);
			delete obj;
		}
	}
}