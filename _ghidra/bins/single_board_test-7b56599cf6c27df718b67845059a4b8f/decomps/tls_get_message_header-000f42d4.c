
undefined4 tls_get_message_header(undefined4 *param_1,uint *param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  undefined4 uVar4;
  byte *pbVar5;
  undefined4 uVar6;
  int local_28;
  int local_24 [2];
  
  uVar3 = param_1[0x1d];
  pbVar5 = *(byte **)(param_1[0x1b] + 4);
  do {
    while (3 < uVar3) {
      if (param_1[7] != 0) {
        uVar3 = (uint)*pbVar5;
LAB_000f4368:
        *param_2 = uVar3;
        *(uint *)(param_1[0x1f] + 0x20c) = (uint)*pbVar5;
        iVar1 = RECORD_LAYER_is_sslv2_record(param_1 + 0x194);
        if (iVar1 == 0) {
          iVar1 = *(int *)(param_1[0x1b] + 4);
          *(uint *)(param_1[0x1f] + 0x208) =
               (uint)pbVar5[2] << 8 | (uint)pbVar5[1] << 0x10 | (uint)pbVar5[3];
          param_1[0x1c] = iVar1 + 4;
          param_1[0x1d] = 0;
        }
        else {
          iVar1 = RECORD_LAYER_get_rrec_length(param_1 + 0x194);
          uVar4 = *(undefined4 *)(param_1[0x1b] + 4);
          *(int *)(param_1[0x1f] + 0x208) = iVar1 + 4;
          param_1[0x1d] = 4;
          param_1[0x1c] = uVar4;
        }
        return 1;
      }
      uVar3 = (uint)*pbVar5;
      if (((param_1[0x10] == 1) || (uVar3 != 0)) || (pbVar5[1] != 0)) goto LAB_000f4368;
      if (pbVar5[2] != 0) {
        uVar3 = 0;
        goto LAB_000f4368;
      }
      uVar3 = 0;
      if (pbVar5[3] != 0) goto LAB_000f4368;
      param_1[0x1d] = 0;
      if ((code *)param_1[0x21] == (code *)0x0) {
        uVar3 = 0;
        break;
      }
      (*(code *)param_1[0x21])(0,*param_1,0x16,pbVar5,4,param_1,param_1[0x22]);
      uVar3 = param_1[0x1d];
    }
    iVar1 = (**(code **)(param_1[1] + 0x38))
                      (param_1,0x16,&local_28,pbVar5 + uVar3,4 - uVar3,0,local_24);
    if (iVar1 < 1) {
      param_1[5] = 3;
      return 0;
    }
    if (local_28 == 0x14) {
      if (((param_1[0x1d] == 0) && (local_24[0] == 1)) && (*pbVar5 == 1)) {
        piVar2 = (int *)param_1[0x1f];
        if ((param_1[0x10] == 0) && (*piVar2 << 0x14 < 0)) {
          return 0;
        }
        iVar1 = param_1[0x1b];
        *param_2 = 0x101;
        uVar4 = *(undefined4 *)(iVar1 + 4);
        piVar2[0x83] = 0x101;
        param_1[0x1d] = 0;
        param_1[0x1c] = uVar4;
        piVar2[0x82] = 1;
        return 1;
      }
      uVar6 = 0x498;
      uVar4 = 0x67;
      goto LAB_000f43d8;
    }
    if (local_28 != 0x16) {
      uVar6 = 0x4ae;
      uVar4 = 0x85;
LAB_000f43d8:
      ossl_statem_fatal(param_1,10,0x183,uVar4,"ssl/statem/statem_lib.c",uVar6);
      return 0;
    }
    uVar3 = local_24[0] + param_1[0x1d];
    param_1[0x1d] = uVar3;
    local_28 = 0x16;
  } while( true );
}

