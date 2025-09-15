
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 surewarehk_init(undefined4 param_1)

{
  DSO_FUNC_TYPE pDVar1;
  DSO_FUNC_TYPE pDVar2;
  DSO_FUNC_TYPE pDVar3;
  DSO_FUNC_TYPE pDVar4;
  DSO_FUNC_TYPE pDVar5;
  DSO_FUNC_TYPE pDVar6;
  DSO_FUNC_TYPE pDVar7;
  DSO_FUNC_TYPE pDVar8;
  DSO_FUNC_TYPE pDVar9;
  DSO_FUNC_TYPE pDVar10;
  DSO_FUNC_TYPE pDVar11;
  DSO_FUNC_TYPE pDVar12;
  DSO_FUNC_TYPE pDVar13;
  int iVar14;
  char local_68 [68];
  
  local_68[0xc] = '\0';
  local_68[0xd] = '\0';
  local_68[0xe] = '\0';
  local_68[0xf] = '\0';
  local_68[0x10] = '\0';
  local_68[0x11] = '\0';
  local_68[0x12] = '\0';
  local_68[0x13] = '\0';
  builtin_strncpy(local_68,"ENGINE_init",0xc);
  local_68[0x14] = '\0';
  local_68[0x15] = '\0';
  local_68[0x16] = '\0';
  local_68[0x17] = '\0';
  local_68[0x18] = '\0';
  local_68[0x19] = '\0';
  local_68[0x1a] = '\0';
  local_68[0x1b] = '\0';
  local_68[0x1c] = '\0';
  local_68[0x1d] = '\0';
  local_68[0x1e] = '\0';
  local_68[0x1f] = '\0';
  local_68[0x20] = '\0';
  local_68[0x21] = '\0';
  local_68[0x22] = '\0';
  local_68[0x23] = '\0';
  local_68[0x24] = '\0';
  local_68[0x25] = '\0';
  local_68[0x26] = '\0';
  local_68[0x27] = '\0';
  local_68[0x28] = '\0';
  local_68[0x29] = '\0';
  local_68[0x2a] = '\0';
  local_68[0x2b] = '\0';
  local_68[0x2c] = '\0';
  local_68[0x2d] = '\0';
  local_68[0x2e] = '\0';
  local_68[0x2f] = '\0';
  local_68[0x30] = '\0';
  local_68[0x31] = '\0';
  local_68[0x32] = '\0';
  local_68[0x33] = '\0';
  local_68[0x34] = '\0';
  local_68[0x35] = '\0';
  local_68[0x36] = '\0';
  local_68[0x37] = '\0';
  local_68[0x38] = '\0';
  local_68[0x39] = '\0';
  local_68[0x3a] = '\0';
  local_68[0x3b] = '\0';
  local_68[0x3c] = '\0';
  local_68[0x3d] = '\0';
  local_68[0x3e] = '\0';
  local_68[0x3f] = '\0';
  if (surewarehk_dso == (DSO *)0x0) {
    surewarehk_dso = DSO_load((DSO *)0x0,"SureWareHook",(DSO_METHOD *)0x0,0);
    if (surewarehk_dso == (DSO *)0x0) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = ERR_get_next_error_library();
      }
      iVar14 = 0x1df;
    }
    else {
      pDVar1 = DSO_bind_func(surewarehk_dso,"SureWareHook_Init");
      if (((((pDVar1 != (DSO_FUNC_TYPE)0x0) &&
            (pDVar2 = DSO_bind_func(surewarehk_dso,"SureWareHook_Finish"),
            pDVar2 != (DSO_FUNC_TYPE)0x0)) &&
           (pDVar3 = DSO_bind_func(surewarehk_dso,"SureWareHook_Rand_Bytes"),
           pDVar3 != (DSO_FUNC_TYPE)0x0)) &&
          (((pDVar4 = DSO_bind_func(surewarehk_dso,"SureWareHook_Rand_Seed"),
            pDVar4 != (DSO_FUNC_TYPE)0x0 &&
            (pDVar5 = DSO_bind_func(surewarehk_dso,"SureWareHook_Load_Privkey"),
            pDVar5 != (DSO_FUNC_TYPE)0x0)) &&
           ((pDVar6 = DSO_bind_func(surewarehk_dso,"SureWareHook_Load_Rsa_Pubkey"),
            pDVar6 != (DSO_FUNC_TYPE)0x0 &&
            ((pDVar7 = DSO_bind_func(surewarehk_dso,"SureWareHook_Free"),
             pDVar7 != (DSO_FUNC_TYPE)0x0 &&
             (pDVar8 = DSO_bind_func(surewarehk_dso,"SureWareHook_Rsa_Priv_Dec"),
             pDVar8 != (DSO_FUNC_TYPE)0x0)))))))) &&
         ((pDVar9 = DSO_bind_func(surewarehk_dso,"SureWareHook_Rsa_Sign"),
          pDVar9 != (DSO_FUNC_TYPE)0x0 &&
          ((((pDVar10 = DSO_bind_func(surewarehk_dso,"SureWareHook_Dsa_Sign"),
             pDVar10 != (DSO_FUNC_TYPE)0x0 &&
             (pDVar11 = DSO_bind_func(surewarehk_dso,"SureWareHook_Info_Pubkey"),
             pDVar11 != (DSO_FUNC_TYPE)0x0)) &&
            (pDVar12 = DSO_bind_func(surewarehk_dso,"SureWareHook_Load_Dsa_Pubkey"),
            pDVar12 != (DSO_FUNC_TYPE)0x0)) &&
           (pDVar13 = DSO_bind_func(surewarehk_dso,"SureWareHook_Mod_Exp"),
           pDVar13 != (DSO_FUNC_TYPE)0x0)))))) {
        p_surewarehk_Free = pDVar7;
        p_surewarehk_Rand_Seed = pDVar4;
        p_surewarehk_Mod_Exp = pDVar13;
        p_surewarehk_Load_Rsa_Pubkey = pDVar6;
        p_surewarehk_Load_Dsa_Pubkey = pDVar12;
        p_surewarehk_Info_Pubkey = pDVar11;
        p_surewarehk_Load_Privkey = pDVar5;
        p_surewarehk_Init = pDVar1;
        p_surewarehk_Finish = pDVar2;
        p_surewarehk_Rand_Bytes = pDVar3;
        p_surewarehk_Rsa_Priv_Dec = pDVar8;
        p_surewarehk_Rsa_Sign = pDVar9;
        p_surewarehk_Dsa_Sign = pDVar10;
        iVar14 = (*pDVar1)(local_68,threadsafe);
        if (iVar14 == -3) {
          ERR_SUREWARE_error_constprop_5(0x68,0x68,0x21c);
        }
        else {
          iVar14 = (*p_surewarehk_Init)(local_68,threadsafe);
          if (iVar14 != -3) {
            surewarehk_load_privkey(param_1,0,0,0);
            if (rsaHndidx == -1) {
              rsaHndidx = RSA_get_ex_new_index
                                    (0,"SureWareHook RSA key handle",(undefined1 *)0x0,
                                     (undefined1 *)0x0,(undefined1 *)0xdd171);
            }
            if (dsaHndidx != -1) {
              return 1;
            }
            dsaHndidx = DSA_get_ex_new_index
                                  (0,"SureWareHook DSA key handle",(undefined1 *)0x0,
                                   (undefined1 *)0x0,(undefined1 *)0xdd171);
            return 1;
          }
          ERR_SUREWARE_error_constprop_5(0x68,0x68,0x220);
        }
        goto LAB_000dd7fe;
      }
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = ERR_get_next_error_library();
      }
      iVar14 = 0x209;
    }
    ERR_put_error(SUREWARE_lib_error_code,0x68,0x68,"e_sureware.c",iVar14);
  }
  else {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(SUREWARE_lib_error_code,0x68,100,"e_sureware.c",0x1d9);
  }
