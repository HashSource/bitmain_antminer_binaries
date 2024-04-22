
/* WARNING: Unknown calling convention */

char * first_sopt(uint *i)

{
  char *p_00;
  char *p;
  uint local_14 [2];
  
  local_14[0] = 0;
  p_00 = first_opt(i,local_14);
  while( true ) {
    if (p_00 == (char *)0x0) {
      return (char *)0x0;
    }
    if (*p_00 != '-') break;
    p_00 = next_opt(p_00,i,local_14);
  }
  return p_00;
}

