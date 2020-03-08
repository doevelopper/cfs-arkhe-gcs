

#ifndef CFS_ARKHE_GCS_APP_APPENDERS_GCSSOCKETAPPENDER_HPP
#define CFS_ARKHE_GCS_APP_APPENDERS_GCSSOCKETAPPENDER_HPP

#include <log4cxx/spi/loggingevent.h>
#include <log4cxx/appenderskeleton.h>
#include <log4cxx/net/socketappenderskeleton.h>
#include <log4cxx/logger.h>

namespace cfs::arkhe::gcs::app::appenders
{
    class GCSSocketAppender
    {
        public:

            DECLARE_LOG4CXX_OBJECT(GCSSocketAppender)
            BEGIN_LOG4CXX_CAST_MAP()
            LOG4CXX_CAST_ENTRY(GCSSocketAppender)
            LOG4CXX_CAST_ENTRY_CHAIN(AppenderSkeleton)
            END_LOG4CXX_CAST_MAP()

            GCSSocketAppender() = default;
            GCSSocketAppender(const GCSSocketAppender&) = default;
            GCSSocketAppender(GCSSocketAppender&&) = default;
            GCSSocketAppender& operator=(const GCSSocketAppender&) = default;
            GCSSocketAppender& operator=(GCSSocketAppender&&) = default;
            virtual ~GCSSocketAppender() = default;

            GCSSocketAppender(helpers::InetAddressPtr& address, int port);
            GCSSocketAppender(const LogString& host, int port);

        protected:

            virtual void setSocket(log4cxx::helpers::SocketPtr& socket, log4cxx::helpers::Pool& p);
            virtual void cleanUp(log4cxx::helpers::Pool& p);
            virtual int getDefaultDelay() const;
            virtual int getDefaultPort() const;
            void append(const log4cxx::spi::LoggingEventPtr& event, log4cxx::helpers::Pool& p);
            bool requiresLayout() const {
                return true;
            }

        //void close();
        //bool isClosed() const { return closed; }

        private:

            log4cxx::helpers::ObjectOutputStreamPtr oos;

            static log4cxx::LoggerPtr logger;
            /*!
             *  The default port number of remote logging server (4560).
             */
            static const int DEFAULT_PORT;

            /*!
             *  The default reconnection delay (30000 milliseconds or 30 seconds).
             */
            static int DEFAULT_RECONNECTION_DELAY;
    };
}

#endif

