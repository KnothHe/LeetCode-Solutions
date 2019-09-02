/*
 * @lc app=leetcode id=432 lang=cpp
 *
 * [432] All O`one Data Structure
 *
 * https://leetcode.com/problems/all-oone-data-structure/description/
 *
 * algorithms
 * Hard (28.51%)
 * Total Accepted:    14.1K
 * Total Submissions: 49.5K
 * Testcase Example:  '["AllOne","getMaxKey","getMinKey"]\n[[],[],[]]'
 *
 * Implement a data structure supporting the following operations:
 * 
 * 
 * 
 * Inc(Key) - Inserts a new key  with value 1. Or increments an existing key by
 * 1. Key is guaranteed to be a non-empty string.
 * Dec(Key) - If Key's value is 1, remove it from the data structure. Otherwise
 * decrements an existing key by 1. If the key does not exist, this function
 * does nothing. Key is guaranteed to be a non-empty string.
 * GetMaxKey() - Returns one of the keys with maximal value. If no element
 * exists, return an empty string "".
 * GetMinKey() - Returns one of the keys with minimal value. If no element
 * exists, return an empty string "".
 * 
 * 
 * 
 * 
 * Challenge: Perform all these in O(1) time complexity.
 * 
 */

/*
 * learn from https://leetcode.com/problems/all-oone-data-structure/discuss/91400/All-in-O(1)-with-detailed-explantation
 */
class AllOne {
public:
    struct Row {
        list<string> strs;
        int val;

        Row(const string &s, int v) : strs({s}), val(v) { }
    };

    unordered_map<string, pair<list<Row>::iterator, list<string>::iterator>> strmap;
    list<Row> matrix;

    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) { 
        if (strmap.find(key) == strmap.end()) {
            if (matrix.empty() || matrix.back().val != 1) {
                auto newRow = matrix.emplace(matrix.end(), key, 1);
                strmap[key] = make_pair(newRow, newRow->strs.begin());
            } else {
                auto newRow = --matrix.end();
                newRow->strs.push_front(key);
                strmap[key] = make_pair(newRow, newRow->strs.begin());
            }
        } else {
            auto row = strmap[key].first;
            auto col = strmap[key].second;
            auto lastRow = row;
            --lastRow;
            if (lastRow == matrix.end() || lastRow->val != row->val + 1) {
                auto newRow = matrix.emplace(row, key, row->val + 1);
                strmap[key] = make_pair(newRow, newRow->strs.begin());
            } else {
                auto newRow = lastRow;
                newRow->strs.push_front(key);
                strmap[key] = make_pair(newRow, newRow->strs.begin());
            }
            row->strs.erase(col);
            if (row->strs.empty()) matrix.erase(row);
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (strmap.find(key) == strmap.end()) {
            return;
        } else {
            auto row = strmap[key].first;
            auto col = strmap[key].second;
            if (row->val == 1) {
                row->strs.erase(col);
                if (row->strs.empty()) matrix.erase(row);
                strmap.erase(key);
            } else {
                auto nextRow = row;
                ++nextRow;
                if (nextRow == matrix.end() || nextRow->val != row->val-1) {
                    auto newRow = matrix.emplace(nextRow, key, row->val-1);
                    strmap[key] = make_pair(newRow, newRow->strs.begin());
                } else {
                    auto newRow = nextRow;
                    newRow->strs.push_front(key);
                    strmap[key] = make_pair(newRow, newRow->strs.begin());
                }
                row->strs.erase(col);
                if (row->strs.empty()) matrix.erase(row);
            }
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return matrix.empty() ? "" : matrix.front().strs.front();
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return matrix.empty() ? "" : matrix.back().strs.front();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */
