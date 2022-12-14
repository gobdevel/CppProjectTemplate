#include <system_error>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "config.h"
#include "doctest/doctest.h"

using namespace Infra;

TEST_CASE("Testing Config file") {
    Config c  = Config::getInstance();
    auto   ec = c.init("../tests/sample.ini");
    CHECK_NE(ec, std::errc::io_error);

    auto ret = c.getString("section1", "key1");
    CHECK_FALSE(!ret);
    CHECK_EQ(ret.value(), "value1");

    auto ret2 = c.getInt("section2", "key2");
    CHECK_FALSE(!ret2.has_value());
    CHECK_EQ(ret2.value(), 100);
}
