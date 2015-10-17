#include "iomodule.h"

IOModule::IOModule()
{

}

int IOModule::write_config_file(WebmConverter *wc)
{
    QFile conv_file("tmp.config");

    conv_file.open(QIODevice::WriteOnly);

    QTextStream tstream(&conv_file);
    tstream << wc->get_base_filename();
    tstream << endl;
    tstream << wc->get_output_filename();
    tstream << endl;
    tstream << wc->get_crf();
    tstream << endl;
    tstream << wc->get_seg_start();
    tstream << endl;
    tstream << wc->get_seg_end();

    conv_file.close();

    return 0;
}

int IOModule::read_config_file(WebmConverter *wc)
{
    bool ok = false;
    QFile conv_file("tmp.config");

    conv_file.open(QIODevice::ReadOnly);

    QTextStream tstream(&conv_file);
    wc->set_base_filename(tstream.readLine(0));
    wc->set_output_filename(tstream.readLine(0));
    wc->set_crf(tstream.readLine(0).toInt(&ok, 10));
    if (!ok) {
        return -1;
    }

    wc->set_seg_start(tstream.readLine(0).toInt(&ok, 10));
    if (!ok) {
        return -1;
    }
    wc->set_seg_end(tstream.readLine(0).toInt(&ok, 10));
    if (!ok) {
        return -1;
    }

    conv_file.close();

    return 0;
}

