#ifndef __Dane_Log__
#define __Dane_Log__

#include "realog.hpp"

#include <memory>

namespace Dane {
  class Log
  {
  public:
    
    static void Init();

    inline static std::shared_ptr<realog::Logger> &GetCoreLogger() { return s_CoreLogger; }
    inline static std::shared_ptr<realog::Logger> &GetClientLogger() { return s_ClientLogger; }
  private:
    static std::shared_ptr<realog::Logger> s_CoreLogger;
    static std::shared_ptr<realog::Logger> s_ClientLogger;
  };
}

#define DN_CORE_INFO(...) Dane::Log::GetCoreLogger()->info(__VA_ARGS__)
#define DN_CORE_DEBUG(...) Dane::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define DN_CORE_ERROR(...) Dane::Log::GetCoreLogger()->error(__VA_ARGS__)
#define DN_CORE_FATAL(...) Dane::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define DN_CORE_TRACE(...) Dane::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define DN_CORE_WARNING(...) Dane::Log::GetCoreLogger()->warn(__VA_ARGS__)

#endif /* defined(__Dane_Log__) */