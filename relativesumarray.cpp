"""
Given two arrays arr1 and arr2, the elements of arr2 are distinct, and 
all elements in arr2 are also in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 
are the same as in arr2. Elements that do not appear in arr2 should be placed 
at the end of arr1 in ascending order.
"""

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> arr3;
        vector<int> ascending;
        int numtimes = 0;
        for(int i = 0; i < arr2.size(); i++){
            numtimes = count(arr1.begin(), arr1.end(), arr2[i]); //count number of times that appears
            //now insert the appropriate number into arr 3. 
            for(int j = 0; j < numtimes; j++){
                arr3.push_back(arr2[i]);
            }
        }
        //at this point we need to check for items in arr1 that aren't in arr2 and then push them in. 
        for(int k = 0; k < arr1.size(); k++){
            if(count(arr2.begin(), arr2.end(), arr1[k]) == 0){
                auto it = upper_bound(ascending.begin(), ascending.end(), arr1[k]); //1
                ascending.insert(it, arr1[k]);
            }
        }
        for(int i = 0; i < ascending.size(); i++){
            arr3.push_back(ascending[i]);
        }
        return arr3;
    }
};