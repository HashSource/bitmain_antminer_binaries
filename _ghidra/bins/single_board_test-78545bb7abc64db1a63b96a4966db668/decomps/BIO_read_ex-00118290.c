
undefined4 BIO_read_ex(int *param_1,undefined4 param_2,uint param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  code *pcVar5;
  
  if (((param_1 == (int *)0x0) || (*param_1 == 0)) || (*(int *)(*param_1 + 0x10) == 0)) {
    ERR_put_error(0x20,0x78,0x79,"crypto/bio/bio_lib.c",0x100);
    return 0;
  }
  pcVar5 = (code *)param_1[2];
  if ((code *)param_1[1] == (code *)0x0) {
    if (pcVar5 != (code *)0x0) goto LAB_001182dc;
  }
  else {
    if (pcVar5 == (code *)0x0) {
      if ((int)param_3 < 0) {
        return 0;
      }
      iVar1 = (*(code *)param_1[1])(param_1,2,param_2,param_3,0,1);
    }
    else {
LAB_001182dc:
      iVar1 = (*pcVar5)(param_1,2,param_2,param_3,0,0,1,0);
    }
    if (iVar1 < 1) {
      return 0;
    }
  }
  if (param_1[4] == 0) {
    ERR_put_error(0x20,0x78,0x78,"crypto/bio/bio_lib.c",0x10a);
    return 0;
  }
  uVar2 = (**(code **)(*param_1 + 0x10))(param_1,param_2,param_3,param_4);
  if (0 < (int)uVar2) {
    uVar4 = param_1[0xe];
    uVar3 = *param_4;
    param_1[0xe] = uVar4 + uVar3;
    param_1[0xf] = param_1[0xf] + (uint)CARRY4(uVar4,uVar3);
  }
  pcVar5 = (code *)param_1[2];
  if ((code *)param_1[1] == (code *)0x0) {
    if (pcVar5 != (code *)0x0) goto LAB_00118356;
  }
  else {
    if (pcVar5 == (code *)0x0) {
      if ((int)param_3 < 0) {
        return 0;
      }
      if ((0 < (int)uVar2) && (uVar2 = *param_4, (int)uVar2 < 0)) {
        return 0;
      }
      uVar2 = (*(code *)param_1[1])(param_1,0x82,param_2,param_3,0,uVar2);
      if ((int)uVar2 < 1) {
        return 0;
      }
      *param_4 = uVar2;
      goto LAB_00118370;
    }
LAB_00118356:
    uVar2 = (*pcVar5)(param_1,0x82,param_2,param_3,0,0,uVar2,param_4);
  }
  if ((int)uVar2 < 1) {
    return 0;
  }
  uVar2 = *param_4;
LAB_00118370:
  if (param_3 < uVar2) {
    ERR_put_error(0x20,0x78,0x44,"crypto/bio/bio_lib.c",0x119);
    return 0;
  }
  return 1;
}

