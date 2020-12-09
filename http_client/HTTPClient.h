/**
 * @file HTTPClient.h
 * @author В.А. Авдеев
 * @version 0.1
 * @date 01.09.2019
 * @copyright ИБСТ ПГУ
 * @brief Заголовочный файл для модуля HTTPClient, для работы по протоколу HTTP
 */

#pragma once
#include <string>
#include <exception>
#include <Winsock2.h>

using namespace std;

/**
 * @brief Класс для работы cкачивания файла по HTTP
 * метод set_url устанавливает url,
 * метод set_url устанавливает путь сохранения файла
 * метод request выполняет запрос
 */
class HTTPClient
{
private:
    char recv_buf[1024*1024]; //!< Буфер пиёма данных от сервера
    int  recv_count; //!< Количество принятых данных в буфере recv_buf
    string server; //!< Адресс сервера
    string path; //!< Путь к файлу на сервере
    string file_path; //!< Путь по которому будет сохранён файл
    SOCKET client_sock; //!< Дейскриптор сокета
    /**
     * @brief Устанавливает соединение с сервером
     * @throw Error в случае ошибки
     */
    void connect();
    /**
     * @brief Записывает полученные с сервера данные в файл
     * @details Записывает recv_count байт recv_buf в файл file_path,
     * затем получает из сокета в recv_buf следующию порцию данных,
     * цикл повторяется пока на сокете не закончутся данные
     * @throw Error в случае ошибки
     */
    void save_to_file();
public:
    /**
     * @brief Выполняет необходимую инициализацию
     * @throw Error в случае ошибки
     */
    HTTPClient();
    string get_server() { return server; } 
    string get_path() { return path; }
    void set_server(const string& s) { server = s; }
    void set_path(const string& p) { path = p; }
    /**
     * @brief Выполняет валидацию url и заполняет аттрибуты server и path,
     * в случаи если аттребуты server и path не пусты метод работает с относительными адресами
     * @param [in] url URL адрес файла который требуется загрузить
     * @throw Error в случае ошибки
     */
    void set_url(const string& url);
    /**
     * @brief Устанавливает аттрибут file_path
     */
    void set_file(const string& f_path);
    /**
     * @brief Выполняет разбор заголовков на  данный момент поддерживается только заголовок Location
     * @param [in] head_buf_str строка с данными полученная с сервера, часть этих данных HTTP-заголовки
     * @param [out] http_code http код ответа
     * @param [out] loc значение заголовка Location
     * @return размер заголовков в байтах
     */
    static int parse_headers(const string& head_buf_str, int &http_code, string &loc);
    /**
     * @brief Выполняет HTTP запрос и сохраняет результат в файл
     * @throw Error в случае ошибки
     */
    int request();
    ~HTTPClient();
};

/**
 * @brief Класс для обработки ошибок
 */
class Error : public exception
{
    string what_str; //!< Описание ошибки
public:
    /**
     * @brief Создаёт ошибку
     * @param [in] what_arg описание ошибки
     */
    Error(const string& what_arg) : what_str(what_arg) {}
    /**
     * @brief Возвращает описание ошибки
     * @return описание ошибки
     */
    const char* what() { return what_str.c_str(); }
    ~Error() throw() {}
};