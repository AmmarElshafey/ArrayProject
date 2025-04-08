// Build My Array.cpp : 

#include <iostream>
using namespace std;
class Array
{
private :
    int size;        //Array size in memory
    int length;     // real length in array
    int* myArray;
public:
    Array(int arrSize)  //constractor
    {
        size = arrSize;
        length = 0;
        myArray = new int[arrSize];
    }
    ~Array()   //destractor
    {
        delete[] myArray;
    }
    void Fill()
    {
        int numItems;
        cout << "Enter number of items you want fill " << endl;
        cin >> numItems;
        if (numItems > size)
        {
            cout << "you can't fill this items , array size is less than number of items" << endl;
        }
        else
        {
            for (int i = 0; i < numItems; i++)
            {
                cout << "Enter item " << (i+1)<<endl;
                cin >> myArray[i];
                length++;
            }
        }
    }
    void Display()
    {
        cout << "your items are : " << endl;
        for (int i = 0; i < length; i++)
        {
            cout<<myArray[i]<<" ";
        }
        cout << endl;
    }
    int GetSize()
    {
        return size;
    }
    int GetLength()
    {
        return length;
    }
    void Search()
    {
        int x;
        cout << "Enter the numper you want search" << endl;
        cin >> x;
        int check = -1;
        for (int i=0; i < length; i++)
        {
            if (x == myArray[i])
            {
                check = i;
                break;
            }
        }
        if(check==-1)
            cout << "the number isn't in array" << endl;
        else
        cout << x << " at index " << check << endl;
    }
        
    void Append()       //push back
    {
        if (length < size)
        {
            int x;
            cout << "Enter the numper you want push back" << endl;
            cin >> x;
            myArray[length] = x;
            length++;
            cout << "after push back ";
            Display();
        }
        else
            cout << "you can't push back because length more than size" << endl;
    }
    void Insert()
    {
        int x;
        cout << "Enter the numper you want insert" << endl;
        cin >> x;
        int index;
        cout << "Enter the index of the number you want insert" << endl;
        cin >> index;
        if (index <= length && index>=0)
        {
            for (int i = length; i > index; i--)
            {
                myArray[i] = myArray[i-1];
            }
            myArray[index] = x;
            length++;
            cout << "after insert ";
            Display();

        }
        else
            cout << "you can't insert because length more than size" << endl;
    }
   void Delete()
    {
       int index;
       cout << "Enter the index of the number you want delete" << endl;
       cin >> index;
       if (index <=length && index >= 0)
       {
           for (int i = index; i < length-1; i++)
           {
               myArray[i] = myArray[i+1];
           }
           length--;
           cout << "after delete ";
           Display();
       }
       else
           cout << "index out of range" << endl;
    }
   void Enlarge()
   {
       int newSize;
       cout << "Enter the new size of Array" << endl;
       cin >> newSize;
       int* old = myArray;
       myArray = new int[newSize];
       for (int i = 0; i < length; i++)
       {
           myArray[i] = old[i];
       }
       delete[]old;
       size = newSize;
       cout << "your new size is : " << GetSize() << endl;
   }
   void Merge(Array otherArr)
   {
    
       int newSize = size + otherArr.GetSize();
      
       int* old = myArray;
       myArray = new int[newSize];
       int i;
       for ( i = 0; i < length; i++)
       {
           myArray[i] = old[i];
       }
       delete[]old;
       int j = i;
       for (i = 0; i < otherArr.GetLength(); i++)
       {
           myArray[j++] = otherArr.myArray[i];
           length++;
       }
       size = newSize;
       cout << "after merge ";
       Display();

   }
};

int main()
{
    int size;
    cout << "Enter size of Array : " << endl;
    cin >> size;
    Array myArray(size);
    myArray.Fill();
    myArray.Display();
    cout << "your size is : " << myArray.GetSize() << endl;
    cout << "your length is : " << myArray.GetLength() << endl;
   myArray.Search();
    myArray.Append();
   myArray.Insert();
   myArray.Delete();
   myArray.Enlarge();
    int otherSize;
    cout << "Enter size of Other Array : " << endl;
    cin >> otherSize;
    Array otherArr(otherSize);
    otherArr.Fill();
    otherArr.Display();
    cout << "size  of Other Array is : " << otherArr.GetSize() << endl;
    cout << " length  of Other Array is : " << otherArr.GetLength() << endl;
    myArray.Merge(otherArr);
    return 0;
}
