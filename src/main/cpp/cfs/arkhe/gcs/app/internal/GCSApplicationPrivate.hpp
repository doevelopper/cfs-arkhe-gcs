

/*
             █████╗ ██████╗ ██╗  ██╗██╗  ██╗███████╗
            ██╔══██╗██╔══██╗██║ ██╔╝██║  ██║██╔════╝
            ███████║██████╔╝█████╔╝ ███████║█████╗
            ██╔══██║██╔══██╗██╔═██╗ ██╔══██║██╔══╝
            ██║  ██║██║  ██║██║  ██╗██║  ██║███████╗
            ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝

    ╔═╗┬─┐┌─┐┬ ┬┌┐┌┌┬┐  ╔═╗┌─┐┌┐┌┌┬┐┬─┐┌─┐┬    ╔═╗┌┬┐┌─┐┌┬┐┬┌─┐┌┐┌
    ║ ╦├┬┘│ ││ ││││ ││  ║  │ ││││ │ ├┬┘│ ││    ╚═╗ │ ├─┤ │ ││ ││││
    ╚═╝┴└─└─┘└─┘┘└┘─┴┘  ╚═╝└─┘┘└┘ ┴ ┴└─└─┘┴─┘  ╚═╝ ┴ ┴ ┴ ┴ ┴└─┘┘└┘

   Copyright 2015-2017 Levitics Applications Systems

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
 */
#ifndef CFS_ARKHE_GCS_APP_PRIVATE_GCSAPPLICATIONPRIVATE_HPP
#define CFS_ARKHE_GCS_APP_PRIVATE_GCSAPPLICATIONPRIVATE_HPP

#include <QCommandLineParser>
#include <QHash>
#include <QLocale>
#include <QVector>
#include <QTranslator>
#include <QtCore/QObject>
#include <QtCore/qglobal.h>
#include <QtCore/QLockFile>
#include <QtCore/QScopedPointer>
#include <QtCore/QPointer>
#include <QtCore/QLoggingCategory>
#include <QtCore/QFile>
#include <QtNetwork/QLocalServer>

#include <cfs/arkhe/gcs/app/GCSApplication.hpp>

namespace cfs::arkhe::gcs::app::internal
{
    class GCSApplicationPrivate : public QObject
    {
        Q_OBJECT

        public:

            // explicit GCSApplicationPrivate(QObject * parent = nullptr);
            static GCSApplicationPrivate * p_ptr ();
            static QString generateSingleId (const QString &seed = QString());
            GCSApplicationPrivate(cfs::arkhe::gcs::app::GCSApplication * q_ptr);
            ~GCSApplicationPrivate();
            void setInstanceId (const QString &id);
            auto run() -> void;
            QString defaultPluginDirectory() const;

        signals:

        public Q_SLOTS:

            int initControlFlow (const QCommandLineParser &parser);

        private Q_SLOTS:

        // int makeMaster (const QCommandLineParser &parser);
        // int startMaster (bool isAutoStart = false , bool isRestart = false);
        // int restartMaster (const QCommandLineParser &parser);
        // int commandMaster ();
        // int purgeMaster (const QCommandLineParser &parser);

        // void newTerminalConnected ();
        // void terminalLoaded (TerminalPrivate * terminal , bool success);
        // void stopMaster (Terminal * term);
        // void doExit (int code);

        // void beginMasterConnect (const QStringList &arguments , bool isStarter);

        protected:

        private:

            GCSApplication * q;

            static bool p_valid;

            bool m_running;
            bool m_masterLogging;
            bool m_autoStart;
            bool m_ignoreExtraStart;
            bool m_autoDelete;
            bool m_autoKill;

            QString m_instanceId;

            QHash<QLocale, QVector<QTranslator*> > m_translators;

            static const QString m_masterArgument;
            static const QString m_purgeArgument;
            static const QString m_startArgument;
            static const QString m_restartArgument;

            static const QString m_terminalMessageFormat;
            static const QString m_masterMessageFormat;

            // Logger * m_loggerService;
            // static log4cxx::LoggerPtr logger;
    };
}

#endif

