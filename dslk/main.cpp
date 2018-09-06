#include "list.h"
#include "date.h"
int main(){
	List <int> ds;
	ds.Add(6);
	ds.Add(0);
	ds.Add(8);

	ds.Add(7);                                        
	ds.Del(2);
	ds.PrintAll();
	return 0;
}