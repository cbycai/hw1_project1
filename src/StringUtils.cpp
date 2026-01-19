#include "StringUtils.h"

namespace StringUtils{

std::string Slice(const std::string &str, ssize_t start, ssize_t end) noexcept{
    // Replace code here
    std::string Temp = str;
    ssize_t n = str.size();
    // empty str
    if (n==0){
        return "";
    }

    //end == 0
    if(end==0){
        end = n;
    }

    //start is negative
    if(start<0){
        start = n+start;
        //That indicates start is too negative
        if (start<0){
            start = 0;
        }
    }

    //end is negative
    if(end<0){
        end = end+n;
        // if end is too small there is no slice in range
        if(end<0){
            return "";
        }
    }

    //start is greater and equal to length
    if(start>=n){
        return "";
    }

    //end is greater than length and I discuss "equal"situation in end==0
    if(end>n){
        end = n;
    }
    
    //start>=end
    if(start>=end){
        return "";
    }

    //legal range
    return str.substr(start, end-start);
}

std::string Capitalize(const std::string &str) noexcept{
    // Replace code here
    std::string Temp = str;
    if(!Temp.empty()){
        Temp[0] = toupper(Temp[0]);
        for(size_t Index = 1; Index < Temp.length(); Index++){
            Temp[Index] = tolower(Temp[Index]);
        }
    }
    return Temp;
}

std::string Upper(const std::string &str) noexcept{
    // Replace code here
    return "";
}

std::string Lower(const std::string &str) noexcept{
    // Replace code here
    return "";
}

std::string LStrip(const std::string &str) noexcept{
    // Replace code here
    std::string Temp = str;
    size_t Index = 0;
    size_t Length = Temp.length();
    while((Index < Length) && isspace(Temp[Index])){
        Index++;
    }

    return Temp.substr(Index);
}

std::string RStrip(const std::string &str) noexcept{
    // Replace code here
    std::string Temp = str;
    if(!Temp.empty()){
        size_t Index = Temp.length()-1;
        while(isspace(Temp[Index])){
            if(!Index){
                return "";
            }
            Index--;
        }
        return Temp.substr(0,Index+1);
    }
    return "";

}

std::string Strip(const std::string &str) noexcept{
    // Replace code here
    return LStrip(RStrip(str));
}

std::string Center(const std::string &str, int width, char fill) noexcept{
    // Replace code here
    return "";
}

std::string LJust(const std::string &str, int width, char fill) noexcept{
    // Replace code here
    return "";
}

std::string RJust(const std::string &str, int width, char fill) noexcept{
    // Replace code here
    return "";
}

std::string Replace(const std::string &str, const std::string &old, const std::string &rep) noexcept{
    // Replace code here
    return "";
}

std::vector< std::string > Split(const std::string &str, const std::string &splt) noexcept{
    // Replace code here
    return {};
}

std::string Join(const std::string &str, const std::vector< std::string > &vect) noexcept{
    // Replace code here
    return "";
}

std::string ExpandTabs(const std::string &str, int tabsize) noexcept{
    // Replace code here
    return "";
}

int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept{
    // Replace code here
    return 0;
}

};