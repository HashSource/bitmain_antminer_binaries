
undefined4 ssl_load_ciphers(void)

{
  uint *puVar1;
  char *pcVar2;
  EVP_CIPHER *pEVar3;
  int iVar4;
  EVP_MD *md;
  EVP_PKEY_ASN1_METHOD *pEVar5;
  undefined *puVar6;
  int iVar7;
  undefined1 *puVar8;
  undefined4 *puVar9;
  ENGINE *local_20;
  int local_1c;
  
  disabled_enc_mask = 0;
  puVar8 = ssl_cipher_methods;
  puVar6 = &UNK_001fd764;
  ssl_sort_cipher_list();
  do {
    while( true ) {
      HintPreloadData(puVar6);
      if (*(int *)(puVar6 + -0x28) != 0) break;
      *(undefined4 *)puVar8 = 0;
LAB_000d9b5e:
      puVar6 = puVar6 + 8;
      puVar8 = (undefined1 *)((int)puVar8 + 4);
      if (puVar6 == (undefined *)0x1fd814) goto LAB_000d9b96;
    }
    pcVar2 = OBJ_nid2sn(*(int *)(puVar6 + -0x28));
    pEVar3 = EVP_get_cipherbyname(pcVar2);
    *(EVP_CIPHER **)puVar8 = pEVar3;
    if (pEVar3 != (EVP_CIPHER *)0x0) goto LAB_000d9b5e;
    puVar1 = (uint *)(puVar6 + -0x2c);
    puVar6 = puVar6 + 8;
    puVar8 = (undefined1 *)((int)puVar8 + 4);
    disabled_enc_mask = disabled_enc_mask | *puVar1;
  } while (puVar6 != (undefined *)0x1fd814);
LAB_000d9b96:
  puVar8 = ssl_mac_secret_size;
  iVar7 = 0x1fd7f0;
  puVar9 = &disabled_mac_mask;
  disabled_mac_mask = 0;
  do {
    while( true ) {
      pcVar2 = OBJ_nid2sn(*(int *)(iVar7 + -4));
      md = EVP_get_digestbyname(pcVar2);
      puVar9 = puVar9 + 1;
      *puVar9 = md;
      if (md != (EVP_MD *)0x0) break;
      puVar1 = (uint *)(iVar7 + -8);
      iVar7 = iVar7 + 8;
      puVar8 = (undefined1 *)((int)puVar8 + 4);
      disabled_mac_mask = disabled_mac_mask | *puVar1;
      if (iVar7 == 0x1fd850) goto LAB_000d9bfc;
    }
    iVar4 = EVP_MD_size(md);
    if (iVar4 < 0) {
      return 0;
    }
    iVar7 = iVar7 + 8;
    *(int *)puVar8 = iVar4;
    puVar8 = (undefined1 *)((int)puVar8 + 4);
  } while (iVar7 != 0x1fd850);
LAB_000d9bfc:
  if ((ssl_digest_methods._0_4_ != 0) && (ssl_digest_methods._4_4_ != 0)) {
    disabled_mkey_mask = 0;
    disabled_auth_mask = 0;
    local_20 = (ENGINE *)0x0;
    local_1c = 0;
    pEVar5 = EVP_PKEY_asn1_find_str(&local_20,"gost-mac",-1);
    if ((pEVar5 != (EVP_PKEY_ASN1_METHOD *)0x0) &&
       (iVar7 = EVP_PKEY_asn1_get0_info
                          (&local_1c,(int *)0x0,(int *)0x0,(char **)0x0,(char **)0x0,pEVar5),
       iVar7 < 1)) {
      local_1c = 0;
    }
    ENGINE_finish(local_20);
    DAT_0027409c = local_1c;
    if (local_1c == 0) {
      disabled_mac_mask = disabled_mac_mask | 8;
    }
    else {
      ssl_mac_secret_size._12_4_ = 0x20;
    }
    local_20 = (ENGINE *)0x0;
    local_1c = 0;
    pEVar5 = EVP_PKEY_asn1_find_str(&local_20,"gost-mac-12",-1);
    if ((pEVar5 != (EVP_PKEY_ASN1_METHOD *)0x0) &&
       (iVar7 = EVP_PKEY_asn1_get0_info
                          (&local_1c,(int *)0x0,(int *)0x0,(char **)0x0,(char **)0x0,pEVar5),
       iVar7 < 1)) {
      local_1c = 0;
    }
    ENGINE_finish(local_20);
    DAT_002740ac = local_1c;
    if (local_1c == 0) {
      disabled_mac_mask = disabled_mac_mask | 0x100;
    }
    else {
      ssl_mac_secret_size._28_4_ = 0x20;
    }
    local_20 = (ENGINE *)0x0;
    local_1c = 0;
    pEVar5 = EVP_PKEY_asn1_find_str(&local_20,"gost2001",-1);
    if ((pEVar5 != (EVP_PKEY_ASN1_METHOD *)0x0) &&
       (iVar7 = EVP_PKEY_asn1_get0_info
                          (&local_1c,(int *)0x0,(int *)0x0,(char **)0x0,(char **)0x0,pEVar5),
       iVar7 < 1)) {
      local_1c = 0;
    }
    ENGINE_finish(local_20);
    if (local_1c == 0) {
      disabled_auth_mask = disabled_auth_mask | 0xa0;
    }
    local_20 = (ENGINE *)0x0;
    local_1c = 0;
    pEVar5 = EVP_PKEY_asn1_find_str(&local_20,"gost2012_256",-1);
    if ((pEVar5 != (EVP_PKEY_ASN1_METHOD *)0x0) &&
       (iVar7 = EVP_PKEY_asn1_get0_info
                          (&local_1c,(int *)0x0,(int *)0x0,(char **)0x0,(char **)0x0,pEVar5),
       iVar7 < 1)) {
      local_1c = 0;
    }
    ENGINE_finish(local_20);
    if (local_1c == 0) {
      disabled_auth_mask = disabled_auth_mask | 0x80;
    }
    local_20 = (ENGINE *)0x0;
    local_1c = 0;
    pEVar5 = EVP_PKEY_asn1_find_str(&local_20,"gost2012_512",-1);
    if ((pEVar5 != (EVP_PKEY_ASN1_METHOD *)0x0) &&
       (iVar7 = EVP_PKEY_asn1_get0_info
                          (&local_1c,(int *)0x0,(int *)0x0,(char **)0x0,(char **)0x0,pEVar5),
       iVar7 < 1)) {
      local_1c = 0;
    }
    ENGINE_finish(local_20);
    if (local_1c == 0) {
      disabled_auth_mask = disabled_auth_mask | 0x80;
    }
    if ((disabled_auth_mask & 0xa0) == 0xa0) {
      disabled_mkey_mask = disabled_mkey_mask | 0x10;
    }
    return 1;
  }
  return 0;
}

