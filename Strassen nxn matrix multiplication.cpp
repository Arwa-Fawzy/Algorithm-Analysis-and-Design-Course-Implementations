#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define foi(n) for (int i=0; i<n; ++i)
#define foj(y) for (int j=0; j<y; ++j)

//calculating the next dividing power 
int nextPowerOf2(int k)
{
	return pow(2, int(ceil(log2(k))));
}

void display(vii C, int m, int n){
	foi(m){
		foj(n){
			cin>>a[i][j];
		}
	}
	foi(m){
		foj(n){
			cin>>b[i][j];
		}
	}
}
// printing the matrix
void display(vii C, int m, int n){
	foi(m){
		foj(n){
			cout<<C[i][j]<<" ";
		}
	}
}

// the following is addition and subtraction that each equation from 
// the 7 strassen's equations required 
void add(vii &A, vii &B, vii &C, int size){
	foi(size){
		foj(size){
			C[i][j] = A[i][j] + B[i][j];
		}
	}
}
void sub(vii &A, vii &B, vii &C, int size){
	foi(size){
		foj(size){
			C[i][j]=A[i][j]-B[i][j];
		}
	}
}

// deviding the matrix into sub matrices by recursionn 
void Strassen_algorithm(vii &A, vii &B, vii &C, int size){
    // if size = 1, this means that the matrix contains only one element 
	if (size == 1){
		C[0][0] = A[0][0] * B[0][0];
		return;
	}
	//devide the matrix into sub matrices with new size equal to n/2 
	//the following recursion is applied for each equation 
	else{
		int newSize = size / 2;
		vi z(newSize);
		vii a(newSize, z), b(newSize, z), c(newSize, z), d(newSize, z),
			e(newSize, z), f(newSize, z), g(newSize, z), h(newSize, z),
			c11(newSize, z), c12(newSize, z), c21(newSize, z), c22(newSize, z),
			p1(newSize, z), p2(newSize, z), p3(newSize, z), p4(newSize, z),
			p5(newSize, z), p6(newSize, z), p7(newSize, z), fResult(newSize, z),
			sResult(newSize, z);
		int i, j;
		//dividing the matrix in equal parts
		foi(newSize){
			foj(newSize){
			    // assign ever
				a[i][j] = A[i][j];
				b[i][j] = A[i][j + newSize];
				c[i][j] = A[i + newSize][j];
				d[i][j] = A[i + newSize][j + newSize];

				e[i][j] = B[i][j];
				f[i][j] = B[i][j + newSize];
				g[i][j] = B[i + newSize][j];
				h[i][j] = B[i + newSize][j + newSize];
			}
		}
		
		sub(f, h, sResult, newSize);
		Strassen_algorithm(a, sResult, p1, newSize);

		//*p2=h*(a+b)
		add(a, b, fResult, newSize);
		Strassen_algorithm(fResult, h, p2, newSize);

		//*p3=e*(c+d)
		add(c, d, fResult, newSize);
		Strassen_algorithm(fResult, e, p3, newSize);

		//*p4=d*(g-e)
		sub(g, e, sResult, newSize);
		Strassen_algorithm(d, sResult, p4, newSize);

		//*p5=(a+d)*(e+h)
		add(a, d, fResult, newSize);
		add(e, h, sResult, newSize);
		Strassen_algorithm(fResult, sResult, p5, newSize);

		//*p6=(b-d)*(g+h)
		sub(b, d, fResult, newSize);
		add(g, h, sResult, newSize);
		Strassen_algorithm(fResult, sResult, p6, newSize);

		//*p7=(a-c)*(e+f)
		sub(a, c, fResult, newSize);
		add(e, f, sResult, newSize);
		Strassen_algorithm(fResult, sResult, p7, newSize);

		/* calculating all elements of C through p1,p2,p3
		c11=p4+p5+p6-p2
		c12=p1+p2
		c21=p3+p4
		c22=p1-p3+p5-p7
		*/
		add(p1, p2, c12, newSize); 
		add(p3, p4, c21, newSize); 

		add(p4, p5, fResult, newSize);
		add(fResult, p6, sResult, newSize);
		sub(sResult, p2, c11, newSize); 

		sub(p1, p3, fResult, newSize);
		add(fResult, p5, sResult, newSize);
		sub(sResult, p7, c22, newSize); 

		// collecting the results and assign them in the new matrix
		foi(newSize)
		{
			foj(newSize)
			{
				C[i][j] = c11[i][j];
				C[i][j + newSize] = c12[i][j];
				C[i + newSize][j] = c21[i][j];
				C[i + newSize][j + newSize] = c22[i][j];
			}
		}
	}
}

/*for converting matrix to square matrix*/
void ConvertToSquareMat(vii &A, vii &B, int r1, int c1, int r2, int c2)
{
	int maxSize = max({r1, c1, r2, c2});
	int size = nextPowerOf2(maxSize);

	vi z(size);
	vii Aa(size, z), Bb(size, z), Cc(size, z);

	foi(r1){
		foj(c1){
			Aa[i][j] = A[i][j];
		}
	}
	foi(r2){
		foj(c2){
			Bb[i][j] = B[i][j];
		}
	}
	Strassen_algorithm(Aa, Bb, Cc, size);
	vi temp1(c2);
	vii C(r1, temp1);
	foi(r1){
		foj(c2){
			C[i][j] = Cc[i][j];
		}
	}
	display(C, r1, c1);
}

int main()
{
	vii a[30][30];
	vii b[30][30];
	ConvertToSquareMat(a, b, 30, 30, 30, 30); 
	return 0;
}
