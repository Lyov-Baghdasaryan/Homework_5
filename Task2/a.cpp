#include <iostream>
#include <cstring>

class Vehicle
{
	public:
		Vehicle() = default;
		Vehicle(float weight, int max_speed) 
			: weight(weight), max_speed(max_speed) {}
	public:
		void setWeight(float weight){
			if(weight > 0){
				this->weight = weight;
			}
		}
		void setMaxspeed(int max_speed){
			if(max_speed > 0){
				this->max_speed = max_speed;
			}
		}
		float getWeight() const{
			return weight;
		}
		int getMaxspeed() const{
			return max_speed;
		}
		virtual void printInfo() const{
			std::cout << "Weight : " << weight << std::endl;
			std::cout << "Max speed : " << max_speed << std::endl;
		}
			
	private:
		float weight;
		int max_speed;	
};

class Car : public Vehicle
{	
	public:
		Car(float weight, int max_speed, std::string fuel_type) 
			: Vehicle(weight, max_speed), fuel_type(fuel_type) {}
	public:
		void setFueltype(std::string fuel_type){
			this->fuel_type = fuel_type;
		}
		std::string getFueltype() const{
			return fuel_type;
		}
		void printInfo() const override{
			Vehicle::printInfo();
			std::cout << "Fuel type : " << fuel_type << std::endl;
		}

	private:
		std::string fuel_type;
};

int main()
{
	Vehicle obj1(1425.2, 260);
	Vehicle* ptr = &obj1;
	ptr->printInfo();

	Car obj2(1650.7, 240, "Gas");
	ptr = &obj2;
	ptr->printInfo();
}	
