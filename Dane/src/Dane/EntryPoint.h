#include "Application.h"

extern Dane::Application* Dane::CreateApplication();

int main(int argc, char *argv[])
{
  Dane::Application* app = Dane::CreateApplication();
  app->Run();
  delete app;

  return 0;
}