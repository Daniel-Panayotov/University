#include <iostream>;
#include <string>;
#include <format>;

using namespace std;

struct Telephone {
public:
	string phoneNumber;
	Telephone* next;

	Telephone(string telephone) : next(nullptr) {	
		this->phoneNumber = telephone;
	}
};

struct Address {
public:
	//1 for home address | 2 for work address
	int home;
	string addressName;
	Telephone* telephone;
	Address* next;

	Address(string address, int home) : telephone(nullptr), next(nullptr) {
		this->addressName = address;
		this->home = home;
	}
};

struct Contact {
public:
	string name;
	Address* address;
	Contact* next;

	Contact(string name) : address(nullptr), next(nullptr) {
		this->name = name;
	};
};

class PhoneBook {
private:
	//first name entry in the linked list
	Contact* tail;
	//last name entry in the linked list
	Contact* head;


	//List out all the contacts in the linked list, numbered starting from 1
	void listContacts() {
		int contactI = 1;
		Contact* currContact = head;
		Address* currAddress = nullptr;
		Telephone* currPhone = nullptr;

		//check if theres a start to the linked list
		if (!currContact) { cout << "No contacts" << endl; return; }

		//loop the linked list and post the stream contact info
		string contactInfo;
		while (currContact) {
			contactInfo = format("\n{}. {}", contactI, currContact->name);

			//concatenate the string with info for each address
			currAddress = currContact->address;
			while (currAddress) {
				contactInfo += format("\n\nAddress: {}", currAddress->addressName);

				//concatenate string with each phone number
				currPhone = currAddress->telephone;
				while (currPhone) {
					contactInfo += format("\nTel: {}", currPhone->phoneNumber);
					currPhone = currPhone->next;
				}
			
				currAddress = currAddress->next;
			}

			cout << contactInfo << "\n------------------" << endl;

			//increment the contact index & get next contact
			contactI++;
			currContact = currContact->next;
		}
	}

	//list all addresses of given contact, each indexed starting from 1
	void listAddresses(Contact* contact) {
		int addressI = 1;
		Address* currAddress = contact->address;

		string addressInfo;
		while (currAddress) {
			addressInfo = format("\n{}. {}", addressI, currAddress->addressName);

			cout << addressInfo << endl;

			addressI++;
			currAddress = currAddress->next;
		}
	}

	//Gives the total count of working contacts
	//A contact is a working contact, when they have at least one address
	void listWorkingContactsCount() {
		Contact* currContact = head;

		int workingCount = 0;
		while (currContact) {
			Address* currAddress = currContact->address;

			while (currAddress) {
				if (currAddress->home == 2) { workingCount++; break; }
				currAddress = currAddress->next;
			}
			currContact = currContact->next;
		}

		cout << "There are total of " << workingCount << " working contacts" << endl;
	}

	//prompt user for a number with the given prompt
	//return number
	int promptNumber(string prompt) {
		int number;

		cout << prompt;
		cin >> number;
		cin.ignore();

		return number;
	}

	//retrieve contact with a given index, index defaults to 1 if left
	//return Contact* | nuullptr
	Contact* getContact(int contactI = 1) {
		auto curr = head;

		int loopI = 1;
		while (curr && loopI < contactI) {	loopI++; curr = curr->next;	}

		//check if both indexes match OR if contact is invalid
		if (loopI != contactI || !curr) { cout << "Couldn't retrieve contact." << endl; return nullptr; }

		return curr;
	}

	//retrieve address with a given index from given contact, index defaults to 1 if left
	//return Address* | nuullptr
	Address* getAddress(Contact* contact, int addressI = 1) {
		Address* currAddress = contact->address;

		int loopI = 1;
		while (currAddress && loopI < addressI) { loopI++; currAddress = currAddress->next; }

		//check if both indexes match OR if address is invalid
		if (loopI != addressI || !currAddress) { cout << "Couldn't retrieve address." << endl; return nullptr; }

		return currAddress;
	}

