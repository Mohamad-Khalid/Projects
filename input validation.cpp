 int x;
  while(cin >> x ,cin.fail()){
    cout << "failed\n";
    cin.clear();
    cin.ignore(100000,'\n');
  }
