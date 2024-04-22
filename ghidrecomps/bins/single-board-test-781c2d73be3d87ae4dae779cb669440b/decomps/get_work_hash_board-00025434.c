
/* WARNING: Unknown calling convention */

int get_work_hash_board(int which_asic,int which_core,FILE *stream,int count)

{
  uchar uVar1;
  char *pcVar2;
  char *temp;
  uchar *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uchar *__ptr;
  work *new_work;
  char str [1024];
  
  memset(str,0,0x400);
  iVar6 = count * which_core * 0x44;
  uVar5 = 0;
  while( true ) {
    pcVar2 = fgets(str,0x3ff,(FILE *)stream);
    if (pcVar2 == (char *)0x0) {
      return uVar5;
    }
    __ptr = cgpu.works[which_asic]->data + iVar6 + -8;
    pcVar2 = strstr(str,"nonce");
    if (pcVar2 == (char *)0x0) break;
    puVar3 = (uchar *)(pcVar2 + 5);
    uVar1 = pcVar2[5];
    while (uVar1 == ' ') {
      puVar3 = puVar3 + 1;
      uVar1 = *puVar3;
    }
    s2hex(__ptr + 4,puVar3,8);
    uVar4 = *(uint *)(__ptr + 4);
    *(uint *)(__ptr + 4) =
         uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 | uVar4 >> 0x18;
    pcVar2 = strstr(str,"midstate");
    if (pcVar2 == (char *)0x0) break;
    puVar3 = (uchar *)(pcVar2 + 8);
    uVar1 = pcVar2[8];
    while (uVar1 == ' ') {
      puVar3 = puVar3 + 1;
      uVar1 = *puVar3;
    }
    s2hex(__ptr + 0x14,puVar3,0x40);
    pcVar2 = strstr(str,"data");
    if (pcVar2 == (char *)0x0) break;
    puVar3 = (uchar *)(pcVar2 + 4);
    uVar1 = pcVar2[4];
    while (uVar1 == ' ') {
      puVar3 = puVar3 + 1;
      uVar1 = *puVar3;
    }
    s2hex(__ptr + 8,puVar3,0x18);
    *(uint *)__ptr = uVar5;
    uVar5 = uVar5 + 1;
    iVar6 = iVar6 + 0x44;
    (*(uint (*) [1])(__ptr + 0x34))[0] = 0;
    (*(uint (*) [1])(__ptr + 0x38))[0] = 0;
    *(undefined4 *)(__ptr + 0x3c) = 0;
    *(undefined4 *)(__ptr + 0x40) = 0;
    if ((uint)count <= uVar5) {
      return uVar5;
    }
  }
  free(__ptr);
  puts("get work err");
  return uVar5;
}

