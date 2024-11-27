#include <iostream>
#include "Article.h"

using namespace std;

template <typename T>
int Article<T>::number_of_articles = 0;

// Constructor
template <typename T>
Article<T>::Article(long article_number, const string& name, double sales_price) 
    : article_number(article_number), name(name), sales_price(sales_price) {
    number_of_articles++;
    cout << "The article is created." << endl;
    cout << "The article number is: " << article_number << endl;
    cout << "The name of the article is: " << name << endl;
    cout << "The sales price of the article is: " << sales_price << endl;
    cout << "The number of articles is: " << number_of_articles << endl;   
}

//copy constructor
template <typename T>
Article<T>::Article(const Article& other): article_number(other.article_number), name(other.name), sales_price(other.sales_price){
    number_of_articles++;
    // cout << "The article is created." <<endl;
    // cout << "The article number is: " << article_number << endl;
    // cout << "The name of the article is: " << name << endl;
    // cout << "The sales price of the article is: " << sales_price << endl;
    // cout << "The number of articles is: " << number_of_articles << endl;
}

// Destructor
template <typename T>
Article<T>::~Article() {
    number_of_articles--;
    cout << "The article is destroyed." << endl;
    cout << "There are still " << number_of_articles << " articles." << endl;
}

// Print method
template <typename T>
void Article<T>::print() {
    cout << "Article Number: " << article_number << endl;
    cout << "Name: " << name << endl;
    cout << "Sales Price: " << sales_price << endl;
}

template <typename T>
void Article<T>::set(T value) {
    cout << "The value is set to: " << value << endl;
}

template <typename T>
T Article<T>::get(T value){
    return value;
}

template <typename T>
int Article<T>::getCount(){
    return number_of_articles;
}

// Explicit instantiation of the template class
template class Article<int>;