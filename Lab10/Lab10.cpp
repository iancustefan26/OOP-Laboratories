#include <iostream>
#include <exception>


class invalidCapacity : public std::exception {
    virtual const char* what() const throw() {
        return "Try a valid positive capacity for an array\n";
    }
};

class invalidIndex : public std::exception {
    virtual const char* what() const throw() {
        return "Try to pass a valid index for the array; consider the capacity and the current size";
    }
};

invalidIndex inv;
invalidCapacity my;

class Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};

template<class T>
class ArrayIterator
{
private:
    int Current; // mai adaugati si alte date si functii necesare pentru iterator
protected:
    T* first;
    T* last;
public:
    ArrayIterator() {
        Current = 0;
    }
    ArrayIterator& operator ++ () const{
        Current++;
    }
    ArrayIterator& operator -- () const{
        Current--;
    }
    bool operator= (ArrayIterator<T>& it) const{
        try {
            this->Current = it.Current;
        }
        catch (std::exception& e) {
            std::cout << "Exception: " << e.what() << "\n";
            return false;
        }
        return true;
    }
    bool operator!=(ArrayIterator<T>& it) const{
        if (this->Current != it.Current)
            return true;
        return false;
    }
    T* GetElement() const{
        return first[Current];
    }
};

template<class T>
class Array
{
private:
    T** List; // lista cu pointeri la obiecte de tipul T*
    int Capacity; // dimensiunea listei de pointeri
    int Size; // cate elemente sunt in lista
    friend class ArrayIterator<T>;
public:
    Array() {
        List = nullptr;
        Capacity = 0;
        Size = 0;
    } // Lista nu e alocata, Capacity si Size = 0
    ~Array() {
        for (int i = 0; i < Size; ++i)
            delete List[i];
    }// destructor
    Array(int capacity) {
        try
        {
            if (capacity <= 0)
                throw my;
            Capacity = capacity;
            List = new T * [capacity];
        }
        catch (std::exception &e)
        {
            Capacity = 0;
            List = nullptr;
            std::cout << "Exception: " << e.what() << "\n";
        }
        Size = 0;
    }// Lista e alocata cu 'capacity' elemente
    Array(const Array<T>& otherArray) {

    }// constructor de copiere

    T& operator[] (int index) {
        if (index < 0 || index > Size)
             throw inv;
        return *List[index];
    }// arunca exceptie daca index este out of range

    const Array<T>& operator+=(const T& newElem) {
        List[Size] = new T(newElem);
        Size++;
        return *this;
    } // adauga un element de tipul T la sfarsitul listei si returneaza this
    const Array<T>& Insert(int index, const T& newElem) {
        if (index > Size)
                throw inv;
        else 
            *List[index] = newElem;
        return *this;
    }
       // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    const Array<T>& Insert(int index, const Array<T> otherArray); // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    const Array<T>& Delete(int index) {
        if (index > Size)
            throw inv;
        else
            List[index] = nullptr;
        return *this;
    } // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie

    bool operator=(const Array<T>& otherArray) {
        if (Size != otherArray.Size)
            return false;
        for (int i = 0; i < Size; ++i)
            if (*List[i] != *otherArray[i])
                return false;
        return true;
            
    }

    void Sort(); // sorteaza folosind comparatia intre elementele din T
    void Sort(int(*compare)(const T&, const T&)); // sorteaza folosind o functie de comparatie
    void Sort(Compare* comparator); // sorteaza folosind un obiect de comparatie

    // functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
    int BinarySearch(const T& elem); // cauta un element folosind binary search in Array
    int BinarySearch(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind binary search si o functie de comparatie
    int BinarySearch(const T& elem, Compare* comparator);//  cauta un element folosind binary search si un comparator

    int Find(const T& elem) {
        for(auto it : *this)
            if (*(it.GetElement()) == elem)
                return true;
        return false;
    }// cauta un element in Array
    int Find(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind o functie de comparatie
    int Find(const T& elem, Compare* comparator);//  cauta un element folosind un comparator

    int GetSize() const {
        return Size;
    }
    int GetCapacity() const {
        return Capacity;
    }

    ArrayIterator<T> begin() const{
        ArrayIterator<T> a;
        a.first = List[0];
        return a;
    }
    ArrayIterator<T> end() const{
        ArrayIterator<T> a;
        a.last = List[Size];
        return a;
    }
};

int main() {
    Array<int> v(10);
    v += 1;
    return 0;
}

