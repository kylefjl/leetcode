/**
 * @author linuy
 * @date 2020/11/27 10:52
 */
//

#include "OutOfListException.hpp"

const char * OutOfListException::what() const noexcept
{
    return "Out of bounds array!";
}