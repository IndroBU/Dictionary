#include<bits/stdc++.h>
using namespace std;
int Fun(string s1, string s2)
{

    int l1,l2,i,j;
    l1=s1.size();
    l2=s2.size();
    int EditDis[l2+1][l1+1];
    for(i=1; i<=l2; i++) EditDis[i][0]=i;
    for(i=0; i<=l1; i++) EditDis[0][i]=i;

    for(i=1; i<=l2; i++)
    {
        for(j=1; j<=l1; j++)
        {
            if(s2[i-1]==s1[j-1]) EditDis[i][j] =EditDis[i-1][j-1];

            else
                EditDis[i][j]=min(EditDis[i-1][j-1],min(EditDis[i-1][j],EditDis[i][j-1]))+1;
        }
    }

    return EditDis[l2][l1];

}
int main()
{
  string s1,s2;
  ifstream myfile1 ("Dictionary.txt");
  ifstream myfile2 ("Dictionary.txt");
  ifstream myfile3 ("Dictionary.txt");
  ifstream myfile4 ("Dictionary.txt");
  ifstream myfile5 ("Dictionary.txt");

  ifstream ifile("file.txt", ios::in);
    ofstream ofile("dictionary.txt", ios::out | ios::app);

  getline(cin,s1);

  int l=s1.size();
  bool flag1;
  for(int i=0; i<l; i++)
  {
      s1[i]=tolower(s1[i]);
  }

  if(myfile1.is_open())
  {

        int l=s1.size();

        while(getline(myfile1,s2))
        {

             if(Fun(s1,s2)==0)
             {
                 cout<<s2<<endl;
                 flag1=true;

                 break;
             }

        }
            myfile1.close();

  }
  if(myfile2.is_open())
  {


        int l=s1.size();

        while(getline(myfile2,s2))
        {

             if(Fun(s1,s2)==1 && s1[0]==s2[0])
             {
                 cout<<s2<<endl;
                 break;
             }

        }
            myfile2.close();

   }
   if(myfile3.is_open())
    {


        int l=s1.size();

        while(getline(myfile3,s2))
        {

             if(Fun(s1,s2)==2 && s1[0]==s2[0])
             {
                 cout<<s2<<endl;
                 break;
             }

        }
            myfile3.close();

    }
    if(myfile4.is_open())
    {


        int l=s1.size();

        while(getline(myfile4,s2))
        {

             if(Fun(s1,s2)==3 && s1[0]==s2[0])
             {
                 cout<<s2<<endl;
                 break;
             }

        }
            myfile4.close();

    }
    if(myfile5.is_open())
    {


        int l=s1.size();

        while(getline(myfile5,s2))
        {

             if(Fun(s1,s2)==4 && s1[0]==s2[0])
             {
                 cout<<s2<<endl;
                 break;
             }

        }
            myfile5.close();

    }
    if(flag1==false)
    {
        cout<<"Do you want to add this word in dictionary? yes : no"<<endl;
        string s;
        cin>>s;
        for(int i=0; i<s.size(); i++)
        {
            s[i]=tolower(s[i]);
        }
        if(s=="yes")
        {

           if(ifile.is_open())
           {

            ofile <<endl<<s1;

           }

        }
    }


    return 0;
}

