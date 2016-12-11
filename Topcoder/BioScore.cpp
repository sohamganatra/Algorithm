#include <bits/stdc++.h>
using namespace std;

class BioScore{
    public:
	double maxAvg(vector<string> A){
		//construct the freq matrix
		string temp = "AA";
		map<string, int> freqMat;
		for(int i=0;i<A.size();i++){
			for(int j=i+1;j<A.size();j++){
				for(int k=0;k<A[i].size();k++){
					if(A[i][k] <= A[j][k]){
						temp[0] = A[i][k];
						temp[1] = A[j][k];
						freqMat[temp]++;						
					}else{
						temp[0] = A[j][k];
						temp[1] = A[i][k];
						freqMat[temp]++;
					}

				}
			}
		}

		vector<int> unequal;
		unequal.push_back(freqMat["AC"]);
		unequal.push_back(freqMat["AT"]);
		unequal.push_back(freqMat["AG"]);
		unequal.push_back(freqMat["CT"]);
		unequal.push_back(freqMat["CG"]);
		unequal.push_back(freqMat["GT"]);
		vector<int> equal;
		equal.push_back(freqMat["AA"]);
		equal.push_back(freqMat["TT"]);
		equal.push_back(freqMat["GG"]);
		equal.push_back(freqMat["CC"]);



		sort(unequal.begin(),unequal.end(),[](int i, int j){
			return (i > j);
		});
		int totalsumbase = 10 * (unequal[0] + unequal[1]) + (-10) * (unequal[3] + unequal[4] + unequal[5]);
 //       cout<<totalsumbase<<" tot ";
		int maxa = INT_MIN;
        // for all possible diagonal combos
		for(int i =1;i<=10;i++){
			for(int j=1;j<=10;j++){
				for(int k=1;k<=10;k++){
					for(int x=1;x<=10;x++){
//                     	cout<<" "<<i<<" "<<j<<" "<<k<<" "<<x<<" ";
						int sum = i + j + k + x;
						int third = 0;
						if( sum % 2 == 0){
 //                           cout<<sum<<" ";
							third = (20 - sum)/2; 
                            int totalsum = totalsumbase + (i * equal[0]) + (j*equal[1]) + (k*equal[2]) + (x*equal[3]) + (third * unequal[2]);
							//maxa = max(maxa,totalsum);
                        	if(maxa < totalsum){
                            //	cout<<maxa<<" m "<<totalsum<<" ";
                                maxa = totalsum;
                            }
                            //cout<<maxa<<" max is this\n";
                        }
					}
				}
			}
		}
       // cout<<" "<<maxa<<" final ";
		return maxa * 2.00/(A.size() *( A.size() - 1) );
	}
};