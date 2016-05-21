int arr[] = {1,2,3,4,5,6,7,8};

int sl(){
  int maximo=0;
    int sum=0;
    deque <int> work;
    int limite=10;
    for (int i=0;i<n;++i){
        sum+=arr[i];
        work.push_back(arr[i]);
        while (sum>limite){
            sum-=work.front();
            work.pop_front();
        }
        maximo= max(maximo,sum);
    }

}
