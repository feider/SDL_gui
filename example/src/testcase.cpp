class Sup
{
public:
	void set_int(int bla) {this->mongo=bla;}
protected:
	int mongo;
};

class Inf: public Sup
{
public:
	void nerve()
	{
		Sup * temp = (Sup*) this;
		temp->set_int(5);
	}
};


int main()
{
	Inf * tmp = new Inf();

	tmp->nerve();

	return 0;
}





