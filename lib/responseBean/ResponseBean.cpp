/**
 * @author linuy
 * @date 2020/11/27 11:15
 */
//

#include "ResponseBean.hpp"
#include <sstream>

const std::string ResponseBean::DEFAULT_MESSAGE_SUCCESS = std::string("SUCCESS");
const std::string ResponseBean::DEFAULT_MESSAGE_ERROR = std::string("ERROR");
const std::string ResponseBean::CODE_SUCCESS = std::string("0");
const std::string ResponseBean::CODE_ERROR = std::string("-1");

ResponseBean::ResponseBean()
{
    this->code = CODE_SUCCESS;
    this->message = DEFAULT_MESSAGE_SUCCESS;
}

ResponseBean::ResponseBean(std::string code, std::string message)
{
    this->code = code;
    this->message = message;
}

void ResponseBean::addDefaultError()
{
    this->code = this->CODE_ERROR;
    this->message = this->DEFAULT_MESSAGE_ERROR;
}

void ResponseBean::addError(std::string message)
{
    this->message = message;
}

void ResponseBean::add(std::string code, std::string message)
{
    this->code = code;
    this->message = message;
}

void ResponseBean::addError(std::string code, std::string message, std::string extParam)
{
    this->code = code;
    this->message = message;
    this->extParam = extParam;
}

void ResponseBean::addSuccess()
{
    this->code = this->CODE_SUCCESS;
    this->message = this->DEFAULT_MESSAGE_SUCCESS;
}

void ResponseBean::addSuccess(std::string message)
{
    this->message = message;
}

void ResponseBean::addSuccess(std::string message, void * data)
{
    this->message = message;
    this->data = data;
}

void ResponseBean::addSuccess(std::string code, std::string message, void * data)
{
    this->code = code;
    this->message = message;
    this->data = data;
}

void ResponseBean::addSuccess(std::string code, std::string message, void * data, std::string extParam)
{
    this->code = code;
    this->message = message;
    this->data = data;
    this->extParam = extParam;
}

void ResponseBean::addSuccess(void * data)
{
    this->data = data;
}

void * ResponseBean::getData()
{
    return this->data;
}

void ResponseBean::setData(void * data)
{
    this->data = data;
}

std::string ResponseBean::getCode()
{
    return this->code;
}

std::string ResponseBean::getMessage()
{
    return this->message;
}

std::string ResponseBean::getExtParam()
{
    return this->extParam;
}

void ResponseBean::setParam(std::string extParam)
{
    this->extParam = extParam;
}

std::string ResponseBean::toString()
{
    std::stringstream sout;
    sout << "{";
    sout << "\"code\":" << "\"" << this->code << "\",";
    sout << "\"message\":" << "\"" << this->message << "\",";
    sout << "\"extParam\":" << "\"" << this->extParam << "\"";
    sout << "}";
    return sout.str();
}

bool ResponseBean::isSuccess()
{
    return this->code == "0";
}

bool ResponseBean::isFail()
{
    return !isSuccess();
}