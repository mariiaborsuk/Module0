#include "phonebook.hpp"
void add_command(PhoneBook &book)
{
	std::string name1;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string secret;
	std::cout << "First name: " << std::endl;
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

void display_each(std::string str)
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
			for (int i = 0; i <= len; i++)
			{
				std::cout << " ";
			}
			std::cout << str;
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
		std::cout << "Enter command:" << std::endl;
		std::cin >> cmd;
		std::cin.ignore();
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
