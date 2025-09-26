
void EVP_PKEY_asn1_copy(EVP_PKEY_ASN1_METHOD *dst,EVP_PKEY_ASN1_METHOD *src)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  uVar6 = *(undefined4 *)(src + 0x1c);
  *(undefined4 *)(dst + 0x14) = *(undefined4 *)(src + 0x14);
  uVar5 = *(undefined4 *)(src + 0x20);
  uVar4 = *(undefined4 *)(src + 0x24);
  *(undefined4 *)(dst + 0x18) = *(undefined4 *)(src + 0x18);
  uVar3 = *(undefined4 *)(src + 0x28);
  uVar1 = *(undefined4 *)(src + 0x2c);
  *(undefined4 *)(dst + 0x60) = *(undefined4 *)(src + 0x60);
  uVar2 = *(undefined4 *)(src + 0x5c);
  *(undefined4 *)(dst + 0x1c) = uVar6;
  *(undefined4 *)(dst + 0x20) = uVar5;
  *(undefined4 *)(dst + 0x5c) = uVar2;
  uVar2 = *(undefined4 *)(src + 0x30);
  uVar6 = *(undefined4 *)(src + 0x44);
  *(undefined4 *)(dst + 0x24) = uVar4;
  *(undefined4 *)(dst + 0x30) = uVar2;
  uVar4 = *(undefined4 *)(src + 0x4c);
  uVar5 = *(undefined4 *)(src + 0x48);
  *(undefined4 *)(dst + 0x34) = *(undefined4 *)(src + 0x34);
  uVar2 = *(undefined4 *)(src + 0x38);
  *(undefined4 *)(dst + 0x28) = uVar3;
  *(undefined4 *)(dst + 0x2c) = uVar1;
  *(undefined4 *)(dst + 0x38) = uVar2;
  uVar1 = *(undefined4 *)(src + 0x3c);
  *(undefined4 *)(dst + 0x44) = uVar6;
  *(undefined4 *)(dst + 0x3c) = uVar1;
  *(undefined4 *)(dst + 0x40) = *(undefined4 *)(src + 0x40);
  *(undefined4 *)(dst + 0x48) = uVar5;
  *(undefined4 *)(dst + 0x4c) = uVar4;
  uVar3 = *(undefined4 *)(src + 0x58);
  uVar1 = *(undefined4 *)(src + 0x68);
  uVar2 = *(undefined4 *)(src + 100);
  *(undefined4 *)(dst + 0x54) = *(undefined4 *)(src + 0x54);
  *(undefined4 *)(dst + 0x58) = uVar3;
  *(undefined4 *)(dst + 0x68) = uVar1;
  *(undefined4 *)(dst + 100) = uVar2;
  return;
}

