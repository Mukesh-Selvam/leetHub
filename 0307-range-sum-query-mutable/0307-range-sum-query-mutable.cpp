class NumArray {
private:
    int n;
    vector<int> tree;

    void buildTree(const vector<int>& nums, int i, int l, int h) {
        if (l==h) {
            tree[i] = nums[l];
            return;
        }
        int mid=l+(h-l)/2;
        buildTree(nums,2*i+1,l,mid);
        buildTree(nums,2*i+2,mid+1,h);
        tree[i]=tree[2*i+1] + tree[2*i+2];
    }

    void updateTree(int i,int l,int h,int arrIndex,int val) {
        if (l==h) {
            tree[i]=val;
            return;
        }
        int mid=l+(h-l)/2;
        if (arrIndex<=mid) {
            updateTree(2*i+1,l,mid,arrIndex,val);
        } else {
            updateTree(2*i+2,mid+1,h,arrIndex,val);
        }
        tree[i]=tree[2*i+1]+tree[2*i+2];
    }

    int queryTree(int idx,int l,int h,int i,int j) {
        if (i>h || j<l) {
            return 0;
        }
        if (i<=l && j>=h){
            return tree[idx];
        }
        int mid = l+(h-l)/2;
        return queryTree(2*idx+1,l,mid,i,j)+
               queryTree(2*idx+2,mid+1,h,i,j);
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