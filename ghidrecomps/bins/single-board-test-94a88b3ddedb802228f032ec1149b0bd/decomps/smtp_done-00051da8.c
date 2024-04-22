
uint smtp_done(int *param_1,uint param_2)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  code **ppcVar6;
  int local_28;
  int iStack_24;
  int local_1c;
  
  ppcVar6 = DAT_00051ea0;
  iVar3 = *param_1;
  puVar4 = *(undefined4 **)(iVar3 + 0x14c);
  if (puVar4 == (undefined4 *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = param_1[0xfb];
    if (param_1[0xfb] != 0) {
      if (param_2 == 0) {
        if (((*(char *)(iVar3 + 0x329) == '\0') &&
            (param_2 = (uint)*(byte *)(iVar3 + 0x309), param_2 != 0)) &&
           (param_2 = *(uint *)(iVar3 + 0x404), param_2 != 0)) {
          if ((*(char *)(puVar4 + 4) == '\0') &&
             ((*(uint *)(iVar3 + 0x86b0) | *(uint *)(iVar3 + 0x86b4)) != 0)) {
            iVar5 = 5;
            iVar3 = (**DAT_00051ea4)(DAT_00051eac);
          }
          else {
            iVar5 = 3;
            iVar3 = (**DAT_00051ea4)(DAT_00051ea8);
          }
          if (iVar3 == 0) {
            return 0x1b;
          }
          uVar1 = Curl_write(param_1,param_1[0x8a],iVar3,iVar5,&local_1c);
          ppcVar6 = DAT_00051ea0;
          if (uVar1 != 0) {
            (**DAT_00051ea0)(iVar3);
            return uVar1;
          }
          if (local_1c == iVar5) {
            curlx_tvnow(&local_28);
            pcVar2 = *ppcVar6;
            param_1[0xf8] = local_28;
            param_1[0xf9] = iStack_24;
            (*pcVar2)(iVar3);
          }
          else {
            param_1[0xf7] = iVar5;
            ppcVar6 = DAT_00051ea0;
            param_1[0xf5] = iVar3;
            param_1[0xf6] = iVar5 - local_1c;
          }
          param_1[0xfe] = 0xb;
          param_2 = smtp_block_statemach(param_1);
        }
      }
      else {
        *(undefined *)((int)param_1 + 0x1ed) = 1;
      }
      (**ppcVar6)(puVar4[1]);
      puVar4[1] = 0;
      *puVar4 = 0;
      uVar1 = param_2;
    }
  }
  return uVar1;
}

