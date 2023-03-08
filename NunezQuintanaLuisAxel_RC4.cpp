
#include <bits/stdc++.h>

using namespace::std;

int main(int argc, char *argv[])
{
	int i = 0, j = 0, n1 = 0, m = 0, s[256], n2 = 0, aux = 0;
	string k, pt;
	
	getline(cin >> ws, k);
	getline(cin>> ws, pt);
	
	n1 = k.length();
	n2 = pt.length();
	
	int r[n2];
	
	for(i = 0; i < 256; i++){
		s[i] = i;
	}
	
	cout << endl;
	
	for(i = 0; i < 256; i++){
		j = (j + s[i] + k[i % n1]) % 256;
		aux = s[i];
		s[i] = s[j];
		s[j] = aux;
	}
	
	i = 0;
	j = 0;
	m = 0;
	
	for(m = 0; m < n2; m++){
  	  i = (i + 1) % 256;
  	  j = (j + s[i]) % 256;
	  aux = s[i];
	  s[i] = s[j];
	  s[j] = aux;
	  aux = s[(s[i] + s[j]) % 256 ];
	  r[m] = aux ^ pt[m];
	  //cout << hex << aux;
	}
	
	//cout << endl;
	
	for(i = 0; i < n2; i++){
	  cout << uppercase << hex << r[i];
	}
	cout << endl;
	
	return 1;
}