   
 
 
/****************************************************************************************
*
* This code was generated by the Command Creator tool for the ChainsAPM project. 
* If manual changes are made to the code they could be lost.
* 
****************************************************************************************/ 
#pragma once
#include "ICommand.h"

namespace Commands  
{
    class MethodEnter :
        public virtual ICommand
    {


    public:
    
        MethodEnter(__int64 timestamp, __int64 threadid, __int64 moduleid, __int64 methoddef); 
        ~MethodEnter();
        virtual std::shared_ptr<std::vector<char>> Encode();
        virtual std::shared_ptr<ICommand> Decode(std::shared_ptr<std::vector<char>> &data);  
        virtual std::wstring Name();
        virtual std::wstring Description();
        virtual short Code() { return code; }
        __int64 ThreadID;
        __int64 ModuleID;
        __int64 MethodDef;
      private:
        __int64 timestamp; // Always use a 64bit so the message doesn't change
        std::shared_ptr<std::vector<char>> internalvector;
        bool hasEncoded;
        short code;
    };

}
