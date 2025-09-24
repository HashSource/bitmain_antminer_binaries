
uchar * OPENSSL_utf82uni(char *param_1,size_t param_2,uchar **param_3,int *param_4)

{
  int iVar1;
  uchar *puVar2;
  uchar *puVar3;
  int iVar4;
  int iVar5;
  uchar *puVar6;
  int iVar7;
  int local_34;
  ulong local_2c [2];
  
  local_2c[0] = 0;
  if (param_2 == 0xffffffff) {
    param_2 = strlen(param_1);
  }
  if ((int)param_2 < 1) {
    puVar2 = (uchar *)CRYPTO_malloc(2,"crypto/pkcs12/p12_utl.c",0x75);
    if (puVar2 == (uchar *)0x0) goto LAB_001ba87a;
    local_34 = 2;
    puVar3 = puVar2;
  }
  else {
    iVar5 = 0;
    local_34 = 0;
    do {
      iVar1 = UTF8_getc((uchar *)(param_1 + iVar5),param_2 - iVar5,local_2c);
      if (iVar1 < 0) {
        puVar2 = OPENSSL_asc2uni(param_1,param_2,param_3,param_4);
        return puVar2;
      }
      if (0x10ffff < local_2c[0]) {
        return (uchar *)0x0;
      }
      iVar5 = iVar5 + iVar1;
      if (local_2c[0] < 0x10000) {
        local_34 = local_34 + 2;
      }
      else {
        local_34 = local_34 + 4;
      }
    } while (iVar5 < (int)param_2);
    local_34 = local_34 + 2;
    puVar3 = (uchar *)CRYPTO_malloc(local_34,"crypto/pkcs12/p12_utl.c",0x75);
    if (puVar3 == (uchar *)0x0) {
LAB_001ba87a:
      ERR_put_error(0x23,0x81,0x41,"crypto/pkcs12/p12_utl.c",0x76);
      return (uchar *)0x0;
    }
    iVar5 = 0;
    puVar6 = puVar3;
    do {
      while( true ) {
        iVar1 = UTF8_getc((uchar *)(param_1 + iVar5),param_2 - iVar5,local_2c);
        if (0xffff < local_2c[0]) break;
        puVar2 = puVar6 + 2;
        *puVar6 = (uchar)(local_2c[0] >> 8);
        iVar5 = iVar5 + iVar1;
        puVar6[1] = (uchar)local_2c[0];
        puVar6 = puVar2;
        if ((int)param_2 <= iVar5) goto LAB_001ba832;
      }
      iVar7 = (local_2c[0] - 0x10000 >> 10) + 0xd800;
      iVar4 = (local_2c[0] & 0x3ff) + 0xdc00;
      iVar5 = iVar5 + iVar1;
      puVar6[3] = (uchar)iVar4;
      puVar6[1] = (uchar)iVar7;
      puVar6[2] = (uchar)((uint)iVar4 >> 8);
      puVar2 = puVar6 + 4;
      *puVar6 = (uchar)((uint)iVar7 >> 8);
      puVar6 = puVar2;
      local_2c[0] = local_2c[0] - 0x10000;
    } while (iVar5 < (int)param_2);
  }
LAB_001ba832:
  *puVar2 = '\0';
  puVar2[1] = '\0';
  if (param_4 != (int *)0x0) {
    *param_4 = local_34;
  }
  if (param_3 == (uchar **)0x0) {
    return puVar3;
  }
  *param_3 = puVar3;
  return puVar3;
}

