/**
 * @author linuy
 * @date 2020/11/27 10:46
 */
//

#include "NotEnoughMemoryException.hpp"

const char * NotEnoughMemoryException::what() const noexcept
{
    return "Not Enough Memory!";
}