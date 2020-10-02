#include <iostream>
#include <time.h>
using namespace std;
class queue
{
private:
	int *info;
	int *prior;
	int size;
public:
	queue(int size)
	{
		this->size=size;
		info=(int*)malloc(size*sizeof(int));
		prior=(int*)malloc(size*sizeof(int));
	}
	void set_info()
	{
		for (int i=0;i<size;i++)
		{
			system("cls");
			cout<<"\n  Info ["<<i<<"] = ";
			cin>>info[i];
			prior[i]=rand()%100+1;
		}
	}
	void statistic()
	{
		int n,max;
		system("cls");
		cout<<"\n  Statistic\n"<<endl;
		while (size)
		{
			max=prior[0];
			for (int i=0;i<size;i++)
			{
				if (prior[i]>=max)
				{
					max=prior[i];
					n=i;
				}
			}
			time_t seconds;
			struct tm *curr_time;
			time(&seconds);
			curr_time=localtime(&seconds);
			cout<<"\n  Info : "<<info[n]<<"   Date/Time : "<<asctime(curr_time);
			for (int i=n;i<size;i++)
				prior[i]=prior[i+1];
			for (int i=n;i<size;i++)
				info[i]=info[i+1];
			size--;
			info=(int*)realloc(info,size*sizeof(int));
		    prior=(int*)realloc(prior,size*sizeof(int));
		}
	}
};
int main()
{
	srand(time(0));
	cout<<"\n  Size of queue : ";
	int size;
	cin>>size;
	queue X(size);
	X.set_info();
	X.statistic();
	return 0;
}