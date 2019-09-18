#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

#define pi 3.1415926535
#define radio 6378137.0

//defining a new struct for the convenience of calculating
typedef struct
{
    long double Longitude;
    long double Lantitude;
    string East_or_West;
    string North_or_South;
} dot;
//function for calculating
int Distance(float lat1, float lon1, float lat2, float lon2)
{
    double latitude1,longitude1,latitude2,longitude2;
    double dlat,dlon;
    latitude1=lat1;
    longitude1=lon1;
    latitude2=lat2;
    longitude2=lon2;
    //computing procedure
    double a,c,distance;
    dlon =fabs((longitude2 - longitude1))*pi/180;
    dlat =fabs((latitude2 - latitude1))*pi/180;
    a = (sin(dlat/2)*sin(dlat/2)) + cos(latitude1*pi/180) * cos(latitude2*pi/180) * (sin(dlon/2)*sin(dlon/2));
    if(a==1.0)
        c=pi;
    else
        c = 2 * atan(sqrt(a)/sqrt(1-a));
    distance= radio*c;

    return distance;
}
int main()
{
    double t=tan(54*pi/180.0);
    double s=0.5*t*1/2*5;
    cout<<s<<endl;
    long double r = 6371.004;
    dot a, b;
    //freopen("D:\example.txt","r",stdin);
    while(1)
    {
        cout<<"Please input the two dots' coordinates like the following format: "<<endl;
        cout<<"East 30 North 20"<<"West 40 North 10"<<endl;
        //data input procedure
        cin>>a.East_or_West>>a.Longitude>>a.North_or_South>>a.Lantitude;
        cin>>b.East_or_West>>b.Longitude>>b.North_or_South>>b.Lantitude;
        //transfer
        {
            if(a.East_or_West == "East")
            {
                a.Longitude = a.Longitude;
            }
            else if(a.East_or_West == "West")
            {
                a.Longitude = - a.Longitude;
            }
        }
        {
            if(a.North_or_South == "North")
            {
                a.Lantitude = pi / 2 - a.Lantitude;
            }
            else if (a.North_or_South == "South")
            {
                a.Lantitude = pi / 2 + a.Lantitude;
            }
        }
        {
            if(b.East_or_West == "East")
            {
                b.Longitude = b.Longitude;
            }
            else if(a.East_or_West == "West")
            {
                b.Longitude = - b.Longitude;
            }
        }
        {
            if(a.North_or_South == "North")
            {
                b.Lantitude = pi / 2 - b.Lantitude;
            }
            else if (a.North_or_South == "South")
            {
                b.Lantitude = pi / 2 + b.Lantitude;
            }
        }
        //data output procedure
        float result = Distance(a.Lantitude, a.Longitude, b.Lantitude, b.Longitude);
        cout<<"The distance is: "<<result<<endl<<endl;
    }
}
