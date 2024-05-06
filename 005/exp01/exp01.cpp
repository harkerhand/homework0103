#include <iostream>
#include <fstream>
#include <vector>
#include <random> // C++11 随机库
#include <chrono> // 用于生成随机种子
#include <ctime>  // 用于转换时间戳
#include <algorithm>
#include <iomanip> // 用于格式化输出

// 生成随机 IPv4 地址
std::string generate_random_ip(std::mt19937 &gen)
{
    std::uniform_int_distribution<> dis(0, 255); // 0-255 随机整数分布
    return std::to_string(dis(gen)) + "." +
           std::to_string(dis(gen)) + "." +
           std::to_string(dis(gen)) + "." +
           std::to_string(dis(gen));
}

// 生成随机时间戳
std::string generate_random_timestamp(std::mt19937 &gen)
{
    // 将 1 年的秒数和 5 年的秒数作为范围
    int seconds_per_year = 365 * 24 * 60 * 60;
    std::uniform_int_distribution<> time_dis(1 * seconds_per_year, 5 * seconds_per_year);

    std::time_t now = std::time(nullptr);
    std::time_t random_time = now - time_dis(gen); // 随机生成过去1到5年的时间戳

    std::tm *tm_ptr = std::gmtime(&random_time);
    std::ostringstream oss;
    oss << std::put_time(tm_ptr, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

// 记录结构体
struct Record
{
    std::string ip_address;
    std::string timestamp;
};

// 比较函数用于排序
bool compare_records(const Record &a, const Record &b)
{
    return a.timestamp < b.timestamp;
}

int main()
{
    // 使用高精度时钟的计时器作为随机种子
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 gen(seed); // 使用 Mersenne Twister 生成器

    std::vector<Record> records;

    // 生成 100 条记录
    for (int i = 0; i < 100; ++i)
    {
        Record record;
        record.ip_address = generate_random_ip(gen);
        record.timestamp = generate_random_timestamp(gen);
        records.push_back(record);
    }

    // 按时间戳排序
    std::sort(records.begin(), records.end(), compare_records);

    // 写入文件
    std::ofstream file("record.txt");
    if (file.is_open())
    {
        for (const auto &record : records)
        {
            file << record.ip_address << " " << record.timestamp << "\n";
        }
        file.close();
    }
    else
    {
        std::cerr << "无法打开文件。\n";
    }

    return 0;
}
