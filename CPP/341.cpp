/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
       begins.push(nestedList.begin());
       ends.push(nestedList.end());
    }

    int next() {
        // Update Stack
        hasNext();
        // Return the current integer, and inc the iterator to the next one
        return (begins.top()++)->getInteger();
    }

    bool hasNext() {
        while (begins.size()){
            if (begins.top() == ends.top()){
                // if reached the end of the nested list
                begins.pop(); ends.pop();
            } else {
                auto x = begins.top();
                // if pointing integer, all good.
                if (x->isInteger()) return true;
                // Otherwise inc the interator to find the next element.
                begins.top()++;
                // x is still pointing the last one.
                // x->isInteger is not true --> means points another list
                // Append it to the stack
                begins.push(x->getList().begin());
                ends.push(x->getList().end());
            }
        }
        return false;
    }
private:
    // Each contains the iterator of each nested list
    stack<vector<NestedInteger>::iterator> begins, ends;
};

class NestedIterator {
private:
    vector<int> vec;
    int currIndex = 0;
public:
    void helper(vector<NestedInteger> &v){
        for (int i = 0; i < v.size(); ++i){
            if (v[i].isInteger()) vec.push_back(v[i].getInteger());
            else helper(v[i].getList());
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
        helper(nestedList);
    }

    int next() {
        return vec[currIndex++];
    }

    bool hasNext() {
        return currIndex != vec.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();

 Key point here is not returning flattened list, but returning by iterator expected value.
 It means as long as we point the right integer, there is no need of copying the given list.
 */
