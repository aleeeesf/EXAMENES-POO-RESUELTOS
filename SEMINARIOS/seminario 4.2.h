
class B{
	public:
		virtual void f() = 0;
		virtual ~B();
};

class D:public B{
	public:
		void f();
		~D();
};
