//
//  freqCounterMap.h
//  frequencyCounter
//
//  Created by syfo_dias on 13/02/2021.
//  Copyright © 2021 syfo_dias. All rights reserved.
//

#ifndef freqCounterMap_h
#define freqCounterMap_h
#include <map>

namespace sfd {
    /** Time O(n logn). */
    /** Container C, Elem T */
    template <typename C, typename T>
    bool frequencyCounterMap (const C& arr1, const C& arr2)
    {
        if (arr1.size() != arr2.size())
            return false;
        std::map<T, int> elemArr1;
        std::map<T, int> elemArr2;
        for (auto elem : arr1) // O(n) -> O (n * log(n)) :(
        {
            (elemArr1.count(elem) > 0) ? elemArr1[elem] += 1 : elemArr1[elem] = 1; // O log(n) -> O (log(n))
        }
        
        for (auto elem : arr2) // O(n)
        {
            elemArr2[elem] += 1; // O (log(n)), but is not save, assuming default int is not 0, however one can find such solutions on the internet!
        }
        if (elemArr1.size() != elemArr2.size())
            return false;
        typename std::map<int, int>::const_iterator it1 = elemArr1.begin();
        typename std::map<int, int>::const_iterator it2 = elemArr2.begin();
        while (it1 != elemArr1.end())
        {
            if ((it1->first * it1->first) != (it2->first))
                return false;
            if ((it1->second) != (it2->second))
                return false;
            ++it1; ++it2;
        }
        
        return true;
    }
}

#endif /* freqCounterMap_h */
