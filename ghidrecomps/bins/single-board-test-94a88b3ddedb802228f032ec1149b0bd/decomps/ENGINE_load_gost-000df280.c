
void ENGINE_load_gost(void)

{
  ENGINE *e;
  int iVar1;
  
  if ((pmeth_GostR3410_94 != 0) || (e = ENGINE_new(), e == (ENGINE *)0x0)) {
    return;
  }
  if (ameth_GostR3410_94 == 0) {
    iVar1 = ENGINE_set_id(e,"gost");
    if (iVar1 == 0) {
      puts("ENGINE_set_id failed");
    }
    else {
      iVar1 = ENGINE_set_name(e,"Reference implementation of GOST engine");
      if (iVar1 == 0) {
        puts("ENGINE_set_name failed");
      }
      else {
        iVar1 = ENGINE_set_digests(e,(ENGINE_DIGESTS_PTR)0xdf149);
        if (iVar1 == 0) {
          puts("ENGINE_set_digests failed");
        }
        else {
          iVar1 = ENGINE_set_ciphers(e,(ENGINE_CIPHERS_PTR)0xdf185);
          if (iVar1 == 0) {
            puts("ENGINE_set_ciphers failed");
          }
          else {
            iVar1 = ENGINE_set_pkey_meths(e,(ENGINE_PKEY_METHS_PTR)0xdf1c1);
            if (iVar1 == 0) {
              puts("ENGINE_set_pkey_meths failed");
            }
            else {
              iVar1 = ENGINE_set_pkey_asn1_meths(e,(ENGINE_PKEY_ASN1_METHS_PTR)0xdf211);
              if (iVar1 == 0) {
                puts("ENGINE_set_pkey_asn1_meths failed");
              }
              else {
                iVar1 = ENGINE_set_cmd_defns(e,(ENGINE_CMD_DEFN *)&gost_cmds);
                if (iVar1 == 0) {
                  fwrite("ENGINE_set_cmd_defns failed\n",1,0x1c,stderr);
                }
                else {
                  iVar1 = ENGINE_set_ctrl_function(e,(ENGINE_CTRL_FUNC_PTR)0x117709);
                  if (iVar1 == 0) {
                    fwrite("ENGINE_set_ctrl_func failed\n",1,0x1c,stderr);
                  }
                  else {
                    iVar1 = ENGINE_set_destroy_function(e,(ENGINE_GEN_INT_FUNC_PTR)0xdf261);
                    if (((((iVar1 != 0) &&
                          (iVar1 = ENGINE_set_init_function(e,(ENGINE_GEN_INT_FUNC_PTR)0xdf141),
                          iVar1 != 0)) &&
                         (iVar1 = ENGINE_set_finish_function(e,(ENGINE_GEN_INT_FUNC_PTR)0xdf145),
                         iVar1 != 0)) &&
                        (((iVar1 = register_ameth_gost(0x32c,&ameth_GostR3410_94,"GOST94",
                                                       "GOST R 34.10-94"), iVar1 != 0 &&
                          (iVar1 = register_ameth_gost(0x32b,&ameth_GostR3410_2001,"GOST2001",
                                                       "GOST R 34.10-2001"), iVar1 != 0)) &&
                         ((iVar1 = register_ameth_gost(0x32f,&ameth_Gost28147_MAC,"GOST-MAC",
                                                       "GOST 28147-89 MAC"), iVar1 != 0 &&
                          ((iVar1 = register_pmeth_gost(0x32c,&pmeth_GostR3410_94,0), iVar1 != 0 &&
                           (iVar1 = register_pmeth_gost(0x32b,&pmeth_GostR3410_2001,0), iVar1 != 0))
                          )))))) &&
                       ((iVar1 = register_pmeth_gost(0x32f,&pmeth_Gost28147_MAC,0), iVar1 != 0 &&
                        (((((iVar1 = ENGINE_register_ciphers(e), iVar1 != 0 &&
                            (iVar1 = ENGINE_register_digests(e), iVar1 != 0)) &&
                           (iVar1 = ENGINE_register_pkey_meths(e), iVar1 != 0)) &&
                          ((iVar1 = EVP_add_cipher((EVP_CIPHER *)cipher_gost), iVar1 != 0 &&
                           (iVar1 = EVP_add_cipher((EVP_CIPHER *)cipher_gost_cpacnt), iVar1 != 0))))
                         && ((iVar1 = EVP_add_digest((EVP_MD *)&digest_gost), iVar1 != 0 &&
                             (iVar1 = EVP_add_digest((EVP_MD *)imit_gost_cpa), iVar1 != 0)))))))) {
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
    puts("GOST engine already loaded");
  }
  ENGINE_free(e);
  return;
}

