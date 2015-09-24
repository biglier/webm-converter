#include "webmconverter.h"

WebmConverter::WebmConverter()
{
    _qmin = -1;
    _qmax = -1;
    _crf = -1;
    _base_filename = "";
    _output_filename = "";
    _seg_start = 0;
    _seg_end = 0;
    _seg_len = 5;
    _final_script = "ffmpeg ";
}

void WebmConverter::convert()
{
    QProcess converter_pr;
    converter_pr.execute(_final_script);
}

int WebmConverter::make_conv_file()
{
    QFile conv_file("tmp.k");

    conv_file.open(QIODevice::ReadWrite);

    QTextStream tstream(&conv_file);
    tstream >> _exec_script;

    conv_file.close();

    return 0;
}

void WebmConverter::set_base_filename(QString base_filename)
{
    _base_filename = base_filename;
}

QString WebmConverter::get_base_filename()
{
    return _base_filename;
}

void WebmConverter::set_output_filename(QString output_filename)
{
    _output_filename = output_filename;
}

QString WebmConverter::get_output_filename()
{
    return _output_filename;
}

void WebmConverter::set_seg_start(quint32 seg_start)
{
    _seg_start = seg_start;
}

quint32 WebmConverter::get_seg_start()
{
    return _seg_start;
}

void WebmConverter::set_seg_end(quint32 seg_end)
{
    _seg_end = seg_end;
}

quint32 WebmConverter::get_seg_end()
{
    return _seg_end;
}

void WebmConverter::set_seg_len(quint32 seg_len)
{
    _seg_len = seg_len;
}

quint32 WebmConverter::get_seg_len()
{
    return _seg_len;
}

void WebmConverter::set_crf(qint32 crf)
{
    _crf = crf;
}

qint32 WebmConverter::get_crf()
{
    return _crf;
}

void WebmConverter::set_qmin(qint32 qmin)
{
    _qmin = qmin;
}

qint32 WebmConverter::get_qmin()
{
    return _qmin;
}

void WebmConverter::set_qmax(qint32 qmax)
{
    _qmax = qmax;
}

qint32 WebmConverter::get_qmax()
{
    return _qmax;
}

void WebmConverter::create_exec_script()
{
    _exec_script += "-ss " + QString::number(_seg_start) +
            " -i " + _base_filename + " " + "-t " + QString::number(_seg_len) +
            " -crf " + QString::number(_crf) + " " + _output_filename;
}
