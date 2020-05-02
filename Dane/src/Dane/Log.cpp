#include "Log.h"

#include "spdlog/sinks/ostream_sink.h"

namespace Dane {

  std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
  std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

  void Log::Init()
  {
    auto sink = std::make_shared<spdlog::sinks::ansicolor_stdout_sink_mt>();
    sink->set_pattern("%^[%T] %n: %v%$");

    s_CoreLogger = std::make_shared<spdlog::logger>("DANE", sink);
    s_CoreLogger->set_level(spdlog::level::trace);

    s_ClientLogger = std::make_shared<spdlog::logger>("APP", sink);
    s_ClientLogger->set_level(spdlog::level::trace);
  }

}