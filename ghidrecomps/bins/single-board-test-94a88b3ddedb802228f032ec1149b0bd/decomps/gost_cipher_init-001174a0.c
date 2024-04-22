
undefined4 gost_cipher_init(EVP_CIPHER_CTX *param_1,int param_2,void *param_3)

{
  size_t sVar1;
  char *s;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  piVar6 = (int *)param_1->cipher_data;
  if (param_1->app_data == (void *)0x0) {
    s = (char *)get_gost_engine_param();
    if ((s == (char *)0x0) || (*s == '\0')) {
      iVar3 = DAT_00117568[3];
      iVar2 = DAT_00117568[4];
      piVar7 = DAT_00117568 + 3;
    }
    else {
      iVar4 = OBJ_txt2nid(s);
      if (iVar4 == 0) {
        ERR_GOST_error(0x67,0x6b,DAT_0011756c,0x97);
        return 0;
      }
      iVar2 = DAT_00117568[1];
      if (iVar2 == 0) {
LAB_00117542:
        ERR_GOST_error(0x67,0x6a,DAT_0011756c,0xa0);
        return 0;
      }
      iVar3 = *DAT_00117568;
      piVar5 = DAT_00117568;
      piVar7 = DAT_00117568;
      if (iVar4 != iVar3) {
        do {
          iVar2 = piVar5[4];
          piVar7 = piVar5 + 3;
          if (iVar2 == 0) goto LAB_00117542;
          iVar3 = piVar5[3];
          piVar5 = piVar7;
        } while (iVar4 != iVar3);
        if (piVar7 == (int *)0x0) {
          return 0;
        }
      }
    }
    iVar4 = piVar7[2];
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

