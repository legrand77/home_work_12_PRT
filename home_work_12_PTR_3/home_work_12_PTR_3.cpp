
#include <iostream>
template<class T>
class unique_ptr {
public:
    unique_ptr(T* p) : ptr{ p } {}

    ~unique_ptr() // деструктор
    {
        if (ptr) {
            std::cout << "destructor called\n";
            delete[] ptr;
        }
    }

    T* release() {
        T* p = ptr;
        ptr = nullptr;
        return p;
    }
    unique_ptr (unique_ptr& other) = delete;


    T& operator*(){
        if (ptr)
        return  *ptr;
   }

   T& operator=(const unique_ptr& other) = delete;

    private:
    T* ptr = new T{ nullptr };
};


int main()
{
    std::cout << "Hello World!\n";
    unique_ptr<int> ptr(new int(17));
    unique_ptr<int> ptr_2(new int(10));

    std::cout << *ptr << std::endl;
    std::cout << *ptr_2 << std::endl;
   // ptr = ptr_2;
   // unique_ptr<int> ptr_3(ptr);
    int* ptr_4 = ptr.release();
    std::cout << *ptr_4 << std::endl;
    std::cout << *ptr << std::endl;
    return 0;
}

