class NumArray {
private:
    int n;
    vector<int> tree;

    void buildTree(const vector<int>& nums, int treeIndex, int lo, int hi) {
        if (lo == hi) {
            tree[treeIndex] = nums[lo];
            return;
        }
        int mid = lo + (hi - lo) / 2;
        buildTree(nums, 2 * treeIndex + 1, lo, mid);
        buildTree(nums, 2 * treeIndex + 2, mid + 1, hi);
        tree[treeIndex] = tree[2 * treeIndex + 1] + tree[2 * treeIndex + 2];
    }

    void updateTree(int treeIndex, int lo, int hi, int arrIndex, int val) {
        if (lo == hi) {
            tree[treeIndex] = val;
            return;
        }
        int mid = lo + (hi - lo) / 2;
        if (arrIndex <= mid) {
            updateTree(2 * treeIndex + 1, lo, mid, arrIndex, val);
        } else {
            updateTree(2 * treeIndex + 2, mid + 1, hi, arrIndex, val);
        }
        tree[treeIndex] = tree[2 * treeIndex + 1] + tree[2 * treeIndex + 2];
    }

    int queryTree(int treeIndex, int lo, int hi, int i, int j) {
        if (i > hi || j < lo) {
            return 0;
        }
        if (i <= lo && j >= hi) {
            return tree[treeIndex];
        }
        int mid = lo + (hi - lo) / 2;
        return queryTree(2 * treeIndex + 1, lo, mid, i, j) +
               queryTree(2 * treeIndex + 2, mid + 1, hi, i, j);
    }

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        if (n > 0) {
            tree.resize(4 * n, 0);
            buildTree(nums, 0, 0, n - 1);
        }
    }
    
    void update(int index, int val) {
        if (n == 0) return;
        updateTree(0, 0, n - 1, index, val);
    }
    
    int sumRange(int left, int right) {
        if (n == 0) return 0;
        return queryTree(0, 0, n - 1, left, right);
    }
};