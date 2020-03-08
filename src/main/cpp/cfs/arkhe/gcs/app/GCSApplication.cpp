

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
#include <locale>
#include <iostream>
#include <cstdlib>      /* getenv */
#include <cstdio>

#include <QCommandLineParser>
#include <QStandardPaths>

#include <cfs/arkhe/gcs/app/GCSApplication.hpp>
#include <cfs/arkhe/gcs/app/internal/GCSApplicationPrivate.hpp>
//#include <levitics/arkhe/gcs/app/MultiScreenManagement.hpp>

using namespace cfs::arkhe::gcs::app;
using namespace cfs::arkhe::gcs::app::internal;

int const GCSApplication::EXIT_CODE_REBOOT = -666;
const std::string GCSApplication::LOGGER_CONFIGURATION_LOCATION = "LOG4CXX_CONFIGURATION_PATH =/etc/cfg/log4cxx.xml";
// log4cxx::LoggerPtr GCSApplication::logger =
// log4cxx::Logger::getLogger(std::string("levitics.arkhe.gcs.app.GCSApplication"));

GCSApplication::GCSApplication(int &  argc,
                               char * *  argv,
                               Qt::WindowFlags f)
#ifndef GCS_NO_GUI
    : QApplication(argc, argv, f)
#else
    : QCoreApplication(argc, argv)
#endif
    , d(new GCSApplicationPrivate(this))
    , m_applicationPath()
    , m_userPath()
    , m_imagePath()
    , m_videoPath()
    , m_homePath()
    , m_desktopPath()
    , m_tempFolderPath()
    , m_documentsPath()
    // , m_multiScreenManagement(new MultiScreenManagement())
{
    // LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    // LOG4CXX_INFO(logger , std::locale("").name().c_str());
    // m_multiScreenManagement->sreensInfo();

    //    QLocale us(QLocale::English,QLocale::UnitedStates);
    //    QLocale::setDefault(us);
    /*
       std::setlocale(LC_ALL, "en_US.UTF-8");
       std::setlocale(LC_NUMERIC, "de_DE");
       std::setlocale(LC_TIME, "ja_JP");
       std::setlocale(LC_ALL    );//selects the entire C locale
       std::setlocale(LC_COLLATE        );//selects the collation category of the C locale
       std::setlocale(LC_CTYPE  );//selects the character classification category of the C locale
       std::setlocale(LC_MONETARY       );//selects the monetary formatting category of the C locale
       std::setlocale(LC_NUMERIC        );//selects the numeric formatting category of the C locale
       std::setlocale(LC_TIME   );//selects the time formatting category of the C locale
     */
    // Version ver;
    // LOG4CXX_INFO(logger , "Dvcs info: " << ver.getRevString());
    // LOG4CXX_INFO(logger , "Release: "<< VERSION_HEX);
    // LOG4CXX_INFO(logger , "Dev info: " << ver.getABI().toStdString());
    // LOG4CXX_WARN(logger , "Locale: " << QLocale::system().name().toStdString());
    // LOG4CXX_WARN(logger , "Country: " << QLocale::system().country());
    //    this->init();
}

GCSApplication::~GCSApplication()
{
    // LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    if(d)
    {
        delete d;
    }

    // if ( m_multiScreenManagement )
    // {
    // delete m_multiScreenManagement;
    // }

    // if (  m_view)
    // {
    // delete m_view;
    // }

    // if (  m_MainWindow)
    // {
    // delete m_MainWindow;
    // }

    ////    this->setParent(Q_NULLPTR);
}

void GCSApplication::init ()
{
    // LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    //    QDesktopWidget * widget = QApplication::desktop();

    // if (QApplication::desktop()->screenCount() > 1)
    // {
    // QRect screenres = QApplication::desktop()->screenGeometry(1 /*screenNumber*/);
    // m_MainWindow = new  MainWindow();
    // this->m_MainWindow->move(QPoint(screenres.x() , screenres.y()));
    // this->m_MainWindow->resize(screenres.width() , screenres.height());
    //        //    QRect rect = widget->screenGeometry(0);
    ////    m_MainWindow->move(rect.width() , rect.y());
    ////    this->m_MainWindow->move(0 , 0);
    //// this->m_MainWindow->windowHandle()->setScreen(qApp->screens()[1]);
    // this->m_MainWindow->show();
    ////        this->m_MainWindow->showFullScreen();

    // QRect secodScreenRes = QApplication::desktop()->screenGeometry(0 /*screenNumber*/);
    // this->m_view = new  View();
    // this->m_view->move(QPoint(secodScreenRes.x() , secodScreenRes.y()));
    // this->m_view->resize(secodScreenRes.width() , secodScreenRes.height());
    ////        this->m_view->showFullScreen();
    // this->m_view->show();
    ////    //    QRect rect widget->screenGeometry(1);
    ////    //    m_view->move(rect.width() , rect.y());
    // }
    // else
    // {
    // LOG4CXX_WARN(logger , "Multi screen not supported");
    // }
}

