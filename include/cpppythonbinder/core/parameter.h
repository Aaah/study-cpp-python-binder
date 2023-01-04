#ifndef __PARAMETER_H__
#define __PARAMETER_H__

#include <string>
#include <list>
#include <functional>

class DSPParameter
{
public:
    // default constructor
    DSPParameter();

    // append callback to list
    int AddCallback(std::function<int(void)>);

    // remove callback from list
    int RemoveCallback(std::function<int(void)>);

    // execute the callbacks in the list
    int OnValueChange(void);

    // pure virtual classes to be defined by child classes?
    // virtual void GetValue(void) = 0;
    // virtual void SetValue(void) = 0;

private:
    // name the of parameter
    std::string name;

    // a list of callbacks on Configure()
    std::list<std::function<int(void)>> callbacks;
};

class ParameterRanged : public DSPParameter
{
public:
    ParameterRanged();

private:
};

class ParameterSet : public DSPParameter
{
public:
    ParameterSet();

private:
};

class ParameterBool : public DSPParameter
{

public:
    // default constructor
    ParameterBool(std::string name, bool defaultv);

    // getter
    bool GetValue(void) { return this->value; };

    // setter
    int SetValue(bool v);

private:
    bool value;
    float defaultv;
};

class ParameterRangedFloat : public ParameterRanged
{

public:
    // default constructor
    ParameterRangedFloat(std::string name, // name of the parameter
                         float minv,       // minimum value
                         float maxv,       // maximum value
                         float resv,       // resolution
                         float defaultv);  // default value

    // getter
    float GetValue(void) { return this->value; };

    // setter
    int SetValue(float v);

private:
    float value;
    float minv;
    float stepv;
    float maxv;
    float defaultv;
};

class ParameterRangedInt : public ParameterRanged
{

public:
    // default constructor
    ParameterRangedInt(std::string name, // name of the parameter
                       int minv,         // minimum value
                       int maxv,         // maximum value
                       int resv,         // resolution
                       int defaultv);    // default value

    // getter
    int GetValue(void) { return this->value; };

    // setter
    int SetValue(int v);

private:
    int value;
    int minv;
    int stepv;
    int maxv;
    int defaultv;
};

class ParameterRangedString : public ParameterRanged
{

public:
    // default constructor
    ParameterRangedString(std::string name,      // name of the parameter
                          std::string fmt,       // accepted format
                          std::string defaultv); // default value

    // getter
    std::string GetValue(void) { return this->value; };

    // setter
    int SetValue(std::string v);

private:
    std::string value;
    std::string fmt;
    std::string defaultv;
};

class ParameterSetInt : public ParameterSet
{

public:
    // default constructor
    ParameterSetInt(std::string name,     // name of the parameter
                    std::vector<int> set, // accepted set
                    int defaultv);        // default value

    // getter
    int GetValue(void) { return this->value; };

    // setter
    int SetValue(int v);

private:
    int value;
    std::vector<int> set;
    int defaultv;
};

class ParameterSetFloat : public ParameterSet
{

public:
    // default constructor
    ParameterSetFloat(std::string name, std::vector<float> set, float defaultv);

    // getter
    float GetValue(void) { return this->value; };

    // setter
    int SetValue(float v);

private:
    float value;
    std::vector<float> set;
    float defaultv;
};

class ParameterSetString : public ParameterSet
{

public:
    // default constructor
    ParameterSetString(std::string name, std::vector<std::string> set, std::string defaultv);

    // getter
    std::string GetValue(void) { return this->value; };

    // setter
    int SetValue(std::string v);

private:
    std::string value;
    std::vector<std::string> set;
    std::string defaultv;
};

#endif