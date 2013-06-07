#include <iostream>
#include <sstream>
#include <bitset>
#include <string>
#include <map>
#include <vector>
using namespace std;
template <size_t N>
struct BITSET: public bitset<N>{
public:
	bool operator<(const BITSET<N> &R) const{
		for(unsigned int i=0;i<this->size();i++)
			if(this->test(i)){
				if(!R.test(i))return false;
			}else{
				if(R.test(i))return true;
		}
		return false; //same
	}
};
typedef BITSET<4096> bs; //more than the number of lines (wc -l)
main(){
	map<string,bs>id_bits,name_bits;
	int i=0,idx;
	string line,sl,sr;
	for(;getline(cin,line);i++){
		idx=line.find("=");
		istringstream ssl(line.substr(0,idx)),ssr(line.substr(idx+1));
		for(;ssl>>sl,ssr>>sr;)id_bits[sl].set(i),name_bits[sr].set(i);
	}
	map<bs,pair<vector<string>,vector<string> > >table;
	map<string,bs>::iterator it;
	for(it=id_bits.begin();it!=id_bits.end();it++)table[it->second].first.push_back(it->first);
	for(it=name_bits.begin();it!=name_bits.end();it++)table[it->second].second.push_back(it->first);
	map<bs,pair<vector<string>,vector<string> > >::iterator it2;
	for(it2=table.begin();it2!=table.end();it2++){
		for(i=0;i<it2->second.first.size();i++)cout<<it2->second.first[i]<<' ';
		cout<<'=';
		for(i=0;i<it2->second.second.size();i++)cout<<' '<<it2->second.second[i];
		cout<<endl;
	}
}