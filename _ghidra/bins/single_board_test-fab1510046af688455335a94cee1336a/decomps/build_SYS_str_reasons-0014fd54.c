
void build_SYS_str_reasons(void)

{
  int iVar1;
  int iVar2;
  char *__src;
  int __errnum;
  
  CRYPTO_lock(5,1,"err.c",0x247);
  if (init_7539 == 0) {
    CRYPTO_lock(6,1,"err.c",0x249);
    return;
  }
  CRYPTO_lock(6,1,"err.c",0x24d);
  CRYPTO_lock(9,1,"err.c",0x24e);
  if (init_7539 != 0) {
    __errnum = 1;
    do {
      iVar2 = __errnum + -1;
      iVar1 = iVar2 * 8;
      *(int *)(SYS_str_reasons + iVar2 * 8) = __errnum;
      if (*(int *)(SYS_str_reasons + iVar1 + 4) == 0) {
        __src = strerror(__errnum);
        if (__src == (char *)0x0) {
          if (*(int *)(SYS_str_reasons + iVar1 + 4) == 0) {
            *(char **)(SYS_str_reasons + iVar1 + 4) = "unknown";
          }
        }
        else {
          strncpy(strerror_tab_7537 + iVar2 * 0x20,__src,0x20);
          strerror_tab_7537[iVar2 * 0x20 + 0x1f] = 0;
          *(undefined1 **)(SYS_str_reasons + iVar1 + 4) = strerror_tab_7537 + iVar2 * 0x20;
        }
      }
      __errnum = __errnum + 1;
    } while (__errnum != 0x80);
    init_7539 = 0;
    CRYPTO_lock(10,1,"err.c",0x26c);
    return;
  }
  CRYPTO_lock(10,1,"err.c",0x250);
  return;
}

