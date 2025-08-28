
/* WARNING: Unknown calling convention */

char * first_sopt(uint *i)

{
  char *p;
  uint local_14 [2];
  
  local_14[0] = 0;
  p = first_opt(i,local_14);
  while( true ) {
    if (p == (char *)0x0) {
      return (char *)0x0;
    }
    if (*p != '-') break;
    p = next_opt(p,i,local_14);
  }
  return p;
}

