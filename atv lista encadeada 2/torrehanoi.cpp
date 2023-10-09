#include <iostream>

using namespace std;

class Disk {
    public:
        int size_disk;
        Disk* next;

        Disk(char value) : size_disk(value), next(nullptr) {}
};

class Tower {
    public:
        Disk* head;
        string name;

        Tower(string name) : head(nullptr), name(name) {}

        void push(int size_disk) {
            if (!head or size_disk < head->size_disk) {
                Disk* newDisk = new Disk(size_disk);
                newDisk->next = head;
                head = newDisk;
            } else {
                cout << "Movimento inválido. Disco maior não pode ser colocado em cima de um menor." << endl;
            }
        }

        int pop() {
            if(head!=nullptr) {
                Disk* diskToRemove = head;
                head = head->next;
                int size = diskToRemove->size_disk;
                delete diskToRemove;
                return size;
            }
            return -1;
        }

        void print() {
            Disk* current = head;
            cout << endl;
            while(current!=nullptr) {
                cout << current->size_disk << endl;
                current = current->next;
            }
            cout << endl;
        }
};

void hanoiTower(int numDisks, Tower& origin, Tower& destination, Tower& aux) {
    if (numDisks == 1) {
        int disk = origin.pop();
        destination.push(disk);
        cout << "Mova o disco " << disk << " de Torre " << origin.name << " para Torre " << destination.name << endl;
    } else {
        // hanoiTower(numDisks, towerA, towerC, towerB);
        hanoiTower(numDisks - 1, origin, aux, destination); // 2 towerA, towerB, towerC 
        hanoiTower(1, origin, destination, aux); // 1 towerA, towerC, towerB
        hanoiTower(numDisks - 1, aux, destination, origin); // towerC, towerB, towerA 
    }
}

int main() {

    int numDisks = 3;

    Tower towerA("A");
    Tower towerB("B");
    Tower towerC("C");
    
    towerA.push(3);
    towerA.push(2);
    towerA.push(1);

    cout << "Estado inicial das torres:" << endl;
    cout << "Torre A: ";
    towerA.print();
    cout << "Torre B: ";
    towerB.print();
    cout << "Torre C: ";
    towerC.print();

    hanoiTower(numDisks, towerA, towerC, towerB);

    cout << "Estado final das torres:" << endl;
    cout << "Torre A: ";
    towerA.print();
    cout << "Torre B: ";
    towerB.print();
    cout << "Torre C: ";
    towerC.print();


    return 0;
}