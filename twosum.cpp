class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer;
        for(int i; i < nums.size(); i++){
            for(int j; j < nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    answer.push_back(i);
                    answer.push_back(j);
                    break;
                }
            }
        }
        return answer;
    }
    //this is a brute force solution and will cost o(n)^2 time due to the double
    //for loops. Inefficient but it works. 

//The hash map solution with key value pairings. 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Keys are the array values and values are the associated array indices
        unordered_map<int, int> hash; // Use as a hash table, instead of creating one
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
            if (hash.count(target - nums[i])) // If the partner of this value to reach the target sum has been saved already
            {
                result.push_back(hash[target - nums[i]]); // Get index of other value
                result.push_back(i);
                return result;
            }
            else // Pair has not yet been found, so save value to hash table
                hash[nums[i]] = i;
        return result;
    }
};