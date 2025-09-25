
void EVP_PKEY_asn1_copy(EVP_PKEY_ASN1_METHOD *dst,EVP_PKEY_ASN1_METHOD *src)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  uVar5 = *(undefined4 *)(src + 0x14);
  uVar1 = *(undefined4 *)(src + 0x20);
  uVar2 = *(undefined4 *)(src + 0x24);
  uVar4 = *(undefined4 *)(src + 0x18);
  uVar3 = *(undefined4 *)(src + 0x1c);
  *(undefined4 *)(dst + 0x28) = *(undefined4 *)(src + 0x28);
  uVar7 = *(undefined4 *)(src + 0x2c);
  *(undefined4 *)(dst + 0x14) = uVar5;
  uVar6 = *(undefined4 *)(src + 100);
  *(undefined4 *)(dst + 0x18) = uVar4;
  uVar5 = *(undefined4 *)(src + 0x60);
  *(undefined4 *)(dst + 0x1c) = uVar3;
  uVar4 = *(undefined4 *)(src + 0x30);
  *(undefined4 *)(dst + 0x20) = uVar1;
  uVar1 = *(undefined4 *)(src + 0x34);
  *(undefined4 *)(dst + 0x24) = uVar2;
  uVar2 = *(undefined4 *)(src + 0x3c);
  uVar3 = *(undefined4 *)(src + 0x40);
  *(undefined4 *)(dst + 0x2c) = uVar7;
  uVar7 = *(undefined4 *)(src + 0x44);
  *(undefined4 *)(dst + 0x40) = uVar3;
  *(undefined4 *)(dst + 100) = uVar6;
  uVar6 = *(undefined4 *)(src + 0x48);
  *(undefined4 *)(dst + 0x60) = uVar5;
  uVar5 = *(undefined4 *)(src + 0x4c);
  *(undefined4 *)(dst + 0x30) = uVar4;
  *(undefined4 *)(dst + 0x34) = uVar1;
  *(undefined4 *)(dst + 0x3c) = uVar2;
  *(undefined4 *)(dst + 0x44) = uVar7;
  uVar7 = *(undefined4 *)(src + 0x50);
  uVar4 = *(undefined4 *)(src + 0x6c);
  uVar2 = *(undefined4 *)(src + 0x68);
  uVar3 = *(undefined4 *)(src + 0x70);
  *(undefined4 *)(dst + 0x48) = uVar6;
  *(undefined4 *)(dst + 0x4c) = uVar5;
  uVar6 = *(undefined4 *)(src + 0x58);
  uVar5 = *(undefined4 *)(src + 0x5c);
  uVar1 = *(undefined4 *)(src + 0x74);
  *(undefined4 *)(dst + 0x50) = uVar7;
  *(undefined4 *)(dst + 0x58) = uVar6;
  *(undefined4 *)(dst + 0x5c) = uVar5;
  *(undefined4 *)(dst + 0x6c) = uVar4;
  *(undefined4 *)(dst + 0x68) = uVar2;
  *(undefined4 *)(dst + 0x70) = uVar3;
  *(undefined4 *)(dst + 0x74) = uVar1;
  return;
}

