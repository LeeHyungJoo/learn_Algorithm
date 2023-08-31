#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Gap
{
public:
    Gap(int self, int gap)
        : self(self), gap(gap){}

    static bool CompareGap(const Gap& g1, const Gap& g2)
    {
        if (g1.gap == g2.gap)
            return g1.self > g2.self;
        else
            return g1.gap < g2.gap;
    }

    int self = 0;
    int gap = 0;
};


vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer;

    vector<Gap> gaps;
    for (auto num : numlist)
        gaps.push_back(Gap(num, abs(num - n)));

    sort(gaps.begin(), gaps.end(), Gap::CompareGap);

    for (auto gap : gaps)
        answer.push_back(gap.self);

    return answer;
}