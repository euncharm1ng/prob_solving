#include <iostream>
#include <stack>
#include <cstring>
#include <string>

using namespace std;

stack<string> symbol, letter;
char input[101];
int return_chk = 0;

void
calc()
{
	while(!symbol.empty()){
		string oper = symbol.top(); symbol.pop();
		if(oper == ")") calc();
		else if (oper == "(") return;
		else{
			string second = letter.top(); letter.pop();
			if(oper == "-" || oper == "+") calc();
			else if(oper == "*" || oper == "/"){
				if(!symbol.empty() && 
						(symbol.top() == "/" || symbol.top() == "*" || symbol.top() == ")")){
					return_chk = 1;
					calc();
				}
			}
			string first = letter.top(); letter.pop();
			first.append(second).append(oper);
			letter.push(first);
			if(return_chk) {return_chk = 0; return;}
		}
	}
}


int 
main()
{
	scanf("%s", input);
	printf("%s\n", input);
	for(int i = 0; i < strlen(input); i++){
		string s(1, input[i]);
		if(input[i] < 48) symbol.push(s);
		else letter.push(s);
	}
	calc();
	cout << letter.top() << "\n";
}
