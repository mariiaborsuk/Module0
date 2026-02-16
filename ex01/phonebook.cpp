#include "phonebook.hpp"

void add_command(PhoneBook &book)
{
	std::string name1;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string secret;
	std::cout <<"First name: "  << std::endl;
	std::getline(std::cin, name1);
	std::cout << "Last name: " << std::endl;
	std::getline(std::cin, last_name);
	std::cout << "Nickname: " << std::endl;
	std::getline(std::cin, nickname);
	std::cout << "Phone number: " << std::endl;
	std::getline(std::cin, phone_number);
	std::cout << "Secret " << std::endl;
	std::getline(std::cin, secret);
	if (secret.length() > 0 && name1.length() > 0 && last_name.length() > 0 && nickname.length() > 0 && phone_number.length() > 0)
		book.add(name1, last_name, nickname, phone_number, secret);
	else
		std::cout << "Please, fill in all the data!" << std::endl;
}

void Contact :: display_each(std::string str)
	{
		int len = 10 - str.length() - 1;
		if (len <= 0)
		{
			std::string ch = str.substr(0, 9);
			std::string new_str = ch + ".";
			std::cout << new_str;
		}
		else
		{
			std::cout <<std::setw(10) << str;
		}
	}
	void Contact::display(void)
	{

		std::cout <<std::setw(10)<< index << "|";
		display_each(first_name);
		std::cout << "|";
		display_each(last_name);
		std::cout << "|";
		display_each(nickname);
	}
		void PhoneBook::add(std::string name, std::string last_name, std::string nickname, std::string phone, std::string secret)
	{
		Contact contact;
			contact.set_name(name);
			contact.set_last_name(last_name);
			contact.set_nickname(nickname);
			contact.set_phone(phone);
			contact.set_secret(secret);
			contact.set_index(this->get_index());
			this->contacts[index] = contact;
			if(count<0)
				count++;
			index = (index + 1) % 8;
	}
	void PhoneBook ::search()
	{
		for (int i = 0; i < count; i++)
		{
			contacts[i].display();
			std::cout << std::endl;
		}
	}
	void PhoneBook:: display_data(int index)
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
int main(void)
{
	int exit = 0;
	PhoneBook book;
	while (exit < 1)
	{
		std::cout << std::endl;
		std::string cmd;
		std::cout << "Enter command:\n";
		//  std::cin>> cmd;
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
		{
			add_command(book);
		}
		else if (cmd == "SEARCH")
		{
			book.search();
			std::cout << "Enter index of contact: " << std::endl;
			int index;
			std::cin >> index;
			std::cin.ignore();
			if (index >= 0 && index < book.get_count())
				book.display_data(index);
			else
			{
				std::cout << "Wrong index!" << std::endl;
				std::cout << "Please, enter index between 0 and " << book.get_count() - 1 << std::endl;
			}
		}
		else if (cmd == "EXIT")
			exit = 1;
		else
			std::cout << "Wrong command" << std::endl;
	}

	return 0;
}

//  https://www.geeksforgeeks.org/cpp/difference-between-public-and-private-in-c-with-example/
// https://www.geeksforgeeks.org/cpp/iterate-over-characters-of-a-string-in-c/
// https://www.youtube.com/watch?v=ZzaPdXTrSb8
// https://www.geeksforgeeks.org/cpp/when-do-we-use-initializer-list-in-c/
// https://www.geeksforgeeks.org/cpp/cin-in-c/
// https://www.geeksforgeeks.org/cpp/how-to-add-element-at-the-beginning-of-array-in-cpp/
