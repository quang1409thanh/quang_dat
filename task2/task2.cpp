
#include <bits/stdc++.h>
using namespace std;
/**
 * \struct DateTime
 * \brief Một struct đại diện cho một giá trị ngày tháng và thời gian.
 *
 * Struct DateTime lưu trữ các thành phần của một ngày tháng và thời gian bao gồm
 * năm (year), tháng (month), ngày (day), giờ (hour), phút (minute) và giây (second).
 * Nó cung cấp phương thức print() để định dạng và hiển thị ngày và thời gian theo định dạng
 * "yyyy:mm:dd hh:mm:ss".
 */
struct DateTime
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    void print()
    {
        cout << setfill('0');
        cout << setw(4) << this->year << ":" << setw(2) << this->month << ":" << setw(2) << this->day << " "
             << setw(2) << this->hour << ":" << setw(2) << this->minute << ":" << setw(2) << this->second;
    }
};

/**
 * \brief So sánh hai đối tượng DateTime.
 *
 * Hàm compare() được sử dụng để so sánh hai đối tượng DateTime để xác định thứ tự của chúng.
 * Hàm này so sánh theo thứ tự từ nhỏ đến lớn, bắt đầu từ năm (year), tháng (month), ngày (day),
 * giờ (hour), phút (minute) và giây (second).
 *
 * \param time1 Đối tượng DateTime thứ nhất cần so sánh.
 * \param time2 Đối tượng DateTime thứ hai cần so sánh.
 * \return Trả về giá trị true nếu time1 nhỏ hơn time2, và false nếu ngược lại.
 * \sa DateTime
 */
bool compare_time(DateTime time1, DateTime time2)
{
    if (time1.year < time2.year)
    {
        return true;
    }
    else if (time1.year > time2.year)
    {
        return false;
    }

    if (time1.month < time2.month)
    {
        return true;
    }
    else if (time1.month > time2.month)
    {
        return false;
    }

    if (time1.day < time2.day)
    {
        return true;
    }
    else if (time1.day > time2.day)
    {
        return false;
    }

    if (time1.hour < time2.hour)
    {
        return true;
    }
    else if (time1.hour > time2.hour)
    {
        return false;
    }

    if (time1.minute < time2.minute)
    {
        return true;
    }
    else if (time1.minute > time2.minute)
    {
        return false;
    }

    if (time1.second < time2.second)
    {
        return true;
    }

    else
    {
        return false;
    }
}

/**
 * \brief Kiểm tra xem một năm có phải là năm nhuận hay không.
 *
 * Hàm isLeapYear() được sử dụng để kiểm tra xem một năm cụ thể có phải là năm nhuận hay không.
 * Hàm này kiểm tra các điều kiện sau để xác định một năm có phải là năm nhuận:
 * - Năm chia hết cho 4 nhưng không chia hết cho 100, hoặc
 * - Năm chia hết cho 400.
 *
 * \param year Năm cần kiểm tra.
 * \return Trả về giá trị true nếu year là năm nhuận, và false nếu ngược lại.
 */
bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

/**
 * \brief Lấy số ngày trong một tháng của một năm cụ thể.
 *
 * Hàm getDaysInMonth() được sử dụng để lấy số ngày trong một tháng của một năm cụ thể.
 * Hàm này xác định số ngày dựa trên các quy tắc sau:
 * - Tháng 2: Kiểm tra xem năm có phải là năm nhuận bằng cách sử dụng hàm isLeapYear().
 *   - Nếu năm là năm nhuận, tháng 2 có 29 ngày.
 *   - Nếu năm không phải là năm nhuận, tháng 2 có 28 ngày.
 * - Tháng 4, 6, 9 và 11: Các tháng này có 30 ngày.
 * - Các tháng còn lại (1, 3, 5, 7, 8, 10 và 12): Các tháng này có 31 ngày.
 *
 * \param month Tháng cần lấy số ngày.
 * \param year Năm liên quan đến tháng.
 * \return Trả về số ngày trong tháng của năm cụ thể.
 */
