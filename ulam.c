#include <stdio.h>
#include <stdlib.h>

#define	n 39

int main () {
	int x,y;
	int *primes=malloc(sizeof(int)*(n*n+1));
	for (x=2;x<=n*n;x++) primes[x]=1;
	for (x=2;x<=n*n/2;x++) if (primes[x]) for (y=x+x;y<=n*n;y+=x) primes[y]=0;
	
	x=0;y=0;
	int pos=n*n-(n<<1)+2;
	while (y<n) {
		printf((primes[pos]?"%4d":"    "),pos);
		pos+=(x>=y&&x+1<n-y?-1:x<=y&&x+1>=n-y?+1:(x<<3)-n*4+((x<<1)<n?7:5));
		if (++x==n) {printf("\n"); ++y;x=0;pos=n*n-n*2+2+y;}
	}
	return 0;
}

