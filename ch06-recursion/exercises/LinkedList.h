class LinkedList {
  private:
    struct node {
        int num;
        node * next;
    };
    typedef node * nodePtr;
    nodePtr _head;
  public:
    LinkedList();
    void addNum(int newNum);
}
