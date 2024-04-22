
void ssl_load_ciphers(void)

{
  int iVar1;
  char *str;
  EVP_CIPHER *pEVar2;
  EVP_MD *pEVar3;
  int iVar4;
  int iVar5;
  EVP_PKEY_ASN1_METHOD *ameth;
  ENGINE *local_18;
  int local_14 [2];
  
  iVar1 = DAT_00080000;
  pEVar2 = EVP_get_cipherbyname(DAT_00080004);
  *(EVP_CIPHER **)(iVar1 + 4) = pEVar2;
  pEVar2 = EVP_get_cipherbyname(DAT_00080008);
  *(EVP_CIPHER **)(iVar1 + 8) = pEVar2;
  pEVar2 = EVP_get_cipherbyname(DAT_0008000c);
  *(EVP_CIPHER **)(iVar1 + 0xc) = pEVar2;
  pEVar2 = EVP_get_cipherbyname(DAT_00080010);
  *(EVP_CIPHER **)(iVar1 + 0x10) = pEVar2;
  pEVar2 = EVP_get_cipherbyname(DAT_00080014);
  *(EVP_CIPHER **)(iVar1 + 0x14) = pEVar2;
  pEVar2 = EVP_get_cipherbyname(DAT_00080018);
  *(EVP_CIPHER **)(iVar1 + 0x1c) = pEVar2;
  pEVar2 = EVP_get_cipherbyname(DAT_0008001c);
  *(EVP_CIPHER **)(iVar1 + 0x20) = pEVar2;
  pEVar2 = EVP_get_cipherbyname(DAT_00080020);
  *(EVP_CIPHER **)(iVar1 + 0x24) = pEVar2;
  pEVar2 = EVP_get_cipherbyname(DAT_00080024);
  *(EVP_CIPHER **)(iVar1 + 0x28) = pEVar2;
  pEVar2 = EVP_get_cipherbyname(DAT_00080028);
  *(EVP_CIPHER **)(iVar1 + 0x2c) = pEVar2;
  pEVar2 = EVP_get_cipherbyname(DAT_0008002c);
  *(EVP_CIPHER **)(iVar1 + 0x30) = pEVar2;
  pEVar2 = EVP_get_cipherbyname(DAT_00080030);
  *(EVP_CIPHER **)(iVar1 + 0x34) = pEVar2;
  pEVar2 = EVP_get_cipherbyname(DAT_00080034);
  *(EVP_CIPHER **)(iVar1 + 0x38) = pEVar2;
  pEVar3 = EVP_get_digestbyname(DAT_00080038);
  *(EVP_MD **)(iVar1 + 0x3c) = pEVar3;
  iVar4 = EVP_MD_size(pEVar3);
  *(int *)(iVar1 + 0x54) = iVar4;
  if (iVar4 < 0) {
    OpenSSLDie(DAT_00080054,0x1b3,DAT_00080058);
  }
  pEVar3 = EVP_get_digestbyname(DAT_0008003c);
  *(EVP_MD **)(iVar1 + 0x40) = pEVar3;
  iVar4 = EVP_MD_size(pEVar3);
  *(int *)(iVar1 + 0x58) = iVar4;
  if (iVar4 < 0) {
    OpenSSLDie(DAT_00080054,0x1b7,DAT_0008005c);
  }
  pEVar3 = EVP_get_digestbyname(DAT_00080040);
  iVar4 = DAT_00080000;
  *(EVP_MD **)(iVar1 + 0x44) = pEVar3;
  if (pEVar3 != (EVP_MD *)0x0) {
    iVar5 = EVP_MD_size(pEVar3);
    *(int *)(iVar4 + 0x5c) = iVar5;
    if (iVar5 < 0) {
      OpenSSLDie(DAT_00080054,0x1bd,DAT_00080060);
    }
  }
  pEVar3 = EVP_get_digestbyname(DAT_00080044);
  str = DAT_00080044;
  *(EVP_MD **)(iVar1 + 0x48) = pEVar3;
  local_18 = (ENGINE *)0x0;
  local_14[0] = 0;
  ameth = EVP_PKEY_asn1_find_str(&local_18,str,-1);
  if (ameth != (EVP_PKEY_ASN1_METHOD *)0x0) {
    EVP_PKEY_asn1_get0_info(local_14,(int *)0x0,(int *)0x0,(char **)0x0,(char **)0x0,ameth);
  }
  if (local_18 != (ENGINE *)0x0) {
    ENGINE_finish(local_18);
  }
  *(int *)(DAT_00080048 + 0xc) = local_14[0];
  if (local_14[0] != 0) {
    *(undefined4 *)(iVar1 + 0x60) = 0x20;
  }
  pEVar3 = EVP_get_digestbyname(DAT_0008004c);
  *(EVP_MD **)(iVar1 + 0x4c) = pEVar3;
  iVar4 = EVP_MD_size(pEVar3);
  *(int *)(iVar1 + 100) = iVar4;
  pEVar3 = EVP_get_digestbyname(DAT_00080050);
  *(EVP_MD **)(iVar1 + 0x50) = pEVar3;
  iVar4 = EVP_MD_size(pEVar3);
  *(int *)(iVar1 + 0x68) = iVar4;
  return;
}

