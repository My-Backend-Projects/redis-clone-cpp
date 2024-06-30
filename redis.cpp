#include <iostream>
#include <unordered_map>
#include <string>

class Redis {
public:
    std::unordered_map<std::string, std::string> store;

    std::string set(const std::string& key, const std::string& value) {
        return store[key] = value;
    }

    void get(const std::string& key) {
        auto it = store.find(key);
        if (it != store.end()) {
            std::cout << it->second << std::endl;
        } else {
            std::cout << "Key '" << key << "' not found." << std::endl;
        }
    }

    int delete_item(const std::string& key) {
        auto it = store.find(key);
        if (it != store.end()) {
            store.erase(it);
            return 1; // Indicate success
        } else {
            return 0; // Indicate failure (key not found)
        }
    }
};

int main() {
    Redis r;
    r.set("key", "value");
    
    std::cout << "After setting key 'key' to 'value':" << std::endl;
    r.get("key");

    int delete_result = r.delete_item("key");
    if (delete_result == 1) {
        std::cout << "Key 'key' deleted successfully." << std::endl;
    } else {
        std::cout << "Key 'key' not found. Nothing deleted." << std::endl;
    }

    std::cout << "After deleting key 'key':" << std::endl;
    r.get("key");

    return 0;
}

