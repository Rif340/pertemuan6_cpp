#include <iostream>
#define maks 20 // maksimum data pada queue
using namespace std;

// deklarasi struct queue
struct Queue
{
    int front, rear, data[maks];
} Q;

// cek apakah queue penuh
bool isFull()
{
    return Q.rear == maks;
}

// cek apakah queue kosong
bool isEmpty()
{
    return Q.rear == 0;
}

// menampilkan queue
void printQueue()
{
    if (isEmpty())
    {
        cout << "Antrian Kosong" << endl;
    }
    else
    {
        cout << "queue : ";
        for (int i = Q.front; i < Q.rear; i++)
        {
            cout << Q.data[i] << ((Q.rear - 1 == i) ? "" : ",");
        }
        cout << endl;
    }
}

// enqueue
void enqueue()
{
    if (isFull())
    {
        cout << "Queue Penuh" << endl;
    }
    else
    {
        int data;
        cout << "Masukkan Data : ";
        cin >> data;
        Q.data[Q.rear] = data;
        // menempatkan tail pada elemen data terakhir yang ditambahkan
        Q.rear++;
        cout << "Data Ditambahkan\n";
        printQueue();
    }
}

// dequeue
void dequeue()
{
    if (isEmpty())
    {
        cout << "Queue Kosong" << endl;
    }
    else
    {
        cout << "Mengeluarkan Data | " << Q.data[Q.front] << " |\n";
        // mengubah queue data ke head
        for (int i = Q.front; i < Q.rear; i++)
        {
            Q.data[i] = Q.data[i + 1];
        }
        Q.rear--;
        printQueue();
    }
}

int main()
{
    int pilih;
    do
    {
        // Tampilkan menu
        cout << "---------------------\n"
             << " Menu Pilihan\n"
             << "---------------------\n"
             << " [1] Enqueue\n"
             << " [2] Dequeue\n"
             << " [3] Keluar\n\n"
             << "---------------------\n"
             << "Masukkan pilihan : ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        default:
            cout << "Pilihan tidak tersedia\n";
            break;
        }
    } while (pilih != 3);

    return 0;
}