int getDaysInMonth(int month, int year)
{
    if (month == 2)
    {
        if (isLeapYear(year))
        {
            return 29;
        }
        else
        {
            return 28;
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return 30;
    }
    else
    {
        return 31;
    }
}

/**
 * \brief Thêm số giây vào một đối tượng DateTime.
 *
 * Hàm addSeconds() được sử dụng để thêm một số giây vào một đối tượng DateTime cụ thể.
 * Hàm này thực hiện việc thêm số giây vào đối tượng DateTime và xử lý tràn các thành phần
 * thời gian như giây, phút, giờ, ngày, tháng và năm.
 *
 * \param dateTime Đối tượng DateTime ban đầu.
 * \param seconds Số giây cần thêm vào.
 * \return Trả về một đối tượng DateTime mới sau khi thêm số giây.
 * \sa DateTime
 * \sa getDaysInMonth
 */
DateTime addSeconds(const DateTime &dateTime, int seconds)
{
    DateTime result = dateTime;
    result.second += seconds;

    // Xử lý tràn giây
    if (result.second >= 60)
    {
        int extraMinutes = result.second / 60;
        result.second %= 60;
        result.minute += extraMinutes;

        // Xử lý tràn phút
        if (result.minute >= 60)
        {
            int extraHours = result.minute / 60;
            result.minute %= 60;
            result.hour += extraHours;

            // Xử lý tràn giờ
            if (result.hour >= 24)
            {
                int extraDays = result.hour / 24;
                result.hour %= 24;
                result.day += extraDays;

                // Xử lý tràn ngày
                while (true)
                {
                    int daysInMonth = getDaysInMonth(result.month, result.year);

                    if (result.day > daysInMonth)
                    {
                        result.day -= daysInMonth;
                        result.month++;

                        if (result.month > 12)
                        {
                            result.month = 1;
                            result.year++;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }

    return result;
}

/**
 * \brief Lấy đối tượng DateTime hiện tại.
 *
 * Hàm getCurrentDateTime() được sử dụng để lấy đối tượng DateTime hiện tại,
 * đại diện cho thời điểm thực tế khi hàm được gọi. Hàm này sử dụng thư viện
 * cấu trúc tm và hàm localtime() để lấy thông tin chi tiết về thời gian hiện tại.
 * Đối tượng DateTime được tạo và trả về với các thành phần tương ứng với năm, tháng,
 * ngày, giờ, phút và giây từ thời gian hiện tại.
 *
 * \return Trả về đối tượng DateTime hiện tại.
 * \sa DateTime
 */
DateTime getCurrentDateTime()
{
    time_t now = time(nullptr);
    tm *timeinfo = localtime(&now);

    DateTime currentDateTime;
    currentDateTime.year = timeinfo->tm_year + 1900; // Năm tính từ 1900
    currentDateTime.month = timeinfo->tm_mon + 1;    // Tháng tính từ 0
    currentDateTime.day = timeinfo->tm_mday;
    currentDateTime.hour = timeinfo->tm_hour;
    currentDateTime.minute = timeinfo->tm_min;
    currentDateTime.second = timeinfo->tm_sec;

    return currentDateTime;
}

/**
 * \brief Trích xuất giá trị số cuối cùng từ một chuỗi.
 *
 * Hàm extract_value() được sử dụng để trích xuất giá trị số cuối cùng từ một chuỗi
 * được phân tách bằng dấu phẩy. Hàm này sử dụng stringstream để chia chuỗi thành các
 * phần tử riêng biệt và chuyển đổi chúng thành giá trị số. Giá trị số cuối cùng được
 * trả về.
 *
 * \param line Chuỗi cần trích xuất giá trị.
 * \return Trả về giá trị số cuối cùng trong chuỗi.
 */
double extract_value(string line)
{
    stringstream ss(line);
    string token;
    vector<double> values;

    while (getline(ss, token, ','))
    {
        double x = stof(token);
        values.push_back(x);
    }
    return values.back();
}

/**
 * \brief Trích xuất ID từ một chuỗi.
 *
 * Hàm extract_id() được sử dụng để trích xuất ID từ một chuỗi, với giả định
 * rằng ID được phân tách bằng dấu phẩy. Hàm này tìm vị trí của dấu phẩy đầu tiên
 * trong chuỗi và sử dụng substr() và stoi() để trích xuất và chuyển đổi ID thành
 * kiểu int.
 *
 * \param line Chuỗi cần trích xuất ID.
 * \return Trả về giá trị ID được trích xuất.
 */
int extract_id(string line)
{
    size_t pos = line.find(',');
    int id = std::stoi(line.substr(0, pos));
    return id;
}

/**
 * \brief Trích xuất thông tin thời gian từ một dòng dữ liệu.
 *
 * Hàm extract_time() được sử dụng để trích xuất thông tin thời gian từ một dòng dữ liệu đã cho.
 * Hàm này sử dụng stringstream để tách lấy giá trị id và thời gian từ dòng dữ liệu và trả về giá
 * trị thời gian đã trích xuất.
 *
 * \param line Dòng dữ liệu cần trích xuất thời gian.
 * \return Trả về thông tin thời gian đã trích xuất.
 */
string extract_time(string line)
{
    std::istringstream ss(line);
    int id;
    std::string time;
    ss >> id;
    ss.ignore();
    std::getline(ss, time, ',');
    return time;
}

/**
 * \brief Trích xuất thông tin ô nhiễm từ một chuỗi.
 *
 * Hàm extract_pollution() được sử dụng để trích xuất thông tin về ô nhiễm từ một chuỗi,
 * với giả định rằng thông tin về ô nhiễm nằm sau dấu phẩy cuối cùng trong chuỗi. Hàm này
 * sử dụng rfind() để tìm vị trí của dấu phẩy cuối cùng trong chuỗi và sử dụng substr() để
 * trích xuất thông tin về ô nhiễm từ vị trí đó trở đi.
 *
 * \param line Chuỗi cần trích xuất thông tin ô nhiễm.
 * \return Trả về thông tin về ô nhiễm được trích xuất từ chuỗi.
 */
string extract_pollution(string line)
{
    size_t pos = line.rfind(',');
    if (pos != string::npos)
    {
        return line.substr(pos + 1);
    }
    return "";
}

/**
 * \brief Chuyển đổi chuỗi thành đối tượng DateTime.
 *
 * Hàm stringToDate() được sử dụng để chuyển đổi một chuỗi đại diện cho ngày và thời gian
 * thành một đối tượng DateTime. Hàm này chuyển đổi các thành phần của ngày và thời gian từ
 * chuỗi thành các thành phần tương ứng trong đối tượng DateTime.
 *
 * \param dateTimeStr Chuỗi đại diện cho ngày và thời gian.
 * \return Trả về đối tượng DateTime được chuyển đổi từ chuỗi.
 * \sa DateTime
 */
DateTime stringToDate(const std::string &dateTimeStr)
{
    DateTime dateTime;

    std::stringstream ss(dateTimeStr);

    char delimiter;

    ss >> dateTime.year >> delimiter >> dateTime.month >> delimiter >> dateTime.day >> dateTime.hour >> delimiter >> dateTime.minute >> delimiter >> dateTime.second;

    return dateTime;
}

/**
 * \brief Chuyển đổi đối tượng DateTime thành chuỗi.
 *
 * Hàm dateToString() được sử dụng để chuyển đổi một đối tượng DateTime thành một chuỗi
 * đại diện cho ngày và thời gian. Hàm này chuyển đổi các thành phần của đối tượng DateTime
 * thành chuỗi có định dạng "yyyy:mm:dd hh:mm:ss".
 *
 * \param dateTime Đối tượng DateTime cần chuyển đổi thành chuỗi.
 * \return Trả về chuỗi đại diện cho ngày và thời gian từ đối tượng DateTime.
 * \sa DateTime
 */
std::string dateToString(const DateTime &dateTime)
{
    std::stringstream ss;
    ss << dateTime.year << ":" << dateTime.month << ":" << dateTime.day << " " << dateTime.hour << ":" << dateTime.minute << ":" << dateTime.second;
    return ss.str();
}

/**
 * \brief Lấy dòng cuối cùng từ một tệp tin.
 *
 * Hàm getLastLine() được sử dụng để lấy dòng cuối cùng từ một tệp tin đã cho.
 * Hàm này mở tệp tin, đọc từng dòng và lưu trữ dòng cuối cùng trong biến lastLine.
 * Cuối cùng, tệp tin được đóng và dòng cuối cùng được trả về.
 *
 * \param filename Tên tệp tin cần lấy dòng cuối cùng.
 * \return Trả về dòng cuối cùng trong tệp tin.
 */
std::string getLastLine(const std::string &filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cerr << "Failed to open the file." << std::endl;
        return "";
    }

    std::string line;
    std::string lastLine;

    while (std::getline(file, line))
    {
        lastLine = line;
    }

    file.close();

    return lastLine;
}

/**
 * \brief Lấy đối tượng DateTime chỉ chứa thông tin giờ.
 *
 * Hàm getHour() được sử dụng để lấy một đối tượng DateTime chỉ chứa thông tin về giờ
 * từ một đối tượng DateTime đã cho. Hàm này tạo một đối tượng DateTime mới với các thành
 * phần phút và giây được đặt thành 0, giữ nguyên các thành phần năm, tháng, ngày và giờ.
 *
 * \param datetime Đối tượng DateTime ban đầu.
 * \return Trả về đối tượng DateTime chỉ chứa thông tin giờ.
 * \sa DateTime
 */
DateTime getHour(const DateTime &datetime)
{
    DateTime result = datetime;
    result.minute = 0;
    result.second = 0;
    return result;
}

/**
 * \brief Làm tròn một số đến một chữ số thập phân.
 *
 * Hàm roundToOneDecimal() được sử dụng để làm tròn một số đến một chữ số thập phân.
 * Hàm này nhân số cho 10, làm tròn số đã nhân, và sau đó chia cho 10 để trả về một số
 * đã làm tròn đến một chữ số thập phân.
 *
 * \param num Số cần làm tròn.
 * \return Trả về số đã làm tròn đến một chữ số thập phân.
 */
double roundToOneDecimal(double num)
{
    double rounded_number = round(num * 10.) / 10.;
    return rounded_number;
}

/**
 * \brief tinh aqi và pollution theo yêu cầu của đề bài(task2_2)
 *
 *
 * \param c giá trị đo được
 * \return Trả về chuỗi gồm giá trị aqi và pollution
 */
string to_aqi_pollution(double c)
{
    string s;

    if (c >= 0 && c < 12)
    {
        // 0<= x < 12;
        double x = (c - 0) * (50 - 0) / (12 - 0);
        int aqi = std::round(x);
        s = "," + std::to_string(aqi) + ",Good";
    }
    else if (c >= 12 && c < 35.5)
    {
        // std::cout << "Trường hợp 12 ≤ c < 35.5" << std::endl;
        double x = 50 + (c - 12) * (100 - 50) / (35.5 - 12);
        int aqi = std::round(x);
        s = "," + std::to_string(aqi) + ",Moderate";
    }
    else if (c >= 35.5 && c < 55.5)
    {
        // std::cout << "Trường hợp 35.5 ≤ c < 55.5" << std::endl;
        double x = 100 + (c - 35.5) * (150 - 100) / (55.5 - 35.5);
        int aqi = std::round(x);
        s = "," + std::to_string(aqi) + ",Slightly unhealthy";
    }
    else if (c >= 55.5 && c < 150.5)
    {
        // std::cout << "Trường hợp 55.5 ≤ c < 150.5" << std::endl;
        double x = 150 + (c - 55.5) * (200 - 150) / (150.5 - 55.5);
        int aqi = std::round(x);
        s = "," + std::to_string(aqi) + ",Unhealthy";
    }
    else if (c >= 150.5 && c < 250.5)
    {
        // std::cout << "Trường hợp 150.5 ≤ c < 250.5" << std::endl;
        double x = 200 + (c - 150.5) * (300 - 200) / (250.5 - 150.5);
        int aqi = std::round(x);
        s = "," + std::to_string(aqi) + ",Very unhealthy";
    }
    else if (c >= 250.5 && c < 350.5)
    {
        // std::cout << "Trường hợp 250.5 ≤ c < 350.5" << std::endl;
        double x = 300 + (c - 250.5) * (400 - 300) / (350.5 - 250.5);
        int aqi = std::round(x);
        s = "," + std::to_string(aqi) + ",Hazardous";
    }
    else
    {
        // std::cout << "Trường hợp 350.5 ≤ c ≤ 550.5" << std::endl;
        double x = 400 + (c - 350.5) / (550.5 - 350.5) * (500 - 400);
        int aqi = std::round(x);
        s = "," + std::to_string(aqi) + ",Extremely hazardous";
    }

    return s;
}

/**
 * \brief Lọc và ghi các dòng dữ liệu không hợp lệ vào file outlier, và ghi các dòng hợp lệ vào file temp.
 *
 * Hàm filter_() được sử dụng để đọc dữ liệu từ một file đã cho, lọc các dòng dữ liệu không hợp lệ
 * và ghi chúng vào file outlier. Các dòng dữ liệu hợp lệ được ghi vào file temp. Hàm này sử dụng
 * extract_value() để trích xuất giá trị từ mỗi dòng và kiểm tra xem giá trị có nằm ngoài khoảng
 * từ 5 đến 550.5 hay không.
 *
 * \param filepath Đường dẫn của file đầu vào.
 * \param outlier Đường dẫn của file outlier để ghi các dòng dữ liệu không hợp lệ.
 * \param temp Đường dẫn của file temp để ghi các dòng dữ liệu hợp lệ.
 * \note Hàm này không trả về giá trị.
 */
void filter_(string filepath, string outlier, string temp)
{
    ifstream i_file(filepath);
    ofstream task2_1_file(outlier);
    ofstream task2_2_file(temp);
    if (!i_file.is_open())
    {
        cout << "Không thể mở file!" << endl;
    }
    // đọc dòng đầu tiên
    string line_0;
    getline(i_file, line_0);
    task2_2_file << line_0 << endl;
    int count = 0;
    string rs = "";
    // đọc các dòng tiếp
    string line;
    while (getline(i_file, line))
    {
        bool check = false;

        double x = extract_value(line);

        if (x < 5 || x > 550.5)
        {
            check = true;
        }
        if (check)
        {
            rs += line + "\n";
            count++;
        }
        if (!check)
        {
            task2_2_file << line << endl;
        }
    }

    task2_1_file << "number of outliers: " << count << endl;
    task2_1_file << line_0 + "\n" + rs;
    task2_1_file << "end" << endl;
    i_file.close();
    task2_1_file.close();
    task2_2_file.close();
}

/**
 * \brief Tính trung bình giá trị và ghi kết quả vào file output.
 *
 * Hàm sol_average() được sử dụng để đọc dữ liệu từ file đầu vào, tính trung bình giá trị theo từng
 * giờ và ghi kết quả vào file output. Hàm này sử dụng các hàm extract_time(), getHour(), compare_time(),
 * addSeconds(), roundToOneDecimal() và to_aqi_pollution() để thực hiện các thao tác và tính toán cần thiết.
 *
 * \param filepath Đường dẫn của file đầu vào.
 * \param file_filter Đường dẫn của file để lọc dữ liệu hợp lệ.
 * \param output Đường dẫn của file output để ghi kết quả tính trung bình
 * \return Trả về số lượng giờ được xử lý.
 * \note Hàm này có thể ném ngoại lệ std::runtime_error nếu không thể mở tệp tin.
 */
int sol_average(string filepath, string file_filter, string ouput)
{
    ifstream dust_sensor(filepath);
    ofstream filter_average(ouput);
    ifstream filter2_2_(file_filter);
    // lấy thời gian đầu tiên trong file dust_sim sau đó tính trung bình của các id từng giờ.
    if (dust_sensor.is_open())
    {
        string line_0;
        getline(dust_sensor, line_0);
    }
    else
    {
        throw std::runtime_error("Lỗi: Không thể mở tệp tin.");
    }
    filter_average << "id,time,value,aqi,pollution" << endl;
    string line1;
    getline(dust_sensor, line1);
    DateTime current_time = stringToDate(extract_time(line1));
    current_time = (getHour(current_time));
    DateTime end_time = stringToDate(extract_time(getLastLine(filepath)));
    end_time = addSeconds(getHour(end_time), 3600 + 1);
    string line0_;
    getline(filter2_2_, line0_);
    int i = 0;
    string old_line;
    while (compare_time(current_time, end_time)) // mỗi lần lặp là tăng thời gian lên 1h 18:00 -> 19:00 -> 1:00
    {
        // trong mỗi giờ mình sẽ xử lý.
        bool check_increment = true;
        std::map<int, std::pair<int, double>> id_value; // id_count_value
        string line;
        DateTime start_time = (getHour(current_time));
        while (getline(filter2_2_, line)) // vòng lặp để đọc file
        {
            if (compare_time(stringToDate(extract_time(line)), current_time)) // kiểm tra thỏa mãn điều kiện
            {
                /* code */
                if (id_value.count(extract_id(line)) == 0) // thêm vào map
                {
                    if (old_line.size() != 0)
                    {
                        if (extract_id(old_line) == extract_id(line))
                        {
                            id_value[extract_id(line)] = make_pair(2, extract_value(line) + extract_value(old_line));
                            old_line = "";
                        }
                        else
                        {
                            id_value[extract_id(line)] = make_pair(1, extract_value(line));

                            id_value[extract_id(old_line)] = make_pair(1, extract_value(old_line));
                            old_line = "";
                        }
                    }
                    else
                    {
                        id_value[extract_id(line)] = make_pair(1, extract_value(line));
                    }
                }
                else // cập nhật lại count với value.
                {
                    if (old_line.size() != 0)
                    {
                        if (extract_value(old_line) == extract_value(line))
                        {
                            id_value[extract_id(line)].first += 2;
                            id_value[extract_id(line)].second += (extract_value(line) + extract_value(old_line));
                            old_line = "";
                        }
                        else
                        {
                            id_value[extract_id(line)].first += 1;
                            id_value[extract_id(line)].second += extract_value(line);

                            id_value[extract_id(old_line)].first += 1;
                            id_value[extract_id(old_line)].second += extract_value(line);
                            old_line = "";
                        }
                    }
                    else
                    {
                        // log_file << "tang count va value" << endl;
                        id_value[extract_id(line)].first += 1;
                        id_value[extract_id(line)].second += extract_value(line);
                    }
                }
            }
            else
            {
                old_line = line;
                current_time = addSeconds(current_time, 3600);
                check_increment = false;
                break;
            }
        }
        for (const auto &entry : id_value)
        {
            double average = entry.second.second / entry.second.first;
            filter_average << entry.first << "," << setfill('0')
                           << setw(4) << start_time.year << ":" << setw(2) << start_time.month << ":" << setw(2) << start_time.day << " "
                           << setw(2) << start_time.hour << ":" << setw(2) << start_time.minute << ":" << setw(2) << start_time.second
                           << "," << fixed << setprecision(1) << roundToOneDecimal(average) << to_aqi_pollution(roundToOneDecimal(average)) << endl;
        }

        if (check_increment)
        {
            current_time = addSeconds(current_time, 3600);
        }
        i++;
    }
    dust_sensor.close();
    filter_average.close();
    filter2_2_.close();
    return i - 2;
}

/**
 * \struct data2_3
 * \brief Một struct đại diện cho dữ liệu thống kê.
 *
 * Struct data2_3 lưu trữ thông tin về dữ liệu thống kê bao gồm giá trị tối thiểu (min),
 * giá trị tối đa (max), dòng tương ứng với giá trị tối đa (line_max), dòng tương ứng
 * với giá trị tối thiểu (line_min), số lượng (cnt), và giá trị (value). Struct cung cấp
 * một constructor mặc định và một constructor với các tham số để khởi tạo các thành phần.
 */
struct data2_3
{
    double min;
    double max;
    string line_max;
    string line_min;
    int cnt;
    double value;
    data2_3(){};
    data2_3(double min_, double max_, int cnt_, double value_, string line_max_, string line_min_)
    {
        min = min_;
        max = max_;
        cnt = cnt_;
        value = value_;
        line_max = line_max_;
        line_min = line_min_;
    }
};

/**
 * \brief Thực hiện tác vụ task2_3 bằng cách tính toán và ghi kết quả vào file output.
 *
 * Hàm task2_3() được sử dụng để đọc dữ liệu từ file đầu vào, tính toán giá trị tối thiểu,
 * tối đa và trung bình cho từng id và ghi kết quả vào file output. Hàm này sử dụng các hàm
 * extract_id(), extract_value(), extract_time(), roundToOneDecimal() và các thành phần của
 * struct data2_3 để thực hiện các thao tác và tính toán cần thiết.
 *
 * \param filepath Đường dẫn của file đầu vào.
 * \param output Đường dẫn của file output để ghi kết quả.
 * \param count_hour Số giờ đang xử lý.
 * \note Hàm này không trả về giá trị.
 */
void task2_3(string filepath, string output, int count_hour)
{
    ifstream input(filepath);
    ofstream output_file(output);
    output_file << "id,parameters,time,value" << endl;
    string line0;
    getline(input, line0);
    string line;
    map<int, data2_3> id_data;
    string old_line;
    while (getline(input, line))
    {
        /* code */
        if (id_data.count(extract_id(line)) == 0)
        {
            id_data[extract_id(line)] = data2_3(1000, 0, 1, extract_value(line), extract_time(line), extract_time(line));
        }
        else
        {
            // cap nhat min max, ..
            id_data[extract_id(line)].cnt += 1;
            id_data[extract_id(line)].value += extract_value(line);
            if (extract_value(line) > id_data[extract_id(line)].max)
            {
                id_data[extract_id(line)].max = extract_value(line);
                id_data[extract_id(line)].line_max = extract_time(line);
            }
            else if (extract_value(line) < id_data[extract_id(line)].min)
            {
                id_data[extract_id(line)].min = extract_value(line);
                id_data[extract_id(line)].line_min = extract_time(line);
            }
        }
        old_line = line;
    }
    for (const auto &entry : id_data)
    {
        output_file << entry.first << ",max," << entry.second.line_max << "," << entry.second.max << endl
                    << entry.first << ",min," << entry.second.line_min << "," << fixed << setprecision(1) << entry.second.min << endl
                    << entry.first << ",mean," << setfill('0')
                    << setw(2) << count_hour << ":00:00"
                    << "," << roundToOneDecimal(entry.second.value / entry.second.cnt) << endl;
    }
    output_file << "end" << endl;
}

/**
 * \brief Thực hiện tác vụ task2_4 bằng cách tính toán số lượng ô nhiễm theo id và loại ô nhiễm và ghi kết quả vào file output.
 *
 * Hàm task2_4() được sử dụng để đọc dữ liệu từ file đầu vào, tính toán số lượng ô nhiễm theo id và loại ô nhiễm,
 * và ghi kết quả vào file output. Hàm này sử dụng các hàm extract_id(), extract_pollution() và các thành phần của
 * map count_pollution để thực hiện các thao tác và tính toán cần thiết.
 *
 * \param filepath Đường dẫn của file đầu vào là kết quả của việc thực hiện task2_2
 * \param output Đường dẫn của file output để ghi kết quả.
 * \note Hàm này không trả về giá trị.
 */
void task2_4(string filepath, string output)
{
    ifstream input(filepath);
    ofstream o_file(output);
    o_file << "id,pollution,duration" << endl;
    string line0;
    getline(input, line0);
    string line;
    map<pair<int, string>, int> count_pollution;
    while (getline(input, line))
    {
        /* code */
        count_pollution[{extract_id(line), extract_pollution(line)}]++;
    }

    std::vector<std::string> pollutionValues = {
        "Good",
        "Moderate",
        "Slightly unhealthy",
        "Unhealthy",
        "Very unhealthy",
        "Hazardous",
        "Extremely hazardous"};
    std::set<int> uniqueIds;
    for (const auto &entry : count_pollution)
    {
        uniqueIds.insert(entry.first.first);
    }
    for (int id : uniqueIds)
    {

        // Duyệt qua danh sách pollutionValues và in ra giá trị tương ứng
        for (const std::string &pollution : pollutionValues)
        {
            std::pair<int, std::string> key = {id, pollution};
            // Kiểm tra xem giá trị pollution có tồn tại trong map không
            if (count_pollution.find(key) != count_pollution.end())
            {
                int count = count_pollution[key];
                o_file << key.first << "," << key.second << "," << count << std::endl;
            }
            else
            {
                // In ra giá trị mặc định
                o_file << key.first << "," << key.second << ",0" << std::endl;
            }
        }
    }
    o_file << "endl";
}

int main()
{

    for (int i = 1; i < 6; i++)
    {
        string input = "dust_sensor_test" + to_string(i) + ".csv";
        string input2 = "dust_outlier_expect_test" + to_string(i) + ".csv";
        string input3 = "dust_aqi_expect_test" + to_string(i) + ".csv";
        string input4 = "dust_summary_expect_test" + to_string(i) + ".csv";
        string temp = "temp2_2_test" + to_string(i) + ".csv";
        string task2_4_file = "dust_statistics_expect_test" + to_string(i) + ".csv";
        filter_(input, input2, temp); // đúng          // lọc ra có 2.1 và lọc ra file ở 2.2
        int count_hour = sol_average(input, temp, input3); // tính trung bình ở 2.2 đang có sai số. ?   // TODO: đang bị làm tròn sai 1 đơn vị
        task2_3(temp, input4, count_hour);                 // đúng 2.3
        task2_4(input3, task2_4_file); // đúng 2.4
    }
    return 0;
}