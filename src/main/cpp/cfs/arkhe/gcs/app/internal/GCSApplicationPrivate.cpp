

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
#include <QtCore/QRegularExpression>
#include <QtCore/QThread>
#include <QtCore/QDir>
#include <QtCore/QProcess>
#include <QtCore/QStandardPaths>

#include <iostream>
#ifdef Q_OS_WIN
  # include <qt_windows.h>
#else
  # include <unistd.h>
  # include <sys/types.h>
  # include <QCtrlSignals>
#endif

#include <cfs/arkhe/gcs/app/internal/GCSApplicationPrivate.hpp>

using namespace cfs::arkhe::gcs::app::internal;

// log4cxx::LoggerPtr GCSApplicationPrivate::logger =
// log4cxx::Logger::getLogger(std::string("levitics.arkhe.gcs.app.private.GCSApplicationPrivate"));


GCSApplicationPrivate::GCSApplicationPrivate(GCSApplication * q_ptr)
    : QObject(q_ptr)
    , q(q_ptr)
    , m_loggerService(new LoggingService())
{
    // LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    //    this->setApplicationName("APP_NAME");
    //    this->setApplicationVersion(APP_VERSION_STR);
    //    this->setOrganizationName(APP_ORG);
    //    this->setOrganizationDomain(APP_DOMAIN);
}

GCSApplicationPrivate::~GCSApplicationPrivate()
{
    // LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    delete this->m_loggerService;
}

void GCSApplicationPrivate::setInstanceId (const QString & id)
{
    // LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

QString
GCSApplicationPrivate::generateSingleId (const QString & seed)
{
    // LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    auto applicationID = QCoreApplication::applicationName().toLower();
    applicationID.remove(QRegularExpression(QStringLiteral("[^a-zA-Z0-9_]")));
    applicationID.truncate(8);
    applicationID.prepend(QStringLiteral("qbackproc-"));
    QByteArray hashBase = (QCoreApplication::organizationName() +
                           QCoreApplication::organizationDomain() +
                           seed).toUtf8();
    applicationID += QLatin1Char('-') +
                     QString::number(qChecksum(hashBase.data(), hashBase.size()), 16) +
                     QLatin1Char('-');

 #ifdef Q_OS_WIN
    DWORD sessID;

    // if (::ProcessIdToSessionId(::GetCurrentProcessId() , &sessID))
    // {
    //    applicationID += QString::number(sessID , 16);
    // }

 #else
    applicationID += QString::number(::getuid(), 16);
 #endif

    return applicationID;
}

GCSApplicationPrivate *
GCSApplicationPrivate::p_ptr ()
{
    // LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    // return qApp->d;
}

int GCSApplicationPrivate::initControlFlow (const QCommandLineParser & parser)
{
    // LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

QString GCSApplicationPrivate::defaultPluginDirectory() const
{
    // LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    // return (QDir::cleanPath(
    // QFileInfo(QCoreApplication::arguments().at(0)).absolutePath() +
    // QDir::separator() + GCS_PLUGIN_PATH
    // ));
}

