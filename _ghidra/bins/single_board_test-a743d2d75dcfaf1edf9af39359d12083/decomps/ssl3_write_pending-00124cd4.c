
int ssl3_write_pending(int *param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  BIO *b;
  int iVar4;
  int iVar5;
  bool bVar6;
  bool bVar7;
  
  iVar5 = param_1[0x16];
  if ((param_4 < *(int *)(iVar5 + 0x168)) ||
     (((*(int *)(iVar5 + 0x174) != param_3 && (-1 < param_1[0x41] << 0x1e)) ||
      (*(int *)(iVar5 + 0x16c) != param_2)))) {
    ERR_put_error(0x14,0x9f,0x7f,"s3_pkt.c",0x449);
    iVar2 = -1;
  }
  else {
    piVar1 = __errno_location();
    while( true ) {
      b = (BIO *)param_1[4];
      *piVar1 = 0;
      if (b == (BIO *)0x0) break;
      iVar3 = *(int *)(iVar5 + 0x104);
      iVar2 = *(int *)(iVar5 + 0xfc);
      iVar4 = *(int *)(iVar5 + 0x108);
      param_1[6] = 2;
      iVar2 = BIO_write(b,(void *)(iVar2 + iVar3),iVar4);
      if (iVar2 == *(int *)(iVar5 + 0x108)) goto LAB_00124d86;
      if (iVar2 < 1) goto LAB_00124d6a;
      *(int *)(iVar5 + 0x108) = *(int *)(iVar5 + 0x108) - iVar2;
      *(int *)(iVar5 + 0x104) = *(int *)(iVar5 + 0x104) + iVar2;
    }
    ERR_put_error(0x14,0x9f,0x80,"s3_pkt.c",0x455);
    iVar2 = *(int *)(iVar5 + 0x108);
    if (iVar2 == -1) {
LAB_00124d86:
      iVar4 = param_1[0x16];
      *(undefined4 *)(iVar5 + 0x108) = 0;
      *(int *)(iVar5 + 0x104) = *(int *)(iVar5 + 0x104) + iVar2;
      iVar2 = *(int *)(iVar4 + 0x170);
      param_1[6] = 1;
    }
    else {
      iVar2 = -1;
LAB_00124d6a:
      iVar4 = *param_1;
      bVar6 = iVar4 == 0xfeff;
      bVar7 = iVar4 == 0x100;
      if (bVar6 || bVar7) {
        iVar4 = 0;
      }
      if (bVar6 || bVar7) {
        *(int *)(iVar5 + 0x108) = iVar4;
      }
    }
  }
  return iVar2;
}

