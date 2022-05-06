#include <stdio.h>
 
// Function to compute `a^m mod n`
int compute(int a, int m, int n)
{
    int r;
    int y = 1;
 
    while (m > 0)
    {
        r = m % 2;
 
        // fast exponention
        if (r == 1) {
            y = (y*a) % n;
        }
        a = a*a % n;
        m = m / 2;
    }
 
    return y;
}
 
// C program to demonstrate the Diffie-Hellman algorithm
int main()
{   int p,g;
    printf("Enter a prime number:");
    scanf("%d",&p);     // modulus
    printf("Enter a primitive root of P:");
    scanf("%d",&g);    // base
 
    int a, b;    // `a` – Alice's secret key, `b` – Bob's secret key.
    int A, B;    // `A` – Alice's public key, `B` – Bob's public key
 
    // choose a secret integer for Alice's private key (only known to Alice)
    printf("choose a secret integer for Alice's private key (only known to Alice)");
    scanf("%d",&a);
 
    // Calculate Alice's public key (Alice will send `A` to Bob)
    A = compute(g, a, p);
    printf("\nAlice's Public key is:");
    printf("%d",A);
 
    // choose a secret integer for Bob's private key (only known to Bob)
    printf("\nchoose a secret integer for Bob's private key (only known to Bob)");
    scanf("%d",&b);
 
    // Calculate Bob's public key (Bob will send `B` to Alice)
    B = compute(g, b, p);
    printf("\nBob's Public key is:");
    printf("%d",B);
 
    // Alice and Bob Exchange their public key `A` and `B` with each other
 
    // Find secret key
    int keyA = compute(B, a, p);
    int keyB = compute(A, b, p);
 
    printf("\nAlice's secret key is %d\nBob's secret key is %d", keyA, keyB);
    printf("Since secret key of Alice and Bob is same. Hence, Keys are exchanged");
    return 0;
}