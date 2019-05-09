// Task 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "MyEdge.h"
#include "MyNode.h"
#include "MyGraph.h"
#include <iostream>
#include <string>

using namespace std;

/*
Реализовать шаблон класса (функции), принимающий элементы любого типа и поддерживающий базовые операции 
в соответствии со своим назначением. В качестве внутренней структуры хранения данных можно 
использовать, например, динамический массив. Использование шаблона должно осуществляться 
из функции main() и содержать примеры работы как минимум с двумя разными типами данных 
(например, int и string).

5. Направленный граф.

Граф с узлами целых чисел, граф с узлами строк.

Операции :
1) Получить количество узлов
2) Напечатать все узлы
3) Добавить новый узел
4) Привязать узел к другому узлу
5) Пометить все узлы как посещенные
6) Пометить все узлы как непосещенные
7) Посмотреть узлы, к которым привязан текущий (напечатать информацию конкретного узла)
*/


int main()
{
	auto* myGraph1 = new MyGraph<int>; // создание типизированного экземпляра класса 

	myGraph1->add(1); // добавление узелка в конкретный граф
	myGraph1->add(2);
	myGraph1->add(3);
	myGraph1->add(4);
	myGraph1->add(5);
	myGraph1->add(6);

	//auto it = myGraph1->begin();
	//cout << it.get_value() << endl;
	//auto it2 = myGraph1->end();

	try
	{
		//myGraph1->connect(11, 2, 40); // связать Node[11] с Node[2] ребром веса 40
		myGraph1->connect(1, 2, 0);
		myGraph1->connect(2, 3, 0);
		myGraph1->connect(3, 4, 0);
		myGraph1->connect(1, 4, 0);
		myGraph1->connect(4, 6, 0);
		myGraph1->connect(1, 5, 0);

		//myGraph1->print(1);  // напечатать содержимое узла Node[1] и его рёбра
		//myGraph1->print(2);
		//myGraph1->print(10);
	}
	catch (...)
	{
		cout << "Wrong node index!" << endl;
	}

	

	cout << myGraph1->get_size() << endl; // получить количество узлов графа

	//myGraph1->visit_all(); // посетить все

	//myGraph1->unvisit_all(); // снять посещение со всех

	//myGraph1->depth_bypass(myGraph1->return_nodes().at(0));

	myGraph1->breadth_bypass(myGraph1->return_nodes().at(0));

	myGraph1->print(true);
	
	myGraph1->unvisit_all();

	myGraph1->print(false);

	// myGraph1->print(false); // напечать посещенные(true) / непосещенные(false) узлы
	
	delete myGraph1; // высвобождение памяти

	/*
	auto* myGraph2 = new MyGraph<char>;
	myGraph2->add('a');
	myGraph2->add('s');
	myGraph2->add('a');
	myGraph2->add('t');
	myGraph2->add('w');
	myGraph2->add('q');
	myGraph2->print(); // напечатать содержимое графа
	myGraph2->get_size(); // получить количество узлов графа
	delete myGraph2;
	*/
	cin.ignore();
	cin.ignore();

	return 0; 
}

// setlocale(LC_ALL, "Russian"); // установка локализации для корректного отображения русских символов