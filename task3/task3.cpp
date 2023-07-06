#include <bits/stdc++.h>
using namespace std;
std::string get_time_hexa(std::string input)
{
    std::tm t = {};
    std::istringstream ss(input);
    ss >> std::get_time(&t, "%Y:%m:%d %H:%M:%S");
    std::time_t timestamp = std::mktime(&t);
    std::stringstream hex_timestamp;
    bool first = true;
    for (int i = sizeof(timestamp) - 1; i >= 0; --i)
    {
        int byte = (timestamp >> (i * 8)) & 0xff;
        if (byte != 0 || !first)
        {
            if (!first)
            {
                hex_timestamp << ' ';
            }
            hex_timestamp << std::hex << std::setw(2) << std::setfill('0') << byte;
            first = false;
        }
    }
    return hex_timestamp.str();
}

std::string get_double_value(double value)
{
    float floatValue = static_cast<float>(value);
    std::stringstream result;
    unsigned char *bytes = reinterpret_cast<unsigned char *>(&floatValue);
    for (int i = sizeof(floatValue) - 1; i >= 0; --i)
    {
        result << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(bytes[i]);
        if (i > 0)
        {
            result << ' ';
        }
    }
    return result.str();
}

std::string aqi_to_hex(int a)
{
    std::stringstream ss;
    ss << std::hex << std::setw(2) << std::setfill('0') << (a >> 8);
    ss << ' ';
    ss << std::hex << std::setw(2) << std::setfill('0') << (a & 0xFF);
    return ss.str();
}
std::string id_to_hex(int a)
{
    std::stringstream ss;
    ss << std::hex << std::setw(2) << std::setfill('0') << a;
    return ss.str();
}

std::string up_case(const std::string &input)
{
    std::string result = input;
    for (char &c : result)
    {
        c = std::toupper(c);
    }
    return result;
}

std::string calc_cksum8(const std::string &N)
{
    // Chuyển giá trị đầu vào thành chữ hoa
    std::string strN = N;
    for (char &c : strN)
    {
        c = tolower(c);
    }

    std::string strHex = "0123456789abcdef";
    int result = 0;
    int fctr = 16;

    for (size_t i = 0; i < strN.length(); i++)
    {
        if (strN[i] == ' ')
            continue;

        int v = strHex.find(strN[i]);
        if (v < 0)
        {
            return "Non-hex character";
        }
        result += v * fctr;

        if (fctr == 16)
            fctr = 1;
        else
            fctr = 16;
    }

    if (result < 0)
    {
        return "Non-hex character";
    }
    else if (fctr == 1)
    {
        return "Odd number of characters";
    }
    else
    {
        // Tính toán bù 2
        result = (~(result & 0xFF) + 1) & 0xFF;

        // Chuyển đổi kết quả thành chuỗi
        std::string strResult;
        strResult.push_back(strHex[result / 16]);
        strResult.push_back(strHex[result % 16]);

        return strResult;
    }
}

void filter(string data_filename, string hex_filename)
{
    ifstream i_file(data_filename);
    ofstream task3_file(hex_filename);
    if (!i_file.is_open())
    {
        cout << "Khong the mo file!" << endl;
    }
    // đọc dòng đầu tiên
    string line_0;
    getline(i_file, line_0);
    // đọc các dòng tiếp
    string line;
    // chuyển sang file .dat
    while (getline(i_file, line))
    {
        std::istringstream ss(line);

        int id;
        std::string time;
        double pm25_concentration;
        int aqi;

        ss >> id;
        ss.ignore();
        std::getline(ss, time, ',');
        ss >> pm25_concentration;
        ss.ignore();
        ss >> aqi;

        string rs = "0f " + id_to_hex(id) + " " + get_time_hexa(time) + " " + get_double_value(pm25_concentration) + " " + aqi_to_hex(aqi);
        string check_sum = calc_cksum8(rs);
        rs = "7a " + rs + " " + check_sum + " 7f";
        // rs = up_case(rs);

        task3_file << rs << endl;
    }
}
int main()
{
    for (int i = 1; i <= 9; i++)
    {
        string input = "dust_aqi_test" + to_string(i) + ".csv";
        string output = "hex_expect_test" + to_string(i) + ".dat";
        filter(input, output);
    }
    return 0;
}