	//prompt the user for a name and append it to the linked list, then ask if they would like to add an address
	void insertContact() {
		string name;

		//prompt user
		cout << "Enter full name: ";
		getline(cin, name);

		auto contact = new Contact(name);

		//append the contact to the linked list
		if (!head) {
			head = contact;
			tail = head;
		}
		else {
			tail->next = contact;
			tail = tail->next;
		}

		int enterAddress;

		//prompt user whether to add an address or not
		cout << "Would you like to add an address?\n1. Yes\n2. No" << endl;
		cin >> enterAddress;
		//ignore \n
		cin.ignore();

		if (enterAddress != 1) return;

		insertAddress(contact);
	}

	//prompt user for address and insert it to the given contact
	void insertAddress(Contact* contact) {
		string addressName;
		int homeAddress;

		int addAddress = 1;
		while (addAddress == 1) {
			cout << "Contact: " << contact->name << endl;
			cout << "Enter address: ";

			getline(cin, addressName);

			//prompt
			cout << "Is this address a home or working address?\n1. Home\n2. Working" << endl;
			cin >> homeAddress;
			cin.ignore();

			//set initial address
			auto address = contact->address;
			if (!address) { contact->address = new Address(addressName, homeAddress); address = contact->address; }
			else {
				//get the last valid address node
				while (address->next) {
					address = address->next;
				}

				//set new address
				address->next = new Address(addressName, homeAddress);
			}

			//prompt user to add a phone
			int enterPhone;
			cout << "Would you like to add a phone number?\n1. Yes\n2. No" << endl;
			cin >> enterPhone;
			cin.ignore();

			if (enterPhone == 1) { insertPhone(address); }

			cout << "Would you like to add another address?\n1. Yes\n2. No" << endl;
			cin >> addAddress;
			cin.ignore();
		}
	}

	//prompt user for a phone number and add it to the given address, can add multiple phone numbers
	void insertPhone(Address* address) {
		string phoneNumber;

		int addPhone = 1;
		while (addPhone == 1) {
			cout << "Address: " << address->addressName << endl;
			cout << "Enter phone number: ";

			getline(cin, phoneNumber);

			if (!address->telephone) { address->telephone = new Telephone(phoneNumber); }
			else {
				//get the last valid phone node
				auto phone = address->telephone;
				while (phone->next) {
					phone = phone->next;
				}

				//set new address
				phone->next = new Telephone(phoneNumber);
			}

			cout << "Would you like to add another number to this address?\n1. Yes\n2. No" << endl;
			cin >> addPhone;
			cin.ignore();
		}		
	}

public:
	PhoneBook() : tail(nullptr), head(nullptr) {}

	~PhoneBook() {}

	//method to start the program
	void run() {
		const string menu = 
R"(
-----Phonebook Menu-----
1. Add contact
2. Add address to contact
3. Add phone number to address of contact
4. List contacts
5. List working contacts
0. Exit
)";
		int command = 1;

		while (command != 0) {			
            cout << menu << endl;
			cout << "Please choose an option: ";
			cin >> command;
			//remove \n from buffer
			cin.ignore();

			//perform desired command
			switch (command) {
			case 1:
				insertContact();
				break;
			case 2: {
				int contactI = promptNumber("Enter number of contact: ");
				auto contact = getContact(contactI);
				if (!contact) break;
				insertAddress(contact);
				break;
			}
			case 3: {
				int contactI = promptNumber("Enter number of contact: ");
				auto contact = getContact(contactI);
				if (!contact) break;
				listAddresses(contact);
				int addressI = promptNumber("Enter number of address: ");
				Address* address = getAddress(contact, addressI);
				if (!address) break;
				insertPhone(address);
				break;
			}
			case 4:
				listContacts();
				break;
			case 5:
				listWorkingContactsCount();
				break;
			}
		}
	}	
};

int main() {
	PhoneBook x;

	x.run();

	return 0;
}