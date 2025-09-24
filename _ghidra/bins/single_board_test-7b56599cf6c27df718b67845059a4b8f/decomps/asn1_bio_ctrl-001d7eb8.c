
long asn1_bio_ctrl(BIO *param_1,int param_2,long param_3,int *param_4)

{
  int *piVar1;
  BIO *bp;
  long lVar2;
  BIO *b;
  int iVar3;
  int iVar4;
  code *pcVar5;
  
  piVar1 = (int *)BIO_get_data();
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  bp = BIO_next(param_1);
  if (param_2 == 0x97) {
    iVar3 = param_4[1];
    piVar1[10] = *param_4;
    piVar1[0xb] = iVar3;
    return 1;
  }
  if (0x97 < param_2) {
    if (param_2 == 0x99) {
      piVar1[0xf] = (int)param_4;
      return 1;
    }
    if (param_2 < 0x99) {
      iVar3 = piVar1[0xb];
      *param_4 = piVar1[10];
      param_4[1] = iVar3;
      return 1;
    }
    if (param_2 == 0x9a) {
      *param_4 = piVar1[0xf];
      return 1;
    }
LAB_001d7f32:
    if (bp == (BIO *)0x0) {
      return 0;
    }
    lVar2 = BIO_ctrl(bp,param_2,param_3,param_4);
    return lVar2;
  }
  if (param_2 == 0x95) {
    iVar3 = param_4[1];
    piVar1[8] = *param_4;
    piVar1[9] = iVar3;
    return 1;
  }
  if (0x95 < param_2) {
    iVar3 = piVar1[9];
    *param_4 = piVar1[8];
    param_4[1] = iVar3;
    return 1;
  }
  if (param_2 != 0xb) goto LAB_001d7f32;
  if (bp == (BIO *)0x0) {
    return 0;
  }
  iVar3 = *piVar1;
  if (iVar3 == 2) {
    if (((code *)piVar1[10] != (code *)0x0) &&
       (iVar3 = (*(code *)piVar1[10])(param_1,piVar1 + 0xc,piVar1 + 0xd,piVar1 + 0xf), iVar3 == 0))
    goto LAB_001d7f08;
    if (piVar1[0xd] < 1) {
      iVar3 = 6;
    }
    else {
      iVar3 = 5;
    }
    *piVar1 = iVar3;
  }
  if (iVar3 == 5) {
    if (0 < piVar1[0xd]) {
      pcVar5 = (code *)piVar1[0xb];
      while( true ) {
        b = BIO_next(param_1);
        iVar3 = BIO_write(b,(void *)(piVar1[0xc] + piVar1[0xe]),piVar1[0xd]);
        if (iVar3 < 1) {
          return iVar3;
        }
        iVar4 = piVar1[0xd];
        piVar1[0xd] = iVar4 - iVar3;
        if (iVar4 - iVar3 < 1) break;
        piVar1[0xe] = iVar3 + piVar1[0xe];
      }
      if (pcVar5 != (code *)0x0) {
        (*pcVar5)(param_1,piVar1 + 0xc,piVar1 + 0xd,piVar1 + 0xf);
      }
      *piVar1 = 6;
      piVar1[0xe] = 0;
      goto LAB_001d7f86;
    }
  }
  else if (iVar3 == 6) {
LAB_001d7f86:
    lVar2 = BIO_ctrl(bp,0xb,param_3,param_4);
    return lVar2;
  }
LAB_001d7f08:
  BIO_clear_flags(param_1,0xf);
  return 0;
}

