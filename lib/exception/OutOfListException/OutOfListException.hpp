/**
 * @author linuy
 * @date 2020/11/27 10:52
 */
//

#ifndef CPPDEMO_OUTOFLISTEXCEPTION_HPP
#define CPPDEMO_OUTOFLISTEXCEPTION_HPP

#include <exception>

class OutOfListException: public std::exception
{
    const char * what() const noexcept override;
};


#endif //CPPDEMO_OUTOFLISTEXCEPTION_HPP
