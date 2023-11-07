#ifndef QUILIB_GLOBAL_H
#define QUILIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QUILIB_LIBRARY)
#  define QUILIB_EXPORT Q_DECL_EXPORT
#else
#  define QUILIB_EXPORT Q_DECL_IMPORT
#endif

#endif // QUILIB_GLOBAL_H
