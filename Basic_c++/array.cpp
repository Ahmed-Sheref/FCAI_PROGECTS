#include <bits/stdc++.h>

using namespace std;

class Array
{
    private:
    int size , length , *ptr , number;
    public:
    Array(int size_input)
    {
        size = size_input;
        length = 0;
        ptr = new int[size_input];
    }
    void fil_Array()
    {
        cout << "how many you want fill items: ";
        int fill_items; cin >> fill_items;
        if (fill_items > size)
        {
            cout << "!!! Segmentation Fult !!!\n";
        }
        else
        {
            for (int i = 0; i < fill_items; i++)
            {
                cout << "number(" << i + 1<< "): ";
                cin >> number;
                ptr[i] = number;
                ++length;
            }
        }
    }
    void Disply()
    {
        cout << '\n';
        cout << "Disply array :\n";
        for (int i = 0; i < length; i++)
        {
            cout << "number(" << i + 1<< "): " << ptr[i] << '\n';
        }
    }
    void Append(int value_item)
    {
        if (length >= size)
        {
            cout << "!!! segmentatiion !!!";
            return;
        }
        else
        {
            ptr[length] = value_item;
            ++length;
        }
    }
    void insert(int index_item , int value_index)
    {
        if (length > size)
        {
            cout << "!!! Segmentation Fult !!!\n";
            return;
        }
        for (int i = length; i > index_item-1; i--)
        {
            ptr[i] = ptr[i-1];
        }
        ptr[index_item-1] = value_index;
        ++length;
    }
    void Delete(int index_item)
    {
        if (length > size)
        {
            cout << "!!! Segmentation Fult !!!\n";
            return;
        }
        else
        {
            for (int i = index_item-1; i < length-1; i++)
            {
                ptr[i] = ptr[i+1];
            }
            --length;
        }
    }
    int get_size()
    {
        return size;
    }
    int get_length()
    {
        return length;
    }
    // void Enlarge(int new_size) // Check ******************* wow wow wow ********* Check digram
    // {
    //     size = new_size;
    //     int* new_ptr = new int[new_size];
    //     for (int i = 0; i < length; i++)
    //     {
    //         new_ptr[i] = ptr[i];
    //     }
    //     ptr = new_ptr;
    //     delete []ptr;
    // }
    void Enlarge(int new_size) // Check
    {
        if (new_size <= size)
        {
            cout << "New Size must be bigger than: " << size << endl;
            return;
        }
        size = new_size;
        int* new_ptr = ptr;
        ptr = new int[new_size];
        for (int i = 0; i < length; i++)
        {
            ptr[i] = new_ptr[i];
        }
        delete []new_ptr;
    }
    int found(int value_item)
    {
        int index = 0;
        for (int i = 0; i < length; i++)
        {
            if (value_item == ptr[i])
            {
                cout << "Found in " << i+1 << " item";
                index = i + 1;
                break;
            }
        }
        if (index == 0)
        {
            cout << "Not Found\n";
        }
        return index;
    }
    void Merge(Array other)
    {
        int* old_ptr = ptr;
        int new_size = length + other.get_length();
        size = new_size;
        ptr = new int[size];
        int i , j;
        for (i = 0; i < length; i++)
        {
            ptr[i] = old_ptr[i];
        }
        j = length;
        delete []old_ptr;
        for (int i = 0; i < other.get_length();i++,j++)
        {
            ptr[j] = other.ptr[i];
            length++;
        }
    }
};


int main ()
{
    Array arr(7);
    arr.fil_Array();
    // arr.Delete(2);
    arr.Disply();
    // arr.Enlarge(12);
    // arr.Append(5);
    // arr.Disply();
    // cout << arr.get_size() << endl;
    // cout << arr.get_length() << endl;
    // cout << arr.found(4);
    // arr.insert(3,8);
    // arr.Disply();
    // arr.Disply();
    // arr.found(3);
    Array other(5);
    other.fil_Array();
    // other.Disply();
    arr.Merge(other);
    arr.Disply();
}