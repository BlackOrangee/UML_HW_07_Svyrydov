// UML_HW_07_Svyrydov.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <vector>

using namespace std;

class User
{
private:
	bool notified;

public:
	User() {
		notified = false;
	}

	void notification() {
		notified = true;
	}

	bool status() {
		return notified;
	}
};


class Notifier
{
private:
	vector<User*> users;

public:
	void setUser(User* user)
	{
		users.push_back(user);
	}

	void printStatus()
	{
		for (int i = 0; i < users.size(); i++)
		{
			if (users[i]->status())
			{
				cout << "user " << i + 1 << " notified" << endl;
			}
			else
			{
				cout << "user " << i + 1 << "is not notified" << endl;

			}
		}
	}

	void notification() {
		for (int i = 0; i < users.size(); i++)
		{
			users[i]->notification();
		}
	}
};

int main()
{
	// Create a notifier object
	Notifier notifier;

	// Set users to notifier
	notifier.setUser(new User());
	notifier.setUser(new User());
	notifier.setUser(new User());
	notifier.setUser(new User());

	// Print users status
	cout << "Added users list:" << endl;
	notifier.printStatus();

	// Notifier added users
	cout << endl << "Notifier added users" << endl;
	notifier.notification();

	// Set new users
	notifier.setUser(new User());
	notifier.setUser(new User());
	notifier.setUser(new User());

	// Print users status again
	cout << endl << "Add new users, after notification and print: " << endl;
	notifier.printStatus();

}