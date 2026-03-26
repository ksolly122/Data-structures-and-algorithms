/* main function to test lab 7
 * Expected output:
 *  [650, 99, 62932, 499, 321] 
 *  [700, 100, 62900, 500, 300] 
 *  [(Lucy, 5.4), (Tabby, 6.3), (Fluffy, 3.4)] 
 *  [(Lunar Lucy, 32.4), (Lunar Tabby, 37.8), (Lunar Fluffy, 20.4)] 
*/


#include "better_linkedlist.h"

#include<iostream>
using namespace std;

struct cat {
	string name;
	float jump_height;
	cat() {}
	cat(string n, float jh) : name(n), jump_height(jh) {}
};

ostream& operator<<(ostream& out, const cat& c){
	return out << "(" << c.name << ", " << c.jump_height << ")";
}

void hundred_round(int &r){
	r = ((r + 50) / 100) * 100;
}

int main(){
	list<int> numbers;
	numbers.push(321);
	numbers.push(499);
	numbers.push(62932);
	numbers.push(99);
	numbers.push(650);
	cout << numbers << endl;
	numbers.apply_to_all(hundred_round);
	cout << numbers << endl;
	
	list<cat> cats;
	cats.push(cat("Fluffy", 3.4));
	cats.push(cat("Tabby", 6.3));
	cats.push(cat("Lucy", 5.4));
	cout << cats << endl;

	cats.apply_to_all([](cat& c){
		c.name = "Lunar " + c.name;
		c.jump_height *= 6;
	});
	cout << cats << endl;

	return 0;
}