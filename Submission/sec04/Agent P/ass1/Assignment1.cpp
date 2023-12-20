#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

class Candidate
{
    string name,faculty,phone,ic,matric;
    int age,voteCount;

    public:
        Candidate(){}
        Candidate(string n,string f,int a,string ic,string p,int v,string m)
        {
            name = n;
            faculty = f;
            age = a;
            this->ic = ic;
            phone = p;
            voteCount = v;
            matric = m;
        }

        string getName(){return name;}
        string getFaculty(){return faculty;}
        int getAge(){return age;}
        int getVoteCount(){return voteCount;}
        string getIC(){return ic;}
        string getPhone(){return phone;}
        string getMatric(){return matric;}
};

void NameAscending(Candidate c[],int size)
{
    Candidate temp;
    for(int last=size-1;last>=1;last--)
    {
        int largeIndex = 0;

        for(int x=1;x<=last;x++)
        {
            if(c[x].getName()>c[largeIndex].getName())
                largeIndex = x;
        }

        //cout<<c[largeIndex].getName()<<endl;
        Candidate temp = c[largeIndex];
        c[largeIndex] = c[last];
        c[last] = temp;
    }
}

void NameDescending(Candidate c[],int size)
{
    Candidate temp;
    for(int last=size-1;last>=1;last--)
    {
        int smallIndex = 0;

        for(int x=1;x<=last;x++)
        {
            if(c[x].getName()<c[smallIndex].getName())
                smallIndex = x;
        }

        //cout<<c[smallIndex].getName()<<endl;
        Candidate temp = c[smallIndex];
        c[smallIndex] = c[last];
        c[last] = temp;
    }
}

void SearchingName(Candidate c[],int size)
{
    string key;
    bool found = false;
    cout<<"Please enter the name you want to search for : ";
    cin>>key;
    for(int i=0;i<key.size();i++)
    {
        key[i] = tolower(key[i]);
    }

    for(int i=0;i<size;i++)
    {
        found = false;
        string name = c[i].getName();

        for(int i=0;i<name.size();i++)
        {
            name[i] = tolower(name[i]);
        }

        if(name == key)
        {
            cout<<"\nRecord Found!    "<<endl;
            cout<<"-------------"<<endl;
            cout<<"Name           : "<<c[i].getName()<<endl;
            cout<<"Faculty        : "<<c[i].getFaculty()<<endl;
            cout<<"IC             : "<<c[i].getIC()<<endl;
            cout<<"Age            : "<<c[i].getAge()<<endl;
            cout<<"Vote Collected : "<<c[i].getVoteCount()<<endl;
            cout<<"Phone number   : "<<c[i].getPhone()<<endl;
            cout<<"Matric Number  : "<<c[i].getMatric()<<endl;
            found = true;
        }
        else 
            found = false;
    }

    if(found == false)
        cout<<"Data not found!"<<endl;
}

void FacultyAscending(Candidate c[],int size)
{
    Candidate temp;
    bool sorted=false;

    for(int pass=1;(pass<size)&&!sorted;pass++)
    {
        sorted = true;
        for(int j=0;j<size-pass;j++)
        {
            if(c[j].getFaculty() > c[j+1].getFaculty())
            {
                temp = c[j];
                c[j] = c[j+1];
                c[j+1] = temp;
                sorted = false;
            }
        }
    }
}

void FacultyDescending(Candidate c[],int size)
{
    Candidate temp;
    bool sorted=false;

    for(int pass=1;(pass<size)&&!sorted;pass++)
    {
        sorted = true;
        for(int j=0;j<size-pass;j++)
        {
            if(c[j].getFaculty() < c[j+1].getFaculty())
            {
                temp = c[j];
                c[j] = c[j+1];
                c[j+1] = temp;
                sorted = false;
            }
        }
    }
}

