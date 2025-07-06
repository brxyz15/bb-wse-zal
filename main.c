#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 50 //definiuje liczbę losowo generowanych liczb w tablicy

void swap(int array[], int indexA, int indexB) { //zamienia liczby o podanych indeksach, funkcja dostosowana tak, by pasowala do wszystkich funkcji sortowania
    int buffer;

    buffer = array[indexA];
    array[indexA] = array[indexB];
    array[indexB] = buffer;
}

void merge(int array[], int begin, int mid, int end) { //łączy dwie rozdzielone tablice w jedną tymczasową, następnie główną opracowywaną tablicę nadpisuje danymi z tymczasowej
    int origArrayBegin, origArrayMid, tempArrayBegin;
    int tempArray[N]; //tablica tymczasowa

    origArrayBegin = begin; origArrayMid = mid;

    for (tempArrayBegin = begin; tempArrayBegin <= end; tempArrayBegin++) {
        if (((origArrayMid <= end) && (array[origArrayMid] < array[origArrayBegin])) || (origArrayBegin == mid)) { //sprawdza z której połowicznej tablicy wpisać liczbę do tablicy
            tempArray[tempArrayBegin] = array[origArrayMid++];                                                     //tymczasowej, zależnie od tego która liczba jest większa
        } else {                                                                                                   //i uzupełnia połowę tablicy tymczasowej zawierającą
            tempArray[tempArrayBegin] = array[origArrayBegin++];                                                   //liczby wyższe od środkowej lub niższe
        }
    }

    for (tempArrayBegin = begin; tempArrayBegin <= end; tempArrayBegin++) { //nadpisuje tablicę oryginalną tą tymczasową, która jest ułożona wzrastająco
        array[tempArrayBegin] = tempArray[tempArrayBegin];
    }
}

void mergeSort(int array[], int begin, int end) { //sortowanie przez scalanie, działające rekurencyjnie
    int mid = (begin+end+1)/2;

    if (begin == end) { //zatrzymuje funkcję, gdy nie da się już dalej podzielić tablicy, tzn utworzony podział zawierałby tylko jedną liczbę
        return;
    }

    mergeSort(array, begin, mid-1); //dzieli poprzez rekurencyjne wywołanie funkcji tablicę na połowę
    mergeSort(array, mid, end);
    merge(array, begin, mid, end);
}

void queryNumber(int* searchNum) { //wypytuje użytkownika o to, jaką liczbę wyszukać i sprawdza czy jest w zakresie obsługiwanym przez program i powtarza jeśli się nie zgadza
    while (*searchNum <= 0 || *searchNum > 50) {
        puts("which number to search?:");
        scanf("%d", searchNum);
    }
}

void printArray(int array[]) { //wypisuje wszystkie w kolejności liczby w tablicy która jest opracowywana
    int i;

    for (i = 0; i < N; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");
}

void bubbleSort(int array[]) { //sortowanie bąbelkowe
    int i, j;

    for (i = N - 1; i > 0; i--) { //zakres końcowy się pomniejsza z każdą pętlą, ponieważ po każdej iteracji największa liczba w zakresie zostaje na ostatnim miejscu
        for (j = 0; j < i; j++) {
            if (array[j] > array[j+1]) {
                swap(array, j, j+1);
            }
        }
    }
}

void selectSort(int array[]) { //sortowanie przez wybieranie
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = i+1; j < N; j++){ //każda liczba z indeksu j jest porównywana z jedną liczbą z indeksu i, która jest przyjęta jako najmniejsza
            if (array[i] > array[j]) { //jeśli i okazuje się jednak większe, następuje zamiana
                swap(array, i, j);
            }
        }
    }
}

int linearSearch(int array[], int searchNum) { //wyszukiwanie liniowe, zwraca wartość -1 jako sygnał tego, że nie znaleziono liczby
    int i;

    for (i = 0; i < N; i++) { //poprostu przechodzi przez całą tabelę i zwraca indeks pierwszej z kolei liczby takiej samej co wyszukiwana
        if (array[i] == searchNum) {
            return i;
        }
    }

    return -1;
}

int binarySearch(int array[], int searchNum, int begin, int end) { //wyszukiwanie binarne, zwraca wartość -1 jako sygnał tego, że nie znaleziono liczby
    int mid = (begin+end)/2;

    if (array[mid] == searchNum) {
        return mid;
    } else if (array[mid] > searchNum) {
        end = mid-1;
    } else if (array[mid] < searchNum) {
        begin = mid+1;
    }
    printf("begin = %d\n", begin); printf("end = %d\n", end);

    if (begin > end) {
        return -1;
    } else {
        return binarySearch(array, searchNum, begin, end); //wyszukiwanie działa rekurencyjnie, wyszukiwany zakres jest dzielony na coraz mniejsze połowy dopóki
    }                                                      //nie zostanie w zakresie tylko jedna liczba, która będzię tą wyszukiwaną
}                                                          //zakres połówek przesuwany jest w zależności od tego czy liczba środkowa jest mniejsza lub większa od szukanej

int main() {
    srand(time(NULL));
    int array[N];
    int i, input, searchNum, searchIndex;
    searchNum = 0;

    for (i = 0; i < N; i++) { //generacja losowej tablicy zawierającej liczby od 1 do 50
        array[i] = (rand() % 50) + 1;
    }
    printArray(array); //pokazuje tablicę przed operacją, dalej w kodzie jest też wywołany wydruk tablicy po operacji

    puts("choose option (enter the corresponding number):"); //instrukcja opcji w programie, należy wpisać numer danej operacji
    puts("1) bubble sort");
    puts("2) selection sort");
    puts("3) linear search");
    puts("4) binary search");
    puts("5) merge sort");
    scanf("%d", &input);

    switch (input) {
        case 1:
            bubbleSort(array);
            printArray(array);
            break;
        case 2:
            selectSort(array);
            printArray(array);
            break;
        case 3:
            queryNumber(&searchNum);
            searchIndex = linearSearch(array, searchNum);
            if(searchIndex == -1) { //zwrócony indeks -1 sygnalizuje brak liczby w tablicy
                puts("number not found in array");
            } else {
                printf("number %d found at index %d\n", searchNum, searchIndex); //pokazywany jest indeks liczby w kodzie, dlatego np gdy zostanie wskazana ostatnia liczba w
            }                                                                    //tablicy, zostanie podany indeks 49
            break;
        case 4:
            queryNumber(&searchNum);
            bubbleSort(array); //tablica musi być przesortowana przed użyciem wyszukiwania binarnego
            printArray(array);
            searchIndex = binarySearch(array, searchNum, 0, N-1); //N-1, żeby nie próbowało operować na indeksie np. 50
            if(searchIndex == -1) { //zwrócony indeks -1 sygnalizuje brak liczby w tablicy
                puts("number not found in array");
            } else {
                printf("number %d found at index %d\n", searchNum, searchIndex); //pokazywany jest indeks liczby w kodzie, dlatego np gdy zostanie wskazana ostatnia liczba w
            }                                                                    //tablicy, zostanie podany indeks 49
            break;
        case 5:
            mergeSort(array, 0, N-1); //N-1, żeby nie próbowało operować na indeksie np. 50
            printArray(array);
            break;
        default:
            puts("wrong input");
            break;
    }

    return 0;
}
