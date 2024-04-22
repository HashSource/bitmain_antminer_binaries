
int ssl3_write_pending(int *param_1,int param_2,int param_3,int param_4)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  BIO *b;
  int iVar5;
  int iVar6;
  bool bVar7;
  
  iVar6 = param_1[0x16];
  if ((param_4 < *(int *)(iVar6 + 0x168)) ||
     (((*(int *)(iVar6 + 0x174) != param_3 && (-1 < param_1[0x41] << 0x1e)) ||
      (*(int *)(iVar6 + 0x16c) != param_2)))) {
    ERR_put_error(0x14,0x9f,0x7f,DAT_0006bd84,0x449);
    iVar3 = -1;
  }
  else {
    piVar2 = __errno_location();
    while( true ) {
      b = (BIO *)param_1[4];
      *piVar2 = 0;
      if (b == (BIO *)0x0) break;
      iVar4 = *(int *)(iVar6 + 0x104);
      iVar3 = *(int *)(iVar6 + 0xfc);
      iVar5 = *(int *)(iVar6 + 0x108);
      param_1[6] = 2;
      iVar3 = BIO_write(b,(void *)(iVar3 + iVar4),iVar5);
      if (iVar3 == *(int *)(iVar6 + 0x108)) goto LAB_0006bd4e;
      if (iVar3 < 1) goto LAB_0006bd32;
      *(int *)(iVar6 + 0x108) = *(int *)(iVar6 + 0x108) - iVar3;
      *(int *)(iVar6 + 0x104) = *(int *)(iVar6 + 0x104) + iVar3;
    }
    ERR_put_error(0x14,0x9f,0x80,DAT_0006bd84,0x455);
    iVar3 = *(int *)(iVar6 + 0x108);
    if (iVar3 == -1) {
LAB_0006bd4e:
      iVar5 = param_1[0x16];
      *(undefined4 *)(iVar6 + 0x108) = 0;
      *(int *)(iVar6 + 0x104) = *(int *)(iVar6 + 0x104) + iVar3;
      iVar3 = *(int *)(iVar5 + 0x170);
      param_1[6] = 1;
    }
    else {
      iVar3 = -1;
LAB_0006bd32:
      iVar5 = *param_1;
      bVar7 = iVar5 == 0xfeff;
      bVar1 = iVar5 == 0x100;
      if (bVar7 || bVar1) {
        iVar5 = 0;
      }
      if (bVar7 || bVar1) {
        *(int *)(iVar6 + 0x108) = iVar5;
      }
    }
  }
  return iVar3;
}

