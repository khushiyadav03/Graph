class Solution {
    long long good(int &n, vector<int> &workerTimes, long long m) {
        long long c = 0;
        for(int i = 0; i < n; i++) {
            long long u = 0, v = 1;
            while(workerTimes[i] * v * (v + 1) <= 2 * m) v *= 2;
            while(v > u + 1) {
                long long w = (u + v) / 2;
                if(workerTimes[i] * w * (w + 1) <= 2 * m) u = w;
                else v = w;
            }
            c += u;
        }
        return c;
    }
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int> &workerTimes) {
        int n = workerTimes.size();
        long long l = -1, r = 1;
        while(good(n, workerTimes, r) < mountainHeight) r *= 2;
        cout << r << endl;
        while(r > l + 1) {
            long long m = (l + r) / 2;
            if(good(n, workerTimes, m) >= mountainHeight) r = m;
            else l = m;
        }
        return r;
    }
};