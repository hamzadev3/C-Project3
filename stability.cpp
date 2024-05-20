#include <iostream>
using namespace std;

bool ok(int q[], int currentman){//purposely didnt abbreviate for easier practicing 
int mp[3][3]={0,2,1,0,2,1,1,2,0};
int wp[3][3]={2,1,0,0,1,2,2,0,1};

//test one, row test basically
for(int i=0; i<currentman; i++){
if(q[i]==q[currentman])
return false;
}

for(int i=0; i<currentman; i++){
if(mp[currentman][q[i]] /* q[i] is new woman */ < mp[currentman][q[currentman]]) /* mp[q[currentman]] is the current wife */ {
// basically above line is saying if current dude likes new woman more than current woman
// if so,enter next phase of loop
if(wp[q[i]][currentman] < wp[q[i]][i]){
// i represents new man here 
return false;
}
}
}
for(int i=0; i<currentman; i++){
if(mp[i][q[i]]>mp[i][q[currentman]]){
if(wp[q[currentman]][i]<wp[q[currentman]][currentman]){
return false;
}
}
}
return true;
}
void print(int q[]){
for(int i=0; i<3; ++i){
cout<<"Man: "<<i<<" --> Woman: "<<q[i]<<endl;
cout<<endl;
}
}
int main(){
int currentman=0;
int q[3]={};
q[currentman]=0; // current man and current woman both paired initialized at 0 before algorithm 
while(currentman!=-1){ // basic condition to allow this to run until all solutions are found 
currentman++; 
if(currentman>2){ // condition met to solve problem, when currentman passes tests and exceeds limit of 2 (3 men 0, 1, 2) 
print(q);
currentman--;
}
else{
q[currentman]=-1; // backtrack protocol in main, sets wife to -1 
}
while(currentman>=0){
q[currentman]++; // then starts adding, symbolize trying the next woman for the current man 
if(q[currentman]>2){ // if wife exceeds limit of 2 then index will go back 
currentman--;
} else if (ok(q,currentman)){ // if conditions are met, break out and move to next man  
break;
}
}
}
return 0;
}
