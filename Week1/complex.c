#include<stdio.h>
struct complex
{
	float real,imag;
};
struct complex add(struct complex c1, struct complex c2)
{
	struct complex c3;
	c3.real = c1.real + c2.real;
	c3.imag = c1.imag + c2.imag;
	return c3;
}
struct complex sub(struct complex c1, struct complex c2)
{
	struct complex c3;
	c3.real = c1.real - c2.real;
	c3.imag = c1.imag - c2.imag;
	return c3;
}
struct complex mul(struct complex c1, struct complex c2)
{
	struct complex c3;
	c3.real = (c1.real * c2.real) - (c1.imag * c2.imag);
	c3.imag = (c1.real * c2.imag) + (c2.real * c1.imag);
	return c3;
}
int main()
{
	struct complex c1,c2,Add,Sub,Mul;
	scanf("%f%f",&c1.real,&c1.imag);
	scanf("%f%f",&c2.real,&c2.imag);
	Add = add(c1,c2);
	Sub = sub(c1,c2);
	Mul = mul(c1,c2);
	printf("%f+%fi\n",Add.real,Add.imag);
	printf("%f+%fi\n",Sub.real,Sub.imag);
	printf("%f+%fi\n",Mul.real,Mul.imag);
}