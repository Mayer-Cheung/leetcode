class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        if (num <= 1)
            return false;
        for (int i = 1; i <= sqrt(num); i++) {
            if (num % i == 0)
                sum += i + num / i;
        }
        return sum - num == num;
    }
};
