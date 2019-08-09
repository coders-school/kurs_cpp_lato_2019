#include <iostream>
#include <vector>
#include <map>
#include <random>
#include <algorithm>

using namespace std;

unsigned int random_int(unsigned int m)
{
	random_device dev;
	mt19937 rng(dev());
	uniform_int_distribution<mt19937::result_type> dist(0,m);
	return dist(rng);
}

void fill_vec(vector<unsigned int> & v, unsigned int n, unsigned int m)
{
	v.reserve(n);
	for(auto i=0; i<n; i++)
		v.emplace_back(random_int(m));
	sort(v.begin(), v.end());
	auto last = unique(v.begin(), v.end());
	v.erase(last, v.end());
}

void show_vec(vector<unsigned int> v)
{
	for(auto a : v)
		cout<<a<<" ";
}

void show_map(map<unsigned int, vector<unsigned int>> m)
{
	for(auto a : m)
	{
		cout<<a.first<<" : ";
		show_vec(a.second);
		cout<<endl;
	}
}

void prime_numbers(vector<unsigned int> & num, vector<unsigned int> & con, vector<unsigned int> & p_n, unsigned int m)
{
	iota(num.begin(),num.end(),2);
	int i,j;
	for(i=0; i<m-1; i++)
	{
		for(j=0; j<=i; j++)
		{
			if(num[i]%num[j]==0)
				con.emplace_back(num[i]);
		}
	if(con.size()==1)
		p_n.emplace_back(num[i]);
	con.clear();
	}
}
vector<unsigned int> map_value(int i, vector<unsigned int> p_n, vector<unsigned int> rand)
{
	vector<unsigned int> vec;
	for(auto a : rand)
	{
		if(a % p_n[i]==0)
			vec.emplace_back(a);
	}
return vec;
}	

void prime_map(map<unsigned int, vector<unsigned int>> &  map, vector<unsigned int> p_n, vector<unsigned int> rand)
{
	int i =0;
	for(auto it=p_n.begin(); it!=p_n.end(); it++)
	{
		int var=p_n[i];
		map[var]=map_value(i, p_n, rand);
		i++;
	}
}

int main()
{
	vector<unsigned int> rand_values{};
	vector<unsigned int> prime_num{};
	vector<unsigned int> container{};
	map<unsigned int, vector <unsigned int>> map{};

	unsigned int n,m;
	cout<<"Podaj ile ma byc wygenerowanych liczb: ";
	cin>>n;
	cout<<"Podaj gorna granice w jakiej maja sie znajdowac wygenerowane wartosci: ";
	cin>>m;
	vector<unsigned int> numbers(m-1);

	fill_vec(rand_values, n ,m);
	prime_numbers(numbers, container, prime_num, m);
	prime_map(map, prime_num, rand_values);
	cout<<"Wylosowane wartosci :"<<endl;
	show_vec(rand_values);
	cout<<"\n";
	cout<<"Size: ";
	cout<<rand_values.size()<<endl;
	cout<<"\n\n";
	cout<<"Mapa :"<<endl;
	show_map(map);
	
return 0;
}
