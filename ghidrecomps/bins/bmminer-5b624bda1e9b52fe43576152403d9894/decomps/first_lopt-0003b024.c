
/* WARNING: Unknown calling convention */

char * first_lopt(uint *i,uint *len)

{
  char *p_00;
  char *p;
  
  p_00 = first_opt(i,len);
  while( true ) {
    if (p_00 == (char *)0x0) {
      return (char *)0x0;
    }
    if (*p_00 == '-') break;
    p_00 = next_opt(p_00,i,len);
  }
  *len = *len - 1;
  return p_00 + 1;
}

