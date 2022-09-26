#include "stdio.h"
#include "CSet.h"
#include "iostream"

using namespace std;
		
int main()
{
	setlocale(LC_ALL, "Russian");
	int pow;
	cout << "Введите мощность основного множества: ";
	cin >> pow;
	int * mass = new int[pow];
	cout << endl << "Введите элементы множества: ";
	for (int i = 0; i < pow; i ++){
		cin >> mass[i];
	}
	CSet set(mass, pow);
	const CSet m1 = set;
	cout << endl << "Выберите желаемую операцию:" << endl << "1 - добавление элемента" << endl << "2 - удаление элемента" << endl << "3 - пересечение множеств" << endl << "4 - объединение множеств" << endl << "5 - разность множеств" << endl << "6 - симметрическая разность множеств" << endl;
	cout << endl;
	int num;
	cin >> num;
	if (num == 1){
		//добавление элемента
		int a;
		cout << endl << "Введите новый элемент для добавления в основное множество: ";
		cin >> a;
		set.Add(a);
		cout << endl << "Полученное множество: ";
		set.Output();
	}
	else{
		if (num == 2){
			//удаление элемента
			int p;
				cout << endl << "Введите значение элемента для удаления из основного множества: ";
				cin >> p;
				set.Del(p);
				cout << endl << "Полученное множество: ";
				set.Output();
		}
		else{
			if (num == 3){
				//пересечение множеств
				int i;
				cout << "Введите мощность дополнительного множества: ";
				cin >> pow;
				int * mass1 = new int [pow];
				cout << endl << "Введите элементы дополнительного множества: " ;
				for (i = 0; i < pow; i ++){
					cin >> mass1[i];
				}
				CSet set2(mass1, pow);
				CSet m = set.Inter(set2);
				m.Output();	
			}
			else {
				if (num == 4){
					//объединение множеств
					int i;
					cout << "Введите мощность дополнительного множества: ";
					cin >> pow;
					int * mass1 = new int [pow];
					cout << endl << "Введите элементы дополнительного множества: " ;
					for (i = 0; i < pow; i ++){
						cin >> mass1[i];
					}
					CSet set2(mass1, pow);
					CSet m = Unif(set, set2);
					m.Output();	
				}
				else{
					if (num == 5){
						//разность множеств
						int i;
						cout << "Введите мощность дополнительного множества: ";
						cin >> pow;
						int * mass1 = new int [pow];
						cout << endl << "Введите элементы дополнительного множества: " ;
						for (i = 0; i < pow; i ++){
							cin >> mass1[i];
						}
						CSet set2(mass1, pow);
						CSet m = set.Diff(set2);
						m.Output();
					}
					else {
						if (num == 6){
							//симметрическая разность множеств
							int i;
							cout << "Введите мощность дополнительного множества: ";
							cin >> pow;
							int * mass1 = new int [pow];
							cout << endl << "Введите элементы дополнительного множества: " ;
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
	
	cout << endl << "Счетчик созданных объектов класса CSet: " << CSet :: Get_tic();
	cout << endl << "Первоначальное множество: ";
	m1.Output();
	return 0;
}
