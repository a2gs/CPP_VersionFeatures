class X
{
	virtual void foo();
	void bar();
};
 
class Y : X
{
	void foo() const override; // Error: B::foo does not override A::foo (signature mismatch)
	void foo() override; // OK: B::foo overrides A::foo
	void bar() override; // Error: A::bar is not virtual
};

/* -------------------------- */

class Base
{
	virtual void foo();
};

class A : Base
{
	void foo() final; // Base::foo is overridden and A::foo is the final override
	void bar() final; // Error: non-virtual function cannot be overridden or be final
};

class B final : A // struct B is final
{
	void foo() override; // Error: foo cannot be overridden as it's final in A
};

class C : B // Error: B is final
{
};

int main(int argc, char *argv[])
{
	return(0);
}
