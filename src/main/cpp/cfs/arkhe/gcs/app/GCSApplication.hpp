

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
#ifndef CFS_ARKHE_GCS_APP_GCSAPPLICATION_HPP
#define CFS_ARKHE_GCS_APP_GCSAPPLICATION_HPP

#include <locale>
#include <iostream>
#include <cstdlib>
#include <cstdio>

#include <QtCore/QObject>
#include <QtGlobal>
#include <QLocale>
#include <QTranslator>
#include <QUrl>
#include <QApplication>
#include <QException>
#include <functional>
#include <QFontDatabase>

#define gcsApp (static_cast<GCSApplication *>(QGuiApplication::instance()))

namespace cfs::arkhe::gcs::app
{
    // #if GCS_SINGLE_APP
    // #include <cfs/arkhe/gcs/app/qtsingleapplication/qtsingleapplication.h>
    // #endif

    class GCSApplicationPrivate;
    // class MultiScreenManagement;

#ifndef GCS_NO_GUI
    class GCSApplication : public QApplication
#else
    class GCSApplication : public QCoreApplication
#endif
    {
        Q_OBJECT
        // Q_DECLARE_PRIVATE(GCSApplication)

        public:

            GCSApplication(int & argc, char * * argv, Qt::WindowFlags f = Qt::WindowFlags());
            GCSApplication(const GCSApplication &) Q_DECL_EQ_DELETE;
            GCSApplication(GCSApplication &&) Q_DECL_EQ_DELETE;
            GCSApplication & operator = (const GCSApplication &) Q_DECL_EQ_DELETE;
            GCSApplication & operator = (GCSApplication &&) Q_DECL_EQ_DELETE;
            ~GCSApplication();

            static GCSApplication * instance ()
            {
                return static_cast<GCSApplication *>(qApp);
            }

            void init ();
            void applicationShutdown ();
            void restartApplication();
            QUrl homePath ();
            QUrl desktopPath ();
            QUrl userPath ();
            QUrl imagePath ();
            QUrl videoPath ();
            QUrl tempFolderPath ();
            QUrl documentsPath ();
            QStringList applicationCurrentPath ();

        protected:

        //  bool event (QEvent * event);

        private:

            void addTranslator(const QLocale &locale, QTranslator *translator);
            void addTranslator(const QString &locale, QTranslator *translator);
            void addTranslators(const QLocale &locale, const QVector<QTranslator *> &translators);
            QString translate(const QLocale &locale
                              , const char *context
                              , const char *sourceText
                              , const char *disambiguation = Q_NULLPTR
                              , int n = -1) const;

            //Q_DECLARE_PRIVATE(GCSApplication);
            // View * m_view { };
            // MainWindow * m_MainWindow{ };
            GCSApplicationPrivate * d;
            // MultiScreenManagement * m_multiScreenManagement;
            QUrl m_applicationPath;
            QUrl m_userPath;
            QUrl m_imagePath;
            QUrl m_videoPath;
            QUrl m_homePath;
            QUrl m_desktopPath;
            QUrl m_tempFolderPath;
            QUrl m_documentsPath;
            // Version m_versionInfo;
            // QFontDatabase m_fontDatabase;
            // const QString m_fontFileName;           ///< Font file is part of the QRC file and compiled into the app.
            // const QString m_fontFamilyName;
            /*!
             *
             */
            // LoggingService * m_loggerService;
            static const long        FILE_MONITOR_DELAY = 5000UL;
            static const std::string LOGGER_CONFIGURATION_LOCATION;
            static int const         EXIT_CODE_REBOOT;
            // static log4cxx::LoggerPtr logger;
    };
}

#endif

