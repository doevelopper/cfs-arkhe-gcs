

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

//#include <QPixmapCache>
#include <cstdlib>

//#include <cfs/arkhe/gcs/app/GCSApplication.hpp>

// [[using CC:opt(1) , debug]]

int main (int argc, char * * argv)
{
 #if defined (Q_OS_WINRT) && !defined (Q_OS_WINPHONE)

 #endif

 #ifdef Q_OS_WIN32
    //QApplication::setAttribute(Qt::AA_UseOpenGLES);
 #endif

 #if defined (Q_OS_ANDROID)

 #endif

 #if defined (Q_OS_LINUX)

 #endif

    /*
        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
        QCoreApplication::setAttribute(Qt::AA_ShareOpenGLContexts , true);
        QCoreApplication::setAttribute(Qt::AA_DontCreateNativeWidgetSiblings , true);
        QLocale::setDefault(QLocale::C);
        // setlocale(LC_ALL , "C");

        QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
        QPixmapCache::setCacheLimit(819200);

        QtSingleApplication app(argc, argv);
        if(app.isRunning())
        {
            return(app.sendMessage(someDataString);

        }

        MyMainWidget mmw;
        app.setActivationWindow(&mmw);
        mmw.show();
        return app.exec();

        int currentExitCode = 0;
        do
        {
        // GCSApplication app (argc , argv);
        // app.init();
            // QObject::connect(GCSApplication, SIGNAL(destroyed(QObject*)),
                         // &app, SLOT(quit()));
        //int currentExitCode = app.exec ();
        //perform some clean up before returning...
        }
        while(currentExitCode == 0 //GCSApplication::EXIT_CODE_REBOOT// );
        return (currentExitCode);
     */
    return(EXIT_SUCCESS);
}

