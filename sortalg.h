#ifndef SORTALG_H
#define SORTALG_H

void swap(long *a, long *b) //Functia de schimbare a 2 valori intre ele
{
    long t=*a;
    *a=*b;
    *b=t;
}
//Algoritmul de sortare prin selectie (Selection Sort)
void selection_sort(long *t,long n) //t-tabloul si n-marimea acestuia
{
    long i,j,min,aux;
    for(i=1;i<=n-1;i++)
    {
        min=i;
        for(j=i+1;j<=n;j++)
        {
            if(t[min]>t[j])
                min=j;
        }
        swap(&t[min],&t[i]);
    }
}
//Algoritmul de sortare prin metoda bulelor (Bubble Sort)
void bubble_sort(long *t,long n) //t-tabloul si n-marimea acestuia
{
    long i,j,aux;
    bool swapped;
    for (i=1;i<=n-1;i++)
    {
        swapped=false;
        for (j=1;j<=n-i-1;j++)
        {
            if (t[j]>t[j+1])
            {
                swap(&t[j],&t[j+1]);
                swapped=true;
            }
        }
        if (swapped==false)
            break;
    }
}
//Algoritmul de sortare prin insertie (Insertion Sort)
void insertion_sort(long *t,long n) //t-tabloul si n-marimea acestuia
{
    long i,j,aux;
    for (i=1;i<=n;i++)
    {
        aux=t[i];
        j=i-1;
        while (j>=1 && t[j]>aux)
        {
            t[j+1]=t[j];
            j--;
        }
        t[j+1]=aux;
    }
}
//Algoritmul de sortare prin interclasare (Merge Sort)
void merge_operation(long *t, long ls, long m, long ld) //Functia de interclasare (merge) a 2 tablouri (se foloseste doar de functia merge_sort)
{ 
    long i,j,k;
    const long n1=m-ls+1;
    const long n2=ld-m;
    long *L=(long *)malloc(n1*sizeof(long)),*D=(long *)malloc(n2*sizeof(long));
    for (i = 0; i < n1; i++)
        L[i] = t[ls + i];
    for (j = 0; j < n2; j++)
        D[j] = t[m + 1 + j];
    i=j=0;
    k=ls;
    while (i < n1 && j < n2)
    {
        if (L[i] <= D[j])
        {
            t[k]=L[i];
            i++;
        }
        else
        {
            t[k]=D[j];
            j++;
        }
        k++;
    }
    while (i<n1)
    {
        t[k] = L[i];
        i++;
        k++;
    }
    while (j<n2)
    {
        t[k] = D[j];
        j++;
        k++;
    }
}

void merge_sort(long *t, long ls, long ld) //Functia centrala de sortare prin interclasare
{ //pentru declarare se foloseste prototipul merge_sort(t,1,n), unde t-tabloul, n-marimea tabloului si 1-valoarea de inceput(nu se schimba niciodata la declarare)
    long m;
    if (ls<ld)
    {
        m=ls+(ld-ls)/2;
        merge_sort(t,ls,m);
        merge_sort(t,m+1,ld);
        merge_operation(t, ls, m, ld);
    }
}
//Algoritmul de sortare radix (Radix Sort)
long Max(long *t, long n) //Functia de gasire a maximului dintr-un tablou
{ //folosit doar de functia radix_sort
    long mx=t[1],i;
    for (i=2;i<=n;i++)
        if(t[i]>mx)
            mx=t[i];
    return mx;
}
void count_sort(long t[], long n, long exp) //functia secundara de sortare radix, unde ea este efectuata dupa a 'exp' cifra din valorile din tablou
{ //folosit doar de functia radix_sort
    long output[102],i;
    long count[10]={0};
    for (i=1;i<=n;i++)
        count[(t[i]/exp)%10]++;
    for (i=1;i<10;i++)
        count[i]+=count[i-1];
    for (i=n;i>=1;i--)
    {
        output[count[(t[i]/exp)%10]]=t[i];
        count[(t[i]/exp)%10]--;
    }
    for (i=1;i<=n; i++)
        t[i]=output[i];
}

