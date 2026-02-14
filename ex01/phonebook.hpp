#include <iomanip>
#include <iostream>
class Contact
{
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string secret;
	int index;

public:
	void set_name(std::string name) { this->first_name = name; }
	void set_last_name(std::string lastname) { this->last_name = lastname; }
	void set_nickname(std::string nick_name) { this->nickname = nick_name; }
	void set_phone(std::string phone) { this->phone_number = phone; }
	void set_secret(std::string my_secret) { this->secret = my_secret; }
	void set_index(int ind) { this->index = ind; }
	int get_index(void) { return index; }
	std::string get_name(void) { return first_name; }
	std::string get_lastname(void) { return last_name; }
	std::string get_nickname(void) { return nickname; }
	std::string get_phone(void) { return phone_number; }
	std::string get_secret(void) { return secret; }
	void display_each(std::string str);
	void display(void);
};
class PhoneBook
{
private:
	Contact contacts[8];
	int count;

public:
	int get_count() { return count; }
	PhoneBook() { count = 0; }
	void add(std::string name, std::string last_name, std::string nickname, std::string phone, std::string secret);
	void search();
	void display_data(int index);
};
