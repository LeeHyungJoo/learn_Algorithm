#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    if(cacheSize == 0)
        return cities.size() * 5;

    int answer = 0;
    deque<string> cache;

    for (auto& city : cities)
        for (auto& c : city)
            if (isupper(c))
                c = tolower(c);

    for (const auto& city : cities)
    {
        bool hit = false;
        int hitIndexed = -1;

        for (int j = 0; j < cache.size(); j++)
        {
            if (cache[j] == city)
            {
                hit = true;
                hitIndexed = j;
                break;
            }
        }

        answer += hit ? 1 : 5;

        if (hit)
        {
            auto hitItem = cache[hitIndexed];
            cache.erase(cache.begin() + hitIndexed);
            cache.push_back(hitItem);
        }
        else
        {
            cache.push_back(city);
            if (cache.size() > cacheSize)
                cache.pop_front();
        }
    }

    return answer;
}