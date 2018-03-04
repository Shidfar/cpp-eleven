//
// Created by Shidfar Hodizoda on 04/03/2018.
//

#ifndef C_11_RING_H
#define C_11_RING_H

#include <iostream>

using namespace std;

template<typename T>
class ring {
private:
    int m_pos;
    int m_size;
    T *m_values;

public:
    class iterator {
    private:
        int m_pos;
        ring m_ring;
    public:
        iterator(int pos, ring &n_ring):
                m_pos(pos), m_ring(n_ring) {
        }

        ~iterator() {
            m_ring = *new ring(0);
        }

        iterator &operator++() {
            ++m_pos;
            return *this;
        }

        iterator &operator++(int) {
            m_pos++;
            return *this;
        }

        bool operator!=(const iterator &other) const {
            return m_pos != other.m_pos;
        }

        T &operator*() {
            return m_ring.get(m_pos);
        }

        void print();
        void inform();
    };

    class terminator {
    public:
        void warn();
    };

public:
    ring(int size): m_pos(0), m_size(size), m_values(NULL) {
        m_values = new T[size];
    }

    ~ring() {
        delete []m_values;
    }

    int size() {
        return m_size;
    }

    iterator begin() {
        return iterator(0, *this);
    }

    iterator end() {
        return iterator(m_size, *this);
    }

    void add(T value) {
        m_values[m_pos++] = value;
        m_pos %= m_size;
    }

    T &get(int pos) {
        return m_values[pos];
    }
};

template<typename T>
void ring<T>::iterator::print()  {
    cout << "wazap! " << T() << endl;
}

template<typename T>
void ring<T>::iterator::inform() {
    cout <<"informing: " << T() << endl;
}

template <typename T>
void ring<T>::terminator::warn() {
    cout << "Warning you: " << T() << endl;
}

#endif //C_11_RING_H
