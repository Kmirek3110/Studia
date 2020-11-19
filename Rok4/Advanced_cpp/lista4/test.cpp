// print every k-th value starting from p-th value
    constexpr int k = 3, p = 4;

    std::for_each(vec_doubles.begin() + p, vec_doubles.end(), [](double val) {
        static int k_counter = 0;
        if (k_counter++ % k == 0)
            std::cout << val << " ";
    });
    std::cout << std::endl;

    auto list_iterator = list_strings.begin();
    std::advance(list_iterator, p);
    std::for_each(list_iterator, list_strings.end(), [](std::string val) {
        static int k_counter = 0;
        if (k_counter++ % k == 0)
            std::cout << val << " ";
    });
    std::cout << std::endl;

    auto set_iterator = set_ints.begin();
    std::advance(set_iterator, p);
    std::for_each(set_iterator, set_ints.end(), [](int val) {
        static int k_counter = 0;
        if (k_counter++ % k == 0)
            std::cout << val << " ";
    });
    std::cout << std::endl;



    emplate <typename T>
std::function<void(T)> compare(const T& a, const T& b)
{
    return [&](const T& c) {
        if (b > c && c > a)
            std::cout << c << " ";
    };
}

template <typename Ts>
auto sum_elements(Ts elements, typename Ts::value_type neutral)
{
    std::for_each(elements.begin(), elements.end(), [&](auto& value) { neutral += value; });
    return neutral;
}

template <typename Ts>
auto find_minmax(const Ts& elements)
{
    auto min = elements.begin(), max = elements.begin(), iter = elements.begin();

    std::for_each(elements.begin(), elements.end(), [&](auto& elem) {
        if (elem < *min)
            min = iter;
        else if (*max < elem)
            max = iter;
        iter++;
    });

    return std::pair{min, max};
}