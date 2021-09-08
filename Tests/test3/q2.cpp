  int main()
  {
    int value = 0;
    void doFunct(int&);

    doFunct(value);
    cout << value << endl;
  }

  void doFunct(int & numb)
  {
    numb++;
    cout << numb << endl;
  }