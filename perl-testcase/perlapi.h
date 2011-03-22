//---------------------------------------------------------------------------

#ifndef perlapiH
#define perlapiH

#if !defined WIN32
extern int _argc;
extern char ** _argv;
#endif

extern void PrintInt(const char* msg, int nb);
extern void PrintStr(const char* msg, const char * str);
extern void PrintPtr(const char* msg, const void * ptr);

//---------------------------------------------------------------------------
class PerlAPI
{
  void* pinterp;

  static bool mGlobPlInit;
  static void perl_init();
  static void perl_init_compat();

  protected:
    //void ReportError(const AnsiString& aMsg);
    //void ReportError(const char* aFmt, ...);

    static const char * mPerl5Lib;
    static const char * mPerl5Site;
    static const char * mPerl5Vendor;

    char* mError;

    // Closures may only returns bool and don' t use any argument.
    //typedef bool (PerlAPI::*PerlAPICallback_t)(void);
    //std::vector<PerlAPICallback_t> mClosures;
    
    //void CallCallbacks();
  
  public:
    PerlAPI();
    PerlAPI(const char* aFile);
    ~PerlAPI();

    const char* GetError() const { return mError; }

    //int Add(int a, int b);
    //int Add2(int a, int b);
    //int Inc(int a);

    static PerlAPI* GetTestPerl(void);

    bool Connect(const char* dsn, const char* user, const char* pwd);
};
//---------------------------------------------------------------------------
#endif
