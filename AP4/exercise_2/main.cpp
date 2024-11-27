#include <iostream>
#include <string>
#include "Article.h"

using namespace std;

void test(Article<int>& article);

int main() {
    Article<int> article1(12345, "Sample Article 1", 99.99);
    Article<int> article2(67890, "Sample Article 2", 149.99);
    Article<int> article3(article1); // Using the copy constructor

    article3.getCount();
    return 0;
}

void test(Article<int>& article){
    article.print();
}