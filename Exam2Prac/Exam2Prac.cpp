// LETS DO THIS THING
#include<string>
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

class Practice
{
private:
	string Prac1;
	vector<double> Prac2;
public:
	Practice(string new_string = "", vector<double> new_vector = {}) :
		Prac1(new_string), Prac2(new_vector)
	{}
	string get_string() const { return Prac1; };
	vector<double> get_vector() const { return Prac2; };
	void set_string(string s) { Prac1 = s; };
	void set_vector(vector<double>& v) { for (int i = 0; i < v.size(); i++) Prac2.push_back(v[i]); };
	void money() { for (int i = 0; i < Prac2.size(); i++) Prac2[i] /= 100; };
	void combine(Practice Prac2);
};

void Practice::combine(Practice p2)
{
	if (Prac2.size() == p2.get_vector().size())
		for (int i = 0; i < Prac2.size(); i++)
			Prac2[i] *= p2.get_vector()[i];
	else
		cout << "Practice vectors aren't equal!\n";
}

bool operator == (Practice const p1, Practice const p2)
{
	vector<bool> b;
	if (p1.get_vector().size() == p2.get_vector().size())
	{
		for (int i = 0; i < p1.get_vector().size(); i++)
		{
			if (p1.get_vector()[i] == p2.get_vector()[i])
				b.push_back(true);
			else
				b.push_back(false);
		}
		for (int i = 0; i < b.size(); i++)
			if (b[i] == false)
				return false;
		return true;
	}
	else
	{
		cout << "Practice vectors aren't equal!\n";
		return false;
	}
}

bool operator != (Practice const p1, Practice const p2)
{
	return !(p1 == p2);
}

ostream& operator << (ostream& o, Practice& const p)
{
	o << "\t   " << p.get_string() << "\t\n\t";
	for (int i = 0; i < p.get_vector().size(); i++)
		o << p.get_vector()[i] << " ";
	o << "\n";
	return o;
}

int main()
{
	Practice p;
	p.set_string("January");
	vector<double> money = {850, 490, 1053};
	p.set_vector(money);
	Practice p2("February", vector<double> {9007, 1045, 235});

	cout << p;
	cout << p2;
	
	p.money();
	p2.money();

	cout << p;
	cout << p2;

	bool b = (p == p2);
	bool b2 = (p != p2);
	cout << b << " " << b2 << endl;

	p.combine(p2);
	cout << p;
	p2.combine(p);
	cout << p2;

	cout << "Enter a output file name: \n";
	string output;
	cin >> output;
	ofstream o{ output };
	if (!o) cout << "Couldn't create file!\n";
	o << p << p2;
	o.close();

	cout << "Success!\n";

	cout << "Enter another output file name: \n";
	string output2;
	cin >> output2;
	ifstream i{ output };
	ofstream o2{ output2,ios_base::app };

	char c;
	while (i.get(c))
		o2.put(c);
	
	i.close();
	i.open(output);

	o2 << "\n";
	while (i >> c)
		o2 << c;

	cout << "Copying complete!\n";

	return 0;
}