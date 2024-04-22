
int asn1_bio_write_part_0(BIO *param_1,void *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  code *pcVar6;
  uchar *local_2c [2];
  
  puVar5 = (undefined4 *)param_1->ptr;
  if (puVar5 == (undefined4 *)0x0) {
    return 0;
  }
  iVar4 = 0;
  uVar2 = *puVar5;
  do {
    switch(uVar2) {
    case 0:
      if (((code *)puVar5[8] != (code *)0x0) &&
         (iVar1 = (*(code *)puVar5[8])(param_1,puVar5 + 0xc,puVar5 + 0xd,puVar5 + 0xf), iVar1 == 0))
      {
        BIO_clear_flags(param_1,0xf);
        return 0;
      }
      if ((int)puVar5[0xd] < 1) {
        uVar2 = 2;
      }
      else {
        uVar2 = 1;
      }
      *puVar5 = uVar2;
      break;
    case 1:
      iVar3 = puVar5[0xd];
      pcVar6 = (code *)puVar5[9];
      if (0 < iVar3) {
        iVar1 = puVar5[0xe];
        while( true ) {
          iVar1 = BIO_write(param_1->next_bio,(void *)(puVar5[0xc] + iVar1),iVar3);
          if (iVar1 < 1) goto LAB_0012c2a4;
          iVar3 = puVar5[0xd] - iVar1;
          puVar5[0xd] = iVar3;
          if (iVar3 < 1) break;
          iVar1 = iVar1 + puVar5[0xe];
          puVar5[0xe] = iVar1;
        }
        if (pcVar6 != (code *)0x0) {
          (*pcVar6)(param_1,puVar5 + 0xc,puVar5 + 0xd,puVar5 + 0xf);
        }
        uVar2 = 2;
        *puVar5 = 2;
        puVar5[0xe] = 0;
      }
      break;
    case 2:
      iVar1 = ASN1_object_size(0,param_3,puVar5[7]);
      puVar5[4] = iVar1 - param_3;
      if ((int)puVar5[2] < iVar1 - param_3) {
        OpenSSLDie(DAT_0012c360,0xe8,DAT_0012c364);
      }
      local_2c[0] = (uchar *)puVar5[1];
      ASN1_put_object(local_2c,0,param_3,puVar5[7],puVar5[6]);
      uVar2 = 3;
      puVar5[5] = param_3;
      *puVar5 = 3;
      break;
    case 3:
      iVar1 = BIO_write(param_1->next_bio,(void *)(puVar5[1] + puVar5[3]),puVar5[4]);
      if (iVar1 < 1) {
LAB_0012c2a4:
        BIO_clear_flags(param_1,0xf);
        if (iVar4 == 0) {
          iVar4 = iVar1;
        }
        BIO_copy_next_retry(param_1);
        return iVar4;
      }
      iVar3 = puVar5[4];
      puVar5[4] = iVar3 - iVar1;
      if (iVar3 - iVar1 == 0) {
        uVar2 = 4;
        puVar5[3] = 0;
        *puVar5 = 4;
      }
      else {
        uVar2 = *puVar5;
        puVar5[3] = puVar5[3] + iVar1;
      }
      break;
    case 4:
      iVar1 = puVar5[5];
      if (param_3 < (int)puVar5[5]) {
        iVar1 = param_3;
      }
      iVar1 = BIO_write(param_1->next_bio,param_2,iVar1);
      if (0 < iVar1) {
        iVar3 = puVar5[5];
        iVar4 = iVar4 + iVar1;
        param_2 = (void *)((int)param_2 + iVar1);
        param_3 = param_3 - iVar1;
        puVar5[5] = iVar3 - iVar1;
        if (iVar3 - iVar1 == 0) {
          *puVar5 = 2;
        }
        if (param_3 == 0) {
          BIO_clear_flags(param_1,0xf);
          BIO_copy_next_retry(param_1);
          return iVar4;
        }
      }
      uVar2 = *puVar5;
      break;
    default:
      BIO_clear_flags(param_1,0xf);
      return 0;
    }
  } while( true );
}

