#include <iostream>

using namespace std;

struct node
{
  long long index;
  long long value;
  long long count;
};


void
merge (long long p, long long q, long long r, node * P, node * R, node * fol1)
{
  long long i = p;
  long long j = q + 1;
  long long k = p;

  while (i <= q && j <= r)
    {
      if (P[i].value > P[j].value)
	{
	  R[k] = P[j];
	  j++;
	  k++;
	}

      else if (P[i].value == P[j].value)
	{
	  if (fol1[P[i].index].value >= fol1[P[j].index].value)
	    {
	      R[k] = P[j];
	      j++;
	      k++;
	    }
	  else
	    {
	      R[k] = P[i];
	      R[k].count += r - j + 1;
	      i++;
	      k++;
	    }
	}
      else
	{
	  R[k] = P[i];
	  R[k].count += r - j + 1;
	  i++;
	  k++;
	}
    }

  while (i <= q)
    {
      R[k] = P[i];
      R[k].count += r - j + 1;
      i++;
      k++;
    }

  while (j <= r)
    {
      R[k] = P[j];
      j++;
      k++;
    }

  i = p;
  while (i <= r)
    {
      P[i] = R[i];
      i++;
    }
}

void
merge1 (long long p, long long q, long long r, node * P, node * R)
{
  long long i = p;
  long long j = q + 1;
  long long k = p;

  while (i <= q && j <= r)
    {
      if (P[i].value >= P[j].value)
	{
	  R[k] = P[j];
	  j++;
	  k++;
	}
      else
	{
	  R[k] = P[i];
	  R[k].count += r - j + 1;
	  i++;
	  k++;
	}
    }

  while (i <= q)
    {
      R[k] = P[i];
      R[k].count += r - j + 1;
      i++;
      k++;
    }

  while (j <= r)
    {
      R[k] = P[j];
      j++;
      k++;
    }

  i = p;
  while (i <= r)
    {
      P[i] = R[i];
      i++;
    }
}

void
Merge_Sort (long long p, long long q, node * P, node * R, node * fol)
{
  if (p < q)
    {
      long long r = (p + q) / 2;
      Merge_Sort (p, r, P, R, fol);
      Merge_Sort (r + 1, q, P, R, fol);
      merge (p, r, q, P, R, fol);
    }

}

void
dnc (long long p, long long q, node * P, node * R)
{
  if (p < q)
    {
      long long r = (p + q) / 2;
      dnc (p, r, P, R);
      dnc (r + 1, q, P, R);
      merge1 (p, r, q, P, R);
    }

}

int
main ()
{
  long long m, n, i, c = 1, y = 0;
  cin >> n;
  long long fol[n], f1, f2, A[n];
  for (i = 0; i < n; i++)
    {
      cin >> f1;
      cin >> f2;
      A[i] = f1;
      fol[i] = f2;
    }

  node *nodes1 = new node[n];
  node *B1 = new node[n];
  node *fol1 = new node[n];

  for (long long i = 0; i < n; i++)
    {
      nodes1[i].index = i;
      nodes1[i].value = A[i];
      nodes1[i].count = 0;
      fol1[i].index = i;
      fol1[i].value = fol[i];
      fol1[i].count = 0;
    }

  Merge_Sort (0, n - 1, nodes1, B1, fol1);

  node *nodes = new node[n];
  node *B = new node[n];
  long long C[n];
  
  for (long long i = 0; i < n; i++)
    {
      C[n - 1 - i] = fol[nodes1[i].index];
    }

  for (long long i = 0; i < n; i++)
    {
      nodes[i].index = i;
      nodes[i].value = C[i];	//fol[nodes1[i].index]; 
      nodes[i].count = 0;
    }

  dnc (0, n - 1, nodes, B);

  long long count = 0;
  for (long long i = 0; i < n; i++)
    {
      count += nodes[i].count;
    }
  cout << count;
}
