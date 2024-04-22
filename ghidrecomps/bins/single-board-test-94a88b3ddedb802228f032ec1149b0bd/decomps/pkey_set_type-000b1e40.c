
undefined4 pkey_set_type(undefined4 *param_1,int param_2,char *param_3,int param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  code *pcVar3;
  ENGINE *local_1c;
  
  local_1c = (ENGINE *)0x0;
  if (param_1 == (undefined4 *)0x0) {
LAB_000b1e82:
    if (param_3 == (char *)0x0) {
      puVar1 = (undefined4 *)EVP_PKEY_asn1_find(&local_1c,param_2);
    }
    else {
      puVar1 = (undefined4 *)EVP_PKEY_asn1_find_str(&local_1c,param_3,param_4);
    }
    if (param_1 == (undefined4 *)0x0) {
      if (local_1c != (ENGINE *)0x0) {
        ENGINE_finish(local_1c);
      }
      if (puVar1 != (undefined4 *)0x0) goto LAB_000b1eb0;
    }
    else if (puVar1 != (undefined4 *)0x0) {
      uVar2 = *puVar1;
      param_1[3] = puVar1;
      *param_1 = uVar2;
      param_1[1] = param_2;
      param_1[4] = local_1c;
      return 1;
    }
    ERR_put_error(6,0x9e,0x9c,DAT_000b1ee0,0xe7);
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
      goto LAB_000b1e82;
    }
LAB_000b1eb0:
    uVar2 = 1;
  }
  return uVar2;
}

