
/* WARNING: Unknown calling convention */
/* Local variable c:uchar[r1:1] conflicts with parameter, skipped. */

void * rpl_memchr(void *s,int c_in,size_t n)

{
  uchar *char_ptr;
  longword *longword_ptr;
  uint uVar1;
  longword *plVar2;
  uint uVar3;
  longword longword1;
  longword repeated_c;
  uint uVar4;
  
  uVar1 = c_in & 0xff;
  longword_ptr = (longword *)n;
  if (n != 0) {
    longword_ptr = (longword *)s;
    if (((uint)s & 3) == 0) {
LAB_0003f288:
      uVar4 = uVar1 | uVar1 << 8;
      uVar4 = uVar4 | uVar4 << 0x10;
      if (3 < n) {
        uVar3 = *longword_ptr ^ uVar4;
        for (uVar3 = uVar3 + 0xfefefeff & ~uVar3; (uVar3 & 0x80808080) == 0;
            uVar3 = uVar3 + 0xfefefeff & ~uVar3) {
          longword_ptr = longword_ptr + 1;
          n = n - 4;
          if (n < 4) {
            if (n == 0) {
              return (void *)0x0;
            }
            break;
          }
          uVar3 = *longword_ptr ^ uVar4;
        }
      }
      if (*(byte *)longword_ptr != uVar1) {
        plVar2 = (longword *)((int)longword_ptr + n);
        do {
          longword_ptr = (longword *)((int)longword_ptr + 1);
          if (longword_ptr == plVar2) {
            return (void *)0x0;
          }
        } while (*(byte *)longword_ptr != uVar1);
      }
    }
    else {
                    /* WARNING: Load size is inaccurate */
      if (*s != uVar1) {
        plVar2 = (longword *)((int)s + 1);
        do {
          longword_ptr = plVar2;
          n = n - 1;
          if (n == 0) {
            return (void *)0x0;
          }
          if (((uint)longword_ptr & 3) == 0) goto LAB_0003f288;
          plVar2 = (longword *)((int)longword_ptr + 1);
        } while (*(byte *)longword_ptr != uVar1);
      }
    }
  }
  return longword_ptr;
}

