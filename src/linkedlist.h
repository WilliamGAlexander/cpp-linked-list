class Node{
  public:
  Node *next;
  int val;
  void deleteNextAndSelf();
};

class LinkedList{
  public:
  int length;
  Node* head;
  
  LinkedList();
  ~LinkedList();
  void add(int val);
  void print();
};