
char * next_opt(char *p,uint *i,uint *len)

{
  char *pcVar1;
  uint *len_local;
  uint *i_local;
  char *p_local;
  
  p_local = p;
  do {
    if (opt_count <= *i) {
      return (char *)0x0;
    }
    if (opt_table[*i].type != OPT_SUBTABLE) {
      if (p_local == (char *)0x0) {
        pcVar1 = first_name(opt_table[*i].names,len);
        return pcVar1;
      }
      p_local = next_name(p_local,len);
      if (p_local != (char *)0x0) {
        return p_local;
      }
    }
    *i = *i + 1;
  } while( true );
}

