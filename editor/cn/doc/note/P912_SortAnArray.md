# 排序数组

算法：冒泡排序，选择排序，插入排序，希尔排序，堆排序，归并排序，快速排序，前3个复杂度是$O(n^2)$，希尔排序复杂度介于$O(n^2)$与$O(nlog(n))$之间，后3个算法的复杂度都是$O(nlog(n))$

$O(n^2)$复杂度的算法都会超时，但为了练手，也写了一下

[排序算法动画bilibili](https://www.bilibili.com/video/BV1CY4y1t7TZ?p=4)



##   冒泡排序 选择排序 插入排序

插入排序是$O(n^2)$复杂度的算法的算法中最快的

```cc
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
       tmp.resize(nums.size());//归并排序需要初始化tmp的大小
        QuickSort(nums.begin(),nums.end());
        return std::move(nums);
    }
    //冒泡排序
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
};
```

## 希尔排序（非稳定排序）

算法”不稳定“，优势是空间复杂度低

时间复杂度介于nlogn和n^2之间，空间复杂度1

```cc
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

```

>执行耗时:164 ms,击败了53.16% 的C++用户
>内存消耗:54 MB,击败了99.82% 的C++用户

## 堆排序（非稳定排序）

利用率二叉树的性质，与优先级队列的原理一致

时间复杂度nlogn 空间复杂度1

```cc
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
    }cc
```

>执行耗时:168 ms,击败了47.84% 的C++用户
>内存消耗:53.9 MB,击败了99.98% 的C++用户

## 归并排序（稳定排序)

时间复杂度nlogn，空间复杂度n

```cc
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
    private:
    vector<int> tmp;
```

>执行耗时:148 ms,击败了66.69% 的C++用户
>内存消耗:55.8 MB,击败了74.51% 的C++用户

## 快速排序（非稳定排序）

时间复杂度nlogn，空间复杂度logn

```cc
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
```

>执行耗时:84 ms,击败了96.94% 的C++用户
>内存消耗:54 MB,击败了99.91% 的C++用户

