#include "phonebook.hpp"

int main(void)
{
	int count=0;
	int exit = 0;
	PhoneBook book;
	while (exit < 1)
	{
		std::cout <<std::endl;
		std::string cmd;
		std::cout<<"Enter command:" <<std::endl;
		std::cin >> cmd;
		std::cin.ignore();
		if (cmd == "ADD")
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
			{
				book.add(name1, last_name, nickname, phone_number, secret, count);
			}
			else
			{
				std::cout << "Please, fill in all the data!" << std::endl;
			}
		}
		else if(cmd=="SEARCH")
		{
			book.search(count);
		}
		else if(cmd=="EXIT")
		{
			exit=1;
		}
		else{
			std:: cout <<"Wrong command" <<std::endl;
		}
	}

	return 0;
}

//  https://www.geeksforgeeks.org/cpp/difference-between-public-and-private-in-c-with-example/
// https://www.geeksforgeeks.org/cpp/iterate-over-characters-of-a-string-in-c/
// https://www.youtube.com/watch?v=ZzaPdXTrSb8
// https://www.geeksforgeeks.org/cpp/when-do-we-use-initializer-list-in-c/
// https://www.geeksforgeeks.org/cpp/cin-in-c/
// https://www.geeksforgeeks.org/cpp/how-to-add-element-at-the-beginning-of-array-in-cpp/
