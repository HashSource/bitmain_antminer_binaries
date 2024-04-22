
void * rpl_memchr(void *s,int c_in,size_t n)

{
  uchar uVar1;
  uint uVar2;
  size_t n_local;
  int c_in_local;
  void *s_local;
  longword longword1;
  longword repeated_c;
  longword repeated_one;
  uchar c;
  longword *longword_ptr;
  uchar *char_ptr;
  
  uVar1 = (uchar)c_in;
  n_local = n;
  for (char_ptr = (uchar *)s; (n_local != 0 && (((uint)char_ptr & 3) != 0)); char_ptr = char_ptr + 1
      ) {
    if (uVar1 == *char_ptr) {
      return char_ptr;
    }
    n_local = n_local - 1;
  }
  longword_ptr = (longword *)char_ptr;
  while ((3 < n_local &&
         (uVar2 = *longword_ptr ^ CONCAT22(CONCAT11(uVar1,uVar1),CONCAT11(uVar1,uVar1)),
         (uVar2 + 0xfefefeff & ~uVar2 & 0x80808080) == 0))) {
    longword_ptr = longword_ptr + 1;
    n_local = n_local - 4;
  }
  char_ptr = (uchar *)longword_ptr;
  while( true ) {
    if (n_local == 0) {
      return (void *)0x0;
    }
    if (uVar1 == *char_ptr) break;
    n_local = n_local - 1;
    char_ptr = char_ptr + 1;
  }
  return char_ptr;
}

