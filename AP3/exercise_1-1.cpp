#include <iostream>
#include <cassert>

using namespace std;

template <typename E>
class AList {
private:
    int maxSize;
    int listSize;
    int curr;
    E* listArray;

public:
    AList(int size){
        maxSize = size;
        listSize = curr = 0;
        listArray = new E[maxSize];
    }

    ~AList(){ delete [] listArray;}

    void clear() {
        delete [] listArray;
        listSize = curr = 0;
        listArray = new E[maxSize]; // por quê recriar o array com o tamanho padrão "maxsize"?
    }
    
    void insert(const E& it) {
        assert(listSize < maxSize && "List capacity exceeded"); // Para quê serve e como utilizar a função Assert?
        for (int i=listSize; i>curr; i--){
            listArray[i] = listArray[i-1];
        }
        listArray[curr] = it;
        listSize++;
    }

    void append(const E& it){
        assert(listSize < maxSize && "List capacity exceeded");
        listArray[listSize++] = it;
    }

    E remove(){
        assert((curr>=0) && (curr < listSize) && "No element");
        E it = listArray[curr];
        for(int i=curr; i<listSize-1; i++){
            listArray[i] = listArray[i+1];
            listSize--;
            return it;
        }
        return it;
    }


    void moveToStart() {curr = 0;}
    void moveToEnd() {curr = listSize;}
    void prev() {if (curr != 0) curr --;}
    void next() {if (curr < listSize) curr++;}

    int length() const {return listSize; }
    int currPos() const {return curr; }

    void moveToPos(int pos){
        assert ((pos>=0) && (pos<=listSize) && "Pos out of range"); 
        curr = pos;
    }

    const E& getValue() const {
        assert((curr >=0) && (curr<listSize) && "No current element");
        return listArray[curr];
    }

    int count(E element){
        int qtt_eq = 0;
        for(int i = 0; i < listSize; i++){
            if(listArray[i] == element){
                qtt_eq++;
            }                                                                                                                        
        }
        return qtt_eq;
    }
};

int main(){
    int nbr_cases;
    int nbr_op;
    string op;
    int num;
    cin >> nbr_cases;

    for (int i = 0; i < nbr_cases; i++){
        cin >> nbr_op;
           AList<int> list(nbr_op);
        cout << "Caso " << i+1 <<  endl;
        for (int j = 0; j < nbr_op; j++){
            cin >> op;
            if(op == "insert"){
                cin >> num;
                list.append(num);
            }

            else if(op == "count"){
                cin >> num;
                cout << list.count(num) << endl;
            }

            else if(op == "next"){
                list.next();
            }

            else if(op == "prev"){
                list.prev();
            }
            else if(op == "remove"){
                list.remove();
            }
        }
            cout << "end of case " << i + 1 << endl;
            list.clear();
    }
      
    return 0;
}