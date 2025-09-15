
/* WARNING: Unknown calling convention */

char * next_sopt(char *p,uint *i)

{
  char *p_00;
  uint local_14 [2];
  
  local_14[0] = 1;
  p_00 = next_opt(p,i,local_14);
  while( true ) {
    if (p_00 == (char *)0x0) {
      return (char *)0x0;
    }
    if (*p_00 != '-') break;
    p_00 = next_opt(p_00,i,local_14);
  }
  return p_00;
}

