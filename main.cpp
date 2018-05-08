#include <climits>
#include <iostream>
#include<stdlib.h>
#define MAX 100
#define v 100
using namespace std;
int flag;
struct node
{
    bool includeset;
    int finaldist;
    int pred;

};
struct node nodearray[v];
/*int dijkstra(int * ,int ,int);
int initialize_single_source(struct node *,int,int);
int extract_min(struct node * ,int);*/
int initialize_single_source(struct node nodearray[],int source,int vertices)
{

    for(int i=0; i<vertices; i++)
    {
        nodearray[i].includeset=false;
        nodearray[i].pred=INT_MIN;
        nodearray[i].finaldist=INT_MAX;


    }


    flag=vertices;
    nodearray[source].pred=-1;
    nodearray[source].finaldist=0;
    return flag;

}
int extract_min(struct node nodearray[],int vertices)
{
    int mindist, x;
    for(x=0; x<vertices; x++)
    {
        if(nodearray[x].includeset==false)
        {
            break;
        }
    }
    mindist=x;
    //cout<<"mindist1="<<mindist<<endl;
    for(int i=x+1; i<vertices; i++)
    {
        if(nodearray[i].includeset==false && nodearray[i].finaldist<nodearray[mindist].finaldist)
        {
            mindist=i;
            //cout<<"mindist="<<mindist<<endl;
        }


    }
    //cout<<"\nfinal mindist="<<mindist<<endl;
    return mindist;

}


void  dijkstra(int arrk[v][v],int source,int vertices)
{
    flag=initialize_single_source(nodearray,source,vertices);
    int count = 0,mincost;

    while( flag!=0)
    {
        int p=extract_min(nodearray,vertices);

        nodearray[p].includeset=true;
        flag--;
       // cout<<"\nincluded vertex"<<p<<endl;
        count++;
        for(int j=1; j<vertices; j++)
        {

            if(arrk[p][j]!=0 && nodearray[j].includeset==false)
            {

                if(nodearray[j].finaldist> arrk[p][j])
                {

                    nodearray[j].finaldist =  arrk[p][j];
                    nodearray[j].pred = p;
                    //cout<<"updated dist= "<<arrk[p][j]<<"vertex= "<<j<<endl;
                }
            }

        }
    }

cout<<"Edge "<<1<<"\t";
        cout<<"Edge between "<<0<<"and "<<0;
        cout<<nodearray[0].finaldist<<endl;



    for(int i=1; i<vertices; i++)
    {
        cout<<"Edge "<<i+1<<"\t";
        cout<<"Edge between "<<i<<"and "<<nodearray[i].pred<<"=";
        cout<<nodearray[i].finaldist<<endl;

    }




}



int main()
{

    int i=0;

    int so;

    int vp;

    int arrk[MAX][MAX],e;
    cout<<"enter the number of vertices(undirected graph)"<<endl;
    cin>>vp;
    cout<<"enter the number of edges"<<endl;
    cin>>e;
    if(vp<=0 || e<=0)
    {
        cout<<"\ninvalid input";
        return 0;
    }
    for(int i=0; i<vp; i++)
    {
        for(int j=0; j<vp; j++)
        {
            if(i!=j)
            {
                cout<<"Enter the edge length between "<<i<<" and "<<j<<" ";
                cin>>arrk[i][j];
            }
            else arrk[i][j]=0;

        }
    }

    cout<<"output matrix is ---->"<<endl;
    for(i=0; i<vp; i++)
    {
        for(int j=0; j<vp; j++)
        {

            cout<<"\t"<<arrk[i][j];

        }
        cout<<endl;
    }

    cout<<"enter source";
    cin>>so;
  cout<<"\nThe MST is -\n";
    dijkstra(arrk,so,vp);






    return 0;
}
