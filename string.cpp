#include"string.h"

namespace bit
{
	const size_t string::npos = -1;
	

	void string::reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* tmp=new char[n+1];
			//strcpy(tmp,_str);
			memcpy(tmp,_str,_size+1);//更安全但要注意多+1把换行符给拷贝进来
			delete[]_str;
			_str=tmp;
			_capacity=n;
		}
		//cout<<"reverse:"<<_capacity<<endl;
	}
	//_size 没有改变吗？
	//_size 在insert等操作中就已经完成改变了


	void string::push_back(char ch)
	{
		if (_size == _capacity)
		{
			reserve(_capacity==0 ? 4 : _capacity*2);
		}
		_str[_size] = ch;
		_size++;
		_str[_size]='\0';//一定不要忘记字符串结尾有斜杠零
	}
	void string::append(const char* str)//append 拼接字符串
	{
		size_t len=strlen(str);
		if (_size + len > _capacity)
		{
			reserve(_size+len>2*_capacity? _size+len : 2*_capacity);
		}
		//strcpy(_str+_size,str);//_str + _size 是什么意思？这样能完成字符串的拷贝吗？可以，这样相当于对_str后面扩容了_size 的大小
		memcpy(_str + _size, str, len+1);//用memcpy更安全,但要注意多+1把换行符给拷贝进来
		_size+=len;
	}
	string& string::operator+=(char ch)
	{
		push_back(ch);
		return *this;
	}
	string& string::operator+=(const char* ch)
	{
		append(ch);
		return *this;
	}
	void string::insert(size_t pos, char ch)//这里的pos是[]里的坐标，下同
	{
		assert(pos<=_size&&pos>=0);
		if (_size == _capacity)
			reserve(_capacity==0? 4 : _capacity*2);
		int end=(int)_size;
		while (end >=(int) pos)//思考这里为什么要强转呢？其实这里是c语言自动类型转换遗留的问题，若没有强转，两者会变成size_t类型的数字，导致头插溢出问题
		{
			_str[end+1]=_str[end];
			--end;
		}
		_str[pos]=ch;
		++_size;
	}
	void string::insert(size_t pos, const char* s)
	{
		assert(pos<=_size&&pos>=0);
		size_t len=strlen(s);
		if (_size + len > _capacity)
		{
			reserve(_size+len>2*_capacity ?_size+len:2*_capacity);
		}
		size_t end=_size+len;
		while (end > pos + len - 1)
		{
			_str[end]=_str[end-len];
			end--;
		}
		for (size_t i = 0; i < len; ++i)
		{
			_str[pos+i]=s[i];
		}
		_size+=len;

	}
	void string::erase(size_t pos, size_t len)
	{
		assert(pos<_size&&pos>=0);
		if (len >= _size-pos)
		{
			_str[pos]='\0';
			_size=pos;
		}
		else
		{
			for (size_t i = pos + len; i <= _size; ++i)
			{
				_str[i-len]=_str[i];
			}
			_size-=len;
		}
		
	}
	size_t string::find(char ch, size_t pos)
	{
		assert(pos < _size&&pos>=0);
		for (size_t i = pos; i < _size; ++i)
		{
			if(_str[i]==ch)return i;
		}
		return npos;
	}
	size_t string::find(const char* s, size_t pos)
	{
		assert(pos<_size&&pos>=0);
		const char* ptr=strstr(_str+pos,s);
		if (ptr == nullptr)
		{
			return npos;
		}
		else return ptr-_str;
	}
	string string::substr(size_t pos, size_t len)//如果返回值是地址会造成什么后果？
	{
		assert(pos<_size);
		if (len > _size - pos)
		{
			len=_size-pos;
		}
		string tmp;
		tmp.reserve(len);
		for (size_t i = 0; i < len; ++i)
		{
			tmp+=_str[pos+i];
		}
		return tmp;
	}
	bool operator<(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(),s2.c_str())<0;
	}
	bool operator<=(const string& s1, const string& s2)
	{
		return s1<s2 || s1==s2;
	}
	bool operator>(const string& s1, const string& s2)
	{
		return !(s1<=s2);
	}
	bool operator>=(const string& s1, const string& s2)
	{
		return !(s1<s2);
	}
	bool operator==(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(),s2.c_str())==0;
	}
	bool operator!=(const string& s1, const string& s2)
	{
		return !(s1==s2);
	}
	ostream& operator<<(ostream& out, const string& s)
	{
		
		out<<s.c_str();
		return out;
	}
	istream& operator>>(istream& in, string& s)
	{
		s.clear();
		const int N=256;
		char buff[N];
		int i=0;
		char ch;
		//in>>ch;
		ch=in.get();
		while (ch != ' ' && ch != '\n')
		{
			buff[i++]=ch;
			if (i == N - 1)
			{
				buff[i]='\0';
				s+=buff;
				i=0;
			}
			//in>>ch;
			ch=in.get();
		}
		if (i > 0)
		{
			buff[i]='\0';
			s+=buff;
		}

		return in;
	}


	void test_string1()
	{
		string s1;
		string s2 = "hello world";
		s1 += 'I';
		s2.insert(0,"I want to say ");
		cout<<"s2: ";
		for (size_t i = 0; i < s2.size(); ++i)
		{
			cout << (char)(s2[i]-0);
		}
		cout << endl;
		s1 += " like you so";
		cout<<"s1: " << s1.c_str() << endl;
			s1.insert(0,'I');
		cout<<"s1: " << s1.c_str() << endl;
		string s3=s2.substr(0,13);
		cout<<"s3 is form s2: "<<s3.c_str()<<endl;
		cout<<s3.find("want",0)<<endl;
		string s4=s3;
		cout<<"s4=s3:" << s4.c_str() << endl;
		string s5;cin>>s5;
		cout<<"s5: "<<s5<<endl;

	}
}