LAB_000dd7fe:
  if (surewarehk_dso != (DSO *)0x0) {
    DSO_free(surewarehk_dso);
  }
  p_surewarehk_Dsa_Sign = (DSO_FUNC_TYPE)0x0;
  p_surewarehk_Rsa_Sign = (DSO_FUNC_TYPE)0x0;
  p_surewarehk_Rsa_Priv_Dec = (DSO_FUNC_TYPE)0x0;
  p_surewarehk_Rand_Bytes = (DSO_FUNC_TYPE)0x0;
  p_surewarehk_Finish = (DSO_FUNC_TYPE)0x0;
  p_surewarehk_Init = (DSO_FUNC_TYPE)0x0;
  surewarehk_dso = (DSO *)0x0;
  p_surewarehk_Load_Privkey = (DSO_FUNC_TYPE)0x0;
  p_surewarehk_Info_Pubkey = (DSO_FUNC_TYPE)0x0;
  p_surewarehk_Load_Dsa_Pubkey = (DSO_FUNC_TYPE)0x0;
  p_surewarehk_Load_Rsa_Pubkey = (DSO_FUNC_TYPE)0x0;
  p_surewarehk_Mod_Exp = (DSO_FUNC_TYPE)0x0;
  p_surewarehk_Rand_Seed = (DSO_FUNC_TYPE)0x0;
  p_surewarehk_Free = (DSO_FUNC_TYPE)0x0;
  return 0;
}

