
void ENGINE_load_aep(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  ENGINE *e;
  int iVar4;
  RSA_METHOD *pRVar5;
  DSA_METHOD *pDVar6;
  int iVar7;
  DH_METHOD *pDVar8;
  _func_1761 *p_Var9;
  _func_1875 *p_Var10;
  _func_1879 *p_Var11;
  char *pcVar12;
  _func_1844 *p_Var13;
  ERR_STRING_DATA *str;
  _func_1762 *p_Var14;
  _func_1876 *p_Var15;
  _func_1880 *p_Var16;
  _func_1882 *p_Var17;
  _func_1845 *p_Var18;
  _func_1763 *p_Var19;
  _func_1877 *p_Var20;
  _func_1881 *p_Var21;
  _func_1883 *p_Var22;
  
  e = ENGINE_new();
  if (e == (ENGINE *)0x0) {
    return;
  }
  iVar4 = ENGINE_set_id(e,DAT_000da08c);
  if ((iVar4 != 0) && (iVar4 = ENGINE_set_name(e,DAT_000da090), piVar1 = DAT_000da094, iVar4 != 0))
  {
    iVar4 = ENGINE_set_RSA(e,(RSA_METHOD *)(DAT_000da094 + 0x37));
    if ((((iVar4 != 0) &&
         (((iVar4 = ENGINE_set_DSA(e,(DSA_METHOD *)(piVar1 + 0x45)), iVar4 != 0 &&
           (iVar4 = ENGINE_set_DH(e,(DH_METHOD *)(piVar1 + 0x51)), iVar4 != 0)) &&
          (iVar4 = ENGINE_set_init_function(e,DAT_000da098), iVar4 != 0)))) &&
        (((iVar4 = ENGINE_set_destroy_function(e,DAT_000da09c), iVar4 != 0 &&
          (iVar4 = ENGINE_set_finish_function(e,DAT_000da0a0), iVar4 != 0)) &&
         (iVar4 = ENGINE_set_ctrl_function(e,DAT_000da0a4), iVar4 != 0)))) &&
       (iVar4 = ENGINE_set_cmd_defns(e,DAT_000da0a8), iVar4 != 0)) {
      pRVar5 = RSA_PKCS1_SSLeay();
      p_Var9 = pRVar5->rsa_pub_dec;
      p_Var14 = pRVar5->rsa_priv_enc;
      p_Var19 = pRVar5->rsa_priv_dec;
      piVar1[0x38] = (int)pRVar5->rsa_pub_enc;
      iVar4 = DAT_000da0ac;
      piVar1[0x39] = (int)p_Var9;
      piVar1[0x3a] = (int)p_Var14;
      piVar1[0x3b] = (int)p_Var19;
      pDVar6 = DSA_OpenSSL();
      p_Var15 = pDVar6->dsa_sign_setup;
      p_Var20 = pDVar6->dsa_do_verify;
      piVar1[0x46] = (int)pDVar6->dsa_do_sign;
      piVar1[0x47] = (int)p_Var15;
      piVar1[0x48] = (int)p_Var20;
      pDVar6 = DSA_get_default_method();
      iVar3 = DAT_000da0b4;
      iVar7 = DAT_000da0b0;
      p_Var10 = pDVar6->dsa_do_sign;
      p_Var15 = pDVar6->dsa_sign_setup;
      p_Var20 = pDVar6->dsa_do_verify;
      piVar1[0x45] = (int)pDVar6->name;
      piVar1[0x46] = (int)p_Var10;
      piVar1[0x47] = (int)p_Var15;
      piVar1[0x48] = (int)p_Var20;
      p_Var11 = pDVar6->bn_mod_exp;
      p_Var16 = pDVar6->init;
      p_Var21 = pDVar6->finish;
      piVar1[0x49] = (int)pDVar6->dsa_mod_exp;
      piVar1[0x4a] = (int)p_Var11;
      piVar1[0x4b] = (int)p_Var16;
      piVar1[0x4c] = (int)p_Var21;
      piVar1[0x49] = iVar7;
      iVar7 = pDVar6->flags;
      pcVar12 = pDVar6->app_data;
      p_Var17 = pDVar6->dsa_paramgen;
      p_Var22 = pDVar6->dsa_keygen;
      piVar1[0x4a] = iVar3;
      piVar1[0x4d] = iVar7;
      piVar1[0x4e] = (int)pcVar12;
      piVar1[0x4f] = (int)p_Var17;
      piVar1[0x50] = (int)p_Var22;
      pDVar8 = DH_OpenSSL();
      iVar7 = *(int *)(iVar4 + 4);
      p_Var13 = pDVar8->compute_key;
      p_Var18 = pDVar8->bn_mod_exp;
      piVar1[0x52] = (int)pDVar8->generate_key;
      piVar1[0x53] = (int)p_Var13;
      piVar1[0x54] = (int)p_Var18;
      if (iVar7 == 0) {
        iVar7 = ERR_get_next_error_library();
        *(int *)(iVar4 + 4) = iVar7;
      }
      piVar2 = DAT_000da094;
      if (*piVar1 != 0) {
        str = (ERR_STRING_DATA *)(DAT_000da094 + 1);
        *DAT_000da094 = 0;
        ERR_load_strings(*(int *)(iVar4 + 4),str);
        ERR_load_strings(*(int *)(iVar4 + 4),(ERR_STRING_DATA *)(piVar2 + 0x13));
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

