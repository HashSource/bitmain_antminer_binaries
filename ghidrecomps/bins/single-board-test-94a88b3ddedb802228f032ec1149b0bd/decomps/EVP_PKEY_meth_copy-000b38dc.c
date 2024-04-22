
void EVP_PKEY_meth_copy(EVP_PKEY_METHOD *dst,EVP_PKEY_METHOD *src)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  uVar6 = *(undefined4 *)(src + 0x10);
  *(undefined4 *)(dst + 8) = *(undefined4 *)(src + 8);
  uVar5 = *(undefined4 *)(src + 0x14);
  uVar4 = *(undefined4 *)(src + 0x18);
  *(undefined4 *)(dst + 0xc) = *(undefined4 *)(src + 0xc);
  uVar3 = *(undefined4 *)(src + 0x1c);
  uVar1 = *(undefined4 *)(src + 0x20);
  *(undefined4 *)(dst + 0x24) = *(undefined4 *)(src + 0x24);
  uVar2 = *(undefined4 *)(src + 0x28);
  *(undefined4 *)(dst + 0x10) = uVar6;
  *(undefined4 *)(dst + 0x14) = uVar5;
  *(undefined4 *)(dst + 0x28) = uVar2;
  uVar6 = *(undefined4 *)(src + 0x40);
  uVar5 = *(undefined4 *)(src + 0x44);
  *(undefined4 *)(dst + 0x2c) = *(undefined4 *)(src + 0x2c);
  uVar2 = *(undefined4 *)(src + 0x30);
  *(undefined4 *)(dst + 0x18) = uVar4;
  *(undefined4 *)(dst + 0x1c) = uVar3;
  *(undefined4 *)(dst + 0x30) = uVar2;
  uVar2 = *(undefined4 *)(src + 0x34);
  uVar3 = *(undefined4 *)(src + 0x48);
  *(undefined4 *)(dst + 0x20) = uVar1;
  *(undefined4 *)(dst + 0x34) = uVar2;
  uVar1 = *(undefined4 *)(src + 0x38);
  *(undefined4 *)(dst + 0x40) = uVar6;
  *(undefined4 *)(dst + 0x38) = uVar1;
  *(undefined4 *)(dst + 0x3c) = *(undefined4 *)(src + 0x3c);
  *(undefined4 *)(dst + 0x44) = uVar5;
  uVar1 = *(undefined4 *)(src + 0x60);
  uVar7 = *(undefined4 *)(src + 0x4c);
  uVar6 = *(undefined4 *)(src + 0x50);
  uVar4 = *(undefined4 *)(src + 0x58);
  uVar2 = *(undefined4 *)(src + 0x5c);
  *(undefined4 *)(dst + 0x48) = uVar3;
  *(undefined4 *)(dst + 0x60) = uVar1;
  uVar5 = *(undefined4 *)(src + 0x54);
  uVar3 = *(undefined4 *)(src + 100);
  uVar1 = *(undefined4 *)(src + 0x68);
  *(undefined4 *)(dst + 0x4c) = uVar7;
  *(undefined4 *)(dst + 100) = uVar3;
  *(undefined4 *)(dst + 0x50) = uVar6;
  *(undefined4 *)(dst + 0x54) = uVar5;
  *(undefined4 *)(dst + 0x58) = uVar4;
  *(undefined4 *)(dst + 0x5c) = uVar2;
  *(undefined4 *)(dst + 0x68) = uVar1;
  return;
}

