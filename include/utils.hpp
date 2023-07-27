#ifndef UTILS_HPP
#define UTILS_HPP

#include <algorithm>
#include <string>
#include <ranges>
#include <format>
#include <stdexcept>
#include <fstream>

#include "db.hpp"

auto validateTag(char c) -> bool;
auto validateStr(std::string_view s) -> bool;
auto validateSequence(std::string_view s) -> bool;

auto parseSchema(std::string_view line) -> std::vector<std::string>;
auto parsePerson(std::string_view line) -> std::pair<std::string, std::vector<size_t>>;
auto readDb(std::ifstream &fin) -> Db;

auto findMaxConsecutiveRepeats(std::string_view sequence, std::string_view str) -> size_t;

#endif
