#include "IcewormApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<IcewormApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

IcewormApp::IcewormApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  IcewormApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  IcewormApp::associateSyntax(_syntax, _action_factory);
}

IcewormApp::~IcewormApp()
{
}

// External entry point for dynamic application loading
extern "C" void IcewormApp__registerApps() { IcewormApp::registerApps(); }
void
IcewormApp::registerApps()
{
  registerApp(IcewormApp);
}

// External entry point for dynamic object registration
extern "C" void IcewormApp__registerObjects(Factory & factory) { IcewormApp::registerObjects(factory); }
void
IcewormApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void IcewormApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { IcewormApp::associateSyntax(syntax, action_factory); }
void
IcewormApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
