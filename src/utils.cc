#include "utils.hpp"

auto validateTag(char c) -> bool
{
    return c == 'A' || c == 'T' || c == 'G' || c == 'C';
}

auto validateStr(std::string_view s) -> bool
{
    return s.size() == 4 && validateSequence(s);
}

auto validateSequence(std::string_view s) -> bool
{
    return std::ranges::all_of(s, [](const auto c) { return validateTag(c); });
}

auto parseSchema(std::string_view line) -> std::vector<std::string>
{
    std::vector<std::string> schema;
    for (const auto strView : std::ranges::views::split(line, ',') | std::ranges::views::drop(1))
    {
        std::string str(strView.begin(), strView.end());
        if (!validateStr(str))
            throw std::runtime_error(std::format("invalid str \"{}\" found", str));

        schema.push_back(str);
    }

    if (schema.empty())
        throw std::runtime_error("empty schema");

    return schema;
}

auto parsePerson(std::string_view line) -> std::pair<std::string, std::vector<size_t>>
{
    auto view = std::ranges::views::split(line, ',');
    const std::string name(view.front().begin(), view.front().end());

    std::vector<size_t> counts;
    for (const auto countView : view | std::ranges::views::drop(1))
    {
        std::string countStr(countView.begin(), countView.end());
        int count = 0;
        try
        {
            size_t pos = 0;
            count = std::stoi(countStr, &pos);

            if (pos != countStr.size())
                throw std::runtime_error(std::format("invalid count \"{}\" found", countStr));
        }
        catch (...)
        {
            throw std::runtime_error(std::format("invalid count \"{}\" found", countStr));
        }

        counts.push_back(count);
    }

    return {name, counts};
}

auto readDb(std::ifstream &fin) -> Db
{
    std::string line;
    std::getline(fin, line);
    auto schema = parseSchema(line);

    Db db(schema);
    while (std::getline(fin, line))
    {
        const auto &[name, data] = parsePerson(line);
        if (data.size() != db.numStrs())
            throw std::runtime_error(std::format("malformed user \"{}\" -- invalid number of counts\n", name));
        db.insert(name, data);
    }

    return db;
}

auto findMaxConsecutiveRepeats(std::string_view sequence, std::string_view str) -> size_t
{
    size_t maxCount = 0;
    size_t count = 0;

    size_t seqIdx = 0;
    size_t newIdx = 0;
    while (true)
    {
        newIdx = sequence.find(str, seqIdx + 1);
        if (newIdx == std::string_view::npos)
        {
            if (newIdx == seqIdx + 4)
                ++count;

            maxCount = std::max(maxCount, count);
            break;
        }

        if (newIdx == seqIdx + 4)
            ++count;
        else
        {
            maxCount = std::max(maxCount, count);
            count = 1;
        }

        seqIdx = newIdx;
    }

    return maxCount;
}
