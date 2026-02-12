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
	void set_name(std::string name)
	{
		first_name = name;
	}
	void set_last_name(std::string last_name)
	{
		last_name = last_name;
	}
	void set_nickname(std::string nickname)
	{
		nickname = nickname;
	}
	void set_phone(std::string phone)
	{
		phone_number = phone;
	}
	void set_secret(std::string secret)
	{
		secret = secret;
	}
	void set_index(int index)
	{
		index = index;
	}
	void display_each(std::string str)
	{
		int len = 10 - str.length() - 1;
		if (len <= 0)
		{
			std::string ch = str.substr(0,9);
			std::string new_str=ch+".";
			std::cout<<new_str;

		}
		else
		{
			for (int i = 0; i < len; i++)
			{
				std::cout << " ";
			}
			std::cout << str;
		}
	}
	void display(void)
	{

		std::cout << "         " << index << "|";
		display_each(first_name);
		std::cout <<"|";
		display_each(last_name);
		std::cout <<"|";
		display_each(nickname);
	}
};
class PhoneBook
{
private:
	Contact contacts[8];

public:
	void add(std::string name, std::string last_name, std::string nickname, std::string phone, std::string secret, int count)
	{
		Contact contact;
		contact.set_name(name);
		contact.set_last_name(last_name);
		contact.set_nickname(nickname);
		contact.set_phone(phone);
		contact.set_secret(secret);
		contact.set_index(count);
		contacts[count] = contact;
		count++;
		std::cout << "added: " << count << std::endl;
	}
	void search(int count)
	{
		for (int i = 0; i < count; i++)
		{
			std::cout <<"SEARCH";
			contacts[i].display();
		}
	}
};