void radix_sort(long t[], long n) //Functia centrala de sortare radix
{ //t-tabloul si n-marimea acestuia
    long m=Max(t,n),exp;
    for (exp=1;m/exp>0;exp*=10)
        count_sort(t,n,exp);
}
//Algoritmii de sortare rapida (Quick Sort)
long partition_by_lp(long *t, long mn, long mx) //Operatia de partitie dupa pivot, unde pivotul este elementul de la sfarsitul tabloului
{ //folosit doar de functia quick_sort_lp
    long pivot=t[mx];
    long i=mn-1,j;
    for (j=mn;j<=mx-1;j++)
    {
        if (t[j]<pivot)
        {
            i++;
            swap(&t[i],&t[j]);
        }
    }
    swap(&t[i+1],&t[mx]);
    return i+1;
}

void quick_sort_lp(long *t, long mn, long mx) //Functia principala de sortare rapida (dupa ultimul pivot)
{  //pentru declarare se foloseste prototipul quick_sort_lp(t,1,n), unde t-tabloul, n-marimea tabloului si 1-valoarea de inceput(nu se schimba niciodata la declarare)
    if (mn<mx)
    {
        long pi=partition_by_lp(t,mn,mx);
        quick_sort_lp(t,mn,pi-1);
        quick_sort_lp(t,pi+1,mx);
    }
}

long partition_by_fp(long *t, long mn, long mx) //Operatia de partitie dupa pivot, unde pivotul este elementul de la inceputul tabloului
{ //folosit doar de functia quick_sort_fp
    long pivot = t[mn];
    long k = mx;
    for (long i = mx; i > mn; i--)
    {
        if (t[i] > pivot)
            swap(&t[i], &t[k--]);
    }
    swap(&t[mn], &t[k]);
    return k;
}

void quick_sort_fp(long *t, long mn, long mx) //Functia principala de sortare rapida (dupa primul pivot)
{ //pentru declarare se foloseste prototipul quick_sort_fp(t,1,n), unde t-tabloul, n-marimea tabloului si 1-valoarea de inceput(nu se schimba niciodata la declarare)
    if (mn<mx)
    {
        long pi=partition_by_fp(t,mn,mx);
        quick_sort_fp(t,mn,pi-1);
        quick_sort_fp(t,pi+1,mx);
    }
}

void quick_sort_mp(long *t,long mn,long mx) //Functia principala de sortare rapida (dupa un pivot aleatoriu)
{ //pentru declarare se foloseste prototipul quick_sort_rp(t,1,n), unde t-tabloul, n-marimea tabloului si 1-valoarea de inceput(nu se schimba niciodata la declarare)
    long i,j;
    if (mn<mx) 
    {
        long x=(mx+mn)/2;
        long pivot=t[x];
        swap(&t[x], &t[mx]);
        long i=mn-1;
        for (j=mn;j<mx;j++)
        {
            if (t[j]<pivot) 
            {
                i++;
                swap(&t[i], &t[j]);
            }
        }
        swap(&t[i+1],&t[mx]);
        quick_sort_mp(t,mn,i);
        quick_sort_mp(t,i+2,mx);
    }
}

void quick_sort_rp(long *t,long mn,long mx) //Functia principala de sortare rapida (dupa un pivot aleatoriu)
{ //pentru declarare se foloseste prototipul quick_sort_rp(t,1,n), unde t-tabloul, n-marimea tabloului si 1-valoarea de inceput(nu se schimba niciodata la declarare)
    long i,j;
    if (mn<mx) 
    {
        srand(time(NULL));
        long x=mn+(rand()%(mx-mn))+1;
        long pivot=t[x];
        swap(&t[x],&t[mx]);
        long i=mn-1;
        for (j=mn;j<mx;j++)
        {
            if (t[j]<pivot) 
            {
                i++;
                swap(&t[i], &t[j]);
            }
        }
        swap(&t[i+1],&t[mx]);
        quick_sort_rp(t,mn,i);
        quick_sort_rp(t,i+2,mx);
    }
}

#endif