
undefined4 dtls_process_hello_verify(int param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  uint __n;
  
  uVar2 = param_2[1];
  if (1 < uVar2) {
    iVar1 = *param_2;
    param_2[1] = uVar2 - 2;
    *param_2 = iVar1 + 2;
    if (uVar2 - 2 != 0) {
      __n = (uint)*(byte *)(iVar1 + 2);
      if (__n <= uVar2 - 3) {
        *param_2 = iVar1 + 3 + __n;
        param_2[1] = (uVar2 - 3) - __n;
        memcpy(*(void **)(param_1 + 0x80),(void *)(iVar1 + 3),__n);
        *(uint *)(*(int *)(param_1 + 0x80) + 0x100) = __n;
        return 1;
      }
    }
  }
  ossl_statem_fatal(param_1,0x32,0x182,0x9f,"ssl/statem/statem_clnt.c",0x518);
  return 0;
}

