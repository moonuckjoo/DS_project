#include "Manager.h"

Manager::Manager()
{
	// Constructor
}

Manager::~Manager()
{
	// Destructor
}

void Manager::run(const char* command)
{
	// Open command and log files
	fcmd.open("command.txt"); // Open the command file
	flog.open("log.txt");     // Record the log

	if (!fcmd.is_open()) // If opening the file fails
	{
		flog << "Fail to open the command file" << endl;
		exit(-1);
	}
	else
	{
		int num;     // Error code
		int cnt = 0; // To check if LOAD has occurred
		string command; // Command
		string re_name = "0";

		while (1)
		{
			
			// Information to input
			string name = "";
			int age = 0;
			string date = "";
			char type = NULL;
			if (fcmd.eof()) break; // If there are no more commands to read, exit the loop

			fcmd >> command; // Get the first command from the file

			if (command == "LOAD")
			{
				num = 100; // Error code
				ifstream load_fin; // Create a stream to open and read from data.txt
				load_fin.open("data.txt");

				if (!load_fin || (cnt != 0)) // If data.txt cannot be opened or LOAD has occurred at least once
				{
					PrintErrorCode(num);
					exit(-1);
				}

				// If the member queue is full, an error occurs
				if (memberQueue->full())
				{
					PrintErrorCode(num);
					exit(-1);
				}
				else
				{
					flog << "====== " << "LOAD" << " =====";
					while (!load_fin.eof()) // Read all information until the end of the file
					{
						load_fin >> name >> age >> date >> type; // Automatically store the data
						if (re_name == name) // Exit the loop if the same name appears again to prevent duplicates
						{
							break;
						}
						memberQueue->push(name, age, date, type);

						flog << endl << name << "/" << age << "/" << date << "/" << type;
						re_name = name;
					}
					flog << endl << "================" << endl << endl;
					cnt++;
				}
				load_fin.close(); // Close the stream that was opened
			}
			else if (command == "ADD")
			{
				num = 200; // Error code
				fcmd >> name >> age >> date >> type; // Parse information after the command
				if ((name == "") || (age == 0) || (date == "") || (type == NULL)) // If input is missing
				{
					PrintErrorCode(num);
					exit(-1);
				}
				if (memberQueue->full())
				{
					PrintErrorCode(num);
					exit(-1);
				}
				else
				{
					flog << "====== " << "ADD" << " =====" << endl;
					flog << name << "/" << age << "/" << date << "/" << type << endl;
					flog << "===============" << endl << endl;
					memberQueue->push(name, age, date, type);
				}
			}
			else if (command == "QPOP")
			{
				num = 300; // Error code
				if (memberQueue->empty()) // If the member queue is empty
				{
					PrintErrorCode(num);
					exit(-1);
				}
				else
				{
					while (!memberQueue->empty())
					{
						MemberQueueNode* TLNode = memberQueue->front(); // Store the member queue function result
						Termslist->insert(TLNode, TermsBST_A, TermsBST_B, TermsBST_C, TermsBST_D);
						// Parse the data and pass it to the namebst
						namebst->insert(namebst->getRoot(), namebst->change_temrstoName(TermsBST_A->ex_data_parsing(TLNode)));
						if (TLNode->gettype() == 'A')
						{
							TermsBST_A->insert(TermsBST_A->getRoot(), TermsBST_A->ex_data_parsing(TLNode));
						}
						else if (TLNode->gettype() == 'B')
						{
							TermsBST_B->insert(TermsBST_B->getRoot(), TermsBST_B->ex_data_parsing(TLNode));
						}
						else if (TLNode->gettype() == 'C')
						{
							TermsBST_C->insert(TermsBST_C->getRoot(), TermsBST_C->ex_data_parsing(TLNode));
						}
						else if (TLNode->gettype() == 'D')
						{
							TermsBST_D->insert(TermsBST_D->getRoot(), TermsBST_D->ex_data_parsing(TLNode));
						}
						memberQueue->pop();
					}
					PrintSuccess("QPOP");
				}
			}
			else if (command == "SEARCH")
			{
				num = 400;
				fcmd >> name;
				NameBSTNode* searchNode = namebst->search_name(name); // Search for data
				if (searchNode == nullptr) // If not found
				{
					PrintErrorCode(num);
				}
				else
				{
					flog << "===== " << "SEARCH" << " =====" << endl;
					flog << searchNode->getName() << "/" << searchNode->getAge() << "/" << searchNode->getDate() << "/" << searchNode->getExdate() << endl;
					flog << "===============" << endl << endl;
				}
			}
			else if (command == "PRINT")
			{
				num = 500;
				string search;
				fcmd >> search;
				if (search.length() == 1) // Type type
				{
					// If TermsBST is empty, print an error code
					if (search == "A")
					{
						if (TermsBST_A->getRoot() == NULL)
							PrintErrorCode(num);
						else
							Printlist_A(TermsBST_A->getRoot());
					}
					else if (search == "B")
					{
						if (TermsBST_B->getRoot() == NULL)
							PrintErrorCode(num);
						else
							Printlist_B(TermsBST_B->getRoot());
					}
					else if (search == "C")
					{
						if (TermsBST_C->getRoot() == NULL)
							PrintErrorCode(num);
						else
							Printlist_C(TermsBST_C->getRoot());
					}
					else
					{
						if (TermsBST_D->getRoot() == NULL)
							PrintErrorCode(num);
						else
							Printlist_D(TermsBST_D->getRoot());
					}
				}
				else //TYPE NAME
				{
					if (namebst->getRoot() == NULL)
						PrintErrorCode(num);
					else
						Printlist_name(namebst->getRoot());
				}
			}
			else if (command == "DELETE")
			{
				num = 600;
				bool pop_success;
				string order, data;
				fcmd >> order >> data;
				if (order == "DATE") // If date is entered
				{
					NameBST_postorder_delete(namebst, namebst->getRoot(), data);
					TermsBST_postorder_delete(TermsBST_A, TermsBST_A->getRoot(), data);
					TermsBST_postorder_delete(TermsBST_B, TermsBST_B->getRoot(), data);
					TermsBST_postorder_delete(TermsBST_C, TermsBST_C->getRoot(), data);
					TermsBST_postorder_delete(TermsBST_D, TermsBST_D->getRoot(), data);
					PrintSuccess("DELETE");
				}
				else if (order == "NAME") // If name is entered
				{
					NameBSTNode* delnode = namebst->search_name(data);
					if (delnode == nullptr) // If the node to be deleted is not found
						PrintErrorCode(num);
					else
					{
						pop_success = namebst->deleteBST(delnode); // Return true if deletion from Name BST is successful
						if (pop_success)
						{
							if (TermsBST_A->search_Name(data) != nullptr)
							{
								pop_success = TermsBST_A->Terms_delete(TermsBST_A->search_Name(data));
								if (!pop_success)
									PrintErrorCode(num);
							}
							else if (TermsBST_B->search_Name(data) != nullptr)
							{
								pop_success = TermsBST_B->Terms_delete(TermsBST_B->search_Name(data));
								if (!pop_success)
									PrintErrorCode(num);
							}
							else if (TermsBST_C->search_Name(data) != nullptr)
							{
								pop_success = TermsBST_C->Terms_delete(TermsBST_C->search_Name(data));
								if (!pop_success)
									PrintErrorCode(num);
							}
							else if (TermsBST_D->search_Name(data) != nullptr)
							{
								pop_success = TermsBST_D->Terms_delete(TermsBST_D->search_Name(data));
								if (!pop_success)
									PrintErrorCode(num);
							}
							PrintSuccess("DELETE");
						}
						else
							PrintErrorCode(num);
					}
				}

				Termslist->size_update(Termslist->getHead(), TermsBST_A, TermsBST_B, TermsBST_C, TermsBST_D);
			}
			else if (command == "EXIT")
			{
				PrintSuccess("EXIT");
				return;
			}
			else
			{
				num = 1000;
				PrintErrorCode(num);
			}

		}
	}
}

