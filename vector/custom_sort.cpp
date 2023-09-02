//by 鸟哥 sort函数
//有疑问请留言或加群 1032082534
#include <iostream>                              // For standard streams
#include <string>                                // For string class
#include <vector>                                // For vector container
#include <iterator>                              // For stream and back insert iterators
#include <algorithm>                             // For sort() algorithm


class Person
{
private:
    std::string name;
    int age;
public:
    Person(const std::string& n, const int a) : name(n), age(a){}
    Person()=default;
    std::string get_name() const { return name; }
    int get_age() const { return age; }
    friend std::istream& operator>>(std::istream& in, Person& p);
    friend std::ostream& operator<<(std::ostream& out, const Person& p);
};
//
inline std::istream& operator>>(std::istream& in, Person& p)
{
    return in >> p.name >> p.age;
}
//
inline std::ostream& operator<<(std::ostream& out, const Person& p)
{
    return out<<"姓名：" << p.name << " 年龄：" << p.age;
}
int main()
{
    std::vector<Person> persons{{"angle",51},{"tlp",22},{"jack",33}};
    std::cout<<"排序之前："<<std::endl;
    std::copy(std::begin(persons), std::end(persons), std::ostream_iterator<Person>(std::cout, "\n"));
    //这里进行排序
    std::sort(std::begin(persons), std::end(persons),
              [](const Person& p1, const Person& p2) {return p1.get_name() < p2.get_name();});
    std::cout << "按姓名排序之后："<<std::endl;
    std::copy(std::begin(persons), std::end(persons), std::ostream_iterator<Person>(std::cout, "\n"));
    //这里进行排序
    std::sort(std::begin(persons), std::end(persons),
              [](const Person& p1, const Person& p2) {return p1.get_age() < p2.get_age();});
    std::cout << "按年龄排序之后："<<std::endl;
    std::copy(std::begin(persons), std::end(persons), std::ostream_iterator<Person>(std::cout, "\n"));
}


