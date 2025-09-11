#include <iostream>
using namespace std;
struct Node { // we are storing non zero elements in node
    int row, col, value;
    Node* next;
};
class SparseMatrix {
private:
    Node* head;
    int rows, cols;
public:
    SparseMatrix(int r, int c) {
        head = nullptr;
        rows = r;
        cols = c;
    }
    void insert(int r, int c, int val) {
        if (val == 0) {
            cout << "Zero values are not stored!" << endl;
            return;
        }
        Node* newNode = new Node();
        newNode->row = r;
        newNode->col = c;
        newNode->value = val;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
    }
    void displayList() { // we are displaying linked list 
        Node* temp = head;
        cout << "\nSparse Matrix (Row, Col, Value):\n";
        while (temp != nullptr) {
            cout << "(" << temp->row << ", " << temp->col << ", " << temp->value << ") -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }  
    void displayFullMatrix() { // we are Displaying full matrix
        cout << "\nFull Matrix:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                Node* temp = head;
                bool found = false;
                while (temp != nullptr) {
                    if (temp->row == i && temp->col == j) {
                        cout << temp->value << " ";
                        found = true;
                        break;
                    }
                    temp = temp->next;
                }
                if (!found)
                    cout << "0 ";
            }
            cout << endl;
        }
    }
};
int main() {
    int rows, cols, n;
    cout << "hey dude enter number of rows please: ";
    cin >> rows;
    cout << "hey dude sorry for bothering enter number of columns please: ";
    cin >> cols;
    SparseMatrix ourresult(rows, cols);
    cout << "last dude please enter number of non-zero elements here: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int r, c, val;
        cout << "can you please enter row, column, and value: ";
        cin >> r >> c >> val;
        ourresult.insert(r, c, val);
    }
    ourresult.displayList();
    ourresult.displayFullMatrix();
    return 0;
}
