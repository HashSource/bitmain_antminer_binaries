
int ssl3_write_pending(int param_1,int param_2,int param_3,uint param_4,undefined4 *param_5)

{
  int iVar1;
  int *piVar2;
  BIO *b;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  bool bVar9;
  
  if ((param_4 < *(uint *)(param_1 + 0xf10)) ||
     (((-1 < *(int *)(param_1 + 0x4f0) << 0x1e && (*(int *)(param_1 + 0xf1c) != param_3)) ||
      (*(int *)(param_1 + 0xf14) != param_2)))) {
    ossl_statem_fatal(param_1,0x50,0x9f,0x7f,"ssl/record/rec_layer_s3.c",0x47f);
    return -1;
  }
  iVar5 = *(int *)(param_1 + 0x688);
  uVar8 = 0;
  piVar2 = __errno_location();
  iVar7 = 0;
  while( true ) {
    iVar3 = iVar7 + uVar8;
    iVar1 = iVar3 * 4;
    while ((iVar1 = param_1 + 0x678 + iVar1, iVar5 == 0 && (uVar8 < *(int *)(param_1 + 0x660) - 1U))
          ) {
      uVar8 = uVar8 + 1;
      iVar5 = *(int *)(iVar1 + 0x24);
      iVar7 = uVar8 * 4;
      iVar3 = uVar8 * 5;
      iVar1 = uVar8 * 0x14;
    }
    b = *(BIO **)(param_1 + 0xc);
    *piVar2 = 0;
    if (b == (BIO *)0x0) break;
    iVar6 = *(int *)(param_1 + 0x678 + iVar3 * 4);
    iVar5 = *(int *)(iVar1 + 0xc);
    iVar3 = *(int *)(iVar1 + 0x10);
    *(undefined4 *)(param_1 + 0x14) = 2;
    iVar3 = BIO_write(b,(void *)(iVar5 + iVar6),iVar3);
    if ((iVar3 < 0) || (iVar3 == 0)) goto LAB_000d5714;
    iVar5 = *(int *)(iVar1 + 0x10) - iVar3;
    if (iVar3 == *(int *)(iVar1 + 0x10)) {
      uVar4 = *(uint *)(param_1 + 0x660);
      iVar5 = 0;
      *(undefined4 *)(iVar1 + 0x10) = 0;
      *(int *)(iVar1 + 0xc) = iVar3 + *(int *)(iVar1 + 0xc);
      if (uVar4 <= uVar8 + 1) {
        *(undefined4 *)(param_1 + 0x14) = 1;
        *param_5 = *(undefined4 *)(param_1 + 0xf18);
        return 1;
      }
    }
    else {
      *(int *)(iVar1 + 0x10) = iVar5;
      *(int *)(iVar1 + 0xc) = iVar3 + *(int *)(iVar1 + 0xc);
    }
  }
  ossl_statem_fatal(param_1,0x50,0x9f,0x80,"ssl/record/rec_layer_s3.c",0x496);
  iVar3 = -1;
LAB_000d5714:
  iVar7 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) << 0x1c;
  bVar9 = iVar7 < 0;
  if (bVar9) {
    iVar7 = 0;
  }
  if (bVar9) {
    *(int *)(iVar1 + 0x10) = iVar7;
  }
  return iVar3;
}

