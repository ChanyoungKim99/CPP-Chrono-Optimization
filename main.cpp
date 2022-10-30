#include <iostream>
#include <chrono>   // �ð� ���� ���

using Comparison = bool(*) (int, int);

bool Ascending(int x, int y)
{
	return x > y;
}

bool Descending(int x, int y)
{
	return x < y;
}

void Sort(int numbers[], int count, Comparison f)
{
	for (int i = 0; i < count; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			if (f(numbers[i], numbers[j]))
			{
				int temp = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = temp;
			}
		}
	}
}

int main()
{
	const int NUM_ARRAY{ 10 };

	int scores[NUM_ARRAY]{ 20, 10, 40, 15, 30, 70, 60, 90, 80, 50 };

	auto startTime = std::chrono::system_clock::now(); 
	// system_clock = �� ��ǻ�� �ð�
	Sort(scores, NUM_ARRAY, Ascending);
	auto endTime = std::chrono::system_clock::now();

	for (int i = 0; i < NUM_ARRAY; i++)
	{
		std::cout << scores[i] << std::endl;
	}

	auto duration = endTime - startTime;
	std::cout << "Sort() runs : " << duration.count() << std::endl;
}

// �� �Լ��� ����ȭ�� �� �Ǿ��ִ°�?
// Sort �Լ��� �ɸ��� �ð��� ����غ���
// chrono time�� ���� = ms
// 1��(1s) = 1000ms (milli~ = 1000) (ex)1000 millimeter = 1 meter)

// �� 25ms�� ��������, ��ǻ�͸��� ��� �ð��� �޶���
// ������ 5�� �������� �����ϸ� ��� �ٸ� ���� ���´�.

// ���������, �츮�� ���� Sort�� �ð� ������ �Ұ����ϴ�
// Complexity�� ������ �� ���!
