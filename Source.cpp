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
		cout << "������� ���������� ����� � �������: ";
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
			ochUm[i] = och[i+1];//������� ������ ������� (�����)
		}
		k--;//��������� ���-�� ��������� �������, ������ ��� ���� �����
		delete[]och;
		och = new string[k];//������� ����� ������, ��� ������� ��������, ������� �����
		for (int i = 0; i < k; i++)
		{
			och[i] = ochUm[i];//�������� � ���� ����������� ��������
			cout<<och[i]<<" ";
		}
	}

	void UvelO()
	{
		ochUv = new string[k + 1];
		for (int i = 0; i < k ; i++)
		{
			ochUv[i] = och[i];//�������� � ����� ������ ��� ������� ��������
		}
		k++;//����������� ���-�� ��������� �������, ������ ��� ���� �������
		cout << "������� ������, ������� ��������: ";
		cin >> car;
		ochUv[k-1] = car;//��������� ������ � ����� �������
		delete[]och;
		och = new string[k];//����� ������
		for (int i = 0; i < k; i++)
		{
			och[i]= ochUv[i];//��������� � ���� ��� ������, ������� ������ � �������, ������ � ����������
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
			cout << "���� ������ ������, ������� 1 \n���� ������ ��������, ������� 0 \n���� ������� �����, ������� 5 \n";
			cin >> p;
			
		}
		else if (p == 1)
		{
			o.UmenshO();
			cout << endl;
			cout << "���� ������ ������, ������� 1 \n���� ������ ��������, ������� 0 \n���� ������� �����, ������� 5 \n";
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