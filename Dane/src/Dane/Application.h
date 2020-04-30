#ifndef __Dane_Application__
#define __Dane_Application__

namespace Dane {

  class Application
  {
  public:
    Application();
    virtual ~Application();

    void Run();
  };

  // To be defined on CLIENT
  Application* CreateApplication();
}

#endif /* defined(__Dane_Application__) */