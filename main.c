#define MAX(a,b) ((a)>(b)?(a):(b))

int countPrimes(int n) {
    int upper = MAX(n,2);
    bool * isPrime= (bool *)malloc(upper*sizeof(bool));
    *isPrime=0;*(isPrime+1)=0;
    for(bool *ip=isPrime+2;ip<isPrime+upper;ip++){
       *ip = 1;
    }
    for(int i=2;i<n;i++){
        if(*(isPrime+i)){
              int p = i*i;
              for(;p<n;){
		          *(isPrime+p)=0;
		          p += i;
              }
        }
    }
    int sum=0;
    for(int i=0;i<upper;i++){
       sum +=*(isPrime+i);
    }
    return sum;
}
