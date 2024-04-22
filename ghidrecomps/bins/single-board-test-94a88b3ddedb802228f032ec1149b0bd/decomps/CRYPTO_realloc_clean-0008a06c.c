
void * CRYPTO_realloc_clean(void *addr,int old_num,int num,char *file,int line)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  
  iVar1 = DAT_0008a100;
  if (addr != (void *)0x0) {
    if ((num < 1) || (num < old_num)) {
      pvVar3 = (void *)0x0;
    }
    else {
      if (*(code **)(DAT_0008a100 + 4) != (code *)0x0) {
        (**(code **)(DAT_0008a100 + 4))();
      }
      iVar2 = DAT_0008a104;
      pvVar3 = (void *)(**(code **)(DAT_0008a104 + 0x10))(num,file,line);
      if (pvVar3 != (void *)0x0) {
        memcpy(pvVar3,addr,old_num);
        OPENSSL_cleanse(addr,old_num);
        (**(code **)(iVar2 + 0x18))(addr);
      }
      if (*(code **)(iVar1 + 4) != (code *)0x0) {
        (**(code **)(iVar1 + 4))(addr,pvVar3,num,file,line,1);
      }
    }
    return pvVar3;
  }
  pvVar3 = CRYPTO_malloc(num,file,line);
  return pvVar3;
}

