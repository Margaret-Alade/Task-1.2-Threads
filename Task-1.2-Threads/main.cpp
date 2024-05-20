//
//  main.cpp
//  Task-1.2 Thread
//
//  Created by Маргарет  on 09.05.2024.
//

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <fstream>

using namespace std::chrono_literals;

void count_cores() {
    std::this_thread::sleep_for(100ms);
    std::cout << "Количество аппаратных ядер: " << std::thread::hardware_concurrency() << "\n";
}
void sum_vec(int &sum, std::vector<int> vec1, std::vector<int> vec2, std::vector<int>::iterator it_start, std::vector<int>::iterator it_end) {
    std::this_thread::sleep_for(200ms);
    std::cout << "Проверяем, актуальная ли ссылка на сумму в начале функции: sum = " << sum << "\n";
    auto start = std::chrono::steady_clock::now();
    for(auto i = it_start; i < it_end; i++) {
        sum += *i;
    }
    for(auto i = it_start; i < it_end; i++) {
        sum += *i;
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Проверяем актуальная ли ссылка на сумму в конце функции: sum = " << sum << "\n";
    std::cout << "сложение двух векторов из "  << vec1.size() << " элементов, распределенное на " << vec1.size() / (it_end - it_start) << " потоков работает за " << diff.count() << "s" << "\n";
}
void sum_vec_ofstream(int &sum, std::vector<int> vec1, std::vector<int> vec2, std::vector<int>::iterator it_start, std::vector<int>::iterator it_end) {
    std::this_thread::sleep_for(200ms);
    std::cout << "Проверяем, актуальная ли ссылка на сумму в начале функции: sum = " << sum << "\n";
    auto start = std::chrono::steady_clock::now();
    for(auto i = it_start; i < it_end; i++) {
        sum += *i;
    }
    for(auto i = it_start; i < it_end; i++) {
        sum += *i;
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::ofstream f;
    std::cout << "Проверяем, актуальная ли ссылка на сумму в конце функции: sum = " << sum << "\n";
    std::cout << "сложение двух векторов из "  << vec1.size() << " элементов, распределенное на " << vec1.size() / (it_end - it_start) << " потоков работает за " << diff.count() << "s" << "\n";
    f.open("/Users/margaret/Desktop/student homework/Task-1.2-Threads/Task-1.2-Threads/time_for_vec.txt", std::fstream::app);
    if (f.is_open()) {
            f << diff.count() << " ";
            if (vec1.size() == 1000000) {
                f << "\n";
            }
    }
    f.close();
}

void print_info() {
    std::this_thread::sleep_for(3000ms);
    std::ifstream f;
    f.open("/Users/margaret/Desktop/student homework/Task-1.2-Threads/Task-1.2-Threads/time_for_vec.txt");
    if (f.is_open()) {
        std::cout << "Таблица" << "\n";
        std::cout << "\t"  << "\t"  << "\t" << 1000 << "\t" << "\t" << "\t" << 10000 << "\t" << "\t" <<"\t" << 100000 << "\t" << "\t" << "\t" << "\t" << 1000000 << "\n";
        std::cout << "1 потоков" << "\t";
        std::string s;
        for (int i = 0; i < 4; i++) {
            f >> s;
            std::cout << s << "s" << "\t" << "\t";
        }
        std::cout << "\n";
        std::cout << "2 потоков" << "\t";
        for (int i = 0; i < 4; i++) {
            f >> s;
            std::cout << s << "s" << "\t" << "\t";
        }
        std::cout << "\n";
        std::cout << "4 потоков" << "\t";
        for (int i = 0; i < 4; i++) {
            f >> s;
            std::cout << s << "s" << "\t" << "\t";
        }
        std::cout << "\n";
        std::cout << "8 потоков" << "\t";
        for (int i = 0; i < 4; i++) {
            f >> s;
            std::cout << s << "s" << "\t" << "\t";
        }
        std::cout << "\n";
        std::cout << "16 потоков" << "\t";
        for (int i = 0; i < 4; i++) {
            f >> s;
            std::cout << s << "s" << "\t" << "\t";
        }
        std::cout << "\n";
        
    }
    f.close();
    
    
    
    
}


int main(int argc, const char * argv[]) {
    
    std::thread th1(count_cores);
    th1.join();
    
    std::vector<int>vec1(1000, 1);
    std::vector<int>vec2(1000, 1);
    std::vector<int>vec3(10000, 1);
    std::vector<int>vec4(10000, 1);
    std::vector<int>vec5(100000, 1);
    std::vector<int>vec6(100000, 1);
    std::vector<int>vec7(1000000, 1);
    std::vector<int>vec8(1000000, 1);

    int sum = 0;
    auto mid = vec7.begin() + (vec7.end() - vec7.begin()) / 2;
    auto quater = vec7.begin() + (vec7.end() - vec7.begin()) / 4;
    auto three_4th = mid + (vec7.end() - vec7.begin()) / 4;
    auto one_8th = vec7.begin() + (vec7.end() - vec7.begin()) / 8;
    auto three_8th = quater + (vec7.end() - vec7.begin()) / 8;
    auto five_8th = mid + (vec7.end() - vec7.begin()) / 8;
    auto sev_8th = three_4th + (vec7.end() - vec7.begin()) / 8;
    auto one_16th = vec7.begin() + (vec7.end() - vec7.begin()) / 16;
    auto three_16th = one_8th + (vec7.end() - vec7.begin()) / 16;
    auto five_16th = quater + (vec7.end() - vec7.begin()) / 16;
    auto seven_16th = three_8th + (vec7.end() - vec7.begin()) / 16;
    auto nine_16th = mid + (vec7.end() - vec7.begin()) / 16;
    auto elev_16th = five_8th + (vec7.end() - vec7.begin()) / 16;
    auto thirte_16th = three_4th + (vec7.end() - vec7.begin()) / 16;
    auto fifte_16th = sev_8th + (vec7.end() - vec7.begin()) / 16;
    std::thread th2(sum_vec, std::ref(sum), vec7, vec8, vec7.begin(), one_16th);
    th2.join();
    std::thread th3(sum_vec, std::ref(sum), vec7, vec8, one_16th, one_8th);
    th3.join();
    std::thread th4(sum_vec, std::ref(sum), vec7, vec8, one_8th, three_16th);
    th4.join();
    std::thread th5(sum_vec, std::ref(sum), vec7, vec8, three_16th, quater);
    th5.join();
    std::thread th6(sum_vec, std::ref(sum), vec7, vec8, quater, five_16th);
    th6.join();
    std::thread th7(sum_vec, std::ref(sum), vec7, vec8, five_16th, three_8th);
    th7.join();
    std::thread th8(sum_vec, std::ref(sum), vec7, vec8, three_8th, seven_16th);
    th8.join();
    std::thread th9(sum_vec, std::ref(sum), vec7, vec8, seven_16th, mid);
    th9.join();
    std::thread th10(sum_vec, std::ref(sum), vec7, vec8, mid, nine_16th);
    th10.join();
    std::thread th11(sum_vec, std::ref(sum), vec7, vec8, nine_16th, five_8th);
    th11.join();
    std::thread th12(sum_vec, std::ref(sum), vec7, vec8, five_8th, elev_16th);
    th12.join();
    std::thread th13(sum_vec, std::ref(sum), vec7, vec8, elev_16th, three_4th);
    th13.join();
    std::thread th14(sum_vec, std::ref(sum), vec7, vec8, three_4th, thirte_16th);
    th14.join();
    std::thread th15(sum_vec, std::ref(sum), vec7, vec8, thirte_16th, sev_8th);
    th15.join();
    std::thread th16(sum_vec, std::ref(sum), vec7, vec8, sev_8th, fifte_16th);
    th16.join();
    std::thread th17(sum_vec_ofstream, std::ref(sum), vec7, vec8, fifte_16th, vec7.end());
    th17.join();




//  печатаем итоговую таблицу
    std::thread th18(print_info);
    th18.join();
//    cложение векторов, распреленное на 1 поток
//    int sum = 0;
//    std::thread th2(sum_thread, vec1, vec2, vec1.begin(), vec1.end());
//    th2.join();
//    сложение векторов, распределенное на 2 потока
//    int sum = 0;
//    auto mid = vec1.begin() + (vec1.end() - vec1.begin()) / 2;
//    std::thread th2(sum_thread,sum vec1, vec2, vec1.begin(), mid_th2);
//    th2.join();
//    std::thread th3(sum_vec_ofstream, std::ref(sum), vec1, vec2, mid, vec1.end());
//    th3.join();
//    сложение векторов, распределенное на 4 потока
//    int sum = 0;
//    auto mid = vec1.begin() + (vec1.end() - vec1.begin()) / 2;
//    auto quater = vec1.begin() + (vec1.end() - vec1.begin()) / 4;
//    auto three_4th = mid + (vec1.end() - vec1.begin()) / 4;
//    std::thread th2(sum_vec, std::ref(sum), vec1, vec2, vec1.begin(), quater);
//    th2.join();
//    std::thread th3(sum_vec, std::ref(sum), vec1, vec2, quater, mid);
//    th3.join();
//    std::thread th4(sum_vec, std::ref(sum), vec1, vec2, mid, three_4th);
//    th4.join();
//    std::thread th5(sum_vec_ofstream, std::ref(sum), vec1, vec2, three_4th, vec1.end());
//    th5.join();
//    сложение векторов, распределенное на 8 потоков
//    int sum = 0;
//    auto mid = vec1.begin() + (vec1.end() - vec1.begin()) / 2;
//    auto quater = vec1.begin() + (vec1.end() - vec1.begin()) / 4;
//    auto three_4th = mid + (vec1.end() - vec1.begin()) / 4;
//    auto one_8th = vec1.begin() + (vec1.end() - vec1.begin()) / 8;
//    auto three_8th = quater + (vec1.end() - vec1.begin()) / 8;
//    auto five_8th = mid + (vec1.end() - vec1.begin()) / 8;
//    auto sev_8th = three_4th + (vec1.end() - vec1.begin()) / 8;
//    std::thread th2(sum_vec, std::ref(sum), vec1, vec2, vec1.begin(), one_8th);
//    th2.join();
//    std::thread th3(sum_vec, std::ref(sum), vec1, vec2, one_8th, quater);
//    th3.join();
//    std::thread th4(sum_vec, std::ref(sum), vec1, vec2, quater, three_8th);
//    th4.join();
//    std::thread th5(sum_vec, std::ref(sum), vec1, vec2, three_8th, mid);
//    th5.join();
//    std::thread th6(sum_vec, std::ref(sum), vec1, vec2, mid, five_8th);
//    th6.join();
//    std::thread th7(sum_vec, std::ref(sum), vec1, vec2, five_8th, three_4th);
//    th7.join();
//    std::thread th8(sum_vec, std::ref(sum), vec1, vec2, three_4th, sev_8th);
//    th8.join();
//    std::thread th9(sum_vec_ofstream, std::ref(sum), vec1, vec2, sev_8th, vec1.end());
//    th9.join();

//    сложение векторов, распределенное на 16 потоков
//    int sum = 0;
//    auto mid = vec1.begin() + (vec1.end() - vec1.begin()) / 2;
//    auto quater = vec1.begin() + (vec1.end() - vec1.begin()) / 4;
//    auto three_4th = mid + (vec1.end() - vec1.begin()) / 4;
//    auto one_8th = vec1.begin() + (vec1.end() - vec1.begin()) / 8;
//    auto three_8th = quater + (vec1.end() - vec1.begin()) / 8;
//    auto five_8th = mid + (vec1.end() - vec1.begin()) / 8;
//    auto sev_8th = three_4th + (vec1.end() - vec1.begin()) / 8;
//    auto one_16th = vec1.begin() + (vec1.end() - vec1.begin()) / 16;
//    auto three_16th = one_8th + (vec1.end() - vec1.begin()) / 16;
//    auto five_16th = quater + (vec1.end() - vec1.begin()) / 16;
//    auto seven_16th = three_8th + (vec1.end() - vec1.begin()) / 16;
//    auto nine_16th = mid + (vec1.end() - vec1.begin()) / 16;
//    auto elev_16th = five_8th + (vec1.end() - vec1.begin()) / 16;
//    auto thirte_16th = three_4th + (vec1.end() - vec1.begin()) / 16;
//    auto fifte_16th = sev_8th + (vec1.end() - vec1.begin()) / 16;
//    std::thread th2(sum_vec, std::ref(sum), vec1, vec2, vec1.begin(), one_16th);
//    th2.join();
//    std::thread th3(sum_vec, std::ref(sum), vec1, vec2, one_16th, one_8th);
//    th3.join();
//    std::thread th4(sum_vec, std::ref(sum), vec1, vec2, one_8th, three_16th);
//    th4.join();
//    std::thread th5(sum_vec, std::ref(sum), vec1, vec2, three_16th, quater);
//    th5.join();
//    std::thread th6(sum_vec, std::ref(sum), vec1, vec2, quater, five_16th);
//    th6.join();
//    std::thread th7(sum_vec, std::ref(sum), vec1, vec2, five_16th, three_8th);
//    th7.join();
//    std::thread th8(sum_vec, std::ref(sum), vec1, vec2, three_8th, seven_16th);
//    th8.join();
//    std::thread th9(sum_vec, std::ref(sum), vec1, vec2, seven_16th, mid);
//    th9.join();
//    std::thread th10(sum_vec, std::ref(sum), vec1, vec2, mid, nine_16th);
//    th10.join();
//    std::thread th11(sum_vec, std::ref(sum), vec1, vec2, nine_16th, five_8th);
//    th11.join();
//    std::thread th12(sum_vec, std::ref(sum), vec1, vec2, five_8th, elev_16th);
//    th12.join();
//    std::thread th13(sum_vec, std::ref(sum), vec1, vec2, elev_16th, three_4th);
//    th13.join();
//    std::thread th14(sum_vec, std::ref(sum), vec1, vec2, three_4th, thirte_16th);
//    th14.join();
//    std::thread th15(sum_vec, std::ref(sum), vec1, vec2, thirte_16th, sev_8th);
//    th15.join();
//    std::thread th16(sum_vec, std::ref(sum), vec1, vec2, sev_8th, fifte_16th);
//    th16.join();
//    std::thread th17(sum_vec_ofstream, std::ref(sum), vec1, vec2, fifte_16th, vec1.end());
//    th17.join();
    

    
                
                    
        
        
    

    
    
    
    return 0;
}
