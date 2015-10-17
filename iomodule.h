#ifndef IOMODULE_H
#define IOMODULE_H


#include "webmconverter.h"

class IOModule
{
public:
    IOModule();

    int write_config_file(WebmConverter *wc);

    int read_config_file(WebmConverter *wc);
};

#endif // IOMODULE_H
