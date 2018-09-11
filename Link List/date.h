class Date
{
public:
	Date():d(1), m(1), y(2000){};
	Date(int day, int month, int year): d(day), m(month), y(year){}

	friend ostream & operator <<(ostream &out, Date const & d){
		out<<d.d<<"-"<<d.m<<"-"<<d.y<<endl;
	}
private:
	int d;
	int m;
	int y;		
};