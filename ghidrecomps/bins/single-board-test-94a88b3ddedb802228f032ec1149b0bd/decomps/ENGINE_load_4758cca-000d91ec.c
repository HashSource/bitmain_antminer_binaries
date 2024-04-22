
void ENGINE_load_4758cca(void)

{
  ENGINE *e;
  int iVar1;
  int iVar2;
  int iVar3;
  ERR_STRING_DATA *str;
  
  e = ENGINE_new();
  if (e == (ENGINE *)0x0) {
    return;
  }
  iVar1 = ENGINE_set_id(e,DAT_000d92c8);
  if ((iVar1 != 0) && (iVar2 = ENGINE_set_name(e,DAT_000d92cc), iVar1 = DAT_000d92d0, iVar2 != 0)) {
    iVar2 = ENGINE_set_RSA(e,(RSA_METHOD *)(DAT_000d92d0 + 0xa0));
    if ((((iVar2 != 0) &&
         ((((iVar2 = ENGINE_set_RAND(e,(RAND_METHOD *)(iVar1 + 0xd8)), iVar2 != 0 &&
            (iVar2 = ENGINE_set_destroy_function(e,DAT_000d92d4), iVar2 != 0)) &&
           (iVar2 = ENGINE_set_init_function(e,DAT_000d92d8), iVar2 != 0)) &&
          ((iVar2 = ENGINE_set_finish_function(e,DAT_000d92dc), iVar2 != 0 &&
           (iVar2 = ENGINE_set_ctrl_function(e,DAT_000d92e0), iVar2 != 0)))))) &&
        (iVar2 = ENGINE_set_load_privkey_function(e,DAT_000d92e4), iVar2 != 0)) &&
       ((iVar2 = ENGINE_set_load_pubkey_function(e,DAT_000d92e8), iVar2 != 0 &&
        (iVar3 = ENGINE_set_cmd_defns(e,DAT_000d92ec), iVar2 = DAT_000d92f0, iVar3 != 0)))) {
      if (*(int *)(DAT_000d92f0 + 0xc) == 0) {
        iVar3 = ERR_get_next_error_library();
        *(int *)(iVar2 + 0xc) = iVar3;
      }
      iVar3 = DAT_000d92d0;
      if (*(int *)(iVar1 + 4) != 0) {
        iVar1 = *(int *)(iVar2 + 0xc);
        str = (ERR_STRING_DATA *)(DAT_000d92d0 + 8);
        *(undefined4 *)(DAT_000d92d0 + 4) = 0;
        ERR_load_strings(iVar1,str);
        ERR_load_strings(*(int *)(iVar2 + 0xc),(ERR_STRING_DATA *)(iVar3 + 0x48));
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

