//http://blog.csdn.net/pointbreak1/article/details/46369559
class Solution {  
public:  
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {  
        vector<pair<int, int>> results;  
        if (buildings.size() == 0)  
            return results;  
        if (buildings.size() == 1) {  
            results.push_back(pair<int, int>(buildings[0][0], buildings[0][2]));  
            results.push_back(pair<int, int>(buildings[0][1], 0));  
            return results;  
        }  
          
        vector<pair<int, int>> left = divide(0, (buildings.size() - 1) / 2, buildings);  
        vector<pair<int, int>> right = divide((buildings.size() - 1) / 2 + 1, buildings.size() - 1, buildings);  
        results = conquer(left, right);  
        return results;  
    }  
      
    vector<pair<int, int>> divide(int start, int end, vector<vector<int>>& buildings) {  
        if (start == end) {  
            vector<pair<int, int>> result;  
            result.push_back(pair<int, int>(buildings[start][0], buildings[start][2]));  
            result.push_back(pair<int, int>(buildings[start][1], 0));  
            return result;  
        }  
        int mid = (end + start) / 2;  
        vector<pair<int, int>> left = divide(start, mid, buildings);  
        vector<pair<int, int>> right = divide(mid + 1, end, buildings);  
        vector<pair<int, int>> result = conquer(left, right);  
        return result;  
    }  
      
    vector<pair<int, int>> conquer(vector<pair<int, int>>& left, vector<pair<int, int>>& right) {  
        vector<pair<int, int>> result;  
        int i = 0, j = 0, h1 = 0, h2 = 0;  
        int maxH = max(h1, h2);  
        while (i != left.size() && j != right.size()) {  
            if (left[i].first < right[j].first) {  
                h1 = left[i].second;  
                if (maxH != max(h1, h2))  
                    result.push_back(pair<int, int>(left[i].first, max(h1, h2)));  
                maxH = max(h1, h2);  
                i++;  
            }  
            else if (left[i].first > right[j].first) {  
                h2 = right[j].second;  
                if (maxH != max(h1, h2))  
                    result.push_back(pair<int, int>(right[j].first, max(h1, h2)));  
                maxH = max(h1, h2);  
                j++;  
            } else {  
                if(left[i].second >= right[j].second) {  
                    h1 = left[i].second;  
                    h2 = right[j].second;  
                    if(maxH != max(h1, h2))  
                        result.push_back(pair<int, int>(left[i].first, left[i].second));  
                    maxH = max(h1, h2);  
                    i++;  
                    j++;  
                } else {  
                    h1 = left[i].second;  
                    h2 = right[j].second;  
                    if(maxH != max(h1, h2))  
                       result.push_back(pair<int, int>(right[j].first, right[j].second));  
                    maxH = max(h1, h2);  
                    i++;  
                    j++;                      
                }  
            }  
              
        }  
          
        while (j < right.size()) {  
            result.push_back(right[j]);  
            j++;  
        }  
          
        while (i != left.size()) {  
            result.push_back(left[i]);  
            i++;  
        }  
        return result;  
    }  
      
};  
