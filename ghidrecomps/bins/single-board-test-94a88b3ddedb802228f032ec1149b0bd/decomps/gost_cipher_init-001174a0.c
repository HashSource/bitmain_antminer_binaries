
undefined4 gost_cipher_init(EVP_CIPHER_CTX *param_1,int param_2,void *param_3)

{
  size_t sVar1;
  char *s;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined4 *puVar7;
  
  piVar6 = (int *)param_1->cipher_data;
  if (param_1->app_data == (void *)0x0) {
    s = (char *)get_gost_engine_param();
    if ((s == (char *)0x0) || (*s == '\0')) {
      puVar7 = &DAT_0019e524;
      iVar2 = DAT_0019e528;
      iVar3 = DAT_0019e524;
    }
    else {
      iVar4 = OBJ_txt2nid(s);
      if (iVar4 == 0) {
        ERR_GOST_error(0x67,0x6b,"gost_crypt.c",0x97);
        return 0;
      }
      if (DAT_0019e51c == 0) {
LAB_00117542:
        ERR_GOST_error(0x67,0x6a,"gost_crypt.c",0xa0);
        return 0;
      }
      puVar5 = &gost_cipher_list;
      if (iVar4 == gost_cipher_list) {
        puVar7 = &gost_cipher_list;
        iVar2 = DAT_0019e51c;
        iVar3 = gost_cipher_list;
      }
      else {
        do {
          iVar2 = puVar5[4];
          puVar7 = puVar5 + 3;
          if (iVar2 == 0) goto LAB_00117542;
          iVar3 = puVar5[3];
          puVar5 = puVar7;
        } while (iVar4 != iVar3);
        if (puVar7 == (undefined4 *)0x0) {
          return 0;
        }
      }
    }
    iVar4 = puVar7[2];
    piVar6[1] = 0;
    *piVar6 = iVar3;
    piVar6[2] = iVar4;
    gost_init(piVar6 + 3,iVar2);
    param_1->app_data = param_1->cipher_data;
  }
  if (param_2 != 0) {
    gost_key(piVar6 + 3,param_2);
  }
  if (param_3 != (void *)0x0) {
    sVar1 = EVP_CIPHER_CTX_iv_length(param_1);
    memcpy(param_1->oiv,param_3,sVar1);
  }
  sVar1 = EVP_CIPHER_CTX_iv_length(param_1);
  memcpy(param_1->iv,param_1->oiv,sVar1);
  return 1;
}

