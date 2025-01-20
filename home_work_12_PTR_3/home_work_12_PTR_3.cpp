
#include <iostream>
#include <string>

class str_error : public std::exception // обработка исключений
{
public:
    str_error(const std::string& message) : message{ message }
    {
    }
    const char* what() const noexcept override
    {
        return message.c_str();     // получаем из std::string строку const char*
    }
private:
    std::string message;    // сообщение об ошибке
};

template<class T>
class unique_ptr {
public:
    unique_ptr(T* p) : ptr{ p } {}

    ~unique_ptr() // деструктор
    {
        if (ptr) {
            std::cout << "destructor called\n";
            delete ptr;
        }
    }

    T* release() {
        T* p = ptr;
        ptr = nullptr;
        return p;
    }
    unique_ptr (unique_ptr& other) = delete;

 
    T& operator*() {
        T x{404};
        if (ptr) return  *ptr;
        else {
            std::cout << "error ";
            return x;
        }
    }
  
    T& operator=(const unique_ptr& other) = delete;
    private:
    T* ptr{nullptr};
    
};


int main()
{
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

