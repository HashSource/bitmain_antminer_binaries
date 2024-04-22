
void ENGINE_load_nuron(void)

{
  int *piVar1;
  int *piVar2;
  ENGINE *e;
  int iVar3;
  RSA_METHOD *pRVar4;
  DSA_METHOD *pDVar5;
  DH_METHOD *pDVar6;
  _func_1761 *p_Var7;
  ERR_STRING_DATA *pEVar8;
  _func_1762 *p_Var9;
  _func_1876 *p_Var10;
  _func_1844 *p_Var11;
  _func_1763 *p_Var12;
  _func_1877 *p_Var13;
  int iVar14;
  
  e = ENGINE_new();
  if (e == (ENGINE *)0x0) {
    return;
  }
  iVar3 = ENGINE_set_id(e,DAT_000dd01c);
  if ((iVar3 != 0) && (iVar3 = ENGINE_set_name(e,DAT_000dd020), piVar1 = DAT_000dd024, iVar3 != 0))
  {
    iVar3 = ENGINE_set_RSA(e,(RSA_METHOD *)(DAT_000dd024 + 0x1d));
    if ((((iVar3 != 0) &&
         (((iVar3 = ENGINE_set_DSA(e,(DSA_METHOD *)(piVar1 + 0x2b)), iVar3 != 0 &&
           (iVar3 = ENGINE_set_DH(e,(DH_METHOD *)(piVar1 + 0x37)), iVar3 != 0)) &&
          (iVar3 = ENGINE_set_destroy_function(e,DAT_000dd028), iVar3 != 0)))) &&
        (((iVar3 = ENGINE_set_init_function(e,DAT_000dd02c), iVar3 != 0 &&
          (iVar3 = ENGINE_set_finish_function(e,DAT_000dd030), iVar3 != 0)) &&
         (iVar3 = ENGINE_set_ctrl_function(e,DAT_000dd034), iVar3 != 0)))) &&
       (iVar3 = ENGINE_set_cmd_defns(e,DAT_000dd038), iVar3 != 0)) {
      pRVar4 = RSA_PKCS1_SSLeay();
      p_Var7 = pRVar4->rsa_pub_dec;
      p_Var9 = pRVar4->rsa_priv_enc;
      p_Var12 = pRVar4->rsa_priv_dec;
      piVar1[0x1e] = (int)pRVar4->rsa_pub_enc;
      iVar3 = DAT_000dd03c;
      piVar1[0x1f] = (int)p_Var7;
      piVar1[0x20] = (int)p_Var9;
      piVar1[0x21] = (int)p_Var12;
      pDVar5 = DSA_OpenSSL();
      p_Var10 = pDVar5->dsa_sign_setup;
      p_Var13 = pDVar5->dsa_do_verify;
      piVar1[0x2c] = (int)pDVar5->dsa_do_sign;
      piVar1[0x2d] = (int)p_Var10;
      piVar1[0x2e] = (int)p_Var13;
      pDVar6 = DH_OpenSSL();
      iVar14 = *(int *)(iVar3 + 4);
      p_Var11 = pDVar6->compute_key;
      piVar1[0x38] = (int)pDVar6->generate_key;
      piVar1[0x39] = (int)p_Var11;
      if (iVar14 == 0) {
        iVar14 = ERR_get_next_error_library();
        *(int *)(iVar3 + 4) = iVar14;
      }
      piVar2 = DAT_000dd024;
      if (*piVar1 != 0) {
        pEVar8 = (ERR_STRING_DATA *)(DAT_000dd024 + 1);
        *DAT_000dd024 = 0;
        ERR_load_strings(*(int *)(iVar3 + 4),pEVar8);
        ERR_load_strings(*(int *)(iVar3 + 4),(ERR_STRING_DATA *)(piVar2 + 0xb));
        pEVar8 = (ERR_STRING_DATA *)(piVar2 + 0x19);
        pEVar8->error = (uint)*(byte *)(iVar3 + 4) << 0x18;
        ERR_load_strings(0,pEVar8);
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

