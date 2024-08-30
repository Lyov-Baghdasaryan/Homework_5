#include <iostream>
#include <cstring>

class Car
{
	public:
		Car() = default;
		Car(std::string model) : model(model){}
	public:	
		// Setter
		void setModel(std::string model){
			this->model = model;
		}

		// Getter
		std::string getModel() const{
			return model;
		}

		void printInfo(){
			std::cout << "Model : " << model << std::endl;
		}

	private:
		//bool isSomeonsOwned;
		std::string model;
};

class Person
{
	public:
		Person() : m_age(0), m_car(nullptr) {}
		Person(std::string name,  int age, Car* car = nullptr) : m_name(name), m_age(age), m_car(car) {}

	public:
		// Setter
		void setName(std::string name){
			m_name = name;
		}		
		void setAge(int age){
			if(age >= 0){
				m_age = age;
			}
		}	
		void setCar(Car* car){
			if(!m_car){
				m_car = car;
			}
		}

		//Getter
		std::string getName() const{ return m_name; }
		int getAge() const{ return m_age; }
		const Car* getCar() const{
			if(m_car){
				return m_car;
			}

			std::cout << "Person does not have a car" << std::endl;
			return nullptr;
		}

		void doesHaveCar(){
			if(m_car){
				std::cout << "The person has a car" << std::endl;
			}
			std::cout << "The person doesn't have a car" << std::endl;
		
		}

		void printInfo(){
			std::cout << "Name : " << m_name << std::endl;
			std::cout << "Age : " << m_age << std::endl;
			if(m_car){
				std::cout << "Ownes car ";
				m_car->printInfo();
			}
		}

	private:
		std::string m_name;
		int m_age;
		Car* m_car;
};

int main()
{
	Person obj("Jasmin", 21);
	Car property("Toyota");

	obj.setCar(&property);

	obj.printInfo();

	return 0;
}
