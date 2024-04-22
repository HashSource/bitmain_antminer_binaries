
undefined4 pkey_gost_mac_ctrl(EVP_PKEY_CTX *param_1,undefined4 param_2,int param_3,EVP_MD *param_4)

{
  int *piVar1;
  undefined4 uVar2;
  EVP_PKEY *pkey;
  int iVar3;
  _func_1222 *p_Var4;
  ulong uVar5;
  _func_1223 *p_Var6;
  int iVar7;
  _func_1221 *p_Var8;
  
  piVar1 = (int *)EVP_PKEY_CTX_get_data(param_1);
  switch(param_2) {
  case 1:
    iVar3 = EVP_MD_type(param_4);
    if (iVar3 == 0x32f) {
      piVar1[1] = (int)param_4;
      return 1;
    }
    ERR_GOST_error(0x80,0x6c,DAT_000df744,0x1be);
    return 0;
  default:
    return 0xfffffffe;
  case 3:
  case 4:
  case 5:
    return 1;
  case 6:
    if (param_3 == 0x20) {
      iVar7 = param_4->pkey_type;
      iVar3 = param_4->md_size;
      uVar5 = param_4->flags;
      piVar1[2] = param_4->type;
      piVar1[3] = iVar7;
      piVar1[4] = iVar3;
      piVar1[5] = uVar5;
      p_Var8 = param_4->update;
      p_Var4 = param_4->final;
      p_Var6 = param_4->copy;
      piVar1[6] = (int)param_4->init;
      piVar1[7] = (int)p_Var8;
      piVar1[8] = (int)p_Var4;
      piVar1[9] = (int)p_Var6;
      *piVar1 = 1;
      return 1;
    }
    ERR_GOST_error(0x80,0x6f,DAT_000df744,0x1d0);
    return 0;
  case 7:
    break;
  case 0xd:
    param_4->type = piVar1[1];
    return 1;
  }
  if (*piVar1 == 0) {
    pkey = EVP_PKEY_CTX_get0_pkey(param_1);
    if (pkey == (EVP_PKEY *)0x0) {
      ERR_GOST_error(0x80,0x74,DAT_000df744,0x1df);
      return 0;
    }
    piVar1 = (int *)EVP_PKEY_get0(pkey);
    if (piVar1 == (int *)0x0) {
      ERR_GOST_error(0x80,0x74,DAT_000df744,0x1e5);
      return 0;
    }
  }
  else {
    piVar1 = piVar1 + 2;
  }
  uVar2 = (**(code **)(param_4->type + 0x48))(param_4,0x1004,0x20,piVar1);
  return uVar2;
}

