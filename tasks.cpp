#include "tasks.h" 
#include <iostream>
#include <algorithm>
using namespace std;

vector<Money> make_vector(int numbers) {
  vector<Money> result;
  for (int i = 0; i < numbers; ++i) {
    Money a;
    cin >> a;
    result.push_back(a);
  }
  return result;
}

void print_vector(const vector<Money>& vec) {
  for (auto& item : vec) {
    cout << item << " ";
  }
  cout << endl;
}

void add_min_to_end_vector(vector<Money>& vec) {
  if (vec.empty()) return;

  Money min_value = *min_element(vec.begin(), vec.end());
  
  vec.push_back(min_value);
}

void delete_by_key_vector(vector<Money>& vec, const Money& key) {
  if (vec.empty()) return;

  auto it = find(vec.begin(), vec.end(), key);
  if (it != vec.end()) {
    vec.erase(it);
  }
}

void add_min_max_sum_vector(vector<Money>& v) {
  
  if (v.empty()) return;
  if (v.size() == 1)
    return;
  Money min_value = *min_element(v.begin(), v.end());;
  Money max_value = *max_element(v.begin(), v.end());;

  for (size_t i = 0; i < v.size(); ++i) {
    v[i] = v[i] + max_value + min_value;
  }
}

queue<Money> make_queue(int number) {
  queue<Money> result;
  for (int i = 0; i < number; ++i) {
    Money a;
    cin >> a;
    result.emplace(a);
  }
  return result;
}

void print_queue(queue<Money> q) {
  while (!q.empty()) {
    auto it = q.front();
    cout << it << " ";
    q.pop();
  }
  cout << endl;
}
vector<Money> copy_queue_to_vector(queue<Money>& q) {
  vector<Money> arr;
  queue<Money> temp = q;
  while (!temp.empty()) {
    auto it = temp.front();
    arr.push_back(it);
    temp.pop();
  }
  return arr;
}

void update_queue_from_vector(queue<Money>& q, const vector<Money>& arr) {
  while (!q.empty()) {
    q.pop();
  }
  for (const auto& item : arr) {
    q.push(item);
  }
}

void add_min_to_end_queue(queue<Money>& q) {
  vector<Money> arr = copy_queue_to_vector(q);
  add_min_to_end_vector(arr);
  update_queue_from_vector(q, arr);
}

void delete_by_key_queue(queue<Money>& q, const Money& key) {
  vector<Money> arr = copy_queue_to_vector(q);
  delete_by_key_vector(arr, key);
  update_queue_from_vector(q, arr);
}

void add_min_max_sum_queue(queue<Money>& q) {
  vector<Money> arr = copy_queue_to_vector(q);
  add_min_max_sum_vector(arr);
  update_queue_from_vector(q, arr);
}

multimap<int, Money> make_multimap(int n) {
  multimap<int, Money> result;
  for (int i = 0; i < n; ++i) {
    Money money;
    cin >> money;
    result.emplace(i, money);
  }
  return result;
}

void print_multimap(const multimap<int, Money>& m) {
  for (auto it = m.begin(); it != m.end(); ++it) {
    cout << it->first << "\t" << it->second << endl;
  }
}

void add_min_to_end_multimap(multimap<int, Money>& m) {
  if (m.empty()) return;
  // Копируем в вектор пар
  vector<pair<int, Money>> temp_vec(m.begin(), m.end());
  // Ищем минимальное значение Money 
  Money min_val = temp_vec[0].second;
  for (const auto& p : temp_vec) {
    if (p.second < min_val) {
      min_val = p.second;
    }
  }
  // Ищем максимальный ключ
  int max_key = temp_vec.back().first; // Так как multimap отсортирован по ключу, последний элемент имеет макс. ключ
  m.emplace(max_key + 1, min_val);
}

void delete_by_key_multimap(multimap<int, Money>& m, int key) {
  m.erase(key); 
}

void add_min_max_sum_multimap(multimap<int, Money>& m) {
  if (m.empty()) return;

  vector<pair<int, Money>> temp_vec(m.begin(), m.end());

  // Ищем мин и макс среди значений (Money)
  Money min_val = temp_vec[0].second;
  Money max_val = temp_vec[0].second;

  for (const auto& p : temp_vec) {
    if (p.second < min_val)
      min_val = p.second;
    if (max_val < p.second)
      max_val = p.second;
  }

  Money sum = min_val + max_val;
  // Очищаем оригинальный map
  m.clear();
  // Вставляем обратно с обновленными значениями
  for (auto& p : temp_vec) {
    Money new_val = p.second + sum;
    m.emplace(p.first, new_val);
  }
}
