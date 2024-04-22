
long asn1_bio_ctrl(BIO *param_1,int param_2,long param_3,int *param_4)

{
  long lVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  code *pcVar5;
  
  piVar4 = (int *)param_1->ptr;
  if (piVar4 == (int *)0x0) {
    return 0;
  }
  if (param_2 == 0x97) {
    iVar3 = param_4[1];
    piVar4[10] = *param_4;
    piVar4[0xb] = iVar3;
    return 1;
  }
  if (0x97 < param_2) {
    if (param_2 == 0x99) {
      piVar4[0xf] = (int)param_4;
      return 1;
    }
    if (param_2 < 0x99) {
      iVar3 = piVar4[0xb];
      *param_4 = piVar4[10];
      param_4[1] = iVar3;
      return 1;
    }
    if (param_2 == 0x9a) {
      *param_4 = piVar4[0xf];
      return 1;
    }
LAB_0012bff8:
    if (param_1->next_bio == (BIO *)0x0) {
      return 0;
    }
    lVar1 = BIO_ctrl(param_1->next_bio,param_2,param_3,param_4);
    return lVar1;
  }
  if (param_2 == 0x95) {
    iVar3 = param_4[1];
    piVar4[8] = *param_4;
    piVar4[9] = iVar3;
    return 1;
  }
  if (0x95 < param_2) {
    iVar3 = piVar4[9];
    *param_4 = piVar4[8];
    param_4[1] = iVar3;
    return 1;
  }
  if (param_2 != 0xb) goto LAB_0012bff8;
  if (param_1->next_bio == (bio_st *)0x0) {
    return 0;
  }
  iVar3 = *piVar4;
  if (iVar3 == 2) {
    if (((code *)piVar4[10] != (code *)0x0) &&
       (iVar3 = (*(code *)piVar4[10])(param_1,piVar4 + 0xc,piVar4 + 0xd,piVar4 + 0xf), iVar3 == 0))
    goto LAB_0012c034;
    if (piVar4[0xd] < 1) {
      iVar3 = 6;
    }
    else {
      iVar3 = 5;
    }
    *piVar4 = iVar3;
  }
  if (iVar3 == 5) {
    iVar3 = piVar4[0xd];
    pcVar5 = (code *)piVar4[0xb];
    if (0 < iVar3) {
      iVar2 = piVar4[0xe];
      while( true ) {
        iVar2 = BIO_write(param_1->next_bio,(void *)(piVar4[0xc] + iVar2),iVar3);
        if (iVar2 < 1) {
          return iVar2;
        }
        iVar3 = piVar4[0xd] - iVar2;
        piVar4[0xd] = iVar3;
        if (iVar3 < 1) break;
        iVar2 = iVar2 + piVar4[0xe];
        piVar4[0xe] = iVar2;
      }
      if (pcVar5 != (code *)0x0) {
        (*pcVar5)(param_1,piVar4 + 0xc,piVar4 + 0xd,piVar4 + 0xf);
      }
      *piVar4 = 6;
      piVar4[0xe] = 0;
      goto LAB_0012c0a2;
    }
  }
  else if (iVar3 == 6) {
LAB_0012c0a2:
    lVar1 = BIO_ctrl(param_1->next_bio,0xb,param_3,param_4);
    return lVar1;
  }
LAB_0012c034:
  BIO_clear_flags(param_1,0xf);
  return 0;
}

