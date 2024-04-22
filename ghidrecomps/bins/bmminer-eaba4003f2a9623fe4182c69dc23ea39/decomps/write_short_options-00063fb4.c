
uint write_short_options(char *str)

{
  char *str_local;
  uint i;
  char *p;
  uint num;
  
  num = 0;
  for (p = first_sopt(&i); p != (char *)0x0; p = next_sopt(p,&i)) {
    if (opt_table[i].desc != opt_hidden) {
      str[num] = *p;
      num = num + 1;
    }
  }
  return num;
}

