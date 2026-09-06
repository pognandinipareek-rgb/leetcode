class Solution {
public:
    int minimumOperations(vector<int>& a) {
        int n=a.size(), res =n;
        for(int i=0;i<=n;i++){
            for(int j=i;j<=n ;j++){
                int curr=0;
                for(int k=0;k<n;k++){
                    if(k<i){
                        curr+=a[k]!=1;

                    }else if(k<j){
                        curr+=a[k]!=2;

                    }else {
                        curr+=a[k]!=3;

                    }

                }
                res=min(res,curr);


            }
        }
        return res;
    }
};