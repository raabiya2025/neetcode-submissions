class Solution {
public:
    int maxArea(vector<int>& height) {
        int left,right,width=0,heightt,area;
        int n=height.size();
        //NO SORTING OF ARRAY
        left=0;
        right=n-1;int maxx=0;
        while(left<right){
            width=right-left;
            heightt=min(height[left],height[right]);
            area=heightt*width;
            if(area>maxx)
                maxx=area;
            
            if(height[left]>height[right]){
                right--;
            }
            else{
                left++;
                


            }
        }

        return maxx;
    }
};
