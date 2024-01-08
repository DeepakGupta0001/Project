#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;
class node{
    public : string key;
    int value;
    node(string key,int value){
        this->key=key;
        this->value=value;
    }
};

class lrucache {
    public : int maxsize;
    list<node>l;
    unordered_map<string,list<node>::iterator>m;
lrucache(int maxsize){
    this->maxsize=maxsize>1 ? maxsize : 1;
}
void insertkeyvalue(string key , int value){
    if(m.count(key)!=0){auto it=m[key];
    it->value=value;
    }
    else{
        if(l.size()==maxsize){
            node last=l.back();
            m.erase(last.key);
            l.pop_back();}
            node n(key,value);
            l.push_front(n);
            m[key]=l.begin();
        
    }
}
int* getvalue(string key){
    if(m.count(key)!=0){
auto it=m[key];
int value=it->value;
l.push_front(*it);
l.erase(it);
m[key]=l.begin();
return &l.begin()->value;

    }
    return NULL;
}

string mostrecentkey(){
return l.front().key;

}
};

int main(){
    lrucache lru(3);
    lru.insertkeyvalue("mango",10);
    lru.insertkeyvalue("apple",20);
    lru.insertkeyvalue("guava",30);
cout<<lru.mostrecentkey()<<endl;
lru.insertkeyvalue("mango",40);
cout<<lru.mostrecentkey()<<endl;
int *order=lru.getvalue("mango");
if(order!=NULL){
    cout<<"order of mango : "<<*order<<endl;

}
lru.insertkeyvalue("banana",20);
if(lru.getvalue("apple")==NULL){
    cout<<"apple does not exist";
}

if(lru.getvalue("guava")==NULL){
    cout<<"guava does not exist";
}

if(lru.getvalue("banana")==NULL){
    cout<<"banana does not exist";
}


if(lru.getvalue("mango")==NULL){
    cout<<"mango does not exist";
}
}