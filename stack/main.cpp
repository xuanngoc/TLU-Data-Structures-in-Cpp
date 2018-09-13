#include "stack.h"
#include <iostream>
using namespace std;

int main(){
	Stack<int> st;
	st.Push(3);
	st.Push(7);
	st.Push(4);

	cout<<st.Pop()<<endl;;
	cout<<st.Pop()<<endl;;
	cout<<st.Pop()<<endl;;
	cout<<st.isEmpty()<<endl;

	return 0;
}