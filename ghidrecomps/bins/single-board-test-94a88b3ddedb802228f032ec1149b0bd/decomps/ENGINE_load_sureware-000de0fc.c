
void ENGINE_load_sureware(void)

{
  int *piVar1;
  int *piVar2;
  ENGINE *e;
  int iVar3;
  RSA_METHOD *pRVar4;
  DSA_METHOD *pDVar5;
  DH_METHOD *pDVar6;
  int iVar7;
  ERR_STRING_DATA *pEVar8;
  _func_1761 *p_Var9;
  _func_1844 *p_Var10;
  
  e = ENGINE_new();
  if (e == (ENGINE *)0x0) {
    return;
  }
  iVar3 = ENGINE_set_id(e,DAT_000de22c);
  if ((iVar3 != 0) && (iVar3 = ENGINE_set_name(e,DAT_000de230), piVar1 = DAT_000de234, iVar3 != 0))
  {
    iVar3 = ENGINE_set_RSA(e,(RSA_METHOD *)(DAT_000de234 + 0x38));
    if (((iVar3 != 0) &&
        ((((iVar3 = ENGINE_set_DSA(e,(DSA_METHOD *)(piVar1 + 0x46)), iVar3 != 0 &&
           (iVar3 = ENGINE_set_DH(e,(DH_METHOD *)(piVar1 + 0x52)), iVar3 != 0)) &&
          (iVar3 = ENGINE_set_RAND(e,(RAND_METHOD *)(piVar1 + 0x5b)), iVar3 != 0)) &&
         ((iVar3 = ENGINE_set_destroy_function(e,DAT_000de238), iVar3 != 0 &&
          (iVar3 = ENGINE_set_init_function(e,DAT_000de23c), iVar3 != 0)))))) &&
       ((iVar3 = ENGINE_set_finish_function(e,DAT_000de240), iVar3 != 0 &&
        (((iVar3 = ENGINE_set_ctrl_function(e,DAT_000de244), iVar3 != 0 &&
          (iVar3 = ENGINE_set_load_privkey_function(e,DAT_000de248), iVar3 != 0)) &&
         (iVar3 = ENGINE_set_load_pubkey_function(e,DAT_000de24c), iVar3 != 0)))))) {
      pRVar4 = RSA_PKCS1_SSLeay();
      if (pRVar4 != (RSA_METHOD *)0x0) {
        p_Var9 = pRVar4->rsa_pub_dec;
        piVar1[0x39] = (int)pRVar4->rsa_pub_enc;
        piVar1[0x3a] = (int)p_Var9;
      }
      pDVar5 = DSA_OpenSSL();
      if (pDVar5 != (DSA_METHOD *)0x0) {
        piVar1[0x49] = (int)pDVar5->dsa_do_verify;
      }
      pDVar6 = DH_OpenSSL();
      if (pDVar6 != (DH_METHOD *)0x0) {
        p_Var10 = pDVar6->compute_key;
        piVar1[0x53] = (int)pDVar6->generate_key;
        piVar1[0x54] = (int)p_Var10;
      }
      iVar3 = DAT_000de250;
      if (*(int *)(DAT_000de250 + 4) == 0) {
        iVar7 = ERR_get_next_error_library();
        *(int *)(iVar3 + 4) = iVar7;
      }
      piVar2 = DAT_000de234;
      if (*piVar1 != 0) {
        pEVar8 = (ERR_STRING_DATA *)(DAT_000de234 + 1);
        *DAT_000de234 = 0;
        ERR_load_strings(*(int *)(iVar3 + 4),pEVar8);
        ERR_load_strings(*(int *)(iVar3 + 4),(ERR_STRING_DATA *)(piVar2 + 0x1f));
        pEVar8 = (ERR_STRING_DATA *)(piVar2 + 0x31);
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

