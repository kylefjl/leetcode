//
// Created by Kyle on 2023/2/9.
//

#ifndef LEETCODE_MYHEAD_H
#define LEETCODE_MYHEAD_H
#include "chrono"


class TimeCost
{
public:
    TimeCost()
    {
        start = std::chrono::system_clock::now();
    }
    TimeCost(std::string name_input) : funName(name_input)
    {
        start = std::chrono::system_clock::now();
    }

    void tic()
    {
        start = std::chrono::system_clock::now();
    }

    double toc()
    {
        end = std::chrono::system_clock::now();
        std::chrono::duration<double> duration = (end - start);
        std::cout << funName << " cost "
                  << duration.count() * std::chrono::seconds::period::num / std::chrono::seconds::period::den
                  << " second " << std::endl;
        return duration.count();
    }

    double toc_noOut()
    {
        end = std::chrono::system_clock::now();
        std::chrono::duration<double> duration = (end - start);
        return duration.count();
    }

private:
    std::chrono::time_point<std::chrono::system_clock> start, end;
    std::string funName = "xxx fun ";
};


#endif //LEETCODE_MYHEAD_H
