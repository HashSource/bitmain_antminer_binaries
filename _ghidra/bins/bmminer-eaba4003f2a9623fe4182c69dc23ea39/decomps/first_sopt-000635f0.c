
char * first_sopt(uint *i)

{
  uint *i_local;
  uint len;
  char *p;
  
  len = 0;
  for (p = first_opt(i,&len); (p != (char *)0x0 && (*p == '-')); p = next_opt(p,i,&len)) {
  }
  return p;
}

