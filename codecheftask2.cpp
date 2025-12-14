#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


int main() {
    int t {};
    std::cin >> t;
    while(t--) {
        int n {};
        std::cin >> n;
        std::vector<int> a(n);
        
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        
        std::sort(a.begin(), a.end());
        
        bool found = false;
        for(int i =0; i < n-1;i++){
            if(a[i] == a[i+1]) {
                found = true;
                break;
            }
        }
        if(found) {
            std::cout << "YES\n";
        }
        else {
            std::cout << "NO\n";
        }
    
    
    
  }
return 0;    
    
}