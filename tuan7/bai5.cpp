#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

/// danh sách liên kết đơn ///
template <typename T>
struct Node_SinglyLinked{
    T value;
    Node_SinglyLinked* next;

    Node_SinglyLinked(T setValue){
        value = setValue;
    }    
};

template<typename T>
class Singly_Linkedlist{ 
    public:
        Node_SinglyLinked<T>* head;
        int size;
        /**
         *              thực hiện viết các hàm có trong danh sách đơn
         * 1. insertNode(vị trí, giá trị mà nút mới sẽ mang)
         *    insertNode(giá trị nút mới sẽ mang) = thêm vào đầu list
         * 
         * 2. deleteNode(giá trị nút)
         *    deleteNode() = xóa nút đầu
         * 
         * 3. findNode(giá trị nút) trả về true or false
         * 
         * 4. printList();
         * 
         * 
        **/
        Singly_Linkedlist(){
            size = 0;
            head = NULL;
        }
        int sizeOfList(){
            return size;
        }
        bool isNullList(){
            return head==NULL;
        }
        ~Singly_Linkedlist(){
            while(!isNullList()){
                deleteNode();
            }
            cout<<"Delete List!\n";
        }
        void insertNode(int position, T value){
            Node_SinglyLinked<T>* temp = new Node_SinglyLinked<T>(value);
            int index = 0;
            if(isNullList()){
                cout << "List is NULL! INSERT to [" << position << "] failed!\n";
            }else{
                Node_SinglyLinked<T>* findPosition = head;
                while(index!=position){
                    findPosition=findPosition->next;
                    index++;
                }
                temp->next=findPosition->next;
                findPosition->next=temp;
                size++;
                cout<<"INSERT: " << value << " to ["<<position<<"] successfully! Size of list: "<<size<<"\n";
            }
        }
        void insertNode(T value){
            Node_SinglyLinked<T>* temp = new Node_SinglyLinked<T>(value);
            temp->next=head;
            head=temp;
            size++;
            cout<<"INSERT: " << value << " successfully! Size of list: "<< size <<"\n";
        }
        void deleteNode(){
            Node_SinglyLinked<T>* temp = head;
            head = temp->next;
            delete temp;
            size--;
        }
        void deleteNode(T value){
            if(head->value==value){
                deleteNode();
            }else{
                Node_SinglyLinked<T>* findNode_value = head;
                while(findNode_value->next!=NULL && findNode_value->next->value!=value){
                    findNode_value=findNode_value->next;
                }
                if(findNode_value->next==NULL){
                    cout<<value<<" does not exists in LinkedList_sig!\n";
                    return;
                }else{
                    Node_SinglyLinked<T>* found=findNode_value->next;
                    findNode_value->next=found->next;
                    delete found;
                    size--;
                }
            }
            cout <<"Delete "<<value<<" successfully!\n";
        }
        bool findNode(T value){
            
            int count = 0;
            Node_SinglyLinked<T>* findNode_value = head;
            while(findNode_value!=NULL && findNode_value->value!=value){
                findNode_value=findNode_value->next;
                count++;
            }
            if(findNode_value==NULL){
                cout<< value <<" does not exists in LinkedList_sig!\n";
                return false;
            }else{
                cout << value <<" has been found successfully at ["<<count<<"]! \n";
                return true;
            }
        
            
        }
        void printList(){
            if(isNullList()){
                cout << "An Empty LinkedList_Sig\n";
            }else{
                Node_SinglyLinked<T>* pointer = head;
                int count = 0 ;
                while(pointer!=NULL){
                    cout <<setw(5)<< "["<< count <<"]: " << pointer->value;
                    pointer=pointer->next; 
                    count++;
                }
                cout<<"\n";
            }
        }
        
};

int main(){
    Singly_Linkedlist<int> exampleLinked;
    cout<<exampleLinked.sizeOfList()<<"\n";
    exampleLinked.printList();
    exampleLinked.insertNode(21);
    exampleLinked.insertNode(34);
    exampleLinked.printList();
    exampleLinked.insertNode(11);
    exampleLinked.insertNode(14);
    exampleLinked.printList();
    exampleLinked.insertNode(64);
    exampleLinked.insertNode(112);
    exampleLinked.printList();
    exampleLinked.findNode(25);
    exampleLinked.findNode(11);
    exampleLinked.findNode(34);
    exampleLinked.insertNode(2);
    exampleLinked.deleteNode(34);
    exampleLinked.printList();
    exampleLinked.deleteNode(112);
    exampleLinked.deleteNode(45);
    exampleLinked.printList();
    exampleLinked.~Singly_Linkedlist();
    exampleLinked.printList();
    return 0;
}
