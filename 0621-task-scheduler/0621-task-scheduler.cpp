class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for (char c : tasks)
            freq[c - 'A']++;

        priority_queue<int> pq;
        for (int x : freq)
            if (x > 0)
                pq.push(x);

        int time = 0;

        while (!pq.empty()) {
            vector<int> temp;
            int cnt = 0;   // tasks executed in this cycle

            for (int i = 0; i <= n; i++) {
                if (!pq.empty()) {
                    int f = pq.top();
                    pq.pop();
                    cnt++;

                    if (--f > 0)
                        temp.push_back(f);
                }
            }

            for (int x : temp)
                pq.push(x);

            if (pq.empty())
                time += cnt;
            else
                time += n + 1;
        }

        return time;
    }
};