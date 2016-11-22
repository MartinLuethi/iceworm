#ifndef ICEWORMAPP_H
#define ICEWORMAPP_H

#include "MooseApp.h"

class IcewormApp;

template<>
InputParameters validParams<IcewormApp>();

class IcewormApp : public MooseApp
{
public:
  IcewormApp(InputParameters parameters);
  virtual ~IcewormApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* ICEWORMAPP_H */
