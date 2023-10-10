<<<<<<< HEAD
### 1. What is the template for writing template classes and function ?
=======
### 1. [What is the template for writing template classes and function ?](https://www.geeksforgeeks.org/templates-cpp/)
>>>>>>> 02967f8 (Started C++ notes)

#### <u>Class: </u>
```cpp
template <typename t1, typename t2 ... >
class ClassName {
	public:
		t1 var_name;
		t2 var_name;

		t3 func_name(t4 x, t5 d){
			....
			....
		}
}
```

#### <u>Functions: </u>
```cpp
template <typename t1, typename t2 ... > t1 FuncName {
	....
	usage of different types defined as and when needed;
	....
}
```

<<<<<<< HEAD
### 2. What is the template for writing friend classes and function ?
=======
### 2. [What is the template for writing friend classes and function ?](https://www.geeksforgeeks.org/friend-class-function-cpp/)
>>>>>>> 02967f8 (Started C++ notes)

#### <u>Friend Class: </u>
```cpp
#include <iostream>
using namespace std;

class GFG {
private:
	int private_variable;
protected:
	int protected_variable;
public:
	GFG()
	{
		private_variable = 10;
		protected_variable = 99;
	}
	// friend class declaration
	friend class F;
};
class F {
public:
	void display(GFG& t)
	{
		cout << "The value of Private Variable = "
			<< t.private_variable << endl;
		cout << "The value of Protected Variable = "
			<< t.protected_variable;
	}
};

int main()
{
	GFG g;
	F fri;
	fri.display(g);
	return 0;
}
```

#### <u>Friend Global Functions: </u>
```cpp
#include <iostream>
using namespace std;

class base {
private:
	int private_variable;
protected:
	int protected_variable;
public:
	base()
	{
		private_variable = 10;
		protected_variable = 99;
	}	
	friend void friendFunction(base& obj);
};


void friendFunction(base& obj){
	cout << "Private Variable: " << obj.private_variable<< endl;
	cout << "Protected Variable: " << obj.protected_variable;
}
int main(){
	base object1;
	friendFunction(object1);
	return 0;
}
```

#### <u>Friend Member / instance functions: </u>
```cpp

#include <iostream>
using namespace std;

class base; // forward definition needed
// another class in which function is declared
class anotherClass {
public:
	void memberFunction(base& obj);
};

class base {
private:
	int private_variable;
protected:
	int protected_variable;
public:
	base()
	{
		private_variable = 10;
		protected_variable = 99;
	}
	friend void anotherClass::memberFunction(base&);
};

void anotherClass::memberFunction(base& obj)
{
	cout << "Private Variable: " << obj.private_variable<< endl;
	cout << "Protected Variable: " << obj.protected_variable;
}

int main()
{
	base object1;
	anotherClass object2;
	object2.memberFunction(object1);
	return 0;
}
```

#### <u>Friend Funstion which is friend of multiple classes: </u>
```cpp
#include <iostream>
using namespace std;
class ABC; 
class XYZ {
	int x;
public:
	void set_data(int a) { 
		x = a; 
	}
	friend void max(XYZ, ABC);
};
class ABC {
	int y;
public:
	void set_data(int a) { 
		y = a; 
	}
	friend void max(XYZ, ABC);
};

void max(XYZ t1, ABC t2){
	if (t1.x > t2.y)
		cout << t1.x;
	else
		cout << t2.y;
}

int main()
{
	ABC _abc;
	XYZ _xyz;
	_xyz.set_data(20);
	_abc.set_data(35);
	max(_xyz, _abc); 
	return 0;
}

```

<<<<<<< HEAD
=======
### REFERENCES: 
1. [Interview Bit Top 40 question on OOPs](https://www.interviewbit.com/oops-interview-questions/)
>>>>>>> 02967f8 (Started C++ notes)
