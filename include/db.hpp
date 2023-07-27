#ifndef DB_HPP
#define DB_HPP

#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>
#include <optional>
#include <iostream>

class Db
{
  public:
    Db() = default;
    explicit Db(const std::vector<std::string> &schema);

    auto insert(std::string_view name, const std::vector<size_t> &data) -> void;

    auto numStrs() const -> size_t;
    auto findMatch(std::string_view sequence) const -> std::optional<std::string>;

  private:
    std::vector<std::string> m_strs;
    std::unordered_map<std::string, std::vector<size_t>> m_data;
};

#endif
