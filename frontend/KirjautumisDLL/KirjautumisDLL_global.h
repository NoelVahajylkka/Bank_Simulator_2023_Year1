#ifndef KIRJAUTUMISDLL_GLOBAL_H
#define KIRJAUTUMISDLL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(KIRJAUTUMISDLL_LIBRARY)
#  define KIRJAUTUMISDLL_EXPORT Q_DECL_EXPORT
#else
#  define KIRJAUTUMISDLL_EXPORT Q_DECL_IMPORT
#endif

#endif // KIRJAUTUMISDLL_GLOBAL_H
