class MyLinkedList {
    struct Node {
        int val;
        Node* next;
        Node(int x) : val(x), next(nullptr) {}
    };

    Node* head;
    int size;

public:
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size) return -1;

        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->val;
    }

    void addAtHead(int val) {
        Node* node = new Node(val);
        node->next = head;
        head = node;
        size++;
    }

    void addAtTail(int val) {
        Node* node = new Node(val);

        if (head == nullptr) {
            head = node;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = node;
        }
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;

        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }

        Node* node = new Node(val);
        node->next = current->next;
        current->next = node;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }

            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
        size--;
    }
};