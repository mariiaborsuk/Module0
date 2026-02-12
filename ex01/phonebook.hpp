#include <iomanip>
#include <iostream>
void display_each(std::string str);
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
	void display(void)
	{

		std::cout << "         " << index << "|";
		display_each(first_name);
		std::cout << "|";
		display_each(last_name);
		std::cout << "|";
		display_each(nickname);
	}
};
class PhoneBook
{
private:
	Contact contacts[8];
	int count;

public:
	int get_count() { return count; }
	PhoneBook() { count = 0; }
	void add(std::string name, std::string last_name, std::string nickname, std::string phone, std::string secret)
	{
		Contact contact;
		if (count < 8)
		{
			contact.set_name(name);
			contact.set_last_name(last_name);
			contact.set_nickname(nickname);
			contact.set_phone(phone);
			contact.set_secret(secret);
			contact.set_index(get_count());
			contacts[count] = contact;
			count++;
		}
		else
		{
			contacts[0].set_name(name);
			contacts[0].set_last_name(last_name);
			contacts[0].set_nickname(nickname);
			contacts[0].set_phone(phone);
			contacts[0].set_secret(secret);
			contacts[0].set_index(0);
		}
	}
	void search()
	{
		for (int i = 0; i < count; i++)
		{
			contacts[i].display();
			std::cout << std::endl;
		}
	}
	void display_data(int index)
	{
		for (int i = 0; i < count; i++)
		{
			if (index == contacts[i].get_index())
			{
				std::cout << contacts[i].get_name();
				std::cout << std::endl;
				std::cout << contacts[i].get_lastname();
				std::cout << std::endl;
				std::cout << contacts[i].get_nickname();
				std::cout << std::endl;
				std::cout << contacts[i].get_phone();
				std::cout << std::endl;
				std::cout << contacts[i].get_secret();
				std::cout << std::endl;
			}
		}
	}
};
