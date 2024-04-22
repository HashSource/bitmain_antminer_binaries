
void * CRYPTO_remalloc(void *addr,int num,char *file,int line)

{
  int iVar1;
  void *pvVar2;
  
  iVar1 = DAT_0008a168;
  if (addr != (void *)0x0) {
    if (*(code **)(DAT_0008a168 + 8) != (code *)0x0) {
      (**(code **)(DAT_0008a168 + 8))(addr,0);
    }
    (**(code **)(DAT_0008a16c + 0x18))(addr);
    if (*(code **)(iVar1 + 8) != (code *)0x0) {
      (**(code **)(iVar1 + 8))(0,1);
    }
  }
  pvVar2 = CRYPTO_malloc(num,DAT_0008a170,0x1c3);
  return pvVar2;
}

