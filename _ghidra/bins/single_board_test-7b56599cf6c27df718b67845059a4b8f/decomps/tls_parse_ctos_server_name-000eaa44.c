
undefined4 tls_parse_ctos_server_name(int param_1,undefined4 *param_2)

{
  undefined1 *puVar1;
  size_t sVar2;
  void *pvVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  char *__s;
  undefined1 *__s_00;
  
  uVar4 = param_2[1];
  if (1 < uVar4) {
    puVar1 = (undefined1 *)*param_2;
    uVar5 = (uint)CONCAT11(*puVar1,puVar1[1]);
    if ((uVar5 <= uVar4 - 2) && (uVar5 == uVar4 - 2)) {
      *param_2 = puVar1 + uVar5 + 2;
      param_2[1] = 0;
      if (uVar5 != 0) {
        if ((puVar1[2] == '\0') && (1 < uVar4 - 3)) {
          __s_00 = puVar1 + 5;
          uVar5 = (uint)CONCAT11(puVar1[3],puVar1[4]);
          if ((uVar5 <= uVar4 - 5) && (uVar5 == uVar4 - 5)) {
            if ((*(int *)(param_1 + 0x8c) != 0) &&
               ((*(int *)((*(int **)(param_1 + 4))[0x19] + 0x30) << 0x1c < 0 ||
                (iVar7 = **(int **)(param_1 + 4), iVar7 == 0x10000 || iVar7 < 0x304)))) {
              __s = *(char **)(*(int *)(param_1 + 0x474) + 0x1cc);
              if (__s != (char *)0x0) {
                sVar2 = strlen(__s);
                if (sVar2 == uVar5) {
                  iVar7 = CRYPTO_memcmp(__s_00,__s,uVar5);
                  __s = (char *)(uint)(iVar7 == 0);
                }
                else {
                  __s = (char *)0x0;
                }
              }
              *(char **)(param_1 + 0x5cc) = __s;
              return 1;
            }
            if (uVar5 < 0x100) {
              pvVar3 = memchr(__s_00,0,uVar5);
              if (pvVar3 == (void *)0x0) {
                CRYPTO_free(*(void **)(param_1 + 0x538));
                *(undefined4 *)(param_1 + 0x538) = 0;
                CRYPTO_free((void *)0x0);
                iVar7 = CRYPTO_strndup(__s_00,uVar5,"ssl/statem/../packet_local.h",0x1e5);
                *(int *)(param_1 + 0x538) = iVar7;
                if (iVar7 != 0) {
                  *(undefined4 *)(param_1 + 0x5cc) = 1;
                  return 1;
                }
                ossl_statem_fatal(param_1,0x50,0x23d,0x44,"ssl/statem/extensions_srvr.c",0x9d);
                return 0;
              }
              uVar6 = 0x91;
            }
            else {
              uVar6 = 0x8a;
            }
            ossl_statem_fatal(param_1,0x70,0x23d,0x6e,"ssl/statem/extensions_srvr.c",uVar6);
            return 0;
          }
        }
        uVar6 = 0x7e;
        goto LAB_000eaa84;
      }
    }
  }
  uVar6 = 0x6b;
LAB_000eaa84:
  ossl_statem_fatal(param_1,0x32,0x23d,0x6e,"ssl/statem/extensions_srvr.c",uVar6);
  return 0;
}

