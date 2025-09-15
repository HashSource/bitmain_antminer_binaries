
char * first_lopt(uint *i,uint *len)

{
  uint *len_local;
  uint *i_local;
  char *p;
  
  p = first_opt(i,len);
  while( true ) {
    if (p == (char *)0x0) {
      return (char *)0x0;
    }
    if (*p == '-') break;
    p = next_opt(p,i,len);
  }
  *len = *len - 1;
  return p + 1;
}

