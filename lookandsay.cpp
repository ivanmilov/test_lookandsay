#include <iostream>

// The look-and-say sequence is defined as a = [1, 11, 21, 1211, 111221, ...],
// calculates len(a[30]).

std::string get_next(const std::string& s)
{
    if (s.empty())
        return "1";
    if (s.size() == 1)
        return "1" + s;

    size_t last{0};
    size_t forward{0};
    std::string res{};
    auto diff = [](int a, int b) { return std::to_string(b - a); };
    for (; forward < s.length();)
    {
        forward++;
        if (s[last] != s[forward])
        {
            res += diff(last, forward) + s[last];
            last = forward;
        }
        if (forward == s.length() - 1)
        {
            res += diff(last, forward + 1) + s[last];
            return res;
        }
    }

    return {};
}

int main(int argc, char** argv)
{
    auto next = [str = std::string{}, nextstr = std::string{}]() mutable {
        nextstr = get_next(str);
        // std::cout << str << " -> " << nextstr << std::endl;
        str = nextstr;
        return nextstr;
    };

    int index = 30;
    if (argc >= 2)
    {
        index = atoi(argv[1]);
    }

    std::cout << index << "th element length is ";

    std::string res{};
    while (index-- > 0)
    {
        res = next();
    }

    std::cout << res.length() << std::endl;

    return 0;
}
