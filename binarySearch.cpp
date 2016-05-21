bool func(){
	//some function to compare
}

int main(){
	int maximum;//puede ser cualquier cosa
	int array[] = {1,2,3,4,5,6};
	//binary search normal
	int mid, Ls = maximum, Li = 0;//Li puede ser lo que sea
	while(Ls>Li){
		mid=Li + (Ls-Li+1)/2;
		if(func(mid)){
			Li = mid;
		}else{
			Ls = mid-1;
		}
	}
	ans = Li;
  //
  
	//binary search para numeros reales
	double mid, Ls = maximum, Li = 0;
	for(int i=0; i<1000; ++i){
		mid = Li + (Ls-Li)/2;
		if(func(mid)){
			Li = mid;
		}else{
			Ls = mid;
		}
	}
	ans = Li;
	//
	return 0;
}
