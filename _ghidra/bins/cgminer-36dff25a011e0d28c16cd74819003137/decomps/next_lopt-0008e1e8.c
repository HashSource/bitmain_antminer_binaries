
char * next_lopt(char *p,uint *i,uint *len)

{
  uint *len_local;
  uint *i_local;
  char *p_local;
  
  p_local = next_opt(p,i,len);
  while( true ) {
    if (p_local == (char *)0x0) {
      return (char *)0x0;
    }
    if (*p_local == '-') break;
    p_local = next_opt(p_local,i,len);
  }
  *len = *len - 1;
  return p_local + 1;
}

