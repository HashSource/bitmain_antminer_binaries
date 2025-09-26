
void ERR_add_error_vdata(int num,va_list args)

{
  undefined1 *ptr;
  size_t sVar1;
  ERR_STATE *pEVar2;
  int iVar3;
  char *__s;
  int iVar4;
  undefined1 *addr;
  int iVar5;
  undefined4 *puVar6;
  char *local_2c;
  
  ptr = (undefined1 *)CRYPTO_malloc(0x51,"crypto/err/err.c",0x374);
  if (ptr != (undefined1 *)0x0) {
    iVar3 = 0;
    *ptr = 0;
    if (0 < num) {
      puVar6 = (undefined4 *)((int)args + -4);
      iVar4 = 0;
      iVar5 = 0x50;
      local_2c = "<NULL>";
      addr = ptr;
      do {
        puVar6 = puVar6 + 1;
        __s = (char *)*puVar6;
        if (__s == (char *)0x0) {
          sVar1 = 6;
          __s = local_2c;
        }
        else {
          sVar1 = strlen(__s);
        }
        iVar3 = iVar3 + sVar1;
        iVar4 = iVar4 + 1;
        ptr = addr;
        if (iVar5 < iVar3) {
          ptr = (undefined1 *)CRYPTO_realloc(addr,iVar3 + 0x15,"crypto/err/err.c",0x382);
          iVar5 = iVar3 + 0x14;
          if (ptr == (undefined1 *)0x0) {
            CRYPTO_free(addr);
            return;
          }
        }
        OPENSSL_strlcat(ptr,__s,iVar5 + 1);
        addr = ptr;
      } while (num != iVar4);
    }
    pEVar2 = ERR_get_state();
    if (pEVar2 == (ERR_STATE *)0x0) {
      CRYPTO_free(ptr);
      return;
    }
    iVar3 = pEVar2->err_line[0xe];
    if ((int)pEVar2->err_data[iVar3 + 0xe] << 0x1f < 0) {
      CRYPTO_free((void *)pEVar2->err_buffer[iVar3 + 0xe]);
    }
    pEVar2->err_buffer[iVar3 + 0xe] = (ulong)ptr;
    pEVar2->err_data[iVar3 + 0xe] = (char *)0x3;
  }
  return;
}

