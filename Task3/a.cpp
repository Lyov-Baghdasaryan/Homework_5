#include <iostream>
#include <cstring>

class Vehicle {
public:
    virtual void printInfo() const = 0;
};


class Car : public Vehicle
{
	public:
		Car() : model("unknown"), make("unknown"), year(0) {}
		Car(std::string model, std::string make,  int year) 
			: model(model), make(make), year(year) {}
	public:
		void printInfo() const override{
			std::cout << "-- Vehicle type is Car --" << std::endl;
			std::cout << "Model : " << model << std::endl;
			std::cout << "Make : " << make << std::endl;
			std::cout << "Year : " << year << std::endl;
			std::cout << std::endl; 
		}	
	private:
		std::string model;
		std::string make;
		int year;
};

class Bike : public Vehicle
{
	public:
		Bike() : brand("unknown"), size(0) {}
		Bike(std::string brand, int size) : brand(brand), size(size) {}

	public:
		void printInfo() const override{
			std::cout << "-- Vehicle type is Bike --" << std::endl;
			std::cout << "Brand : " << brand << std::endl;
			std::cout << "Size : " << size << std::endl;
			std::cout << std::endl;
		}	
	private:
		std::string brand;
		int size;
};

class Fleet
{
	public:
		Fleet() : capacity(5), size(0), m_vehicle(new Vehicle*[capacity]) {}

		~Fleet(){
    			delete[] m_vehicle;
			m_vehicle = nullptr;
		}

	public:
		void addVehicle(Vehicle* vehicle){
			if(size == capacity){
				capacity *= 2;
				Vehicle** tmp = new Vehicle*[capacity];
				for(int i = 0; i < size; i++){
					tmp[i] = m_vehicle[i];
				}
				delete[] m_vehicle;
				m_vehicle = tmp;
				tmp = nullptr;
			}
			
			m_vehicle[size] = vehicle;
			size++;
		}
		void removeVehicle(int index) {
	   		if (index < 0 || index > size) return;
    		  	for (int i = index; i < size-1; ++i) {
       				m_vehicle[i] = m_vehicle[i + 1];
    			}
			m_vehicle[size-1] = nullptr;
    			size--;
		}

		void fleetList() {
			for(int i = 0; i < size; i++){
				m_vehicle[i]->printInfo();		
			}	
		}
	private:
		Vehicle** m_vehicle;
		int capacity;
		int size;

};

int main()
{
	Bike obj;
	Car obj2;

	Fleet fleet;
	fleet.addVehicle(&obj);
	fleet.addVehicle(&obj2);
	
	fleet.fleetList();

}
