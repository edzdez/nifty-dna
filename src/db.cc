#include "db.hpp"

extern auto findMaxConsecutiveRepeats(std::string_view sequence, std::string_view str) -> size_t;

Db::Db(const std::vector<std::string> &schema)
    : m_strs(schema)
{
}

auto Db::insert(std::string_view name, const std::vector<size_t> &data) -> void
{
    m_data.emplace(name, data);
}

auto Db::numStrs() const -> size_t
{
    return m_strs.size();
}

auto Db::findMatch(std::string_view sequence) const -> std::optional<std::string>
{
    for (const auto &[name, data] : m_data)
    {
        bool matches = true;
        size_t strIdx = 0;
        for (const auto &str : m_strs)
        {
            auto repeats = findMaxConsecutiveRepeats(sequence, str);
            if (repeats != data[strIdx])
            {
                matches = false;
                break;
            }

            ++strIdx;
        }

        if (matches)
            return name;
    }

    return {};
}
