#include <iostream>
#include <string>

using namespace std;

class OCHERED
{
	int k;
	string* och = new string[k];
	string* ochUm;
	string* ochUv;
	string car;
public:
	
	OCHERED()
	{
		cout << "Введите количество машин в очереди: ";
		cin >> k;
		och = new string[k];
		for (int i = 0; i < k; i++)
		{
			cin >> car;
			och[i] = car;
		}
	}

	void UmenshO()
	{
		ochUm = new string[k - 1];
		for (int i = 0; i < k-1; i++)
		{
			ochUm[i] = och[i+1];//удаляем первый элемент (уехал)
		}
		k--;//уменьшаем кол-во элементов массива, потому что один уехал
		delete[]och;
		och = new string[k];//создаем новый массив, без первого элемента, который уехал
		for (int i = 0; i < k; i++)
		{
			och[i] = ochUm[i];//сохранем в него оставшиееся значения
			cout<<och[i]<<" ";
		}
	}

	void UvelO()
	{
		ochUv = new string[k + 1];
		for (int i = 0; i < k ; i++)
		{
			ochUv[i] = och[i];//сохранем в новый массив все прошлые элементы
		}
		k++;//увеличиваем кол-во элементов массива, потому что один приехал
		cout << "Введите машину, которая приехала: ";
		cin >> car;
		ochUv[k-1] = car;//добавляем машину в конец очереди
		delete[]och;
		och = new string[k];//новый массив
		for (int i = 0; i < k; i++)
		{
			och[i]= ochUv[i];//сохраняем в него все машины, которые сейчас в очереди, вместе с приехавшей
			cout<< och[i] << " ";
		}
	}

	~OCHERED()
	{
		delete[]och;
		och = nullptr;
		delete[]ochUm;
		ochUm = nullptr;
		delete[]ochUv;
		ochUv = nullptr;
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	int p = 0;
	
	OCHERED o;
	
	do
	{
		if (p == 0)
		{
			o.UvelO();
			cout << endl;
			cout << "Если машина уехала, нажмите 1 \nЕсли машина осталась, нажмите 0 \nЕсли хотетие выйти, нажмите 5 \n";
			cin >> p;
			
		}
		else if (p == 1)
		{
			o.UmenshO();
			cout << endl;
			cout << "Если машина уехала, нажмите 1 \nЕсли машина осталась, нажмите 0 \nЕсли хотетие выйти, нажмите 5 \n";
			cin >> p;
		}
		else if (p == 5) break;
		else
		{
			cout << "ERROR";
			return 0;
		}
	} 
	while (p != 5);
	
	o.~OCHERED();
}