void Manager::TermsBST_postorder_delete(TermsBST* BSTtype, TermsBSTNode* root, string searchdate)
{
	if (root == NULL)
		return;

	TermsBST_postorder_delete( BSTtype, root->getLeft(), searchdate);
	TermsBST_postorder_delete( BSTtype, root->getRight(), searchdate);
	if (root->getex_date() < searchdate)
	{
		BSTtype->Terms_delete(root);
	}
}


void Manager::NameBST_postorder_delete(NameBST* namebst, NameBSTNode* root, string searchdate)
{
	if (root == NULL)
		return;

	NameBST_postorder_delete(namebst,  root->getLeft(), searchdate);
	NameBST_postorder_delete(namebst, root->getRight(), searchdate);
	if (root->getExdate() < searchdate)
	{
		namebst->deleteBST(root);
	}
}

void Manager::Printlist_A(TermsBSTNode* rootNode) // Print function
{
	flog << endl << "===== " << "PRINT" << " =====";
	flog << endl << "Terms_BST A";
	inorder_print(rootNode);
	flog << endl << "===============" << endl << endl;
}
void Manager::Printlist_B(TermsBSTNode* rootNode) // Print function
{
	flog << endl << "===== " << "PRINT" << " =====";
	flog << endl << "Terms_BST B";
	inorder_print(rootNode);
	flog << endl << "===============" << endl << endl;
}
void Manager::Printlist_C(TermsBSTNode* rootNode) // Print function
{
	flog << endl << "===== " << "PRINT" << " =====";
	flog << endl << "Terms_BST C";
	inorder_print(rootNode);
	flog << endl << "===============" << endl << endl;
}
void Manager::Printlist_D(TermsBSTNode* rootNode) // Print function
{
	flog << endl << "===== " << "PRINT" << " =====";
	flog << endl << "Terms_BST D";
	inorder_print(rootNode);
	flog << endl << "===============" << endl << endl;
}

void Manager::inorder_print(TermsBSTNode* root)
{
	if (root == NULL)
		return;

	inorder_print(root->getLeft());
	flog << endl << root->getname() << "/" << root->getage() << "/" << root->getdate() << "/" << root->getex_date();
	inorder_print(root->getRight());
}

void Manager::Printlist_name(NameBSTNode* rootNode) // Print function
{
	flog << endl << "===== " << "PRINT" << " =====";
	flog << endl << "Name_BST";
	inorder_print_name(rootNode);
	flog << endl << "===============" << endl << endl;
}

void Manager::inorder_print_name(NameBSTNode* root)
{
	if (root == NULL)
		return;

	inorder_print_name(root->getLeft());
	flog << endl << root->getName() << "/" << root->getAge() << "/" << root->getDate() << "/" << root->getExdate();
	inorder_print_name(root->getRight());
}

void Manager::PrintSuccess(const char* cmd)
{
	flog << "===== " << cmd << " =====" << endl;
	flog << "Success" << endl;
	flog << "===============" << endl << endl;
}

void Manager::PrintErrorCode(int num)
{
	flog << "===== ERROR =====" << endl;
	flog << num << endl;
	flog << "=================" << endl << endl;
}
