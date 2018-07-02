#include <iostream>
using namespace std;
void main() 
{
	int n;
	cout << "Please enter the number of mailboxes for the Postal problem:";
	cin >> n;
	char **mails = new char *[n];

		for (int i = 0; i < n; i++)
	{
		mails[i] = new char[n];
	}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				mails[i][j] = 'c';
			}
		}

	for (int a = 1; a <= n; a++)
	{
		cout << a << "\t";
	}
	cout << endl;

	for (int i = 1; i < n; i++) 
	{
		for (int j = 0; j < n; j++)
		{
			mails[i][j] = mails[i - 1][j];
			if (mails[i][j] == 'O')
			{
				mails[i][j] = 'o';
			}
			else if (mails[i][j] == 'C')
			{
				mails[i][j] = 'c';
			}
		}
			int c = i;
			while (c < n)
			{
				if (mails[i][c] == 'c' || mails[i][c] == 'C')
				{
					mails[i][c] = 'O';
				}
				else if (mails[i - 1][c] == 'o' || mails[i - 1][c] == 'O')
				{
					mails[i][c] = 'C';
				}
				c = (c + i);
				c++;
			}
	}
		// Printing array values 
		for (int i = 0; i < n; i++) 
		{
			for (int j = 0; j < n; j++) 
			{
				cout << mails[i][j] << "\t";
			}
			cout << endl;
		}
		cout << "Toal Mailboxes: " << n << endl;
		cout << "Closed Mailboxes: ";

		for (int j = 0; j < n; j++) 
		{
			if (mails[n - 1][j] == 'c' || mails[n - 1][j] == 'C') // scanning all the columns (say on 150th row) 
			{
				cout << j + 1 << ","; // increment because index starts from 0 
			}
		}

		cout << endl;
	}

