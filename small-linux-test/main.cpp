//---------------------------------------------------------------------------

#pragma hdrstop  
#include "perlapi.h"

#include <string>
#include <iostream>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;


#if !defined WIN32
int _argc;
char ** _argv;
#endif

#pragma argsused
int main(int argc, char* argv[])
{
#if !defined WIN32
  _argc = argc;
  _argv = argv;
#endif
  cout << "start ..." << endl;

  PerlAPI lApi("test.pl");

  bool lConnect = lApi.Connect("DBI:mysql:bastien;host=linux2", "bastien", "");

  cout << "connect: " << lConnect << endl;

  if (lApi.GetError()) cerr << lApi.GetError() << endl;

  int i;
  cin >> i;
  return 0;
}

static std::string ExePath()
{
#if defined WIN32
  return "C:\\strawberry-perl-5.12.2.0-portable\\";
#else
  return "/usr/lib/5.10";
#endif
}

bool PerlAPI::mGlobPlInit=false;

#define TOTDebugInitFunc() 
#define TOTDebug(x)
#define TOTDebugError(x)
#define TOTDebugInfo(x)

//---------------------------------------------------------------------------
static std::string sgLib;
static std::string sgSite;
static std::string sgVendor;
const char * PerlAPI::mPerl5Lib;
const char * PerlAPI::mPerl5Site;
const char * PerlAPI::mPerl5Vendor;

/*  this function has to be defined where perl.h is not included */
/* otherwise Borland will complain */
void PerlAPI::perl_init_compat()
{        
  TOTDebugInitFunc();
  TOTDebugInfo(("Initializing perl ..."));
	putenv("PERL5LIB=");
#if defined WIN32
	sgSite=std::string("-I")+ExePath()+"perl\\site\\lib";
	sgVendor=std::string("-I")+ExePath()+"perl\\vendor\\lib";
	sgLib=std::string("-I")+ExePath()+"perl\\lib";
#else
	sgSite=std::string("-I")+ExePath()+"/perl/site/lib";
	sgVendor=std::string("-I")+ExePath()+"/perl/vendor/lib";
	sgLib=std::string("-I")+ExePath()+"/perl/lib";
#endif
	mPerl5Lib=sgLib.c_str();
	mPerl5Site=sgSite.c_str();
	mPerl5Vendor=sgVendor.c_str();
}
//---------------------------------------------------------------------------