void GCSApplication::restartApplication()
{
    // LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    qApp->exit( GCSApplication::EXIT_CODE_REBOOT );
}

/*
   bool GCSApplication::event (QEvent * event)
   {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    switch (event->type())
    {
    case QEvent::FileOpen :
        break;

    case QEvent::Close :
        // saveSettings();
        break;

    case QEvent::FontChange :
        break;

    case QEvent::Gesture :
    case QEvent::GestureOverride :
        break;

    case QEvent::Hide :
        break;

    case QEvent::HideToParent :
        break;

    case QEvent::HoverEnter :
        break;

    case QEvent::HoverLeave :
        break;

    case QEvent::OrientationChange :             // The screens orientation has changes
        break;

    case QEvent::HoverMove :            // Widget's position changed
        break;

    case QEvent::Move :
        break;

    case QEvent::Resize :            // Widget's size changed
        break;

    case QEvent::Leave :             // Mouse leaves widget's boundaries.
        break;

    default :
        break;
    }

    // return QApplication::event(event);
   }
 */

QUrl GCSApplication::homePath ()
{
    // LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    const QStringList homesLocation = QStandardPaths::standardLocations(QStandardPaths::HomeLocation);
    QUrl appPath(applicationCurrentPath().at(0));

    if (homesLocation.isEmpty())
    {
        m_homePath = appPath.resolved(QUrl("/"));
    }
    else
    {
        m_homePath = QString("%1").arg(homesLocation.first());
    }

    return (m_homePath);
}

QUrl GCSApplication::desktopPath ()
{
    // LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    const QStringList desktopsLocation = QStandardPaths::standardLocations(QStandardPaths::DesktopLocation);
    QUrl appPath(applicationCurrentPath().join(""));

    if (desktopsLocation.isEmpty())
    {
        m_desktopPath = appPath.resolved(QUrl("/"));
    }
    else
    {
        m_desktopPath = QString("%1").arg(desktopsLocation.first());
    }

    return (m_desktopPath);
}

QStringList GCSApplication::applicationCurrentPath ()
{
    // LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    m_applicationPath = QString("%1").arg(QCoreApplication::applicationDirPath());
    // LOG4CXX_DEBUG(logger , m_applicationPath.toString().toStdString());

    //  return(m_applicationPath);
}

QUrl GCSApplication::userPath ()
{
    // LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    const QStringList usersLocation = QStandardPaths::standardLocations(QStandardPaths::HomeLocation);
    QUrl appPath(applicationCurrentPath().join(""));

    if (usersLocation.isEmpty())
    {
        // m_userPath = applicationCurrentPath().resolved(QUrl("/home/"));
        m_userPath = appPath.resolved(QUrl("/home/"));
    }
    else
    {
        m_userPath = QString("%1").arg(usersLocation.first());
    }

    // LOG4CXX_DEBUG(logger , m_userPath.toString().toStdString());
    return (m_userPath);
}

QUrl GCSApplication::imagePath ()
{
    // LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    const QStringList picturesLocation = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
    QUrl appPath(applicationCurrentPath().join(""));

    if (picturesLocation.isEmpty())
    {
        m_imagePath = appPath.resolved(QUrl("images"));
    }
    else
    {
        m_imagePath = QString("%1").arg(picturesLocation.first());
    }

    // LOG4CXX_DEBUG(logger , m_imagePath.toString().toStdString());
    return (m_imagePath);
}

QUrl GCSApplication::videoPath ()
{
    // LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    const QStringList moviesLocation = QStandardPaths::standardLocations(QStandardPaths::MoviesLocation);
    QUrl appPath(applicationCurrentPath().join(""));

    if (moviesLocation.isEmpty())
    {
        m_videoPath = appPath.resolved(QUrl("./"));
    }
    else
    {
        m_videoPath = QString("%1").arg(moviesLocation.first());
    }

    // LOG4CXX_DEBUG(logger , m_videoPath.toString().toStdString());
    return (m_videoPath);
}

QUrl GCSApplication::tempFolderPath ()
{
    // LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    const QStringList tempsLocation = QStandardPaths::standardLocations(QStandardPaths::TempLocation);
    QUrl appPath(applicationCurrentPath().join(""));

    if (tempsLocation.isEmpty())
    {
        m_tempFolderPath = appPath.resolved(QUrl("/"));
    }
    else
    {
        m_tempFolderPath = QString("%1").arg(tempsLocation.first());
    }

    // LOG4CXX_DEBUG(logger , m_tempFolderPath.toString().toStdString());
    return (m_tempFolderPath);
}

QUrl GCSApplication::documentsPath ()
{
    // LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    const QStringList docsLocation = QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation);
    QUrl appPath(applicationCurrentPath().join(""));

    if (docsLocation.isEmpty())
    {
        m_documentsPath = appPath.resolved(QUrl("/"));
    }
    else
    {
        m_documentsPath = QString("%1").arg(docsLocation.first());
    }

    // LOG4CXX_DEBUG(logger , m_documentsPath.toString().toStdString());
    return (m_documentsPath);
}

