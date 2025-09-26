
undefined4 pkey_set_type(undefined4 *param_1,int param_2,char *param_3,int param_4)

{
  EVP_PKEY_ASN1_METHOD *pEVar1;
  undefined4 uVar2;
  code *pcVar3;
  ENGINE *local_1c;
  
  local_1c = (ENGINE *)0x0;
  if (param_1 == (undefined4 *)0x0) {
LAB_0015561e:
    if (param_3 == (char *)0x0) {
      pEVar1 = EVP_PKEY_asn1_find(&local_1c,param_2);
    }
    else {
      pEVar1 = EVP_PKEY_asn1_find_str(&local_1c,param_3,param_4);
    }
    if (param_1 == (undefined4 *)0x0) {
      if (local_1c != (ENGINE *)0x0) {
        ENGINE_finish(local_1c);
      }
      if (pEVar1 != (EVP_PKEY_ASN1_METHOD *)0x0) goto LAB_0015564c;
    }
    else if (pEVar1 != (EVP_PKEY_ASN1_METHOD *)0x0) {
      uVar2 = *(undefined4 *)pEVar1;
      param_1[3] = pEVar1;
      *param_1 = uVar2;
      param_1[1] = param_2;
      param_1[4] = local_1c;
      return 1;
    }
    ERR_put_error(6,0x9e,0x9c,"p_lib.c",0xe7);
    uVar2 = 0;
  }
  else {
    if (param_1[5] != 0) {
      if ((param_1[3] != 0) && (pcVar3 = *(code **)(param_1[3] + 0x54), pcVar3 != (code *)0x0)) {
        (*pcVar3)();
        param_1[5] = 0;
      }
      if ((ENGINE *)param_1[4] != (ENGINE *)0x0) {
        ENGINE_finish((ENGINE *)param_1[4]);
        param_1[4] = 0;
      }
    }
    if ((param_1[1] != param_2) || (param_1[3] == 0)) {
      if ((ENGINE *)param_1[4] != (ENGINE *)0x0) {
        ENGINE_finish((ENGINE *)param_1[4]);
        param_1[4] = 0;
      }
      goto LAB_0015561e;
    }
LAB_0015564c:
    uVar2 = 1;
  }
  return uVar2;
}

