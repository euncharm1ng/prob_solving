/*
test cases:
input: A*B*C-D+E/F*G+H-I-J/K/L-M/N
answer: AB*C*D-EF/G*+H+I-JK/L/-MN/-

input: A*((B*C)/D-(E/F+(G*H/((I*J-(((K+L*M))))/N)))+O-P*(Q/R)+S)-T
answer: ABC*D/EF/GH*IJ*KLM*+-N//+-O+PQR/*-S+*T-

input: (A*(B-C/D))-E-F-((((G+(H*I)))-((J*(K*(L-M*N/O)-P/Q*R)/(S-T*U*V-W-X*Y/Z)))))
answer: ABCD/-*E-F-GHI*+JKLMN*O/-*PQ/R*-*STU*V*-W-XY*Z/-/--
*/
#include <iostream>
#include <string>
#include <stack>
#include <cstring>

using namespace std;
stack<string> symbol, letter;
char input[101];
char mult_cnt = 0;

void
pop_append(string oper, string second)
{
	string first = letter.top(); letter.pop();
	first.append(second).append(oper);
	letter.push(first);
}

void
post_fix()
{
	while(!symbol.empty()){
		string oper = symbol.top(); symbol.pop();
		if(oper == "(") return;
		string second = letter.top(); letter.pop();
		string next("&"); if(!symbol.empty()) next = symbol.top();
		
		if(oper == "+" || oper == "-"){
			if(next == "&" || next == "(")
				pop_append(oper, second);
			else{
				post_fix();
				pop_append(oper, second);
				return;
			}
		}
		else if(oper == "*" || oper == "/"){
			if(next == "*" || next == "/"){
				mult_cnt++;
				post_fix();
				pop_append(oper, second);
			}
			else if(next == "+" || next == "-")
				pop_append(oper, second);
			else
				pop_append(oper, second);
			if(mult_cnt){ mult_cnt--; return; }
		}
	}
}

int 
main()
{
	scanf("%s", input);
	for(int i = 0; i < strlen(input); i++){
		string curr(1, input[i]);
		if(input[i] == ')')
			post_fix();
		else if(input[i] < 48)
			symbol.push(curr);
		else
			letter.push(curr);
	}
	post_fix();
	cout << letter.top() << "\n";
}
