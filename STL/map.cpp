/*
    map is key value structure
    keys are unique form eachother

*/

#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main()
{
    map<string, int> m;
    m["tv"] = 100;
    m["laptop"] = 300;
    m["headphone"] = 100;
    m["tablet"] = 200;
    m["watch"] = 50;

    for(auto p: m)
    {
        cout<<p.first<<" " << p.second << endl;
        /*
        headphone 100
        laptop 300
        tablet 200
        tv 100
        watch 50   // this prints sorted in ascending manner by keys
        */
    }

    m.insert({"camera", 25});
    m.emplace("box",500);      // syntax change in emplace

    m.count("laptop"); // it does not count accurance of key
    // it return 1 if ley exist    otherwise 0

    m.erase("tv");  // removes tv

    // aslo map have m.size()


    // m.find(key) if true it return iterator so in cout have to dereference
    //             if false it return end

    auto c=m.find("camera");
    cout<<(*c).first<<" "<< (*c).second;  // camera 25

    if(m.find("camera")!= m.end())
    {
        cout<<"exist";
    }
    else{
        cout<<"not found";
    }   // exist


    /*
    Multi map: can have duplicate keys
    */
   multimap<string, int> m1;  
   m1.insert({"tv",1});  // cant add like map m[key] = value
   m1.emplace("tv",1);
   m1.insert({"tv",1});
   m1.insert({"tv",1});

   // will ahve 4 keys         if it was map we will have only 1 key

   m1.erase("tv"); // by this whole multimap beco,e empty bcz all are tv
   m1.erase(m1.find("tv")); // only one delte     remains 3

    /*
     most used::   Unordered map:data stores randomly instead sorted 
    keys cant be duplicated
    */

    unordered_map<string, int> m2;
    m2.insert({"tv",1});
    m2.emplace("tv",1);
    m2.insert({"tv",1});

    /*
    differnce in map and unordered map
    in map insert,erase,count use O(logn) tc
    in unordered map has O(1)

    */
}