typedef char * arrayString;

class MyString {
  public:
    MyString();
    MyString(arrayString newStr);
    ~MyString();
    arrayString str;
    char characterAt(int position);
    char operator[](int pos);
    void append(char newChar);
    void concatenate(arrayString newStr);
    void remove(int start, int end);
    MyString& operator=(const MyString &rhs);
  private:
    int _length(arrayString str);
    arrayString copiedString(const arrayString original);
};
