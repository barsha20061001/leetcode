class Solution {
public:
string lexGreaterPermutation(string s, string t) {
int c[26]={};
for(char x:s) c[x-'a']++;
string ans;
for(int i=0;i<t.size();i++){
int x=t[i]-'a';
if(c[x]){
c[x]--;
ans+=t[i];}
else{
for(int j=x+1;j<26;j++) if(c[j]){
ans+=char('a'+j);
c[j]--;
 for(int k=0;k<26;k++)
ans+=string(c[k],char('a'+k));
return ans;}
while(!ans.empty()){
int p=ans.back()-'a';
ans.pop_back();
c[p]++;
for(int j=p+1;j<26;j++) if(c[j]){
ans+=char('a'+j);
c[j]--;
for(int k=0;k<26;k++)
ans+=string(c[k],char('a'+k));
return ans;}}
 return "";}}
while(!ans.empty()){
int p=ans.back()-'a';
ans.pop_back();
c[p]++;
for(int j=p+1;j<26;j++) if(c[j]){
ans+=char('a'+j);
c[j]--;
for(int k=0;k<26;k++)
ans+=string(c[k],char('a'+k));
return ans; }}
return "";}
};