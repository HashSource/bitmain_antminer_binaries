
void ERR_add_error_vdata(int num,va_list args)

{
  char *dst;
  size_t sVar1;
  ERR_STATE *pEVar2;
  int iVar3;
  char *__s;
  int iVar4;
  int iVar5;
  char *addr;
  int iVar6;
  
  dst = (char *)CRYPTO_malloc(0x51,DAT_000ae4f4,0x441);
  if (dst != (char *)0x0) {
    iVar3 = 0;
    *dst = '\0';
    if (0 < num) {
      iVar4 = (int)args + 4;
      iVar5 = 0;
      iVar6 = 0x50;
      addr = dst;
      do {
        __s = *(char **)(iVar4 + -4);
        iVar5 = iVar5 + 1;
        iVar4 = iVar4 + 4;
        dst = addr;
        if (__s != (char *)0x0) {
          sVar1 = strlen(__s);
          iVar3 = sVar1 + iVar3;
          if (iVar6 < iVar3) {
            dst = (char *)CRYPTO_realloc(addr,iVar3 + 0x15,DAT_000ae4f4,0x44e);
            iVar6 = iVar3 + 0x14;
            if (dst == (char *)0x0) {
              CRYPTO_free(addr);
              return;
            }
          }
          BUF_strlcat(dst,__s,iVar6 + 1);
        }
        addr = dst;
      } while (iVar5 != num);
    }
    pEVar2 = ERR_get_state();
    iVar3 = pEVar2->top;
    if (iVar3 == 0) {
      iVar3 = 0xf;
    }
    if ((pEVar2->err_data[iVar3] != (char *)0x0) && (pEVar2->err_data_flags[iVar3] << 0x1f < 0)) {
      CRYPTO_free(pEVar2->err_data[iVar3]);
    }
    pEVar2->err_data[iVar3] = dst;
    pEVar2->err_data_flags[iVar3] = 3;
  }
  return;
}

