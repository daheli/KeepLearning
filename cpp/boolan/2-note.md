#内存块

##Complex
```
class complex {
public:
	complex (double r = 0, double i = 0): re (r), im (i) { }
	complex& operator += (const complex&);
	complex& operator -= (const complex&);
	complex& operator *= (const complex&);
	complex& operator /= (const complex&);
	double real () const { return re; }
	double imag () const { return im; }
private:
	double re, im;
	friend complex& __doapl (complex *, const complex&);
	friend complex& __doami (complex *, const complex&);
	friend complex& __doaml (complex *, const complex&);
};
```

##动态分配所得内存 in VC
![image](https://cloud.githubusercontent.com/assets/6140508/22282569/406cf2fe-e318-11e6-9c30-d8beaaaa190b.png)

##动态分配所得的array
![image](https://cloud.githubusercontent.com/assets/6140508/22282605/7efd3e98-e318-11e6-9e62-cd985dd00c5d.png)

##array new 为什么要搭配array delete
![image](https://cloud.githubusercontent.com/assets/6140508/22282622/938adef6-e318-11e6-8aa5-b89aa4f84085.png)
