int D(const void *a, const void *b){return *(int*)b-*(int*)a;}
c[100];main(A,a,C,n,i,x,r,s){scanf("%d%d%d%d",&n,&A,&a,&C);for(i=0;i<n;i++)scanf("%d",c+i);qsort(c,n,4,D);for(r=C/A,x=i=0;i<n;i++){x+=c[i];s=(C+x)/(A+a*(i+1));if(s<r)break;r=s;}printf("%d\n",r);exit(0);}