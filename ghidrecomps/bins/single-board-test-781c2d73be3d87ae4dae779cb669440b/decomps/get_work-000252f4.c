
/* WARNING: Unknown calling convention */

int get_work(int id,int count)

{
  uchar uVar1;
  work *pwVar2;
  char *pcVar3;
  char *temp;
  uchar *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uchar *__ptr;
  work *new_work;
  char str [1024];
  
  memset(str,0,0x400);
  iVar7 = 0;
  iVar6 = 0;
  pwVar2 = (work *)malloc(count * 0x44);
  cgpu.works[id] = pwVar2;
  if (pwVar2 == (work *)0x0) {
    puts("malloc struct work err");
    return 0;
  }
  while( true ) {
    pcVar3 = fgets(str,0x3ff,(FILE *)cgpu.fps[id]);
    if (pcVar3 == (char *)0x0) {
      return iVar6;
    }
    __ptr = cgpu.works[id]->data + iVar7 + -8;
    pcVar3 = strstr(str,"nonce");
    if (pcVar3 == (char *)0x0) break;
    puVar4 = (uchar *)(pcVar3 + 5);
    uVar1 = pcVar3[5];
    while (uVar1 == ' ') {
      puVar4 = puVar4 + 1;
      uVar1 = *puVar4;
    }
    s2hex(__ptr + 4,puVar4,8);
    uVar5 = *(uint *)(__ptr + 4);
    *(uint *)(__ptr + 4) =
         uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 | uVar5 >> 0x18;
    pcVar3 = strstr(str,"midstate");
    if (pcVar3 == (char *)0x0) break;
    puVar4 = (uchar *)(pcVar3 + 8);
    uVar1 = pcVar3[8];
    while (uVar1 == ' ') {
      puVar4 = puVar4 + 1;
      uVar1 = *puVar4;
    }
    s2hex(__ptr + 0x14,puVar4,0x40);
    pcVar3 = strstr(str,"data");
    if (pcVar3 == (char *)0x0) break;
    puVar4 = (uchar *)(pcVar3 + 4);
    uVar1 = pcVar3[4];
    while (uVar1 == ' ') {
      puVar4 = puVar4 + 1;
      uVar1 = *puVar4;
    }
    s2hex(__ptr + 8,puVar4,0x18);
    *(int *)__ptr = iVar6;
    iVar6 = iVar6 + 1;
    iVar7 = iVar7 + 0x44;
    (*(uint (*) [1])(__ptr + 0x34))[0] = 0;
    (*(uint (*) [1])(__ptr + 0x38))[0] = 0;
    *(undefined4 *)(__ptr + 0x3c) = 0;
    *(undefined4 *)(__ptr + 0x40) = 0;
    if (count <= iVar6) {
      return iVar6;
    }
  }
  free(__ptr);
  puts("get work err");
  return iVar6;
}

