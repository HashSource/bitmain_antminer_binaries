
void ENGINE_load_chil(void)

{
  ENGINE *e;
  int iVar1;
  int iVar2;
  RSA_METHOD *pRVar3;
  DH_METHOD *pDVar4;
  _func_1761 *p_Var5;
  ERR_STRING_DATA *str;
  _func_1762 *p_Var6;
  _func_1844 *p_Var7;
  _func_1763 *p_Var8;
  int iVar9;
  
  e = ENGINE_new();
  if (e == (ENGINE *)0x0) {
    return;
  }
  iVar1 = ENGINE_set_id(e,DAT_000dcb78);
  if ((iVar1 != 0) && (iVar2 = ENGINE_set_name(e,DAT_000dcb7c), iVar1 = DAT_000dcb80, iVar2 != 0)) {
    iVar2 = ENGINE_set_RSA(e,(RSA_METHOD *)(DAT_000dcb80 + 0x13c));
    if (((iVar2 != 0) &&
        ((((iVar2 = ENGINE_set_DH(e,(DH_METHOD *)(iVar1 + 0x174)), iVar2 != 0 &&
           (iVar2 = ENGINE_set_RAND(e,(RAND_METHOD *)(iVar1 + 0x198)), iVar2 != 0)) &&
          (iVar2 = ENGINE_set_destroy_function(e,DAT_000dcb84), iVar2 != 0)) &&
         ((iVar2 = ENGINE_set_init_function(e,DAT_000dcb88), iVar2 != 0 &&
          (iVar2 = ENGINE_set_finish_function(e,DAT_000dcb8c), iVar2 != 0)))))) &&
       ((iVar2 = ENGINE_set_ctrl_function(e,DAT_000dcb90), iVar2 != 0 &&
        (((iVar2 = ENGINE_set_load_privkey_function(e,DAT_000dcb94), iVar2 != 0 &&
          (iVar2 = ENGINE_set_load_pubkey_function(e,DAT_000dcb98), iVar2 != 0)) &&
         (iVar2 = ENGINE_set_cmd_defns(e,DAT_000dcb9c), iVar2 != 0)))))) {
      pRVar3 = RSA_PKCS1_SSLeay();
      iVar2 = DAT_000dcba0;
      p_Var5 = pRVar3->rsa_pub_dec;
      p_Var6 = pRVar3->rsa_priv_enc;
      p_Var8 = pRVar3->rsa_priv_dec;
      *(_func_1760 **)(iVar1 + 0x140) = pRVar3->rsa_pub_enc;
      *(_func_1761 **)(iVar1 + 0x144) = p_Var5;
      *(_func_1762 **)(iVar1 + 0x148) = p_Var6;
      *(_func_1763 **)(iVar1 + 0x14c) = p_Var8;
      pDVar4 = DH_OpenSSL();
      iVar9 = *(int *)(iVar2 + 0x1c);
      p_Var7 = pDVar4->compute_key;
      *(_func_1843 **)(iVar1 + 0x178) = pDVar4->generate_key;
      *(_func_1844 **)(iVar1 + 0x17c) = p_Var7;
      if (iVar9 == 0) {
        iVar9 = ERR_get_next_error_library();
        *(int *)(iVar2 + 0x1c) = iVar9;
      }
      iVar9 = DAT_000dcb80;
      if (*(int *)(iVar1 + 0x58) != 0) {
        iVar1 = *(int *)(iVar2 + 0x1c);
        str = (ERR_STRING_DATA *)(DAT_000dcb80 + 0x5c);
        *(undefined4 *)(DAT_000dcb80 + 0x58) = 0;
        ERR_load_strings(iVar1,str);
        ERR_load_strings(*(int *)(iVar2 + 0x1c),(ERR_STRING_DATA *)(iVar9 + 0xb4));
        *(uint *)(iVar9 + 300) = (uint)*(byte *)(iVar2 + 0x1c) << 0x18;
        ERR_load_strings(0,(ERR_STRING_DATA *)(iVar9 + 300));
      }
      ENGINE_add(e);
      ENGINE_free(e);
      ERR_clear_error();
      return;
    }
  }
  ENGINE_free(e);
  return;
}

