
#include <cfs/arkhe/gcs/Test.hpp>

using namespace cfs::arkhe::cgs::test;

Test::Test()
    : m_testSuites(std::string())
    , m_numberOfTestIteration(1)
{

}

Test::Test(std::string & suite, unsigned int iteration)
    : m_testSuites(suite)
    , m_numberOfTestIteration(iteration)
{

}

Test::~Test()
{

}

int Test::run (int argc, char * argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

void Test::showUsage(std::string name)
{
    std::cerr << "Usage: " << name << " <option(s)> SOURCES \n"
              << "Options:\n"
              << "\t-h,--help \t Show this help message\n"
              << "\t-i,--iterration \t Number of iteration on test Default 1\n"
              << "\t-o,--outputpath \t Specify the destination path Default netx to executable\n"
              << "\t-m,--module \t The name of xml test report to be generated\n"
              << "\t-l,--list \t Specify the list of tests to be executed Default netx to executable\n"
              << std::endl;

}
