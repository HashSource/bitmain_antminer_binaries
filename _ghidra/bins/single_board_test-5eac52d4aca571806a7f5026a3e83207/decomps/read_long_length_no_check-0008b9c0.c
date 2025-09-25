
size_t read_long_length_no_check(BYTE **pp)

{
  byte bVar1;
  BYTE **pp_local;
  size_t b;
  size_t l;
  
  l = 0;
  do {
    bVar1 = **pp;
    *pp = *pp + 1;
    l = bVar1 + l;
  } while (bVar1 == 0xff);
  return l;
}

