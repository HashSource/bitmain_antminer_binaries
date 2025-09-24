
int asn1_bio_write(BIO *param_1,void *param_2,int param_3)

{
  undefined4 *puVar1;
  BIO *b;
  int iVar2;
  BIO *b_00;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  void *local_34;
  uchar *local_2c [2];
  
  puVar1 = (undefined4 *)BIO_get_data();
  b = BIO_next(param_1);
  if ((param_2 == (void *)0x0 || param_3 < 0) || (b == (BIO *)0x0 || puVar1 == (undefined4 *)0x0)) {
    return 0;
  }
  iVar5 = 0;
  uVar3 = *puVar1;
  local_34 = param_2;
  do {
    switch(uVar3) {
    case 0:
      if (((code *)puVar1[8] != (code *)0x0) &&
         (iVar2 = (*(code *)puVar1[8])(param_1,puVar1 + 0xc,puVar1 + 0xd,puVar1 + 0xf), iVar2 == 0))
      {
        BIO_clear_flags(param_1,0xf);
        return 0;
      }
      if ((int)puVar1[0xd] < 1) {
        uVar3 = 2;
      }
      else {
        uVar3 = 1;
      }
      *puVar1 = uVar3;
      break;
    case 1:
      pcVar6 = (code *)puVar1[9];
      if (0 < (int)puVar1[0xd]) {
        while( true ) {
          b_00 = BIO_next(param_1);
          iVar2 = BIO_write(b_00,(void *)(puVar1[0xc] + puVar1[0xe]),puVar1[0xd]);
          if (iVar2 < 1) goto LAB_001d8156;
          iVar4 = puVar1[0xd];
          puVar1[0xd] = iVar4 - iVar2;
          if (iVar4 - iVar2 < 1) break;
          puVar1[0xe] = iVar2 + puVar1[0xe];
        }
        if (pcVar6 != (code *)0x0) {
          (*pcVar6)(param_1,puVar1 + 0xc,puVar1 + 0xd,puVar1 + 0xf);
        }
        *puVar1 = 2;
        puVar1[0xe] = 0;
        uVar3 = 2;
      }
      break;
    case 2:
      iVar2 = ASN1_object_size(0,param_3,puVar1[7]);
      puVar1[4] = iVar2 - param_3;
      if ((int)puVar1[2] < iVar2 - param_3) {
        return 0;
      }
      local_2c[0] = (uchar *)puVar1[1];
      ASN1_put_object(local_2c,0,param_3,puVar1[7],puVar1[6]);
      uVar3 = 3;
      puVar1[5] = param_3;
      *puVar1 = 3;
      break;
    case 3:
      iVar2 = BIO_write(b,(void *)(puVar1[1] + puVar1[3]),puVar1[4]);
      if (iVar2 < 1) {
LAB_001d8156:
        BIO_clear_flags(param_1,0xf);
        BIO_copy_next_retry(param_1);
        if (iVar5 != 0) {
          return iVar5;
        }
        return iVar2;
      }
      iVar4 = puVar1[4];
      puVar1[4] = iVar4 - iVar2;
      if (iVar4 - iVar2 == 0) {
        uVar3 = 4;
        puVar1[3] = 0;
        *puVar1 = 4;
      }
      else {
        uVar3 = *puVar1;
        puVar1[3] = iVar2 + puVar1[3];
      }
      break;
    case 4:
      iVar2 = puVar1[5];
      if (param_3 <= (int)puVar1[5]) {
        iVar2 = param_3;
      }
      iVar2 = BIO_write(b,local_34,iVar2);
      if (iVar2 < 1) goto LAB_001d8156;
      iVar4 = puVar1[5];
      local_34 = (void *)((int)local_34 + iVar2);
      iVar5 = iVar5 + iVar2;
      param_3 = param_3 - iVar2;
      puVar1[5] = iVar4 - iVar2;
      if (iVar4 - iVar2 == 0) {
        *puVar1 = 2;
      }
      if (param_3 == 0) {
        BIO_clear_flags(param_1,0xf);
        BIO_copy_next_retry(param_1);
        return iVar5;
      }
      uVar3 = *puVar1;
      break;
    case 5:
    case 6:
      BIO_clear_flags(param_1,0xf);
      return 0;
    }
  } while( true );
}

