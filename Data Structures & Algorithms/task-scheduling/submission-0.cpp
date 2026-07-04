class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        array<int, 26> freq{};
        for (auto task : tasks) {
            ++freq[task - 'A'];
        }

        priority_queue<int> maxHeap;
        for (auto count : freq) {
            if (count > 0) maxHeap.push(count);
        }

        int t = 0;
        queue<pair<int, int>> q;
        while (!maxHeap.empty() || !q.empty()) {
            ++t;

            if (maxHeap.empty()) t= q.front().second;
            else {
                int count = maxHeap.top() - 1;
                maxHeap.pop();
                if (count > 0) q.push({count, t + n});
            }

            if (!q.empty() && q.front().second == t) {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }
        return t;
    }
};
