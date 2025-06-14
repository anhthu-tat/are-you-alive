#include <iostream>
using namespace std;

// Template class for a singly linked list
template <typename T> 
    class Node {
        // Node class to represent each element in the linked list
        public:
            T data;                                         // Data of type T stored in the node
            Node* next;                                     // Pointer to the next node in the list
            Node(T d) : data(d), next(nullptr) {}           // Constructor to initialize the node with data and set next to nullptr
    };

// Template class for the linked list
template <typename T> 
    class LinkedList { 
        private:
            Node<T>* head;                                  // Node<T> is a pointer to the Node class, which holds data of type T

        public:
            LinkedList() : head(nullptr) {}                 // Constructor to initialize the head pointer
            ~LinkedList() {                                 // Destructor to free memory
                Node<T>* current = head;                    // Start from the head of the list
                
                while (current != nullptr) {                // Traverse the list and delete each node
                    Node<T>* nextNode = current->next;      // Store the next node
                    delete current;                         // Delete the current node
                    current = nextNode;                     // Move to the next node
                }
            }

            // Function to insert a new node at the front of the list
            void insertFront(T value) {
                Node<T>* newNode = new Node<T>(value);      // Create a new node with the given value
                newNode->next = head;                       // Point the new node's next to the current head
                head = newNode;                             // Update the head to point to the new node
            }


            // Function to display the elements of the list
            void display() { 
                Node<T>* temp = head;                 // Start from the head of the list
                cout << "List: ";                     // Print a header for the list
                while (temp != nullptr) {             // Traverse the list
                    cout << temp->data << " ";        // Print the data of the current node
                    temp = temp->next;                // Move to the next node
                }
                cout << endl; 
            }

            // Function to search for a value in the list
            bool search(T value) {                    // Check if the list is empty
                Node<T>* temp = head;                 // Start from the head of the list
                while (temp != nullptr) {             // Traverse the list
                    if (temp->data == value)          // If the current node's data matches the value, return true
                        return true; 
                    temp = temp->next;                // Move to the next node
                }
                return false;                         // If the value is not found, return false
            }

            // Function to delete a node with a specific value
            void deleteValue(T value) { 
                if (!head) return;                     // If the list is empty, do nothing
                if (head->data == value) {             // If the head node contains the value to be deleted
                    Node<T>* temp = head;              // Store the head node
                    head = head->next;                 // Update the head to the next node
                    delete temp;                       // Delete the old head node
                    return;                            // Exit the function after deleting the head node
                }

                Node<T>* current = head;                                    // Start from the head of the list
                while (current->next && current->next->data != value)       // Traverse the list until the next node is null or the next node's data matches the value
                    current = current->next;                                // Move to the next node

                if (current->next) {                                        // If the next node is not null, it means the value was found
                    Node<T>* temp = current->next;                          // Store the node to be deleted
                    current->next = temp->next;                             // Update the current node's next pointer to skip the node to be deleted
                    delete temp;                                            // Delete the node that was found
                }
            }
        };

int main() {
    LinkedList<int> list;                                                           // Create an instance of the LinkedList class for integers

    list.insertFront(10);                                                           // Insert elements at the front of the list
    list.insertFront(20); 
    list.insertFront(30);
    list.display();                                                                 // Should display: List: 30 20 10

    list.deleteValue(20);
    list.display();                                                                 // Should display: List: 30 10

    cout << "Search 10: " << (list.search(10) ? "Found" : "Not Found") << endl;     // Should display: Search 10: Found
    cout << "Search 99: " << (list.search(99) ? "Found" : "Not Found") << endl;

    return 0;
}
