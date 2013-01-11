#ifndef REALISTICRAYTRACING_IMPORT_H
#define REALISTICRAYTRACING_IMPORT_H 

#ifndef R_DLL_EXPORT
#define R_DECLDIR __declspec(dllimport)
#else
#define R_DECLDIR __declspec(dllexport)
#endif

#endif 