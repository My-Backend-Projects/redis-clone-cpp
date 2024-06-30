#include <iostream>
#include <unordered_map>
#include <map>

class Redis {
  public:
    std::unordered_map<std::string, std::string> store;

    void set(const std::string& key, const std::string& value) {
      store[key] = value;
      std::cout << store[key] << std::endl;
    }
  
};


int main() {

  Redis r;
  r.set("key", "value");
  return 0;
}
