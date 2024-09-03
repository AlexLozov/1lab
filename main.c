#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    false,
    true
} bool;

typedef struct {
    int *data;
    size_t size;
} Array;

Array make_copy(const Array *a);                        // - создает копию существующего массива
Array make_from_array(const int array[], size_t n);     // - создает массив из существующего массива
Array make_of_size(size_t n);                           // - создает массив заданного размера
Array make_empty();                                     // - создает возвращает пустой массив
void clear(Array *a);                                   // - очищает массив и освобождает память
int at(const Array *a, int index);                      // - возвращает элемент массива по заданному индексу
bool is_equal(const Array *a, const Array *b);          // - сравнивает два массива
void printArray(Array a, size_t size); // - вывод массива на экран

int main(int argc, char const *argv[]) {
    // int array[] = {1, 4, 7, 9, 8, 5, 4, 3, 2, 77};
    // Array a = make_from_array(array, 10);
    // printArray(a, a.size);
    // int x = at(&a, 0);
    // int y = at(&a, -1);
    // int z = at(&a, -13);
    // int j = at(&a, -9);
    // int i = at(&a, 11);
    // int c = at(&a, 15);
    // Array b = make_copy(&a);
    // printArray(b, b.size);
    // Array cc = make_empty();
    // Array dd = make_of_size(5);
    // printArray(dd, dd.size);
    // printArray(cc, cc.size);
    // clear(&a);
    // clear(&b);
    // clear(&cc);
    // clear(&dd);

     int array[] = {1, 4, 7, 9};
     Array a = make_from_array(array, 4);
     assert(9 == at(&a, 3));
     assert(1 == at(&a, -1));
     assert(9 == at(&a, 13));
     assert(1 == at(&a, -13));
     Array b = make_copy(&a);
     assert(is_equal(&a, &b));
     clear(&a);
     clear(&b);

    return 0; // --------------------
}



// -1- создает массив из существующего массива
Array make_from_array(const int array[], size_t n) {
    Array newArray;
    newArray.size = n;
    newArray.data = (int*)malloc(sizeof(int) * n);

    for (size_t i = 0; i < n; i++) {
        newArray.data[i] = array[i];
    }

    return newArray;
}



// -2- создает копию существующего массива
Array make_copy(const Array *a) {
    Array newArray;
    newArray.size = a->size;
    newArray.data = (int*)malloc(sizeof(int) * newArray.size);

    for (size_t i = 0; i < newArray.size; i++) {
        newArray.data[i] = a->data[i];
    }

    return newArray;
}



// -3- очищает массив и освобождает память
void clear(Array *a) {
    free(a->data);
    a->data = NULL;
    a->size = 0;
    printf("\nMemory is free\n");
}



// -4- возвращает элемент массива по заданному индексу
int at(const Array *a, int index) {
    int result;

    if (index >= (int)a->size) {
        result = a->data[a->size - 1];
    } else if (index < 0) {
        result = a->data[0];
    } else {
        result = a->data[index];
    }

    printf("result = %d\n", result);

    return result;
}


// -5- сравнивает два массива
bool is_equal(const Array *a, const Array *b) {
    if(a->size != b->size) {
        printf("the problem is the sizes of arrays\n");
        return false;
    }

    for(size_t i = 0; i < a->size; i++) {
        if(a->data[i] != b->data[i]) {
            printf("the problem is the values of arrays");
            return false;

        }
    }

    printf("arrays are equals");
    return true;
}


// -6- создает возвращает пустой массив
Array make_empty() {
    Array newArray;
    newArray.size = 0;
    newArray.data = NULL;
    return newArray;
}


// -7- создает массив заданного размера
Array make_of_size(size_t n) {
    Array newArray;
    newArray.size = n;
    newArray.data = (int*)malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++) {
        newArray.data[i] = 0;
    }

    return newArray;
}

// - вывод массива на экран
void printArray(Array a, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d ", a.data[i]);
    }
    printf("\n");
}
