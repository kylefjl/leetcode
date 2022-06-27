/**
 * @author linuy
 * @date 2020/11/27 10:46
 */
//

#ifndef CPPDEMO_NOTENOUGHMEMORYEXCEPTION_HPP
#define CPPDEMO_NOTENOUGHMEMORYEXCEPTION_HPP

#include <exception>

class NotEnoughMemoryException: public std::exception
{
public:
    const char * what() const noexcept override;
};


#endif //CPPDEMO_NOTENOUGHMEMORYEXCEPTION_HPP
