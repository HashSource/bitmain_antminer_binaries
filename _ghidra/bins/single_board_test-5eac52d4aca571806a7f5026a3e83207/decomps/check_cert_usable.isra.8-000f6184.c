
undefined4 check_cert_usable_isra_8(int *param_1,int *param_2,undefined4 param_3,EVP_PKEY *param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  int local_24;
  int local_20;
  int local_1c;
  
  ERR_set_mark();
  iVar1 = EVP_PKEY_get_default_digest_nid(param_4,&local_24);
  if ((iVar1 != 2) || (*param_2 == local_24)) {
    ERR_pop_to_mark();
    iVar1 = *param_1;
    iVar3 = *(int *)(iVar1 + 0x26c);
    if (iVar3 == 0) {
      return 1;
    }
    uVar2 = *(uint *)(iVar1 + 0x274);
    if (uVar2 != 0) {
      uVar5 = 0;
      do {
        puVar4 = &sigalg_lookup_tbl;
        do {
          if (*(short *)(puVar4 + 4) == *(short *)(iVar3 + uVar5 * 2)) {
            iVar1 = X509_get_signature_info(param_3,&local_20,&local_1c,0,0);
            if (((iVar1 != 0) && (*(int *)(puVar4 + 8) == local_20)) &&
               (*(int *)(puVar4 + 0x10) == local_1c)) {
              return 1;
            }
            iVar1 = *param_1;
            uVar2 = *(uint *)(iVar1 + 0x274);
            break;
          }
          puVar4 = puVar4 + 0x20;
        } while (puVar4 != legacy_rsa_sigalg);
        uVar5 = uVar5 + 1;
        if (uVar2 <= uVar5) {
          return 0;
        }
        iVar3 = *(int *)(iVar1 + 0x26c);
      } while( true );
    }
  }
  return 0;
}

