/**
 * @file
 * @ingroup i386
 * @brief Default output streams
 */

#include "output.h"

#if DEBUG

CGA kout;
CGA debug;

#else // DEBUG

Serial kout(Serial::COM1);
Null_Stream debug;

#endif // DEBUG
