
undefined4 SSL_CTX_use_serverinfo(int param_1,byte *param_2,uint param_3)

{
  int iVar1;
  void *pvVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  byte *pbVar6;
  
  if ((param_1 == 0 || param_2 == (byte *)0x0) || (param_3 == 0)) {
    ERR_put_error(0x14,0x150,0x43,"ssl_rsa.c",0x371);
    return 0;
  }
  if ((1 < param_3) && (1 < param_3 - 2)) {
    uVar3 = (uint)param_2[3] + (uint)param_2[2] * 0x100;
    if (uVar3 <= param_3 - 4) {
      pbVar6 = param_2 + uVar3 + 4;
      for (uVar3 = (param_3 - 4) - uVar3; uVar3 != 0; uVar3 = (uVar3 - 4) - uVar4) {
        if ((uVar3 < 2) || (uVar3 - 2 < 2)) goto LAB_000822c4;
        uVar4 = (uint)pbVar6[3] + (uint)pbVar6[2] * 0x100;
        pbVar6 = pbVar6 + uVar4 + 4;
        if (uVar3 - 4 < uVar4) goto LAB_000822c4;
      }
      iVar1 = ssl_cert_inst(param_1 + 0xb0);
      if (iVar1 == 0) {
        iVar1 = 0x379;
LAB_000822e8:
        ERR_put_error(0x14,0x150,0x41,"ssl_rsa.c",iVar1);
        return 0;
      }
      iVar1 = **(int **)(param_1 + 0xb0);
      if (iVar1 == 0) {
        ERR_put_error(0x14,0x150,0x44,"ssl_rsa.c",0x37d);
        return 0;
      }
      pvVar2 = CRYPTO_realloc(*(void **)(iVar1 + 0x10),param_3,"ssl_rsa.c",0x381);
      piVar5 = *(int **)(param_1 + 0xb0);
      *(void **)(iVar1 + 0x10) = pvVar2;
      pvVar2 = *(void **)(*piVar5 + 0x10);
      if (pvVar2 == (void *)0x0) {
        iVar1 = 899;
        goto LAB_000822e8;
      }
      memcpy(pvVar2,param_2,param_3);
      *(uint *)(**(int **)(param_1 + 0xb0) + 0x14) = param_3;
      do {
        iVar1 = SSL_CTX_add_server_custom_ext
                          (param_1,(uint)param_2[1] + (uint)*param_2 * 0x100,0x812d1,0,0,0x812c1,0);
        if ((iVar1 == 0) || (param_3 - 2 < 2)) break;
        uVar3 = (uint)param_2[3] + (uint)param_2[2] * 0x100;
        param_2 = param_2 + uVar3 + 4;
        if (param_3 - 4 < uVar3) break;
        param_3 = (param_3 - 4) - uVar3;
        if (param_3 == 0) {
          return 1;
        }
      } while (param_3 != 1);
      iVar1 = 0x38e;
      goto LAB_000822c8;
    }
  }
LAB_000822c4:
  iVar1 = 0x375;
LAB_000822c8:
  ERR_put_error(0x14,0x150,0x184,"ssl_rsa.c",iVar1);
  return 0;
}

