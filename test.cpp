#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <string_view>
#include <utility>
 
template<class M>
void print(const std::string_view rem, const M& mmap)
{
    std::cout << rem << " ";
    for (const auto & e : mmap)
        std::cout << "{" << e.first << "," << e.second << "} ";
    std::cout << '\n';
}
 
int main()
{
    // 列表初始化
    std::multimap<int, std::string, std::greater<int>> mmap
        {{2, "foo"}, {2, "bar"}, {3, "baz"}, {1, "abc"}, {5, "def"}};
    print("#1", mmap);
 
    // 用 value_type 插入
    mmap.insert(decltype(mmap)::value_type(5, "pqr"));
    print("#2", mmap);
 
    // 用 pair 插入
    mmap.insert(std::pair{6, "uvw"});
    print("#3", mmap);
 
    mmap.insert({7, "xyz"});
    print("#4", mmap);
 
    // 用 initialization_list 插入
    mmap.insert({{5, "one"}, {5, "two"}});
    print("#5", mmap);

    auto range = mmap.equal_range(5);
    for(auto i = range.first; i != range.second; i++)
        std::cout << i->first << ", " << i->second << std::endl;

    std::cin.get();
}