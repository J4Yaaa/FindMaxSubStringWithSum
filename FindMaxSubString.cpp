#include <iostream>
using namespace std;
//输入第一行为元素个数
//第二行为数组元素,以空格分离
//要求找出连续子串的最大值

int isvalid = 1; //标志返回的0值是合法的(最大值为0),还是非法的(数组为null或者数组长度小于等于0)

int find_max_sub_string(const int arr[],int len)
{
    if(arr == nullptr || len <= 0)
    {
        isvalid = 0;
        return 0;
    }
    int curmax = arr[0];
    int max = 0x80000000; //赋值为int最小值,确保第一次比价赋值正确
    for(int i = 1; i < len; ++i)
    {
        //如果当前的curmax<=0,那就让curmax等于新的数组元素
        //情况1 : 数组里全是负数 -> curmax每次存储的都是当前的数组元素(负数只会越加越小),经过比价,最大的负数已经赋给max了,逻辑正确
        //情况2 : 数组中有正数 -> 只要存在正数,那么curmax<=0时一定不是最大值,所以取丢弃之前的和,取后面的元素
        if(arr[i] <= 0)
        {
            curmax = arr[i];
        }
        else
        {
            if(curmax > 0)
            {
                curmax += arr[i];
            }
            else
            {
                curmax = arr[i];
            }
        }

        if(curmax > max)
        {
            max = curmax;
        }
    }
    return max;
}

int main()
{
    //1.从标准输入读出个数
    int len = 0;
    cout<<"input arr length : ";
    cin>>len;
    //2.从标准输入读出元素
    int size = len;
    int arr[1024] = {0}; //这里给的1024为最大值,这个可以根据需要改变
    int index = 0;
    cout<<"input arr element : ";
    while(len > 0 && size--)
    {
        cin>>arr[index];
        ++index;
    }
    //3.进行查找
    int ret = find_max_sub_string(arr,len);
    if(isvalid == 1)
    {
        cout<<"max = "<<ret<<endl;
    }
    else
    {
        cout<<"is invalid,arr == nullptr || len <= 0"<<endl;
    }
    return 0;
}
