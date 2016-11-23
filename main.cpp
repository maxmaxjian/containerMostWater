#include <iostream>
#include <vector>
#include <algorithm>

class solution {
public:
    int maxArea(const std::vector<int> & hgt) {
	int mA = 0;
	if (hgt.size() == 2) {
	    mA = *std::min_element(hgt.begin(), hgt.end());
	}
	else if (hgt.size() > 2) {
	    std::vector<int> water;
	    int dist = 1;
	    std::transform(hgt.begin()+dist, hgt.end(), std::inserter(water, water.begin()),
			   [&](int h){
			       int curr = dist;
			       dist++;
			       return curr*std::min(*hgt.begin(), h);
			   });
	    mA = std::max({*std::max_element(water.begin(), water.end()), maxArea(std::vector<int>(hgt.begin()+1, hgt.end()))});
	}
	return mA;
    }
};

int main() {
    std::vector<int> heights{1,2,13,14,5,6};

    solution soln;
    int maxA = soln.maxArea(heights);
    std::cout << "The amount of water that the maximum container can contain is:\n"
	      << maxA << std::endl;
}
