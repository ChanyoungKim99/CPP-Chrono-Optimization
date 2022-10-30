#include <iostream>
#include <chrono>   // 시간 관련 헤더

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
	// system_clock = 내 컴퓨터 시계
	Sort(scores, NUM_ARRAY, Ascending);
	auto endTime = std::chrono::system_clock::now();

	for (int i = 0; i < NUM_ARRAY; i++)
	{
		std::cout << scores[i] << std::endl;
	}

	auto duration = endTime - startTime;
	std::cout << "Sort() runs : " << duration.count() << std::endl;
}

// 이 함수가 최적화가 잘 되어있는가?
// Sort 함수가 걸리는 시간을 계산해보자
// chrono time의 단위 = ms
// 1초(1s) = 1000ms (milli~ = 1000) (ex)1000 millimeter = 1 meter)

// 난 25ms가 나왔지만, 컴퓨터마다 모두 시간이 달랐다
// 심지어 5번 연속으로 실행하면 계속 다른 값이 나온다.

// 결론적으로, 우리가 만든 Sort의 시간 측정이 불가능하다
// Complexity가 나오게 된 배경!
