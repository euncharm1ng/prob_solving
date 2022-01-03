#include <iostream>
#include <string>
#include <stack>
#include <cstring>

using namespace std;
stack<string> symbol, letter;
char input[101];
char return_chk = 0;

void
parenthesis()
{
	while(!symbol.empty()){
		string oper = symbol.top(); symbol.pop();
		if(oper == "(") return;
		string second = letter.top(); letter.pop();
		string next({"&"}); if(!symbol.empty()) next = symbol.top();
		
		if(next == "&" || next == "("){
			string first = letter.top(); letter.pop();
			first.append(second).append(oper);
			letter.push(first);
		}
		else if(next == "*" || next == "/"){
			if(oper == "*" || oper == "/") return_chk++;
			parenthesis();
			string first = letter.top(); letter.pop();
			first.append(second).append(oper);
			letter.push(first);
		}
		else if(oper == "+" || oper == "-"){
			parenthesis();
			string first = letter.top(); letter.pop();
			first.append(second).append(oper);
			letter.push(first);
		}
		else if(oper == "*" || oper == "/"){
			string first = letter.top(); letter.pop();
			first.append(second).append(oper);
			letter.push(first);
			if(return_chk) {return_chk--; return;}
		}
	}
}

void
calc()
{
	while(!symbol.empty()){
		string oper = symbol.top(); symbol.pop();
		string second = letter.top(); letter.pop();
		string next({"&"}); if(!symbol.empty()) next = symbol.top();
		if(oper == "+" || oper == "-") calc();
		else if(next == "*" || next == "/"){
			return_chk++;
			calc();
		}
		string first = letter.top(); letter.pop();
		first.append(second).append(oper);
		letter.push(first);
		if(return_chk){return_chk--; return;}
	}
}

void
print_stack(stack<string> target)
{
	if(target.empty()) return;
	string curr = target.top(); target.pop();
	print_stack(target);
	cout << curr << "  ";
	target.push(curr);
}

int 
main()
{
	scanf("%s", input);
	for(int i = 0; i < strlen(input); i++){
		if(input[i] == ')'){
			parenthesis();
			printf("print_stack()\n\t");
			print_stack(symbol);
			printf("\n\t");
			print_stack(letter);
			puts("");
		}
		else if(input[i] < 48) symbol.push({input[i]});
		else letter.push({input[i]});
	}
	calc();
	cout << letter.top() << "\n";
}
