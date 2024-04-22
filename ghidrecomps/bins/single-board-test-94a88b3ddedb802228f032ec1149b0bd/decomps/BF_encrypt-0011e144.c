
void BF_encrypt(uint *data,BF_KEY *key)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  uVar5 = *data ^ key->P[0];
  uVar4 = data[1] ^ key->P[1] ^
          (*(int *)((int)key->S + (uVar5 >> 0xe & 0x3fc) + 0x400) +
           *(int *)((int)key->S + (uVar5 >> 0x16 & 0x3fc)) ^
          *(uint *)((int)key->S + (uVar5 >> 6 & 0x3fc) + 0x800)) + key->S[(uVar5 & 0xff) + 0x300];
  uVar5 = uVar5 ^ key->P[2] ^
          (*(int *)((int)key->S + (uVar4 >> 0xe & 0x3fc) + 0x400) +
           *(int *)((int)key->S + (uVar4 >> 0x16 & 0x3fc)) ^
          *(uint *)((int)key->S + (uVar4 >> 6 & 0x3fc) + 0x800)) + key->S[(uVar4 & 0xff) + 0x300];
  uVar6 = uVar4 ^ key->P[3] ^
          (*(int *)((int)key->S + (uVar5 >> 0xe & 0x3fc) + 0x400) +
           *(int *)((int)key->S + (uVar5 >> 0x16 & 0x3fc)) ^
          *(uint *)((int)key->S + (uVar5 >> 6 & 0x3fc) + 0x800)) + key->S[(uVar5 & 0xff) + 0x300];
  uVar4 = uVar5 ^ key->P[4] ^
          (*(int *)((int)key->S + (uVar6 >> 0xe & 0x3fc) + 0x400) +
           *(int *)((int)key->S + (uVar6 >> 0x16 & 0x3fc)) ^
          *(uint *)((int)key->S + (uVar6 >> 6 & 0x3fc) + 0x800)) + key->S[(uVar6 & 0xff) + 0x300];
  uVar5 = uVar6 ^ key->P[5] ^
          key->S[(uVar4 & 0xff) + 0x300] +
          (*(int *)((int)key->S + (uVar4 >> 0xe & 0x3fc) + 0x400) +
           *(int *)((int)key->S + (uVar4 >> 0x16 & 0x3fc)) ^
          *(uint *)((int)key->S + (uVar4 >> 6 & 0x3fc) + 0x800));
  uVar4 = uVar4 ^ key->P[6] ^
          (*(int *)((int)key->S + (uVar5 >> 0xe & 0x3fc) + 0x400) +
           *(int *)((int)key->S + (uVar5 >> 0x16 & 0x3fc)) ^
          *(uint *)((int)key->S + (uVar5 >> 6 & 0x3fc) + 0x800)) + key->S[(uVar5 & 0xff) + 0x300];
  uVar6 = uVar5 ^ key->P[7] ^
          (*(int *)((int)key->S + (uVar4 >> 0xe & 0x3fc) + 0x400) +
           *(int *)((int)key->S + (uVar4 >> 0x16 & 0x3fc)) ^
          *(uint *)((int)key->S + (uVar4 >> 6 & 0x3fc) + 0x800)) + key->S[(uVar4 & 0xff) + 0x300];
  uVar5 = uVar4 ^ key->P[8] ^
          (*(int *)((int)key->S + (uVar6 >> 0xe & 0x3fc) + 0x400) +
           *(int *)((int)key->S + (uVar6 >> 0x16 & 0x3fc)) ^
          *(uint *)((int)key->S + (uVar6 >> 6 & 0x3fc) + 0x800)) + key->S[(uVar6 & 0xff) + 0x300];
  uVar4 = key->P[0x10];
  uVar6 = uVar6 ^ key->P[9] ^
          (*(int *)((int)key->S + (uVar5 >> 0x16 & 0x3fc)) +
           *(int *)((int)key->S + (uVar5 >> 0xe & 0x3fc) + 0x400) ^
          *(uint *)((int)key->S + (uVar5 >> 6 & 0x3fc) + 0x800)) + key->S[(uVar5 & 0xff) + 0x300];
  uVar5 = uVar5 ^ key->P[10] ^
          key->S[(uVar6 & 0xff) + 0x300] +
          (*(int *)((int)key->S + (uVar6 >> 0x16 & 0x3fc)) +
           *(int *)((int)key->S + (uVar6 >> 0xe & 0x3fc) + 0x400) ^
          *(uint *)((int)key->S + (uVar6 >> 6 & 0x3fc) + 0x800));
  uVar6 = uVar6 ^ key->P[0xb] ^
          key->S[(uVar5 & 0xff) + 0x300] +
          (*(int *)((int)key->S + (uVar5 >> 0x16 & 0x3fc)) +
           *(int *)((int)key->S + (uVar5 >> 0xe & 0x3fc) + 0x400) ^
          *(uint *)((int)key->S + (uVar5 >> 6 & 0x3fc) + 0x800));
  uVar5 = uVar5 ^ key->P[0xc] ^
          key->S[(uVar6 & 0xff) + 0x300] +
          (*(int *)((int)key->S + (uVar6 >> 0x16 & 0x3fc)) +
           *(int *)((int)key->S + (uVar6 >> 0xe & 0x3fc) + 0x400) ^
          *(uint *)((int)key->S + (uVar6 >> 6 & 0x3fc) + 0x800));
  uVar6 = uVar6 ^ key->P[0xd] ^
          (*(int *)((int)key->S + (uVar5 >> 0xe & 0x3fc) + 0x400) +
           *(int *)((int)key->S + (uVar5 >> 0x16 & 0x3fc)) ^
          *(uint *)((int)key->S + (uVar5 >> 6 & 0x3fc) + 0x800)) + key->S[(uVar5 & 0xff) + 0x300];
  uVar2 = key->P[0xe] ^ uVar5 ^
          (*(int *)((int)key->S + (uVar6 >> 0xe & 0x3fc) + 0x400) +
           *(int *)((int)key->S + (uVar6 >> 0x16 & 0x3fc)) ^
          *(uint *)((int)key->S + (uVar6 >> 6 & 0x3fc) + 0x800)) + key->S[(uVar6 & 0xff) + 0x300];
  uVar1 = key->P[0xf] ^ uVar6 ^
          (*(uint *)((int)key->S + (uVar2 >> 6 & 0x3fc) + 0x800) ^
          *(int *)((int)key->S + (uVar2 >> 0xe & 0x3fc) + 0x400) +
          *(int *)((int)key->S + (uVar2 >> 0x16 & 0x3fc))) + key->S[(uVar2 & 0xff) + 0x300];
  iVar3 = *(int *)((int)key->S + (uVar1 >> 0x16 & 0x3fc));
  iVar7 = *(int *)((int)key->S + (uVar1 >> 0xe & 0x3fc) + 0x400);
  uVar6 = *(uint *)((int)key->S + (uVar1 >> 6 & 0x3fc) + 0x800);
  uVar5 = key->S[(uVar1 & 0xff) + 0x300];
  *data = key->P[0x11] ^ uVar1;
  data[1] = uVar2 ^ uVar4 ^ (iVar7 + iVar3 ^ uVar6) + uVar5;
  return;
}

