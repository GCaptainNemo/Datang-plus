#ifndef PAR_PROJECTS_H
#define PAR_PROJECTS_H


#include <iostream>


class projects
{
public:
    static std::string pj_name;
    static int pj_num;
    static void setPar(const std::string &name, const int num){
        projects::pj_name = name;
        projects::pj_num = num;
    }
};



#endif // PAR_PROJECTS_H