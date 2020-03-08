

#include <log4cxx/helpers/loglog.h>
#include <log4cxx/helpers/optionconverter.h>
#include <log4cxx/helpers/stringhelper.h>
#include <log4cxx/spi/loggingevent.h>
#include <log4cxx/helpers/synchronized.h>
#include <log4cxx/helpers/objectoutputstream.h>
//#include <apr_time.h>
//#include <apr_atomic.h>
//#include <apr_thread_proc.h>
#include <log4cxx/helpers/socketoutputstream.h>
#include <cfs/arkhe/gcs/app/appenders/GCSSocketAppender.hpp>

using namespace cfs::arkhe::gcs::app::appenders;
using namespace log4cxx;
using namespace log4cxx::helpers;

log4cxx::LoggerPtr GCSSocketAppender::logger = "";

const int GCSSocketAppender::DEFAULT_PORT = 4560;
const int GCSSocketAppender::DEFAULT_RECONNECTION_DELAY = 3000;

GCSSocketAppender::GCSSocketAppender()
    : SocketAppenderSkeleton(DEFAULT_PORT, DEFAULT_RECONNECTION_DELAY)
{
}

GCSSocketAppender::GCSSocketAppender(InetAddressPtr& address1, int port1)
    : SocketAppenderSkeleton(address1, port1, DEFAULT_RECONNECTION_DELAY)
{
    Pool p;
    activateOptions(p);
}

GCSSocketAppender::GCSSocketAppender(const LogString& host, int port1)
    : SocketAppenderSkeleton(host, port1, DEFAULT_RECONNECTION_DELAY)
{
    Pool p;
    activateOptions(p);
}

/*
   GCSSocketAppender::~GCSSocketAppender()
   {
    finalize();
   }

   int GCSSocketAppender::getDefaultDelay() const
   {
    return DEFAULT_RECONNECTION_DELAY;
   }

   int GCSSocketAppender::getDefaultPort() const
   {
    return DEFAULT_PORT;
   }

   void GCSSocketAppender::setSocket(log4cxx::helpers::SocketPtr& socket, Pool& p)
   {
    synchronized sync(mutex);
    oos = new ObjectOutputStream(new SocketOutputStream(socket), p);
   }

   void GCSSocketAppender::cleanUp(Pool& p)
   {
    if (oos != 0)
    {
        try
        {
            oos->close(p);
            oos = 0;
        }
        catch(std::exception& e)
        {
        }
    }
   }

   void GCSSocketAppender::append(const log4cxx::spi::LoggingEventPtr& event, Pool& p)
   {
       if ( this->layout == NULL )
       {
             LOG4CXX_ENCODE_CHAR(nameStr, name);
             std::string msg("No Layout set for the appender named [ ");
             msg.append(nameStr);
             msg.append(" ].");

             LOG4CXX_DECODE_CHAR(msgL, msg);
             errorHandler->error(msgL);
           return;
       }

       log4cxx::LogString fMsg;

       this->layout->format(fMsg, event, p);

       if (oos != 0)
       {
           try
           {
              //event->write(*oos, p);
              oos->writeUTFString(fMsg.c_str(),p);
              oos->flush(p);
           }
           catch(std::exception& e)
           {
              oos = 0;
              LogLog::warn(LOG4CXX_STR("Detected problem with connection: "), e);
                  if (getReconnectionDelay() > 0)
                {
                  fireConnector();
                }
           }
       }


       LOG4CXX_ENCODE_CHAR(fMsgStr, fMsg);

       // This example appender prints to the screen just like
       // a console appender. Do something with the data here
       //std::cout<<"GCSSocketAppender: " <<fMsgStr.c_str();

       //LogVector.push_back(fMsgStr);
   }
 */

