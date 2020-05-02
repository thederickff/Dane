#include "Log.h"

namespace Dane {

  std::shared_ptr<Realog::Logger> Log::s_CoreLogger;
  std::shared_ptr<Realog::Logger> Log::s_ClientLogger;

  void Log::Init()
  {
    s_CoreLogger = std::make_shared<Realog::Logger>("DANE");
    s_ClientLogger = std::make_shared<Realog::Logger>("APP");
  }

}