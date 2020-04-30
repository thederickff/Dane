#include <Dane.h>

class SandboxApp : public Dane::Application
{
public:
  SandboxApp()
  {

  }

  ~SandboxApp()
  {

  }
};

Dane::Application* Dane::CreateApplication()
{
  return new SandboxApp();
}