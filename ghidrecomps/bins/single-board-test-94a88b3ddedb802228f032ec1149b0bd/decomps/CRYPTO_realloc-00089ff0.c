
void * CRYPTO_realloc(void *addr,int num,char *file,int line)

{
  int iVar1;
  void *pvVar2;
  
  iVar1 = DAT_0008a064;
  if (addr != (void *)0x0) {
    if (num < 1) {
      pvVar2 = (void *)0x0;
    }
    else {
      if (*(code **)(DAT_0008a064 + 4) != (code *)0x0) {
        (**(code **)(DAT_0008a064 + 4))(addr,0,num,file,line,0);
      }
      pvVar2 = (void *)(**(code **)(DAT_0008a068 + 0x14))(addr,num,file,line);
      if (*(code **)(iVar1 + 4) != (code *)0x0) {
        (**(code **)(iVar1 + 4))(addr,pvVar2,num,file,line,1);
      }
    }
    return pvVar2;
  }
  pvVar2 = CRYPTO_malloc(num,file,line);
  return pvVar2;
}

