#include<iostream>
#include<stack>
#include<vector>
#include<climits> // STD_MIN

void operator<< (std::ostream &Cout , std::vector<int> x){
    for(auto i : x) Cout<<i<<" ";
    Cout<<"\n";
    return;
}

std::vector<int> nsBruteForce(std::vector<int> &arr){
    
    for(int outer = 0 ; outer < arr.size(); outer++){
        int max = INT_MIN;
        for(int inner = outer+1; inner < arr.size(); inner++){
              if(arr[outer] >= arr[inner]) {
                max = arr[inner];
                arr[outer] = arr[inner];
              }
        }
        arr[outer] = max==INT_MIN?0:max;
    }
    
    return arr;
}

std::vector<int> nsOptimal(std::vector<int> &arr){
    
    std::stack<int> min;
    min.push(0);
    for(signed int x = arr.size()-1 ; x >= 0 ; x--){
        int temp = arr[x];
        while(min.top() > arr[x]) min.pop();
        arr[x] = min.top();
        min.push(temp);
    }
    
    return arr;
}


int main(){
    std::vector<int> arr;
    // std::cout<<nsBruteForce(arr);
    arr = {2,1,5,6,2,3};
    std::cout<<nsOptimal(arr);
    
}