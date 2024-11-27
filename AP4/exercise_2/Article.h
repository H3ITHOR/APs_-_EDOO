#include <iostream>
#include <string>

using namespace std;

template <typename T>

class Article {
    private:
        long article_number;
        const string& name;
        double sales_price;

    public:

        static int number_of_articles;
        Article(long article_number, const string& name, double sales_price);
        Article(const Article& other);
        ~Article();

        void print();
        void set(T value);
        T get(T value);

        // exercise 3: 

        static int getCount();
        
};

// Supplementary question: Suppose you modify the program by declaring a function called test() with a parameter of type Article and calling the function with an article type object. The counter for the number of objects is negative after running the program. Why?


// Answer: The counter for the number of objects becomes negative because the Article object is being copied when passed by value to the test() function. This results in the constructor and destructor being called multiple times, which incorrectly increments and decrements the number_of_articles counter. To avoid this issue, the Article object should be passed by reference or pointer to the test() function. This way, the original object is not copied, and the counter is correctly updated.