void SearchingFaculty(Candidate c[],int size)
{
    string key;
    bool found = false;
    cout<<"Please enter the faculty you want to search for : ";
    cin>>key;

    for(int i=0;i<key.size();i++)
    {
        key[i] = tolower(key[i]);
    }

    for(int i=0;i<size;i++)
    {
        string faculty = c[i].getFaculty();

        for(int i=0;i<faculty.size();i++)
        {
            faculty[i] = tolower(faculty[i]);
        }
        if(faculty == key)
        {
            cout<<"\nRecord Found! "<<endl;
            cout<<"Name           : "<<c[i].getName()<<endl;
            cout<<"Faculty        : "<<c[i].getFaculty()<<endl;
            cout<<"IC             : "<<c[i].getIC()<<endl;
            cout<<"Age            : "<<c[i].getAge()<<endl;
            cout<<"Vote Collected : "<<c[i].getVoteCount()<<endl;
            cout<<"Phone number   : "<<c[i].getPhone()<<endl;
            cout<<"Matric Number  : "<<c[i].getMatric()<<endl;
            found = true;
        }
        else 
            found = false;
    }

    if(!found)
        cout<<"Data not found!"<<endl;
}

void swap(int &d1, int &d2)
    {
        int temp = d1;
        d1 = d2;
        d2 = temp;
    }
 
    void ICAscend(Candidate D[],int n)
    {
        for(int last=n-1; last>=1; --last){

        int largesti=0;

        for(int p=1; p<=last; ++p)
        { 
            if(D[p].getIC() > D[largesti].getIC())
                largesti=p;
        }

        swap(D[largesti],D[last]);
        }
        
        
    }
    
    void ICDescend(Candidate D[], int n){
    	for(int last=n-1; last>=1; --last){

        int largesti=0;

        for(int p=1; p<=last; ++p)
        { 
            if(D[p].getIC() < D[largesti].getIC())
                largesti=p;
        }

        swap(D[largesti],D[last]);
         
        }
    
}

void VoteCountAscend(Candidate D[] , int n){
		Candidate item;
		int pass, insertIndex;
	for (pass=1; pass<n; pass++)
	{
		item = D[pass];
		insertIndex = pass;
	while((insertIndex > 0) && (D[(insertIndex -1)].getVoteCount() > item.getVoteCount()))
	{
		D[insertIndex]= D[insertIndex -1];
		insertIndex --;
	}
		D[insertIndex] = item;
	}

}

	void VoteCountDescend(Candidate D[] , int n){
		Candidate item;
    	int pass, insertIndex;
    for(pass=1;pass<n;pass++)
	{
        item = D[pass];
        insertIndex = pass;
        while((insertIndex>0)&&(D[(insertIndex-1)].getVoteCount()<item.getVoteCount()))
		{
            D[insertIndex]=D[insertIndex-1];
            insertIndex--;
        }
        D[insertIndex]=item;
    }
    
}

void searchingVoteCount(Candidate c[],int size){
    int key;
    bool check = false;
    cout<<"Please enter the vote count of the Candidate you want to search for : ";
    cin>>key;

    for(int i=0;i<size;i++){
        if(c[i].getVoteCount()== key){
            cout<<"\nRecord Found! "<<endl;
            cout<<"Name           : "<<c[i].getName()<<endl;
            cout<<"Faculty        : "<<c[i].getFaculty()<<endl;
            cout<<"IC             : "<<c[i].getIC()<<endl;
            cout<<"Age            : "<<c[i].getAge()<<endl;
            cout<<"Vote Collected : "<<c[i].getVoteCount()<<endl;
            check = true;
            break;
        }
    }
    if(!check){
    	cout <<"Sorry no record is found" << endl;
	}
}

void searchingIC(Candidate c[],int size){
    string key;
    bool check = false;
    cout<<"Please enter the IC of the Candidate you want to search for : ";
    cin>>key;

    for(int i=0;i<size;i++){
        if(c[i].getIC() == key){
        	check = true;
            cout<<"\nRecord Found! "<<endl;
            cout<<"Name           : "<<c[i].getName()<<endl;
            cout<<"Faculty        : "<<c[i].getFaculty()<<endl;
            cout<<"IC             : "<<c[i].getIC()<<endl;
            cout<<"Age            : "<<c[i].getAge()<<endl;
            cout<<"Vote Collected : "<<c[i].getVoteCount()<<endl;
            break;
        }
        
    }
    if(!check){
    	cout <<"Sorry no record is found" << endl;
	}
}

