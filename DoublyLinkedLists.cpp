#include <iostream>

using namespace std;

typedef struct Node1
{
    int data;
    struct  Node1* llink;
    struct Node1* rlink;

}Node;

Node* getNode()
{
    Node* temp = (Node*)malloc(sizeof(struct Node1));
    if (temp == NULL)
        cout << "Memory is not allocated!!!" << endl;
    temp->llink = NULL;
    temp->rlink = NULL;
    return temp;
}
Node* InsertBegin(Node* Head)
{
    Node* temp = getNode();
    cout << "Enter the data" << endl;
    cin >> temp->data;
    cout << temp->data << " is Inserted" << endl;
    if (Head == NULL)
    {

        Head = temp;
        return Head;
    }
    temp->llink = Head;
    Head->rlink = temp;

    return temp;
}
Node* InsertEnd(Node* Head)
{
    Node* temp = getNode();
    Node* cur = Head;
    cout << "Enter the data" << endl;
    cin >> temp->data;
    cout << temp->data << " is Inserted" << endl;
    if (Head == NULL)
    {

        Head = temp;
        return Head;
    }
    while (cur->llink != NULL)
        cur = cur->llink;
    cur->llink = temp;
    temp->rlink = cur;
    return Head;

}
Node* InsertBetween(Node* Head)
{
    int pos, count;
    Node* temp = getNode();
    cout << "Enter the pos" << endl;
    cin >> pos;
    cout << "Enter the data" << endl;
    cin >> temp->data;
    cout << temp->data << " is Inserted" << endl;
    if (Head == NULL)
    {

        Head = temp;
        return Head;
    }
    Node* cur = Head;
    Node* prv = cur;
    for (count = 0; cur->llink != NULL; cur = cur->llink, count++)
    {
        if (count + 1 == pos)
        {
            prv->llink = temp;
            temp->rlink = prv;
            cur->rlink = temp;
            temp->llink = cur;
            break;
        }
        prv = cur;
    }


    return Head;
}
Node* DeleteBegin(Node* Head)
{
    if (Head == NULL)
        cout << "No Element in a list";
    if (Head->llink == NULL)
    {
        free(Head);
        return NULL;
    }
    Node* next;
    cout << Head->data << " is Deleted" << endl;
    (Head->llink)->rlink = NULL;
    next = Head->llink;
    free(Head);
    return next;

}
Node* DeleteEnd(Node* Head)
{
    if (Head == NULL)
        cout << "No Element in a list";
    if (Head->llink == NULL)
    {
        free(Head);
        return NULL;
    }
    Node* cur = Head;
    Node* prv = cur;

    while (cur->llink != NULL)
    {
        prv = cur;
        cur = cur->llink;
    }
    cout << cur->data << " is Deleted" << endl;
    prv->llink = NULL;
    cur->rlink = NULL;
    free(cur);

    return Head;

}
Node* DeleteBetween(Node* Head)
{
    int pos, count;
    if (Head == NULL)
        cout << "No Element in a list";
    cout << "Enter the pos" << endl;
    cin >> pos;
    if (Head->llink == NULL)
    {
        free(Head);
        return NULL;
    }
    Node* cur = Head;
    Node* prv = cur;
    for (count = 0; cur->llink != NULL; cur = cur->llink, count++)
    {
        if (count + 1 == pos)
        {

            prv->llink = cur->llink;
            cur->rlink = prv;
            cout << cur->data << " is deleted" << endl;
            free(cur);
            break;
        }
        prv = cur;
    }
    return Head;

}
void print_list(Node* Head)
{
    if (Head == NULL)
    {
        cout << "No Element in a list" << endl;
        return;
    }

    if (Head->llink == NULL)
    {
        cout << Head->data << endl;
    }
    Node* cur = Head;


    while (cur != NULL)
    {
        cout << cur->data << "->";
        cur = cur->llink;
    }

    cout << endl;


}
int main()
{
    Node* Head = NULL;
    int ch;
    while (1)
    {
        cout << "1.Insert at Begin\n2.Insert at End\n3.Delete at Begin\n4.Delete at End\n5.Insert Between\n6.Delete Between\n7.Display List\n8.Exit\n";
        cin >> ch;
        switch (ch)
        {
        case 1: Head = InsertBegin(Head);
            break;
        case 2: Head = InsertEnd(Head);
            break;
        case 3: Head = DeleteBegin(Head);
            break;
        case 4: Head = DeleteEnd(Head);
            break;
        case 5: Head = InsertBetween(Head);
            break;
        case 6: Head = DeleteBetween(Head);
            break;
        case 7: print_list(Head);
            break;
        default: exit(0);

        }
    }
}
