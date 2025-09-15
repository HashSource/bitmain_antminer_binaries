
/* WARNING: Unknown calling convention */

char * next_lopt(char *p,uint *i,uint *len)

{
  char *p_00;
  
  p_00 = next_opt(p,i,len);
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

