#ifndef WEBMCONVERTER_H
#define WEBMCONVERTER_H

#include <QString>
#include <QProcess>
#include <QFile>
#include <QTextStream>

class WebmConverter
{
public:
    WebmConverter();

    int make_conv_file();
    int convert();

    void set_base_filename(QString base_filename);
    void set_output_filename(QString output_filename);
    void set_seg_start(quint32 seg_start);
    void set_seg_end(quint32 seg_end);
    void set_seg_len(quint32 seg_len);
    void set_crf(qint32 crf);
    void set_qmin(qint32 qmin);
    void set_qmax(qint32 qmax);
    void create_exec_script();
    void set_codec(QString codec);

    QString get_base_filename();
    QString get_output_filename();
    quint32 get_seg_start();
    quint32 get_seg_end();
    quint32 get_seg_len();
    qint32 get_crf();
    qint32 get_qmin();
    qint32 get_qmax();

private:
    QString _base_filename;
    QString _output_filename;
    QString _codec;
    quint32 _seg_start;
    quint32 _seg_end;
    quint32 _seg_len;
    qint32 _crf;
    qint32 _qmin;
    qint32 _qmax;
    QString _exec_script;
};

#endif // WEBMCONVERTER_H
