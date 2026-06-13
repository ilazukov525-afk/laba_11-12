#include <iostream>
#include "Money.h"
#include "tasks.h"

using namespace std;

int main() {
  setlocale(LC_ALL, "ru");

  int n;
  cout << "введите количество элементов (n): ";
  cin >> n;

  // --- 1. VECTOR ---
  cout << "\n--- работа с vector ---\n";
  cout << "введите " << n << " сумм (рубли копейки):\n";
  vector<Money> v = make_vector(n);

  cout << "\nисходный вектор:\n";
  print_vector(v);

  add_min_to_end_vector(v);
  cout << "после добавления минимума в конец:\n";
  print_vector(v);

  cout << "введите сумму для удаления (рубли копейки): ";
  Money key_del;
  cin >> key_del;
  delete_by_key_vector(v, key_del);
  cout << "после удаления элемента:\n";
  print_vector(v);

  add_min_max_sum_vector(v);
  cout << "после прибавления суммы min/max к каждому:\n";
  print_vector(v);

  // --- 2. QUEUE ---
  cout << "\n--- работа с queue ---\n";
  cout << "введите " << n << " сумм для очереди:\n";
  queue<Money> q = make_queue(n);

  cout << "\nисходная очередь:\n";
  print_queue(q);

  add_min_to_end_queue(q);
  cout << "после добавления минимума в конец:\n";
  print_queue(q);

  cout << "введите сумму для удаления из очереди: ";
  cin >> key_del;
  delete_by_key_queue(q, key_del);
  cout << "после удаления элемента:\n";
  print_queue(q);

  add_min_max_sum_queue(q);
  cout << "после прибавления суммы min/max к каждому:\n";
  print_queue(q);

  // --- 3. MULTIMAP ---
  cout << "\n--- работа с multimap ---\n";
  cout << "введите " << n << " сумм для словаря (ключи будут 0, 1, ...):\n";
  multimap<int, Money> m = make_multimap(n);

  cout << "\nисходный multimap (ключ -> значение):\n";
  print_multimap(m);

  add_min_to_end_multimap(m);
  cout << "после добавления минимума в конец (под макс. ключом+1):\n";
  print_multimap(m);

  cout << "введите целочисленный ключ для удаления: ";
  int key_int;
  cin >> key_int;
  delete_by_key_multimap(m, key_int);
  cout << "после удаления по ключу " << key_int << ":\n";
  print_multimap(m);

  add_min_max_sum_multimap(m);
  cout << "после прибавления суммы min/max к значениям:\n";
  print_multimap(m);

  return 0;
}