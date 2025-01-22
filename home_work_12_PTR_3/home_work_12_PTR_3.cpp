
#include <iostream>
#include <string>
#include <memory>



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
     try {
        if (!ptr) throw str_error("error ptr");
     else  return  *ptr;
     }catch (const std::exception& ex) { std::cout << ex.what() << std::endl;}
    }
  
    T& operator=(const unique_ptr& other) = delete;
    private:
    T* ptr{nullptr};

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

    auto ptr_6 = std::make_unique<int>(15);
    //auto ptr_7 = ptr_6.release();
    std::cout << *ptr_6 << std::endl;
    std::cout << *ptr_4 << std::endl;
    std::cout << *ptr << std::endl;
    
    return 0;
}

