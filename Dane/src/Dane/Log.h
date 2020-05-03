#ifndef __Dane_Log__
#define __Dane_Log__

#include "realog.hpp"

#include <memory>

namespace Dane {
  class Log
  {
  public:
    
    static void Init();

    inline static std::shared_ptr<Realog::Logger> &GetCoreLogger() { return s_CoreLogger; }
    inline static std::shared_ptr<Realog::Logger> &GetClientLogger() { return s_ClientLogger; }
  private:
    static std::shared_ptr<Realog::Logger> s_CoreLogger;
    static std::shared_ptr<Realog::Logger> s_ClientLogger;
  };
}

#ifdef DN_DIST_CONFIG
  #define DN_CORE_INFO(...)
  #define DN_CORE_DEBUG(...)
  #define DN_CORE_ERROR(...)
  #define DN_CORE_FATAL(...)
  #define DN_CORE_TRACE(...)
  #define DN_CORE_WARNING(...)

  #define DN_INFO(...)
  #define DN_DEBUG(...)
  #define DN_ERROR(...)
  #define DN_FATAL(...)
  #define DN_TRACE(...)
  #define DN_WARNING(...)
#else
  #define DN_CORE_INFO(...) Dane::Log::GetCoreLogger()->info(__VA_ARGS__)
  #define DN_CORE_DEBUG(...) Dane::Log::GetCoreLogger()->debug(__VA_ARGS__)
  #define DN_CORE_ERROR(...) Dane::Log::GetCoreLogger()->error(__VA_ARGS__)
  #define DN_CORE_FATAL(...) Dane::Log::GetCoreLogger()->critical(__VA_ARGS__)
  #define DN_CORE_TRACE(...) Dane::Log::GetCoreLogger()->trace(__VA_ARGS__)
  #define DN_CORE_WARNING(...) Dane::Log::GetCoreLogger()->warn(__VA_ARGS__)

  #define DN_INFO(...) Dane::Log::GetClientLogger()->info(__VA_ARGS__)
  #define DN_DEBUG(...) Dane::Log::GetClientLogger()->debug(__VA_ARGS__)
  #define DN_ERROR(...) Dane::Log::GetClientLogger()->error(__VA_ARGS__)
  #define DN_FATAL(...) Dane::Log::GetClientLogger()->critical(__VA_ARGS__)
  #define DN_TRACE(...) Dane::Log::GetClientLogger()->trace(__VA_ARGS__)
  #define DN_WARNING(...) Dane::Log::GetClientLogger()->warn(__VA_ARGS__)
#endif

#endif /* defined(__Dane_Log__) */