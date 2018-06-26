main(){int n, c[2], o, t; while ( scanf("%d", &n) == 1 ){
*c=1[c]=o=0;while (n-- && scanf("%d", &t) > 0)if(t&1)o=!o,++1[c];else++*c;
printf("%d\n", c[o]);
} return 0;}