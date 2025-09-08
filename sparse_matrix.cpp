#include <iostream>
using namespace std;

// Node for storing non-zero elements
struct Node {
    int row, col, value;
    Node* next;
};

class SparseMatrix {
private:
    Node* head;
    int rows, cols;

public:
    // Constructor
    SparseMatrix(int r, int c) {
        head = nullptr;
        rows = r;
        cols = c;
    }

    // Insert non-zero value
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

        // Add to the end of the linked list
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    // Display linked list representation
    void displayList() {
        Node* temp = head;
        cout << "\nSparse Matrix (Row, Col, Value):\n";
        while (temp != nullptr) {
            cout << "(" << temp->row << ", " << temp->col << ", " << temp->value << ") -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Display full matrix
    void displayFullMatrix() {
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

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    SparseMatrix sm(rows, cols);

    cout << "Enter number of non-zero elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int r, c, val;
        cout << "Enter row, column, and value: ";
        cin >> r >> c >> val;
        sm.insert(r, c, val);
    }

    sm.displayList();
    sm.displayFullMatrix();

    return 0;
}
