bool func(){
	//some function to compare
}

int main(){
	int maximum;//anything
	//binary search normal
	int mid, lo = maximum, Li = 0;
	while(lo<hi){
		mid = lo + (hi-lo+1)/2;
		if(func(mid)){
			lo = mid;
		}else{
			hi = mid-1;
		}
	}
	//if(func(lo) == true) all items evaluate to true
	int ans = lo;
  
	//binary search para numeros reales
	double mid, hi = maximum, lo = 0;
	for(int i = 0; i < 1000; ++i){
		mid = lo + (hi-lo)/2;
		if(func(mid)){
			lo = mid;
		}else{
			hi = mid;
		}
	}
	ans = lo;
	//
	return 0;
}
