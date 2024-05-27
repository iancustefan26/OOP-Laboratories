#include <iostream>

enum class Relation {
	Friend,
	Acquaintace,
	Colleague,
	Unknown
};

class Contact {
protected:
	const char* name;
	Relation relationship;
public:
	Contact(const char* name) {
		this->name = name;
	}
	const char* getName() const {
		return name;
	}
	virtual Relation getRelationshipType() const = 0;
	~Contact() {
		delete name;
	}
};

class Friend : public Contact {
	int birth_date;
	const char* phone_number;
	const char* address;
public:
	Friend(const char* name) : Contact(name) {
		relationship = Relation::Friend;
	};
	Friend(const char* name, const char* phone, const char* address, int birth) : 
		birth_date(birth), phone_number(phone), address(address), Contact(name) {}
	const char* getPhone() const {
		return phone_number;
	}
	const char* getAddress() const {
		return address;
	}
	const int getBirth() const {
		return birth_date;
	}
	Relation getRelationshipType() const {
		return Relation::Friend;
	}
	~Friend() {
		delete phone_number;
		delete address;
		delete name;
	}
};

class Acquaintance : public Contact {
	const char* phone_number;
public:
	Acquaintance(const char* name) : Contact(name) {
		relationship = Relation::Acquaintace;
	}
	Acquaintance(const char* name, const char* phone) : Contact(name), phone_number(phone) {}
	Relation getRelationshipType() const {
		return Relation::Acquaintace;
	}
	~Acquaintance() {
		delete name;
		delete phone_number;
	}
};

class Colleague : public Contact {
	const char* company;
	const char* address;
public:
	Colleague(const char* name) : Contact(name){
		relationship = Relation::Colleague;
	}
	Colleague(const char* name, const char* company, const char* address) :
		Contact(name), company(company), address(address) {}
	Relation getRelationshipType() const {
		return Relation::Colleague;
	}
	~Colleague() {
		delete company;
		delete address;
		delete name;
	}
};

class AddressBook {
private:
	Contact** list;
	int number_of_contacts;
public:
	AddressBook() {
		list = new Contact*[100];
		number_of_contacts = 0;
	}
	Contact* getContact(const char* name_param) const{
		for (int i = 0; i < number_of_contacts; ++i)
			if (list[i]->getName() == name_param)
				return list[i];
		return nullptr;
	}
	Friend** getFriends() const{
		Friend** friend_list;
		int number_of_friends = 0;
		for (int i = 0; i < number_of_contacts; ++i)
			if (list[i]->getRelationshipType() == Relation::Friend)
				friend_list[number_of_friends] = (Friend *)list[i];
		return friend_list;

	}
	bool deleteContact(const char* name_param) {
		for (int i = 0; i < number_of_contacts; ++i)
			if (list[i]->getName() == name_param)
			{
				delete list[i]; return true;
			}
		return false;
	}
	bool addContact(Contact& person) {
		Relation rel_type = person.getRelationshipType();
		switch (rel_type) {
			case Relation::Friend:
				list[number_of_contacts] = new Friend(person.getName());
				break;
			case Relation::Acquaintace:
				list[number_of_contacts] = new Acquaintance(person.getName());
				break;
			case Relation::Colleague:
				list[number_of_contacts] = new Colleague(person.getName());
				break;
			default:
				return false;
		}
		number_of_contacts++;
		return true;
	}
	~AddressBook() {
		delete list;
	}
};

int main() {

	return 0;
}