#pragma once

#include <vector>
#include <queue>
#include <map>
#include "Money.h"

using namespace std;


vector<Money> make_vector(int numbers);
void print_vector(const vector<Money>& v);
void add_min_to_end_vector(vector<Money>& v);
void delete_by_key_vector(vector<Money>& v, const Money& key);
void add_min_max_sum_vector(vector<Money>& v);

void update_queue_from_vector(queue<Money>& q, const vector<Money>& arr);
queue<Money> make_queue(int n);
void print_queue(queue<Money> q); 
void add_min_to_end_queue(queue<Money>& q);
void delete_by_key_queue(queue<Money>& q, const Money& key);
void add_min_max_sum_queue(queue<Money>& q);

multimap<int, Money> make_multimap(int n);
void print_multimap(const multimap<int, Money>& m);
void add_min_to_end_multimap(multimap<int, Money>& m);
void delete_by_key_multimap(multimap<int, Money>& m, int key);
void add_min_max_sum_multimap(multimap<int, Money>& m);