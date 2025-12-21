//
// Created by root on 24-4-17.
//
#include <iostream>
#include <memory>
#include <regex>
#include <string>
#include <unordered_map>

struct Request {
  // request method, POST, GET; path; HTTP version
  std::string method, path, http_version;
  // use smart pointer for reference counting of content
  std::shared_ptr<std::istream> content;
  // hash container, key-value dict
  std::unordered_map<std::string, std::string> header;
  // use regular expression for path match
  std::smatch path_match;
};

typedef std::map<std::string, std::unordered_map<std::string, std::function<void(std::ostream&, Request&)>>>
    resource_type;

template <typename socket_type>
class ServerBase {
 public:
  resource_type resource;
  resource_type default_resource;

  void start() {
    auto request = parse_request(std::cin);
    resource[request.path][request.method](std::cout, request);
  }

 protected:
  Request parse_request(std::istream& stream) const {
    Request req;
    std::string str;
    getline(stream, str);
    // parse http method
    if (!str.empty()) {
      std::regex method_regex("(GET|POST) ([/0-9_a-zA-Z]*) (HTTP/[0-9].[0-9])");
      std::smatch base_match;
      bool match = std::regex_match(str, base_match, method_regex);
      req.method = base_match[1].str();
      req.path = base_match[2].str();
      req.http_version = base_match[3].str();
      // read next line
      getline(stream, str);
    }
    // parse http header
    while (!str.empty()) {
      std::regex method_regex("([a-z_A-Z]*) ([0-9a-zA-Z]*)");
      std::smatch base_match;
      std::regex_match(str, base_match, method_regex);
      req.header[base_match[1]] = base_match[2];
      // read next line
      getline(stream, str);
    }
    // req.content(stream);
    return req;
  }
};

template <typename SERVER_TYPE>
void start_server(SERVER_TYPE& server) {
  // process GET request for /match/[digit+numbers],
  // e.g. GET request is /match/abc123, will return abc123
  server.resource["fill_your_reg_ex"]["GET"] = [](std::ostream& response, Request& request) {
    std::string number = request.path_match[1];
    response << "HTTP/1.1 200 OK\r\nContent-Length: " << number.length() << "\r\n\r\n" << number;
  };

  // peocess default GET request;
  // anonymous function will be called
  // if no other matches response files in folder web/
  // default: index.html
  server.default_resource["fill_your_reg_ex"]["GET"] = [](std::ostream& response, Request& request) {
    std::string filename = "www/";

    std::string path = request.path_match[1];

    // forbidden use `..` access content outside folder web/
    size_t last_pos = path.rfind(".");
    size_t current_pos = 0;
    size_t pos;
    while ((pos = path.find('.', current_pos)) != std::string::npos && pos != last_pos) {
      current_pos = pos;
      path.erase(pos, 1);
      last_pos--;
    }

    // (...)
  };
  server.start();
}

int main(int argc, char** argv) {
  ServerBase<void> sb;
  start_server(sb);
  return 0;
}