//sobrecarga de operadores

class overload{
public:
  int some,some2;
  overload(){};
  bool operator <(const overload& other) const{
    //example
			if(some == other.some){
				return some2 < other.some2;				
			}else {
				return some < other.some;
			}
		}
};
