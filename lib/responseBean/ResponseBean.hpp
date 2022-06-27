/**
 * @author linuy
 * @date 2020/11/27 11:15
 */
//

#ifndef CPPDEMO_RESPONSEBEAN_HPP
#define CPPDEMO_RESPONSEBEAN_HPP

#include <string>

class ResponseBean
{
private:
    const static std::string DEFAULT_MESSAGE_SUCCESS;
    const static std::string DEFAULT_MESSAGE_ERROR;
    const static std::string CODE_SUCCESS;
    const static std::string CODE_ERROR;
    std::string code;
    std::string message;
    std::string extParam;
    void * data{};
public:
    ResponseBean();

    ResponseBean(std::string code, std::string message);

    /**
     * 添加错误信息
     */
    void addDefaultError();

    void addError(std::string message);

    void add(std::string code, std::string message);

    void addError(std::string code, std::string message, std::string extParam);

    /**
     * 添加成功信息
     */
    void addSuccess();

    void addSuccess(std::string message);

    void addSuccess(std::string message, void * data);

    void addSuccess(std::string code, std::string message, void * data);

    void addSuccess(std::string code, std::string message, void * data, std::string extParam);

    void addSuccess(void * data);

    void * getData();

    void setData(void * data);

    std::string getCode();

    std::string getMessage();

    std::string getExtParam();

    void setParam(std::string extParam);

    std::string toString();

    bool isSuccess();

    bool isFail();
};


#endif //CPPDEMO_RESPONSEBEAN_HPP
