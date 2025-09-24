
char * EC_POINT_point2hex(EC_GROUP *param_1,EC_POINT *param_2,point_conversion_form_t form,
                         BN_CTX *param_4)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  byte *pbVar5;
  int num;
  byte *local_1c [2];
  byte *pbVar6;
  
  local_1c[0] = (byte *)0x0;
  iVar3 = EC_POINT_point2buf(param_1,param_2,form,local_1c,param_4);
  if (iVar3 != 0) {
    num = (iVar3 + 1) * 2;
    pcVar4 = (char *)CRYPTO_malloc(num,"crypto/ec/ec_print.c",0x58);
    if (pcVar4 == (char *)0x0) {
      CRYPTO_free(local_1c[0]);
    }
    else {
      pbVar6 = local_1c[0];
      pcVar2 = pcVar4;
      do {
        pbVar5 = pbVar6 + 1;
        cVar1 = "0123456789ABCDEF"[(int)(uint)*pbVar6 >> 4];
        pcVar2[1] = "0123456789ABCDEF"[*pbVar6 & 0xf];
        *pcVar2 = cVar1;
        pbVar6 = pbVar5;
        pcVar2 = pcVar2 + 2;
      } while (pbVar5 != local_1c[0] + iVar3);
      pcVar4[num + -2] = '\0';
      CRYPTO_free(local_1c[0]);
    }
    return pcVar4;
  }
  return (char *)0x0;
}