void menu(int &opt1,int &opt2,int &opt3)
{
    do{
    cout<<"[1] Sort \n[2] Search"<<endl;
    cout<<"You want to do sorting or searching : ";
    cin>>opt1;
    cout<<endl;
    }while(opt1<1 || opt1>3);
    
    switch(opt1)
    {
        case 1 : do{
                 cout<<"[1] Name \n[2] Faculty \n[3] IC \n[4] Age \n[5] ID \n[6] Vote Count"<<endl;
                 cout<<"Please choose the sorting category : ";
                 cin>>opt2;
                 cout<<endl;
                 }while(opt2<1 || opt2>6);
                 do{
                    cout<<"[1] Ascending Order \n[2] Descending Order"<<endl;
                    cout<<"You want ascending or desending order : ";
                    cin>>opt3;
                    cout<<endl;
                }while(opt3<1 || opt3>2);
                 break;
        case 2 : do{
                 cout<<"[1] Name \n[2] Faculty \n[3] IC \n[4] Age \n[5] ID \n[6] Vote Count"<<endl;
                 cout<<"Please choose the searching category : ";
                 cin>>opt2;
                 cout<<endl;
                 }while(opt2<1 || opt2>6);
                 break;

    }

    
    
}
void display(Candidate c[],int size)
{
    cout<<"--------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"|       Name       "<<" | "<<"      Faculty      "<<" | "<<"      IC     "<<" | "<<"   Age  "<<" | "<<"   Matric Number  "<<" | "<<"  Vote Count  "<<" | "<<"Phone Number"<<" | "<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------------------"<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<left<<"|  "<<setw(16)<<c[i].getName()<<" |       "<<setw(13)<<c[i].getFaculty()<<" |  "<<setw(8)<<c[i].getIC()<<" |     "<<setw(4)<<c[i].getAge()<<" |    "<<setw(16)<<c[i].getMatric()<<"|       "<<setw(9)<<c[i].getVoteCount()<<"|  "<<setw(10)<<c[i].getPhone()<<"  |"<<endl;
        cout<<"--------------------------------------------------------------------------------------------------------------------------"<<endl;
}
}

int main()
{
    Candidate c[10];
    ifstream in("cand.csv");
    string name,faculty,phone,ic,matric;
    int id,age,vote;
    int i = 0;

    if(!in){
        cout<<"File cannot be opened!"<<endl;
        return 0;
    }
    
    //Reading from the file
    getline(in,name,',');
    while(!in.eof())
    {
        getline(in,faculty,',');
        in>>age;
        in.ignore();
        getline(in,ic,',');
        getline(in,phone,',');
        in>>vote;
        in.ignore();
        getline(in,matric,'\n');
        c[i] = Candidate(name,faculty,age,ic,phone,vote,matric);
        getline(in,name,',');
        i++;
    }



    int opt1,opt2,opt3; //Storing user selection options
    menu(opt1,opt2,opt3); //User interface for the menu
    

   switch(opt1)
    {
        case 1:
            switch(opt2)
            {
                case 1 : if(opt3 == 1)
                            NameAscending(c,i);
                         else
                            NameDescending(c,i);
                        display(c,i);
                        break;
                case 2: if(opt3 == 1)
                            FacultyAscending(c,i);
                         else
                            FacultyDescending(c,i);
                        display(c,i);
                        break;
                case 3: if(opt3 == 1)
                            ICAscend(c,i);
                         else
                            ICDescend(c,i);
                        display(c,i);
                        break;
                case 4 : if(opt3==1)
                            AgeAsc(c,i);
                         else
                            AgeDes(c,i);
                        display(c,i);
                        break;
                case 5 : if(opt3==1)
                            MatAsc(c,i);
                         else
                            MatDes(c,i);
                        display(c,i);
                        break;
                case 6 : if(opt3==1)
                            VoteCountAscend(c,i);
                         else
                            VoteCountDescend(c,i);
                        display(c,i);
                        break;

            }
            break;
        
        case 2:
            switch(opt2)
            {
                case 1: SearchingName(c,i);
                        break;
                case 2: SearchingFaculty(c,i);
                        break;
                case 3: searchingIC(c,i);
                        break;
                case 4: searchingAge(c,i);
                        break;
                case 5: searchingMat(c,i);
                        break;
                case 6: searchingVoteCount(c,i);
                        break;
            }
            break;
    }
    


    //display(c,3); //Displaying the candidates of election
    return 0;
}
