
undefined4 tls_parse_stoc_renegotiate(int param_1,undefined4 *param_2)

{
  int iVar1;
  uint uVar2;
  size_t __n;
  byte *__s1;
  uint uVar3;
  size_t __n_00;
  int iVar4;
  byte *__s1_00;
  uint uVar5;
  
  iVar4 = *(int *)(param_1 + 0x7c);
  __n = *(size_t *)(iVar4 + 0x2f0);
  __n_00 = *(size_t *)(iVar4 + 0x334);
  uVar5 = __n + __n_00;
  if ((__n == 0 && uVar5 != 0) || (__n_00 == 0 && uVar5 != 0)) {
    ossl_statem_fatal(param_1,0x50,0x1c0,0x44,"ssl/statem/extensions_clnt.c",0x4e1);
  }
  else {
    if (param_2[1] == 0) {
      ossl_statem_fatal(param_1,0x32,0x1c0,0x150,"ssl/statem/extensions_clnt.c",0x4e8);
      return 0;
    }
    uVar3 = param_2[1] - 1;
    __s1 = (byte *)*param_2 + 1;
    uVar2 = (uint)*(byte *)*param_2;
    *param_2 = __s1;
    param_2[1] = uVar3;
    if (uVar2 == uVar3) {
      if (uVar5 == uVar2) {
        if (__n <= uVar5) {
          __s1_00 = __s1 + __n;
          param_2[1] = __n_00;
          *param_2 = __s1_00;
          iVar1 = memcmp(__s1,(void *)(iVar4 + 0x2b0),__n);
          if (iVar1 == 0) {
            *param_2 = __s1_00 + __n_00;
            param_2[1] = 0;
            iVar1 = memcmp(__s1_00,(void *)(iVar4 + 0x2f4),__n_00);
            if (iVar1 == 0) {
              *(undefined4 *)(iVar4 + 0x338) = 1;
              return 1;
            }
            ossl_statem_fatal(param_1,0x2f,0x1c0,0x151,"ssl/statem/extensions_clnt.c",0x506);
            return 0;
          }
        }
        ossl_statem_fatal(param_1,0x2f,0x1c0,0x151,"ssl/statem/extensions_clnt.c",0x4fe);
      }
      else {
        ossl_statem_fatal(param_1,0x2f,0x1c0,0x151,"ssl/statem/extensions_clnt.c",0x4f6);
      }
    }
    else {
      ossl_statem_fatal(param_1,0x32,0x1c0,0x150,"ssl/statem/extensions_clnt.c",0x4ef);
    }
  }
  return 0;
}

