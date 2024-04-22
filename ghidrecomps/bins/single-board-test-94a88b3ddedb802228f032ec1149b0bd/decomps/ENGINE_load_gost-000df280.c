
void ENGINE_load_gost(void)

{
  int *piVar1;
  ENGINE *e;
  int iVar2;
  
  piVar1 = DAT_000df444;
  if ((*DAT_000df444 != 0) || (e = ENGINE_new(), e == (ENGINE *)0x0)) {
    return;
  }
  if (piVar1[3] == 0) {
    iVar2 = ENGINE_set_id(e,DAT_000df44c);
    if (iVar2 == 0) {
      puts(DAT_000df450);
    }
    else {
      iVar2 = ENGINE_set_name(e,DAT_000df454);
      if (iVar2 == 0) {
        puts(DAT_000df458);
      }
      else {
        iVar2 = ENGINE_set_digests(e,DAT_000df45c);
        if (iVar2 == 0) {
          puts(DAT_000df460);
        }
        else {
          iVar2 = ENGINE_set_ciphers(e,DAT_000df464);
          if (iVar2 == 0) {
            puts(DAT_000df468);
          }
          else {
            iVar2 = ENGINE_set_pkey_meths(e,DAT_000df46c);
            if (iVar2 == 0) {
              puts(DAT_000df470);
            }
            else {
              iVar2 = ENGINE_set_pkey_asn1_meths(e,DAT_000df474);
              if (iVar2 == 0) {
                puts(DAT_000df478);
              }
              else {
                iVar2 = ENGINE_set_cmd_defns(e,DAT_000df47c);
                if (iVar2 == 0) {
                  fwrite(DAT_000df484,1,0x1c,*DAT_000df480);
                }
                else {
                  iVar2 = ENGINE_set_ctrl_function(e,DAT_000df488);
                  if (iVar2 == 0) {
                    fwrite(DAT_000df48c,1,0x1c,*DAT_000df480);
                  }
                  else {
                    iVar2 = ENGINE_set_destroy_function(e,DAT_000df490);
                    if (((((iVar2 != 0) &&
                          (iVar2 = ENGINE_set_init_function(e,DAT_000df494), iVar2 != 0)) &&
                         (iVar2 = ENGINE_set_finish_function(e,DAT_000df498), iVar2 != 0)) &&
                        (((iVar2 = register_ameth_gost(0x32c,DAT_000df49c,DAT_000df4a0,DAT_000df4a4)
                          , iVar2 != 0 &&
                          (iVar2 = register_ameth_gost(0x32b,DAT_000df4a8,DAT_000df4ac,DAT_000df4b0)
                          , iVar2 != 0)) &&
                         ((iVar2 = register_ameth_gost(0x32f,DAT_000df4b4,DAT_000df4b8,DAT_000df4bc)
                          , iVar2 != 0 &&
                          ((iVar2 = register_pmeth_gost(0x32c,DAT_000df444,0), iVar2 != 0 &&
                           (iVar2 = register_pmeth_gost(0x32b,DAT_000df4c0,0), iVar2 != 0)))))))) &&
                       ((iVar2 = register_pmeth_gost(0x32f,DAT_000df4c4,0), iVar2 != 0 &&
                        (((((iVar2 = ENGINE_register_ciphers(e), iVar2 != 0 &&
                            (iVar2 = ENGINE_register_digests(e), iVar2 != 0)) &&
                           (iVar2 = ENGINE_register_pkey_meths(e), iVar2 != 0)) &&
                          ((iVar2 = EVP_add_cipher(DAT_000df4c8), iVar2 != 0 &&
                           (iVar2 = EVP_add_cipher(DAT_000df4cc), iVar2 != 0)))) &&
                         ((iVar2 = EVP_add_digest(DAT_000df4d0), iVar2 != 0 &&
                          (iVar2 = EVP_add_digest(DAT_000df4d4), iVar2 != 0)))))))) {
                      ERR_load_GOST_strings();
                      ENGINE_add(e);
                      ENGINE_free(e);
                      ERR_clear_error();
                      return;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  else {
    puts(DAT_000df448);
  }
  ENGINE_free(e);
  return;
}

