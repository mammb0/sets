#include "stdio.h"
#include "CSet.h"
#include "iostream"

using namespace std;
		
int main()
{
	setlocale(LC_ALL, "Russian");
	int pow;
	cout << "������� �������� ��������� ���������: ";
	cin >> pow;
	int * mass = new int[pow];
	cout << endl << "������� �������� ���������: ";
	for (int i = 0; i < pow; i ++){
		cin >> mass[i];
	}
	CSet set(mass, pow);
	const CSet m1 = set;
	cout << endl << "�������� �������� ��������:" << endl << "1 - ���������� ��������" << endl << "2 - �������� ��������" << endl << "3 - ����������� ��������" << endl << "4 - ����������� ��������" << endl << "5 - �������� ��������" << endl << "6 - �������������� �������� ��������" << endl;
	cout << endl;
	int num;
	cin >> num;
	if (num == 1){
		//���������� ��������
		int a;
		cout << endl << "������� ����� ������� ��� ���������� � �������� ���������: ";
		cin >> a;
		set.Add(a);
		cout << endl << "���������� ���������: ";
		set.Output();
	}
	else{
		if (num == 2){
			//�������� ��������
			int p;
				cout << endl << "������� �������� �������� ��� �������� �� ��������� ���������: ";
				cin >> p;
				set.Del(p);
				cout << endl << "���������� ���������: ";
				set.Output();
		}
		else{
			if (num == 3){
				//����������� ��������
				int i;
				cout << "������� �������� ��������������� ���������: ";
				cin >> pow;
				int * mass1 = new int [pow];
				cout << endl << "������� �������� ��������������� ���������: " ;
				for (i = 0; i < pow; i ++){
					cin >> mass1[i];
				}
				CSet set2(mass1, pow);
				CSet m = set.Inter(set2);
				m.Output();	
			}
			else {
				if (num == 4){
					//����������� ��������
					int i;
					cout << "������� �������� ��������������� ���������: ";
					cin >> pow;
					int * mass1 = new int [pow];
					cout << endl << "������� �������� ��������������� ���������: " ;
					for (i = 0; i < pow; i ++){
						cin >> mass1[i];
					}
					CSet set2(mass1, pow);
					CSet m = Unif(set, set2);
					m.Output();	
				}
				else{
					if (num == 5){
						//�������� ��������
						int i;
						cout << "������� �������� ��������������� ���������: ";
						cin >> pow;
						int * mass1 = new int [pow];
						cout << endl << "������� �������� ��������������� ���������: " ;
						for (i = 0; i < pow; i ++){
							cin >> mass1[i];
						}
						CSet set2(mass1, pow);
						CSet m = set.Diff(set2);
						m.Output();
					}
					else {
						if (num == 6){
							//�������������� �������� ��������
							int i;
							cout << "������� �������� ��������������� ���������: ";
							cin >> pow;
							int * mass1 = new int [pow];
							cout << endl << "������� �������� ��������������� ���������: " ;
							for (i = 0; i < pow; i ++){
								cin >> mass1[i];
							}
							CSet set2(mass1, pow);
							CSet m = set.SimDiff(set2);
							m.Output();
						}
					}
				}
			}
		}
	}
	
	cout << endl << "������� ��������� �������� ������ CSet: " << CSet :: Get_tic();
	cout << endl << "�������������� ���������: ";
	m1.Output();
	return 0;
}
