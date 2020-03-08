

#include <cfs/arkhe/gcs/app/ColorPatternLayout.hpp>

using namespace log4cxx;
using namespace cfs::arkhe::gcs::app;

IMPLEMENT_LOG4CXX_OBJECT(ColorPatternLayout);
ColorPatternLayout::ColorPatternLayout()
    : log4cxx::PatternLayout()
{
}

ColorPatternLayout::ColorPatternLayout(const LogString &s)
    : log4cxx::PatternLayout(s)
{
}

void ColorPatternLayout::format(LogString &output
                                , const spi::LoggingEventPtr &event
                                , helpers::Pool &pool) const
{
    log4cxx::LogString tmp;
    log4cxx::PatternLayout::format(tmp,event,pool);
    log4cxx::LevelPtr lvl = event->getLevel();
    switch (lvl->toInt()) {
    case log4cxx::Level::FATAL_INT:
        output.append("\u001b[0;41m"); //red BG
        break;
    case log4cxx::Level::ERROR_INT:
        output.append("\u001b[0;31m"); // red FG
        break;
    case log4cxx::Level::WARN_INT:
        output.append("\u001b[0;33m"); //Yellow FG
        break;
    case log4cxx::Level::INFO_INT:
        output.append("\u001b[1m"); // Bright
        break;
    case log4cxx::Level::DEBUG_INT:
        output.append("\u001b[2;32m"); // Green FG
        break;
    case log4cxx::Level::TRACE_INT:
        output.append("\u001b[0;30m"); // Black FG
        break;
    default:
        break;
    }
    output.append(tmp);
    output.append("\u001b[m");
}

