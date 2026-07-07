📌 Container With Most Water (LC 11)
Pattern
Two Pointers
Approach
Place one pointer at the beginning and one at the end.
Calculate:
Width = right - left
Height = min(height[left], height[right])
Area = width × height
Update the maximum area.
Move the pointer with the smaller height.
Repeat until left >= right.
Key Idea

The water level is limited by the shorter bar.

Area = min(leftHeight, rightHeight) × (right - left)
Why move the shorter pointer?
The shorter bar limits the water height.
Moving the taller bar only decreases the width while the limiting height stays the same or decreases.
Moving the shorter bar gives a chance to find a taller bar and increase the area.
Time Complexity
O(n)

Each pointer moves at most n times.

Space Complexity
O(1)



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
