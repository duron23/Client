#pragma once

#include "Shared.h"
#include "AbstractCommand.h"

#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

#include <QtCore/QList>
#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QXmlStreamWriter>

class CORE_EXPORT FileRecorderCommand : public AbstractCommand
{
    Q_OBJECT

    public:
        explicit FileRecorderCommand(QObject* parent = 0);

        virtual int getDelay() const;
        virtual int getChannel() const;
        virtual int getVideolayer() const {}
        virtual bool getAllowGpi() const;

        virtual void setChannel(int channel);
        virtual void setVideolayer(int videolayer) {}
        virtual void setDelay(int delay);
        virtual void setAllowGpi(bool allowGpi);

        virtual void readProperties(boost::property_tree::wptree& pt);
        virtual void writeProperties(QXmlStreamWriter* writer);

        const QString& getOutput() const;
        const QString& getCodec() const;
        const QString& getPreset() const;
        const QString& getTune() const;
        bool getWithAlpha() const;

        void setOutput(const QString& output);
        void setCodec(const QString& codec);
        void setPreset(const QString& preset);
        void setTune(const QString& tune);
        void setWithAlpha(bool withAlpha);

    private:
        int channel;
        int delay;
        bool allowGpi;
        QString output;
        QString codec;
        QString preset;
        QString tune;
        bool withAlpha;

        Q_SIGNAL void allowGpiChanged(bool);
        Q_SIGNAL void channelChanged(int);
        Q_SIGNAL void delayChanged(int);
        Q_SIGNAL void outputChanged(const QString&);
        Q_SIGNAL void codecChanged(const QString&);
        Q_SIGNAL void presetChanged(const QString&);
        Q_SIGNAL void tuneChanged(const QString&);
        Q_SIGNAL void withAlphaChanged(bool);
};
