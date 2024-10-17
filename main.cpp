#include "LinkedList.h"

int main() {
    LinkedList dll;
    int choice, value;

    cout << "----------------------------------------------\n";
    cout << "     🌟 Doubly linked List Operations!🌟\n";
    cout << "----------------------------------------------\n";

    do {
        cout << "1. Insert at Start\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete at Start\n";
        cout << "4. Delete at End\n";
        cout << "5. Traverse\n";
        cout << "6. Insert After\n";
        cout << "7. Delete After\n";
        cout << "8. Insert Before\n";
        cout << "9. Delete Node\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at start: ";
            cin >> value;
            dll.insertAtStart(value);
            break;
        case 2:
            cout << "Enter value to insert at end: ";
            cin >> value;
            dll.insertAtEnd(value);
            break;
        case 3:
            dll.deleteAtStart();
            break;
        case 4:
            dll.deleteAtEnd();
            break;
        case 5:
            dll.traverse();
            break;
        case 6:
            cout << "Enter value to insert after: ";
            cin >> value;
            dll.insertAfter(value);
            break;
        case 7:
            cout << "Enter value to delete after: ";
            cin >> value;
            dll.deleteAfter(value);
            break;
        case 8:
            cout << "Enter value to insert before: ";
            cin >> value;
            dll.insertBefore(value);
            break;
        case 9:
            cout << "Enter value to delete: ";
            cin >> value;
            dll.deleteNode(value);
            break;
        case 10:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 10);

    return 0;
}
