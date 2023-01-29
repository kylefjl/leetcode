//给你一个整数数组 nums，请你将该数组升序排列。 
//
// 
//
// 
// 
//
// 示例 1： 
//
// 
//输入：nums = [5,2,3,1]
//输出：[1,2,3,5]
// 
//
// 示例 2： 
//
// 
//输入：nums = [5,1,1,2,0,0]
//输出：[0,0,1,1,2,5]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 5 * 10⁴ 
// -5 * 10⁴ <= nums[i] <= 5 * 10⁴ 
// 
//
// Related Topics 数组 分治 桶排序 计数排序 基数排序 排序 堆（优先队列） 归并排序 👍 763 👎 0

#include<bits/stdc++.h>
using namespace std;

/*
* 排序数组
* @author fjl
* @date 2023-01-28 19:50:33
*/
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
       tmp.resize(nums.size());//归并排序需要初始化tmp的大小
        mergeSort(nums.begin(),nums.end());
//        HeapSort(nums);
        return std::move(nums);
    }
    //冒泡排序()
    void BubbleSort(vector<int>& nums)
    {
        const int num_size=nums.size();
        int temp=0;
        for(int i=0;i<num_size;++i)
        {
            bool flag=false;//是否交换
            int max_idx=num_size-i-1;
            for(int j=0;j<max_idx;++j)
            {
                if(nums[j]>nums[j+1])
                {
                    temp=nums[j+1];
                    nums[j+1]=nums[j];
                    nums[j]=temp;
                    flag= true;
                }
            }
            if(!flag)break;
        }
    }
    //简单选择
    void SelectSort(vector<int>& nums) {
        const int num_size=nums.size();
        for(int i=0;i<num_size-1;i++) {
            int min = i;
            for(int j=i+1;j<num_size;j++) {
                if(nums[j]<nums[min]) min = j;
            }
            if(min!=i) swap(nums[i],nums[min]);
        }
    }
    //插入排序
    void InsertSort(vector<int >& nums)
    {
        const int num_size=nums.size();
//        int low_idx=0,high_idx=0;
        for(int i=0;i<num_size;++i) {
            int temp =nums[i];
            int n=i-1;
            while(n>=0)
            {
                if(nums[n]>temp)
                   nums[n+1]=nums[n];
                else break;
                --n;
            }
            nums[n+1]=temp;
        }
    }
    //插入排序 重载
    void InsertSort(vector<int>::iterator beg, vector<int>::iterator end)
    {
        for(auto it=beg;it!=end;++it) {
            int temp =*it;
            auto n=it-1;
            while(n>=beg)
            {
                if(*n>temp)
                    *(n+1)=*n;
                else break;
                --n;
            }
            *(n+1)=temp;
        }
    }
     //希尔排序
     void ShellSort(vector<int>& nums)
     {
         const int num_size=nums.size();
         for(int dk=num_size/2;dk>=1;dk=dk/2) {
             for(int j=0;j<num_size-dk;++j)
             {//对每个子序列进行插入排序
                 if(nums[j]>nums[j+dk])
                 {
                     int temp =nums[j+dk],k;
                     for(k=j;k>=0&&nums[k]>temp;k-=dk) {
                          nums[k+dk]=nums[k];
                     }
                     nums[k+dk]=temp;
                 }
             }
         }

     }
     //堆排序 调整堆 index 为该父节点在nums的位置
     void adjust(vector<int> &nums,int len,int index)
     {
         if(2*index + 1>=len)return;
         int left = 2*index + 1;
         int right = 2*index + 2;
         int maxIdx = index;
         if(left<len && nums[left] > nums[maxIdx])     maxIdx = left;
         if(right<len && nums[right] > nums[maxIdx])     maxIdx = right;
         if(maxIdx != index)
         {
             swap(nums[maxIdx], nums[index]);
             adjust(nums, len,maxIdx);
         }
     }
    //堆排序 创建堆(大顶)
    void HeapSort(vector<int> &nums){
        for(int i=nums.size()/2 - 1; i >= 0; --i){
            adjust(nums,nums.size(), i);
        }
        for(int i = nums.size() - 1; i >0; --i){
            swap(nums[0], nums[i]);
            adjust(nums,i, 0);
        }
    }
     //归并排序
    void mergeSort(vector<int>::iterator beg, vector<int>::iterator end){
         if(end-beg<10)//个数小于某个值，选择用插入排序
        {
            InsertSort(beg,end);
            return;
        }
        auto mid=(end-beg)/2+beg+1;//二分
        mergeSort(beg,mid);//对每段进行排序
        mergeSort(mid,end);
        //合并连个有序数组，存到tmp里面
        auto it_left = beg, it_right = mid ;
        int cnt = 0;//tmp需要保证可以存放两个数组
        while (it_left < mid && it_right < end) {
            if (*it_left <= *it_right)  tmp[cnt++] =*(it_left++);
            else  tmp[cnt++] = *(it_right++);
        }
        while (it_left <mid) tmp[cnt++] =*(it_left++);
        while (it_right < end) tmp[cnt++] = *(it_right++);
        //重新拷贝到原数组里面
        auto temp_it=beg;
        for (int i = 0; temp_it!=end; ++i,++temp_it) {
            *temp_it= tmp[i];
        }
    }
    //快速排序
    void QuickSort(vector<int>::iterator beg, vector<int>::iterator end){
        if(end-beg<15)//个数小于某个值，选择用插入排序
        {
            InsertSort(beg,end);return;
        }
        auto pivot=*(rand()%(end-beg)+beg);//随机取
        auto it_left = beg-1, it_right = end ;//开始时不指向有效数据
        while (it_left<it_right) {
            //1、pivot为left和right之间的一个值，所以如果序列可以用pivot二分且没有第二个pivot，则第一次循环left=right=pivot,直接结束循环
            //2、如果发生了一次交换，则交换后的数组左边存在数a<= pivot 右边存在数b>= pivot,当迭代器it_left> it_right后，最坏情况下也必然会在这一组数的位置处
            //  触发判断 it_left< it_right？，如果it_left>it_right，则数组访问完毕，退出
            do ++it_left; while (*it_left < pivot);
            do --it_right;while (*it_right > pivot);
            if (it_left< it_right)//有可能出现it_left> it_right
            {
                swap(*it_left,*it_right);
            }
            if(it_left> it_right)cout<<"over mid"<<endl;
        }
        QuickSort(beg,it_left);
        QuickSort(it_left,end);
    }
private:
    vector<int> tmp;
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
   vector<int > input={-74,48,-20,2,10,-84,-5,-9,11,-24,-91,2,-71,64,63,80,28,-30,-58,-11,-44,-87,-22,54,-74,-10,-55,-28,-46,29,10,50,-72,34,26,25,8,51,13,30,35,-8,50,65,-6,16,-2,21,-78,35,-13,14,23,-3,26,-90,86,25,-56,91,-13,92,-25,37,57,-20,-69,98,95,45,47,29,86,-28,73,-44,-46,65,-84,-96,-24,-12,72,-68,93,57,92,52,-45,-2,85,-63,56,55,12,-85,77,-39};
   auto result=s.sortArray(input);
   for(auto item:result)
   {
       cout<< item<< ' ';
   }
   cout<<endl;
}