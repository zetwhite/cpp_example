


# function overloading
다른 매개변수를 가진 같은 이름의 함수의 여러개 만들 수 있는 기능이다. 
```cpp
int add(int a, int b);
double add(double a, double b);
```
이때, 함수의 반환형은 함수를 구분하는 기준이 되지 못한다.
```cpp
int print(int score);
void print(int score); //compile error
```
(+)overload resolution :  [https://en.cppreference.com/w/cpp/language/overload_resolution](https://en.cppreference.com/w/cpp/language/overload_resolution)



# operator overloading
overloading도 c++에서는 함수와 마찬가지다.
```cpp
int number = 1000;
cout.operator<< number << endl; //이런 형태로도 사용할 수 있다. 
cout << operator << number << endl;
```
oerator도 function과 마찬가지로 overloading하여 매개변수에 대하여 새롭게 정의할 수 있다.  
이항연산자 뿐만 아니라 단항연산자, 기타([], (), new, delete)연산자에 대해서도 overloading할 수 있다.  
(+) overloading new and delete operator : [https://www.geeksforgeeks.org/overloading-new-delete-operator-c/](https://www.geeksforgeeks.org/overloading-new-delete-operator-c/)  
다만 operator overloading을 하는 방법은 2가지가 존재하며, 필요에 따라 적절한 방법을 택해야한다.  

### 멤버함수로 overloading하는 경우
* `=`, `()`, `[]`, `->`는 멤버함수의 형태로만 overlaoding이 가능하다.   
* 좌항이 멤버함수를 호출한 객체에 해당한다.  
```cpp
class Vector{
public: 
	Vector(int _x, int _y)
	:x(_x), y(_y){}
	Vector operator+ (const Vector& rhs) const{
		Vector res(x + rhs.x , y + rhs.y);
		return res; 
	}
	Vector& operator+= (const Vector& rhs) const{
		x += rhs.x;
		y += rhs.y;
		return *this;
	}
private:
	int x;
	int y;
};
```

### 전역함수로 overloading하는 경우 
* 좌항에 해당하는 객체의 class의 소스코드를 수정할 수 없는 경우 전역함수로 선언해야한다.  
```cpp
//Vector.cpp
std::ostream& operator << (std::ostream& os, const Vector& v);
```
* 좌항의 소스코드를 수정할 수 없기때문에 수정할 수 있는 매개변수의 cpp파일에 함수구현을 작성하는 것이 일반적이다.  

### 주의사항 
* reference와 const를 적절하게 사용할 것   
* `.`, `::`, `.*`, `?:`, `::` 등의 operator는 오버로딩할 수 없다.  
* 새로운 operator 부호를 생성할 수 없다.  
* 직관적이게 연산자를 overloading할것    
만약 함수 구현을 봐야한다면 operator overloading보다 관련된 함수를 작성하는 것이 낫다.   



# freind 
위의 예제에서 전역함수로 Vector를 출력하는 <<를 overloading하고자하는 경우,    
전역함수는 Vector의 private member에 접근하지 못하는 문제가 있다.  
이러한 경우 freind지시자를 이용하여 명시하면, 외부함수나 클래스로부터 private, protected 멤버에 대한 접근 권한을 허용할 수 있다.   
friend지시자는 operator overloading이나 관계가 애매한 class들 사이를 정의할 때 유용하게 사용된다.  

### friend class
```cpp
class X{
friend class Y;
private:
	int private_x;
};

class Y{
public: 
	void access_X(X& objectX){
		//can access to objectX.private_x;
	}	
};
```
### friend function 
class안에 함수 원형이 작성되긴 하지만, 이는 friend지시자와 같이 권한을 명시하기 위한 것일 뿐    
해당 함수가 멤버함수가 되는 것은 아니다.   
```cpp
class Vector{
friend std::ostream& operator << (std::ostream& os, const Vector& rhs);
public:
	Vector(int _x, int _y)
	:x(_x), y(_y){}
	Vector operator+ (const Vector& rhs) const{
		Vector res(x + rhs.x , y + rhs.y);
		return res;
	}
private:
	int x;
	int y;
};

std::ostream& operator << (std::ostream& os, const Vector& v){
    std::cout << "(" << v.x << ", " << v.y << ")" << std::endl;
}
```



# assign operator
* `operator =`   
* 복사생성자와 비슷하며, 차이점은 대입연산자의 경우 원래 존재하던 객체에 값을 덮어쓰는 역할을 한다.    

### implicit operator 
마찬가지로 따로 코드를 작성하지 않으면 컴파일러가 자동적으로 대입연산자를 생성해준다.  
자동적으로 생성된 복사 연산자는 다음과 같은 동작을 한다.  
* 멤버변수별로 값을 복사  
* 만약 멤버가 객체인 경우 해당 객체의 assign operator를 호출한다.   
* `*this`를 이용하여 자기 자신을 반환   

따라서 copy operator와 마찬가지로 만약 동적 할당된 메모리를 가지고 있다면,    
덮어씌워질 객체이 동적 메모리를 해제해주고, 추가로 할당한뒤 복사하는 부분을 직접 작성해야한다.    

# How to avoid implicit constructor/operator
* basic constructor
* implicit copy constructor
* implicit assign operator

만약 아예 해당 객체의 copy나 assign이 불가능한 상태로 두고 싶어서 자동적으로 생기는 생성자/연산자를 없애고 싶다면,  
해당 함수 원형을 private 필드에 선언하면 된다.  
원형을 private 필드에 선언한 다음 굳이 함수 내부를 구현할 필요는 없다.   
