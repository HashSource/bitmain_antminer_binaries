
bool BIO_write_ex(int *param_1,undefined4 param_2,int param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  code *pcVar5;
  
  if (param_1 == (int *)0x0) {
    return false;
  }
  if ((*param_1 == 0) || (*(int *)(*param_1 + 8) == 0)) {
    ERR_put_error(0x20,0x80,0x79,"crypto/bio/bio_lib.c",0x149);
    return false;
  }
  pcVar5 = (code *)param_1[2];
  if ((code *)param_1[1] == (code *)0x0) {
    if (pcVar5 != (code *)0x0) goto LAB_00118548;
  }
  else {
    if (pcVar5 == (code *)0x0) {
      if (param_3 < 0) {
        return false;
      }
      iVar1 = (*(code *)param_1[1])(param_1,3,param_2,param_3,0,1);
    }
    else {
LAB_00118548:
      iVar1 = (*pcVar5)(param_1,3,param_2,param_3,0,0,1,0);
    }
    if (iVar1 < 1) {
      return false;
    }
  }
  if (param_1[4] == 0) {
    ERR_put_error(0x20,0x80,0x78,"crypto/bio/bio_lib.c",0x153);
    return false;
  }
  uVar2 = (**(code **)(*param_1 + 8))(param_1,param_2,param_3,param_4);
  if (0 < (int)uVar2) {
    uVar4 = param_1[0x10];
    uVar3 = *param_4;
    param_1[0x10] = uVar4 + uVar3;
    param_1[0x11] = param_1[0x11] + (uint)CARRY4(uVar4,uVar3);
  }
  pcVar5 = (code *)param_1[2];
  if ((code *)param_1[1] == (code *)0x0) {
    if (pcVar5 == (code *)0x0) goto LAB_001185e8;
  }
  else if (pcVar5 == (code *)0x0) {
    if (param_3 < 0) {
      return false;
    }
    if ((0 < (int)uVar2) && (uVar2 = *param_4, (int)uVar2 < 0)) {
      return false;
    }
    uVar2 = (*(code *)param_1[1])(param_1,0x83,param_2,param_3,0,uVar2);
    if ((int)uVar2 < 1) {
      return false;
    }
    *param_4 = uVar2;
    return true;
  }
  uVar2 = (*pcVar5)(param_1,0x83,param_2,param_3,0,0,uVar2,param_4);
LAB_001185e8:
  return 0 < (int)uVar2;
}

