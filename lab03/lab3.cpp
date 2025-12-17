#include <iostream>
using namespace std;

class modInt
{
private:
	int value,mod;

public:
	modInt(){
		value = 1;
		mod = 2;
	}

	modInt(int l, int m){
		value = l;
		mod = m;
	}

	int getValue() const{ return value; }
    int getMod() const{ return mod; }

    void operator +=(const modInt& rhs)
	{
		value = value + rhs.value;

		if(mod!= rhs.mod)
		{
			mod = -1;
			value= -1;
		}
	}
	//this is because you are changing the direct value of self 

};

bool operator ==(const modInt& lhs, const modInt& rhs)
{
	if(lhs.getValue() == rhs.getValue() && lhs.getMod() == rhs.getMod())
		return true;
	return false;
}

bool operator <(const modInt& lhs, const modInt& rhs)
{
	if(lhs.getValue() < rhs.getValue() && lhs.getMod() == rhs.getMod())
		return true;
	return false;
}

bool operator >(const modInt& lhs, const modInt& rhs)
{
	return(lhs.getValue() > rhs.getValue() && lhs.getMod() == rhs.getMod());
}

modInt operator +(const modInt& lhs,const modInt& rhs){
	modInt total(lhs.getValue(), lhs.getMod());
	total += rhs;
	return modInt(total.getValue(), total.getMod());
}

int main()
{
	modInt playlist1(179,180);
    cout<<"modded value: "<<playlist1.getValue()%playlist1.getMod()<<endl;

    modInt playlist2(179,180);

    if(playlist1 == playlist2)
    	cout<<"yes"<<endl;
    else
    	cout<<"no"<<endl;

    playlist1 += playlist2;
    cout<<playlist1.getValue()<<endl;

    modInt playlist3 = playlist1 + playlist2;
    cout<<playlist3.getValue()<<playlist3.getMod()<<endl;

    return 0;
}