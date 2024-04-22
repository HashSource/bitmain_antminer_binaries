
undefined4 SSL_CTX_use_serverinfo(int param_1,byte *param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  byte *pbVar7;
  
  if ((param_1 == 0 || param_2 == (byte *)0x0) || (param_3 == 0)) {
    ERR_put_error(0x14,0x150,0x43,DAT_0008231c,0x371);
    return 0;
  }
  if ((1 < param_3) && (1 < param_3 - 2)) {
    uVar4 = (uint)param_2[3] + (uint)param_2[2] * 0x100;
    if (uVar4 <= param_3 - 4) {
      pbVar7 = param_2 + uVar4 + 4;
      for (uVar4 = (param_3 - 4) - uVar4; uVar4 != 0; uVar4 = (uVar4 - 4) - uVar5) {
        if ((uVar4 < 2) || (uVar4 - 2 < 2)) goto LAB_000822c4;
        uVar5 = (uint)pbVar7[3] + (uint)pbVar7[2] * 0x100;
        pbVar7 = pbVar7 + uVar5 + 4;
        if (uVar4 - 4 < uVar5) goto LAB_000822c4;
      }
      iVar2 = ssl_cert_inst(param_1 + 0xb0);
      if (iVar2 == 0) {
        iVar2 = 0x379;
LAB_000822e8:
        ERR_put_error(0x14,0x150,0x41,DAT_0008231c,iVar2);
        return 0;
      }
      iVar2 = **(int **)(param_1 + 0xb0);
      if (iVar2 == 0) {
        ERR_put_error(0x14,0x150,0x44,DAT_0008231c,0x37d);
        return 0;
      }
      pvVar3 = CRYPTO_realloc(*(void **)(iVar2 + 0x10),param_3,DAT_0008231c,0x381);
      piVar6 = *(int **)(param_1 + 0xb0);
      *(void **)(iVar2 + 0x10) = pvVar3;
      uVar1 = DAT_00082320;
      pvVar3 = *(void **)(*piVar6 + 0x10);
      if (pvVar3 == (void *)0x0) {
        iVar2 = 899;
        goto LAB_000822e8;
      }
      memcpy(pvVar3,param_2,param_3);
      *(uint *)(**(int **)(param_1 + 0xb0) + 0x14) = param_3;
      do {
        iVar2 = SSL_CTX_add_server_custom_ext
                          (param_1,(uint)param_2[1] + (uint)*param_2 * 0x100,DAT_00082324,0,0,uVar1,
                           0);
        if ((iVar2 == 0) || (param_3 - 2 < 2)) break;
        uVar4 = (uint)param_2[3] + (uint)param_2[2] * 0x100;
        param_2 = param_2 + uVar4 + 4;
        if (param_3 - 4 < uVar4) break;
        param_3 = (param_3 - 4) - uVar4;
        if (param_3 == 0) {
          return 1;
        }
      } while (param_3 != 1);
      iVar2 = 0x38e;
      goto LAB_000822c8;
    }
  }
LAB_000822c4:
  iVar2 = 0x375;
LAB_000822c8:
  ERR_put_error(0x14,0x150,0x184,DAT_0008231c,iVar2);
  return 0;
}

