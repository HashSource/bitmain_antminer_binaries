
char * first_opt(uint *i,uint *len)

{
  char *pcVar1;
  uint *len_local;
  uint *i_local;
  
  *i = 0;
  while( true ) {
    if (opt_count <= *i) {
      return (char *)0x0;
    }
    if (opt_table[*i].type != OPT_SUBTABLE) break;
    *i = *i + 1;
  }
  pcVar1 = first_name(opt_table[*i].names,len);
  return pcVar1;
}

