#include "list.h"
#include "date.h"
int main(){
	List <int> ds;
	ds.Add(6);
	ds.Add(100);
	ds.Add(281);
	
	ds.Add(0);
	ds.Add(8);
	ds.Add(7);   
	ds.PrintAll();
	ds.Change(2, 32007);
	ds.PrintAll();

	//ds.Del(4);
	//ds.PrintAll();
	ds.Insert(1, 32014);
	ds.PrintAll();
	ds.Insert(ds.Count(), 32021);
	ds.Del(5);
	ds.PrintAll();

	//cout<<ds.Count(6)<<endl;
	return 0;
}