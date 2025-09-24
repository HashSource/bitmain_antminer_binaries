
undefined4 tls_process_certificate_request(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined1 *puVar2;
  void *pvVar3;
  int *piVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  byte *pbVar9;
  undefined4 uVar10;
  void *local_2c;
  undefined1 *local_28;
  uint local_24;
  
  iVar7 = *(int *)(param_1 + 0x7c);
  memset((void *)(iVar7 + 0x27c),0,0x24);
  pvVar3 = (void *)(*(uint *)((*(int **)(param_1 + 4))[0x19] + 0x30) & 8);
  if ((pvVar3 == (void *)0x0) &&
     (iVar1 = **(int **)(param_1 + 4), iVar1 != 0x10000 && 0x303 < iVar1)) {
    if ((*(uint *)(param_1 + 0x28) & 1) != 0) {
      return 1;
    }
    local_2c = pvVar3;
    CRYPTO_free(*(void **)(iVar7 + 0x21c));
    iVar7 = *(int *)(param_1 + 0x7c);
    pvVar3 = *(void **)(param_1 + 0x5fc);
    *(undefined4 *)(iVar7 + 0x21c) = 0;
    *(undefined4 *)(iVar7 + 0x220) = 0;
    CRYPTO_free(pvVar3);
    *(undefined4 *)(param_1 + 0x5fc) = 0;
    *(undefined4 *)(param_1 + 0x600) = 0;
    if (param_2[1] != 0) {
      uVar5 = param_2[1] - 1;
      pbVar9 = (byte *)*param_2 + 1;
      uVar8 = (uint)*(byte *)*param_2;
      if (uVar8 <= uVar5) {
        *param_2 = pbVar9 + uVar8;
        param_2[1] = uVar5 - uVar8;
        CRYPTO_free(*(void **)(param_1 + 0x5fc));
        *(undefined4 *)(param_1 + 0x5fc) = 0;
        *(undefined4 *)(param_1 + 0x600) = 0;
        if (uVar8 != 0) {
          iVar7 = CRYPTO_memdup(pbVar9,uVar8,"ssl/statem/../packet_local.h",0x1ce);
          *(int *)(param_1 + 0x5fc) = iVar7;
          if (iVar7 == 0) goto LAB_000f058c;
          *(uint *)(param_1 + 0x600) = uVar8;
        }
        if (1 < (uint)param_2[1]) {
          puVar2 = (undefined1 *)*param_2;
          uVar5 = param_2[1] - 2;
          uVar8 = (uint)CONCAT11(*puVar2,puVar2[1]);
          if (uVar8 <= uVar5) {
            local_28 = puVar2 + 2;
            *param_2 = local_28 + uVar8;
            param_2[1] = uVar5 - uVar8;
            local_24 = uVar8;
            iVar7 = tls_collect_extensions(param_1,&local_28,0x4000,&local_2c,0,1);
            if ((iVar7 == 0) ||
               (iVar7 = tls_parse_all_extensions(param_1,0x4000,local_2c,0,0,1), iVar7 == 0)) {
              CRYPTO_free(local_2c);
              return 0;
            }
            CRYPTO_free(local_2c);
            iVar7 = tls1_process_sigalgs(param_1);
            if (iVar7 == 0) {
              ossl_statem_fatal(param_1,0x50,0x169,0x10f,"ssl/statem/statem_clnt.c",0x9c4);
              return 0;
            }
            goto LAB_000f0506;
          }
        }
        uVar10 = 0x9b4;
        uVar6 = 0x10f;
        goto LAB_000f059a;
      }
    }
LAB_000f058c:
    uVar10 = 0x9ad;
    uVar6 = 0x9f;
LAB_000f059a:
    ossl_statem_fatal(param_1,0x32,0x169,uVar6,"ssl/statem/statem_clnt.c",uVar10);
    return 0;
  }
  if (param_2[1] != 0) {
    uVar5 = param_2[1] - 1;
    pbVar9 = (byte *)*param_2 + 1;
    uVar8 = (uint)*(byte *)*param_2;
    if (uVar8 <= uVar5) {
      param_2[1] = uVar5 - uVar8;
      *param_2 = pbVar9 + uVar8;
      iVar7 = *(int *)(param_1 + 0x7c);
      CRYPTO_free(*(void **)(iVar7 + 0x21c));
      *(undefined4 *)(iVar7 + 0x21c) = 0;
      *(undefined4 *)(iVar7 + 0x220) = 0;
      if (uVar8 != 0) {
        iVar1 = CRYPTO_memdup(pbVar9,uVar8,"ssl/statem/../packet_local.h",0x1ce);
        *(int *)(iVar7 + 0x21c) = iVar1;
        if (iVar1 == 0) {
          ossl_statem_fatal(param_1,0x50,0x169,0x44,"ssl/statem/statem_clnt.c",0x9d5);
          return 0;
        }
        *(uint *)(iVar7 + 0x220) = uVar8;
      }
      if (*(int *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) << 0x1e < 0) {
        if (1 < (uint)param_2[1]) {
          local_28 = (undefined1 *)*param_2;
          uVar5 = param_2[1] - 2;
          local_24 = (uint)CONCAT11(*local_28,local_28[1]);
          if (local_24 <= uVar5) {
            local_28 = local_28 + 2;
            *param_2 = local_28 + local_24;
            param_2[1] = uVar5 - local_24;
            iVar7 = tls1_save_sigalgs(param_1,&local_28,0);
            if (iVar7 == 0) {
              ossl_statem_fatal(param_1,0x50,0x169,0x168,"ssl/statem/statem_clnt.c",0x9ea);
              return 0;
            }
            iVar7 = tls1_process_sigalgs(param_1);
            if (iVar7 == 0) {
              ossl_statem_fatal(param_1,0x50,0x169,0x41,"ssl/statem/statem_clnt.c",0x9f0);
              return 0;
            }
            goto LAB_000f04fa;
          }
        }
        uVar6 = 0x9df;
        goto LAB_000f049a;
      }
LAB_000f04fa:
      iVar7 = parse_ca_names(param_1,param_2);
      if (iVar7 == 0) {
        return 0;
      }
LAB_000f0506:
      if (param_2[1] == 0) {
        piVar4 = *(int **)(param_1 + 4);
        iVar7 = piVar4[0x19];
        *(undefined4 *)(*(int *)(param_1 + 0x7c) + 0x218) = 1;
        if ((*(int *)(iVar7 + 0x30) << 0x1c < 0) ||
           (iVar7 = *piVar4, iVar7 == 0x10000 || iVar7 < 0x304)) {
          uVar6 = 2;
        }
        else if (*(int *)(param_1 + 0x5f4) == 4) {
          uVar6 = 2;
        }
        else {
          uVar6 = 3;
        }
        return uVar6;
      }
      uVar10 = 0x9ff;
      uVar6 = 0x9f;
      goto LAB_000f059a;
    }
  }
  uVar6 = 0x9ce;
LAB_000f049a:
  ossl_statem_fatal(param_1,0x32,0x169,0x9f,"ssl/statem/statem_clnt.c",uVar6);
  return 0;
}

