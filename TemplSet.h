#pragma once

#include <algorithm>
#include <iostream>
#include <vector>
template<typename T>
void clean(std::vector<T>& int_set) {
    if(int_set.size() > 1){
        for (int i = 0; i < int_set.size() - 1; ++i) {
            if (int_set[i] == int_set[i + 1]) {
                int_set.erase(int_set.begin() + i);
                i--;
            }
        }
    }
}

template <typename T>
class Set {
public:

    Set() {
    }
    Set(const std::vector<T>& to_copy) {
        this->T_set = to_copy;
        std::sort(this->T_set.begin(), this->T_set.end());
        clean(this->T_set);
    }
    Set<T> add(Set<T>& to_add)  {
        std::vector<T> to_return;
        size_t i = 0;
        size_t j = 0;
        while (i < to_add.T_set.size() && j < this->T_set.size()) {
            if (to_add.T_set[i] == this->T_set[j]) {
                to_return.push_back(this->T_set[j]);
                i++;
                j++;
            }
            else {
                to_return.push_back(to_add.T_set[i]);
                to_return.push_back(this->T_set[j]);
                i++;
                j++;
            }
            if (i == to_add.T_set.size()) {
                while (j < this->T_set.size()) {
                    to_return.push_back(this->T_set[j]);
                    j++;
                }
            }
            if (j == this->T_set.size()) {
                while (i < to_add.T_set.size()) {
                    to_return.push_back(to_add.T_set[i]);
                    i++;
                }
            }
        }
        std::sort(to_return.begin(), to_return.end());
        clean(to_return);
        Set result(to_return);
        return result;
    }
    Set<T> mult(Set<T>& to_mult)  {
        std::vector<T> result;
        std::vector<T> res2 = to_mult.T_set;
        for (auto i : this->T_set) {
            if (std::find(res2.begin(), res2.end(), i) != res2.end()) {
                result.push_back(i);
                res2.erase(std::find(res2.begin(), res2.end(), i));
            }
        }
        Set<T> res;
        clean(result);
        res.T_set = result;
        return res;
    }
    Set<T> sim_sub(Set<T>& to_sim_sub) {
        Set self;
        Set self2;
        self.T_set = this->T_set;
        self2.T_set = to_sim_sub.T_set;
        Set addm = self.add(self2);
        Set summ = self.mult(self2);
        for (auto i : summ.T_set) {
            addm.T_set.erase(std::find(addm.T_set.begin(), addm.T_set.end(), i));
        }
        return addm;
    }

    std::vector<T> T_set;
};
