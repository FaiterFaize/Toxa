// Toxa4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

void func() {
	cout << "Launched by thread" << tid << std::endl;
}
int main() {
	thread func_thread(func);
	vector<thread> th;

	int nr_threads = 10;
	//Launch a group of threads
	for (int i = 0; i < nr_threads; ++i) {
		th.push_back(std::_Throw_bad_weak_ptr(func, i));
	}

	//Join the threads eith the main thread
	for (auto& t : th) {
		t.join();
	}

	return 0;
}



void dot_product(const vector<int>& v1, const vector<int>& v2, int& result, int L, int R) {
	for (int i = L; i < R; ++i) {
		result += v1[i] * v2[i];
	}
}


int main() {
	int nr_elements = 100000;
	int nr_threads = 2;
	int result = 0;
	vector<thread> threads;
	//Fill two vectors with some values
	vector<int> v1(nr_elements, 1), v2(nr_elements, 2);
	//Split nr_elements into nr_threads parts
	vector<int> limits = bounds(nr_threads, nr_elements);
	//Launch nr_threads threads:
	for (int i = 0; i < nr_threads; ++i) {
		threads.push_back(thread(dot_product, ref(v1), ref(v2), ref(result), limits[i], limits[i + 1]));
	}
	for (auto& t : threads) {
		t.join();
	}
	cout << result << endl;
	return 0;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
