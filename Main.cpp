#include <iostream>
#include <string>
#include <vector>


class Cat {
public:
	~Cat() {};
	std::string name_;
	std::string breed_;
	std::string owner_;
	int age_;

	Cat() : name_("no_name"), breed_("no_breed"), owner_("no_owner"), age_(0) {};

	Cat(std::string name, std::string breed, std::string owner, int age) {
		name_ = name;
		breed_ = breed;
		owner_ = owner;
		age_ = age;
	}	
	void printCat()
	{
		std::cout << "Имя кота: " << name_ << '\n';
		std::cout << "Порода кота: " << breed_ << '\n';
		std::cout << "Хозяин кота: " << owner_ << '\n';
		std::cout << "Возраст кота: " << age_ << '\n';
	}
	std::string getName(){
		return name_;
	}
};

class Hostel {
public:	

	void addCat(const Cat& Cat)
	{
		counterCat++;
		if (counterCat > 5) throw - 1;
		obj_Cat.push_back(Cat);
		
		
	}

	void searchCat(const std::string& Cat) 
	{
		for (auto i = obj_Cat.begin(); i != obj_Cat.end(); i++) {
			if (i->getName() == Cat)
			{
				std::cout << "Есть такой кот! " << Cat << '\n';
				return;
			}			
		}
		std::cout << "Нет такого кота!\n";
		std::cout << std::endl;
	}
	void delCat(const std::string& Cat)
	{
		counterCat--;
		if (counterCat < 0) throw - 1;		
		for (auto i = obj_Cat.begin(); i != obj_Cat.end(); i++) {
			if (i->getName() == Cat) {
				obj_Cat.erase(i);
				i = obj_Cat.begin();
			}
		}

	}
	
	void printAllCat() {
		std::cout << "Живут коты: \n";
		for (int i = 0; i < obj_Cat.size(); i++) {
			std::cout << obj_Cat[i].name_ << ',';
		}
		std::cout << std::endl;
	}
	
private:
	int maxQuantityCat_ = 5;
	int counterCat = 0;
	std::vector<Cat>obj_Cat;
};
int main() {
	setlocale(LC_ALL, "ru");


	Cat cat1("Sadam", "arab", "Oleg", 3);	
	Cat cat2("Paul", "mexicanec", "Sasha", 5);
	Cat cat3("HunChi", "kitaec", "Petya", 6);
	Cat cat4("Vasia", "russkiy", "Vova", 9);
	Cat cat5("Alfred", "niger", "Misha", 1);
	Cat cat6("Maga", "kazah", "Dima", 30);

	cat1.printCat();

	Hostel hostel1;
	hostel1.addCat(cat1);
	hostel1.addCat(cat2);
	hostel1.addCat(cat3);
	hostel1.addCat(cat4);
	hostel1.addCat(cat5);
	//hostel1.addCat(cat6);

	hostel1.printAllCat();
	hostel1.searchCat("Vasia");
	hostel1.delCat("Sadam");
	hostel1.printAllCat();
	
	
	return 0;
}