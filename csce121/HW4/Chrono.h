#include "std_lib_facilities_4.h"
namespace Chrono
{
	enum class Month 
	{
		jan = 1, feb, mar, apr, may, jun, july, aug, sep, oct, nov, dec
	};
	
	class Date
	{
	public:
			class Invalid{};
			
			Date(int y, Month m, int d);
			Date();
			
			int day() const {return d;}
			Month month() const {return m;}
			int year() const {return y;}
			
			void add_day(int n);
			void add_month(int n);
			void add_year(int n);
	private:
			int y;
			Month m;
			int d;
	};
	
	bool is_date(int y, Month m, int d);
	bool leapyear(int y);
	
	bool operator == (const Date& a, const Date& b);
	bool operator != (const Date& a, const Date& b);
	
	std::ostream& operator<<(ostream& os, const Date& d);
	
	std::istream& operator>>(istream& is, Date& dd);
	
	Date& operator++(Date& d);
	Date& operator++(Date& d, int);
}