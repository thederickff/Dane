#include "Application.h"

extern Dane::Application* Dane::CreateApplication();

int main(int argc, char *argv[])
{
  Dane::Log::Init();

  DN_CORE_DEBUG("Debug");
  DN_CORE_ERROR("Error");
  DN_CORE_FATAL("Fatal");
  DN_CORE_INFO("My Info");
  DN_CORE_TRACE("Trace");
  DN_CORE_WARNING("Var {0}", 4);

  Dane::Application* app = Dane::CreateApplication();
  app->Run();
  delete app;

  return 0;
}