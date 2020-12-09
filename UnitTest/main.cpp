#include <UnitTest++/UnitTest++.h>
#include "../http_client/HTTPClient.h"

SUITE(SetUrlTest)
{
    TEST(HttpUrlTest1)
    {
        HTTPClient hc;
        hc.set_url("http://pnzgu.ru/Abitur/abitur_2019");
        CHECK_EQUAL(hc.get_server(), "pnzgu.ru");
        CHECK_EQUAL(hc.get_path(), "/Abitur/abitur_2019");
    }
    TEST(HttpUrlTest2)
    {
        HTTPClient hc;
        hc.set_url("http://pnzgu.ru/");
        CHECK_EQUAL(hc.get_server(), "pnzgu.ru");
        CHECK_EQUAL(hc.get_path(), "/");
    }
    TEST(HttpUrlTest3)
    {
        HTTPClient hc;
        hc.set_url("http://pnzgu.ru");
        CHECK_EQUAL(hc.get_server(), "pnzgu.ru");
        CHECK_EQUAL(hc.get_path(), "/");
    }
    TEST(HttpsUrlTest)
    {
        HTTPClient hc;
        CHECK_THROW(hc.set_url("https://pnzgu.ru/"), Error);
    }
    TEST(FtpUrlTest)
    {
        HTTPClient hc;
        CHECK_THROW(hc.set_url("ftp://pnzgu.ru/"), Error);
    }
    TEST(RelativeUrlTest1)
    {
        HTTPClient hc;
        CHECK_THROW(hc.set_url("/schedule"), Error);
    }
    TEST(RelativeUrlTest2)
    {
        HTTPClient hc;
        CHECK_THROW(hc.set_url("admission/rezult_old"), Error);
    }
    TEST(RelativeUrlTest3)
    {
        HTTPClient hc;
        hc.set_server("pnzgu.ru");
        hc.set_path("/Abitur/admission/contacts");
        hc.set_url("/schedule");
        CHECK_EQUAL(hc.get_server(), "pnzgu.ru");
        CHECK_EQUAL(hc.get_path(), "/schedule");
    }
    TEST(RelativeUrlTest4)
    {
        HTTPClient hc;
        hc.set_server("pnzgu.ru");
        hc.set_path("/Abitur/abitur_2019");
        hc.set_url("admission/rezult_old");
        CHECK_EQUAL(hc.get_server(), "pnzgu.ru");
        CHECK_EQUAL(hc.get_path(), "/Abitur/admission/rezult_old");
    }
}
    
SUITE(ParseHeadersTest)
{
    TEST(ResponseCode200)
    {
        int http_code;
        std::string loc, http_str = "HTTP/1.0 200 OK\r\n\r\n";
        int ret = HTTPClient::parse_headers(http_str, http_code, loc);
        CHECK_EQUAL(ret, 19);
        CHECK_EQUAL(http_code, 200);
        CHECK(loc.empty());
    }
    TEST(ResponseCode301)
    {
        int http_code;
        std::string loc, http_str = "HTTP/1.1 301 Moved Permanently\r\nServer: Apache\r\nLocation: http://ya.ru\r\nContent-Language: ru\r\n\r\n";
        int ret = HTTPClient::parse_headers(http_str, http_code, loc);
        CHECK_EQUAL(ret, 96);
        CHECK_EQUAL(http_code, 301);
        CHECK_EQUAL(loc, "http://ya.ru");
    }
    TEST(ResponseLocationNotHeader)
    {
        int http_code;
        std::string loc, http_str = "HTTP/1.1 200 OK\r\nServer: Apache\r\n\r\nLocation: http://ya.ru\r\n";
        int ret = HTTPClient::parse_headers(http_str, http_code, loc);
        CHECK_EQUAL(ret, 35);
        CHECK_EQUAL(http_code, 200);
        CHECK(loc.empty());
    }
    TEST(IncorrectResponse)
    {
        int http_code;
        std::string loc, http_str = "HTTP/1.1 200 OK\r\n";
        int ret = HTTPClient::parse_headers(http_str, http_code, loc);
        CHECK_EQUAL(ret, -1);
    }
}

int main(int argc, char **argv)
{
    return UnitTest::RunAllTests();
}
