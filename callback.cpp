#include <iostream>
#include <string>

using namespace std;

//以下是仿函数实现
enum CONVERSION{
	UPPER = 0,
	LOWER
};
class CFunctor{
public:
	CFunctor(int c)
	:m_c(c){}
	char operator()(char ch) const;
private:
	int m_c;
};
char CFunctor::operator()(char ch) const {
	switch (m_c)
	{
	case UPPER:
		return ch & 0x5F;
	case LOWER:
		return ch | 0x20;
	default:
		break;
	}
	return ch;
}


//以下是回调函数实现
typedef char(*pfunc)(char c);
char Upper(char ch) {
	return  (ch & 0x5F);
}
char Lower(char ch) {
	return  (ch | 0x20);
}

void conversion(const string str, const CFunctor &fc) {
	for (int i = 0; i < (int)str.length(); i++) {
		char ch=fc(str[i]);
		cout << ch;
	}
}

void conversion(const string str, const pfunc fc) {
	for (int i = 0; i < (int)str.length(); i++) {
		char ch = fc(str[i]);
		cout << ch ;
	}
}
int main(){

	std::string str = "hello nvshen";
	CFunctor cf(UPPER);
	conversion(str, cf);

	cout << endl;
	conversion("hello nvshen", Upper);
	getchar();
	return 0;
}