#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

std::ostream& operator<<(std::ostream& os, const vector<int>& vec)
{
	cout << "{ ";
	for (auto& it : vec) {
		os << it;
		if (it != *(vec.end() - 1)) {
			os << ", ";
		}
	}
	cout << " }";

	return os;
}

vector<vector<int>> fun1(size_t n)
{
	// Главный вектор. Вектор векторов.
	vector<vector<int>> majorVector(n);

	// Возможные размеры (1, 2, 3, ...).
	// Для получения случайных размеров без повторения, тасуем этот вектор
	// и получаем случайный список неповторяющихся размеров.
	vector<int> sizes(n);
	for (size_t i = 0; i < n; i++) {
		sizes[i] = i + 1;
	}
	std::random_shuffle(sizes.begin(), sizes.end());


	// Обход по векторам.
	for (size_t vectorI = 0; vectorI < n; vectorI++) {
		// Создаем вектор.
		majorVector[vectorI] = vector<int>(sizes[vectorI]);

		// Обход по элементам.
		for (size_t elemI = 0; elemI < majorVector[vectorI].size(); elemI++) {
			// Смещаем результат rand() для того, чтобы были отрицательные числа.
			majorVector[vectorI][elemI] = rand() - RAND_MAX / 2;
		}

		// Если номер вектора четный.
		if (vectorI % 2 == 0) {
			// Сортируем вектор по возрастанию.
			std::sort(majorVector[vectorI].begin(), majorVector[vectorI].end());
		}
		// Если номер вектора нечетный.
		else {
			// Сортируем вектор по убыванию.
			std::sort(majorVector[vectorI].rbegin(), majorVector[vectorI].rend());
		}
	}

	return majorVector;
}

int main()
{
	srand(static_cast<unsigned int>(time(0)));

	size_t n = 0;
	cout << "Enter number of arrays: ";
	cin >> n;

	auto majorVector = fun1(n);

	for (auto& it : majorVector) {
		cout << it << endl;
	}

	return 0;
}
