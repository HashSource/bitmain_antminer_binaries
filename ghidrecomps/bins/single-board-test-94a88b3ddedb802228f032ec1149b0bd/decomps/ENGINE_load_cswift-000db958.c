
void ENGINE_load_cswift(void)

{
  int *piVar1;
  int *piVar2;
  ENGINE *e;
  int iVar3;
  RSA_METHOD *pRVar4;
  DH_METHOD *pDVar5;
  _func_1761 *p_Var6;
  ERR_STRING_DATA *pEVar7;
  _func_1762 *p_Var8;
  _func_1844 *p_Var9;
  _func_1763 *p_Var10;
  int iVar11;
  
  e = ENGINE_new();
  if (e == (ENGINE *)0x0) {
    return;
  }
  iVar3 = ENGINE_set_id(e,DAT_000dba78);
  if ((iVar3 != 0) && (iVar3 = ENGINE_set_name(e,DAT_000dba7c), piVar1 = DAT_000dba80, iVar3 != 0))
  {
    iVar3 = ENGINE_set_RSA(e,(RSA_METHOD *)(DAT_000dba80 + 0x2d));
    if ((((iVar3 != 0) &&
         ((((iVar3 = ENGINE_set_DSA(e,(DSA_METHOD *)(piVar1 + 0x3b)), iVar3 != 0 &&
            (iVar3 = ENGINE_set_DH(e,(DH_METHOD *)(piVar1 + 0x47)), iVar3 != 0)) &&
           (iVar3 = ENGINE_set_RAND(e,(RAND_METHOD *)(piVar1 + 0x50)), iVar3 != 0)) &&
          ((iVar3 = ENGINE_set_destroy_function(e,DAT_000dba84), iVar3 != 0 &&
           (iVar3 = ENGINE_set_init_function(e,DAT_000dba88), iVar3 != 0)))))) &&
        (iVar3 = ENGINE_set_finish_function(e,DAT_000dba8c), iVar3 != 0)) &&
       ((iVar3 = ENGINE_set_ctrl_function(e,DAT_000dba90), iVar3 != 0 &&
        (iVar3 = ENGINE_set_cmd_defns(e,DAT_000dba94), iVar3 != 0)))) {
      pRVar4 = RSA_PKCS1_SSLeay();
      iVar3 = DAT_000dba98;
      p_Var6 = pRVar4->rsa_pub_dec;
      p_Var8 = pRVar4->rsa_priv_enc;
      p_Var10 = pRVar4->rsa_priv_dec;
      piVar1[0x2e] = (int)pRVar4->rsa_pub_enc;
      piVar1[0x2f] = (int)p_Var6;
      piVar1[0x30] = (int)p_Var8;
      piVar1[0x31] = (int)p_Var10;
      pDVar5 = DH_OpenSSL();
      iVar11 = *(int *)(iVar3 + 4);
      p_Var9 = pDVar5->compute_key;
      piVar1[0x48] = (int)pDVar5->generate_key;
      piVar1[0x49] = (int)p_Var9;
      if (iVar11 == 0) {
        iVar11 = ERR_get_next_error_library();
        *(int *)(iVar3 + 4) = iVar11;
      }
      piVar2 = DAT_000dba80;
      if (*piVar1 != 0) {
        pEVar7 = (ERR_STRING_DATA *)(DAT_000dba80 + 1);
        *DAT_000dba80 = 0;
        ERR_load_strings(*(int *)(iVar3 + 4),pEVar7);
        ERR_load_strings(*(int *)(iVar3 + 4),(ERR_STRING_DATA *)(piVar2 + 0x15));
        pEVar7 = (ERR_STRING_DATA *)(piVar2 + 0x29);
        pEVar7->error = (uint)*(byte *)(iVar3 + 4) << 0x18;
        ERR_load_strings(0,pEVar7);
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

