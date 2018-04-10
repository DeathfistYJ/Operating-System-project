#include<windows.h>
#include<stdio.h>
#include <bits/stdc++.h>
using namespace std;
char d[100]=" OS project for K1620 B26";

int i=0,j;

struct Processes
{
	int p_id;
	int b_time,ar_time;
	float priority;               /* to store the info of processes including the priority */
};
void process_waiting_time(Processes process[],int number_of_p,int waiting_time[])
{
		for(j=0;j<48;j++)
		{
		cout<<"+";
		}
		for(j=0;j<36;j++)
		{
		cout<<d[j];
		}
		for(j=0;j<48;j++)
		{
		cout<<"+";
		}
	for(int i=0;i<number_of_p;i++)
	{
		process[i].priority=-1.0;                  
	}
	int temp[number_of_p],value=0;
	int time=0,least_burst_time_OR_PRIORITY_P=0,exe=0,f_time,min_exe_time=INT_MAX;
	bool flag=false;bool next_if=false; 
	float temp_for_priority=-1.0;    
	
	for(int x=0;x<number_of_p;x++)
{
	temp[x]=process[x].b_time;           
}
	bool P_or_BT=false;
	while(exe!=number_of_p)
	{
		
		for(int x=0;x<number_of_p;x++)
		{
			if(process[x].ar_time<=time&&process[x].priority!=0)
			/*calculating  If it is not yet exe*/
			{          
			      
				process[x].priority=1+((time-process[x].ar_time)/(float)process[x].b_time);
				cout<<"\n "<<"\xB2"<<" priority of proceess "<<process[x].p_id<<" = "<<" 1 + (("<<time<<"-"<<process[x].ar_time<<")/running-time)"<< " ->"<<process[x].priority<<endl; 
			
			
			}
			
			
			if(process[x].priority>=temp_for_priority&&process[x].priority>1.5)
			{ /*If priority value has increased to more than 1.5 Than the process with the highest priority is exe*/
				temp_for_priority=process[x].priority;
				P_or_BT=true;
				min_exe_time=temp[x];
			least_burst_time_OR_PRIORITY_P=x;
				flag=true;
				next_if=true;     /*This is to make sure that the higher priority process should be exe instead of simple selecting the process with smaller burst time*/
			}
			
			if((process[x].ar_time<=time)&&(temp[x]<min_exe_time&&temp[x]>0)&&next_if==false)
			{/*If no process has very high priority or have same priority the they are exe on the basis of there burst time*/
				
				min_exe_time=temp[x];
			least_burst_time_OR_PRIORITY_P=x;
				flag=true;
			}
			
		}
				if(flag==false)
		{
			time++;
			continue;
		}
		if(P_or_BT==false)
		{
			cout<<"\n\n "<<"\xB2 "<<"Process will be sorted on the basis of burst time because priorities are either equal or not very high \n";
		}
		else
		{
			cout<<"\n\n "<<"\xB2 "<<"Process will be sorted on the basis of Priority  \n";
			P_or_BT=false;
		}
		cout<<"\n\n"<<" \xB2"<<" Selected Process priority ="<<temp_for_priority;
		value=temp[least_burst_time_OR_PRIORITY_P];
		time=time+value;;
        process[least_burst_time_OR_PRIORITY_P].priority=0;
		temp[least_burst_time_OR_PRIORITY_P]=0;
		min_exe_time=INT_MAX;
		temp_for_priority=-1.0;
		next_if=false;
		if(temp[least_burst_time_OR_PRIORITY_P]==0)
		{
		
			cout<<"\n\n\n "<<"\t\t\t"<<"\xB2\xB2\xB2 "<<"process : "<<process[least_burst_time_OR_PRIORITY_P].p_id<<" exe "<<"\xB2\xB2\xB2"<<endl;

			for(int i=0;i<40;i++)
			{
				cout<<"-";
			}
			cout<<"\n\n";
			
			exe++;
			f_time=time;
		             
			waiting_time[least_burst_time_OR_PRIORITY_P]=f_time-process[least_burst_time_OR_PRIORITY_P].b_time-process[least_burst_time_OR_PRIORITY_P].ar_time;
			
			
		}
		
		
	}
} 

void turn_around_time_of_process(Processes process[],int number_of_p,int waiting_time[],int turn_around_time[])
{
	for(int a=0;a<number_of_p;a++)
	{
		turn_around_time[a]=process[a].b_time+waiting_time[a];
		 
	}
}

void Average_time(Processes process[],int number_of_p)
{
	int waiting_time[number_of_p],turn_around_time[number_of_p];
	int total_waiting_time=0,Total_turnaround=0;      //int
	
	process_waiting_time(process,number_of_p,waiting_time);
	turn_around_time_of_process(process,number_of_p,waiting_time,turn_around_time);
	
		cout << " | Processes |"<< " | Burst time | "<< " | Waiting time | "<< " | Turn around time | "<< " | ARRIVAL TIME | \n";

	
	for(int x=0;x<number_of_p;x++)
	{
		total_waiting_time=total_waiting_time+waiting_time[x];
		Total_turnaround=Total_turnaround+turn_around_time[x];
		cout << "  " << process[x].p_id << " \t\t  "<< process[x].b_time << " \t\t   " << waiting_time[x]<< " \t\t   " << turn_around_time[x] << " \t\t\t   " <<process[x].ar_time << "\n";
	}
		for(int i=0;i<40;i++)
			{
				cout<<"-";
			}
			cout<<"\n\n";
		cout << "\n"<<"\xB2\xB2 "<<"Average waiting time : "<< (float)total_waiting_time / (float)number_of_p;
    	cout<<"\n\n";
		
		cout << "\n"<<"\xB2\xB2 "<<"Average turnaroundtime : "<< (float)Total_turnaround / (float)number_of_p<<"\n\n";

}
int main()
{
	string numbers[15]={" FIRST "," SECOND "," THIRD "," FOURTH "," FIFTH "," SIXTH "," SEVENTH "," EIGHT "," NINTH "," TENTH "," ELEVENTH "," TWELTH "," THIRTEENTH "," FOURTEENTH "," FIFTEENTH "};
char d[100]=" OS project for K1620 B26";

int i=0,j;

for(j=0;j<58;j++)
{
Sleep(15);
cout<<"\xB2";
}
for(j=0;j<36;j++)
{
Sleep(20);
cout<<d[j];
}
for(j=0;j<58;j++)
{
Sleep(15);
cout<<"\xB2";
}

	int No_of_processes;
	cout<<"\n"<<"\xB2\xB2"<<" Please Enter number of processes:\t ";
	cin>>No_of_processes;
	Processes process[No_of_processes];
	for(int i=0;i<No_of_processes;i++)
	{
		system("cls");
		
		for(j=0;j<48;j++)
		{
		cout<<"*";
		}
		for(j=0;j<36;j++)
		{
		cout<<d[j];
		}
		for(j=0;j<48;j++)
		{
		cout<<"*";
		}

		cout<<"\n\n\n\n"<<"\xB2\xB2"<<" Enter the process ID of -"<<numbers[i]<<" process : " ;
		cin>>process[i].p_id;
		cout<<"\n"<<"\xB2\xB2"<<" Enter the arrival time : ";
		cin>>process[i].ar_time;
		cout<<"\n"<<"\xB2\xB2"<<" Enter the burst time : ";
		cin>>process[i].b_time;
		process[i].priority=0;
	}
	system("cls");
		
	Average_time(process,No_of_processes);
	return 0;	
}