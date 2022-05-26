class Solution
{
    public:
        int hammingWeight(uint32_t n)
        {

            int count = 0;
            while (n != 0)
            {
                int rsb = n & -n;
                n -= rsb;
                count++;
            }
            return count;
        }
};

// These are Builtin functions of GCC compiler

// __builtin_popcount(x): This function is used to count the number of one’s(set bits) in an integer.

// __builtin_parity(x): This function is used to check the parity of a number. This function returns true(1) if the number has odd parity else it returns false(0) for even parity.

// __builtin_clz(x): This function is used to count the leading zeros of the integer. Note: clz = count leading zero’s.

// __builtin_ctz(x): This function is used to count the trailing zeros of the given integer. Note: ctz = count trailing zeros.

// Reference: You can find more examples on geeks for geeks.
// P.S: I can't provide you the link or else my post will not be visible to you.