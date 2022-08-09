/*
	Note: This particular code sample was originally adopted from the Learn CPP website.
	https://www.learncpp.com/cpp-tutorial/template-classes/

	Note that we named this as a .hpp file.
	For our purposes we are using this naming convention to mean that the file contains
	both traditional header information as well as function definitions (that would
	usually be placed in a corresponding .cpp file).
	Since we are working with a template class, C++ has certain requirements, one of which is
	that the template code needs to be contained all in one file.
	There are certain work-arounds but this requirement is something to be aware of.
*/

#ifndef CUSTOM_ARRAY_H
#define CUSTOM_ARRAY_H

template <typename T>
class Custom_Array {
private:
    int m_length;
    T *m_data;

public:
    Custom_Array() {
        m_length = 0;
        m_data = nullptr;
    }

    Custom_Array(int length) {
        m_data = new T[length];
        m_length = length;
    }

    ~Custom_Array() {
        delete[] m_data;
    }

    void Erase() {
        delete[] m_data;
        // We need to make sure we set m_data to NULL here, otherwise it will
        // be left pointing at deallocated memory!
        m_data = nullptr;
        m_length = 0;
    }


    T& operator[](int index) {
        return m_data[index];
    }

    // The length of the array is always an integer
    // It does not depend on the data type of the array
    int getLength();
};

template <typename T>
int Custom_Array<T>::getLength() {
   return m_length;
}

#endif
