
void OPENSSL_INIT_new(void)

{
  void *pvVar1;
  
  pvVar1 = calloc(0xc,1);
  if (pvVar1 != (void *)0x0) {
    *(undefined4 *)((int)pvVar1 + 8) = 0x32;
  }
  return;
}

