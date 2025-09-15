
/* WARNING: Unknown calling convention */

void * rpl_memchr(void *s,int c_in,size_t n)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  longword repeated_c;
  uint uVar5;
  
  uVar1 = c_in & 0xff;
  puVar4 = (uint *)n;
  if (n != 0) {
    puVar4 = (uint *)s;
    if (((uint)s & 3) == 0) {
LAB_0003f288:
      uVar5 = uVar1 | uVar1 << 8;
      uVar5 = uVar5 | uVar5 << 0x10;
      if (3 < n) {
        uVar3 = *puVar4 ^ uVar5;
        for (uVar3 = uVar3 + 0xfefefeff & ~uVar3; (uVar3 & 0x80808080) == 0;
            uVar3 = uVar3 + 0xfefefeff & ~uVar3) {
          puVar4 = puVar4 + 1;
          n = n - 4;
          if (n < 4) {
            if (n == 0) {
              return (void *)0x0;
            }
            break;
          }
          uVar3 = *puVar4 ^ uVar5;
        }
      }
      if ((byte)*puVar4 != uVar1) {
        puVar2 = (uint *)((int)puVar4 + n);
        do {
          puVar4 = (uint *)((int)puVar4 + 1);
          if (puVar4 == puVar2) {
            return (void *)0x0;
          }
        } while (*(byte *)puVar4 != uVar1);
      }
    }
    else {
                    /* WARNING: Load size is inaccurate */
      if (*s != uVar1) {
        puVar2 = (uint *)((int)s + 1);
        do {
          puVar4 = puVar2;
          n = n - 1;
          if (n == 0) {
            return (void *)0x0;
          }
          if (((uint)puVar4 & 3) == 0) goto LAB_0003f288;
          puVar2 = (uint *)((int)puVar4 + 1);
        } while ((byte)*puVar4 != uVar1);
      }
    }
  }
  return puVar4;
}

