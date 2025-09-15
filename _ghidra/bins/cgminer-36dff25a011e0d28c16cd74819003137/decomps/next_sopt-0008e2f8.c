
char * next_sopt(char *p,uint *i)

{
  uint *i_local;
  char *p_local;
  uint len;
  
  len = 1;
  for (p_local = next_opt(p,i,&len); (p_local != (char *)0x0 && (*p_local == '-'));
      p_local = next_opt(p_local,i,&len)) {
  }
  return p_local;
}

